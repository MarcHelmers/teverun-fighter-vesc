// rea decompile_all
// name: FUN_0001e3e4
// address: 0x1e3e4
// body: available
// range: 0x1e3e4-0x1e60f inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0001e3e4(short param_1,short param_2,short param_3,short param_4,short param_5,
                 undefined2 param_6)

{
  short sVar1;
  undefined2 local_1a;
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_10;
  undefined2 local_e;
  undefined2 local_c;
  undefined2 local_a;
  
  local_e = param_3;
  local_a = param_1;
  if (param_3 < param_1) {
    local_e = param_1;
    local_a = param_3;
  }
  local_10 = param_4;
  local_c = param_2;
  if (param_4 < param_2) {
    local_10 = param_2;
    local_c = param_4;
  }
  if (0 < param_5) {
    local_1a = param_5 * -2 + 3;
    local_16 = 0;
    local_18 = param_5;
    FUN_0001e294(local_a + param_5,local_c,local_e - param_5,local_10,param_6);
    for (; local_16 <= local_18; local_16 = local_16 + 1) {
      if (0 < local_18) {
        sVar1 = (local_e + local_16) - param_5;
        FUN_0001e610(sVar1,(local_c - local_18) + param_5,sVar1,(local_18 + local_10) - param_5,
                     param_6);
        sVar1 = (local_a - local_16) + param_5;
        FUN_0001e610(sVar1,(local_c - local_18) + param_5,sVar1,(local_18 + local_10) - param_5,
                     param_6);
      }
      if (0 < local_16) {
        sVar1 = (local_a - local_18) + param_5;
        FUN_0001e610(sVar1,(local_c - local_16) + param_5,sVar1,(local_16 + local_10) - param_5,
                     param_6);
        sVar1 = (local_e + local_18) - param_5;
        FUN_0001e610(sVar1,(local_c - local_16) + param_5,sVar1,(local_16 + local_10) - param_5,
                     param_6);
      }
      if ((uint)(int)local_1a < 0x80000000) {
        local_1a = local_1a + (local_16 - local_18) * 4 + 10;
        local_18 = local_18 + -1;
      }
      else {
        local_1a = local_1a + local_16 * 4 + 6;
      }
    }
  }
  return;
}

