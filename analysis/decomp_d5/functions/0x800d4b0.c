// rea decompile_all
// name: FUN_0800d4b0
// address: 0x800d4b0
// body: available
// range: 0x800d4b0-0x800d547 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0800d4b0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_10 = param_1;
  uStack_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  FUN_0800b990(&DAT_20000c38,(undefined1 *)((int)&uStack_10 + 2),10);
  if (DAT_20000c38 != 0xff) {
    _DAT_200000ae = (ushort)DAT_20000c38;
  }
  if (DAT_20000c39 != 0xff) {
    _DAT_200000c6 = (ushort)DAT_20000c39;
  }
  if (DAT_20000c3a != 0xff) {
    _DAT_200000de = (ushort)DAT_20000c3a;
  }
  if (DAT_20000c3b != 0xff) {
    _DAT_200000f6 = (ushort)DAT_20000c3b;
  }
  if (DAT_20000c3c != 0xff) {
    _DAT_20000246 = (ushort)DAT_20000c3c;
  }
  if (DAT_20000c3d != 0xff) {
    _DAT_2000025e = (ushort)DAT_20000c3d;
  }
  if (DAT_20000c3e != 0xff) {
    _DAT_20000276 = (ushort)DAT_20000c3e;
  }
  if (DAT_20000c3f != 0xff) {
    _DAT_2000028e = (ushort)DAT_20000c3f;
  }
  return 6;
}

