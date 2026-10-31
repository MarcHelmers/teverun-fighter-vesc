// rea decompile_all
// name: FUN_00012a74
// address: 0x12a74
// body: available
// range: 0x12a74-0x12c81 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00012a74(int param_1,uint *param_2)

{
  uint uVar1;
  
  if (param_1 == 0x40042000) {
    _DAT_40000008 = _DAT_40000008 | 0x40;
  }
  else if (param_1 == 0x40042800) {
    _DAT_40000008 = _DAT_40000008 | 0x80;
  }
  else if (param_1 == 0x40043000) {
    _DAT_40000008 = _DAT_40000008 | 0x100;
  }
  else if (param_1 == 0x40043800) {
    _DAT_40000008 = _DAT_40000008 | 0x200;
  }
  FUN_00012c84(param_1);
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xfffc000;
  uVar1 = _DAT_20000044 / *param_2 - 1;
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | uVar1 >> 4 | uVar1 * 0x10000000;
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xff03ffff;
  *(uint *)(param_1 + 4) =
       *(uint *)(param_1 + 4) |
       (uint)(byte)param_2[1] << 0x12 | (uint)*(byte *)((int)param_2 + 5) << 0x13 |
       (uint)*(byte *)((int)param_2 + 6) << 0x16;
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xffff;
  *(uint *)(param_1 + 0xc) =
       *(uint *)(param_1 + 0xc) |
       (uint)*(byte *)((int)param_2 + 7) << 0x10 | (uint)*(byte *)((int)param_2 + 9) << 0x18;
  *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) & 0xfffff000;
  *(uint *)(param_1 + 0x1c) =
       (uint)*(byte *)((int)param_2 + 0xb) | *(uint *)(param_1 + 0x1c) | 0x1000;
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xffffbfeb;
  *(uint *)(param_1 + 4) =
       *(uint *)(param_1 + 4) |
       (uint)(byte)param_2[2] << 4 | (uint)*(byte *)((int)param_2 + 10) << 2 |
       (uint)(byte)param_2[3] << 0xe;
  if (param_1 == 0x40042000) {
    if (((char)param_2[2] == '\0' && *(char *)((int)param_2 + 10) == '\0') &&
        (char)param_2[3] == '\0') {
      FUN_00012cc8('\0');
    }
    else {
      FUN_00012c98('\0');
    }
  }
  else if (param_1 == 0x40042800) {
    if (((char)param_2[2] == '\0' && *(char *)((int)param_2 + 10) == '\0') &&
        (char)param_2[3] == '\0') {
      FUN_00012cc8('\x01');
    }
    else {
      FUN_00012c98('\x01');
    }
  }
  else if (param_1 == 0x40043000) {
    if (((char)param_2[2] == '\0' && *(char *)((int)param_2 + 10) == '\0') &&
        (char)param_2[3] == '\0') {
      FUN_00012cc8('\b');
    }
    else {
      FUN_00012c98('\b');
    }
  }
  else if (param_1 == 0x40043800) {
    if (((char)param_2[2] == '\0' && *(char *)((int)param_2 + 10) == '\0') &&
        (char)param_2[3] == '\0') {
      FUN_00012cc8('\x15');
    }
    else {
      FUN_00012c98('\x15');
    }
  }
  return;
}

