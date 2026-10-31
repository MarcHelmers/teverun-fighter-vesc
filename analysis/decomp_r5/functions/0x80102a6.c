// rea decompile_all
// name: FUN_080102a6
// address: 0x80102a6
// body: available
// range: 0x80102a6-0x80103db inclusive
// range: 0x8010458-0x80104c5 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_080102a6(void)

{
  byte bVar1;
  uint uVar2;
  
  if (DAT_20000301 == '\0') {
    uVar2 = (uint)DAT_20000299;
  }
  else {
    uVar2 = 0;
  }
  DAT_20001369 = DAT_200002a3;
  DAT_2000136a = DAT_200002af;
  DAT_2000136c = DAT_200002b6;
  if (uVar2 != 5) {
    DAT_20001369 = (&DAT_2000029f)[uVar2];
    DAT_2000136a = (&DAT_200002ab)[uVar2];
    DAT_2000136c = (&DAT_200002b2)[uVar2];
  }
  bVar1 = DAT_2000029b;
  if ((DAT_20000302 & 1) != 0) {
    DAT_20000302 = DAT_20000302 & 0xfe;
    bVar1 = DAT_2000029b | 1;
    DAT_2000029b = DAT_2000029b & 0xfe;
  }
  if (((DAT_2000029b & 0x80) == 0) && ((DAT_200002df & 8) == 0)) {
    bVar1 = bVar1 | 0x80;
  }
  if (DAT_2000030b == '\x02') {
    bVar1 = bVar1 | 0x80;
    DAT_2000136b = DAT_200002c2;
  }
  else {
    DAT_2000136b = DAT_200002b1;
    if (DAT_2000030b == '\x01') {
      bVar1 = bVar1 | 0x80;
    }
  }
  if ((0x6b < DAT_20000365) && (0xf < DAT_2000136c)) {
    DAT_2000136c = 0xf;
  }
  if (DAT_20000305 == '\0') {
    DAT_20001365 = bVar1 & 0xdf;
  }
  else {
    DAT_20001365 = bVar1 | 0x20;
  }
  if (DAT_20000388 == '\x01') {
    DAT_2000136b = '\0';
    DAT_2000136c = 0;
    DAT_20001365 = DAT_20001365 & 0x7f;
  }
  if (DAT_200002c5 == '\0') {
    DAT_2000136f = 0;
  }
  else {
    DAT_2000136f = 0x80;
  }
  if ((DAT_2000030c != '\0') && (DAT_2000136f = DAT_2000136f | 0x20, 0x16 < DAT_2000136a)) {
    DAT_2000136a = 0x16;
  }
  if (DAT_200003ff == '\x01') {
    DAT_2000136b = DAT_2000136b + '\x01';
    DAT_2000136a = DAT_2000136a + 1;
  }
  DAT_20001360 = 0x4a;
  DAT_20001361 = 0x11;
  DAT_20001362 = 0x3a;
  DAT_20001363 = 0;
  DAT_20001364 = (undefined1)uVar2;
  DAT_20001366 = DAT_2000029c;
  DAT_20001367 = 0x5f;
  DAT_20001368 = DAT_2000029e;
  DAT_2000136d = DAT_200002be;
  DAT_2000136e = DAT_200002bf;
  DAT_20001373 = FUN_0800f9f8(0x20001360,0x13);
  FUN_0800b990((undefined1 *)0x200010c8,&DAT_20001360,0x10);
  DAT_200010d8 = DAT_20001373;
  DAT_20001190 = 0x11;
  return;
}

