// rea decompile_all
// name: FUN_080128ee
// address: 0x80128ee
// body: available
// range: 0x80128ee-0x80128fb inclusive
// range: 0x8012904-0x8012adf inclusive
// range: 0x8012ae2-0x8012c4d inclusive
// range: 0x8012c64-0x8012c75 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_080128ee(undefined4 param_1)

{
  switch(param_1) {
  case 4:
    _DAT_200013a4 = FUN_080117b4((uint)DAT_20000322,0xff0000);
    _DAT_200013a8 = FUN_080117b4((uint)DAT_20000322,0xff7f00);
    _DAT_200013ac = FUN_080117b4((uint)DAT_20000322,0xffff00);
    _DAT_200013b0 = FUN_080117b4((uint)DAT_20000322,0xff00);
    _DAT_200013b4 = FUN_080117b4((uint)DAT_20000322,0xffff);
    _DAT_200013b8 = FUN_080117b4((uint)DAT_20000322,0xff);
    _DAT_200013bc = FUN_080117b4((uint)DAT_20000322,0xff00ff);
    DAT_200013e0 = 7;
    DAT_200013e1 = 0;
    DAT_200013f0 = 0;
    _DAT_200013e4 = 0x32;
    DAT_200013e8 = 100;
    DAT_200013f2 = 0;
    FUN_080110b0((undefined4 *)0x200013ec);
    break;
  case 5:
    _DAT_200013a4 = FUN_080117b4((uint)DAT_20000322,0xff0000);
    _DAT_200013a8 = FUN_080117b4((uint)DAT_20000322,0xff7f00);
    _DAT_200013ac = FUN_080117b4((uint)DAT_20000322,0xffff00);
    _DAT_200013b0 = FUN_080117b4((uint)DAT_20000322,0xff00);
    _DAT_200013b4 = FUN_080117b4((uint)DAT_20000322,0xffff);
    _DAT_200013b8 = FUN_080117b4((uint)DAT_20000322,0xff);
    _DAT_200013bc = FUN_080117b4((uint)DAT_20000322,0xff00ff);
    DAT_200013e0 = 7;
    DAT_200013e1 = 0;
    DAT_200013f0 = 0;
    _DAT_200013e4 = 0x19;
    DAT_200013e8 = 100;
    DAT_200013f2 = 0;
    FUN_080110b0((undefined4 *)0x200013ec);
    break;
  case 6:
    _DAT_200013a4 = FUN_080117b4((uint)DAT_20000322,0xff0000);
    _DAT_200013a8 = FUN_080117b4((uint)DAT_20000322,0xff00);
    _DAT_200013ac = FUN_080117b4((uint)DAT_20000322,0xff);
    DAT_200013e0 = 3;
    DAT_200013e1 = 0;
    DAT_200013f0 = 0;
    _DAT_200013e4 = 0x19;
    DAT_200013e8 = 100;
    DAT_200013f2 = 0;
    FUN_080110b0((undefined4 *)0x200013ec);
    break;
  case 7:
    _DAT_200013a4 = FUN_080117b4((uint)DAT_20000322,0xffff00);
    _DAT_200013a8 = FUN_080117b4((uint)DAT_20000322,0xffff);
    _DAT_200013ac = FUN_080117b4((uint)DAT_20000322,0xff00ff);
    DAT_200013e0 = 3;
    DAT_200013e1 = 0;
    DAT_200013f0 = 0;
    _DAT_200013e4 = 0x19;
    DAT_200013e8 = 100;
    DAT_200013f2 = 0;
    FUN_080110b0((undefined4 *)0x200013ec);
    break;
  case 8:
    _DAT_200013a4 = FUN_080117b4((uint)DAT_20000322,0xff0000);
    _DAT_200013a8 = 0;
    _DAT_200013ac = FUN_080117b4((uint)DAT_20000322,0xff7f00);
    _DAT_200013b0 = 0;
    _DAT_200013b4 = FUN_080117b4((uint)DAT_20000322,0xffff00);
    _DAT_200013b8 = 0;
    _DAT_200013bc = FUN_080117b4((uint)DAT_20000322,0xff00);
    _DAT_200013c0 = 0;
    _DAT_200013c4 = FUN_080117b4((uint)DAT_20000322,0xffff);
    _DAT_200013c8 = 0;
    _DAT_200013cc = FUN_080117b4((uint)DAT_20000322,0xff);
    _DAT_200013d0 = 0;
    _DAT_200013d4 = FUN_080117b4((uint)DAT_20000322,0xff00ff);
    _DAT_200013d8 = 0;
    DAT_200013e0 = 0xe;
    DAT_200013e1 = 0;
    DAT_200013f0 = 0;
    _DAT_200013e4 = 0x32;
    DAT_200013e8 = 100;
    DAT_200013f2 = 0;
    FUN_080110b0((undefined4 *)0x200013ec);
    break;
  case 9:
    _DAT_200013a4 = FUN_080117b4((uint)DAT_20000322,0xff0000);
    _DAT_200013a8 = 0;
    _DAT_200013ac = FUN_080117b4((uint)DAT_20000322,0xff00);
    _DAT_200013b0 = 0;
    _DAT_200013b4 = FUN_080117b4((uint)DAT_20000322,0xff);
    _DAT_200013b8 = 0;
    DAT_200013e0 = 6;
    DAT_200013e1 = 0;
    DAT_200013f0 = 0;
    _DAT_200013e4 = 0x32;
    DAT_200013e8 = 100;
    DAT_200013f2 = 0;
    FUN_080110b0((undefined4 *)0x200013ec);
    break;
  case 10:
    _DAT_200013a4 = FUN_080117b4((uint)DAT_20000322,0xffff00);
    _DAT_200013a8 = 0;
    _DAT_200013ac = FUN_080117b4((uint)DAT_20000322,0xffff);
    _DAT_200013b0 = 0;
    _DAT_200013b4 = FUN_080117b4((uint)DAT_20000322,0xff00ff);
    _DAT_200013b8 = 0;
    DAT_200013e0 = 6;
    DAT_200013e1 = 0;
    DAT_200013f0 = 0;
    _DAT_200013e4 = 0x32;
    DAT_200013e8 = 100;
    DAT_200013f2 = 0;
    FUN_080110b0((undefined4 *)0x200013ec);
  }
  return;
}

