// rea decompile_all
// name: FUN_0001eb8c
// address: 0x1eb8c
// body: available
// range: 0x1eb8c-0x1ee21 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001eb8c(short param_1,short param_2,short param_3,byte param_4,undefined2 param_5)

{
  short local_1c;
  short local_1a;
  short local_18;
  short local_16;
  short local_14;
  
  if ((((uint)(int)param_1 < 0x80000000) && ((uint)(int)param_2 < 0x80000000)) && (0 < param_3)) {
    local_18 = param_3 * -2 + 1;
    local_1a = 0;
    local_1c = 0;
    local_16 = 0;
    local_14 = param_3;
    while (local_16 <= local_14) {
      if ((param_4 & 1) != 0) {
        (*(code *)*_DAT_20000ca0)
                  ((int)(short)(param_1 + local_14),(int)(short)(param_2 - local_16),param_5);
      }
      if ((int)((uint)param_4 * 0x40000000) < 0) {
        (*(code *)*_DAT_20000ca0)
                  ((int)(short)(param_1 + local_16),(int)(short)(param_2 - local_14),param_5);
      }
      if ((int)((uint)param_4 * 0x20000000) < 0) {
        (*(code *)*_DAT_20000ca0)
                  ((int)(short)(param_1 - local_16),(int)(short)(param_2 - local_14),param_5);
      }
      if ((int)((uint)param_4 * 0x10000000) < 0) {
        (*(code *)*_DAT_20000ca0)
                  ((int)(short)(param_1 - local_14),(int)(short)(param_2 - local_16),param_5);
      }
      if ((int)((uint)param_4 * 0x8000000) < 0) {
        (*(code *)*_DAT_20000ca0)
                  ((int)(short)(param_1 - local_14),(int)(short)(param_2 + local_16),param_5);
      }
      if ((int)((uint)param_4 * 0x4000000) < 0) {
        (*(code *)*_DAT_20000ca0)
                  ((int)(short)(param_1 - local_16),(int)(short)(param_2 + local_14),param_5);
      }
      if ((int)((uint)param_4 * 0x2000000) < 0) {
        (*(code *)*_DAT_20000ca0)
                  ((int)(short)(param_1 + local_16),(int)(short)(param_2 + local_14),param_5);
      }
      if ((int)((uint)param_4 * 0x1000000) < 0) {
        (*(code *)*_DAT_20000ca0)
                  ((int)(short)(param_1 + local_14),(int)(short)(param_2 + local_16),param_5);
      }
      local_16 = local_16 + 1;
      local_1c = local_1c + local_1a;
      local_1a = local_1a + 2;
      if (0 < (int)local_18 + local_1c * 2) {
        local_14 = local_14 + -1;
        local_1c = local_1c + local_18;
        local_18 = local_18 + 2;
      }
    }
  }
  return;
}

