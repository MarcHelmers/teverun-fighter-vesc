// rea decompile_all
// name: FUN_0801c814
// address: 0x801c814
// body: available
// range: 0x801c814-0x801c885 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0801c814(void)

{
  if (DAT_20002629 == '\x03') {
    DAT_2000030b = 2;
    DAT_200002c1 = DAT_20002636;
    DAT_200002c2 = DAT_20002637;
    DAT_200002c0 = DAT_20002638;
  }
  else if (DAT_20002629 == '\x02') {
    DAT_2000030b = 3;
  }
  else if (DAT_20002629 == '\0') {
    DAT_2000030b = 0;
  }
  else {
    DAT_2000030b = 1;
  }
  if ((DAT_20002639 == '\0') || (DAT_20002629 != '\x03')) {
    DAT_20000313 = 0;
  }
  else {
    DAT_20000313 = 1;
  }
  DAT_20000312 = DAT_20002629;
  return;
}

