// rea decompile_all
// name: FUN_0800c582
// address: 0x800c582
// body: available
// range: 0x800c582-0x800c717 inclusive
// range: 0x800c7e8-0x800cbe3 inclusive
// range: 0x800cd8c-0x800d0ed inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0800c582(void)

{
  uint uVar1;
  byte bVar2;
  
  for (uVar1 = 0; uVar1 < 0x11; uVar1 = uVar1 + 1 & 0xff) {
    (&DAT_20000d40)[uVar1] = (&DAT_20000731)[uVar1];
    *(undefined1 *)(uVar1 + 0x20000d51) = (&DAT_200006f8)[uVar1];
  }
  DAT_20000d62 = DAT_20000011;
  DAT_20000d63 = DAT_20000012;
  DAT_20000d64 = DAT_20000013;
  DAT_20000d65 = DAT_2000000f;
  DAT_20000d66 = DAT_20000019;
  DAT_20000d67 = DAT_2000001a;
  DAT_20000d68 = DAT_2000001b;
  DAT_20000d69 = DAT_20000017;
  DAT_20000d6a = DAT_2000002c;
  DAT_20000d6b = DAT_2000002d;
  DAT_20000d6c = DAT_2000002e;
  DAT_20000d6d = DAT_2000002f;
  DAT_20000d6e = DAT_20000326;
  DAT_20000d6f = DAT_20000327;
  DAT_20000d70 = DAT_20000328;
  DAT_20000d71 = DAT_20000329;
  DAT_20000d72 = DAT_2000032a;
  DAT_20000d73 = DAT_2000032b;
  DAT_20000d74 = DAT_2000032c;
  DAT_20000d75 = DAT_2000032d;
  DAT_20000d76 = DAT_2000032e;
  DAT_20000d77 = DAT_2000032f;
  DAT_20000d78 = DAT_20000330;
  DAT_20000d79 = DAT_20000331;
  DAT_20000d7a = DAT_20000332;
  DAT_20000d7b = DAT_20000333;
  DAT_20000d7c = DAT_20000334;
  DAT_20000d7d = DAT_20000335;
  DAT_20000d7e = DAT_20000356;
  DAT_20000d7f = DAT_20000357;
  DAT_20000d80 = DAT_20000358;
  DAT_20000d81 = DAT_20000359;
  DAT_20000d82 = DAT_2000035a;
  DAT_20000d83 = DAT_2000035b;
  DAT_20000d84 = DAT_2000035c;
  DAT_20000d85 = DAT_2000035d;
  DAT_20000d86 = DAT_2000035e;
  DAT_20000d87 = DAT_2000035f;
  DAT_20000d88 = DAT_2000035f;
  DAT_20000d89 = DAT_20000361;
  DAT_20000d8a = DAT_20000362;
  DAT_20000d8b = DAT_20000363;
  DAT_20000d8c = DAT_20000364;
  DAT_20000d8d = DAT_20000365;
  DAT_20000d8e = DAT_20000366;
  DAT_20000d8f = DAT_20000367;
  DAT_20000d90 = DAT_20000368;
  DAT_20000d91 = DAT_20000369;
  DAT_20000d92 = DAT_2000036a;
  DAT_20000d93 = DAT_2000036b;
  DAT_20000d94 = DAT_2000036c;
  DAT_20000d95 = DAT_2000036d;
  DAT_20000d96 = DAT_2000036e;
  DAT_20000d97 = 0;
  DAT_20000d98 = 0;
  DAT_20000d99 = (undefined1)((ushort)_DAT_200002e8 >> 8);
  DAT_20000d9a = DAT_200002e8;
  DAT_20000d9b = DAT_20000373;
  DAT_20000d9c = DAT_20000374;
  DAT_20000d9d = DAT_20000375;
  DAT_20000d9e = DAT_20000376;
  DAT_20000d9f = DAT_20000377;
  DAT_20000da0 = DAT_20000297;
  if (DAT_20000378 == '\x03') {
    DAT_20000da0 = 3;
  }
  DAT_20000da1 = DAT_20000379;
  DAT_20000da2 = DAT_2000037a;
  DAT_20000da3 = DAT_2000037b;
  DAT_20000da4 = DAT_2000037c;
  DAT_20000da5 = DAT_2000037d;
  DAT_20000da6 = DAT_2000037e;
  DAT_20000da7 = DAT_2000037f;
  DAT_20000da8 = DAT_20000380;
  DAT_20000da9 = DAT_20000381;
  DAT_20000daa = DAT_20000382;
  DAT_20000dab = DAT_20000383;
  DAT_20000dac = DAT_20000384;
  DAT_20000dad = DAT_20000385;
  DAT_20000dae = DAT_20000386;
  DAT_20000daf = DAT_20000388;
  DAT_20000db0 = DAT_20000064 ^ 1;
  DAT_20000db1 = DAT_20000336;
  DAT_20000db2 = DAT_20000337;
  DAT_20000db3 = DAT_20000338;
  DAT_20000db4 = DAT_20000339;
  DAT_20000db5 = DAT_2000033a;
  DAT_20000db6 = DAT_2000033b;
  DAT_20000db7 = DAT_2000033c;
  DAT_20000db8 = DAT_2000033d;
  DAT_20000db9 = DAT_2000033e;
  DAT_20000dba = DAT_2000033f;
  DAT_20000dbb = DAT_20000340;
  DAT_20000dbc = DAT_20000341;
  DAT_20000dbd = DAT_20000342;
  DAT_20000dbe = DAT_20000343;
  DAT_20000dbf = DAT_20000344;
  DAT_20000dc0 = DAT_20000345;
  DAT_20000dc1 = DAT_20000346;
  DAT_20000dc2 = DAT_20000347;
  DAT_20000dc3 = DAT_20000348;
  DAT_20000dc4 = DAT_20000349;
  DAT_20000dc5 = DAT_2000034a;
  DAT_20000dc6 = DAT_2000034b;
  DAT_20000dc7 = DAT_2000034c;
  DAT_20000dc8 = DAT_2000034d;
  DAT_20000dc9 = DAT_2000034e;
  DAT_20000dca = DAT_2000034f;
  DAT_20000dcb = DAT_20000350;
  DAT_20000dcc = DAT_20000351;
  DAT_20000dcd = DAT_20000352;
  DAT_20000dce = DAT_20000353;
  DAT_20000dcf = DAT_20000354;
  DAT_20000dd0 = DAT_20000355;
  _DAT_20000dd8 = _DAT_20000186;
  _DAT_20000dd2 = _DAT_20000126;
  _DAT_20000dda = _DAT_2000019e;
  _DAT_20000dd4 = _DAT_2000013e;
  _DAT_20000ddc = _DAT_2000016e;
  _DAT_20000dd6 = _DAT_2000010e;
  _DAT_20000de0 = _DAT_200001c8;
  _DAT_20000dde = _DAT_200001f8;
  DAT_200003b5 = DAT_200000de;
  DAT_200003b6 = DAT_200000f6;
  DAT_200003b3 = DAT_200000ae;
  DAT_200003b4 = DAT_200000c6;
  DAT_200003b9 = DAT_20000276;
  DAT_200003ba = DAT_2000028e;
  DAT_200003b7 = DAT_20000246;
  DAT_200003b8 = DAT_2000025e;
  bVar2 = DAT_20000299;
  if (DAT_20000301 != '\0') {
    bVar2 = 0;
  }
  *(undefined1 *)((uint)DAT_20000299 * 0x10 + 0x20000cc2) = DAT_20000298;
  *(byte *)((uint)DAT_20000299 * 0x10 + 0x20000cc3) = bVar2;
  *(undefined1 *)((uint)DAT_20000299 * 0x10 + 0x20000cd0) = DAT_2000029a;
  *(byte *)((uint)DAT_20000299 * 0x10 + 0x20000cc4) = DAT_2000029b;
  *(undefined1 *)((uint)DAT_20000299 * 0x10 + 0x20000cc5) = DAT_2000029c;
  *(undefined1 *)((uint)DAT_20000299 * 0x10 + 0x20000cc6) = DAT_2000029d;
  *(undefined1 *)((uint)DAT_20000299 * 0x10 + 0x20000cc7) = DAT_2000029e;
  *(undefined1 *)((uint)DAT_20000299 * 0x10 + 0x20000cc8) = (&DAT_200002a5)[DAT_20000299];
  *(undefined1 *)((uint)DAT_20000299 * 0x10 + 0x20000cc9) = (&DAT_2000029f)[DAT_20000299];
  *(undefined1 *)((uint)DAT_20000299 * 0x10 + 0x20000cca) = (&DAT_200002ab)[DAT_20000299];
  *(undefined1 *)((uint)DAT_20000299 * 0x10 + 0x20000ccb) = DAT_200002b1;
  *(undefined1 *)((uint)DAT_20000299 * 0x10 + 0x20000ccd) = (&DAT_200002b2)[DAT_20000299];
  *(undefined1 *)((uint)DAT_20000299 * 0x10 + 0x20000ccc) = (&DAT_200002b8)[DAT_20000299];
  *(undefined1 *)((uint)DAT_20000299 * 0x10 + 0x20000cce) = DAT_200002be;
  *(undefined1 *)((uint)DAT_20000299 * 0x10 + 0x20000ccf) = DAT_200002bf;
  *(undefined1 *)((uint)DAT_20000299 * 0x10 + 0x20000cd1) = DAT_200002ff;
  DAT_20000d2a = DAT_200002d3;
  if ((DAT_2000029b & 0x80) == 0) {
    bVar2 = 0;
  }
  else {
    bVar2 = 8;
  }
  DAT_20000d2b = DAT_200002d4 & 0xf7 | bVar2;
  DAT_200003e0 = DAT_200003e0 + 1;
  uVar1 = ((int)(uint)DAT_200003e0 >> 2) + ((int)(uint)DAT_200003e0 >> 3) * -2 & 0xff;
  if ((500 < _DAT_20000034) && (uVar1 == 1)) {
    DAT_20000d2b = DAT_20000d2b | 0x20;
  }
  if ((500 < _DAT_20000036) && (uVar1 == 1)) {
    DAT_20000d2b = DAT_20000d2b | 0x40;
  }
  if (500 < _DAT_20000032) {
    DAT_20000d2b = DAT_20000d2b | 0x10;
  }
  if (DAT_200002c5 == '\0') {
    DAT_20000d2b = DAT_20000d2b & 0x7f;
  }
  else {
    DAT_20000d2b = DAT_20000d2b & 0xf7 | 0x80;
  }
  DAT_20000d2c = (char)((ushort)_DAT_200002d6 >> 8);
  DAT_20000d2d = (char)_DAT_200002d6;
  DAT_20000d2e = DAT_200002d8;
  DAT_20000d2f = (char)((ushort)_DAT_200002da >> 8);
  DAT_20000d30 = (char)_DAT_200002da;
  DAT_20000d31 = DAT_200002dc;
  DAT_20000d22 = DAT_200002de;
  DAT_20000d23 = DAT_200002d4 & 0xf7 | DAT_200002df & 8;
  if ((500 < _DAT_20000034) && (uVar1 == 1)) {
    DAT_20000d23 = DAT_20000d23 | 0x20;
  }
  if ((500 < _DAT_20000036) && (uVar1 == 1)) {
    DAT_20000d23 = DAT_20000d23 | 0x40;
  }
  if (500 < _DAT_20000032) {
    DAT_20000d23 = DAT_20000d23 | 0x10;
  }
  if (DAT_200002c5 == '\0') {
    DAT_20000d23 = DAT_20000d23 & 0x7f;
  }
  else {
    DAT_20000d23 = DAT_20000d23 & 0xf7 | 0x80;
  }
  DAT_20000d24 = (char)((ushort)_DAT_200002e0 >> 8);
  DAT_20000d25 = (char)_DAT_200002e0;
  DAT_20000d26 = DAT_200002e2;
  DAT_20000d27 = (char)((ushort)_DAT_200002e4 >> 8);
  DAT_20000d28 = (char)_DAT_200002e4;
  DAT_20000d29 = DAT_200002e6;
  DAT_20000d32 = (char)((ushort)_DAT_200002ec >> 8);
  DAT_20000d33 = (char)_DAT_200002ec;
  DAT_20000d34 = (char)((ushort)_DAT_200002f0 >> 8);
  DAT_20000d35 = (char)_DAT_200002f0;
  DAT_20000d36 = (char)((ushort)_DAT_200002f6 >> 8);
  DAT_20000d37 = DAT_200002f6;
  DAT_20000d38 = (char)(_DAT_200002f8 / 10 >> 0x10);
  DAT_20000d39 = (char)(_DAT_200002f8 / 10 >> 8);
  DAT_20000d3a = (char)(_DAT_200002f8 / 10);
  DAT_20000d3b = (char)((ushort)_DAT_200002fc >> 8);
  DAT_20000d3c = DAT_200002fc;
  DAT_20000d3d = DAT_200002c6;
  DAT_20000d3e = DAT_200002c7;
  DAT_20000d3f = DAT_200002c8;
  return;
}

