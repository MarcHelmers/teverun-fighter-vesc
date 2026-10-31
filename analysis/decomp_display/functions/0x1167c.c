// rea decompile_all
// name: FUN_0001167c
// address: 0x1167c
// body: available
// range: 0x1167c-0x11867 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001167c(uint *param_1,byte *param_2)

{
  uint uVar1;
  
  _DAT_40000008 = _DAT_40000008 | 0x1000;
  *param_1 = (uint)*param_2 | (uint)*(ushort *)(param_2 + 2) * 0x40 - 0x40 | 4;
  uVar1 = (uint)(param_2[0x16] != 0) * 2;
  if (param_2[0xc] != 0) {
    uVar1 = uVar1 + 1;
  }
  if (param_2[0xd] != 0) {
    uVar1 = uVar1 + 4;
  }
  if (param_2[0x17] != 0) {
    uVar1 = uVar1 + 8;
  }
  if (param_2[0xe] != 0) {
    uVar1 = uVar1 | 0x10;
  }
  if (param_2[0x18] != 0) {
    uVar1 = uVar1 | 0x20;
  }
  if (param_2[0xf] != 0) {
    uVar1 = uVar1 | 0x40;
  }
  if (param_2[0x19] != 0) {
    uVar1 = uVar1 | 0x80;
  }
  param_1[1] = uVar1;
  param_1[8] = *(ushort *)(param_2 + 4) - 1;
  param_1[9] = (uint)*(ushort *)(param_2 + 6);
  param_1[0xd] = (uint)*(ushort *)(param_2 + 8);
  param_1[0xb] = (uint)*(ushort *)(param_2 + 10);
  param_1[10] = (uint)*(ushort *)(param_2 + 0x10);
  param_1[0xe] = (uint)*(ushort *)(param_2 + 0x12);
  param_1[0xc] = (uint)*(ushort *)(param_2 + 0x14);
  _DAT_4004640c = 0x3f;
  param_1[0x1d] = 0x3f;
  uVar1 = (uint)(param_2[0x1b] != 0) * 2;
  if (param_2[0x1a] != 0) {
    uVar1 = uVar1 + 1;
  }
  if (param_2[0x1c] != 0) {
    uVar1 = uVar1 + 4;
  }
  if (param_2[0x1d] != 0) {
    uVar1 = uVar1 + 0x10;
  }
  if (param_2[0x1e] != 0) {
    uVar1 = uVar1 | 8;
  }
  if (param_2[0x1f] != 0) {
    uVar1 = uVar1 | 0x20;
  }
  param_1[0x1c] = uVar1;
  if ((((param_2[0x1a] != 0) || (param_2[0x1b] != 0)) || (param_2[0x1c] != 0)) ||
     (((param_2[0x1d] != 0 || (param_2[0x1e] != 0)) || (param_2[0x1f] != 0)))) {
    if (param_1 == (uint *)0x40046000) {
      FUN_00011868('\x06');
    }
    else if (param_1 == (uint *)0x40046080) {
      FUN_00011868('\t');
    }
    else if (param_1 == (uint *)0x40046100) {
      FUN_00011868('\r');
    }
    else if (param_1 == (uint *)0x40046180) {
      FUN_00011868('\x13');
    }
    else if (param_1 == (uint *)0x40046200) {
      FUN_00011868('\x1b');
    }
  }
  return;
}

