// rea decompile_all
// name: FUN_08011128
// address: 0x8011128
// body: available
// range: 0x8011128-0x80112eb inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_08011128(uint param_1,uint param_2,uint param_3,uint param_4,undefined1 *param_5,
                 undefined1 *param_6,undefined1 *param_7)

{
  uint uVar1;
  uint uVar2;
  char in_ZR;
  undefined1 in_CY;
  undefined8 in_d0;
  uint uVar3;
  uint extraout_s1;
  uint extraout_s1_00;
  uint extraout_s1_01;
  uint uVar4;
  longlong lVar5;
  ulonglong uVar6;
  undefined4 local_60;
  undefined4 uStack_5c;
  undefined4 local_58;
  undefined4 uStack_54;
  
  uVar1 = (uint)in_d0;
  uVar3 = (uint)((ulonglong)in_d0 >> 0x20);
  FUN_0801d208(param_1,param_2);
  local_58 = param_3;
  uStack_54 = param_4;
  local_60 = param_3;
  uStack_5c = param_4;
  if (in_ZR == '\0') {
    FUN_0801d208(param_3,param_4);
    if ((bool)in_CY && !(bool)in_ZR) {
      uVar6 = FUN_0801cffa(param_3,param_4,param_1,param_2);
      lVar5 = (uVar6 & 0xffffffff00000000) + (uVar6 & 0xffffffff);
      uVar6 = FUN_0801ceac(param_3,param_4,param_1,param_2);
      uVar6 = FUN_0801cfee((uint)uVar6,(uint)(uVar6 >> 0x20),(uint)lVar5,
                           (uint)((ulonglong)lVar5 >> 0x20));
      lVar5 = (uVar6 & 0xffffffff00000000) + (uVar6 & 0xffffffff);
    }
    else {
      uVar6 = FUN_0801ceac(0,0x3ff00000,param_1,param_2);
      uVar6 = FUN_0801cffa((uint)uVar6,(uint)(uVar6 >> 0x20),param_3,param_4);
      lVar5 = (uVar6 & 0xffffffff00000000) + (uVar6 & 0xffffffff);
    }
    uVar6 = FUN_0801cffa(0,0x40000000,param_3,param_4);
    uVar2 = (uint)((ulonglong)lVar5 >> 0x20);
    uVar4 = (uint)lVar5;
    uVar6 = FUN_0801cfee((uint)uVar6,(uint)(uVar6 >> 0x20),uVar4,uVar2);
    lVar5 = (uVar6 & 0xffffffff00000000) + (uVar6 & 0xffffffff);
    FUN_0801cfee(uVar4,uVar2,(uint)lVar5,(uint)((ulonglong)lVar5 >> 0x20));
    uVar6 = FUN_0801ceac(uVar1,uVar3,0x55555555,0x3fd55555);
    lVar5 = (uVar6 & 0xffffffff00000000) + (uVar6 & 0xffffffff);
    local_58 = FUN_08010fb8(uVar4,uVar2,(uint)lVar5,(uint)((ulonglong)lVar5 >> 0x20));
    local_60 = FUN_08010fb8(uVar4,uVar2,uVar1,uVar3);
    uVar6 = FUN_0801cfee(uVar1,uVar3,0x55555555,0x3fd55555);
    lVar5 = (uVar6 & 0xffffffff00000000) + (uVar6 & 0xffffffff);
    param_3 = FUN_08010fb8(uVar4,uVar2,(uint)lVar5,(uint)((ulonglong)lVar5 >> 0x20));
    param_4 = extraout_s1_01;
    uStack_54 = extraout_s1;
    uStack_5c = extraout_s1_00;
  }
  uVar6 = FUN_0801cffa(local_58,uStack_54,0,0x406fe000);
  uVar6 = FUN_0801d1d6((uint)uVar6,(uint)(uVar6 >> 0x20));
  *param_5 = (char)uVar6;
  uVar6 = FUN_0801cffa(local_60,uStack_5c,0,0x406fe000);
  uVar6 = FUN_0801d1d6((uint)uVar6,(uint)(uVar6 >> 0x20));
  *param_6 = (char)uVar6;
  uVar6 = FUN_0801cffa(param_3,param_4,0,0x406fe000);
  uVar6 = FUN_0801d1d6((uint)uVar6,(uint)(uVar6 >> 0x20));
  *param_7 = (char)uVar6;
  return;
}

