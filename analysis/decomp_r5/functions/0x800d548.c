// rea decompile_all
// name: FUN_0800d548
// address: 0x800d548
// body: available
// range: 0x800d548-0x800d5ff inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0800d548(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_10 = param_1;
  uStack_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  FUN_0800b990(&DAT_20000c40,(undefined1 *)((int)&uStack_10 + 2),0x10);
  if (_DAT_20000c40 != -1) {
    _DAT_20000126 = _DAT_20000c40;
  }
  if (_DAT_20000c42 != -1) {
    _DAT_2000013e = _DAT_20000c42;
  }
  if (_DAT_20000c44 != -1) {
    _DAT_2000010e = _DAT_20000c44;
  }
  if (_DAT_20000c46 != -1) {
    _DAT_20000186 = _DAT_20000c46;
  }
  if (_DAT_20000c48 != -1) {
    _DAT_2000019e = _DAT_20000c48;
  }
  if (_DAT_20000c4a != -1) {
    _DAT_2000016e = _DAT_20000c4a;
  }
  if (_DAT_20000c4c != 0xffff) {
    _DAT_200001f8 = (uint)_DAT_20000c4c;
  }
  if (_DAT_20000c4e != 0xffff) {
    _DAT_200001c8 = (uint)_DAT_20000c4e;
  }
  return 6;
}

