// rea decompile_all
// name: FUN_08007286
// address: 0x8007286
// body: available
// range: 0x8007286-0x8007323 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08007286(void)

{
  _DAT_e000ed88 = _DAT_e000ed88 | 0xf00000;
  _DAT_40021024 = _DAT_40021024 | 4;
  _DAT_40021000 = _DAT_40021000 & 0xfef2ffff;
  _DAT_40021004 = _DAT_40021004 & 0xc000;
  _DAT_4002102c = 0;
  _DAT_40021030 = 0x3800;
  _DAT_40021034 = 0;
  _DAT_40021040 = 0;
  _DAT_40021008 = 0x4bf8000;
  _DAT_4002101c = _DAT_4002101c & 0xefffffff;
  if ((_DAT_40022000 & 0x100) != 0) {
    _DAT_40022000 = _DAT_40022000 & 0xfffffdff;
  }
  _DAT_40022000 = _DAT_40022000 | 0x90;
  FUN_08007184();
  _DAT_e000ed08 = &DAT_08007000;
  return;
}

