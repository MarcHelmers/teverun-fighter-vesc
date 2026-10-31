// rea decompile_all
// name: FUN_0801ccd6
// address: 0x801ccd6
// body: available
// range: 0x801ccd6-0x801cd91 inclusive
// range: 0x801cdfc-0x801cf43 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0801ccd6(void)

{
  if (DAT_20002641 == '\0') {
    if (((DAT_20002640 != '\0') && (1 < DAT_20000299)) && (DAT_20000299 < 5)) {
      if ((DAT_20002655 == '\0') || (DAT_20002656 == '\0')) {
        DAT_20002641 = '\x01';
        DAT_20002659 = 0;
        DAT_20002658 = 1;
        _DAT_200006ca = 0;
        _DAT_200006cc = 0;
        _DAT_200006d0 = 0;
      }
      else {
        DAT_20002641 = '\x03';
        DAT_20002659 = 1;
        DAT_20002658 = 1;
        _DAT_200006ca = 0;
        _DAT_200006cc = 0;
        _DAT_200006d0 = 0;
      }
    }
  }
  else if (DAT_20002641 == '\x01') {
    if (((ushort)((ushort)DAT_20002654 * 8) < _DAT_2000264c) && (_DAT_20002642 < 0x96)) {
      _DAT_200006ca = _DAT_200006ca + 1;
      _DAT_200006d0 = _DAT_200006d0 + 1;
      if (50000 < _DAT_200006ca) {
        _DAT_200006ca = 50000;
      }
      _DAT_200006cc = 0;
      _DAT_200006ce = 0;
    }
    else if ((_DAT_2000264c < 10) && (0x3c < _DAT_200006ca)) {
      _DAT_200006cc = _DAT_200006cc + 1;
      _DAT_200006ce = 0;
      _DAT_200006d0 = 0;
    }
    else if (((_DAT_2000264c < 10) && (_DAT_200006ca < 0x3d)) || (200 < _DAT_20002642)) {
      _DAT_200006ca = 0;
    }
    else {
      _DAT_200006ce = _DAT_200006ce + 1;
      if (100 < _DAT_200006ce) {
        _DAT_200006ce = 0;
        _DAT_200006ca = 0;
        _DAT_200006cc = 0;
        _DAT_200006d0 = 0;
      }
    }
    if ((0x3c < _DAT_200006ca) && (2 < _DAT_200006cc)) {
      _DAT_200006ca = 0;
      _DAT_200006cc = 0;
      DAT_20002641 = '\x02';
      DAT_20002659 = 1;
      DAT_20002658 = 1;
      _DAT_200006d2 = 0;
    }
  }
  else if (DAT_20002641 == '\x02') {
    if (DAT_20002657 != '\0') {
      DAT_20002641 = '\x03';
    }
    _DAT_200006d2 = _DAT_200006d2 + 1;
    if (50000 < _DAT_200006d2) {
      _DAT_200006d2 = 0;
      DAT_20002641 = '\0';
      DAT_20002659 = 0;
      DAT_20002658 = 1;
    }
  }
  else if (DAT_20002641 == '\x03') {
    FUN_0801cbda(_DAT_20002648,(float *)&DAT_20002620);
    FUN_0801ca6a();
  }
  else {
    DAT_20002641 = '\0';
  }
  if (((DAT_20002640 == '\0') || (DAT_20000299 < 2)) || (4 < DAT_20000299)) {
    DAT_20002641 = '\0';
  }
  else if ((DAT_20002655 == '\0') || (DAT_20002656 == '\0')) {
    if ((_DAT_20002642 < 100) && (_DAT_2000264c < 0x32)) {
      _DAT_200006d4 = _DAT_200006d4 + 1;
      if (199 < _DAT_200006d4) {
        _DAT_200006d4 = 0;
        DAT_20002641 = '\0';
      }
    }
    else {
      _DAT_200006d4 = 0;
    }
  }
  return;
}

