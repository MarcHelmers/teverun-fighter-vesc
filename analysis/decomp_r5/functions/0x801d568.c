// rea decompile_all
// name: FUN_0801d568
// address: 0x801d568
// body: available
// range: 0x801d568-0x801d58b inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


ulonglong FUN_0801d568(void)

{
  int iVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte *extraout_r2;
  byte *pbVar5;
  byte *pbVar6;
  byte *extraout_r3;
  uint uVar7;
  byte *pbVar8;
  undefined4 *puVar9;
  uint uVar10;
  uint unaff_r8;
  uint unaff_r10;
  uint unaff_r11;
  char cVar11;
  bool bVar12;
  char cVar13;
  ulonglong uVar14;
  ulonglong uVar15;
  longlong lVar16;
  uint in_stack_00000020;
  int in_stack_00000024;
  int in_stack_00000028;
  
  puVar9 = &DAT_0801da8c;
  while( true ) {
    cVar13 = SBORROW4((int)puVar9,0x801daac);
    cVar11 = (int)(puVar9 + -0x20076ab) < 0;
    if (&UNK_0801daab < puVar9) break;
    (*(code *)puVar9[3])(*puVar9,puVar9[1],puVar9[2]);
    puVar9 = puVar9 + 4;
  }
  lVar16 = thunk_FUN_0800b882();
  pbVar5 = extraout_r2;
  pbVar8 = extraout_r3;
  while( true ) {
    pbVar3 = (byte *)lVar16;
    if (cVar11 == cVar13) {
      return CONCAT44(pbVar8,(uint)pbVar3 >> ((uint)pbVar5 & 0xff) |
                             (int)((ulonglong)lVar16 >> 0x20) << (0x20U - (int)pbVar5 & 0xff));
    }
    if (cVar13 == '\0') break;
    pbVar4 = (byte *)0x0;
    do {
      uVar10 = (uint)*pbVar3;
      uVar7 = uVar10 & 7;
      pbVar2 = pbVar3 + 1;
      if ((*pbVar3 & 7) == 0) {
        pbVar2 = pbVar3 + 2;
        uVar7 = (uint)pbVar3[1];
      }
      pbVar6 = (byte *)((int)uVar10 >> 4);
      if (pbVar6 == (byte *)0x0) {
        pbVar6 = (byte *)(uint)*pbVar2;
        pbVar2 = pbVar2 + 1;
      }
      while (uVar7 = uVar7 - 1, uVar7 != 0) {
        *pbVar4 = *pbVar2;
        pbVar2 = pbVar2 + 1;
        pbVar4 = pbVar4 + 1;
      }
      if ((int)(uVar10 << 0x1c) < 0) {
        pbVar3 = pbVar2 + 1;
        pbVar6 = pbVar6 + 2;
        pbVar8 = pbVar4 + -(uint)*pbVar2;
        while (pbVar6 = pbVar6 + -1, -1 < (int)pbVar6) {
          *pbVar4 = *pbVar8;
          pbVar4 = pbVar4 + 1;
          pbVar8 = pbVar8 + 1;
        }
      }
      else {
        pbVar8 = (byte *)0x0;
        while (pbVar6 = pbVar6 + -1, pbVar3 = pbVar2, -1 < (int)pbVar6) {
          *pbVar4 = 0;
          pbVar4 = pbVar4 + 1;
        }
      }
      cVar13 = SBORROW4((int)pbVar4,(int)pbVar5);
    } while (pbVar4 < pbVar5);
    lVar16 = ZEXT48(pbVar4) << 0x20;
    cVar11 = '\0';
    pbVar5 = pbVar6;
  }
  uVar14 = FUN_0801d44c((uint)pbVar3,0,(uint)pbVar5);
  uVar7 = (uint)(uVar14 >> 0x20);
  if (((uint)uVar14 != 0 || unaff_r10 != 0) || (uVar7 != 0 || unaff_r11 != 0)) {
    if (unaff_r10 != 0 || unaff_r11 != 0) {
      uVar15 = FUN_0801d46a(unaff_r10,unaff_r11,0x40 - unaff_r8);
      lVar16 = FUN_0801d44c(unaff_r10,unaff_r11,unaff_r8);
      uVar14 = CONCAT44(uVar7 | (uint)(uVar15 >> 0x20),
                        (uint)uVar14 | (uint)uVar15 | (uint)(lVar16 != 0));
    }
    uVar7 = (uint)(uVar14 >> 0xb);
    iVar1 = (in_stack_00000028 - unaff_r8) + 10;
    if (-1 < iVar1) {
      uVar10 = uVar7 + in_stack_00000020;
      iVar1 = iVar1 * 0x100000 + (int)((uVar14 >> 0xb) >> 0x20) + in_stack_00000024 +
              (uint)CARRY4(uVar7,in_stack_00000020);
      if ((int)uVar14 * 0x200000 < 0) {
        bVar12 = 0xfffffffe < uVar10;
        uVar10 = uVar10 + 1;
        iVar1 = iVar1 + (uint)bVar12;
        if ((uVar14 & 0x3ff) == 0) {
          uVar10 = uVar10 & 0xfffffffe;
        }
      }
      return CONCAT44(iVar1,uVar10);
    }
    uVar14 = 0;
  }
  return uVar14;
}

