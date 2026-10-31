// rea decompile_all
// name: FUN_00013004
// address: 0x13004
// body: available
// range: 0x13004-0x13089 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


uint FUN_00013004(int param_1,uint param_2)

{
  uint local_10;
  uint local_c;
  
  if ((((-1 < (int)(param_2 * 0x8000000)) || (local_c = 1, -1 < *(int *)(param_1 + 8) * 0x200)) &&
      ((-1 < (int)((param_2 >> 8) * 0x2000000) || (local_c = 1, -1 < *(int *)(param_1 + 8) * 0x400))
      )) && ((-1 < (int)(param_2 * 0x20000000) || (local_c = 1, -1 < *(int *)(param_1 + 8) * 0x4000)
             ))) {
    local_10 = 0;
    if ((int)(param_2 * 0x2000000) < 0) {
      local_10 = (*(uint *)(param_1 + 8) & 0xfffffff) >> 0x1b;
    }
    local_c = local_10;
  }
  return local_c;
}

