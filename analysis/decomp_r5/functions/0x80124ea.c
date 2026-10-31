// rea decompile_all
// name: FUN_080124ea
// address: 0x80124ea
// body: available
// range: 0x80124ea-0x80124f9 inclusive
// range: 0x8012502-0x80126b3 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_080124ea(undefined4 param_1)

{
  switch(param_1) {
  case 0x11:
    _DAT_20001494 = FUN_080117b4((uint)DAT_20000322,0xff0000);
    DAT_200014d0 = 1;
    DAT_200014d1 = 0;
    DAT_200014e1 = 0;
    DAT_200014e0 = 0;
    _DAT_200014d4 = 10;
    DAT_200014d8 = 100;
    DAT_200014e2 = 0;
    FUN_080110b0((undefined4 *)0x200014dc);
    break;
  case 0x12:
    _DAT_20001494 = FUN_080117b4((uint)DAT_20000322,0xff00);
    DAT_200014d0 = 1;
    DAT_200014d1 = 0;
    DAT_200014e1 = 0;
    DAT_200014e0 = 0;
    _DAT_200014d4 = 10;
    DAT_200014d8 = 100;
    DAT_200014e2 = 0;
    FUN_080110b0((undefined4 *)0x200014dc);
    break;
  case 0x13:
    _DAT_20001494 = FUN_080117b4((uint)DAT_20000322,0xff);
    DAT_200014d0 = 1;
    DAT_200014d1 = 0;
    DAT_200014e1 = 0;
    DAT_200014e0 = 0;
    _DAT_200014d4 = 10;
    DAT_200014d8 = 100;
    DAT_200014e2 = 0;
    FUN_080110b0((undefined4 *)0x200014dc);
    break;
  case 0x14:
    _DAT_20001494 = FUN_080117b4((uint)DAT_20000322,0xffff00);
    DAT_200014d0 = 1;
    DAT_200014d1 = 0;
    DAT_200014e1 = 0;
    DAT_200014e0 = 0;
    _DAT_200014d4 = 10;
    DAT_200014d8 = 100;
    DAT_200014e2 = 0;
    FUN_080110b0((undefined4 *)0x200014dc);
    break;
  case 0x15:
    _DAT_20001494 = FUN_080117b4((uint)DAT_20000322,0xffff);
    DAT_200014d0 = 1;
    DAT_200014d1 = 0;
    DAT_200014e1 = 0;
    DAT_200014e0 = 0;
    _DAT_200014d4 = 10;
    DAT_200014d8 = 100;
    DAT_200014e2 = 0;
    FUN_080110b0((undefined4 *)0x200014dc);
    break;
  case 0x16:
    _DAT_20001494 = FUN_080117b4((uint)DAT_20000322,0xff00ff);
    DAT_200014d0 = 1;
    DAT_200014d1 = 0;
    DAT_200014e1 = 0;
    DAT_200014e0 = 0;
    _DAT_200014d4 = 10;
    DAT_200014d8 = 100;
    DAT_200014e2 = 0;
    FUN_080110b0((undefined4 *)0x200014dc);
    break;
  case 0x17:
    _DAT_20001494 = FUN_080117b4((uint)DAT_20000322,0xffffff);
    DAT_200014d0 = 1;
    DAT_200014d1 = 0;
    DAT_200014e1 = 0;
    DAT_200014e0 = 0;
    _DAT_200014d4 = 10;
    DAT_200014d8 = 100;
    DAT_200014e2 = 0;
    FUN_080110b0((undefined4 *)0x200014dc);
  }
  return;
}

