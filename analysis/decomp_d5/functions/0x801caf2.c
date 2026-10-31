// rea decompile_all
// name: FUN_0801caf2
// address: 0x801caf2
// body: available
// range: 0x801caf2-0x801cbad inclusive
// range: 0x801cc18-0x801cd5f inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0801caf2(void)

{
  if (DAT_20002629 == '\0') {
    if (((DAT_20002628 != '\0') && (1 < DAT_20000299)) && (DAT_20000299 < 5)) {
      if ((DAT_2000263d == '\0') || (DAT_2000263e == '\0')) {
        DAT_20002629 = '\x01';
        DAT_20002641 = 0;
        DAT_20002640 = 1;
        _DAT_200006b2 = 0;
        _DAT_200006b4 = 0;
        _DAT_200006b8 = 0;
      }
      else {
        DAT_20002629 = '\x03';
        DAT_20002641 = 1;
        DAT_20002640 = 1;
        _DAT_200006b2 = 0;
        _DAT_200006b4 = 0;
        _DAT_200006b8 = 0;
      }
    }
  }
  else if (DAT_20002629 == '\x01') {
    if (((ushort)((ushort)DAT_2000263c * 8) < _DAT_20002634) && (_DAT_2000262a < 0x96)) {
      _DAT_200006b2 = _DAT_200006b2 + 1;
      _DAT_200006b8 = _DAT_200006b8 + 1;
      if (50000 < _DAT_200006b2) {
        _DAT_200006b2 = 50000;
      }
      _DAT_200006b4 = 0;
      _DAT_200006b6 = 0;
    }
    else if ((_DAT_20002634 < 10) && (0x3c < _DAT_200006b2)) {
      _DAT_200006b4 = _DAT_200006b4 + 1;
      _DAT_200006b6 = 0;
      _DAT_200006b8 = 0;
    }
    else if (((_DAT_20002634 < 10) && (_DAT_200006b2 < 0x3d)) || (200 < _DAT_2000262a)) {
      _DAT_200006b2 = 0;
    }
    else {
      _DAT_200006b6 = _DAT_200006b6 + 1;
      if (100 < _DAT_200006b6) {
        _DAT_200006b6 = 0;
        _DAT_200006b2 = 0;
        _DAT_200006b4 = 0;
        _DAT_200006b8 = 0;
      }
    }
    if ((0x3c < _DAT_200006b2) && (2 < _DAT_200006b4)) {
      _DAT_200006b2 = 0;
      _DAT_200006b4 = 0;
      DAT_20002629 = '\x02';
      DAT_20002641 = 1;
      DAT_20002640 = 1;
      _DAT_200006ba = 0;
    }
  }
  else if (DAT_20002629 == '\x02') {
    if (DAT_2000263f != '\0') {
      DAT_20002629 = '\x03';
    }
    _DAT_200006ba = _DAT_200006ba + 1;
    if (50000 < _DAT_200006ba) {
      _DAT_200006ba = 0;
      DAT_20002629 = '\0';
      DAT_20002641 = 0;
      DAT_20002640 = 1;
    }
  }
  else if (DAT_20002629 == '\x03') {
    FUN_0801c9f6(_DAT_20002630,(float *)&DAT_20002608);
    FUN_0801c886();
  }
  else {
    DAT_20002629 = '\0';
  }
  if (((DAT_20002628 == '\0') || (DAT_20000299 < 2)) || (4 < DAT_20000299)) {
    DAT_20002629 = '\0';
  }
  else if ((DAT_2000263d == '\0') || (DAT_2000263e == '\0')) {
    if ((_DAT_2000262a < 100) && (_DAT_20002634 < 0x32)) {
      _DAT_200006bc = _DAT_200006bc + 1;
      if (199 < _DAT_200006bc) {
        _DAT_200006bc = 0;
        DAT_20002629 = '\0';
      }
    }
    else {
      _DAT_200006bc = 0;
    }
  }
  return;
}

