// rea decompile_all
// name: FUN_0001c4a8
// address: 0x1c4a8
// body: available
// range: 0x1c4a8-0x1c54f inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined1 FUN_0001c4a8(void)

{
  undefined1 local_1;
  
  if ((((DAT_20000185 == DAT_20000181) && (DAT_20000186 == DAT_20000182)) &&
      (DAT_20000187 == DAT_20000183)) && (DAT_20000188 == DAT_20000184)) {
    local_1 = 1;
    DAT_2000058c = DAT_20000185;
    DAT_2000058d = DAT_20000186;
    DAT_2000058e = DAT_20000187;
    DAT_2000058f = DAT_20000188;
  }
  else {
    local_1 = 0;
  }
  DAT_2000018a = 0;
  DAT_20000189 = 0;
  DAT_20000181 = 0x30;
  DAT_20000182 = 0x30;
  DAT_20000183 = 0x30;
  DAT_20000184 = 0x30;
  DAT_20000185 = 0x30;
  DAT_20000186 = 0x30;
  DAT_20000187 = 0x30;
  DAT_20000188 = 0x30;
  return local_1;
}

