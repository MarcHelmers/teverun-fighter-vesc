// rea decompile_all
// name: FUN_00022ad0
// address: 0x22ad0
// body: available
// range: 0x22ad0-0x22e07 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00022ad0(int param_1,byte *param_2)

{
  byte bVar1;
  undefined2 *puVar2;
  undefined2 local_50;
  undefined4 local_38;
  undefined4 local_34;
  short local_30;
  short local_2e;
  short local_2c;
  short local_2a;
  undefined2 local_28;
  undefined2 local_26;
  byte local_24;
  undefined2 local_22;
  undefined2 local_20;
  short local_1c;
  short local_1a;
  byte *local_14;
  byte *local_10;
  int local_c;
  
  local_14 = *(byte **)(param_2 + 0x1c);
  if ((param_2[1] & 1) != 0) {
    if ((int)((uint)param_2[1] * 0x1000000) < 0) {
      param_2[0x1a] = 1;
      *param_2 = *param_2 | 0x20;
    }
    if ((int)((uint)param_2[1] * 0x40000000) < 0) {
      *local_14 = *local_14 | 1;
      *param_2 = *param_2 | 0x20;
      param_2[0x1a] = 4;
    }
    else if ((*local_14 & 1) != 0) {
      *local_14 = *local_14 & 0xfe;
      *param_2 = *param_2 | 0x20;
      param_2[0x1a] = 5;
    }
    param_2[1] = param_2[1] & 0xfe;
  }
  if ((int)((uint)*param_2 * 0x4000000) < 0) {
    local_10 = param_2;
    local_c = param_1;
    if ((int)((uint)*param_2 * 0x10000000) < 0) {
      if (((int)((uint)*param_2 * 0x2000000) < 0) || ((int)((uint)*local_14 * 0x40000000) < 0)) {
        FUN_000227a4(param_1,&local_1c);
        *(short *)(local_10 + 8) = *(short *)(local_10 + 0x10) + local_1c;
        *(short *)(local_10 + 10) = *(short *)(local_10 + 0x12) + local_1a;
        *(short *)(local_10 + 0xc) = *(short *)(local_10 + 0x14) + local_1c;
        *(short *)(local_10 + 0xe) = *(short *)(local_10 + 0x16) + local_1a;
        if (*(short *)(local_c + 0x14) < *(short *)(local_10 + 0xe)) {
          return;
        }
        if (*(short *)(local_c + 0x12) < *(short *)(local_10 + 0xc)) {
          return;
        }
        FUN_000210d0(local_c,(int)local_10);
        bVar1 = 1;
        if ((local_14[1] & 1) != 0) {
          bVar1 = 3;
        }
        local_26 = *(undefined2 *)(local_14 + 4);
        local_28 = *(undefined2 *)(local_14 + 2);
        if ((*local_14 & 1) != 0) {
          if ((int)((uint)local_14[1] * 0x40000000) < 0) {
            local_26 = *(undefined2 *)(local_14 + 2);
            local_28 = *(undefined2 *)(local_14 + 4);
          }
          else if ((int)((uint)local_14[1] * 0x20000000) < 0) {
            local_26 = *(undefined2 *)(local_14 + 8);
            local_28 = *(undefined2 *)(local_14 + 6);
          }
        }
        if (-1 < (int)((uint)local_14[1] * 0x8000000)) {
          FUN_0001e294(*(short *)(local_10 + 8) + (ushort)bVar1,
                       *(short *)(local_10 + 10) + (ushort)bVar1,
                       *(short *)(local_10 + 0xc) - (ushort)bVar1,
                       *(short *)(local_10 + 0xe) - (ushort)bVar1,local_26);
        }
        local_30 = *(short *)(local_10 + 8) + (ushort)bVar1;
        local_2e = *(short *)(local_10 + 10) + (ushort)bVar1;
        local_2c = *(short *)(local_10 + 0xc) - (ushort)bVar1;
        local_2a = *(short *)(local_10 + 0xe) - (ushort)bVar1;
        local_24 = local_14[0x10];
        local_34 = *(undefined4 *)(local_14 + 0xc);
        local_22 = 2;
        local_20 = 2;
        local_38 = *(undefined4 *)(local_14 + 0x14);
        FUN_0002049c(&local_38);
        *local_10 = *local_10 & 0xbf;
        FUN_00021104(local_c,(int)local_10);
      }
      if (-1 < (int)((uint)local_14[1] * 0x10000000)) {
        if ((local_14[1] & 1) == 0) {
          if ((*local_14 & 1) == 0) {
            local_50 = *(undefined2 *)(local_14 + 6);
          }
          else {
            local_50 = *(undefined2 *)(local_14 + 8);
          }
          FUN_0001e930(*(short *)(local_10 + 8),*(short *)(local_10 + 10),*(short *)(local_10 + 0xc)
                       ,*(short *)(local_10 + 0xe),local_50);
        }
        else {
          puVar2 = (undefined2 *)0x56b34;
          if ((*local_14 & 1) != 0) {
            puVar2 = (undefined2 *)0x56b1c;
          }
          FUN_00020c68(*(short *)(local_10 + 8),*(short *)(local_10 + 10),*(short *)(local_10 + 0xc)
                       ,*(short *)(local_10 + 0xe),puVar2);
        }
      }
    }
    else if (-1 < (int)((uint)local_14[1] * 0x8000000)) {
      FUN_0001e294(*(short *)(param_2 + 8),*(short *)(param_2 + 10),*(short *)(param_2 + 0xc),
                   *(short *)(param_2 + 0xe),*(undefined2 *)(param_1 + 0xc));
    }
    *local_10 = *local_10 & 0xdf;
  }
  return;
}

