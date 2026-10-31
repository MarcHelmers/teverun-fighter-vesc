// rea decompile_all
// name: FUN_0002049c
// address: 0x2049c
// body: available
// range: 0x2049c-0x20799 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0002049c(undefined4 *param_1)

{
  byte bVar1;
  byte bVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  ushort uVar6;
  short sVar7;
  short sVar8;
  short sVar9;
  ushort uVar10;
  bool bVar11;
  byte *local_34;
  byte *local_30;
  short local_16;
  short local_14;
  short local_12;
  short local_10;
  
  sVar3 = *(short *)(param_1 + 2);
  sVar4 = *(short *)((int)param_1 + 10);
  sVar5 = *(short *)(param_1 + 3);
  bVar1 = *(byte *)(param_1 + 5);
  uVar6 = *(ushort *)(param_1[1] + 6);
  sVar7 = *(short *)(param_1[1] + 8);
  sVar8 = *(short *)((int)param_1 + 0x16);
  sVar9 = *(short *)(param_1 + 6);
  local_30 = (byte *)*param_1;
  if (((*(int *)param_1[1] != 0) && (local_30 != (byte *)0x0)) &&
     ((int)*(short *)(param_1[1] + 8) <= (int)*(short *)((int)param_1 + 0xe) - (int)sVar4)) {
    local_10 = 1;
    for (local_34 = local_30; *local_34 != 0; local_34 = local_34 + 1) {
      if (*local_34 == 10) {
        local_10 = local_10 + 1;
      }
    }
    local_16 = 0;
    if (((bVar1 & 0x30) == 0) ||
       (local_16 = (((*(short *)((int)param_1 + 0xe) - sVar4) + 1) - sVar7 * local_10) -
                   sVar9 * (local_10 + -1), (uint)(int)local_16 < 0x80000000)) {
      if ((int)((uint)bVar1 * 0x8000000) < 0) {
        local_16 = (short)((uint)(int)local_16 >> 1);
      }
      local_16 = local_16 + sVar4;
      while( true ) {
        local_34 = local_30;
        local_12 = 0;
        while( true ) {
          bVar11 = false;
          if (*local_34 != 0) {
            bVar11 = *local_34 != 10;
          }
          if (!bVar11) break;
          if (((ushort)*local_34 < *(ushort *)(param_1[1] + 10)) ||
             (*(ushort *)(param_1[1] + 0xc) < (ushort)*local_34)) {
            local_34 = local_34 + 1;
          }
          else {
            uVar10 = uVar6;
            if (*(int *)(param_1[1] + 0x10) != 0) {
              uVar10 = (ushort)*(byte *)(*(int *)(param_1[1] + 0x10) +
                                        ((uint)*local_34 - (uint)*(ushort *)(param_1[1] + 10)));
            }
            local_12 = local_12 + sVar8 + uVar10;
            local_34 = local_34 + 1;
          }
        }
        local_14 = ((sVar5 - sVar3) + 1) - (local_12 - sVar8);
        if (0x7fffffff < (uint)(int)local_14) break;
        if ((bVar1 & 1) == 0) {
          if ((int)((uint)bVar1 * 0x40000000) < 0) {
            local_14 = (short)((uint)(int)local_14 >> 1);
          }
        }
        else {
          local_14 = 0;
        }
        local_14 = local_14 + sVar3;
        while (*local_30 != 10) {
          bVar2 = *local_30;
          if (bVar2 == 0) {
            return;
          }
          FUN_0001f6bc(bVar2,local_14,local_16,*(ushort *)(param_1 + 4),
                       (uint)*(ushort *)((int)param_1 + 0x12),(int *)param_1[1]);
          uVar10 = uVar6;
          if (*(int *)(param_1[1] + 0x10) != 0) {
            uVar10 = (ushort)*(byte *)(*(int *)(param_1[1] + 0x10) +
                                      ((uint)bVar2 - (uint)*(ushort *)(param_1[1] + 10)));
          }
          local_14 = local_14 + sVar8 + uVar10;
          local_30 = local_30 + 1;
        }
        local_30 = local_30 + 1;
        local_16 = local_16 + sVar9 + sVar7;
      }
    }
  }
  return;
}

