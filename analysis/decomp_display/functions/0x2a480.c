// rea decompile_all
// name: FUN_0002a480
// address: 0x2a480
// body: available
// range: 0x2a480-0x2a4f1 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002a480(void)

{
  _DAT_20000148 = _DAT_20001720 & 0xff;
  _DAT_2000014c = _DAT_20001720 >> 8 & 0xff;
  _DAT_20000150 = (_DAT_20001720 & 0xfff) >> 4;
  _DAT_20000154 = (_DAT_20001720 & 0x7ff) >> 3;
  _DAT_20000158 = (_DAT_20001720 & 0x3ff) >> 2;
  _DAT_2000015c = (_DAT_20001720 & 0x1ff) >> 1;
  _DAT_20000160 = _DAT_20001720 >> 0x10 & 0xff;
  _DAT_20000164 = (_DAT_20001720 & 0x3ffff) >> 10;
  _DAT_20000168 = (_DAT_20001720 & 0x7ffff) >> 0xb;
  _DAT_2000016c = (_DAT_20001720 & 0xfffff) >> 0xc;
  _DAT_20000170 = (_DAT_20001720 & 0x1fffff) >> 0xd;
  _DAT_20000174 = _DAT_20001720 >> 0x18;
  _DAT_20000178 = (_DAT_20001720 & 0x7fffff) >> 0xf;
  _DAT_2000017c = (_DAT_20001720 & 0x7fff) >> 7;
  return;
}

