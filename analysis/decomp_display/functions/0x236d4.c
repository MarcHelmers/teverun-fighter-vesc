// rea decompile_all
// name: FUN_000236d4
// address: 0x236d4
// body: available
// range: 0x236d4-0x236d5 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_000236d4(undefined4 param_1,byte *param_2)

{
  ushort uVar1;
  short sVar2;
  ushort uVar3;
  ushort uVar4;
  undefined2 *puVar5;
  uint uStack00000004;
  uint uStack00000008;
  uint uStack0000000c;
  int iStack00000010;
  int iStack00000014;
  int iStack00000018;
  byte bStack0000001e;
  byte bStack0000001f;
  undefined4 in_stack_00000020;
  undefined4 in_stack_00000024;
  short in_stack_00000028;
  short in_stack_0000002a;
  undefined2 in_stack_0000002c;
  undefined2 in_stack_0000002e;
  undefined2 in_stack_00000030;
  undefined2 in_stack_00000032;
  byte in_stack_00000034;
  undefined2 in_stack_00000036;
  undefined2 in_stack_00000038;
  short in_stack_0000003c;
  short in_stack_0000003e;
  byte *in_stack_00000044;
  byte *in_stack_00000048;
  int in_stack_0000004c;
  
  *param_2 = *param_2 | 0x20;
  in_stack_00000048[0x1a] = 4;
  in_stack_00000048[1] = in_stack_00000048[1] & 0xfe;
  if ((int)((uint)*in_stack_00000048 * 0x4000000) < 0) {
    FUN_000227a4(in_stack_0000004c,&stack0x0000003c);
    *(short *)(in_stack_00000048 + 8) = *(short *)(in_stack_00000048 + 0x10) + in_stack_0000003c;
    *(short *)(in_stack_00000048 + 10) = *(short *)(in_stack_00000048 + 0x12) + in_stack_0000003e;
    *(short *)(in_stack_00000048 + 0xc) = *(short *)(in_stack_00000048 + 0x14) + in_stack_0000003c;
    *(short *)(in_stack_00000048 + 0xe) = *(short *)(in_stack_00000048 + 0x16) + in_stack_0000003e;
    if ((*(short *)(in_stack_00000048 + 0xe) <= *(short *)(in_stack_0000004c + 0x14)) &&
       (*(short *)(in_stack_00000048 + 0xc) <= *(short *)(in_stack_0000004c + 0x12))) {
      if ((int)((uint)*in_stack_00000048 * 0x10000000) < 0) {
        bStack0000001f = 1;
        if ((in_stack_00000044[1] & 1) != 0) {
          bStack0000001f = 3;
        }
        if (*(short *)(*(int *)(in_stack_00000044 + 0xc) + 6) <
            *(short *)(*(int *)(in_stack_00000044 + 0xc) + 8)) {
          sVar2 = *(short *)(*(int *)(in_stack_00000044 + 0xc) + 8);
        }
        else {
          sVar2 = *(short *)(*(int *)(in_stack_00000044 + 0xc) + 6);
        }
        iStack00000018 = (int)sVar2;
        bStack0000001e = (byte)sVar2;
        if (((int)((uint)*in_stack_00000048 * 0x2000000) < 0) ||
           ((int)((uint)*in_stack_00000044 * 0x40000000) < 0)) {
          FUN_000210d0(in_stack_0000004c,(int)in_stack_00000048);
          in_stack_00000032 = *(undefined2 *)(in_stack_00000044 + 4);
          in_stack_00000030 = *(undefined2 *)(in_stack_00000044 + 2);
          if ((*in_stack_00000044 & 1) != 0) {
            if ((int)((uint)in_stack_00000044[1] * 0x40000000) < 0) {
              in_stack_00000032 = *(undefined2 *)(in_stack_00000044 + 2);
              in_stack_00000030 = *(undefined2 *)(in_stack_00000044 + 4);
            }
            else if ((int)((uint)in_stack_00000044[1] * 0x20000000) < 0) {
              in_stack_00000032 = *(undefined2 *)(in_stack_00000044 + 8);
              in_stack_00000030 = *(undefined2 *)(in_stack_00000044 + 6);
            }
          }
          if (-1 < (int)((uint)in_stack_00000044[1] * 0x8000000)) {
            FUN_0001e294(*(short *)(in_stack_00000048 + 8) + (ushort)bStack0000001f,
                         *(short *)(in_stack_00000048 + 10) + (ushort)bStack0000001f,
                         *(short *)(in_stack_00000048 + 0xc) - (ushort)bStack0000001f,
                         *(short *)(in_stack_00000048 + 0xe) - (ushort)bStack0000001f,
                         in_stack_00000032);
          }
          in_stack_00000028 =
               *(short *)(in_stack_00000048 + 8) + (ushort)bStack0000001e +
               (ushort)bStack0000001f * 3;
          in_stack_0000002a = *(short *)(in_stack_00000048 + 10) + (ushort)bStack0000001f;
          in_stack_0000002c = *(undefined2 *)(in_stack_00000048 + 0xc);
          in_stack_0000002e = *(undefined2 *)(in_stack_00000048 + 0xe);
          in_stack_00000034 = in_stack_00000044[0x10];
          in_stack_00000024 = *(undefined4 *)(in_stack_00000044 + 0xc);
          in_stack_00000036 = 2;
          in_stack_00000038 = 2;
          in_stack_00000020 = *(undefined4 *)(in_stack_00000044 + 0x14);
          FUN_0002049c(&stack0x00000020);
          *in_stack_00000048 = *in_stack_00000048 & 0xbf;
          FUN_00021104(in_stack_0000004c,(int)in_stack_00000048);
        }
        if (in_stack_00000044[0x18] == 0) {
          FUN_0001e610(*(short *)(in_stack_00000048 + 8) + (ushort)bStack0000001f + 1,
                       *(short *)(in_stack_00000048 + 10) + (ushort)bStack0000001f,
                       *(short *)(in_stack_00000048 + 8) + (ushort)bStack0000001e +
                       (ushort)bStack0000001f + -1,
                       *(short *)(in_stack_00000048 + 10) + (ushort)bStack0000001e +
                       (ushort)bStack0000001f + -2,*(undefined2 *)(in_stack_00000044 + 4));
          FUN_0001e610(*(short *)(in_stack_00000048 + 8) + (ushort)bStack0000001f,
                       *(short *)(in_stack_00000048 + 10) + (ushort)bStack0000001f,
                       *(short *)(in_stack_00000048 + 8) + (ushort)bStack0000001e +
                       (ushort)bStack0000001f + -1,
                       *(short *)(in_stack_00000048 + 10) + (ushort)bStack0000001e +
                       (ushort)bStack0000001f + -1,*(undefined2 *)(in_stack_00000044 + 4));
          FUN_0001e610(*(short *)(in_stack_00000048 + 8) + (ushort)bStack0000001f,
                       *(short *)(in_stack_00000048 + 10) + (ushort)bStack0000001f + 1,
                       *(short *)(in_stack_00000048 + 8) + (ushort)bStack0000001e +
                       (ushort)bStack0000001f + -2,
                       *(short *)(in_stack_00000048 + 10) + (ushort)bStack0000001e +
                       (ushort)bStack0000001f + -1,*(undefined2 *)(in_stack_00000044 + 4));
          FUN_0001e610(*(short *)(in_stack_00000048 + 8) + (ushort)bStack0000001e +
                       (ushort)bStack0000001f + -1,
                       *(short *)(in_stack_00000048 + 10) + (ushort)bStack0000001f + 1,
                       *(short *)(in_stack_00000048 + 8) + (ushort)bStack0000001f + 1,
                       *(short *)(in_stack_00000048 + 10) + (ushort)bStack0000001e +
                       (ushort)bStack0000001f + -1,*(undefined2 *)(in_stack_00000044 + 4));
          FUN_0001e610(*(short *)(in_stack_00000048 + 8) + (ushort)bStack0000001e +
                       (ushort)bStack0000001f + -1,
                       *(short *)(in_stack_00000048 + 10) + (ushort)bStack0000001f,
                       *(short *)(in_stack_00000048 + 8) + (ushort)bStack0000001f,
                       *(short *)(in_stack_00000048 + 10) + (ushort)bStack0000001e +
                       (ushort)bStack0000001f + -1,*(undefined2 *)(in_stack_00000044 + 4));
          FUN_0001e610(*(short *)(in_stack_00000048 + 8) + (ushort)bStack0000001e +
                       (ushort)bStack0000001f + -2,
                       *(short *)(in_stack_00000048 + 10) + (ushort)bStack0000001f,
                       *(short *)(in_stack_00000048 + 8) + (ushort)bStack0000001f,
                       *(short *)(in_stack_00000048 + 10) + (ushort)bStack0000001e +
                       (ushort)bStack0000001f + -2,*(undefined2 *)(in_stack_00000044 + 4));
        }
        else {
          FUN_0001e610(*(short *)(in_stack_00000048 + 8) + (ushort)bStack0000001f + 1,
                       *(short *)(in_stack_00000048 + 10) + (ushort)bStack0000001f,
                       *(short *)(in_stack_00000048 + 8) + (ushort)bStack0000001e +
                       (ushort)bStack0000001f + -1,
                       *(short *)(in_stack_00000048 + 10) + (ushort)bStack0000001e +
                       (ushort)bStack0000001f + -2,*(undefined2 *)(in_stack_00000044 + 2));
          FUN_0001e610(*(short *)(in_stack_00000048 + 8) + (ushort)bStack0000001f,
                       *(short *)(in_stack_00000048 + 10) + (ushort)bStack0000001f,
                       *(short *)(in_stack_00000048 + 8) + (ushort)bStack0000001e +
                       (ushort)bStack0000001f + -1,
                       *(short *)(in_stack_00000048 + 10) + (ushort)bStack0000001e +
                       (ushort)bStack0000001f + -1,*(undefined2 *)(in_stack_00000044 + 2));
          FUN_0001e610(*(short *)(in_stack_00000048 + 8) + (ushort)bStack0000001f,
                       *(short *)(in_stack_00000048 + 10) + (ushort)bStack0000001f + 1,
                       *(short *)(in_stack_00000048 + 8) + (ushort)bStack0000001e +
                       (ushort)bStack0000001f + -2,
                       *(short *)(in_stack_00000048 + 10) + (ushort)bStack0000001e +
                       (ushort)bStack0000001f + -1,*(undefined2 *)(in_stack_00000044 + 2));
          FUN_0001e610(*(short *)(in_stack_00000048 + 8) + (ushort)bStack0000001e +
                       (ushort)bStack0000001f + -1,
                       *(short *)(in_stack_00000048 + 10) + (ushort)bStack0000001f + 1,
                       *(short *)(in_stack_00000048 + 8) + (ushort)bStack0000001f + 1,
                       *(short *)(in_stack_00000048 + 10) + (ushort)bStack0000001e +
                       (ushort)bStack0000001f + -1,*(undefined2 *)(in_stack_00000044 + 2));
          FUN_0001e610(*(short *)(in_stack_00000048 + 8) + (ushort)bStack0000001e +
                       (ushort)bStack0000001f + -1,
                       *(short *)(in_stack_00000048 + 10) + (ushort)bStack0000001f,
                       *(short *)(in_stack_00000048 + 8) + (ushort)bStack0000001f,
                       *(short *)(in_stack_00000048 + 10) + (ushort)bStack0000001e +
                       (ushort)bStack0000001f + -1,*(undefined2 *)(in_stack_00000044 + 2));
          FUN_0001e610(*(short *)(in_stack_00000048 + 8) + (ushort)bStack0000001e +
                       (ushort)bStack0000001f + -2,
                       *(short *)(in_stack_00000048 + 10) + (ushort)bStack0000001f,
                       *(short *)(in_stack_00000048 + 8) + (ushort)bStack0000001f,
                       *(short *)(in_stack_00000048 + 10) + (ushort)bStack0000001e +
                       (ushort)bStack0000001f + -2,*(undefined2 *)(in_stack_00000044 + 2));
        }
        if (-1 < (int)((uint)in_stack_00000044[1] * 0x10000000)) {
          if ((in_stack_00000044[1] & 1) == 0) {
            uVar3 = *(ushort *)(in_stack_00000048 + 8);
            uVar4 = *(ushort *)(in_stack_00000048 + 10);
            uStack00000008 = (uint)uVar3;
            uStack0000000c = (uint)uVar4;
            iStack00000010 =
                 (int)(short)uVar3 + (uint)bStack0000001e + (uint)bStack0000001f * 2 + -1;
            iStack00000014 =
                 (int)(short)uVar4 + (uint)bStack0000001e + (uint)bStack0000001f * 2 + -1;
            if ((*in_stack_00000044 & 1) == 0) {
              uVar1 = *(ushort *)(in_stack_00000044 + 6);
            }
            else {
              uVar1 = *(ushort *)(in_stack_00000044 + 8);
            }
            uStack00000004 = (uint)uVar1;
            FUN_0001e930(uVar3,uVar4,(short)iStack00000010,(short)iStack00000014,uVar1);
          }
          else {
            puVar5 = (undefined2 *)0x56b64;
            if ((*in_stack_00000044 & 1) != 0) {
              puVar5 = (undefined2 *)0x56b4c;
            }
            FUN_00020c68(*(short *)(in_stack_00000048 + 8),*(short *)(in_stack_00000048 + 10),
                         *(short *)(in_stack_00000048 + 8) + (ushort)bStack0000001e +
                         (ushort)bStack0000001f * 2 + -1,
                         (ushort)bStack0000001e + *(short *)(in_stack_00000048 + 10) +
                         (ushort)bStack0000001f * 2 + -1,puVar5);
          }
        }
      }
      else if (-1 < (int)((uint)in_stack_00000044[1] * 0x8000000)) {
        FUN_0001e294(*(short *)(in_stack_00000048 + 8),*(short *)(in_stack_00000048 + 10),
                     *(short *)(in_stack_00000048 + 0xc),*(short *)(in_stack_00000048 + 0xe),
                     *(undefined2 *)(in_stack_0000004c + 0xc));
      }
      *in_stack_00000048 = *in_stack_00000048 & 0xdf;
    }
  }
  return;
}

