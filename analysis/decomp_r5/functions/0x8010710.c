// rea decompile_all
// name: FUN_08010710
// address: 0x8010710
// body: available
// range: 0x8010710-0x8010863 inclusive
// range: 0x8010928-0x801096b inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08010710(void)

{
  uint uVar1;
  
  if (DAT_20000301 == '\0') {
    uVar1 = (uint)DAT_20000299;
  }
  else {
    uVar1 = 0;
  }
  DAT_20001326 = 0x35;
  DAT_20001327 = 0x27;
  DAT_20001328 = 0x3b;
  DAT_20001329 = DAT_200002de;
  DAT_2000132a = DAT_200002df;
  DAT_2000132b = (undefined1)((ushort)_DAT_200002e0 >> 8);
  DAT_2000132c = DAT_200002e0;
  DAT_2000132d = DAT_200002e2;
  DAT_2000132e = (undefined1)((ushort)_DAT_200002e4 >> 8);
  DAT_2000132f = DAT_200002e4;
  DAT_20001330 = DAT_200002e6;
  DAT_20001331 = (undefined1)uVar1;
  DAT_20001332 = DAT_2000029a & 0xfe;
  if (DAT_20000365 < 0x29) {
    DAT_20001333 = '\0';
  }
  else {
    DAT_20001333 = DAT_20000365 - 0x28;
  }
  DAT_20001334 = DAT_2000035c;
  DAT_20001335 = DAT_20000356;
  DAT_20001336 = DAT_20000357;
  DAT_20001337 = (undefined1)((ushort)_DAT_200002e8 >> 8);
  DAT_20001338 = DAT_200002e8;
  DAT_20001339 = DAT_200002ea & 0x5f;
  DAT_2000133a = (undefined1)((ushort)_DAT_200002ec >> 8);
  DAT_2000133b = (undefined1)_DAT_200002ec;
  DAT_2000133c = (undefined1)((ushort)_DAT_200002f0 >> 8);
  DAT_2000133d = (undefined1)_DAT_200002f0;
  DAT_2000133e = (undefined1)((ushort)_DAT_200002f6 >> 8);
  DAT_2000133f = DAT_200002f6;
  DAT_20001340 = (undefined1)(_DAT_200002f8 / 10 >> 0x10);
  DAT_20001341 = (undefined1)(_DAT_200002f8 / 10 >> 8);
  DAT_20001342 = (undefined1)(_DAT_200002f8 / 10);
  DAT_20001343 = DAT_200002fe;
  DAT_20001344 = DAT_2000029d;
  DAT_20001345 = DAT_200002bf;
  DAT_20001346 = DAT_2000029c;
  DAT_20001347 = (undefined1)((int)(DAT_2000029e - 0x50) / 5);
  DAT_20001348 = (&DAT_200002a5)[uVar1];
  DAT_20001349 = (&DAT_200002ab)[uVar1];
  DAT_2000134a = DAT_200002b1;
  DAT_2000134b = (&DAT_200002b8)[uVar1];
  DAT_2000134c = FUN_0800f9f8(0x20001326,0x26);
  FUN_0800b990((undefined1 *)0x2000125c,&DAT_20001326,0x27);
  DAT_20001324 = 0x27;
  return;
}

