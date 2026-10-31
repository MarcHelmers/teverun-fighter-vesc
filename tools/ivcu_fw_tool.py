#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
ivcu_fw_tool.py
===============
CLI-Werkzeug fuer Teverun-IVCU-Firmware im Intel-HEX-Format.
Reines Python 3, keine externen Abhaengigkeiten. Das Original wird nie veraendert.

Befehle
-------
  info         <hex>                          Ueberblick: Basisadresse, Regionen, Version, CRC, SHA-256
  validate     <hex>                          strenge Pruefung (Zeilenchecksummen, Recordtypen, CRC, Version)
  set-version  <hex> <a.b.c> -o <out.hex>     Versionsbytes NUR im Trailer patchen (Image bleibt unveraendert)
  patch        <hex> <adresse>=<hexbytes> ... -o <out.hex>
                                              Bytes im Image patchen, CRC wird neu berechnet
  dump         <hex> <adresse> <laenge>       Hexdump ueber einen Adressbereich
  --selftest                                  Selbsttest gegen die Beispieldatei AWIVCU_APP_R3_4_13.hex

Formatwissen (an der Beispieldatei verifiziert)
-----------------------------------------------
* Datenblock 0x08007000-0x0801DDBB (0x16DBC = 93628 Bytes), 16-Byte-Datensaetze.
  Basisadresse ueber Extended-Linear-Address-Records:
    ":020000040800F2" zu Beginn (Basis 0x08000000),
    ":020000040801F1" an der 64K-Grenze (Basis 0x08010000).
* Vor dem EOF steht der Start-Linear-Address-Record ":040000050800714935".
* EOF-Record: ":00000001FF".
* NACH dem EOF steht ein Hersteller-Trailer-Record:
      ":07AAA555" + [uId_BE(2)] [ver_major ver_minor ver_patch] [crc_hi crc_lo] + Checksumme
  Beispiel: ":07AAA555000003040DE349EB"
      -> uId/Projekt 0x0000, Version 3.4.13, CRC-16/MODBUS 0xE349
  Die CRC laeuft ueber ALLE Image-Bytes in Adressreihenfolge (Luecken gibt es nicht).
* CRC-16/MODBUS: Polynom 0x8005 reflektiert (0xA001), Init 0xFFFF, kein Final-XOR.
* Zeilenchecksumme der Standard-Records (Typen 00-05):
  Zweierkomplement der Summe aller Bytes vor der Checksumme.
* Sonderfall Trailer-Record: Der Hersteller verwendet hier NICHT das Zweierkomplement,
  sondern die rohe Summe & 0xFF (im Beispiel 0x2EB & 0xFF = 0xEB, verifiziert am Original).
  Dieses Werkzeug reproduziert beim Schreiben exakt diese Regel und akzeptiert beim
  Pruefen zusaetzlich das Standard-Zweierkomplement (tolerant, mit Hinweis).

