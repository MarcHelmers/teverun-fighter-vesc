// rea decompile_all
// name: FUN_080110fc
// address: 0x80110fc
// body: available
// range: 0x80110fc-0x801126b inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_080110fc(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  char in_CY;
  undefined8 in_d0;
  uint uVar2;
  uint uVar3;
  longlong lVar4;
  uint uVar5;
  ulonglong uVar6;
  
  uVar2 = (uint)((ulonglong)in_d0 >> 0x20);
  lVar4 = CONCAT44(param_4,param_3);
  FUN_0801d3ec(param_3,param_4);
  if (in_CY == '\0') {
    uVar6 = FUN_0801d090(param_3,param_4,0,0x3ff00000);
    lVar4 = (uVar6 & 0xffffffff00000000) + (uVar6 & 0xffffffff);
  }
  uVar1 = (uint)((ulonglong)lVar4 >> 0x20);
  FUN_0801d41c((uint)lVar4,uVar1);
  if (in_CY == '\0') {
    uVar6 = FUN_0801d1d2((uint)lVar4,uVar1,0,0x3ff00000);
    lVar4 = (uVar6 & 0xffffffff00000000) + (uVar6 & 0xffffffff);
  }
  uVar1 = (uint)((ulonglong)lVar4 >> 0x20);
  uVar3 = (uint)lVar4;
  uVar6 = FUN_0801d1de(0,0x40180000,uVar3,uVar1);
  FUN_0801d3ec((int)uVar6,(int)(uVar6 >> 0x20));
  uVar5 = (uint)in_d0;
  if (in_CY == '\0') {
    uVar6 = FUN_0801d1d8(uVar5,uVar2,param_1,param_2);
    uVar6 = FUN_0801d1de((uint)uVar6,(uint)(uVar6 >> 0x20),0,0x40180000);
    uVar6 = FUN_0801d1de((uint)uVar6,(uint)(uVar6 >> 0x20),uVar3,uVar1);
    FUN_0801d090((uint)uVar6,(uint)(uVar6 >> 0x20),uVar5,uVar2);
  }
  else {
    uVar6 = FUN_0801d1de(0,0x40000000,uVar3,uVar1);
    FUN_0801d3ec((int)uVar6,(int)(uVar6 >> 0x20));
    if (in_CY != '\0') {
      uVar6 = FUN_0801d1de(0,0x40080000,uVar3,uVar1);
      FUN_0801d3ec((int)uVar6,(int)(uVar6 >> 0x20));
      if (in_CY == '\0') {
        uVar6 = FUN_0801d1d2(0x55555555,0x3fe55555,uVar3,uVar1);
        lVar4 = (uVar6 & 0xffffffff00000000) + (uVar6 & 0xffffffff);
        uVar6 = FUN_0801d1d8(uVar5,uVar2,param_1,param_2);
        uVar6 = FUN_0801d1de((uint)uVar6,(uint)(uVar6 >> 0x20),(uint)lVar4,
                             (uint)((ulonglong)lVar4 >> 0x20));
        uVar6 = FUN_0801d1de((uint)uVar6,(uint)(uVar6 >> 0x20),0,0x40180000);
        FUN_0801d090((uint)uVar6,(uint)(uVar6 >> 0x20),uVar5,uVar2);
      }
    }
  }
  return;
}

