// rea decompile_all
// name: FUN_08011c8e
// address: 0x8011c8e
// body: available
// range: 0x8011c8e-0x8011c9d inclusive
// range: 0x8011cce-0x801200b inclusive
// range: 0x8012020-0x8012419 inclusive
// range: 0x801242c-0x80124e9 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08011c8e(undefined4 param_1)

{
  switch(param_1) {
  case 0x18:
    _DAT_200014e4 = FUN_080117b4((uint)DAT_20000322,0xff0000);
    _DAT_200014e8 = FUN_080117b4((uint)DAT_20000322,0xff7f00);
    _DAT_200014ec = FUN_080117b4((uint)DAT_20000322,0xffff00);
    _DAT_200014f0 = FUN_080117b4((uint)DAT_20000322,0xff00);
    _DAT_200014f4 = FUN_080117b4((uint)DAT_20000322,0xffff);
    _DAT_200014f8 = FUN_080117b4((uint)DAT_20000322,0xff);
    _DAT_200014fc = FUN_080117b4((uint)DAT_20000322,0xff00ff);
    DAT_20001520 = 7;
    DAT_20001521 = 0;
    DAT_20001531 = 0;
    DAT_20001530 = 0;
    _DAT_20001524 = 2;
    DAT_20001528 = 100;
    DAT_20001532 = 0;
    FUN_080110b0((undefined4 *)0x2000152c);
  default:
    break;
  case 0x19:
    _DAT_200014e4 = FUN_080117b4((uint)DAT_20000322,0xff0000);
    _DAT_200014e8 = FUN_080117b4((uint)DAT_20000322,0xff7f00);
    _DAT_200014ec = FUN_080117b4((uint)DAT_20000322,0xffff00);
    _DAT_200014f0 = FUN_080117b4((uint)DAT_20000322,0xff00);
    _DAT_200014f4 = FUN_080117b4((uint)DAT_20000322,0xffff);
    _DAT_200014f8 = FUN_080117b4((uint)DAT_20000322,0xff);
    _DAT_200014fc = FUN_080117b4((uint)DAT_20000322,0xff00ff);
    DAT_20001520 = 7;
    DAT_20001521 = 0;
    DAT_20001531 = 0;
    DAT_20001530 = 1;
    _DAT_20001524 = 2;
    DAT_20001528 = 100;
    DAT_20001532 = 0;
    FUN_080110b0((undefined4 *)0x2000152c);
    break;
  case 0x1a:
    _DAT_200014e4 = FUN_080117b4((uint)DAT_20000322,0xff0000);
    _DAT_200014e8 = FUN_080117b4((uint)DAT_20000322,0xff00);
    _DAT_200014ec = FUN_080117b4((uint)DAT_20000322,0xff);
    DAT_20001520 = 3;
    DAT_20001521 = 0;
    DAT_20001531 = 0;
    DAT_20001530 = 0;
    _DAT_20001524 = 2;
    DAT_20001528 = 100;
    DAT_20001532 = 0;
    FUN_080110b0((undefined4 *)0x2000152c);
    break;
  case 0x1b:
    _DAT_200014e4 = FUN_080117b4((uint)DAT_20000322,0xff0000);
    _DAT_200014e8 = FUN_080117b4((uint)DAT_20000322,0xff00);
    _DAT_200014ec = FUN_080117b4((uint)DAT_20000322,0xff);
    DAT_20001520 = 3;
    DAT_20001521 = 0;
    DAT_20001531 = 0;
    DAT_20001530 = 1;
    _DAT_20001524 = 2;
    DAT_20001528 = 100;
    DAT_20001532 = 0;
    FUN_080110b0((undefined4 *)0x2000152c);
    break;
  case 0x1c:
    _DAT_200014e4 = FUN_080117b4((uint)DAT_20000322,0xffff00);
    _DAT_200014e8 = FUN_080117b4((uint)DAT_20000322,0xffff);
    _DAT_200014ec = FUN_080117b4((uint)DAT_20000322,0xff00ff);
    DAT_20001520 = 3;
    DAT_20001521 = 0;
    DAT_20001531 = 0;
    DAT_20001530 = 0;
    _DAT_20001524 = 2;
    DAT_20001528 = 100;
    DAT_20001532 = 0;
    FUN_080110b0((undefined4 *)0x2000152c);
    break;
  case 0x1d:
    _DAT_200014e4 = FUN_080117b4((uint)DAT_20000322,0xffff00);
    _DAT_200014e8 = FUN_080117b4((uint)DAT_20000322,0xffff);
    _DAT_200014ec = FUN_080117b4((uint)DAT_20000322,0xff00ff);
    DAT_20001520 = 3;
    DAT_20001521 = 0;
    DAT_20001531 = 0;
    DAT_20001530 = 1;
    _DAT_20001524 = 2;
    DAT_20001528 = 100;
    DAT_20001532 = 0;
    FUN_080110b0((undefined4 *)0x2000152c);
    break;
  case 0x24:
    _DAT_200014e4 = FUN_080117b4((uint)DAT_20000322,0xff0000);
    _DAT_200014e8 = FUN_080117b4((uint)DAT_20000322,0xff7f00);
    _DAT_200014ec = FUN_080117b4((uint)DAT_20000322,0xffff00);
    _DAT_200014f0 = FUN_080117b4((uint)DAT_20000322,0xff00);
    _DAT_200014f4 = FUN_080117b4((uint)DAT_20000322,0xffff);
    _DAT_200014f8 = FUN_080117b4((uint)DAT_20000322,0xff);
    _DAT_200014fc = FUN_080117b4((uint)DAT_20000322,0xff00ff);
    DAT_20001520 = 7;
    DAT_20001521 = 0;
    DAT_20001531 = 0;
    DAT_20001530 = 0;
    _DAT_20001524 = 5;
    DAT_20001528 = 100;
    DAT_20001532 = 0;
    FUN_080110b0((undefined4 *)0x2000152c);
    break;
  case 0x25:
    _DAT_200014e4 = FUN_080117b4((uint)DAT_20000322,0xff0000);
    _DAT_200014e8 = FUN_080117b4((uint)DAT_20000322,0xff7f00);
    _DAT_200014ec = FUN_080117b4((uint)DAT_20000322,0xffff00);
    _DAT_200014f0 = FUN_080117b4((uint)DAT_20000322,0xff00);
    _DAT_200014f4 = FUN_080117b4((uint)DAT_20000322,0xffff);
    _DAT_200014f8 = FUN_080117b4((uint)DAT_20000322,0xff);
    _DAT_200014fc = FUN_080117b4((uint)DAT_20000322,0xff00ff);
    DAT_20001520 = 7;
    DAT_20001521 = 0;
    DAT_20001531 = 0;
    DAT_20001530 = 1;
    _DAT_20001524 = 5;
    DAT_20001528 = 100;
    DAT_20001532 = 0;
    FUN_080110b0((undefined4 *)0x2000152c);
    break;
  case 0x26:
    _DAT_200014e4 = FUN_080117b4((uint)DAT_20000322,0xff0000);
    _DAT_200014e8 = FUN_080117b4((uint)DAT_20000322,0xff00);
    _DAT_200014ec = FUN_080117b4((uint)DAT_20000322,0xff);
    DAT_20001520 = 3;
    DAT_20001521 = 0;
    DAT_20001531 = 0;
    DAT_20001530 = 0;
    _DAT_20001524 = 5;
    DAT_20001528 = 100;
    DAT_20001532 = 0;
    FUN_080110b0((undefined4 *)0x2000152c);
    break;
  case 0x27:
    _DAT_200014e4 = FUN_080117b4((uint)DAT_20000322,0xff0000);
    _DAT_200014e8 = FUN_080117b4((uint)DAT_20000322,0xff00);
    _DAT_200014ec = FUN_080117b4((uint)DAT_20000322,0xff);
    DAT_20001520 = 3;
    DAT_20001521 = 0;
    DAT_20001531 = 0;
    DAT_20001530 = 1;
    _DAT_20001524 = 5;
    DAT_20001528 = 100;
    DAT_20001532 = 0;
    FUN_080110b0((undefined4 *)0x2000152c);
    break;
  case 0x28:
    _DAT_200014e4 = FUN_080117b4((uint)DAT_20000322,0xffff00);
    _DAT_200014e8 = FUN_080117b4((uint)DAT_20000322,0xffff);
    _DAT_200014ec = FUN_080117b4((uint)DAT_20000322,0xff00ff);
    DAT_20001520 = 3;
    DAT_20001521 = 0;
    DAT_20001531 = 0;
    DAT_20001530 = 0;
    _DAT_20001524 = 5;
    DAT_20001528 = 100;
    DAT_20001532 = 0;
    FUN_080110b0((undefined4 *)0x2000152c);
    break;
  case 0x29:
    _DAT_200014e4 = FUN_080117b4((uint)DAT_20000322,0xffff00);
    _DAT_200014e8 = FUN_080117b4((uint)DAT_20000322,0xffff);
    _DAT_200014ec = FUN_080117b4((uint)DAT_20000322,0xff00ff);
    DAT_20001520 = 3;
    DAT_20001521 = 0;
    DAT_20001531 = 0;
    DAT_20001530 = 1;
    _DAT_20001524 = 5;
    DAT_20001528 = 100;
    DAT_20001532 = 0;
    FUN_080110b0((undefined4 *)0x2000152c);
    break;
  case 0x2a:
    _DAT_200014e4 = FUN_080117b4((uint)DAT_20000322,0xff0000);
    _DAT_200014e8 = FUN_080117b4((uint)DAT_20000322,0xff7f00);
    _DAT_200014ec = FUN_080117b4((uint)DAT_20000322,0xffff00);
    _DAT_200014f0 = FUN_080117b4((uint)DAT_20000322,0xff00);
    _DAT_200014f4 = FUN_080117b4((uint)DAT_20000322,0xffff);
    _DAT_200014f8 = FUN_080117b4((uint)DAT_20000322,0xff);
    _DAT_200014fc = FUN_080117b4((uint)DAT_20000322,0xff00ff);
    DAT_20001520 = 7;
    DAT_20001521 = 0;
    DAT_20001531 = 0;
    DAT_20001530 = 0;
    _DAT_20001524 = 10;
    DAT_20001528 = 100;
    DAT_20001532 = 0;
    FUN_080110b0((undefined4 *)0x2000152c);
    break;
  case 0x2b:
    _DAT_200014e4 = FUN_080117b4((uint)DAT_20000322,0xff0000);
    _DAT_200014e8 = FUN_080117b4((uint)DAT_20000322,0xff7f00);
    _DAT_200014ec = FUN_080117b4((uint)DAT_20000322,0xffff00);
    _DAT_200014f0 = FUN_080117b4((uint)DAT_20000322,0xff00);
    _DAT_200014f4 = FUN_080117b4((uint)DAT_20000322,0xffff);
    _DAT_200014f8 = FUN_080117b4((uint)DAT_20000322,0xff);
    _DAT_200014fc = FUN_080117b4((uint)DAT_20000322,0xff00ff);
    DAT_20001520 = 7;
    DAT_20001521 = 0;
    DAT_20001531 = 0;
    DAT_20001530 = 1;
    _DAT_20001524 = 10;
    DAT_20001528 = 100;
    DAT_20001532 = 0;
    FUN_080110b0((undefined4 *)0x2000152c);
    break;
  case 0x2c:
    _DAT_200014e4 = FUN_080117b4((uint)DAT_20000322,0xff0000);
    _DAT_200014e8 = FUN_080117b4((uint)DAT_20000322,0xff00);
    _DAT_200014ec = FUN_080117b4((uint)DAT_20000322,0xff);
    DAT_20001520 = 3;
    DAT_20001521 = 0;
    DAT_20001531 = 0;
    DAT_20001530 = 0;
    _DAT_20001524 = 10;
    DAT_20001528 = 100;
    DAT_20001532 = 0;
    FUN_080110b0((undefined4 *)0x2000152c);
    break;
  case 0x2d:
    _DAT_200014e4 = FUN_080117b4((uint)DAT_20000322,0xff0000);
    _DAT_200014e8 = FUN_080117b4((uint)DAT_20000322,0xff00);
    _DAT_200014ec = FUN_080117b4((uint)DAT_20000322,0xff);
    DAT_20001520 = 3;
    DAT_20001521 = 0;
    DAT_20001531 = 0;
    DAT_20001530 = 1;
    _DAT_20001524 = 10;
    DAT_20001528 = 100;
    DAT_20001532 = 0;
    FUN_080110b0((undefined4 *)0x2000152c);
    break;
  case 0x2e:
    _DAT_200014e4 = FUN_080117b4((uint)DAT_20000322,0xffff00);
    _DAT_200014e8 = FUN_080117b4((uint)DAT_20000322,0xffff);
    _DAT_200014ec = FUN_080117b4((uint)DAT_20000322,0xff00ff);
    DAT_20001520 = 3;
    DAT_20001521 = 0;
    DAT_20001531 = 0;
    DAT_20001530 = 0;
    _DAT_20001524 = 10;
    DAT_20001528 = 100;
    DAT_20001532 = 0;
    FUN_080110b0((undefined4 *)0x2000152c);
    break;
  case 0x2f:
    _DAT_200014e4 = FUN_080117b4((uint)DAT_20000322,0xffff00);
    _DAT_200014e8 = FUN_080117b4((uint)DAT_20000322,0xffff);
    _DAT_200014ec = FUN_080117b4((uint)DAT_20000322,0xff00ff);
    DAT_20001520 = 3;
    DAT_20001521 = 0;
    DAT_20001531 = 0;
    DAT_20001530 = 1;
    _DAT_20001524 = 10;
    DAT_20001528 = 100;
    DAT_20001532 = 0;
    FUN_080110b0((undefined4 *)0x2000152c);
  }
  return;
}

