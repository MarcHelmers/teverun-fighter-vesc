// rea decompile_all
// name: FUN_08010f66
// address: 0x8010f66
// body: available
// range: 0x8010f66-0x801105f inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08010f66(void)

{
  if (DAT_20000430 == '\0') {
    if (((_DAT_200002da < 3000) && (_DAT_200002da != 0)) && ((DAT_200002d3 & 4) == 4)) {
      _DAT_20000434 = _DAT_20000434 + 1;
      if (4 < _DAT_20000434) {
        _DAT_20000434 = 0;
        DAT_20000430 = '\x01';
      }
    }
    else {
      _DAT_20000434 = 0;
    }
  }
  else if (((_DAT_200002da < 3000) && (_DAT_200002da != 0)) && ((DAT_200002d3 & 4) == 4)) {
    _DAT_20000438 = 0;
  }
  else {
    _DAT_20000438 = _DAT_20000438 + 1;
    if (0x1d < _DAT_20000438) {
      _DAT_20000438 = 0;
      DAT_20000430 = '\0';
    }
  }
  if (DAT_20000428 == '\0') {
    if (DAT_20000430 == '\0') {
      _DAT_2000042c = 0;
    }
    else {
      _DAT_2000042c = _DAT_2000042c + 1;
      if (2 < _DAT_2000042c) {
        _DAT_20000424 = 5;
      }
    }
    if (_DAT_20000424 == 0) {
      DAT_20000388 = DAT_20000387;
      if (DAT_20000387 != '\0') {
        DAT_20000428 = '\x01';
      }
    }
    else {
      _DAT_20000424 = _DAT_20000424 + -1;
      DAT_20000388 = '\0';
    }
  }
  else {
    DAT_20000388 = DAT_20000387;
    if (DAT_20000387 == '\0') {
      DAT_20000428 = '\0';
    }
  }
  return;
}

