// rea decompile_all
// name: FUN_08016ce6
// address: 0x8016ce6
// body: available
// range: 0x8016ce6-0x8016d15 inclusive
// range: 0x8016d20-0x8016d3f inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_08016ce6(int param_1,ushort *param_2,int *param_3,undefined4 param_4)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  int local_30;
  undefined4 local_2c;
  int *piStack_28;
  undefined4 uStack_24;
  
  uVar3 = 0;
  uVar2 = 0;
  local_30 = param_1;
  local_2c = param_2;
  piStack_28 = param_3;
  uStack_24 = param_4;
  bVar1 = FUN_08016cac(0x2000187c,&local_30);
  if (!bVar1) {
    *param_2 = (ushort)(byte)local_2c;
    *param_3 = local_30;
    for (; uVar2 < ((uint)local_2c & 0xff); uVar2 = uVar2 + 1 & 0xff) {
      *(undefined1 *)(param_1 + uVar2) = *(undefined1 *)((int)&local_2c + uVar2 + 1);
    }
    uVar3 = 2;
  }
  return uVar3;
}

