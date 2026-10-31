// rea decompile_all
// name: FUN_0801beb8
// address: 0x801beb8
// body: available
// range: 0x801beb8-0x801bf7d inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0801beb8(int param_1)

{
  uint uVar1;
  
  if (DAT_200002bf == '0') {
    DAT_20000373 = 0xd;
  }
  else if (DAT_200002bf == '4') {
    DAT_20000373 = 0xe;
  }
  else if (DAT_200002bf == '<') {
    DAT_20000373 = 0x10;
  }
  else if (DAT_200002bf == 'H') {
    DAT_20000373 = 0x14;
  }
  else {
    DAT_20000373 = 0x14;
  }
  uVar1 = (param_1 * 100 + 600U) / (uint)DAT_20000373 & 0xffff;
  if (uVar1 < 0x1195) {
    if (uVar1 < 0x1069) {
      _DAT_20000048 = _DAT_20000044 + 600;
    }
    else {
      _DAT_20000048 = (short)(ushort)DAT_20000373 * 0x1068;
    }
  }
  else {
    _DAT_20000048 = _DAT_20000044 + 400;
  }
  DAT_20000356 = (undefined1)(_DAT_20000048 / 100 >> 8);
  DAT_20000357 = (undefined1)(_DAT_20000048 / 100);
  DAT_20000358 = DAT_20000356;
  DAT_20000359 = DAT_20000357;
  return;
}

