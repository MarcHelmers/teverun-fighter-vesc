// rea decompile_all
// name: FUN_0001308c
// address: 0x1308c
// body: available
// range: 0x1308c-0x130ed inclusive
// range: 0x130f4-0x13203 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001308c(void)

{
  if ((_DAT_40000000 & 1) == 0) {
    switch((_DAT_40000000 & 0x1f) >> 2) {
    case 0:
      _DAT_20000044 = 32000;
      break;
    case 1:
      if (_DAT_400aa040 * 0x40000000 < 0) {
        _DAT_20000044 = 20000000;
      }
      else {
        _DAT_20000044 = 8000000;
      }
      _DAT_20000044 = ((_DAT_20000044 / 3) * 0x10 - _DAT_20000044 / 3 & 0xfffffff) << 1;
      break;
    case 2:
      _DAT_20000044 = 0x8000;
      break;
    case 3:
      _DAT_20000044 = 8000000;
      break;
    case 4:
      _DAT_20000044 = 20000000;
      if (_DAT_400aa000 * 0x40000000 < 0) {
        _DAT_20000044 = 40000000;
      }
    }
    if ((int)(_DAT_40000000 * 0x40000000) < 0) {
      _DAT_20000044 = _DAT_20000044 >> 3;
    }
  }
  else if (_DAT_400aa000 * 0x40000000 < 0) {
    _DAT_20000044 = 40000000;
  }
  else {
    _DAT_20000044 = 20000000;
  }
  _DAT_20000010 = _DAT_20000044 / 1000000;
  return;
}

