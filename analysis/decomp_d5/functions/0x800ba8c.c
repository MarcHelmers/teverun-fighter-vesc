// rea decompile_all
// name: FUN_0800ba8c
// address: 0x800ba8c
// body: available
// range: 0x800ba8c-0x800bad1 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0800ba8c(void)

{
  byte local_18 [12];
  
  local_18[0] = 0x41;
  local_18[1] = 0x54;
  local_18[2] = 0x2b;
  local_18[3] = 0x46;
  local_18[4] = 0x43;
  local_18[5] = 0x3d;
  local_18[6] = 0x31;
  local_18[7] = 0xd;
  local_18[8] = 10;
  local_18[9] = 0;
  local_18[10] = 0;
  local_18[0xb] = 0;
  _DAT_200003f8 = _DAT_200003f8 + 1;
  if (((_DAT_200003f8 % 5 == 1) && (DAT_200003c1 == '\0')) &&
     (FUN_080199b6(local_18,9), 0x14 < _DAT_200003f8)) {
    DAT_200003c1 = '\x01';
  }
  return;
}

