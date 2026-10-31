// rea decompile_all
// name: FUN_080186b6
// address: 0x80186b6
// body: available
// range: 0x80186b6-0x8018735 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_080186b6(void)

{
  uint local_24;
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  undefined2 local_1a;
  undefined2 local_18;
  ushort local_14;
  undefined1 local_11;
  undefined1 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  FUN_0800795a(&local_14);
  FUN_08007f40(0x200000,1);
  FUN_0800af1c(0x40005400);
  FUN_080081e4(8,1);
  FUN_080081e4(8,1);
  local_14 = 0xc0;
  local_11 = 0;
  local_c = 0x12;
  local_8 = 1;
  local_10 = 1;
  FUN_08007776((uint *)0x40010c00,&local_14);
  FUN_0800af1c(0x40005400);
  local_20 = 0;
  local_1e = 0xbfff;
  local_1c = 0xff;
  local_1a = 0x400;
  local_18 = 0x4000;
  local_24 = 400000;
  FUN_0800af4e((ushort *)0x40005400,&local_24);
  return;
}

