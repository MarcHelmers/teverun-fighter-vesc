// rea decompile_all
// name: FUN_000285ec
// address: 0x285ec
// body: available
// range: 0x285ec-0x28643 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_000285ec(void)

{
  DAT_200005f8 = 4;
  DAT_200005f9 = 10;
  DAT_200005fa = 0;
  DAT_200005fb = 1;
  DAT_200005fc = 0;
  DAT_200005fd = 0x6e;
  DAT_200005fe = 0x3c;
  DAT_200005ff = 100;
  DAT_20000600 = 0x1e;
  DAT_20000601 = 0;
  DAT_20000602 = 0;
  DAT_20000603 = 10;
  DAT_20000605 = 3;
  FUN_00028644('\x01');
  FUN_00027fc0(1);
  return;
}

