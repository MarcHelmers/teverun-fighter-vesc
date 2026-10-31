// rea decompile_all
// name: FUN_0001e0e4
// address: 0x1e0e4
// body: available
// range: 0x1e0e4-0x1e1d1 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_0001e0e4(undefined4 *param_1,undefined4 param_2,undefined2 param_3,undefined2 param_4)

{
  byte local_d;
  
  *param_1 = param_2;
  *(undefined2 *)(param_1 + 1) = param_3;
  *(undefined2 *)((int)param_1 + 6) = param_4;
  *(undefined2 *)(param_1 + 8) = 4;
  *(undefined2 *)((int)param_1 + 0x22) = 4;
  *(ushort *)(param_1 + 9) = ~*(ushort *)(param_1 + 8) + *(short *)(param_1 + 1);
  *(ushort *)((int)param_1 + 0x26) = ~*(ushort *)(param_1 + 8) + *(short *)((int)param_1 + 6);
  *(undefined2 *)(param_1 + 7) = *(undefined2 *)(param_1 + 9);
  *(undefined2 *)((int)param_1 + 0x1e) = *(undefined2 *)((int)param_1 + 0x26);
  *(undefined1 *)(param_1 + 0x10) = 1;
  *(undefined1 *)((int)param_1 + 0x41) = 1;
  param_1[0xb] = 0;
  *(undefined2 *)(param_1 + 0xd) = 0;
  *(undefined2 *)((int)param_1 + 0x32) = 0;
  *(undefined2 *)((int)param_1 + 0x36) = 0;
  *(undefined2 *)(param_1 + 0xe) = 0;
  param_1[0xf] = 0;
  *(undefined2 *)((int)param_1 + 0x46) = 0x5c5d;
  *(undefined2 *)((int)param_1 + 0x42) = 0xffff;
  *(undefined2 *)(param_1 + 0x11) = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  for (local_d = 0; local_d < 3; local_d = local_d + 1) {
    param_1[(uint)local_d * 2 + 0x13] = 0;
    *(undefined1 *)(param_1 + (uint)local_d * 2 + 0x14) = 0;
  }
  _DAT_20000ca0 = param_1;
  return 1;
}

