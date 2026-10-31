// rea decompile_all
// name: FUN_08012570
// address: 0x8012570
// body: available
// range: 0x8012570-0x801257f inclusive
// range: 0x8012586-0x80126df inclusive
// range: 0x80126f4-0x80127a9 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08012570(undefined4 param_1)

{
  switch(param_1) {
  case 0xb:
    _DAT_2000142c = FUN_08011670((uint)DAT_20000322,0xff0000);
    _DAT_20001430 = FUN_08011670((uint)DAT_20000322,0xffff00);
    _DAT_20001434 = FUN_08011670((uint)DAT_20000322,0xff00);
    _DAT_20001438 = FUN_08011670((uint)DAT_20000322,0xffff);
    _DAT_2000143c = FUN_08011670((uint)DAT_20000322,0xff);
    _DAT_20001440 = FUN_08011670((uint)DAT_20000322,0xff00ff);
    DAT_20001468 = 6;
    DAT_20001469 = 0;
    DAT_20001479 = 0;
    DAT_20001478 = 0;
    _DAT_2000146c = 6;
    DAT_20001470 = 100;
    DAT_2000147a = 0;
    FUN_08010f6c((undefined4 *)0x20001474);
    break;
  case 0xc:
    _DAT_2000142c = FUN_08011670((uint)DAT_20000322,0xff0000);
    _DAT_20001430 = FUN_08011670((uint)DAT_20000322,0xffff00);
    DAT_20001468 = 2;
    DAT_20001469 = 0;
    DAT_20001479 = 0;
    DAT_20001478 = 0;
    _DAT_2000146c = 6;
    DAT_20001470 = 100;
    DAT_2000147a = 0;
    FUN_08010f6c((undefined4 *)0x20001474);
    break;
  case 0xd:
    _DAT_2000142c = FUN_08011670((uint)DAT_20000322,0xff0000);
    _DAT_20001430 = FUN_08011670((uint)DAT_20000322,0xff00ff);
    DAT_20001468 = 2;
    DAT_20001469 = 0;
    DAT_20001479 = 0;
    DAT_20001478 = 0;
    _DAT_2000146c = 6;
    DAT_20001470 = 100;
    DAT_2000147a = 0;
    FUN_08010f6c((undefined4 *)0x20001474);
    break;
  case 0xe:
    _DAT_2000142c = FUN_08011670((uint)DAT_20000322,0xff00);
    _DAT_20001430 = FUN_08011670((uint)DAT_20000322,0xffff);
    DAT_20001468 = 2;
    DAT_20001469 = 0;
    DAT_20001479 = 0;
    DAT_20001478 = 0;
    _DAT_2000146c = 6;
    DAT_20001470 = 100;
    DAT_2000147a = 0;
    FUN_08010f6c((undefined4 *)0x20001474);
    break;
  case 0xf:
    _DAT_2000142c = FUN_08011670((uint)DAT_20000322,0xff00);
    _DAT_20001430 = FUN_08011670((uint)DAT_20000322,0xffff00);
    DAT_20001468 = 2;
    DAT_20001469 = 0;
    DAT_20001479 = 0;
    DAT_20001478 = 0;
    _DAT_2000146c = 6;
    DAT_20001470 = 100;
    DAT_2000147a = 0;
    FUN_08010f6c((undefined4 *)0x20001474);
    break;
  case 0x10:
    _DAT_2000142c = FUN_08011670((uint)DAT_20000322,0xff);
    _DAT_20001430 = FUN_08011670((uint)DAT_20000322,0xff00ff);
    DAT_20001468 = 2;
    DAT_20001469 = 0;
    DAT_20001479 = 0;
    DAT_20001478 = 0;
    _DAT_2000146c = 6;
    DAT_20001470 = 100;
    DAT_2000147a = 0;
    FUN_08010f6c((undefined4 *)0x20001474);
  }
  return;
}

