// rea decompile_all
// name: FUN_0801640a
// address: 0x801640a
// body: available
// range: 0x801640a-0x80164b5 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0801640a(void)

{
  undefined4 auStack_24 [7];
  
  FUN_0801d048(auStack_24,(undefined4 *)&DAT_0801d6c8,0x1c);
  if (DAT_20000464 == '\0') {
    DAT_20000464 = '\x01';
    FUN_08011874(0,0,0);
    _DAT_20001624 = FUN_080117b4((uint)DAT_20000322,0xffff00);
    DAT_20001660 = 1;
    DAT_20001661 = 0;
    DAT_20001671 = 0;
    DAT_20001670 = 0;
    _DAT_20001664 = 3;
    DAT_20001668 = 100;
    DAT_20001672 = 2;
    FUN_080110b0((undefined4 *)0x2000166c);
    _DAT_200013a4 = FUN_080117b4((uint)DAT_20000322,0xffff00);
    _DAT_200013a8 = 0;
    DAT_200013e0 = 2;
    DAT_200013e1 = 0;
    DAT_200013f0 = 0;
    _DAT_200013e4 = 0xf;
    DAT_200013e8 = 100;
    DAT_200013f2 = 1;
    FUN_080110b0((undefined4 *)0x200013ec);
  }
  FUN_080133d8();
  FUN_080145ee();
  FUN_080141f8();
  return;
}

