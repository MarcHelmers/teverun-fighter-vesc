// rea decompile_all
// name: FUN_0001380c
// address: 0x1380c
// body: available
// range: 0x1380c-0x1385b inclusive
// range: 0x13882-0x13965 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0001380c(void)

{
  DAT_20000c0d = DAT_20000bdb;
  DAT_20000c0b = DAT_20000bd9;
  DAT_20000bfe = DAT_20000c25;
  switch(DAT_20000bd9) {
  case 0x24:
    DAT_20000bda = 0;
    break;
  default:
    DAT_20000bda = 3;
    break;
  case 0x30:
    DAT_20000bda = 1;
    break;
  case 0x34:
    DAT_20000bda = 2;
    break;
  case 0x3c:
    DAT_20000bda = 3;
    break;
  case 0x48:
    DAT_20000bda = 4;
  }
  DAT_20000bfd = DAT_20000bd8;
  DAT_20000bfa = DAT_20000bd5;
  DAT_20000bde = DAT_20000bcd;
  DAT_20000bdd = DAT_20000bcc;
  DAT_20000bf9 = DAT_20000bd3;
  DAT_20000bfb = DAT_20000bd6;
  DAT_20000bfc = DAT_20000bd7;
  return;
}

