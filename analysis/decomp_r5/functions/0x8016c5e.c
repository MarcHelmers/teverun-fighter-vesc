// rea decompile_all
// name: FUN_08016c5e
// address: 0x8016c5e
// body: available
// range: 0x8016c5e-0x8016d73 inclusive
// range: 0x8016d76-0x8016d7d inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08016c5e(int param_1,uint param_2)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 local_24;
  uint3 local_20;
  undefined1 local_1d;
  undefined1 local_1c;
  undefined3 uStack_1b;
  
  uVar3 = 0;
  if ((DAT_20001814 != '\0') && (param_2 < 0x78)) {
    _DAT_20001890 = (ushort)param_2;
    if ((param_2 & 0xffff) == ((param_2 & 0xffff) / 7) * 7) {
      _DAT_2000188e = _DAT_20001890 / 7;
    }
    else {
      _DAT_2000188e = _DAT_20001890 / 7 + 1;
    }
    local_24 = CONCAT13((char)(param_2 >> 8),CONCAT12(DAT_2000188e,0x400));
    local_20 = (uint3)(_DAT_20001890 & 0xff);
    _local_20 = CONCAT13(0xaa,local_20);
    _local_1c = CONCAT31(uStack_1b,0x55);
    local_24 = CONCAT31(local_24._1_3_,8);
    FUN_08016be6(0x20001894,0x712,local_24,_local_20);
    for (uVar1 = 0; uVar1 < _DAT_2000188e; uVar1 = uVar1 + 1) {
      for (uVar2 = 0; uVar2 < 7; uVar2 = uVar2 + 1 & 0xffff) {
        if (uVar3 < _DAT_20001890) {
          *(undefined1 *)((int)&local_24 + uVar2 + 2) = *(undefined1 *)(param_1 + uVar3);
        }
        else {
          *(undefined1 *)((int)&local_24 + uVar2 + 2) = 0;
        }
        uVar3 = uVar3 + 1 & 0xffff;
      }
      local_24 = CONCAT31(CONCAT21(local_24._2_2_,(char)uVar1 + '\x10'),8);
      FUN_08016be6(0x20001894,0x712,local_24,_local_20);
    }
  }
  return;
}

