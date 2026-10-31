// rea decompile_all
// name: FUN_0002a868
// address: 0x2a868
// body: available
// range: 0x2a868-0x2a957 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


char FUN_0002a868(undefined1 param_1,int param_2)

{
  char cVar1;
  byte local_2b [16];
  byte abStack_1b [2];
  byte local_19;
  int local_18;
  char local_11;
  int local_10;
  undefined1 local_9;
  
  local_2b[0] = 0xa0;
  local_2b[1] = param_1;
  local_10 = param_2;
  local_9 = param_1;
  FUN_0002c12c((int)local_2b,2,local_2b + 2);
  cVar1 = FUN_0002bf1c(0xc,(int)local_2b,4,(int)local_2b,&local_18);
  if (((cVar1 != '\0') || (local_18 != 4)) || (local_11 = '\0', (local_2b[0] & 0xf) != 10)) {
    local_11 = -2;
  }
  if (local_11 == '\0') {
    for (local_19 = 0; local_19 < 0x10; local_19 = local_19 + 1) {
      local_2b[local_19] = *(byte *)(local_10 + (uint)local_19);
    }
    FUN_0002c12c((int)local_2b,0x10,abStack_1b);
    cVar1 = FUN_0002bf1c(0xc,(int)local_2b,0x12,(int)local_2b,&local_18);
    if (((cVar1 != '\0') || (local_18 != 4)) || (local_11 = '\0', (local_2b[0] & 0xf) != 10)) {
      local_11 = -2;
    }
  }
  return local_11;
}

