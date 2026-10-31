// rea decompile_all
// name: FUN_00020b0c
// address: 0x20b0c
// body: available
// range: 0x20b0c-0x20bbd inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00020b0c(byte *param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte *pbVar4;
  ushort local_e;
  
  bVar1 = *param_1;
  for (local_e = 0; local_e < bVar1; local_e = local_e + 1) {
    pbVar4 = (byte *)(*(int *)(param_1 + 4) + (uint)local_e * 0x20);
    bVar2 = *pbVar4;
    bVar3 = pbVar4[1];
    if (((bVar2 & 1) == 0) && ((int)((uint)bVar2 * 0x40000000) < 0)) {
      if ((int)((uint)bVar2 * 0x4000000) < 0) {
        (**(code **)(pbVar4 + 4))(param_1);
      }
      if ((((int)((uint)bVar2 * 0x10000000) < 0) && ((int)((uint)bVar2 * 0x1000000) < 0)) &&
         ((bVar3 & 0x41) != 0)) {
        (**(code **)(pbVar4 + 4))(param_1);
      }
    }
  }
  return;
}

