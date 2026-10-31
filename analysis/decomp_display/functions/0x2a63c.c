// rea decompile_all
// name: FUN_0002a63c
// address: 0x2a63c
// body: available
// range: 0x2a63c-0x2a6f9 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


char FUN_0002a63c(int param_1)

{
  byte local_26 [4];
  byte abStack_22 [14];
  int iStack_14;
  byte local_f;
  byte local_e;
  char local_d;
  int local_c;
  
  local_f = 0;
  local_c = param_1;
  FUN_0002bd00(8,8);
  FUN_0002bd34(0xd,0);
  FUN_0002bd00(0xe,0x80);
  local_26[0] = 0x93;
  local_26[1] = 0x20;
  local_d = FUN_0002bf1c(0xc,(int)local_26,2,(int)local_26,&iStack_14);
  if (local_d == '\0') {
    for (local_e = 0; local_e < 4; local_e = local_e + 1) {
      *(byte *)(local_c + (uint)local_e) = local_26[local_e];
      local_f = local_f ^ local_26[local_e];
    }
    if (local_f != local_26[local_e]) {
      local_d = -2;
    }
  }
  FUN_0002bee8(0xe,0x80);
  return local_d;
}

