// rea decompile_all
// name: FUN_0801bd94
// address: 0x801bd94
// body: available
// range: 0x801bd94-0x801be6f inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0801bd94(void)

{
  if (DAT_20000309 == '\0') {
    _DAT_2000066c = 0;
    if (DAT_200002dc < 0x65) {
      if (DAT_200002dc < 0x3d) {
        DAT_20000668 = (byte)(((uint)DAT_200002dc << 1) / 3);
      }
      else {
        DAT_20000668 = (char)((int)(uint)DAT_200002dc >> 1) + 10;
      }
    }
    else {
      DAT_20000668 = 0x3d;
    }
  }
  else {
    _DAT_2000066c = _DAT_2000066c + 1;
    if ((300 < _DAT_2000066c) && (_DAT_2000066c = 0, DAT_20000668 != 0x19)) {
      if (DAT_20000668 < 0x1a) {
        DAT_20000668 = DAT_20000668 + 1;
      }
      else {
        DAT_20000668 = DAT_20000668 - 1;
      }
    }
  }
  DAT_20000365 = DAT_20000668 + 0x29;
  DAT_20000366 = DAT_20000668 + 0x28;
  DAT_2000035e = DAT_20000366;
  DAT_2000035f = DAT_20000365;
  DAT_20000360 = (char)(((uint)DAT_20000365 + (uint)DAT_20000366) * 0x800000 >> 0x18);
  DAT_20000361 = DAT_20000668 + 0x2e;
  DAT_20000362 = DAT_20000668 + 0x2f;
  DAT_20000363 = 0x42;
  DAT_20000364 = 0x42;
  return;
}

