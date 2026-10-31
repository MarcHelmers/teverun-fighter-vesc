// rea decompile_all
// name: FUN_080088b4
// address: 0x80088b4
// body: available
// range: 0x80088b4-0x800891d inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_080088b4(int param_1,ushort *param_2)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  
  *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfffffffe;
  uVar3 = *(uint *)(param_1 + 4);
  uVar1 = *param_2;
  uVar2 = *(uint *)(param_1 + 0x20) & 0xfffffffd | (uint)param_2[4] | (uint)param_2[1];
  if ((param_1 == 0x40012c00) || (param_1 == 0x40013400)) {
    uVar2 = (uVar2 & 0xfffffff7 | (uint)param_2[5]) & 0xfffffffb | (uint)param_2[2];
    uVar3 = uVar3 & 0xfffffcff | (uint)param_2[6] | (uint)param_2[7];
  }
  *(uint *)(param_1 + 4) = uVar3;
  *(ushort *)(param_1 + 0x18) = *(ushort *)(param_1 + 0x18) & 0xff8c | uVar1;
  *(ushort *)(param_1 + 0x34) = param_2[3];
  *(uint *)(param_1 + 0x20) = uVar2;
  return;
}

