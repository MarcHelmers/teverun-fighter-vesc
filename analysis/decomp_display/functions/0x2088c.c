// rea decompile_all
// name: FUN_0002088c
// address: 0x2088c
// body: available
// range: 0x2088c-0x20909 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int FUN_0002088c(byte *param_1,byte param_2,byte param_3)

{
  byte *pbVar1;
  char local_9;
  
  pbVar1 = FUN_00020800(param_1,param_2,param_3);
  if (pbVar1 == (byte *)0x0) {
    local_9 = -1;
  }
  else if (((int)((uint)*pbVar1 * 0x10000000) < 0) || ((int)((uint)*pbVar1 * 0x4000000) < 0)) {
    local_9 = -1;
  }
  else {
    *pbVar1 = 3;
    pbVar1[0x1c] = 0;
    pbVar1[0x1d] = 0;
    pbVar1[0x1e] = 0;
    pbVar1[0x1f] = 0;
    pbVar1[0x1a] = 0;
    pbVar1[0x19] = 0;
    pbVar1[1] = 0;
    pbVar1[0x18] = 0;
    pbVar1[4] = 0;
    pbVar1[5] = 0;
    pbVar1[6] = 0;
    pbVar1[7] = 0;
    local_9 = '\0';
  }
  return (int)local_9;
}

