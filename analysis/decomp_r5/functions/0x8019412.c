// rea decompile_all
// name: FUN_08019412
// address: 0x8019412
// body: available
// range: 0x8019412-0x80194ab inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined8 FUN_08019412(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  ushort local_18;
  undefined1 local_16;
  undefined1 uStack_15;
  undefined4 uStack_14;
  undefined4 local_10;
  undefined4 uStack_c;
  
  local_18 = (ushort)param_1;
  local_16 = (undefined1)((uint)param_1 >> 0x10);
  uStack_15 = (undefined1)((uint)param_1 >> 0x18);
  uStack_14 = param_2;
  local_10 = param_3;
  uStack_c = param_4;
  FUN_080081e4(0x1c,1);
  FUN_0800795a(&local_18);
  local_18 = 0x8000;
  local_10 = 1;
  local_16 = 1;
  FUN_08007776((uint *)0x40010800,&local_18);
  local_18 = 0x100;
  local_10 = 0;
  local_16 = 1;
  FUN_08007776((uint *)0x40010800,&local_18);
  local_18 = 0xf03c;
  local_10 = 1;
  local_16 = 1;
  FUN_08007776((uint *)0x40010c00,&local_18);
  local_18 = 0x6000;
  local_10 = 1;
  local_16 = 1;
  FUN_08007776((uint *)0x40011000,&local_18);
  local_18 = 0x8000;
  local_10 = 0;
  local_16 = 1;
  FUN_08007776((uint *)0x40011000,&local_18);
  FUN_08019406();
  FUN_080193f8();
  FUN_080193ea();
  return CONCAT44(uStack_14,CONCAT13(uStack_15,CONCAT12(local_16,local_18)));
}

