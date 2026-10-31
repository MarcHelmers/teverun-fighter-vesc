// rea decompile_all
// name: FUN_00021534
// address: 0x21534
// body: available
// range: 0x21534-0x216cb inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00021534(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  short local_1c;
  short local_1a;
  short local_18;
  short local_16;
  ushort local_e;
  
  local_16 = *(short *)(param_1 + 0xe);
  local_18 = *(short *)(param_1 + 0x10);
  local_1a = *(short *)(param_1 + 0x12);
  local_1c = *(short *)(param_1 + 0x14);
  param_1[8] = param_1[8] & 0xdf;
  if ((int)((uint)param_1[8] * 0x10000000) < 0) {
    if (((param_1[0x16] & 1) != 0) && (-1 < (int)((uint)param_1[8] * 0x2000000))) {
      FUN_00020c68(local_16,local_18,local_1a,local_1c,(undefined2 *)0x56b7c);
      local_16 = local_16 + 3;
      local_18 = local_18 + 3;
      local_1a = local_1a + -3;
      local_1c = local_1c + -3;
    }
    if ((int)((uint)param_1[0x16] * 0x40000000) < 0) {
      FUN_000213c4((int)param_1);
      local_18 = (ushort)param_1[0x2c] + local_18 + 1;
      if ((int)((uint)param_1[8] * 0x2000000) < 0) {
        param_1[8] = param_1[8] & 0xbf;
        return;
      }
    }
    FUN_0001e294(local_16,local_18,local_1a,local_1c,*(undefined2 *)(param_1 + 0xc));
    bVar1 = *param_1;
    for (local_e = 0; local_e < bVar1; local_e = local_e + 1) {
      pbVar2 = (byte *)(*(int *)(param_1 + 4) + (uint)local_e * 0x20);
      if ((((*pbVar2 & 1) == 0) && ((int)((uint)*pbVar2 * 0x40000000) < 0)) &&
         ((int)((uint)*pbVar2 * 0x10000000) < 0)) {
        *pbVar2 = *pbVar2 | 0x60;
      }
    }
  }
  else {
    FUN_0001e294(*(short *)(param_1 + 0xe),*(short *)(param_1 + 0xe),*(short *)(param_1 + 0x12),
                 *(short *)(param_1 + 0x14),*(undefined2 *)(_DAT_20000ca0 + 0x46));
  }
  return;
}

