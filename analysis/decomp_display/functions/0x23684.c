// rea decompile_all
// name: FUN_00023684
// address: 0x23684
// body: available
// range: 0x23684-0x2368b inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00023684(int param_1,byte *param_2)

{
  ushort uVar1;
  byte bVar2;
  undefined2 *puVar3;
  undefined2 uStack_54;
  undefined4 uStack_38;
  undefined4 uStack_34;
  short sStack_30;
  short sStack_2e;
  undefined2 uStack_2c;
  undefined2 uStack_2a;
  undefined2 uStack_28;
  undefined2 uStack_26;
  byte bStack_24;
  undefined2 uStack_22;
  undefined2 uStack_20;
  short sStack_1c;
  short sStack_1a;
  byte *pbStack_14;
  byte *local_10;
  int local_c;
  
  pbStack_14 = *(byte **)(param_2 + 0x1c);
  local_10 = param_2;
  local_c = param_1;
  if ((param_2[1] & 1) != 0) {
    if ((int)((uint)param_2[1] * 0x1000000) < 0) {
      param_2[0x1a] = 1;
      *param_2 = *param_2 | 0x20;
    }
    if (-1 < (int)((uint)param_2[1] * 0x40000000)) {
      if ((*pbStack_14 & 1) != 0) {
        *pbStack_14 = *pbStack_14 & 0xfe;
        *param_2 = *param_2 | 0x20;
        param_2[0x1a] = 5;
        pbStack_14[0x18] = pbStack_14[0x18] == 0;
      }
      FUN_00023718();
      return;
    }
    *pbStack_14 = *pbStack_14 | 1;
    *param_2 = *param_2 | 0x20;
    param_2[0x1a] = 4;
    param_2[1] = param_2[1] & 0xfe;
  }
  if ((int)((uint)*param_2 * 0x4000000) < 0) {
    FUN_000227a4(param_1,&sStack_1c);
    *(short *)(local_10 + 8) = *(short *)(local_10 + 0x10) + sStack_1c;
    *(short *)(local_10 + 10) = *(short *)(local_10 + 0x12) + sStack_1a;
    *(short *)(local_10 + 0xc) = *(short *)(local_10 + 0x14) + sStack_1c;
    *(short *)(local_10 + 0xe) = *(short *)(local_10 + 0x16) + sStack_1a;
    if ((*(short *)(local_10 + 0xe) <= *(short *)(local_c + 0x14)) &&
       (*(short *)(local_10 + 0xc) <= *(short *)(local_c + 0x12))) {
      if ((int)((uint)*local_10 * 0x10000000) < 0) {
        bVar2 = 1;
        if ((pbStack_14[1] & 1) != 0) {
          bVar2 = 3;
        }
        if (*(short *)(*(int *)(pbStack_14 + 0xc) + 6) < *(short *)(*(int *)(pbStack_14 + 0xc) + 8))
        {
          uVar1 = *(ushort *)(*(int *)(pbStack_14 + 0xc) + 8);
        }
        else {
          uVar1 = *(ushort *)(*(int *)(pbStack_14 + 0xc) + 6);
        }
        if (((int)((uint)*local_10 * 0x2000000) < 0) || ((int)((uint)*pbStack_14 * 0x40000000) < 0))
        {
          FUN_000210d0(local_c,(int)local_10);
          uStack_26 = *(undefined2 *)(pbStack_14 + 4);
          uStack_28 = *(undefined2 *)(pbStack_14 + 2);
          if ((*pbStack_14 & 1) != 0) {
            if ((int)((uint)pbStack_14[1] * 0x40000000) < 0) {
              uStack_26 = *(undefined2 *)(pbStack_14 + 2);
              uStack_28 = *(undefined2 *)(pbStack_14 + 4);
            }
            else if ((int)((uint)pbStack_14[1] * 0x20000000) < 0) {
              uStack_26 = *(undefined2 *)(pbStack_14 + 8);
              uStack_28 = *(undefined2 *)(pbStack_14 + 6);
            }
          }
          if (-1 < (int)((uint)pbStack_14[1] * 0x8000000)) {
            FUN_0001e294(*(short *)(local_10 + 8) + (ushort)bVar2,
                         *(short *)(local_10 + 10) + (ushort)bVar2,
                         *(short *)(local_10 + 0xc) - (ushort)bVar2,
                         *(short *)(local_10 + 0xe) - (ushort)bVar2,uStack_26);
          }
          sStack_30 = *(short *)(local_10 + 8) + (uVar1 & 0xff) + (ushort)bVar2 * 3;
          sStack_2e = *(short *)(local_10 + 10) + (ushort)bVar2;
          uStack_2c = *(undefined2 *)(local_10 + 0xc);
          uStack_2a = *(undefined2 *)(local_10 + 0xe);
          bStack_24 = pbStack_14[0x10];
          uStack_34 = *(undefined4 *)(pbStack_14 + 0xc);
          uStack_22 = 2;
          uStack_20 = 2;
          uStack_38 = *(undefined4 *)(pbStack_14 + 0x14);
          FUN_0002049c(&uStack_38);
          *local_10 = *local_10 & 0xbf;
          FUN_00021104(local_c,(int)local_10);
        }
        if (pbStack_14[0x18] == 0) {
          FUN_0001e610(*(short *)(local_10 + 8) + (ushort)bVar2 + 1,
                       *(short *)(local_10 + 10) + (ushort)bVar2,
                       *(short *)(local_10 + 8) + (uVar1 & 0xff) + (ushort)bVar2 + -1,
                       *(short *)(local_10 + 10) + (uVar1 & 0xff) + (ushort)bVar2 + -2,
                       *(undefined2 *)(pbStack_14 + 4));
          FUN_0001e610(*(short *)(local_10 + 8) + (ushort)bVar2,
                       *(short *)(local_10 + 10) + (ushort)bVar2,
                       *(short *)(local_10 + 8) + (uVar1 & 0xff) + (ushort)bVar2 + -1,
                       *(short *)(local_10 + 10) + (uVar1 & 0xff) + (ushort)bVar2 + -1,
                       *(undefined2 *)(pbStack_14 + 4));
          FUN_0001e610(*(short *)(local_10 + 8) + (ushort)bVar2,
                       *(short *)(local_10 + 10) + (ushort)bVar2 + 1,
                       *(short *)(local_10 + 8) + (uVar1 & 0xff) + (ushort)bVar2 + -2,
                       *(short *)(local_10 + 10) + (uVar1 & 0xff) + (ushort)bVar2 + -1,
                       *(undefined2 *)(pbStack_14 + 4));
          FUN_0001e610(*(short *)(local_10 + 8) + (uVar1 & 0xff) + (ushort)bVar2 + -1,
                       *(short *)(local_10 + 10) + (ushort)bVar2 + 1,
                       *(short *)(local_10 + 8) + (ushort)bVar2 + 1,
                       *(short *)(local_10 + 10) + (uVar1 & 0xff) + (ushort)bVar2 + -1,
                       *(undefined2 *)(pbStack_14 + 4));
          FUN_0001e610(*(short *)(local_10 + 8) + (uVar1 & 0xff) + (ushort)bVar2 + -1,
                       *(short *)(local_10 + 10) + (ushort)bVar2,
                       *(short *)(local_10 + 8) + (ushort)bVar2,
                       *(short *)(local_10 + 10) + (uVar1 & 0xff) + (ushort)bVar2 + -1,
                       *(undefined2 *)(pbStack_14 + 4));
          FUN_0001e610(*(short *)(local_10 + 8) + (uVar1 & 0xff) + (ushort)bVar2 + -2,
                       *(short *)(local_10 + 10) + (ushort)bVar2,
                       *(short *)(local_10 + 8) + (ushort)bVar2,
                       *(short *)(local_10 + 10) + (uVar1 & 0xff) + (ushort)bVar2 + -2,
                       *(undefined2 *)(pbStack_14 + 4));
        }
        else {
          FUN_0001e610(*(short *)(local_10 + 8) + (ushort)bVar2 + 1,
                       *(short *)(local_10 + 10) + (ushort)bVar2,
                       *(short *)(local_10 + 8) + (uVar1 & 0xff) + (ushort)bVar2 + -1,
                       *(short *)(local_10 + 10) + (uVar1 & 0xff) + (ushort)bVar2 + -2,
                       *(undefined2 *)(pbStack_14 + 2));
          FUN_0001e610(*(short *)(local_10 + 8) + (ushort)bVar2,
                       *(short *)(local_10 + 10) + (ushort)bVar2,
                       *(short *)(local_10 + 8) + (uVar1 & 0xff) + (ushort)bVar2 + -1,
                       *(short *)(local_10 + 10) + (uVar1 & 0xff) + (ushort)bVar2 + -1,
                       *(undefined2 *)(pbStack_14 + 2));
          FUN_0001e610(*(short *)(local_10 + 8) + (ushort)bVar2,
                       *(short *)(local_10 + 10) + (ushort)bVar2 + 1,
                       *(short *)(local_10 + 8) + (uVar1 & 0xff) + (ushort)bVar2 + -2,
                       *(short *)(local_10 + 10) + (uVar1 & 0xff) + (ushort)bVar2 + -1,
                       *(undefined2 *)(pbStack_14 + 2));
          FUN_0001e610(*(short *)(local_10 + 8) + (uVar1 & 0xff) + (ushort)bVar2 + -1,
                       *(short *)(local_10 + 10) + (ushort)bVar2 + 1,
                       *(short *)(local_10 + 8) + (ushort)bVar2 + 1,
                       *(short *)(local_10 + 10) + (uVar1 & 0xff) + (ushort)bVar2 + -1,
                       *(undefined2 *)(pbStack_14 + 2));
          FUN_0001e610(*(short *)(local_10 + 8) + (uVar1 & 0xff) + (ushort)bVar2 + -1,
                       *(short *)(local_10 + 10) + (ushort)bVar2,
                       *(short *)(local_10 + 8) + (ushort)bVar2,
                       *(short *)(local_10 + 10) + (uVar1 & 0xff) + (ushort)bVar2 + -1,
                       *(undefined2 *)(pbStack_14 + 2));
          FUN_0001e610(*(short *)(local_10 + 8) + (uVar1 & 0xff) + (ushort)bVar2 + -2,
                       *(short *)(local_10 + 10) + (ushort)bVar2,
                       *(short *)(local_10 + 8) + (ushort)bVar2,
                       *(short *)(local_10 + 10) + (uVar1 & 0xff) + (ushort)bVar2 + -2,
                       *(undefined2 *)(pbStack_14 + 2));
        }
        if (-1 < (int)((uint)pbStack_14[1] * 0x10000000)) {
          if ((pbStack_14[1] & 1) == 0) {
            if ((*pbStack_14 & 1) == 0) {
              uStack_54 = *(undefined2 *)(pbStack_14 + 6);
            }
            else {
              uStack_54 = *(undefined2 *)(pbStack_14 + 8);
            }
            FUN_0001e930(*(short *)(local_10 + 8),*(short *)(local_10 + 10),
                         *(short *)(local_10 + 8) + (uVar1 & 0xff) + (ushort)bVar2 * 2 + -1,
                         *(short *)(local_10 + 10) + (uVar1 & 0xff) + (ushort)bVar2 * 2 + -1,
                         uStack_54);
          }
          else {
            puVar3 = (undefined2 *)0x56b64;
            if ((*pbStack_14 & 1) != 0) {
              puVar3 = (undefined2 *)0x56b4c;
            }
            FUN_00020c68(*(short *)(local_10 + 8),*(short *)(local_10 + 10),
                         *(short *)(local_10 + 8) + (uVar1 & 0xff) + (ushort)bVar2 * 2 + -1,
                         (uVar1 & 0xff) + *(short *)(local_10 + 10) + (ushort)bVar2 * 2 + -1,puVar3)
            ;
          }
        }
      }
      else if (-1 < (int)((uint)pbStack_14[1] * 0x8000000)) {
        FUN_0001e294(*(short *)(local_10 + 8),*(short *)(local_10 + 10),*(short *)(local_10 + 0xc),
                     *(short *)(local_10 + 0xe),*(undefined2 *)(local_c + 0xc));
      }
      *local_10 = *local_10 & 0xdf;
    }
  }
  return;
}

