// rea decompile_all
// name: FUN_00018c34
// address: 0x18c34
// body: available
// range: 0x18c34-0x18d81 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00018c34(char *param_1)

{
  ushort uVar1;
  char local_10;
  char local_c;
  
  uVar1 = _DAT_20000bc6;
  if (_DAT_20000bc6 < 1000) {
    if (((uint)_DAT_20000bc6 % 1000) / 100 == 0) {
      local_c = ' ';
    }
    else {
      local_c = (char)(((uint)_DAT_20000bc6 % 1000) / 100) + '0';
    }
    *param_1 = local_c;
    if (((uint)uVar1 % 100) / 10 == 0) {
      local_10 = '0';
    }
    else {
      local_10 = (char)(((uint)uVar1 % 100) / 10) + '0';
    }
    param_1[1] = local_10;
    param_1[2] = '.';
    param_1[3] = (char)uVar1 + (char)(uVar1 / 10) * -10 | 0x30;
    param_1[4] = 'V';
    param_1[5] = '\0';
  }
  else {
    builtin_strncpy(param_1,"99.9V",6);
  }
  return;
}

