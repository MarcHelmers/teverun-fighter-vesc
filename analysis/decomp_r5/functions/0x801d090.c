// rea decompile_all
// name: FUN_0801d090
// address: 0x801d090
// body: available
// range: 0x801d090-0x801d1d1 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


ulonglong FUN_0801d090(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  ulonglong uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  bool bVar12;
  ulonglong uVar13;
  longlong lVar14;
  
  iVar3 = (int)(param_2 ^ param_4) >> 0x1f;
  uVar4 = -iVar3;
  uVar8 = param_3;
  uVar11 = param_4;
  if ((param_2 & 0x7fffffff) <= (param_4 & 0x7fffffff) &&
      (uint)(param_3 <= param_1) <= (param_2 & 0x7fffffff) - (param_4 & 0x7fffffff)) {
    uVar8 = param_1;
    uVar11 = param_2;
    param_2 = param_4;
    param_1 = param_3;
  }
  if ((uVar11 & 0x7fffffff) != 0 || uVar8 != 0) {
    uVar10 = param_2 >> 0x14;
    uVar5 = uVar10 & 0x7ff;
    uVar6 = uVar5 - ((uVar11 & 0x7fffffff) >> 0x14);
    if ((int)uVar6 < 0x40) {
      uVar11 = uVar11 & 0xfffff | 0x100000;
      if (uVar4 != 0) {
        bVar12 = uVar8 != 0;
        uVar8 = -uVar8;
        uVar11 = -(uint)bVar12 - uVar11;
      }
      uVar13 = FUN_0801d44c(uVar8,uVar11,0x40 - uVar6);
      uVar9 = (uint)(uVar13 >> 0x20);
      uVar7 = (uint)uVar13;
      lVar14 = FUN_0801d48a(uVar8,uVar11,uVar6);
      uVar1 = lVar14 + CONCAT44(param_2,param_1);
      uVar8 = (uint)uVar1;
      uVar11 = (uint)(uVar1 >> 0x20);
      if ((param_2 ^ uVar11) >> 0x14 != 0) {
        if (uVar4 == 0) {
          uVar13 = CONCAT44(uVar9 >> 1 | uVar8 * -0x80000000,
                            (uint)((uVar13 & 0x100000000) != 0) << 0x1f | uVar7 >> 1);
          uVar11 = uVar11 + uVar10 * -0x100000 + 0x100000;
          uVar1 = CONCAT44((uVar11 >> 1) + uVar10 * 0x100000,
                           (uint)((uVar11 & 1) != 0) << 0x1f | uVar8 >> 1);
        }
        else {
          if ((int)uVar6 < 2) {
            uVar13 = FUN_0801d4cc(uVar8,uVar11 + uVar10 * -0x100000 + 0x100000,uVar7,uVar9,0,
                                  (uVar10 & 0x800) << 0x14,uVar5);
            return uVar13;
          }
          uVar1 = CONCAT44(uVar10 * -0x100000 + uVar11 * 2 + (uint)CARRY4(uVar8,uVar8),
                           uVar8 * 2 | uVar9 >> 0x1f);
          uVar13 = CONCAT44(uVar9 * 2 + (uint)CARRY4(uVar7,uVar7),uVar7 * 2);
        }
      }
    }
    else {
      uVar13 = CONCAT44(-(uint)(1 < (uint)(iVar3 * -2)),iVar3 * 2 + 1);
      uVar1 = CONCAT44(param_2 - (param_1 < uVar4),param_1 + iVar3);
    }
    if ((longlong)uVar13 < 0) {
      uVar2 = uVar1 + 1;
      uVar1 = uVar1 + 1;
      if ((uVar13 & 0x7fffffff) == 0 &&
          (int)(uVar13 >> 0x20) * 2 + (uint)CARRY4((uint)uVar13,(uint)uVar13) == 0) {
        uVar1 = uVar2 & 0xfffffffffffffffe;
      }
    }
    return uVar1;
  }
  return CONCAT44(param_2,param_1);
}

