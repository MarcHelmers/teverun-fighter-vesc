// rea decompile_all
// name: FUN_08016c3a
// address: 0x8016c3a
// body: available
// range: 0x8016c3a-0x8016c4f inclusive
// range: 0x8016c56-0x8016c95 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_08016c3a(int param_1,ushort *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar1 = 0;
  uVar2 = 0;
  switch(DAT_20001778) {
  case 0:
    uVar1 = 0;
    break;
  case 1:
    uVar1 = 1;
    break;
  case 2:
    uVar1 = 2;
    *param_2 = _DAT_200017f4;
    for (uVar2 = 0; uVar2 < _DAT_200017f4; uVar2 = uVar2 + 1 & 0xffff) {
      *(undefined1 *)(param_1 + uVar2) = *(undefined1 *)(uVar2 + 0x20001779);
    }
    DAT_20001778 = 3;
    break;
  case 3:
    uVar1 = 1;
    break;
  case 4:
    uVar1 = 1;
  }
  return CONCAT44(uVar2,uVar1);
}

