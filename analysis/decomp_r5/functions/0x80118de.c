// rea decompile_all
// name: FUN_080118de
// address: 0x80118de
// body: available
// range: 0x80118de-0x801197f inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_080118de(undefined4 param_1,undefined1 param_2,undefined1 param_3)

{
  _DAT_200016c4 = FUN_080117b4((uint)DAT_20000322,0xff0000);
  _DAT_200016c8 = FUN_080117b4((uint)DAT_20000322,0xff7f00);
  _DAT_200016cc = FUN_080117b4((uint)DAT_20000322,0xffff00);
  _DAT_200016d0 = FUN_080117b4((uint)DAT_20000322,0xff00);
  _DAT_200016d4 = FUN_080117b4((uint)DAT_20000322,0xffff);
  _DAT_200016d8 = FUN_080117b4((uint)DAT_20000322,0xff);
  _DAT_200016dc = FUN_080117b4((uint)DAT_20000322,0xff00ff);
  DAT_20001700 = 7;
  DAT_20001711 = 0;
  DAT_20001708 = 100;
  DAT_20001712 = 0;
  DAT_20001701 = param_2;
  _DAT_20001704 = param_1;
  DAT_20001710 = param_3;
  FUN_080110b0((undefined4 *)0x2000170c);
  return;
}

