// rea decompile_all
// name: FUN_0801d384
// address: 0x801d384
// body: available
// range: 0x801d384-0x801d3a7 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


ulonglong FUN_0801d384(void)

{
  int iVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte *extraout_r2;
  byte *pbVar5;
  byte *pbVar6;
  uint uVar7;
  undefined4 *puVar8;
  uint uVar9;
  uint unaff_r10;
  uint unaff_r11;
  undefined1 uVar10;
  bool bVar11;
  undefined1 uVar12;
  undefined8 uVar13;
  ulonglong uVar14;
  ulonglong uVar15;
  longlong lVar16;
  uint in_stack_00000020;
  int in_stack_00000024;
  int in_stack_00000028;
  
  puVar8 = &DAT_0801d8a8;
  while( true ) {
    uVar12 = &UNK_0801d8c7 < puVar8;
    uVar10 = puVar8 == (undefined4 *)&DAT_0801d8c8;
    if ((bool)uVar12) break;
    (*(code *)puVar8[3])(*puVar8,puVar8[1],puVar8[2]);
    puVar8 = puVar8 + 4;
  }
  pbVar2 = (byte *)thunk_FUN_0800b882();
  pbVar5 = extraout_r2;
  while (!(bool)uVar12 || (bool)uVar10) {
    pbVar4 = (byte *)0x0;
    do {
      uVar9 = (uint)*pbVar2;
      uVar7 = uVar9 & 7;
      pbVar3 = pbVar2 + 1;
      if ((*pbVar2 & 7) == 0) {
        pbVar3 = pbVar2 + 2;
        uVar7 = (uint)pbVar2[1];
      }
      pbVar6 = (byte *)((int)uVar9 >> 4);
      if (pbVar6 == (byte *)0x0) {
        pbVar6 = (byte *)(uint)*pbVar3;
        pbVar3 = pbVar3 + 1;
      }
      while (uVar7 = uVar7 - 1, uVar7 != 0) {
        *pbVar4 = *pbVar3;
        pbVar3 = pbVar3 + 1;
        pbVar4 = pbVar4 + 1;
      }
      if ((int)(uVar9 << 0x1c) < 0) {
        pbVar2 = pbVar3 + 1;
        pbVar6 = pbVar6 + 2;
        pbVar3 = pbVar4 + -(uint)*pbVar3;
        while (pbVar6 = pbVar6 + -1, -1 < (int)pbVar6) {
          *pbVar4 = *pbVar3;
          pbVar4 = pbVar4 + 1;
          pbVar3 = pbVar3 + 1;
        }
      }
      else {
        while (pbVar6 = pbVar6 + -1, pbVar2 = pbVar3, -1 < (int)pbVar6) {
          *pbVar4 = 0;
          pbVar4 = pbVar4 + 1;
        }
      }
      uVar12 = pbVar5 <= pbVar4;
    } while (!(bool)uVar12);
    pbVar2 = (byte *)0x0;
    pbVar5 = pbVar6;
    uVar10 = true;
  }
  uVar13 = func_0x0869e2fc();
  uVar9 = LZCOUNT((uint)uVar13) + 0x20;
  uVar14 = FUN_0801d268((uint)uVar13,(int)((ulonglong)uVar13 >> 0x20),uVar9);
  uVar7 = (uint)(uVar14 >> 0x20);
  if (((uint)uVar14 != 0 || unaff_r10 != 0) || (uVar7 != 0 || unaff_r11 != 0)) {
    if (unaff_r10 != 0 || unaff_r11 != 0) {
      uVar15 = FUN_0801d286(unaff_r10,unaff_r11,0x40 - uVar9);
      lVar16 = FUN_0801d268(unaff_r10,unaff_r11,uVar9);
      uVar14 = CONCAT44(uVar7 | (uint)(uVar15 >> 0x20),
                        (uint)uVar14 | (uint)uVar15 | (uint)(lVar16 != 0));
    }
    uVar7 = (uint)(uVar14 >> 0xb);
    iVar1 = (in_stack_00000028 - uVar9) + 10;
    if (-1 < iVar1) {
      uVar9 = uVar7 + in_stack_00000020;
      iVar1 = iVar1 * 0x100000 + (int)((uVar14 >> 0xb) >> 0x20) + in_stack_00000024 +
              (uint)CARRY4(uVar7,in_stack_00000020);
      if ((int)uVar14 * 0x200000 < 0) {
        bVar11 = 0xfffffffe < uVar9;
        uVar9 = uVar9 + 1;
        iVar1 = iVar1 + (uint)bVar11;
        if ((uVar14 & 0x3ff) == 0) {
          uVar9 = uVar9 & 0xfffffffe;
        }
      }
      return CONCAT44(iVar1,uVar9);
    }
    uVar14 = 0;
  }
  return uVar14;
}

