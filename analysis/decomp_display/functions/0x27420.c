// rea decompile_all
// name: FUN_00027420
// address: 0x27420
// body: available
// range: 0x27420-0x2748d inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00027420(void)

{
  DAT_20000a54 = 0xa5;
  DAT_20000a55 = 8;
  DAT_20000a56 = 1;
  DAT_20000a57 = DAT_20000c77;
  DAT_20000a58 = DAT_20000c7d;
  DAT_20000a59 = DAT_20000c7e;
  DAT_20000a5a = DAT_20000c7b;
  DAT_20000a5b = FUN_00026338(0x20000a54,7);
  DAT_20000b80 = 8;
  FUN_00025de8(&DAT_20000a54,8);
  return;
}

