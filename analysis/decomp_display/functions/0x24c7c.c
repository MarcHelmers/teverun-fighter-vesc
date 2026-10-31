// rea decompile_all
// name: FUN_00024c7c
// address: 0x24c7c
// body: available
// range: 0x24c7c-0x24d45 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int FUN_00024c7c(byte *param_1,undefined4 *param_2,byte param_3,undefined2 param_4,
                undefined2 param_5,undefined2 param_6,undefined2 param_7)

{
  byte *pbVar1;
  char local_11;
  
  pbVar1 = FUN_0002079c(param_1);
  if (pbVar1 == (byte *)0x0) {
    local_11 = -1;
  }
  else {
    *param_2 = 0;
    *(undefined1 *)(param_2 + 1) = 1;
    pbVar1[4] = 0x49;
    pbVar1[5] = 0x4d;
    pbVar1[6] = 3;
    pbVar1[7] = 0;
    pbVar1[1] = 0;
    pbVar1[0x18] = 3;
    pbVar1[0x1a] = 0;
    *(undefined2 *)(pbVar1 + 0x10) = param_4;
    *(undefined2 *)(pbVar1 + 0x12) = param_5;
    *(undefined2 *)(pbVar1 + 0x14) = param_6;
    *(undefined2 *)(pbVar1 + 0x16) = param_7;
    pbVar1[8] = 0xff;
    pbVar1[9] = 0xff;
    pbVar1[10] = 0xff;
    pbVar1[0xb] = 0xff;
    pbVar1[0xc] = 0xff;
    pbVar1[0xd] = 0xff;
    pbVar1[0xe] = 0xff;
    pbVar1[0xf] = 0xff;
    pbVar1[0x19] = param_3;
    *pbVar1 = *pbVar1 | 0x4a;
    *(undefined4 **)(pbVar1 + 0x1c) = param_2;
    *pbVar1 = *pbVar1 & 0xfe;
    local_11 = '\0';
  }
  return (int)local_11;
}

