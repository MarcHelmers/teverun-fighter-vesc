// rea decompile_all
// name: FUN_080170e8
// address: 0x80170e8
// body: available
// range: 0x80170e8-0x801715f inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_080170e8(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  uint uStack_c;
  
  uStack_18 = param_1;
  uStack_14 = param_2;
  uStack_10 = param_3;
  uStack_c = param_4;
  FUN_080170ca(0xa0,0x10,(undefined1 *)&uStack_18);
  uVar1 = FUN_08016fde(&uStack_18,0xe);
  if (uStack_c >> 0x10 == uVar1) {
    FUN_0800b990(&DAT_20001a78,(undefined1 *)&uStack_18,0x10);
  }
  else {
    FUN_0801709e();
  }
  DAT_20000317 = DAT_20001a78;
  DAT_20000318 = DAT_20001a79;
  DAT_20000319 = DAT_20001a7a;
  DAT_2000031a = DAT_20001a7b;
  DAT_2000031b = DAT_20001a7c;
  _DAT_20000320 = _DAT_20001a7e;
  DAT_20000322 = DAT_20001a80;
  DAT_20000323 = DAT_20001a81;
  DAT_20000324 = DAT_20001a82;
  return CONCAT44(uStack_14,uStack_18);
}

