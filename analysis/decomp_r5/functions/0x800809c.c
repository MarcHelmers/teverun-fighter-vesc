// rea decompile_all
// name: FUN_0800809c
// address: 0x800809c
// body: available
// range: 0x800809c-0x80081c9 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0800809c(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = (_DAT_40021024 & 0x7f) >> 4;
  if ((_DAT_40021004 & 0x8000000) == 0) {
    iVar3 = ((_DAT_40021004 & 0x83c0000) >> 0x12) + 2;
  }
  else {
    iVar3 = ((_DAT_40021004 & 0x83c0000) >> 0x12) - 0x1ef;
  }
  if ((_DAT_40021004 & 0x10000) == 0) {
    if ((_DAT_40021040 & 1) == 0) {
      uVar2 = iVar3 * 16000000;
    }
    else {
      uVar2 = iVar3 * 8000000;
    }
  }
  else if ((_DAT_40021004 & 0x20000) == 0) {
    uVar2 = iVar3 * 8000000;
  }
  else {
    uVar2 = iVar3 * 4000000;
  }
  if ((_DAT_40021040 & 2) != 0) {
    uVar2 = uVar2 >> 1;
  }
  uVar1 = _DAT_40021004 & 0xc;
  if (uVar1 == 0) {
    *param_1 = *(uint *)(&DAT_0801d674 + uVar4 * 4);
  }
  else if (uVar1 == 4) {
    *param_1 = 16000000;
  }
  else if (uVar1 == 8) {
    *param_1 = 8000000;
  }
  else if (uVar1 == 0xc) {
    *param_1 = uVar2;
  }
  else {
    *param_1 = *(uint *)(&DAT_0801d674 + uVar4 * 4);
  }
  param_1[1] = *param_1 >> (&DAT_0801d634)[(_DAT_40021004 & 0xf0) >> 4];
  param_1[2] = param_1[1] >> (&DAT_0801d634)[(_DAT_40021004 & 0x700) >> 8];
  param_1[3] = param_1[1] >> (&DAT_0801d634)[(_DAT_40021004 & 0x3800) >> 0xb];
  param_1[5] = param_1[1] / (uint)(byte)(&DAT_0801d644)[_DAT_4002102c & 0xf];
  param_1[4] = uVar2 / *(ushort *)(&DAT_0801d654 + ((_DAT_4002102c & 0x1f0) >> 4 & 0xf) * 2);
  return;
}

