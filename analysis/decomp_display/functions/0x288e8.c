// rea decompile_all
// name: FUN_000288e8
// address: 0x288e8
// body: available
// range: 0x288e8-0x289a9 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_000288e8(void)

{
  DAT_200005f8 = DAT_200005ac;
  DAT_200005f9 = DAT_2000057b;
  DAT_200005fa = DAT_20000579;
  DAT_200005fb = DAT_20000590;
  DAT_200005fc = DAT_20000c25;
  DAT_200005fd = DAT_20000bdb;
  DAT_200005fe = DAT_20000bd9;
  DAT_200005ff = DAT_20000bd8;
  DAT_20000600 = DAT_20000bd5;
  DAT_20000601 = DAT_20000bcc;
  DAT_20000602 = DAT_20000bd3;
  DAT_20000603 = DAT_20000bd6;
  DAT_20000604 = DAT_20000bd7;
  DAT_20000605 = DAT_20000bf2;
  FUN_00028b88();
  FUN_00027fc0(1);
  return;
}

