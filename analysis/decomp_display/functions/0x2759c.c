// rea decompile_all
// name: FUN_0002759c
// address: 0x2759c
// body: available
// range: 0x2759c-0x2766d inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0002759c(byte param_1,byte param_2,uint param_3,int param_4)

{
  byte local_16;
  byte local_15;
  uint local_10;
  byte local_a;
  byte local_9;
  
  local_16 = param_1 >> 3;
  local_15 = 8 - (param_1 & 7);
  local_10 = param_3;
  local_a = param_2;
  local_9 = param_1;
  if (param_2 <= local_15) {
    local_15 = param_2;
  }
  while (FUN_00027490((byte *)(param_4 + (uint)local_16),(byte)local_10 & (char)(1 << local_15) - 1U
                      ,local_9,local_15), local_15 != local_a) {
    local_16 = local_16 - 1;
    local_9 = local_16 * '\b';
    local_10 = local_10 >> local_15;
    local_a = local_a - local_15;
    local_15 = local_a;
    if (8 < local_a) {
      local_15 = 8;
    }
  }
  return;
}

