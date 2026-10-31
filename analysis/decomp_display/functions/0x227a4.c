// rea decompile_all
// name: FUN_000227a4
// address: 0x227a4
// body: available
// range: 0x227a4-0x2283f inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int FUN_000227a4(int param_1,short *param_2)

{
  char local_1;
  
  if ((param_1 == 0) || (-1 < (int)((uint)*(byte *)(param_1 + 8) * 0x40000000))) {
    local_1 = -1;
  }
  else {
    *param_2 = *(short *)(param_1 + 0xe);
    param_2[1] = *(short *)(param_1 + 0x10);
    param_2[2] = *(short *)(param_1 + 0x12);
    param_2[3] = *(short *)(param_1 + 0x14);
    if ((*(byte *)(param_1 + 0x16) & 1) != 0) {
      *param_2 = *param_2 + 3;
      param_2[1] = param_2[1] + 3;
      param_2[2] = param_2[2] + -3;
      param_2[3] = param_2[3] + -3;
    }
    if ((int)((uint)*(byte *)(param_1 + 0x16) * 0x40000000) < 0) {
      param_2[1] = (ushort)*(byte *)(param_1 + 0x2c) + param_2[1] + 1;
    }
    local_1 = '\0';
  }
  return (int)local_1;
}

