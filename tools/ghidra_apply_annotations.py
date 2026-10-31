# -*- coding: utf-8 -*-
#@category REA
#@description Wendet REA-Annotationen aus der function_index-CSV im aktuellen
#  Programm an: Plate-Kommentar (Praefix "REA: ") + Label "rea_<sanitized>".
#  Idempotent, benennt nichts um und loescht keine Symbole.
#@runtime PyGhidra
#
# Aufruf in Ghidra:
#   - Script Manager: ausfuehren, CSV per Dateidialog waehlen, ODER
#   - Kopf-Modus / Script-Args: CSV-Pfad als erstes Script-Argument.
#
# Hinweis: bewusst Jython-kompatibel geschrieben (keine Typannotationen,
# keine f-strings, kein pathlib); laeuft aber auch als PyGhidra-CPython-3.

import io
import re

from ghidra.program.model.symbol import SourceType

COMMENT_PREFIX = "REA: "
LABEL_PREFIX = "rea_"
MAX_LABEL_LEN = 64

_SANITIZE_RE = re.compile(r'[^A-Za-z0-9_]+')


def sanitize_label(text):
    """Annotation -> label-tauglicher Name (nur [A-Za-z0-9_])."""
    s = text.lower()
    s = _SANITIZE_RE.sub('_', s)
    s = s.strip('_')
    if len(s) > MAX_LABEL_LEN:
        s = s[:MAX_LABEL_LEN].rstrip('_')
    if not s:
        s = "annotation"
    return s


def read_csv_rows(path):
    """Liest die CSV (address;name;bytes;parts;annotation) als Liste von Tupeln."""
    rows = []
    fh = io.open(path, 'r', encoding='utf-8')
    try:
        text = fh.read()
    finally:
        fh.close()
    # BOM tolerant entfernen (falls vorhanden)
    if text and text[0] == u'\ufeff':
        text = text[1:]
    for line in text.splitlines():
        line = line.strip()
        if not line:
            continue
        parts = line.split(';', 4)
        if len(parts) < 2:
            continue
        addr_txt = parts[0].strip()
        name = parts[1].strip()
        size_txt = parts[2].strip() if len(parts) > 2 else ""
        annotation = parts[4].strip() if len(parts) > 4 else ""
        try:
            addr_int = int(addr_txt, 16)
        except ValueError:
            continue  # Kopfzeile oder unlesbare Adresse
        rows.append((addr_int, name, size_txt, annotation))
    return rows


def has_user_defined_symbol(st, addr):
    """True, wenn an addr bereits ein USER_DEFINED-Symbol haengt."""
    for sym in st.getSymbols(addr):
        if sym.getSource() == SourceType.USER_DEFINED:
            return True
    return False


def choose_label_name(st, base_name, addr, addr_int):
    """Kollisionsfreier Labelname; bei Namenskonflikt Adresse anhaengen."""
    name = base_name
    for attempt in range(2):
        conflict = False
        for sym in st.getSymbols(name):
            if not sym.getAddress().equals(addr):
                conflict = True
                break
        if not conflict:
            return name
        if attempt == 0:
            name = base_name + "_" + ('%x' % addr_int)
    return name


def run():
    args = getScriptArgs()
    csv_path = None
    if args is not None and len(args) > 0:
        first = args[0]
        if first is not None and str(first).strip():
            csv_path = str(first).strip()

    if csv_path is None:
        chosen = askFile("CSV wählen (address;name;bytes;parts;annotation)",
                         "CSV verwenden")
        if chosen is None:
            println("REA: Keine CSV gewaehlt - Abbruch.")
            return
        csv_path = str(chosen.getAbsolutePath())

    println("REA: CSV = " + csv_path)
    rows = read_csv_rows(csv_path)

    program = currentProgram
    memory = program.getMemory()
    st = program.getSymbolTable()

    n_rows = 0
    n_annotated = 0
    n_comment_set = 0
    n_comment_same = 0
    n_comment_replaced = 0
    n_label_created = 0
    n_label_skipped_user = 0
    n_label_failed = 0
    n_addr_not_in_program = 0
    n_without_function = 0
    n_unparsable_addr = 0

    for addr_int, name, size_txt, annotation in rows:
        n_rows += 1
        if not annotation:
            continue
        n_annotated += 1

        try:
            addr = toAddr(addr_int)
        except Exception:
            n_unparsable_addr += 1
            continue
        if addr is None or not memory.contains(addr):
            n_addr_not_in_program += 1
            continue

        func = getFunctionAt(addr)
        if func is None:
            func = getFunctionContaining(addr)
        if func is not None:
            comment_addr = func.getEntryPoint()
        else:
            comment_addr = addr
            n_without_function += 1

        # (a) Plate-Kommentar: "REA: " + Annotation + Groesse
        comment = COMMENT_PREFIX + annotation
        if size_txt:
            comment = comment + " (Groesse: " + size_txt + " Bytes)"
        existing = getPlateComment(comment_addr)
        if existing is not None:
            existing = str(existing)  # Jython: Java-String -> Python-String
        if existing == comment:
            n_comment_same += 1
        else:
            if existing is not None and not existing.startswith(COMMENT_PREFIX):
                n_comment_replaced += 1
            setPlateComment(comment_addr, comment)
            n_comment_set += 1

        # (b) Label "rea_<sanitized>" - nur anlegen, wenn an der Adresse
        #     noch kein USER_DEFINED-Symbol existiert (haelt es idempotent
        #     und laesst manuell gepflegte Labels unangetastet).
        if has_user_defined_symbol(st, addr):
            n_label_skipped_user += 1
            continue
        label_name = choose_label_name(st, LABEL_PREFIX + sanitize_label(annotation),
                                       addr, addr_int)
        try:
            st.createLabel(addr, label_name, SourceType.USER_DEFINED)
            n_label_created += 1
        except Exception as exc:
            n_label_failed += 1
            println("REA: Label '" + label_name + "' fehlgeschlagen bei " + str(addr) + ": " + str(exc))

    applied = n_comment_set + n_label_created
    skipped = (n_comment_same + n_label_skipped_user + n_addr_not_in_program +
               n_unparsable_addr)
    println("REA: Zusammenfassung")
    println("  CSV-Zeilen gesamt: %d, mit Annotation: %d" % (n_rows, n_annotated))
    println("  Angewendet: %d  (Plate-Kommentare gesetzt: %d, davon ersetzt: %d; Labels neu: %d)"
            % (applied, n_comment_set, n_comment_replaced, n_label_created))
    println("  Uebersprungen: %d  (Kommentar unveraendert: %d; USER_DEFINED-Label vorhanden: %d)"
            % (skipped, n_comment_same, n_label_skipped_user))
    println("  Hinweise: Adresse nicht im Programm: %d; ohne Funktion (Kontext): %d; Label-Fehler: %d; unlesbare Adresse: %d"
            % (n_addr_not_in_program, n_without_function, n_label_failed, n_unparsable_addr))


run()
