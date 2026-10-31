// rea decompile_all
// name: FUN_000271b8
// address: 0x271b8
// body: available
// range: 0x271b8-0x2726d inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_000271b8(void)

{
  DAT_20000a54 = 0xa5;
  DAT_20000a55 = 0x13;
  DAT_20000a56 = 0xa5;
  DAT_20000a57 = DAT_20000596;
  DAT_20000a58 = DAT_20000597;
  DAT_20000a59 = DAT_20000598;
  DAT_20000a5a = DAT_20000599;
  DAT_20000a5b = DAT_2000059a;
  DAT_20000a5c = DAT_2000059b;
  DAT_20000a5d = DAT_2000059c;
  DAT_20000a5e = DAT_2000059d;
  DAT_20000a5f = DAT_2000059e;
  DAT_20000a60 = DAT_20000c77;
  DAT_20000a61 = DAT_20000c7d;
  DAT_20000a62 = DAT_20000c7e;
  DAT_20000a63 = DAT_20000c7b;
  DAT_20000a64 = DAT_20000bc9;
  DAT_20000a65 = 0x55;
  DAT_20000b80 = 0x13;
  DAT_20000a66 = FUN_00026338(0x20000a54,0x12);
  FUN_00025de8(&DAT_20000a54,(uint)DAT_20000b80);
  return;
}

