// rea decompile_all
// name: FUN_0002a6fc
// address: 0x2a6fc
// body: available
// range: 0x2a6fc-0x2a7a7 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined1 FUN_0002a6fc(int param_1)

{
  char cVar1;
  undefined1 local_26;
  undefined1 local_25;
  undefined1 auStack_24 [4];
  byte local_20;
  byte abStack_1f [11];
  int local_14;
  byte local_e;
  undefined1 local_d;
  int local_c;
  
  local_26 = 0x93;
  local_25 = 0x70;
  local_20 = 0;
  for (local_e = 0; local_e < 4; local_e = local_e + 1) {
    auStack_24[local_e] = *(undefined1 *)(param_1 + (uint)local_e);
    local_20 = local_20 ^ *(byte *)(param_1 + (uint)local_e);
  }
  local_c = param_1;
  FUN_0002c12c((int)&local_26,7,abStack_1f);
  FUN_0002bd00(8,8);
  cVar1 = FUN_0002bf1c(0xc,(int)&local_26,9,(int)&local_26,&local_14);
  if ((cVar1 == '\0') && (local_14 == 0x18)) {
    local_d = 0;
  }
  else {
    local_d = 0xfe;
  }
  return local_d;
}

