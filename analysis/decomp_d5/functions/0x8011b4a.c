// rea decompile_all
// name: FUN_08011b4a
// address: 0x8011b4a
// body: available
// range: 0x8011b4a-0x8011b59 inclusive
// range: 0x8011b8a-0x8011ec7 inclusive
// range: 0x8011edc-0x80122d5 inclusive
// range: 0x80122e8-0x80123a5 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08011b4a(undefined4 param_1)

{
  switch(param_1) {
  case 0x18:
    _DAT_200014cc = FUN_08011670((uint)DAT_20000322,0xff0000);
    _DAT_200014d0 = FUN_08011670((uint)DAT_20000322,0xff7f00);
    _DAT_200014d4 = FUN_08011670((uint)DAT_20000322,0xffff00);
    _DAT_200014d8 = FUN_08011670((uint)DAT_20000322,0xff00);
    _DAT_200014dc = FUN_08011670((uint)DAT_20000322,0xffff);
    _DAT_200014e0 = FUN_08011670((uint)DAT_20000322,0xff);
    _DAT_200014e4 = FUN_08011670((uint)DAT_20000322,0xff00ff);
    DAT_20001508 = 7;
    DAT_20001509 = 0;
    DAT_20001519 = 0;
    DAT_20001518 = 0;
    _DAT_2000150c = 2;
    DAT_20001510 = 100;
    DAT_2000151a = 0;
    FUN_08010f6c((undefined4 *)0x20001514);
  default:
    break;
  case 0x19:
    _DAT_200014cc = FUN_08011670((uint)DAT_20000322,0xff0000);
    _DAT_200014d0 = FUN_08011670((uint)DAT_20000322,0xff7f00);
    _DAT_200014d4 = FUN_08011670((uint)DAT_20000322,0xffff00);
    _DAT_200014d8 = FUN_08011670((uint)DAT_20000322,0xff00);
    _DAT_200014dc = FUN_08011670((uint)DAT_20000322,0xffff);
    _DAT_200014e0 = FUN_08011670((uint)DAT_20000322,0xff);
    _DAT_200014e4 = FUN_08011670((uint)DAT_20000322,0xff00ff);
    DAT_20001508 = 7;
    DAT_20001509 = 0;
    DAT_20001519 = 0;
    DAT_20001518 = 1;
    _DAT_2000150c = 2;
    DAT_20001510 = 100;
    DAT_2000151a = 0;
    FUN_08010f6c((undefined4 *)0x20001514);
    break;
  case 0x1a:
    _DAT_200014cc = FUN_08011670((uint)DAT_20000322,0xff0000);
    _DAT_200014d0 = FUN_08011670((uint)DAT_20000322,0xff00);
    _DAT_200014d4 = FUN_08011670((uint)DAT_20000322,0xff);
    DAT_20001508 = 3;
    DAT_20001509 = 0;
    DAT_20001519 = 0;
    DAT_20001518 = 0;
    _DAT_2000150c = 2;
    DAT_20001510 = 100;
    DAT_2000151a = 0;
    FUN_08010f6c((undefined4 *)0x20001514);
    break;
  case 0x1b:
    _DAT_200014cc = FUN_08011670((uint)DAT_20000322,0xff0000);
    _DAT_200014d0 = FUN_08011670((uint)DAT_20000322,0xff00);
    _DAT_200014d4 = FUN_08011670((uint)DAT_20000322,0xff);
    DAT_20001508 = 3;
    DAT_20001509 = 0;
    DAT_20001519 = 0;
    DAT_20001518 = 1;
    _DAT_2000150c = 2;
    DAT_20001510 = 100;
    DAT_2000151a = 0;
    FUN_08010f6c((undefined4 *)0x20001514);
    break;
  case 0x1c:
    _DAT_200014cc = FUN_08011670((uint)DAT_20000322,0xffff00);
    _DAT_200014d0 = FUN_08011670((uint)DAT_20000322,0xffff);
    _DAT_200014d4 = FUN_08011670((uint)DAT_20000322,0xff00ff);
    DAT_20001508 = 3;
    DAT_20001509 = 0;
    DAT_20001519 = 0;
    DAT_20001518 = 0;
    _DAT_2000150c = 2;
    DAT_20001510 = 100;
    DAT_2000151a = 0;
    FUN_08010f6c((undefined4 *)0x20001514);
    break;
  case 0x1d:
    _DAT_200014cc = FUN_08011670((uint)DAT_20000322,0xffff00);
    _DAT_200014d0 = FUN_08011670((uint)DAT_20000322,0xffff);
    _DAT_200014d4 = FUN_08011670((uint)DAT_20000322,0xff00ff);
    DAT_20001508 = 3;
    DAT_20001509 = 0;
    DAT_20001519 = 0;
    DAT_20001518 = 1;
    _DAT_2000150c = 2;
    DAT_20001510 = 100;
    DAT_2000151a = 0;
    FUN_08010f6c((undefined4 *)0x20001514);
    break;
  case 0x24:
    _DAT_200014cc = FUN_08011670((uint)DAT_20000322,0xff0000);
    _DAT_200014d0 = FUN_08011670((uint)DAT_20000322,0xff7f00);
    _DAT_200014d4 = FUN_08011670((uint)DAT_20000322,0xffff00);
    _DAT_200014d8 = FUN_08011670((uint)DAT_20000322,0xff00);
    _DAT_200014dc = FUN_08011670((uint)DAT_20000322,0xffff);
    _DAT_200014e0 = FUN_08011670((uint)DAT_20000322,0xff);
    _DAT_200014e4 = FUN_08011670((uint)DAT_20000322,0xff00ff);
    DAT_20001508 = 7;
    DAT_20001509 = 0;
    DAT_20001519 = 0;
    DAT_20001518 = 0;
    _DAT_2000150c = 5;
    DAT_20001510 = 100;
    DAT_2000151a = 0;
    FUN_08010f6c((undefined4 *)0x20001514);
    break;
  case 0x25:
    _DAT_200014cc = FUN_08011670((uint)DAT_20000322,0xff0000);
    _DAT_200014d0 = FUN_08011670((uint)DAT_20000322,0xff7f00);
    _DAT_200014d4 = FUN_08011670((uint)DAT_20000322,0xffff00);
    _DAT_200014d8 = FUN_08011670((uint)DAT_20000322,0xff00);
    _DAT_200014dc = FUN_08011670((uint)DAT_20000322,0xffff);
    _DAT_200014e0 = FUN_08011670((uint)DAT_20000322,0xff);
    _DAT_200014e4 = FUN_08011670((uint)DAT_20000322,0xff00ff);
    DAT_20001508 = 7;
    DAT_20001509 = 0;
    DAT_20001519 = 0;
    DAT_20001518 = 1;
    _DAT_2000150c = 5;
    DAT_20001510 = 100;
    DAT_2000151a = 0;
    FUN_08010f6c((undefined4 *)0x20001514);
    break;
  case 0x26:
    _DAT_200014cc = FUN_08011670((uint)DAT_20000322,0xff0000);
    _DAT_200014d0 = FUN_08011670((uint)DAT_20000322,0xff00);
    _DAT_200014d4 = FUN_08011670((uint)DAT_20000322,0xff);
    DAT_20001508 = 3;
    DAT_20001509 = 0;
    DAT_20001519 = 0;
    DAT_20001518 = 0;
    _DAT_2000150c = 5;
    DAT_20001510 = 100;
    DAT_2000151a = 0;
    FUN_08010f6c((undefined4 *)0x20001514);
    break;
  case 0x27:
    _DAT_200014cc = FUN_08011670((uint)DAT_20000322,0xff0000);
    _DAT_200014d0 = FUN_08011670((uint)DAT_20000322,0xff00);
    _DAT_200014d4 = FUN_08011670((uint)DAT_20000322,0xff);
    DAT_20001508 = 3;
    DAT_20001509 = 0;
    DAT_20001519 = 0;
    DAT_20001518 = 1;
    _DAT_2000150c = 5;
    DAT_20001510 = 100;
    DAT_2000151a = 0;
    FUN_08010f6c((undefined4 *)0x20001514);
    break;
  case 0x28:
    _DAT_200014cc = FUN_08011670((uint)DAT_20000322,0xffff00);
    _DAT_200014d0 = FUN_08011670((uint)DAT_20000322,0xffff);
    _DAT_200014d4 = FUN_08011670((uint)DAT_20000322,0xff00ff);
    DAT_20001508 = 3;
    DAT_20001509 = 0;
    DAT_20001519 = 0;
    DAT_20001518 = 0;
    _DAT_2000150c = 5;
    DAT_20001510 = 100;
    DAT_2000151a = 0;
    FUN_08010f6c((undefined4 *)0x20001514);
    break;
  case 0x29:
    _DAT_200014cc = FUN_08011670((uint)DAT_20000322,0xffff00);
    _DAT_200014d0 = FUN_08011670((uint)DAT_20000322,0xffff);
    _DAT_200014d4 = FUN_08011670((uint)DAT_20000322,0xff00ff);
    DAT_20001508 = 3;
    DAT_20001509 = 0;
    DAT_20001519 = 0;
    DAT_20001518 = 1;
    _DAT_2000150c = 5;
    DAT_20001510 = 100;
    DAT_2000151a = 0;
    FUN_08010f6c((undefined4 *)0x20001514);
    break;
  case 0x2a:
    _DAT_200014cc = FUN_08011670((uint)DAT_20000322,0xff0000);
    _DAT_200014d0 = FUN_08011670((uint)DAT_20000322,0xff7f00);
    _DAT_200014d4 = FUN_08011670((uint)DAT_20000322,0xffff00);
    _DAT_200014d8 = FUN_08011670((uint)DAT_20000322,0xff00);
    _DAT_200014dc = FUN_08011670((uint)DAT_20000322,0xffff);
    _DAT_200014e0 = FUN_08011670((uint)DAT_20000322,0xff);
    _DAT_200014e4 = FUN_08011670((uint)DAT_20000322,0xff00ff);
    DAT_20001508 = 7;
    DAT_20001509 = 0;
    DAT_20001519 = 0;
    DAT_20001518 = 0;
    _DAT_2000150c = 10;
    DAT_20001510 = 100;
    DAT_2000151a = 0;
    FUN_08010f6c((undefined4 *)0x20001514);
    break;
  case 0x2b:
    _DAT_200014cc = FUN_08011670((uint)DAT_20000322,0xff0000);
    _DAT_200014d0 = FUN_08011670((uint)DAT_20000322,0xff7f00);
    _DAT_200014d4 = FUN_08011670((uint)DAT_20000322,0xffff00);
    _DAT_200014d8 = FUN_08011670((uint)DAT_20000322,0xff00);
    _DAT_200014dc = FUN_08011670((uint)DAT_20000322,0xffff);
    _DAT_200014e0 = FUN_08011670((uint)DAT_20000322,0xff);
    _DAT_200014e4 = FUN_08011670((uint)DAT_20000322,0xff00ff);
    DAT_20001508 = 7;
    DAT_20001509 = 0;
    DAT_20001519 = 0;
    DAT_20001518 = 1;
    _DAT_2000150c = 10;
    DAT_20001510 = 100;
    DAT_2000151a = 0;
    FUN_08010f6c((undefined4 *)0x20001514);
    break;
  case 0x2c:
    _DAT_200014cc = FUN_08011670((uint)DAT_20000322,0xff0000);
    _DAT_200014d0 = FUN_08011670((uint)DAT_20000322,0xff00);
    _DAT_200014d4 = FUN_08011670((uint)DAT_20000322,0xff);
    DAT_20001508 = 3;
    DAT_20001509 = 0;
    DAT_20001519 = 0;
    DAT_20001518 = 0;
    _DAT_2000150c = 10;
    DAT_20001510 = 100;
    DAT_2000151a = 0;
    FUN_08010f6c((undefined4 *)0x20001514);
    break;
  case 0x2d:
    _DAT_200014cc = FUN_08011670((uint)DAT_20000322,0xff0000);
    _DAT_200014d0 = FUN_08011670((uint)DAT_20000322,0xff00);
    _DAT_200014d4 = FUN_08011670((uint)DAT_20000322,0xff);
    DAT_20001508 = 3;
    DAT_20001509 = 0;
    DAT_20001519 = 0;
    DAT_20001518 = 1;
    _DAT_2000150c = 10;
    DAT_20001510 = 100;
    DAT_2000151a = 0;
    FUN_08010f6c((undefined4 *)0x20001514);
    break;
  case 0x2e:
    _DAT_200014cc = FUN_08011670((uint)DAT_20000322,0xffff00);
    _DAT_200014d0 = FUN_08011670((uint)DAT_20000322,0xffff);
    _DAT_200014d4 = FUN_08011670((uint)DAT_20000322,0xff00ff);
    DAT_20001508 = 3;
    DAT_20001509 = 0;
    DAT_20001519 = 0;
    DAT_20001518 = 0;
    _DAT_2000150c = 10;
    DAT_20001510 = 100;
    DAT_2000151a = 0;
    FUN_08010f6c((undefined4 *)0x20001514);
    break;
  case 0x2f:
    _DAT_200014cc = FUN_08011670((uint)DAT_20000322,0xffff00);
    _DAT_200014d0 = FUN_08011670((uint)DAT_20000322,0xffff);
    _DAT_200014d4 = FUN_08011670((uint)DAT_20000322,0xff00ff);
    DAT_20001508 = 3;
    DAT_20001509 = 0;
    DAT_20001519 = 0;
    DAT_20001518 = 1;
    _DAT_2000150c = 10;
    DAT_20001510 = 100;
    DAT_2000151a = 0;
    FUN_08010f6c((undefined4 *)0x20001514);
  }
  return;
}

