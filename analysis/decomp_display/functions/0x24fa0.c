// rea decompile_all
// name: FUN_00024fa0
// address: 0x24fa0
// body: available
// range: 0x24fa0-0x25129 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00024fa0(void)

{
  byte local_2c;
  undefined1 local_2b;
  undefined2 local_2a;
  undefined2 local_28;
  undefined1 local_26;
  undefined2 local_24;
  undefined1 local_22;
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined1 local_10;
  undefined1 local_f;
  
  FUN_000115e0((uint *)0x400a0010,0xf,7,0);
  FUN_000115e0((uint *)0x400a0000,2,4,0);
  FUN_000115e0((uint *)0x400a0000,9,2,0);
  FUN_000115e0((uint *)0x400a0000,10,5,0);
  FUN_000115e0((uint *)0x400a0000,0xb,4,0);
  FUN_000115e0((uint *)0x400a0000,0xe,2,0);
  FUN_000115e0((uint *)0x400a0000,0xf,2,0);
  FUN_000115e0((uint *)0x400a0020,0,5,0);
  FUN_000115e0((uint *)0x400a0020,1,6,0);
  FUN_000115e0((uint *)0x400a0020,2,6,0);
  FUN_000115e0((uint *)0x400a0020,3,6,0);
  FUN_000115e0((uint *)0x400a0020,9,4,0);
  FUN_000115e0((uint *)0x400a0020,10,4,0);
  FUN_000115e0((uint *)0x400a0020,0xb,4,0);
  FUN_000115e0((uint *)0x400a0020,0xc,3,0);
  FUN_000115e0((uint *)0x400a0020,0xd,6,0);
  FUN_000115e0((uint *)0x400a0010,2,6,0);
  FUN_000115e0((uint *)0x400a0010,3,7,0);
  FUN_000115e0((uint *)0x400a0010,4,6,0);
  FUN_000115e0((uint *)0x400a0010,5,6,0);
  local_2c = 3;
  local_2b = 0;
  local_2a = 0x1e0;
  local_28 = 0x299;
  local_26 = 0x20;
  local_24 = 0x20;
  local_22 = 2;
  local_20 = 7;
  local_1e = 2;
  local_18 = _DAT_20000018;
  local_14 = 0xffff;
  local_f = 1;
  local_1c = local_1e;
  local_10 = local_2b;
  FUN_000111a8((undefined4 *)0x40002000,&local_2c);
  return;
}

