// rea decompile_all
// name: FUN_0001caa0
// address: 0x1caa0
// body: available
// range: 0x1caa0-0x1cfdb inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001caa0(void)

{
  byte bVar1;
  
  FUN_000218c4((byte *)0x200017c4,0x20000d78,0x2a,0x2ca99);
  bVar1 = DAT_00056b14;
  FUN_00024c7c((byte *)0x200017c4,(undefined4 *)0x20000d6c,DAT_00056b14,_DAT_00056b16,_DAT_00056b18,
               0,0);
  FUN_00024ee8((byte *)0x200017c4,bVar1,0x56b08);
  FUN_00024e48((byte *)0x200017c4,bVar1);
  bVar1 = DAT_00056a88;
  FUN_00024c7c((byte *)0x200017c4,(undefined4 *)0x20000d5c,DAT_00056a88,_DAT_00056a8a,_DAT_00056a8c,
               0,0);
  FUN_00024ee8((byte *)0x200017c4,bVar1,0x56a7c);
  FUN_00024e48((byte *)0x200017c4,bVar1);
  bVar1 = DAT_00056808;
  FUN_00024c7c((byte *)0x200017c4,(undefined4 *)0x20000d14,DAT_00056808,_DAT_0005680a,_DAT_0005680c,
               0,0);
  FUN_00024ee8((byte *)0x200017c4,bVar1,0x567fc);
  FUN_00024e48((byte *)0x200017c4,bVar1);
  bVar1 = DAT_0005681c;
  FUN_00024c7c((byte *)0x200017c4,(undefined4 *)0x20000d1c,DAT_0005681c,_DAT_0005681e,_DAT_00056820,
               0,0);
  FUN_00024ee8((byte *)0x200017c4,bVar1,0x56810);
  FUN_00024e48((byte *)0x200017c4,bVar1);
  bVar1 = DAT_00056858;
  FUN_00024c7c((byte *)0x200017c4,(undefined4 *)0x20000d2c,DAT_00056858,_DAT_0005685a,_DAT_0005685c,
               0,0);
  FUN_00024ee8((byte *)0x200017c4,bVar1,0x5684c);
  FUN_00024e48((byte *)0x200017c4,bVar1);
  bVar1 = DAT_00056984;
  FUN_00024c7c((byte *)0x200017c4,(undefined4 *)0x20000d3c,DAT_00056984,_DAT_00056986,_DAT_00056988,
               0,0);
  FUN_00024ee8((byte *)0x200017c4,bVar1,0x56978);
  FUN_00024e48((byte *)0x200017c4,bVar1);
  bVar1 = DAT_00056830;
  FUN_00024c7c((byte *)0x200017c4,(undefined4 *)0x20000d24,DAT_00056830,_DAT_00056832,_DAT_00056834,
               0,0);
  FUN_00024ee8((byte *)0x200017c4,bVar1,0x56824);
  FUN_00024e48((byte *)0x200017c4,bVar1);
  bVar1 = DAT_00056998;
  FUN_00024c7c((byte *)0x200017c4,(undefined4 *)0x20000d44,DAT_00056998,_DAT_0005699a,_DAT_0005699c,
               0,0);
  FUN_00024ee8((byte *)0x200017c4,bVar1,0x5698c);
  FUN_00024e48((byte *)0x200017c4,bVar1);
  bVar1 = DAT_000567e0;
  FUN_00024c7c((byte *)0x200017c4,(undefined4 *)0x20000d0c,DAT_000567e0,_DAT_000567e2,_DAT_000567e4,
               0,0);
  FUN_00024ee8((byte *)0x200017c4,bVar1,0x567d4);
  FUN_00024e48((byte *)0x200017c4,bVar1);
  bVar1 = DAT_00056a38;
  FUN_00024c7c((byte *)0x200017c4,(undefined4 *)0x20000d54,DAT_00056a38,_DAT_00056a3a,_DAT_00056a3c,
               0,0);
  FUN_00024ee8((byte *)0x200017c4,bVar1,0x56a2c);
  FUN_00024e48((byte *)0x200017c4,bVar1);
  bVar1 = DAT_000569d4;
  FUN_00024c7c((byte *)0x200017c4,(undefined4 *)0x20000d4c,DAT_000569d4,_DAT_000569d6,_DAT_000569d8,
               0,0);
  FUN_00024ee8((byte *)0x200017c4,bVar1,0x569c8);
  FUN_00024e48((byte *)0x200017c4,bVar1);
  bVar1 = DAT_000568f8;
  FUN_00024c7c((byte *)0x200017c4,(undefined4 *)0x20000d34,DAT_000568f8,_DAT_000568fa,_DAT_000568fc,
               0,0);
  FUN_00024ee8((byte *)0x200017c4,bVar1,0x568ec);
  FUN_00024e48((byte *)0x200017c4,bVar1);
  return;
}

