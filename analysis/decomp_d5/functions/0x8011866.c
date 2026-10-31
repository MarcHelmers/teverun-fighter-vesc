// rea decompile_all
// name: FUN_08011866
// address: 0x8011866
// body: available
// range: 0x8011866-0x8011875 inclusive
// range: 0x801187c-0x8011a69 inclusive
// range: 0x8011a6c-0x8011ac7 inclusive
// range: 0x8011ae8-0x8011b49 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08011866(undefined4 param_1)

{
  switch(param_1) {
  case 0x1e:
    _DAT_2000151c = FUN_08011670((uint)DAT_20000322,0xff0000);
    _DAT_20001520 = FUN_08011670((uint)DAT_20000322,0xff7f00);
    _DAT_20001524 = FUN_08011670((uint)DAT_20000322,0xffff00);
    _DAT_20001528 = FUN_08011670((uint)DAT_20000322,0xff00);
    _DAT_2000152c = FUN_08011670((uint)DAT_20000322,0xffff);
    _DAT_20001530 = FUN_08011670((uint)DAT_20000322,0xff);
    _DAT_20001534 = FUN_08011670((uint)DAT_20000322,0xff00ff);
    DAT_20001558 = 7;
    DAT_20001559 = 0;
    DAT_20001569 = 0;
    DAT_20001568 = 0;
    _DAT_2000155c = 5;
    DAT_20001560 = 100;
    DAT_2000156a = 0;
    FUN_08010f6c((undefined4 *)0x20001564);
    break;
  case 0x1f:
    _DAT_20001534 = FUN_08011670((uint)DAT_20000322,0xff0000);
    _DAT_20001530 = FUN_08011670((uint)DAT_20000322,0xff7f00);
    _DAT_2000152c = FUN_08011670((uint)DAT_20000322,0xffff00);
    _DAT_20001528 = FUN_08011670((uint)DAT_20000322,0xff00);
    _DAT_20001524 = FUN_08011670((uint)DAT_20000322,0xffff);
    _DAT_20001520 = FUN_08011670((uint)DAT_20000322,0xff);
    _DAT_2000151c = FUN_08011670((uint)DAT_20000322,0xff00ff);
    DAT_20001558 = 7;
    DAT_20001559 = 0;
    DAT_20001569 = 0;
    DAT_20001568 = 1;
    _DAT_2000155c = 5;
    DAT_20001560 = 100;
    DAT_2000156a = 0;
    FUN_08010f6c((undefined4 *)0x20001564);
    break;
  case 0x20:
    _DAT_2000151c = FUN_08011670((uint)DAT_20000322,0xff0000);
    _DAT_20001520 = FUN_08011670((uint)DAT_20000322,0xff00);
    _DAT_20001524 = FUN_08011670((uint)DAT_20000322,0xff);
    DAT_20001558 = 3;
    DAT_20001559 = 0;
    DAT_20001569 = 0;
    DAT_20001568 = 0;
    _DAT_2000155c = 5;
    DAT_20001560 = 100;
    DAT_2000156a = 0;
    FUN_08010f6c((undefined4 *)0x20001564);
    break;
  case 0x21:
    _DAT_20001524 = FUN_08011670((uint)DAT_20000322,0xff0000);
    _DAT_20001520 = FUN_08011670((uint)DAT_20000322,0xff00);
    _DAT_2000151c = FUN_08011670((uint)DAT_20000322,0xff);
    DAT_20001558 = 3;
    DAT_20001559 = 0;
    DAT_20001569 = 0;
    DAT_20001568 = 1;
    _DAT_2000155c = 5;
    DAT_20001560 = 100;
    DAT_2000156a = 0;
    FUN_08010f6c((undefined4 *)0x20001564);
    break;
  case 0x22:
    _DAT_2000151c = FUN_08011670((uint)DAT_20000322,0xffff00);
    _DAT_20001520 = FUN_08011670((uint)DAT_20000322,0xffff);
    _DAT_20001524 = FUN_08011670((uint)DAT_20000322,0xff00ff);
    DAT_20001558 = 3;
    DAT_20001559 = 0;
    DAT_20001569 = 0;
    DAT_20001568 = 0;
    _DAT_2000155c = 5;
    DAT_20001560 = 100;
    DAT_2000156a = 0;
    FUN_08010f6c((undefined4 *)0x20001564);
    break;
  case 0x23:
    _DAT_20001524 = FUN_08011670((uint)DAT_20000322,0xffff00);
    _DAT_20001520 = FUN_08011670((uint)DAT_20000322,0xffff);
    _DAT_2000151c = FUN_08011670((uint)DAT_20000322,0xff00ff);
    DAT_20001558 = 3;
    DAT_20001559 = 0;
    DAT_20001569 = 0;
    DAT_20001568 = 1;
    _DAT_2000155c = 5;
    DAT_20001560 = 100;
    DAT_2000156a = 0;
    FUN_08010f6c((undefined4 *)0x20001564);
  }
  return;
}

