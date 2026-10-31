// rea decompile_all
// name: FUN_08016be6
// address: 0x8016be6
// body: available
// range: 0x8016be6-0x8016c5d inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_08016be6(int param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 local_8;
  undefined4 uStack_4;
  
  local_8 = param_3;
  uStack_4 = param_4;
  bVar1 = FUN_08016bc4(param_1);
  if (bVar1) {
    uVar3 = 2;
  }
  else if ((byte)local_8 < 9) {
    *(byte *)(param_1 + (uint)*(byte *)(param_1 + 0x141) * 0x10 + 4) = (byte)local_8;
    *(undefined4 *)(param_1 + (uint)*(byte *)(param_1 + 0x141) * 0x10) = param_2;
    for (uVar2 = 0; uVar2 < (local_8 & 0xff); uVar2 = uVar2 + 1 & 0xffff) {
      *(undefined1 *)(param_1 + (uint)*(byte *)(param_1 + 0x141) * 0x10 + 5 + uVar2) =
           *(undefined1 *)((int)&local_8 + uVar2 + 1);
    }
    uVar2 = *(byte *)(param_1 + 0x141) + 1;
    *(char *)(param_1 + 0x141) = (char)uVar2 + (char)(uVar2 / 0x14) * -0x14;
    uVar3 = 0;
  }
  else {
    uVar3 = 2;
  }
  return uVar3;
}

