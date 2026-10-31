// rea decompile_all
// name: FUN_080105de
// address: 0x80105de
// body: available
// range: 0x80105de-0x8010773 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_080105de(void)

{
  uint uVar1;
  
  if (DAT_20000301 == '\0') {
    uVar1 = (uint)DAT_20000299;
  }
  else {
    uVar1 = 0;
  }
  DAT_2000130e = 0x35;
  DAT_2000130f = 0x27;
  DAT_20001310 = 0x3b;
  DAT_20001311 = DAT_200002de;
  DAT_20001312 = DAT_200002df;
  DAT_20001313 = (undefined1)((ushort)_DAT_200002e0 >> 8);
  DAT_20001314 = DAT_200002e0;
  DAT_20001315 = DAT_200002e2;
  DAT_20001316 = (undefined1)((ushort)_DAT_200002e4 >> 8);
  DAT_20001317 = DAT_200002e4;
  DAT_20001318 = DAT_200002e6;
  DAT_20001319 = (undefined1)uVar1;
  DAT_2000131a = DAT_2000029a & 0xfe;
  if (DAT_20000365 < 0x29) {
    DAT_2000131b = '\0';
  }
  else {
    DAT_2000131b = DAT_20000365 - 0x28;
  }
  DAT_2000131c = DAT_2000035c;
  DAT_2000131d = DAT_20000356;
  DAT_2000131e = DAT_20000357;
  DAT_2000131f = (undefined1)((ushort)_DAT_200002e8 >> 8);
  DAT_20001320 = DAT_200002e8;
  DAT_20001321 = DAT_200002ea & 0x5f;
  DAT_20001322 = (undefined1)((ushort)_DAT_200002ec >> 8);
  DAT_20001323 = (undefined1)_DAT_200002ec;
  DAT_20001324 = (undefined1)((ushort)_DAT_200002f0 >> 8);
  DAT_20001325 = (undefined1)_DAT_200002f0;
  DAT_20001326 = (undefined1)((ushort)_DAT_200002f6 >> 8);
  DAT_20001327 = DAT_200002f6;
  DAT_20001328 = (undefined1)(_DAT_200002f8 / 10 >> 0x10);
  DAT_20001329 = (undefined1)(_DAT_200002f8 / 10 >> 8);
  DAT_2000132a = (undefined1)(_DAT_200002f8 / 10);
  DAT_2000132b = DAT_200002fe;
  DAT_2000132c = DAT_2000029d;
  DAT_2000132d = DAT_200002bf;
  DAT_2000132e = DAT_2000029c;
  DAT_2000132f = (undefined1)((int)(DAT_2000029e - 0x50) / 5);
  DAT_20001330 = (&DAT_200002a5)[uVar1];
  DAT_20001331 = (&DAT_200002ab)[uVar1];
  DAT_20001332 = DAT_200002b1;
  DAT_20001333 = (&DAT_200002b8)[uVar1];
  DAT_20001334 = FUN_0800f8f2(0x2000130e,0x26);
  FUN_0800b990((undefined1 *)0x20001244,&DAT_2000130e,0x27);
  DAT_2000130c = 0x27;
  return;
}

