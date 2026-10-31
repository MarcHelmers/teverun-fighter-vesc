// rea decompile_all
// name: FUN_000217b0
// address: 0x217b0
// body: available
// range: 0x217b0-0x2188d inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_000217b0(short param_1,short param_2,int *param_3,short param_4)

{
  undefined2 *local_20;
  short local_16;
  short local_14;
  short local_c;
  short local_a;
  
  if ((*param_3 != 0) && ((char)param_3[2] == '\x10')) {
    local_20 = (undefined2 *)*param_3;
    local_c = param_2;
    for (local_16 = 0; (int)local_16 < (int)(uint)*(ushort *)((int)param_3 + 6);
        local_16 = local_16 + 1) {
      local_a = param_1;
      for (local_14 = 0; (int)local_14 < (int)(uint)*(ushort *)(param_3 + 1);
          local_14 = local_14 + 1) {
        if (local_14 < param_4) {
          FUN_0001ee24(local_a,local_c,*local_20);
        }
        else {
          FUN_0001ee24(local_a,local_c,0);
        }
        local_a = local_a + 1;
        local_20 = local_20 + 1;
      }
      local_c = local_c + 1;
    }
  }
  return;
}

