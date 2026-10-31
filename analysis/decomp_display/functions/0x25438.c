// rea decompile_all
// name: FUN_00025438
// address: 0x25438
// body: available
// range: 0x25438-0x25561 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00025438(void)

{
  DAT_20000119 = DAT_20000560;
  if ((_DAT_200000e4 < 0x60e) || (0x6d6 < _DAT_200000e4)) {
    DAT_2000012d = 1;
  }
  else {
    DAT_2000012d = 0;
  }
  if ((_DAT_200000e4 < 0x834) || (0x8fc < _DAT_200000e4)) {
    DAT_200000f1 = 1;
  }
  else {
    DAT_200000f1 = 0;
  }
  DAT_20000105 = 100 < _DAT_200000e4;
  DAT_2000012c = DAT_20000128;
  DAT_200000f0 = DAT_200000ec;
  DAT_20000104 = DAT_20000100;
  DAT_20000118 = DAT_20000114;
  return;
}

