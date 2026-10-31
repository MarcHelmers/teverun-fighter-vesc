#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Callgraph-Builder fuer die REA-Dekompilate (decomp2/functions/*.c).

- Quellordner: decomp2/functions (Fallback: decomp3/functions, decomp/functions)
- Funktionsname aus Kopfzeile '// name: FUN_xxxx', sonst Dateiname ohne .c
- Callees: 'FUN_[0-9a-fA-F]{4,8}(' in Code-Zeilen (Kommentarzeilen '//' werden
  uebersprungen); 'thunk_FUN_...' wird auf das Ziel FUN_... normalisiert.
- Es bleiben nur Kanten zwischen Funktionen des Quellordners erhalten.
- Knotenlabel: CSV-Annotation (falls vorhanden), sonst Name.
- Output: callgraph.dot (geclustert nach Adressbereichen) und
  callgraph_reduced.dot (nur annotierte Knoten + direkte Nachbarn).
- Wenn Graphviz 'dot' im PATH liegt, wird zusaetzlich callgraph.svg gerendert.

Nur Standardbibliothek (Python 3)."""

import argparse
import os
import re
import shutil
import subprocess
import sys
from collections import Counter, defaultdict

SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))

NAME_RE = re.compile(r'^//\s*name:\s*(\S+)', re.M)
ADDR_RE = re.compile(r'^//\s*address:\s*(0x[0-9a-fA-F]+)', re.M)
CALLEE_RE = re.compile(r'\b((?:thunk_)?FUN_[0-9a-fA-F]{4,8})\s*\(')

# Adressbereiche (Start inkl., Ende exkl.). Grenze 0x8016 wird EEPROM/UART
# zugeschlagen, 0x8019 der Anwendung/Runtime.
CLUSTERS = [
    (0x08000000, 0x0800B000, "Startup/Treiber (0x8007...)"),
    (0x0800B000, 0x0800C000, "IRQ/BLE (0x800B)"),
    (0x0800C000, 0x0800F000, "BLE/State (0x800C-0x800E)"),
    (0x0800F000, 0x08011000, "Builder/TX (0x800F-0x8010)"),
    (0x08011000, 0x08016000, "Mathe (0x8011-0x8016)"),
    (0x08016000, 0x08019000, "EEPROM/UART (0x8016-0x8019)"),
    (0x08019000, 0x0801D000, "Anwendung/Runtime (0x8019-0x801D)"),
    (0x00000000, 0x100000000, "Sonstige"),
]


def cluster_index(addr):
    for i, (lo, hi, _label) in enumerate(CLUSTERS):
        if lo <= addr < hi:
            return i
    return len(CLUSTERS) - 1


def find_source_dir(cli_dir):
    if cli_dir:
        return cli_dir
    for cand in ('decomp2', 'decomp3', 'decomp'):
        p = os.path.join(SCRIPT_DIR, cand, 'functions')
        if os.path.isdir(p):
            return p
    return None


def read_text(path):
    with open(path, 'r', encoding='utf-8', errors='replace') as fh:
        return fh.read()


def parse_function(path):
    """Liest Name, Adresse und Callee-Namen einer Dekompilat-Datei."""
    text = read_text(path)
    head = text[:4000]

    m = NAME_RE.search(head)
    if m:
        name = m.group(1)
    else:
        name = os.path.splitext(os.path.basename(path))[0]

    m = ADDR_RE.search(head)
    if m:
        addr = int(m.group(1), 16)
    else:
        try:
            addr = int(os.path.splitext(os.path.basename(path))[0], 16)
        except ValueError:
            addr = 0

    callees = []
    for line in text.splitlines():
        if line.lstrip().startswith('//'):
            continue  # Kopf-/Kommentarzeilen enthalten keine echten Aufrufe
        for cm in CALLEE_RE.finditer(line):
            callees.append(cm.group(1))
    return {'name': name, 'addr': addr, 'callees': callees, 'path': path}


def load_annotations(csv_path):
    """address(hex) -> Annotation aus 'address;name;bytes;parts;annotation'."""
    annotations = {}
    if not csv_path or not os.path.isfile(csv_path):
        return annotations
    with open(csv_path, 'r', encoding='utf-8', errors='replace') as fh:
        for line in fh:
            line = line.strip().lstrip('\ufeff')
            if not line:
                continue
            parts = line.split(';', 4)
            if len(parts) < 2:
                continue
            try:
                addr = int(parts[0].strip(), 16)
            except ValueError:
                continue  # Kopfzeile
            text = parts[4].strip() if len(parts) > 4 else ''
            if text:
                annotations[addr] = text
    return annotations


def dot_escape(text):
    text = text.replace('\\', '\\\\')
    text = text.replace('"', '\\"')
    text = text.replace('\r', '')
    text = text.replace('\n', '\\n')
    return text


def write_dot(path, funcs, edges, annotations, title):
    """Schreibt eine geclusterte DOT-Datei; liefert (knoten, kanten)."""
    by_cluster = defaultdict(list)
    for fn in funcs:
        by_cluster[cluster_index(fn['addr'])].append(fn)

    lines = []
    lines.append('digraph callgraph {')
    lines.append('  graph [charset="UTF-8", rankdir=LR, fontsize=10, '
                 'label="%s", labelloc=t, fontname="Helvetica"];'
                 % dot_escape(title))
    lines.append('  node [shape=box, style="rounded", fontname="Helvetica", fontsize=9];')
    lines.append('  edge [color="#555555", arrowsize=0.7];')
    lines.append('')

    for idx in sorted(by_cluster.keys()):
        members = sorted(by_cluster[idx], key=lambda f: (f['addr'], f['key']))
        label = CLUSTERS[idx][2]
        lines.append('  subgraph cluster_%d {' % idx)
        lines.append('    label="%s";' % dot_escape(label))
        lines.append('    style="rounded";')
        lines.append('    color="#adb5bd";')
        for fn in members:
            annotation = annotations.get(fn['addr'])
            text = annotation if annotation else fn['key']
            if annotation:
                attrs = 'label="%s", tooltip="%s @ 0x%x", fillcolor="#fff3bf", color="#e67700", style="rounded,filled"'
                attrs = attrs % (dot_escape(text), dot_escape(fn['key']), fn['addr'])
            else:
                attrs = 'label="%s", tooltip="%s @ 0x%x"' % (
                    dot_escape(text), dot_escape(fn['key']), fn['addr'])
            lines.append('    "%s" [%s];' % (dot_escape(fn['key']), attrs))
        lines.append('  }')
        lines.append('')

    for src, dst in sorted(edges):
        lines.append('  "%s" -> "%s";' % (dot_escape(src), dot_escape(dst)))
    lines.append('}')
    lines.append('')

    with open(path, 'w', encoding='utf-8') as fh:
        fh.write('\n'.join(lines))
    return len(funcs), len(edges)


def render_svg(dot_path):
    dot_bin = shutil.which('dot')
    if not dot_bin:
        print("Hinweis: Graphviz 'dot' ist nicht im PATH - "
              "callgraph.svg wurde nicht erzeugt (DOT-Datei manuell rendern).")
        return None
    svg_path = os.path.splitext(dot_path)[0] + '.svg'
    try:
        res = subprocess.run([dot_bin, '-Tsvg', dot_path, '-o', svg_path],
                             capture_output=True, text=True)
    except Exception as exc:  # pragma: no cover - Umgebungsabhaengig
        print("Hinweis: Graphviz-Rendering fehlgeschlagen: %s" % exc)
        return None
    if res.returncode != 0:
        print("Hinweis: Graphviz-Rendering fehlgeschlagen: %s"
              % (res.stderr or '').strip()[:300])
        return None
    print("SVG gerendert: %s" % svg_path)
    return svg_path


def main(argv=None):
    parser = argparse.ArgumentParser(
        description='Callgraph aus REA-Dekompilaten (decomp2/functions/*.c) bauen.')
    parser.add_argument('--dir', default=None,
                        help='Ordner mit Dekompilat-*.c '
                             '(Default: decomp2/functions, Fallback decomp3/decomp)')
    parser.add_argument('--csv', default=None,
                        help='function_index-CSV fuer Annotationen '
                             '(Default: AWIVCU_APP_R3_4_13_function_index.csv neben dem Script)')
    parser.add_argument('--out', default=None,
                        help='Pfad der DOT-Ausgabe (Default: callgraph.dot neben dem Script)')
    parser.add_argument('--full', action='store_true',
                        help='auch Funktionen ohne Kanten als isolierte Knoten aufnehmen')
    args = parser.parse_args(argv)

    src_dir = find_source_dir(args.dir)
    if not src_dir or not os.path.isdir(src_dir):
        print("FEHLER: Kein Dekompilat-Ordner gefunden (--dir angeben).")
        return 2

    csv_path = args.csv
    if csv_path is None:
        csv_path = os.path.join(SCRIPT_DIR, 'AWIVCU_APP_R3_4_13_function_index.csv')
    if not os.path.isfile(csv_path):
        print("Warnung: CSV '%s' nicht gefunden - Knotenlabels ohne Annotationen."
              % csv_path)
        csv_path = None

    out_path = args.out or os.path.join(SCRIPT_DIR, 'callgraph.dot')
    out_dir = os.path.dirname(os.path.abspath(out_path)) or '.'
    stem = os.path.splitext(os.path.basename(out_path))[0]
    reduced_path = os.path.join(out_dir, stem + '_reduced.dot')

    files = sorted(f for f in os.listdir(src_dir) if f.lower().endswith('.c'))
    funcs = [parse_function(os.path.join(src_dir, f)) for f in files]

    # Doppelte Funktionsnamen (z.B. thunk an zwei Adressen) eindeutig machen.
    name_counts = Counter(fn['name'] for fn in funcs)
    for fn in funcs:
        if name_counts[fn['name']] > 1:
            fn['key'] = '%s@0x%x' % (fn['name'], fn['addr'])
        else:
            fn['key'] = fn['name']

    exact = defaultdict(list)
    lower = defaultdict(list)
    for fn in funcs:
        exact[fn['name']].append(fn['key'])
        lower[fn['name'].lower()].append(fn['key'])

    def resolve(callee):
        norm = callee[6:] if callee.startswith('thunk_') else callee
        for cand in (callee, norm):
            keys = exact.get(cand)
            if keys and len(keys) == 1:
                return keys[0]
        for cand in (callee, norm):
            keys = lower.get(cand.lower())
            if keys and len(keys) == 1:
                return keys[0]
        return None

    edges = set()
    for fn in funcs:
        own = fn['name']
        for callee in set(fn['callees']):
            if callee == own:
                continue  # eigener Name zaehlt nicht als Kante
            dst = resolve(callee)
            if dst is None or dst == fn['key']:
                continue  # nur bekannte Funktionen des Ordners, keine Selbstkanten
            edges.add((fn['key'], dst))

    annotations = load_annotations(csv_path)

    all_keys = {fn['key'] for fn in funcs}
    degree = Counter()
    for src, dst in edges:
        degree[src] += 1
        degree[dst] += 1
    annotated_keys = {fn['key'] for fn in funcs if fn['addr'] in annotations}

    if args.full:
        main_keys = set(all_keys)
    else:
        main_keys = {k for k in all_keys if degree[k] > 0} | annotated_keys
    main_funcs = [fn for fn in funcs if fn['key'] in main_keys]
    main_edges = {(a, b) for (a, b) in edges if a in main_keys and b in main_keys}

    neighbors = set()
    for a, b in edges:
        if a in annotated_keys:
            neighbors.add(b)
        if b in annotated_keys:
            neighbors.add(a)
    reduced_keys = annotated_keys | neighbors
    reduced_funcs = [fn for fn in funcs if fn['key'] in reduced_keys]
    reduced_edges = {(a, b) for (a, b) in edges
                     if a in reduced_keys and b in reduced_keys}

    title = 'REA Callgraph (%s)' % os.path.basename(os.path.dirname(src_dir))
    n_nodes, n_edges = write_dot(out_path, main_funcs, main_edges, annotations, title)
    r_nodes, r_edges = write_dot(reduced_path, reduced_funcs, reduced_edges,
                                 annotations,
                                 'REA Callgraph reduziert (annotierte + Nachbarn)')

    print("Quellordner: %s" % src_dir)
    print("Funktionen gelesen: %d, annotierte Knoten: %d (davon im Ordner: %d)"
          % (len(funcs), len(annotations), len(annotated_keys)))
    print("callgraph.dot: %d Knoten, %d Kanten, %d Bytes"
          % (n_nodes, n_edges, os.path.getsize(out_path)))
    print("callgraph_reduced.dot: %d Knoten, %d Kanten, %d Bytes"
          % (r_nodes, r_edges, os.path.getsize(reduced_path)))
    if not args.full:
        isolated = len(all_keys) - len(main_keys)
        if isolated:
            print("Hinweis: %d Funktionen ohne Kanten ausgelassen (--full nimmt alle auf)."
                  % isolated)
    render_svg(out_path)
    return 0


if __name__ == '__main__':
    sys.exit(main())
