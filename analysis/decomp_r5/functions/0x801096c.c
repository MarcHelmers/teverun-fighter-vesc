// rea decompile_all
// name: FUN_0801096c
// address: 0x801096c
// body: available
// range: 0x801096c-0x8010bcd inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0801096c(void)

{
  uint uVar1;
  byte bVar2;
  
  if (DAT_20000301 == '\0') {
    uVar1 = (uint)DAT_20000299;
  }
  else {
    uVar1 = 0;
  }
  if ((DAT_2000029b & 0x80) == 0) {
    bVar2 = 0;
  }
  else {
    bVar2 = 8;
  }
  if ((DAT_200002dd & 0x80) == 0x80) {
    bVar2 = DAT_200002d4 & 0xf7 | 0x80;
  }
  else {
    bVar2 = DAT_200002d4 & 0x77 | bVar2;
  }
  if ((DAT_200002dd & 0x20) == 0x20) {
    bVar2 = bVar2 | 4;
  }
  else {
    bVar2 = bVar2 & 0xfb;
  }
  DAT_20001332 = DAT_2000029b & 0xfe;
  DAT_20001326 = 0x35;
  DAT_20001327 = 0x27;
  DAT_20001328 = 0x3a;
  DAT_20001329 = DAT_200002d3;
  if ((_DAT_20000034 < 0x1f5) || (DAT_20000325 == DAT_20000419)) {
    DAT_2000132a = bVar2 & 0xdf;
  }
  else {
    DAT_2000132a = bVar2 | 0x20;
  }
  if ((_DAT_20000036 < 0x1f5) || (DAT_20000325 == DAT_20000419)) {
    DAT_2000132a = DAT_2000132a & 0xbf;
  }
  else {
    DAT_2000132a = DAT_2000132a | 0x40;
  }
  if (_DAT_20000032 < 0x1f5) {
    DAT_2000132a = DAT_2000132a & 0xef;
  }
  else {
    DAT_2000132a = DAT_2000132a | 0x10;
  }
  if (DAT_20000305 == '\0') {
    DAT_2000132a = DAT_2000132a & 0xfd;
  }
  else {
    DAT_2000132a = DAT_2000132a | 2;
  }
  DAT_2000132b = (undefined1)((ushort)_DAT_200002d6 >> 8);
  DAT_2000132c = DAT_200002d6;
  DAT_2000132d = DAT_200002d8;
  DAT_2000132e = (undefined1)((ushort)_DAT_200002da >> 8);
  DAT_2000132f = DAT_200002da;
  DAT_20001330 = DAT_200002dc;
  DAT_20001331 = (undefined1)uVar1;
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
  DAT_20001348 = (&DAT_2000029f)[uVar1];
  DAT_20001349 = (&DAT_200002ab)[uVar1];
  DAT_2000134a = DAT_200002b1;
  DAT_2000134b = (&DAT_200002b2)[uVar1];
  DAT_2000134c = FUN_0800f9f8(0x20001326,0x26);
  FUN_0800b990((undefined1 *)0x2000125c,&DAT_20001326,0x27);
  DAT_20001324 = 0x27;
  return;
}

