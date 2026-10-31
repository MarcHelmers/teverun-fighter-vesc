// rea decompile_all
// name: FUN_0001ee54
// address: 0x1ee54
// body: available
// range: 0x1ee54-0x1f04b inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001ee54(short param_1,short param_2,short param_3,undefined2 param_4)

{
  short local_1a;
  short local_18;
  short local_16;
  short local_14;
  short local_12;
  
  if ((((uint)(int)param_1 < 0x80000000) && ((uint)(int)param_2 < 0x80000000)) && (0 < param_3)) {
    local_16 = param_3 * -2 + 1;
    local_18 = 0;
    local_1a = 0;
    local_14 = 0;
    local_12 = param_3;
    while (local_14 <= local_12) {
      (*(code *)*_DAT_20000ca0)
                ((int)(short)(param_1 - local_12),(int)(short)(param_2 + local_14),param_4);
      (*(code *)*_DAT_20000ca0)
                ((int)(short)(param_1 - local_12),(int)(short)(param_2 - local_14),param_4);
      (*(code *)*_DAT_20000ca0)
                ((int)(short)(param_1 + local_12),(int)(short)(param_2 + local_14),param_4);
      (*(code *)*_DAT_20000ca0)
                ((int)(short)(param_1 + local_12),(int)(short)(param_2 - local_14),param_4);
      (*(code *)*_DAT_20000ca0)
                ((int)(short)(param_1 - local_14),(int)(short)(param_2 + local_12),param_4);
      (*(code *)*_DAT_20000ca0)
                ((int)(short)(param_1 - local_14),(int)(short)(param_2 - local_12),param_4);
      (*(code *)*_DAT_20000ca0)
                ((int)(short)(param_1 + local_14),(int)(short)(param_2 + local_12),param_4);
      (*(code *)*_DAT_20000ca0)
                ((int)(short)(param_1 + local_14),(int)(short)(param_2 - local_12),param_4);
      local_14 = local_14 + 1;
      local_1a = local_1a + local_18;
      local_18 = local_18 + 2;
      if (0 < (int)local_16 + local_1a * 2) {
        local_12 = local_12 + -1;
        local_1a = local_1a + local_16;
        local_16 = local_16 + 2;
      }
    }
  }
  return;
}

