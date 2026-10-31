// rea decompile_all
// name: FUN_080112ec
// address: 0x80112ec
// body: available
// range: 0x80112ec-0x8011367 inclusive
// range: 0x80113b8-0x8011659 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_080112ec(uint param_1,uint param_2,uint param_3,ulonglong *param_4,undefined8 *param_5,
                 undefined8 *param_6)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  char in_ZR;
  char in_CY;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  longlong lVar9;
  longlong lVar10;
  uint uVar11;
  uint uVar12;
  longlong lVar13;
  uint uVar14;
  longlong lVar15;
  ulonglong uVar16;
  undefined8 uVar17;
  
  uVar16 = FUN_0801d1bc(param_1);
  uVar16 = FUN_0801d0de((uint)uVar16,(uint)(uVar16 >> 0x20),0,0x406fe000);
  lVar13 = (uVar16 & 0xffffffff00000000) + (uVar16 & 0xffffffff);
  uVar16 = FUN_0801d1bc(param_2);
  uVar16 = FUN_0801d0de((uint)uVar16,(uint)(uVar16 >> 0x20),0,0x406fe000);
  lVar9 = (uVar16 & 0xffffffff00000000) + (uVar16 & 0xffffffff);
  uVar16 = FUN_0801d1bc(param_3);
  uVar16 = FUN_0801d0de((uint)uVar16,(uint)(uVar16 >> 0x20),0,0x406fe000);
  lVar10 = (uVar16 & 0xffffffff00000000) + (uVar16 & 0xffffffff);
  uVar1 = (uint)((ulonglong)lVar9 >> 0x20);
  uVar8 = (uint)lVar9;
  FUN_0801d208(uVar8,uVar1);
  uVar2 = (uint)((ulonglong)lVar13 >> 0x20);
  uVar12 = (uint)lVar13;
  FUN_0801d208(uVar12,uVar2);
  uVar11 = (uint)((ulonglong)lVar10 >> 0x20);
  lVar15 = lVar13;
  if ((in_CY != '\0') && (FUN_0801d208(uVar8,uVar1), lVar15 = lVar10, in_CY == '\0')) {
    lVar15 = lVar9;
  }
  uVar6 = (uint)((ulonglong)lVar15 >> 0x20);
  uVar4 = (uint)lVar15;
  FUN_0801d238(uVar8,uVar1);
  FUN_0801d238(uVar12,uVar2);
  if ((in_CY != '\0') && (FUN_0801d238(uVar8,uVar1), lVar13 = lVar10, in_CY == '\0')) {
    lVar13 = lVar9;
  }
  uVar7 = (uint)((ulonglong)lVar13 >> 0x20);
  uVar5 = (uint)lVar13;
  uVar16 = FUN_0801cfee(uVar5,uVar7,uVar4,uVar6);
  lVar15 = (uVar16 & 0xffffffff00000000) + (uVar16 & 0xffffffff);
  uVar16 = FUN_0801ceac(uVar5,uVar7,uVar4,uVar6);
  uVar17 = FUN_0801d0de((uint)uVar16,(uint)(uVar16 >> 0x20),0,0x40000000);
  *param_6 = uVar17;
  FUN_0801d208(uVar5,uVar7);
  if (in_ZR == '\0') {
    FUN_0801d208(uVar5,uVar7);
    uVar14 = (uint)lVar15;
    uVar3 = (uint)((ulonglong)lVar15 >> 0x20);
    if (in_ZR == '\0') {
      FUN_0801d208(uVar5,uVar7);
      if (in_ZR == '\0') {
        FUN_0801d208(uVar5,uVar7);
        if (in_ZR != '\0') {
          uVar16 = FUN_0801cfee(uVar12,uVar2,uVar8,uVar1);
          uVar17 = FUN_0801d0de((uint)uVar16,(uint)(uVar16 >> 0x20),uVar14,uVar3);
          uVar17 = FUN_0801d0de((uint)uVar17,(uint)((ulonglong)uVar17 >> 0x20),0,0x40180000);
          uVar16 = FUN_0801ceac((uint)uVar17,(uint)((ulonglong)uVar17 >> 0x20),0x55555555,0x3fe55555
                               );
          *param_4 = uVar16;
        }
      }
      else {
        uVar16 = FUN_0801cfee((uint)lVar10,uVar11,uVar12,uVar2);
        uVar17 = FUN_0801d0de((uint)uVar16,(uint)(uVar16 >> 0x20),uVar14,uVar3);
        uVar17 = FUN_0801d0de((uint)uVar17,(uint)((ulonglong)uVar17 >> 0x20),0,0x40180000);
        uVar16 = FUN_0801ceac((uint)uVar17,(uint)((ulonglong)uVar17 >> 0x20),0x55555555,0x3fd55555);
        *param_4 = uVar16;
      }
    }
    else {
      uVar16 = FUN_0801cfee(uVar8,uVar1,(uint)lVar10,uVar11);
      uVar17 = FUN_0801d0de((uint)uVar16,(uint)(uVar16 >> 0x20),uVar14,uVar3);
      uVar16 = FUN_0801d0de((uint)uVar17,(uint)((ulonglong)uVar17 >> 0x20),0,0x40180000);
      *param_4 = uVar16;
    }
    FUN_0801d208((int)*param_4,(int)(*param_4 >> 0x20));
    if (in_CY == '\0') {
      uVar16 = FUN_0801ceac((uint)*param_4,(uint)(*param_4 >> 0x20),0,0x3ff00000);
      *param_4 = uVar16;
    }
    FUN_0801d238((int)*param_6,(int)((ulonglong)*param_6 >> 0x20));
    if (in_CY == '\0') {
      uVar16 = FUN_0801cfee(0,0x40000000,uVar5,uVar7);
      uVar16 = FUN_0801cfee((uint)uVar16,(uint)(uVar16 >> 0x20),uVar4,uVar6);
      lVar15 = (uVar16 & 0xffffffff00000000) + (uVar16 & 0xffffffff);
      uVar17 = FUN_0801d0de(uVar14,uVar3,(uint)lVar15,(uint)((ulonglong)lVar15 >> 0x20));
      *param_5 = uVar17;
    }
    else {
      uVar16 = FUN_0801ceac(uVar5,uVar7,uVar4,uVar6);
      lVar15 = (uVar16 & 0xffffffff00000000) + (uVar16 & 0xffffffff);
      uVar17 = FUN_0801d0de(uVar14,uVar3,(uint)lVar15,(uint)((ulonglong)lVar15 >> 0x20));
      *param_5 = uVar17;
    }
  }
  else {
    *param_4 = 0;
    *param_5 = 0;
  }
  return;
}

