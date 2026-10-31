// rea decompile_all
// name: FUN_0800ee0a
// address: 0x800ee0a
// body: available
// range: 0x800ee0a-0x800eebf inclusive
// range: 0x800eec6-0x800eef1 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0800ee0a(void)

{
  ushort uVar1;
  
  if (_DAT_200002e0 < _DAT_200002d6) {
    uVar1 = _DAT_200002d6 - _DAT_200002e0;
  }
  else {
    uVar1 = _DAT_200002e0 - _DAT_200002d6;
  }
  if (((_DAT_200002f4 < 0x97) || (uVar1 < 0xb)) || ((9 < _DAT_200002d6 && (9 < _DAT_200002e0)))) {
    if (_DAT_200002f4 == 0) {
      _DAT_20000444 = _DAT_20000444 + 1;
      if (800 < _DAT_20000444) {
        _DAT_20000444 = 0;
        DAT_2000043c = 0;
      }
    }
    else {
      _DAT_20000444 = 0;
    }
    if (_DAT_20000440 != 0) {
      _DAT_20000440 = _DAT_20000440 - 1;
    }
  }
  else {
    _DAT_20000440 = _DAT_20000440 + 1;
    if (0x50 < _DAT_20000440) {
      _DAT_20000440 = 0;
      if (_DAT_200002d6 < 10) {
        DAT_2000043c = 1;
      }
      else {
        DAT_2000043c = 2;
      }
    }
  }
  switch(DAT_2000043c) {
  case 0:
    DAT_200003ff = 0;
    break;
  case 1:
    DAT_200003ff = 1;
    _DAT_20000448 = 100;
    break;
  case 2:
    DAT_200003ff = 2;
    _DAT_20000448 = 100;
    break;
  case 3:
  }
  return;
}

