// rea decompile_all
// name: FUN_080096f8
// address: 0x80096f8
// body: available
// range: 0x80096f8-0x800973f inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_080096f8(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_8;
  
  iVar2 = 0;
  local_8 = 0;
  uVar1 = 0;
  if ((_DAT_40021000 & 2) == 0) {
    _DAT_40021000 = _DAT_40021000 | 1;
    do {
      local_8 = local_8 + 1;
      if ((int)(_DAT_40021000 << 0x1e) < 0) break;
    } while (local_8 != 0x500);
    iVar2 = -((int)(_DAT_40021000 << 0x1e) >> 0x1f);
    if (iVar2 == 0) {
      uVar1 = 1;
    }
  }
  return CONCAT44(iVar2,uVar1);
}

