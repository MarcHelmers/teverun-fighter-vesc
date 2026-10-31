// rea decompile_all
// name: FUN_0001fc6c
// address: 0x1fc6c
// body: available
// range: 0x1fc6c-0x1fca7 inclusive
// range: 0x1fcf6-0x20235 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001fc6c(byte param_1,short param_2,short param_3,ushort param_4,uint param_5,int *param_6)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  code *pcVar5;
  int local_28;
  byte local_24;
  byte local_23;
  ushort local_20;
  ushort local_1e;
  short local_1c;
  short local_1a;
  ushort local_18;
  ushort local_16;
  ushort local_14;
  
  uVar1 = (ushort)param_5;
  local_24 = param_1;
  switch(param_1) {
  case 0xb0:
    local_24 = 0xf8;
    break;
  case 0xb5:
    local_24 = 0xe6;
    break;
  case 0xc4:
    local_24 = 0x8e;
    break;
  case 0xd6:
    local_24 = 0x99;
    break;
  case 0xdc:
    local_24 = 0x9a;
    break;
  case 0xe4:
    local_24 = 0x84;
    break;
  case 0xf6:
    local_24 = 0x94;
    break;
  case 0xfc:
    local_24 = 0x81;
  }
  if ((*(ushort *)((int)param_6 + 10) <= (ushort)local_24) &&
     ((ushort)local_24 <= *(ushort *)(param_6 + 3))) {
    uVar2 = *(short *)((int)param_6 + 6) -
            (ushort)*(byte *)(_DAT_20000ca0[0x19] +
                             ((uint)param_1 - (uint)*(ushort *)((int)_DAT_20000ca0 + 0x36)));
    if (*(ushort *)((int)param_6 + 6) != 0) {
      local_20 = *(ushort *)((int)param_6 + 6) >> 3;
      uVar4 = (uint)*(short *)((int)param_6 + 6);
      if (uVar4 != (uVar4 + (uVar4 >> 0x1d) & 0xfffffff8)) {
        local_20 = local_20 + 1;
      }
      uVar3 = uVar2;
      if (param_6[4] != 0) {
        uVar3 = (ushort)*(byte *)(param_6[4] +
                                 ((uint)local_24 - (uint)*(ushort *)((int)param_6 + 10)));
      }
      if ((int)((uint)*(byte *)(_DAT_20000ca0 + 0x18) * 0x40000000) < 0) {
        pcVar5 = (code *)(*(code *)_DAT_20000ca0[0x17])
                                   ((int)param_2,(int)param_3,(int)(short)(uVar3 + param_2 + -1),
                                    (int)(short)((short)param_6[2] + param_3 + -1));
        if ((char)param_6[1] == '\0') {
          local_28 = ((uint)local_24 - (uint)*(ushort *)((int)param_6 + 10)) *
                     (int)(short)param_6[2] * (uint)local_20;
          for (local_16 = 0; (int)(uint)local_16 < (int)(short)param_6[2]; local_16 = local_16 + 1)
          {
            local_1e = uVar3;
            for (local_14 = 0; local_14 < local_20; local_14 = local_14 + 1) {
              local_23 = *(byte *)(*param_6 + local_28);
              for (local_18 = 0; local_18 < 8 && local_1e != 0; local_18 = local_18 + 1) {
                if ((local_23 & 1) == 0) {
                  (*pcVar5)(uVar1);
                }
                else {
                  (*pcVar5)(param_4);
                }
                local_23 = local_23 >> 1;
                local_1e = local_1e - 1;
              }
              local_28 = local_28 + 1;
            }
          }
        }
        else if ((char)param_6[1] == '\x01') {
          local_28 = ((uint)local_24 - (uint)*(ushort *)((int)param_6 + 10)) *
                     (int)(short)param_6[2] * (int)(short)uVar2;
          for (local_16 = 0; (int)(uint)local_16 < (int)(short)param_6[2]; local_16 = local_16 + 1)
          {
            for (local_14 = 0; local_14 < uVar3; local_14 = local_14 + 1) {
              uVar4 = (uint)*(byte *)(*param_6 + local_28);
              (*pcVar5)((ushort)((int)(short)(uVar1 & 0xff) * (int)(short)(0x100 - uVar4) +
                                 (byte)param_4 * uVar4 >> 8) & 0xff |
                        (ushort)(((param_4 & 0xffffff00) * uVar4 +
                                  (param_5 & 0xff00) * (0x100 - uVar4) >> 0x10) << 8));
              local_28 = local_28 + 1;
            }
            local_28 = local_28 + ((int)(short)uVar2 - (uint)uVar3);
          }
        }
      }
      else {
        local_1c = param_3;
        if ((char)param_6[1] == '\0') {
          local_28 = ((uint)local_24 - (uint)*(ushort *)((int)param_6 + 10)) *
                     (int)(short)param_6[2] * (uint)local_20;
          for (local_16 = 0; (int)(uint)local_16 < (int)(short)param_6[2]; local_16 = local_16 + 1)
          {
            local_1e = uVar3;
            local_1a = param_2;
            for (local_14 = 0; local_14 < local_20; local_14 = local_14 + 1) {
              local_23 = *(byte *)(*param_6 + local_28);
              for (local_18 = 0; local_18 < 8 && local_1e != 0; local_18 = local_18 + 1) {
                if ((local_23 & 1) == 0) {
                  (*(code *)*_DAT_20000ca0)((int)local_1a,(int)local_1c,uVar1);
                }
                else {
                  (*(code *)*_DAT_20000ca0)((int)local_1a,(int)local_1c,param_4);
                }
                local_23 = local_23 >> 1;
                local_1a = local_1a + 1;
                local_1e = local_1e - 1;
              }
              local_28 = local_28 + 1;
            }
            local_1c = local_1c + 1;
          }
        }
        else if ((char)param_6[1] == '\x01') {
          local_28 = ((uint)local_24 - (uint)*(ushort *)((int)param_6 + 10)) *
                     (int)(short)param_6[2] * (int)(short)uVar2;
          for (local_16 = 0; (int)(uint)local_16 < (int)(short)param_6[2]; local_16 = local_16 + 1)
          {
            local_1a = param_2;
            for (local_14 = 0; local_14 < uVar3; local_14 = local_14 + 1) {
              uVar4 = (uint)*(byte *)(*param_6 + local_28);
              (*(code *)*_DAT_20000ca0)
                        ((int)local_1a,(int)local_1c,
                         (ushort)((int)(short)(uVar1 & 0xff) * (int)(short)(0x100 - uVar4) +
                                  (byte)param_4 * uVar4 >> 8) & 0xff |
                         (ushort)(((param_4 & 0xffffff00) * uVar4 +
                                   (param_5 & 0xff00) * (0x100 - uVar4) >> 0x10) << 8));
              local_1a = local_1a + 1;
              local_28 = local_28 + 1;
            }
            local_28 = local_28 + ((int)(short)uVar2 - (uint)uVar3);
            local_1c = local_1c + 1;
          }
        }
      }
    }
  }
  return;
}

