// rea decompile_all
// name: FUN_0002d3a8
// address: 0x2d3a8
// body: available
// range: 0x2d3a8-0x2d55b inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Removing unreachable block (ram,0x0002d4e2) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002d3a8(void)

{
  if ((DAT_20000bbd != '\0') && (_DAT_20000564 = _DAT_20000564 + 1, 0xf < _DAT_20000564)) {
    DAT_20000bbd = '\0';
    DAT_20000bb5 = 0;
  }
  if (DAT_2000056e != '\0') {
    _DAT_20000566 = _DAT_20000566 + 1;
    if ((_DAT_20000566 < 0x19) && (DAT_2000056f != DAT_2000056e)) {
      DAT_2000056f = DAT_2000056e;
      _DAT_20000566 = 0;
    }
    if (0x18 < _DAT_20000566) {
      DAT_2000056e = '\0';
      _DAT_20000566 = 0;
    }
  }
  if (DAT_20000bf2 == 0) {
    DAT_20000bc4 = DAT_20000bc4 & 0x7f;
  }
  else if ((_DAT_20000c0e == 0) && (DAT_20000c18 == '\0')) {
    _DAT_20000568 = _DAT_20000568 + 1;
    if ((uint)DAT_20000bf2 * 100 <= _DAT_20000568) {
      DAT_20000bc4 = DAT_20000bc4 | 0x80;
    }
  }
  else {
    _DAT_20000568 = 0;
  }
  if ((DAT_20000bb4 != '\0') && (_DAT_2000056c = _DAT_2000056c + 1, 0x13 < _DAT_2000056c)) {
    DAT_20000bb4 = '\0';
    _DAT_2000056c = 0;
  }
  return;
}

