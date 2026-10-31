// rea decompile_all
// name: FUN_0801179a
// address: 0x801179a
// body: available
// range: 0x801179a-0x801183b inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0801179a(undefined4 param_1,undefined1 param_2,undefined1 param_3)

{
  _DAT_200016ac = FUN_08011670((uint)DAT_20000322,0xff0000);
  _DAT_200016b0 = FUN_08011670((uint)DAT_20000322,0xff7f00);
  _DAT_200016b4 = FUN_08011670((uint)DAT_20000322,0xffff00);
  _DAT_200016b8 = FUN_08011670((uint)DAT_20000322,0xff00);
  _DAT_200016bc = FUN_08011670((uint)DAT_20000322,0xffff);
  _DAT_200016c0 = FUN_08011670((uint)DAT_20000322,0xff);
  _DAT_200016c4 = FUN_08011670((uint)DAT_20000322,0xff00ff);
  DAT_200016e8 = 7;
  DAT_200016f9 = 0;
  DAT_200016f0 = 100;
  DAT_200016fa = 0;
  DAT_200016e9 = param_2;
  _DAT_200016ec = param_1;
  DAT_200016f8 = param_3;
  FUN_08010f6c((undefined4 *)0x200016f4);
  return;
}

