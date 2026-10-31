// rea decompile_all
// name: FUN_08019768
// address: 0x8019768
// body: available
// range: 0x8019768-0x8019969 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_08019768(int param_1)

{
  ushort uVar1;
  short sVar3;
  byte local_2c [4];
  ushort local_28 [2];
  undefined1 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  undefined2 local_14;
  undefined2 local_12;
  undefined2 local_10;
  undefined2 local_e;
  undefined2 local_c;
  ushort uVar2;
  
  sVar3 = (short)((uint)param_1 >> 0x10);
  uVar1 = sVar3 >> 4;
  uVar2 = sVar3 >> 3;
  if (param_1 == 0x40013800) {
    FUN_080081e4(0x4000,1);
    local_28[0] = 0x200;
    local_20 = 2;
    local_1c = 4;
    FUN_08007776((uint *)0x40010800,local_28);
    local_24 = 1;
    local_1c = 4;
    local_28[0] = uVar1;
    FUN_08007776((uint *)0x40010800,local_28);
    local_20 = 0;
    local_1c = 4;
    local_28[0] = uVar2;
    FUN_08007776((uint *)0x40010800,local_28);
    local_28[0] = 0x1000;
    local_20 = 2;
    local_1c = 4;
    FUN_08007776((uint *)0x40010800,local_28);
    local_2c[0] = 0x25;
    local_2c[1] = 0;
    local_2c[2] = 0;
    local_2c[3] = 1;
    FUN_08007462(local_2c);
    FUN_0800842e(&local_18);
    local_18 = 0x1c200;
    local_14 = 0;
    local_12 = 0;
    local_10 = 0;
    local_c = 0x300;
    local_e = 0xc;
    FUN_08008386(0x40013800,&local_18);
    FUN_0800848c(0x40013800,0x525,1);
    FUN_08008474(0x40013800,1);
  }
  if (param_1 == 0x40004400) {
    FUN_08007f40(0x20000,1);
    local_28[0] = 4;
    local_20 = 2;
    local_1c = 4;
    FUN_08007776((uint *)0x40010800,local_28);
    local_28[0] = 8;
    local_24 = 1;
    local_1c = 4;
    FUN_08007776((uint *)0x40010800,local_28);
    local_2c[0] = 0x26;
    local_2c[1] = 3;
    local_2c[2] = 3;
    local_2c[3] = 1;
    FUN_08007462(local_2c);
    FUN_0800842e(&local_18);
    local_18 = 0x2580;
    local_14 = 0;
    local_12 = 0;
    local_10 = 0;
    local_c = 0;
    local_e = 0xc;
    FUN_08008386(0x40004400,&local_18);
    FUN_0800848c(0x40004400,0x525,1);
    FUN_08008474(0x40004400,1);
  }
  if (param_1 == 0x40004800) {
    FUN_08007f40(0x40000,1);
    local_20 = 2;
    local_1c = 0;
    local_28[0] = uVar1;
    FUN_08007776((uint *)0x40010c00,local_28);
    local_24 = 1;
    local_1c = 5;
    local_28[0] = uVar2;
    FUN_08007776((uint *)0x40010c00,local_28);
    local_2c[0] = 0x27;
    local_2c[1] = 4;
    local_2c[2] = 4;
    local_2c[3] = 1;
    FUN_08007462(local_2c);
    FUN_0800842e(&local_18);
    local_18 = 0x2580;
    local_14 = 0;
    local_12 = 0;
    local_10 = 0;
    local_c = 0;
    local_e = 0xc;
    FUN_08008386(0x40004800,&local_18);
    FUN_0800848c(0x40004800,0x525,1);
    FUN_08008474(0x40004800,1);
  }
  return;
}

