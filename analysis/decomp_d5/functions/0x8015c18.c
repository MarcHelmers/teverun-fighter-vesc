// rea decompile_all
// name: FUN_08015c18
// address: 0x8015c18
// body: available
// range: 0x8015c18-0x8015cbf inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08015c18(void)

{
  byte bVar1;
  uint auStack_34 [7];
  
  bVar1 = 0;
  FUN_0801ce64(auStack_34,(undefined4 *)&DAT_0801d4ac,0x1c);
  _DAT_2000043e = _DAT_2000043e + 1;
  _DAT_20000440 = _DAT_20000440 + 1;
  if (0x32 < _DAT_2000043e) {
    _DAT_2000043e = 0;
    for (; bVar1 < 0xe; bVar1 = bVar1 + 1) {
      FUN_0801165a((char)auStack_34[(_DAT_20000440 + 4) % 7]);
      FUN_08011660(auStack_34[(_DAT_20000440 + 4) % 7]);
      FUN_08011668(auStack_34[(_DAT_20000440 + 4) % 7]);
      FUN_08012b98();
    }
  }
  return;
}

