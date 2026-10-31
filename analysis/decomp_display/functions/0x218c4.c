// rea decompile_all
// name: FUN_000218c4
// address: 0x218c4
// body: available
// range: 0x218c4-0x219ef inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_000218c4(byte *param_1,int param_2,byte param_3,undefined4 param_4)

{
  undefined1 *puVar1;
  int iVar2;
  byte local_1d;
  char local_9;
  
  if (((param_1 == (byte *)0x0) || (param_2 == 0)) || (param_3 == 0)) {
    local_9 = -1;
  }
  else {
    for (local_1d = 0; local_1d < param_3; local_1d = local_1d + 1) {
      puVar1 = (undefined1 *)(param_2 + (uint)local_1d * 0x20);
      *puVar1 = 3;
      *(undefined4 *)(puVar1 + 0x1c) = 0;
    }
    *param_1 = param_3;
    *(int *)(param_1 + 4) = param_2;
    param_1[8] = 2;
    param_1[10] = 0x7d;
    param_1[0xb] = 0xef;
    param_1[0xc] = 0;
    param_1[0xd] = 0;
    param_1[0xe] = 0;
    param_1[0xf] = 0;
    param_1[0x10] = 0;
    param_1[0x11] = 0;
    iVar2 = FUN_00020444();
    *(short *)(param_1 + 0x12) = (short)iVar2 + -1;
    iVar2 = FUN_00020454();
    *(short *)(param_1 + 0x14) = (short)iVar2 + -1;
    *(undefined4 *)(param_1 + 0x30) = param_4;
    param_1[0x16] = 0;
    param_1[0x18] = 0;
    param_1[0x19] = 0;
    param_1[0x1a] = 0;
    param_1[0x1b] = 0;
    if (_DAT_20000ca0 == 0) {
      param_1[0x1c] = 0;
      param_1[0x1d] = 0;
      param_1[0x1e] = 0;
      param_1[0x1f] = 0;
    }
    else {
      *(int *)(param_1 + 0x1c) = _DAT_20000ca0 + 0x2c;
    }
    param_1[0x20] = 2;
    param_1[0x21] = 2;
    param_1[0x22] = 0x11;
    param_1[0x24] = 0xff;
    param_1[0x25] = 0xff;
    param_1[0x26] = 0x1f;
    param_1[0x27] = 0;
    param_1[0x28] = 0xff;
    param_1[0x29] = 0xff;
    param_1[0x2a] = 0x10;
    param_1[0x2b] = 0x84;
    param_1[0x2c] = 0xf;
    local_9 = '\0';
  }
  return (int)local_9;
}

