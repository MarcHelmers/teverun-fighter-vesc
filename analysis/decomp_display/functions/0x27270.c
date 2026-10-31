// rea decompile_all
// name: FUN_00027270
// address: 0x27270
// body: available
// range: 0x27270-0x2741f inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00027270(void)

{
  DAT_20000a54 = 0x4c;
  DAT_20000a55 = 0x13;
  DAT_20000a56 = 0x35;
  DAT_20000a57 = DAT_20000bb5;
  if (DAT_20000bb5 == '\x05') {
    DAT_20000a58 = DAT_20000bf1;
  }
  else if (DAT_20000bbc == 4) {
    DAT_20000a58 = 5;
  }
  else {
    DAT_20000a58 = DAT_20000bbc;
  }
  DAT_20000a59 = DAT_20000bae;
  if (DAT_20000ba4 == '\0') {
    DAT_20000bc4 = DAT_20000bc4 & 0xbf | 4;
  }
  else {
    DAT_20000bc4 = DAT_20000bc4 | 0x44;
  }
  DAT_20000a5a = DAT_20000bc4;
  DAT_20000a5b = DAT_20000bfa;
  DAT_20000a5c = DAT_20000c0d;
  DAT_20000a5d = DAT_20000bfb;
  DAT_20000a5e = (&DAT_20000c05)[DAT_20000bf1] | (&DAT_20000beb)[DAT_20000bf1] << 4;
  DAT_20000a5f = (&DAT_20000bff)[DAT_20000bf1];
  DAT_20000a60 = (&DAT_20000bf3)[DAT_20000bf1];
  DAT_20000a61 = DAT_20000bfd;
  DAT_20000a62 = (&DAT_20000be5)[DAT_20000bf1];
  DAT_20000a63 = (&DAT_20000bdf)[DAT_20000bf1];
  DAT_20000a64 = DAT_20000c0c;
  DAT_20000a65 = DAT_20000c0b;
  DAT_20000a66 = FUN_00026338(0x20000a54,0x12);
  DAT_20000b80 = 0x13;
  FUN_00025de8(&DAT_20000a54,0x13);
  return;
}

