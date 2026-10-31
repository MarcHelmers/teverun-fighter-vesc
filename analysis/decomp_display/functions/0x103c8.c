// rea decompile_all
// name: FUN_000103c8
// address: 0x103c8
// body: available
// range: 0x103c8-0x104f7 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_000103c8(int param_1,int param_2,ushort *param_3)

{
  uint uVar1;
  int local_20;
  
  uVar1 = FUN_000104f8(param_2);
  if (param_2 - 1U < 2) {
    *(uint *)(param_1 + 0x8c) = *(uint *)(param_1 + 0x8c) & ~(0xfff << ((uVar1 & 0x7f) << 1));
    *(uint *)(param_1 + 0x8c) = *(uint *)(param_1 + 0x8c) | (uint)*param_3 << ((uVar1 & 0x7f) << 1);
  }
  else if ((param_2 == 4) || (param_2 == 8)) {
    *(uint *)(param_1 + 0x90) = *(uint *)(param_1 + 0x90) & ~(0xfff << (uVar1 * 2 - 0x20 & 0xff));
    *(uint *)(param_1 + 0x90) =
         *(uint *)(param_1 + 0x90) | (uint)*param_3 << (uVar1 * 2 - 0x20 & 0xff);
  }
  *(uint *)(param_1 + 0x94) = *(uint *)(param_1 + 0x94) & ~(0xff << (uVar1 & 0xff));
  *(uint *)(param_1 + 0x94) = *(uint *)(param_1 + 0x94) | (uint)(byte)param_3[1] << (uVar1 & 0xff);
  *(uint *)(param_1 + 0x98) = *(uint *)(param_1 + 0x98) & ~(0xff << (uVar1 & 0xff));
  if (param_3[2] == 0) {
    local_20 = 0;
  }
  else {
    local_20 = param_3[2] - 1;
  }
  *(uint *)(param_1 + 0x98) = *(uint *)(param_1 + 0x98) | local_20 << (uVar1 & 0xff);
  *(uint *)(param_1 + 0x9c) = *(uint *)(param_1 + 0x9c) & ~(0xff << (uVar1 & 0xff));
  *(uint *)(param_1 + 0x9c) = *(uint *)(param_1 + 0x9c) | (uint)(byte)param_3[3] << (uVar1 & 0xff);
  return;
}

