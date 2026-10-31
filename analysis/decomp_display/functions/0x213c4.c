// rea decompile_all
// name: FUN_000213c4
// address: 0x213c4
// body: available
// range: 0x213c4-0x214c3 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_000213c4(int param_1)

{
  short local_32;
  short local_30;
  short local_2e;
  undefined4 local_2c;
  undefined4 local_28;
  short local_24;
  short local_22;
  short local_20;
  short sStack_1e;
  undefined2 local_1c;
  undefined2 local_1a;
  undefined1 uStack_18;
  short sStack_16;
  short sStack_14;
  int local_10;
  char cStack_9;
  
  if ((param_1 == 0) || (-1 < (int)((uint)*(byte *)(param_1 + 8) * 0x40000000))) {
    cStack_9 = -1;
  }
  else {
    local_2e = *(short *)(param_1 + 0xe);
    local_30 = *(short *)(param_1 + 0x10);
    local_32 = *(short *)(param_1 + 0x12);
    if ((*(byte *)(param_1 + 0x16) & 1) != 0) {
      local_2e = local_2e + 3;
      local_30 = local_30 + 3;
      local_32 = local_32 + -3;
    }
    if (param_1 == *(int *)(_DAT_20000ca0 + 0x14)) {
      local_1a = *(undefined2 *)(param_1 + 0x26);
      local_1c = *(undefined2 *)(param_1 + 0x24);
    }
    else {
      local_1a = *(undefined2 *)(param_1 + 0x2a);
      local_1c = *(undefined2 *)(param_1 + 0x28);
    }
    local_10 = param_1;
    FUN_0001e294(local_2e,local_30,local_32,(ushort)*(byte *)(param_1 + 0x2c) + local_30 + -1,
                 local_1a);
    local_2c = *(undefined4 *)(local_10 + 0x18);
    local_28 = *(undefined4 *)(local_10 + 0x1c);
    local_24 = local_2e + 3;
    local_22 = local_30;
    local_20 = local_32;
    sStack_1e = local_30 + (ushort)*(byte *)(local_10 + 0x2c) + -1;
    uStack_18 = *(undefined1 *)(local_10 + 0x22);
    sStack_16 = (short)*(char *)(local_10 + 0x20);
    sStack_14 = (short)*(char *)(local_10 + 0x21);
    FUN_0002049c(&local_2c);
    local_30 = local_30 + (ushort)*(byte *)(local_10 + 0x2c);
    FUN_0001e610(local_2e,local_30,local_32,local_30,_DAT_00056b92);
    cStack_9 = '\0';
  }
  return (int)cStack_9;
}

