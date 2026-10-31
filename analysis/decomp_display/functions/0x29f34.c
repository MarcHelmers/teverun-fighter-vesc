// rea decompile_all
// name: FUN_00029f34
// address: 0x29f34
// body: available
// range: 0x29f34-0x29f9b inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00029f34(int param_1,ushort param_2,undefined1 *param_3)

{
  uint local_41c;
  undefined1 auStack_414 [1024];
  undefined1 *local_14;
  ushort local_e;
  int local_c;
  
  local_14 = param_3;
  local_e = param_2;
  local_c = param_1;
  FUN_0002d5b2(auStack_414,0x400);
  if ((local_e & 3) == 0) {
    local_41c = (uint)(local_e >> 2);
  }
  else {
    local_41c = (local_e >> 2) + 1;
  }
  FUN_00010a68(local_c,(int)auStack_414,local_41c);
  FUN_000276a4(local_14,auStack_414,local_e);
  return;
}

