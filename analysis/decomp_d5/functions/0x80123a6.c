// rea decompile_all
// name: FUN_080123a6
// address: 0x80123a6
// body: available
// range: 0x80123a6-0x80123b5 inclusive
// range: 0x80123be-0x801256f inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_080123a6(undefined4 param_1)

{
  switch(param_1) {
  case 0x11:
    _DAT_2000147c = FUN_08011670((uint)DAT_20000322,0xff0000);
    DAT_200014b8 = 1;
    DAT_200014b9 = 0;
    DAT_200014c9 = 0;
    DAT_200014c8 = 0;
    _DAT_200014bc = 10;
    DAT_200014c0 = 100;
    DAT_200014ca = 0;
    FUN_08010f6c((undefined4 *)0x200014c4);
    break;
  case 0x12:
    _DAT_2000147c = FUN_08011670((uint)DAT_20000322,0xff00);
    DAT_200014b8 = 1;
    DAT_200014b9 = 0;
    DAT_200014c9 = 0;
    DAT_200014c8 = 0;
    _DAT_200014bc = 10;
    DAT_200014c0 = 100;
    DAT_200014ca = 0;
    FUN_08010f6c((undefined4 *)0x200014c4);
    break;
  case 0x13:
    _DAT_2000147c = FUN_08011670((uint)DAT_20000322,0xff);
    DAT_200014b8 = 1;
    DAT_200014b9 = 0;
    DAT_200014c9 = 0;
    DAT_200014c8 = 0;
    _DAT_200014bc = 10;
    DAT_200014c0 = 100;
    DAT_200014ca = 0;
    FUN_08010f6c((undefined4 *)0x200014c4);
    break;
  case 0x14:
    _DAT_2000147c = FUN_08011670((uint)DAT_20000322,0xffff00);
    DAT_200014b8 = 1;
    DAT_200014b9 = 0;
    DAT_200014c9 = 0;
    DAT_200014c8 = 0;
    _DAT_200014bc = 10;
    DAT_200014c0 = 100;
    DAT_200014ca = 0;
    FUN_08010f6c((undefined4 *)0x200014c4);
    break;
  case 0x15:
    _DAT_2000147c = FUN_08011670((uint)DAT_20000322,0xffff);
    DAT_200014b8 = 1;
    DAT_200014b9 = 0;
    DAT_200014c9 = 0;
    DAT_200014c8 = 0;
    _DAT_200014bc = 10;
    DAT_200014c0 = 100;
    DAT_200014ca = 0;
    FUN_08010f6c((undefined4 *)0x200014c4);
    break;
  case 0x16:
    _DAT_2000147c = FUN_08011670((uint)DAT_20000322,0xff00ff);
    DAT_200014b8 = 1;
    DAT_200014b9 = 0;
    DAT_200014c9 = 0;
    DAT_200014c8 = 0;
    _DAT_200014bc = 10;
    DAT_200014c0 = 100;
    DAT_200014ca = 0;
    FUN_08010f6c((undefined4 *)0x200014c4);
    break;
  case 0x17:
    _DAT_2000147c = FUN_08011670((uint)DAT_20000322,0xffffff);
    DAT_200014b8 = 1;
    DAT_200014b9 = 0;
    DAT_200014c9 = 0;
    DAT_200014c8 = 0;
    _DAT_200014bc = 10;
    DAT_200014c0 = 100;
    DAT_200014ca = 0;
    FUN_08010f6c((undefined4 *)0x200014c4);
  }
  return;
}

