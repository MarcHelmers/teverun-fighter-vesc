// rea decompile_all
// name: FUN_0801cf44
// address: 0x801cf44
// body: available
// range: 0x801cf44-0x801cff3 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0801cf44(void)

{
  uint in_fpscr;
  
  DAT_20002640 = DAT_2000030a;
  _DAT_20002644 = _DAT_2000030e;
  _DAT_20002642 = _DAT_20000310;
  if (DAT_2000030a == '\0') {
    _DAT_20002648 = 0.0;
  }
  else {
    _DAT_20002648 =
         (float)VectorSignedToFloat((uint)_DAT_20000310 - (uint)_DAT_2000030e,
                                    (byte)(in_fpscr >> 0x16) & 3);
    _DAT_20002648 = _DAT_20002648 / 10.0;
  }
  DAT_20002655 = (DAT_2000029b & 0x80) == 0x80;
  DAT_20002656 = (DAT_2000029a & 0x80) == 0x80;
  DAT_20002657 = (DAT_200002df & 8) == 8;
  _DAT_2000264c = _DAT_200002d6;
  DAT_20002654 = (&DAT_200002b2)[DAT_20000299];
  return;
}

