// rea decompile_all
// name: FUN_080119aa
// address: 0x80119aa
// body: available
// range: 0x80119aa-0x80119b9 inclusive
// range: 0x80119c0-0x8011bad inclusive
// range: 0x8011bb0-0x8011c0b inclusive
// range: 0x8011c2c-0x8011c8d inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_080119aa(undefined4 param_1)

{
  switch(param_1) {
  case 0x1e:
    _DAT_20001534 = FUN_080117b4((uint)DAT_20000322,0xff0000);
    _DAT_20001538 = FUN_080117b4((uint)DAT_20000322,0xff7f00);
    _DAT_2000153c = FUN_080117b4((uint)DAT_20000322,0xffff00);
    _DAT_20001540 = FUN_080117b4((uint)DAT_20000322,0xff00);
    _DAT_20001544 = FUN_080117b4((uint)DAT_20000322,0xffff);
    _DAT_20001548 = FUN_080117b4((uint)DAT_20000322,0xff);
    _DAT_2000154c = FUN_080117b4((uint)DAT_20000322,0xff00ff);
    DAT_20001570 = 7;
    DAT_20001571 = 0;
    DAT_20001581 = 0;
    DAT_20001580 = 0;
    _DAT_20001574 = 5;
    DAT_20001578 = 100;
    DAT_20001582 = 0;
    FUN_080110b0((undefined4 *)0x2000157c);
    break;
  case 0x1f:
    _DAT_2000154c = FUN_080117b4((uint)DAT_20000322,0xff0000);
    _DAT_20001548 = FUN_080117b4((uint)DAT_20000322,0xff7f00);
    _DAT_20001544 = FUN_080117b4((uint)DAT_20000322,0xffff00);
    _DAT_20001540 = FUN_080117b4((uint)DAT_20000322,0xff00);
    _DAT_2000153c = FUN_080117b4((uint)DAT_20000322,0xffff);
    _DAT_20001538 = FUN_080117b4((uint)DAT_20000322,0xff);
    _DAT_20001534 = FUN_080117b4((uint)DAT_20000322,0xff00ff);
    DAT_20001570 = 7;
    DAT_20001571 = 0;
    DAT_20001581 = 0;
    DAT_20001580 = 1;
    _DAT_20001574 = 5;
    DAT_20001578 = 100;
    DAT_20001582 = 0;
    FUN_080110b0((undefined4 *)0x2000157c);
    break;
  case 0x20:
    _DAT_20001534 = FUN_080117b4((uint)DAT_20000322,0xff0000);
    _DAT_20001538 = FUN_080117b4((uint)DAT_20000322,0xff00);
    _DAT_2000153c = FUN_080117b4((uint)DAT_20000322,0xff);
    DAT_20001570 = 3;
    DAT_20001571 = 0;
    DAT_20001581 = 0;
    DAT_20001580 = 0;
    _DAT_20001574 = 5;
    DAT_20001578 = 100;
    DAT_20001582 = 0;
    FUN_080110b0((undefined4 *)0x2000157c);
    break;
  case 0x21:
    _DAT_2000153c = FUN_080117b4((uint)DAT_20000322,0xff0000);
    _DAT_20001538 = FUN_080117b4((uint)DAT_20000322,0xff00);
    _DAT_20001534 = FUN_080117b4((uint)DAT_20000322,0xff);
    DAT_20001570 = 3;
    DAT_20001571 = 0;
    DAT_20001581 = 0;
    DAT_20001580 = 1;
    _DAT_20001574 = 5;
    DAT_20001578 = 100;
    DAT_20001582 = 0;
    FUN_080110b0((undefined4 *)0x2000157c);
    break;
  case 0x22:
    _DAT_20001534 = FUN_080117b4((uint)DAT_20000322,0xffff00);
    _DAT_20001538 = FUN_080117b4((uint)DAT_20000322,0xffff);
    _DAT_2000153c = FUN_080117b4((uint)DAT_20000322,0xff00ff);
    DAT_20001570 = 3;
    DAT_20001571 = 0;
    DAT_20001581 = 0;
    DAT_20001580 = 0;
    _DAT_20001574 = 5;
    DAT_20001578 = 100;
    DAT_20001582 = 0;
    FUN_080110b0((undefined4 *)0x2000157c);
    break;
  case 0x23:
    _DAT_2000153c = FUN_080117b4((uint)DAT_20000322,0xffff00);
    _DAT_20001538 = FUN_080117b4((uint)DAT_20000322,0xffff);
    _DAT_20001534 = FUN_080117b4((uint)DAT_20000322,0xff00ff);
    DAT_20001570 = 3;
    DAT_20001571 = 0;
    DAT_20001581 = 0;
    DAT_20001580 = 1;
    _DAT_20001574 = 5;
    DAT_20001578 = 100;
    DAT_20001582 = 0;
    FUN_080110b0((undefined4 *)0x2000157c);
  }
  return;
}