Sicherheit
----------
* Eingabedateien werden ausschliesslich gelesen; Ausgaben gehen nur an -o bzw. in Temp-Dateien.
* Die Ausgabedatei darf nicht die Eingabedatei sein (Schutz vor versehentlichem Ueberschreiben).
* Nach jedem Schreiben wird die Ausgabedatei automatisch neu geparst und validiert.
"""

import argparse
import hashlib
import os
import re
import shutil
import sys
import tempfile
from dataclasses import dataclass, field

# --------------------------------------------------------------------------- #
# Konstanten / Formatwissen
# --------------------------------------------------------------------------- #

SAMPLE_NAME = "AWIVCU_APP_R3_4_13.hex"   # Beispieldatei fuer den Selbsttest
DEFAULT_SLA = 0x08007149                 # Startadresse aus ":040000050800714935"
TRAILER_ADDR16 = 0xAAA5                  # "Adresse" des Trailer-Records (:07AAA555 ...)
TRAILER_TYPE = 0x55                      # Custom-Recordtyp 0x55 (nicht Intel-Standard)
DEFAULT_UID = 0x0000                     # uId/Projektfeld, Standardwert der Beispieldatei
DEFAULT_EOL = "\r\n"                     # Beispieldatei ist CRLF-formatiert

# Erwartete Kenngroessen der Beispieldatei (fuer den Selbsttest)
SAMPLE_VERSION = (3, 4, 13)
SAMPLE_CRC = 0xE349
SAMPLE_ERSTE = 0x08007000
SAMPLE_LETZTE = 0x0801DDBB
SAMPLE_GROESSE = 0x16DBC

INTEL_TYPEN = {
    0x00: "Daten",
    0x01: "EOF",
    0x02: "Extended-Segment-Adresse",
    0x03: "Start-Segment-Adresse",
    0x04: "Extended-Linear-Adresse",
    0x05: "Start-Linear-Adresse",
}


class HexFehler(Exception):
    """Fataler Fehler: Datei nicht lesbar, kein Intel-HEX, ungueltiger Patch usw."""


# --------------------------------------------------------------------------- #
# CRC-16/MODBUS
# --------------------------------------------------------------------------- #

_CRC_TABELLE = None


def _crc_tabelle():
    """Baut (einmalig) die 256er-Lookup-Tabelle fuer das reflektierte Polynom 0xA001."""
    global _CRC_TABELLE
    if _CRC_TABELLE is None:
        tabelle = []
        for i in range(256):
            c = i
            for _ in range(8):
                c = (c >> 1) ^ 0xA001 if c & 1 else c >> 1
            tabelle.append(c)
        _CRC_TABELLE = tabelle
    return _CRC_TABELLE


def crc16_modbus(daten):
    """CRC-16/MODBUS ueber 'daten': Init 0xFFFF, Poly 0xA001 (reflektiert), kein Final-XOR."""
    crc = 0xFFFF
    tabelle = _crc_tabelle()
    for b in daten:
        crc = (crc >> 8) ^ tabelle[(crc ^ b) & 0xFF]
    return crc


# --------------------------------------------------------------------------- #
# Kleine Hilfsfunktionen
# --------------------------------------------------------------------------- #

def parse_zahl(text):
    """Zahl aus CLI-Text: '0x...' = hex, fuehrende Null = hex (z. B. 0801DA43), sonst dezimal."""
    s = str(text).strip().replace("_", "")
    if s.lower().startswith("0x"):
        return int(s, 16)
    if re.fullmatch(r"[0-9]+", s):
        return int(s, 16) if (len(s) > 1 and s[0] == "0") else int(s, 10)
    if re.fullmatch(r"[0-9a-fA-F]+", s):
        return int(s, 16)
    raise HexFehler(f"'{text}' ist keine gueltige Zahl (dezimal, 0x-hex oder fuehrende-Null-hex).")


def parse_bytes_hex(text):
    """Bytefolge aus CLI-Text, IMMER hexadezimal: '64', '0x64', 'DE AD BE EF' usw."""
    s = re.sub(r"[\s_:,;-]", "", str(text))
    if s.lower().startswith("0x"):
        s = s[2:]
    if not s:
        raise HexFehler("Leere Bytefolge (erwartet Hexbytes, z. B. 64 oder 0x64).")
    if len(s) % 2 != 0:
        raise HexFehler(f"Hexbytefolge '{text}' hat eine ungerade Anzahl Ziffern.")
    if not re.fullmatch(r"[0-9a-fA-F]+", s):
        raise HexFehler(f"Hexbytefolge '{text}' enthaelt ungueltige Zeichen.")
    return bytes.fromhex(s)


def parse_version(text):
    """Version 'a.b.c' -> Tupel (a, b, c), jeder Teil 0..255; Dezimal oder 0x-Hex."""
    teile = str(text).strip().split(".")
    if len(teile) != 3:
        raise HexFehler(f"Version '{text}' hat nicht das Format a.b.c (drei Zahlen 0-255).")
    werte = []
    for teil in teile:
        t = teil.strip()
        if not t:
            raise HexFehler(f"Version '{text}' enthaelt einen leeren Teil.")
        if t.lower().startswith("0x"):
            wert = int(t, 16)
        elif re.fullmatch(r"[0-9]+", t):
            wert = int(t, 10)
        elif re.fullmatch(r"[0-9a-fA-F]+", t):
            wert = int(t, 16)
        else:
            raise HexFehler(f"Versionsteil '{teil}' ist keine Zahl.")
        if not 0 <= wert <= 255:
            raise HexFehler(f"Versionsteil '{teil}' liegt ausserhalb von 0..255.")
        werte.append(wert)
    return tuple(werte)


def version_text(ver):
    """(3, 4, 13) -> '3.4.13'."""
    return f"{ver[0]}.{ver[1]}.{ver[2]}"


def parse_patch_token(token):
    """'<adresse>=<hexbytes>' -> (adresse, bytes)."""
    if "=" not in token:
        raise HexFehler(f"Patch '{token}': Format ADRESSE=HEXBYTES erwartet (z. B. 0x0801DA43=64).")
    links, rechts = token.split("=", 1)
    return parse_zahl(links), parse_bytes_hex(rechts)


def gleicher_pfad(a, b):
    """True, wenn beide Pfade dieselbe Datei bezeichnen (Windows: case-insensitiv)."""
    try:
        return os.path.samefile(a, b)
    except OSError:
        return os.path.normcase(os.path.abspath(a)) == os.path.normcase(os.path.abspath(b))


def kib_text(anzahl):
    """'93628 Bytes (0x16DBC, 91.4 KiB)'-Teiltext."""
    return f"{anzahl} Bytes = 0x{anzahl:X}, {anzahl / 1024:.1f} KiB"


# --------------------------------------------------------------------------- #
# Datenklassen: Record, Trailer, FirmwareImage
# --------------------------------------------------------------------------- #

@dataclass
class Record:
    """Ein geparster Intel-HEX-Record (eine Dateizeile)."""
    zeile: int              # 1-basierte Zeilennummer in der Datei (physisch)
    text: str               # Originalzeile (ohne Zeilenumbruch)
    roh: bytes              # dekodierte Bytes inkl. Checksumme (ohne ':')
    count: int              # Byte-Count-Feld
    addr16: int             # 16-Bit-Adressfeld
    typ: int                # Recordtyp
    daten: bytes            # Nutzdaten
    checksumme: int         # Checksummenbyte der Zeile

    @property
    def std_ok(self):
        """Zeilenchecksumme nach Intel-Standard (Zweierkomplement) korrekt?"""
        return self.checksumme == (-sum(self.roh[:-1])) & 0xFF

    @property
    def sum_ok(self):
        """Hersteller-Sonderregel (rohe Summe & 0xFF) - gilt fuer den Trailer-Record."""
        return self.checksumme == sum(self.roh[:-1]) & 0xFF

    @property
    def ist_trailer(self):
        """Erkennt den Hersteller-Trailer ':07AAA555 ...' (Typ 0x55, Adr 0xAAA5, 7 Datenbytes)."""
        return self.typ == TRAILER_TYPE and self.addr16 == TRAILER_ADDR16 and self.count == 7


@dataclass
class Trailer:
    """Inhalt des Hersteller-Trailer-Records nach dem EOF."""
    record: Record
    uid: int                      # uId/Projekt (Big-Endian aus 2 Bytes)
    version: tuple                # (major, minor, patch)
    crc: int                      # CRC-16/MODBUS ueber alle Image-Bytes
    regel: str                    # erkannte Checksummenregel ("Vendor" / "Standard")


@dataclass
class FirmwareImage:
    """Geparste Firmware: Records, Regionen (Adresse -> Bytes), Trailer, SLA."""
    pfad: str
    eol: str
    zeilen: list                  # nicht-leere Originalzeilen
    records: list                 # alle Record-Objekte
    datenrecords: list            # nur Typ-00-Records
    regionen: list                # [(startadresse, bytearray)] aufsteigend, lueckenlos zusammengefasst
    basisadresse: int
    basis_quelle: str
    sla: int
    trailer: Trailer
    eof_zeile: int                # Zeilennummer des EOF-Records (oder None)
    fehler: list = field(default_factory=list)
    warnungen: list = field(default_factory=list)

    # ---- Abfragen -------------------------------------------------------- #

    def image_bytes(self):
        """Alle Image-Bytes in Adressreihenfolge (Basis fuer CRC und SHA-256)."""
        return b"".join(bytes(daten) for _, daten in self.regionen)

    def groesse(self):
        return sum(len(daten) for _, daten in self.regionen)

    def erste_adresse(self):
        return self.regionen[0][0] if self.regionen else 0

    def letzte_adresse(self):
        if not self.regionen:
            return 0
        start, daten = self.regionen[-1]
        return start + len(daten) - 1

    def crc(self):
        """CRC-16/MODBUS ueber alle Image-Bytes."""
        return crc16_modbus(self.image_bytes())

    def sha256(self):
        return hashlib.sha256(self.image_bytes()).hexdigest()

    def lese_bytes(self, adresse, laenge):
        """Bytes ab 'adresse' lesen; None, wenn die Adresse nicht im Image liegt.
        Das Ergebnis wird am Regionen-Ende geklemmt."""
        for start, daten in self.regionen:
            if start <= adresse < start + len(daten):
                off = adresse - start
                return bytes(daten[off:off + laenge])
        return None

    def adress_abgedeckt(self, adresse, laenge=1):
        """True, wenn [adresse, adresse+laenge) vollstaendig in einer Region liegt."""
        for start, daten in self.regionen:
            if start <= adresse and adresse + laenge <= start + len(daten):
                return True
        return False

    def patche(self, adresse, daten):
        """Bytes im Image ueberschreiben (in-place); Fehler, wenn nicht vollstaendig abgedeckt."""
        if not daten:
            raise HexFehler("Patch ohne Datenbytes.")
        for start, puffer in self.regionen:
            if start <= adresse and adresse + len(daten) <= start + len(puffer):
                off = adresse - start
                puffer[off:off + len(daten)] = daten
                return
        raise HexFehler(
            f"Adresse 0x{adresse:08X} (+{len(daten)} Bytes) liegt ausserhalb des Images "
            f"(0x{self.erste_adresse():08X}-0x{self.letzte_adresse():08X})."
        )


# --------------------------------------------------------------------------- #
# HEX-Datei einlesen
# --------------------------------------------------------------------------- #

def _baue_regionen(teile, fehler, warnungen):
    """Datenstuecke (adresse, bytes, zeile) zu lueckenlosen Regionen zusammenfassen.
    Ueberlappungen werden auf Identitaet geprueft (identisch = Warnung, Konflikt = Fehler)."""
    regionen = []
    for adresse, daten, zeile in sorted(teile, key=lambda t: (t[0], t[2])):
        d = bytes(daten)
        if regionen:
            start, puffer = regionen[-1]
            ende = start + len(puffer)
            if adresse < ende:
                ueberlappung = ende - adresse
                if puffer[adresse - start:] == d[:ueberlappung]:
                    rest = d[ueberlappung:]
                    if rest:
                        puffer.extend(rest)
                    else:
                        warnungen.append(f"Zeile {zeile}: doppelter Record (identische Daten @0x{adresse:08X})")
                else:
                    fehler.append(f"Zeile {zeile}: widerspruechliche ueberlappende Daten @0x{adresse:08X}")
                continue
            if adresse == ende:
                puffer.extend(d)
                continue
        regionen.append((adresse, bytearray(d)))
    return regionen


def lade_hex(pfad):
    """Intel-HEX-Datei einlesen und vollstaendig auswerten.

    Strukturelle Fehler landen in 'fehler' (fuer validate), harte Probleme (nicht lesbar,
    kein ASCII usw.) werfen HexFehler."""
    try:
        rohdaten = open(pfad, "rb").read()
    except OSError as e:
        raise HexFehler(f"Datei kann nicht gelesen werden: {e}")
    if not rohdaten:
        raise HexFehler("Datei ist leer.")

    eol = "\r\n" if b"\r\n" in rohdaten else "\n"
    try:
        text = rohdaten.decode("ascii")
    except UnicodeDecodeError:
        raise HexFehler("Datei enthaelt Nicht-ASCII-Zeichen - kein Intel-HEX?")

    alle_zeilen = text.splitlines()
    zeilen = [z for z in alle_zeilen if z.strip()]

    fehler = []
    warnungen = []
    records = []
    datenrecords = []
    datenteile = []
    basisadresse = None
    basis_quelle = "aus Datenbereich abgeleitet"
    aktuell_basis = 0
    sla = None
    trailer = None
    eof_zeile = None
    eof_sehen = False

    for nr, rohzeile in enumerate(alle_zeilen, 1):
        s = rohzeile.strip()
        if not s:
            continue  # Leerzeilen werden ignoriert
        if not s.startswith(":"):
            fehler.append(f"Zeile {nr}: kein ':' am Zeilenanfang")
            continue
        hexteil = s[1:].strip()
        if not re.fullmatch(r"[0-9a-fA-F]*", hexteil):
            fehler.append(f"Zeile {nr}: ungueltige Hex-Zeichen")
            continue
        if len(hexteil) % 2 or len(hexteil) < 10:
            fehler.append(f"Zeile {nr}: Record-Laenge ungueltig ({len(hexteil)} Hexziffern)")
            continue
        roh = bytes.fromhex(hexteil)
        count = roh[0]
        if len(roh) != count + 5:
            fehler.append(f"Zeile {nr}: Byte-Count {count} passt nicht zur Zeilenlaenge ({len(roh) - 5} Datenbytes)")
            continue
        addr16 = (roh[1] << 8) | roh[2]
        typ = roh[3]
        rec = Record(zeile=nr, text=s, roh=roh, count=count, addr16=addr16,
                     typ=typ, daten=roh[4:4 + count], checksumme=roh[-1])
        records.append(rec)

        # ---- Records nach dem EOF: nur der Trailer-Record ist erlaubt ---------- #
        if eof_sehen:
            if rec.ist_trailer:
                if trailer is not None:
                    fehler.append(f"Zeile {nr}: zweiter Trailer-Record")
                    continue
                daten = rec.daten
                uid = (daten[0] << 8) | daten[1]
                version = (daten[2], daten[3], daten[4])
                crc = (daten[5] << 8) | daten[6]
                if rec.sum_ok:
                    regel = "Vendor (rohe Summe & 0xFF)"
                elif rec.std_ok:
                    regel = "Standard (Zweierkomplement)"
                    warnungen.append(
                        f"Zeile {nr}: Trailer-Checksumme folgt dem Standard-Zweierkomplement, "
                        f"nicht der Vendor-Regel (Summe & 0xFF)"
                    )
                else:
                    regel = "ungueltig"
                    fehler.append(
                        f"Zeile {nr}: Trailer-Checksumme falsch (gefunden 0x{rec.checksumme:02X}, "
                        f"Vendor-Regel erwartet 0x{sum(rec.roh[:-1]) & 0xFF:02X}, "
                        f"Standard erwartet 0x{(-sum(rec.roh[:-1])) & 0xFF:02X})"
                    )
                trailer = Trailer(record=rec, uid=uid, version=version, crc=crc, regel=regel)
            elif typ == 0x01:
                fehler.append(f"Zeile {nr}: doppelter EOF-Record")
            else:
                fehler.append(f"Zeile {nr}: unerwarteter Record nach dem EOF (Typ 0x{typ:02X})")
            continue

        # ---- Records vor dem EOF ------------------------------------------------- #
        if typ == 0x00:                                  # Datensatz
            if not rec.std_ok:
                fehler.append(
                    f"Zeile {nr}: Zeilenchecksumme falsch (gefunden 0x{rec.checksumme:02X}, "
                    f"erwartet 0x{(-sum(rec.roh[:-1])) & 0xFF:02X})"
                )
            datenteile.append((aktuell_basis + addr16, rec.daten, nr))
            datenrecords.append(rec)
        elif typ == 0x01:                                # EOF
            eof_sehen = True
            eof_zeile = nr
            if count != 0:
                fehler.append(f"Zeile {nr}: EOF-Record mit {count} Datenbytes (erwartet 0)")
            if not rec.std_ok:
                fehler.append(f"Zeile {nr}: EOF-Checksumme falsch")
        elif typ == 0x04:                                # Extended Linear Address
            if not rec.std_ok:
                fehler.append(f"Zeile {nr}: Checksumme des Extended-Linear-Address-Records falsch")
            if count != 2:
                fehler.append(f"Zeile {nr}: Extended-Linear-Address-Record mit {count} statt 2 Datenbytes")
            else:
                aktuell_basis = int.from_bytes(rec.daten, "big") << 16
                if basisadresse is None:
                    basisadresse = aktuell_basis
                    basis_quelle = "Extended-Linear-Address-Record"
        elif typ == 0x05:                                # Start Linear Address
            if not rec.std_ok:
                fehler.append(f"Zeile {nr}: Checksumme des Start-Linear-Address-Records falsch")
            if count != 4:
                fehler.append(f"Zeile {nr}: Start-Linear-Address-Record mit {count} statt 4 Datenbytes")
            else:
                sla = int.from_bytes(rec.daten, "big")
        elif typ == 0x02:                                # Extended Segment Address (tolerant)
            if not rec.std_ok:
                fehler.append(f"Zeile {nr}: Checksumme des Extended-Segment-Adress-Records falsch")
            if count == 2:
                aktuell_basis = int.from_bytes(rec.daten, "big") << 4
                if basisadresse is None:
                    basisadresse = aktuell_basis
                    basis_quelle = "Extended-Segment-Adress-Record"
            warnungen.append(f"Zeile {nr}: Extended-Segment-Adress-Record (Typ 02) - fuer dieses Format ungewoehnlich")
        elif typ == 0x03:                                # Start Segment Address (wird ignoriert)
            if not rec.std_ok:
                fehler.append(f"Zeile {nr}: Checksumme des Start-Segment-Adress-Records falsch")
            warnungen.append(f"Zeile {nr}: Start-Segment-Adress-Record (Typ 03) ignoriert")
        else:
            fehler.append(f"Zeile {nr}: unbekannter Recordtyp 0x{typ:02X}")
        # EOF-Zeile als eof_zeile merken ist oben erledigt

    # ---- Gesamtbefunde ---------------------------------------------------- #
    if not eof_sehen:
        fehler.append("EOF-Record (:00000001FF) fehlt")
    if trailer is None:
        fehler.append("Trailer-Record (:07AAA555 ...) fehlt")
    if not datenteile:
        fehler.append("Keine Datensaetze (Recordtyp 00) vorhanden")

    regionen = _baue_regionen(datenteile, fehler, warnungen)
    if basisadresse is None and regionen:
        basisadresse = regionen[0][0] & 0xFFFF0000
    if basisadresse is None:
        basisadresse = 0

    return FirmwareImage(
        pfad=os.path.abspath(pfad),
        eol=eol,
        zeilen=zeilen,
        records=records,
        datenrecords=datenrecords,
        regionen=regionen,
        basisadresse=basisadresse,
        basis_quelle=basis_quelle,
        sla=sla,
        trailer=trailer,
        eof_zeile=eof_zeile,
        fehler=fehler,
        warnungen=warnungen,
    )


# --------------------------------------------------------------------------- #
# Validierung (auf bereits geparster Datei)
# --------------------------------------------------------------------------- #

def pruefe_image(img):
    """Liefert (fehler, warnungen): Formatbefunde aus dem Parsing plus CRC-/Plausibilitaetschecks."""
    fehler = list(img.fehler)
    warnungen = list(img.warnungen)

    if len(img.regionen) > 1:
        luecken = []
        for (s1, d1), (s2, _) in zip(img.regionen, img.regionen[1:]):
            luecken.append((s1 + len(d1), s2 - 1))
        warnungen.append(
            f"{len(luecken)} Luecke(n) im Image, z. B. 0x{luecken[0][0]:08X}-0x{luecken[0][1]:08X}"
        )

    if img.trailer is not None:
        berechnet = img.crc()
        if berechnet != img.trailer.crc:
            fehler.append(
                f"CRC-Abgleich fehlgeschlagen: Trailer 0x{img.trailer.crc:04X} != berechnet 0x{berechnet:04X}"
            )
        a, b, c = img.trailer.version
        if (a, b, c) in ((0, 0, 0), (255, 255, 255)):
            warnungen.append(f"Trailer-Version unplausibel: {version_text(img.trailer.version)}")

    return fehler, warnungen


def berichte_validierung(pfad):
    """Ausgabedatei neu parsen, pruefen und Ergebnis drucken. True = fehlerfrei."""
    img = lade_hex(pfad)
    fehler, warnungen = pruefe_image(img)
    for f in fehler:
        print(f"  FEHLER   : {f}")
    for w in warnungen:
        print(f"  WARNUNG  : {w}")
    if fehler:
        print(f"Validierung       : FAIL ({len(fehler)} Fehler, {len(warnungen)} Warnungen)")
        return False
    zusatz = f", {len(warnungen)} Warnung(en)" if warnungen else ""
    print(f"Validierung       : PASS (0 Fehler{zusatz})")
    return True


# --------------------------------------------------------------------------- #
# HEX-Datei schreiben
# --------------------------------------------------------------------------- #

def format_record(typ, addr16, daten):
    """Standard-Intel-HEX-Zeile mit Zweierkomplement-Checksumme (Typen 00-05)."""
    kopf = bytes([len(daten), (addr16 >> 8) & 0xFF, addr16 & 0xFF, typ]) + bytes(daten)
    cks = (-sum(kopf)) & 0xFF
    return ":" + (kopf + bytes([cks])).hex().upper()


def format_trailer(uid, version, crc):
    """Hersteller-Trailer-Record ':07AAA555 ...' bauen.

    ACHTUNG Sonderfall: Der Hersteller setzt hier NICHT das Zweierkomplement,
    sondern die rohe Summe & 0xFF als Checksummenbyte (verifiziert am Original:
    ':07AAA555000003040DE349EB' -> 0x2EB & 0xFF = 0xEB)."""
    daten = bytes([
        (uid >> 8) & 0xFF, uid & 0xFF,
        version[0] & 0xFF, version[1] & 0xFF, version[2] & 0xFF,
        (crc >> 8) & 0xFF, crc & 0xFF,
    ])
    kopf = bytes([len(daten), 0xAA, 0xA5, TRAILER_TYPE]) + daten
    cks = sum(kopf) & 0xFF
    return ":" + (kopf + bytes([cks])).hex().upper()


def baue_hex_text(img, version=None, crc=None, uid=None):
    """Komplette Ausgabe-HEX erzeugen:
    ELAR-Records bei Bedarf -> 16-Byte-Datensaetze -> SLA -> EOF -> Trailer (mit neuen Werten)."""
    if version is None:
        version = img.trailer.version if img.trailer else (0, 0, 0)
    if crc is None:
        crc = img.crc()  # immer neu berechnen
    if uid is None:
        uid = img.trailer.uid if img.trailer else DEFAULT_UID
    sla = img.sla if img.sla is not None else DEFAULT_SLA  # SLA erhalten bzw. Standard setzen

    zeilen = []
    seite = None
    for start, daten in img.regionen:
        pos = 0
        while pos < len(daten):
            adresse = start + pos
            aktuelle_seite = adresse >> 16
            if aktuelle_seite != seite:  # Satzgrenze/64K-Grenze -> neuen ELAR-Record ausgeben
                zeilen.append(format_record(0x04, 0, bytes([(aktuelle_seite >> 8) & 0xFF, aktuelle_seite & 0xFF])))
                seite = aktuelle_seite
            addr16 = adresse & 0xFFFF
            anzahl = min(16, len(daten) - pos, 0x10000 - addr16)  # nie ueber 64K-Grenze hinaus
            zeilen.append(format_record(0x00, addr16, bytes(daten[pos:pos + anzahl])))
            pos += anzahl

    zeilen.append(format_record(0x05, 0, sla.to_bytes(4, "big")))   # ':040000050800714935'
    zeilen.append(format_record(0x01, 0, b""))                      # ':00000001FF'
    zeilen.append(format_trailer(uid, version, crc))
    return img.eol.join(zeilen) + img.eol


def schreibe_hex(img, zielpfad, version=None, crc=None, uid=None):
    """Ausgabe-HEX schreiben. Die Eingabedatei ist als Ziel gesperrt (Originalschutz)."""
    if gleicher_pfad(img.pfad, zielpfad):
        raise HexFehler("Ausgabedatei ist die Eingabedatei - die Originaldatei wird niemals ueberschrieben.")
    text = baue_hex_text(img, version=version, crc=crc, uid=uid)
    try:
        with open(zielpfad, "w", encoding="ascii", newline="") as fh:
            fh.write(text)
    except OSError as e:
        raise HexFehler(f"Ausgabedatei kann nicht geschrieben werden: {e}")
    return text


# --------------------------------------------------------------------------- #
# Befehle
# --------------------------------------------------------------------------- #

def cmd_info(args):
    """Ueberblick ueber die Firmware-Datei."""
    img = lade_hex(args.hex)

    print(f"{'Datei':<18}: {img.pfad}")
    print(f"{'Format':<18}: Intel-HEX, {len(img.records)} Records, Zeilenende {'CRLF' if img.eol == chr(13) + chr(10) else 'LF'}")
    print(f"{'Basisadresse':<18}: 0x{img.basisadresse:08X} ({img.basis_quelle})")

    if len(img.regionen) == 1:
        start, daten = img.regionen[0]
        print(f"{'Region(en)':<18}: 1 Region: 0x{start:08X} - 0x{start + len(daten) - 1:08X} ({kib_text(len(daten))})")
    else:
        print(f"{'Region(en)':<18}: {len(img.regionen)} Regionen")
        for start, daten in img.regionen:
            print(f"{'':<18}  0x{start:08X} - 0x{start + len(daten) - 1:08X} ({kib_text(len(daten))})")

    print(f"{'Erste/Letzte Adr.':<18}: 0x{img.erste_adresse():08X} / 0x{img.letzte_adresse():08X}")

    if img.trailer is not None:
        print(f"{'Version (Trailer)':<18}: {version_text(img.trailer.version)} (uId/Projekt 0x{img.trailer.uid:04X})")
        crc_berechnet = img.crc()
        status = "OK" if crc_berechnet == img.trailer.crc else "FEHLER (stimmt nicht ueberein)"
        print(f"{'CRC':<18}: Datei 0x{img.trailer.crc:04X} / berechnet 0x{crc_berechnet:04X} -> {status}")
    else:
        print(f"{'Version (Trailer)':<18}: kein Trailer-Record vorhanden")
        print(f"{'CRC':<18}: kein Trailer-Record vorhanden")

    print(f"{'Startadresse (SLA)':<18}: " + (f"0x{img.sla:08X}" if img.sla is not None else "nicht vorhanden"))
    print(f"{'SHA-256 (Image)':<18}: {img.sha256()}")

    if img.fehler:
        print(f"Hinweis: {len(img.fehler)} Formatauffaelligkeit(en) - Details mit 'validate {args.hex}'.")
    return 0


def cmd_validate(args):
    """Strenge Formatpruefung; Exit-Code 0 = gueltig, 1 = fehlerhaft."""
    img = lade_hex(args.hex)
    fehler, warnungen = pruefe_image(img)

    anzahl = {t: sum(1 for r in img.records if r.typ == t) for t in (0x00, 0x01, 0x04, 0x05)}
    trailer_n = sum(1 for r in img.records if r.ist_trailer)

    ok_cks, bad_cks = 0, 0
    for r in img.records:
        gut = (r.std_ok or r.sum_ok) if r.ist_trailer else r.std_ok
        ok_cks += 1 if gut else 0
        bad_cks += 0 if gut else 1

    print(f"{'Validiere':<18}: {img.pfad}")
    print(f"{'Records':<18}: {len(img.records)} von {len(img.zeilen)} Zeilen "
          f"(Daten {anzahl[0x00]}, ELAR {anzahl[0x04]}, SLA {anzahl[0x05]}, EOF {anzahl[0x01]}, Trailer {trailer_n})")
    print(f"{'Zeilenchecksummen':<18}: {ok_cks} OK, {bad_cks} fehlerhaft")

    if img.trailer is not None:
        print(f"{'Trailer':<18}: Version {version_text(img.trailer.version)}, CRC 0x{img.trailer.crc:04X}, "
              f"Checksumme 0x{img.trailer.record.checksumme:02X} ({img.trailer.regel})")
        crc_berechnet = img.crc()
        status = "OK" if crc_berechnet == img.trailer.crc else "FEHLER"
        print(f"{'CRC-Abgleich':<18}: 0x{img.trailer.crc:04X} (Datei) vs. 0x{crc_berechnet:04X} (berechnet) -> {status}")
    else:
        print(f"{'Trailer':<18}: FEHLT")

    lueckenfrei = "lueckenlos" if len(img.regionen) == 1 else f"{len(img.regionen)} Regionen"
    print(f"{'Image':<18}: {lueckenfrei}, {img.groesse()} Bytes (0x{img.erste_adresse():08X}-0x{img.letzte_adresse():08X})")

    for f in fehler:
        print(f"  FEHLER   : {f}")
    for w in warnungen:
        print(f"  WARNUNG  : {w}")

    if fehler:
        print(f"{'Ergebnis':<18}: FAIL ({len(fehler)} Fehler, {len(warnungen)} Warnungen)")
        return 1
    print(f"{'Ergebnis':<18}: PASS (0 Fehler, {len(warnungen)} Warnungen)")
    return 0


def cmd_set_version(args):
    """Versionsbytes im Trailer patchen; Image-Bytes und CRC bleiben unveraendert."""
    img = lade_hex(args.hex)
    if img.trailer is None:
        raise HexFehler("Kein Trailer-Record vorhanden - set-version nicht moeglich.")
    neue_version = parse_version(args.version)
    alte_version = img.trailer.version
    crc = img.crc()  # Image wird nicht angefasst -> CRC bleibt gleich (wird neu berechnet/sichergestellt)

    schreibe_hex(img, args.output, version=neue_version, crc=crc)

    print(f"Version (alt)     : {version_text(alte_version)}")
    print(f"Version (neu)     : {version_text(neue_version)}")
    print(f"CRC (unveraendert): 0x{crc:04X}  (neu berechnet ueber die unveraenderten Image-Bytes)")
    print(f"Hinweis           : Es wurde NUR der Trailer-Record gepatcht. Die Image-Bytes "
          f"0x{img.erste_adresse():08X}-0x{img.letzte_adresse():08X} bleiben vollstaendig unveraendert.")
    print(f"Ausgabe           : {os.path.abspath(args.output)}")
    ok = berichte_validierung(args.output)
    return 0 if ok else 1


def cmd_patch(args):
    """Bytes im Image patchen; CRC wird anschliessend neu berechnet und im Trailer aktualisiert."""
    img = lade_hex(args.hex)
    if img.trailer is None:
        raise HexFehler("Kein Trailer-Record vorhanden - patch nicht moeglich (CRC-Ziel fehlt).")

    crc_alt = img.crc()
    patchliste = [parse_patch_token(t) for t in args.patches]

    for i, (adresse, daten) in enumerate(patchliste, 1):
        if not img.adress_abgedeckt(adresse, len(daten)):
            raise HexFehler(
                f"Patch {i}: Adressbereich 0x{adresse:08X} (+{len(daten)} Bytes) liegt ausserhalb "
                f"des Images (0x{img.erste_adresse():08X}-0x{img.letzte_adresse():08X})."
            )
        alt = img.lese_bytes(adresse, len(daten))
        img.patche(adresse, daten)
        marker = "  (unveraendert)" if alt == daten else ""
        print(f"Patch {i}           : 0x{adresse:08X}  {alt.hex(' ').upper()} -> {daten.hex(' ').upper()}{marker}")

    crc_neu = img.crc()
    schreibe_hex(img, args.output, version=img.trailer.version, crc=crc_neu)

    print(f"CRC               : 0x{crc_alt:04X} -> 0x{crc_neu:04X}  (neu berechnet ueber das gepatchte Image)")
    print(f"Version           : {version_text(img.trailer.version)}  (Trailer-Version unveraendert)")
    print(f"Hinweis           : Image-Bytes wurden geaendert; CRC im Trailer wurde aktualisiert.")
    print(f"Ausgabe           : {os.path.abspath(args.output)}")
    ok = berichte_validierung(args.output)
    return 0 if ok else 1


def cmd_dump(args):
    """Hexdump ueber einen Adressbereich des Images."""
    img = lade_hex(args.hex)
    start = parse_zahl(args.adresse)
    laenge = parse_zahl(args.laenge)
    if laenge <= 0:
        raise HexFehler("Laenge muss groesser als 0 sein.")
    if img.lese_bytes(start, 1) is None:
        raise HexFehler(
            f"Startadresse 0x{start:08X} liegt ausserhalb des Images "
            f"(0x{img.erste_adresse():08X}-0x{img.letzte_adresse():08X})."
        )
    ende = start + laenge
    image_ende = img.letzte_adresse() + 1
    if ende > image_ende:
        print(f"Hinweis: Bereich wird am Image-Ende (0x{image_ende - 1:08X}) beschnitten.")
        ende = image_ende

    adresse = start
    while adresse < ende:
        anzahl = min(16, ende - adresse)
        zeile = img.lese_bytes(adresse, anzahl)
        if zeile is None:  # Luecke (bei mehreren Regionen): als '--' darstellen
            hexteil = "--"
            ascii_teil = ""
        else:
            hexteil = " ".join(f"{b:02X}" for b in zeile).ljust(47)
            ascii_teil = "".join(chr(b) if 32 <= b < 127 else "." for b in zeile)
        print(f"0x{adresse:08X}  {hexteil}  |{ascii_teil}|")
        adresse += anzahl
    return 0


# --------------------------------------------------------------------------- #
# Selbsttest
# --------------------------------------------------------------------------- #

def cmd_selftest(args):
    """Selbsttest: Beispieldatei analysieren, Roundtrip pruefen, Patchpfad pruefen."""
    sample = args.sample or os.path.join(os.path.dirname(os.path.abspath(__file__)), SAMPLE_NAME)
    print("=== Selbsttest ivcu_fw_tool ===")
    print(f"Beispieldatei: {sample}")
    if not os.path.isfile(sample):
        print(f"[FAIL] Beispieldatei nicht gefunden: {sample}")
        print("SELFTEST: 0/3 FAIL")
        return 2

    try:
        img = lade_hex(sample)
    except HexFehler as e:
        print(f"[FAIL] Beispieldatei nicht lesbar: {e}")
        print("SELFTEST: 0/3 FAIL")
        return 2

    ergebnisse = []
    tmpdir = tempfile.mkdtemp(prefix="ivcu_selftest_")
    try:
        # ---- Test 1: Analyse der Beispieldatei -------------------------------- #
        try:
            fehler, warnungen = pruefe_image(img)
            ok = (
                not fehler
                and img.trailer is not None
                and img.trailer.version == SAMPLE_VERSION
                and img.trailer.crc == SAMPLE_CRC
                and img.crc() == SAMPLE_CRC
                and img.erste_adresse() == SAMPLE_ERSTE
                and img.letzte_adresse() == SAMPLE_LETZTE
                and img.groesse() == SAMPLE_GROESSE
            )
            detail = (f"Version {version_text(img.trailer.version)}, CRC 0x{img.crc():04X}, "
                      f"{len(img.datenrecords)} Datenrecords, {img.groesse()} Bytes, "
                      f"Checksummenfehler {len([f for f in fehler if 'checksumme' in f.lower()])}")
        except Exception as e:  # noqa: BLE001 - Selftest soll immer weiterlaufen
            ok, detail = False, f"Ausnahme: {e}"
        ergebnisse.append(("1) Analyse Beispieldatei (Version 3.4.13, CRC 0xE349)", ok, detail))

        # ---- Test 2: Roundtrip (neu schreiben + erneut parsen) ---------------- #
        try:
            ziel = os.path.join(tmpdir, "roundtrip.hex")
            schreibe_hex(img, ziel)
            neu = lade_hex(ziel)
            nfehler, _ = pruefe_image(neu)
            gleich = (
                not nfehler
                and neu.image_bytes() == img.image_bytes()
                and neu.crc() == img.crc()
                and neu.trailer is not None
                and neu.trailer.version == img.trailer.version
                and neu.trailer.crc == img.trailer.crc
                and neu.sla == img.sla
            )
            byte_identisch = open(ziel, "rb").read() == open(sample, "rb").read()
            ok = gleich
            detail = ("Image-Bytes und CRC identisch; "
                      f"Datei byte-identisch zur Vorlage: {'ja' if byte_identisch else 'nein'}")
        except Exception as e:  # noqa: BLE001
            ok, detail = False, f"Ausnahme: {e}"
        ergebnisse.append(("2) Roundtrip (neu schreiben, erneut parsen, gleiche Bytes/CRC)", ok, detail))

        # ---- Test 3: Patch-Test ----------------------------------------------- #
        try:
            # 3a) set-version 9.9.9: nur der Trailer aendert sich, Image/CRC bleiben gleich.
            ziel_a = os.path.join(tmpdir, "set_version_999.hex")
            schreibe_hex(img, ziel_a, version=(9, 9, 9))
            neu_a = lade_hex(ziel_a)
            fehler_a, _ = pruefe_image(neu_a)
            ok_a = (
                not fehler_a
                and neu_a.trailer is not None
                and neu_a.trailer.version == (9, 9, 9)
                and neu_a.crc() == SAMPLE_CRC
                and neu_a.trailer.crc == SAMPLE_CRC
                and neu_a.image_bytes() == img.image_bytes()
            )
            # 3b) Byte-Patch (Raddurchmesser-Werksbyte) auf das 9.9.9-Image: CRC aendert sich.
            img_patch = lade_hex(ziel_a)
            altbyte = img_patch.lese_bytes(0x0801DA43, 1)
            img_patch.patche(0x0801DA43, b"\x64")
            crc_neu = img_patch.crc()
            ziel_b = os.path.join(tmpdir, "patch_da43.hex")
            schreibe_hex(img_patch, ziel_b, version=(9, 9, 9), crc=crc_neu)
            neu_b = lade_hex(ziel_b)
            fehler_b, _ = pruefe_image(neu_b)
            ok_b = (
                not fehler_b
                and neu_b.lese_bytes(0x0801DA43, 1) == b"\x64"
                and crc_neu != SAMPLE_CRC
                and neu_b.trailer.crc == crc_neu
            )
            ok = ok_a and ok_b
            detail = (f"set-version 9.9.9 ok; Byte-Patch 0x0801DA43 {altbyte.hex().upper()}->64: "
                      f"CRC 0x{SAMPLE_CRC:04X} -> 0x{crc_neu:04X}, beide Dateien validiert")
        except Exception as e:  # noqa: BLE001
            ok, detail = False, f"Ausnahme: {e}"
        ergebnisse.append(("3) Patch-Test (set-version 9.9.9 + Byte-Patch, CRC neu, validiert)", ok, detail))
    finally:
        shutil.rmtree(tmpdir, ignore_errors=True)

    bestanden = sum(1 for _, ok, _ in ergebnisse if ok)
    for titel, ok, detail in ergebnisse:
        print(f"[{'PASS' if ok else 'FAIL'}] Test {titel} - {detail}")
    print(f"SELFTEST: {bestanden}/{len(ergebnisse)} {'PASS' if bestanden == len(ergebnisse) else 'FAIL'}")
    return 0 if bestanden == len(ergebnisse) else 1


# --------------------------------------------------------------------------- #
# CLI
# --------------------------------------------------------------------------- #

def baue_parser():
    parser = argparse.ArgumentParser(
        prog="ivcu_fw_tool.py",
        description="Werkzeug fuer Teverun-IVCU-Firmware (Intel-HEX): Info, Validierung, "
                    "Versions- und Byte-Patching mit CRC-16/MODBUS-Neuberechnung.",
        epilog="Beispiele:  ivcu_fw_tool.py info AWIVCU_APP_R3_4_13.hex | "
               "validate ... | set-version ... 9.9.9 -o out.hex | patch ... 0x0801DA43=64 -o out.hex | "
               "dump ... 0x0801DA40 32 | --selftest",
    )
    parser.add_argument("--selftest", action="store_true",
                        help="Selbsttest mit der Beispieldatei ausfuehren (liest/erzeugt nur Temp-Dateien)")
    parser.add_argument("--sample", metavar="HEX", default=None,
                        help=f"Beispieldatei fuer --selftest (Standard: {SAMPLE_NAME} neben diesem Skript)")

    sub = parser.add_subparsers(dest="befehl", metavar="BEFEHL")

    p = sub.add_parser("info", help="Ueberblick: Basisadresse, Regionen, Version, CRC, SHA-256")
    p.add_argument("hex", help="Intel-HEX-Eingabedatei")

    p = sub.add_parser("validate", help="Format und CRC streng pruefen (Exit 0/1)")
    p.add_argument("hex", help="Intel-HEX-Eingabedatei")

    p = sub.add_parser("set-version", help="Version im Trailer patchen (Image bleibt unveraendert)")
    p.add_argument("hex", help="Intel-HEX-Eingabedatei")
    p.add_argument("version", metavar="A.B.C", help="neue Version, z. B. 9.9.9")
    p.add_argument("-o", "--output", required=True, metavar="OUT.HEX", help="Ausgabedatei")

    p = sub.add_parser("patch", help="Bytes im Image patchen, CRC neu berechnen")
    p.add_argument("hex", help="Intel-HEX-Eingabedatei")
    p.add_argument("patches", nargs="+", metavar="ADRESSE=HEXBYTES",
                   help="ein oder mehrere Patches, z. B. 0x0801DA43=64 (Bytes immer hex)")
    p.add_argument("-o", "--output", required=True, metavar="OUT.HEX", help="Ausgabedatei")

    p = sub.add_parser("dump", help="Hexdump ueber einen Adressbereich")
    p.add_argument("hex", help="Intel-HEX-Eingabedatei")
    p.add_argument("adresse", metavar="ADRESSE", help="Startadresse (0x-hex, fuehrende Null = hex, sonst dezimal)")
    p.add_argument("laenge", metavar="LAENGE", help="Anzahl Bytes (0x-hex oder dezimal)")

    return parser


def main(argv=None):
    parser = baue_parser()
    args = parser.parse_args(argv)

    if args.selftest:
        return cmd_selftest(args)
    if not args.befehl:
        parser.print_help()
        return 2

    befehle = {
        "info": cmd_info,
        "validate": cmd_validate,
        "set-version": cmd_set_version,
        "patch": cmd_patch,
        "dump": cmd_dump,
    }
    try:
        return befehle[args.befehl](args)
    except HexFehler as e:
        print(f"FEHLER: {e}", file=sys.stderr)
        return 2
    except OSError as e:
        print(f"FEHLER: {e}", file=sys.stderr)
        return 2


if __name__ == "__main__":
    sys.exit(main())
