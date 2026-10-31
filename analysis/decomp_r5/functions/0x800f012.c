// rea decompile_all
// name: FUN_0800f012
// address: 0x800f012
// body: available
// range: 0x800f012-0x800f135 inclusive
// range: 0x800f248-0x800f50f inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0800f012(void)

{
  uint uVar1;
  uint uVar2;
  
  _DAT_200002e8 =
       (undefined2)
       ((ulonglong)
        (((uint)DAT_2000036f << 0x18 | (uint)DAT_20000370 << 0x10 | (uint)DAT_20000371 << 8 |
         (uint)DAT_20000372) * 5) / ((ulonglong)CONCAT11(DAT_2000036d,DAT_2000036e) << 2));
  if (_DAT_20000412 == 0) {
    _DAT_200002fc = 0;
    _DAT_20000412 = 1;
    _DAT_20000414 = 0;
  }
  else {
    uVar2 = (uint)CONCAT11(DAT_2000035a,DAT_2000035b);
    if ((((5000 < uVar2) && (uVar2 < 0x2706)) && (DAT_20000388 == '\0')) &&
       (_DAT_20000414 = (uint)DAT_200002bf * (10000 - uVar2) + _DAT_20000414, 299999 < _DAT_20000414
       )) {
      _DAT_200002fc = _DAT_200002fc + 1;
      _DAT_20000414 = _DAT_20000414 - 300000;
    }
  }
  if ((DAT_20000297 == '\0') && (0x68 < DAT_20000365)) {
    DAT_20000297 = '\x02';
  }
  else if ((DAT_20000297 != '\0') && (DAT_20000365 < 0x67)) {
    DAT_20000297 = '\0';
  }
  DAT_200002ea = 0;
  if ((DAT_2000037e == '\x03') || (DAT_2000037c == '\x03')) {
    DAT_200002ea = 1;
  }
  if ((DAT_2000037f == '\x03') || (DAT_2000037d == '\x03')) {
    DAT_200002ea = DAT_200002ea | 2;
  }
  if ((((DAT_20000378 == '\x03') || (DAT_2000037a == '\x03')) || (DAT_20000385 == '\x03')) ||
     (DAT_20000386 == '\x03')) {
    DAT_200002ea = DAT_200002ea | 4;
  }
  if ((DAT_20000381 == '\x03') || (DAT_20000380 == '\x03')) {
    DAT_200002ea = DAT_200002ea | 8;
  }
  if (DAT_20000297 != '\0') {
    DAT_200002ea = DAT_200002ea | 0x10;
  }
  if (DAT_20000064 == '\0') {
    DAT_200002ea = DAT_200002ea | 0x80;
  }
  if (DAT_20000306 != '\0') {
    DAT_200002ea = DAT_200002ea | 0x40;
  }
  if (4 < _DAT_200002da) {
    _DAT_200002f4 = (ushort)(((uint)DAT_2000029d * 0x11f) / (uint)_DAT_200002da);
  }
  if (0x63f < _DAT_200002f4) {
    _DAT_200002f4 = 0x640;
  }
  if (4 < _DAT_200002e4) {
    _DAT_2000030e = (ushort)(((uint)DAT_2000029d * 0x11f) / (uint)_DAT_200002e4);
  }
  if (0x63f < _DAT_2000030e) {
    _DAT_2000030e = 0x640;
  }
  _DAT_20000310 = _DAT_200002f4;
  if (_DAT_200002f0 < _DAT_200002f4) {
    _DAT_200002f0 = _DAT_200002f4;
  }
  _DAT_200002f2 = (undefined2)((uint)_DAT_200002f0 * 0xa000 >> 0x10);
  _DAT_20000408 = _DAT_200002f4;
  uVar2 = (uint)_DAT_20000410;
  _DAT_20000410 = _DAT_20000410 + 1;
  *(ushort *)(uVar2 * 2 + 0x2000138e) = _DAT_200002f4;
  if (_DAT_20000410 == 10) {
    _DAT_20000410 = 0;
  }
  uVar1 = 0;
  for (uVar2 = 0; uVar2 < 10; uVar2 = uVar2 + 1 & 0xff) {
    uVar1 = uVar1 + (int)*(short *)(uVar2 * 2 + 0x2000138e);
  }
  _DAT_200002ec = (ushort)(uVar1 / 10);
  if (_DAT_200002ec < 2) {
    _DAT_200002ec = 0;
  }
  _DAT_200002ee = (short)((uint)_DAT_200002ec * 0xa000 >> 0x10);
  if (DAT_20000308 == '\0') {
    DAT_2000029a = DAT_2000029a & 0xef;
  }
  else {
    DAT_2000029a = DAT_2000029a | 0x10;
  }
  if (DAT_20000309 == '\0') {
    DAT_2000029b = DAT_2000029b & 0xef;
  }
  else {
    DAT_2000029b = DAT_2000029b | 0x10;
  }
  DAT_200002fe = DAT_20000301 | DAT_20000300 << 1 | DAT_20000388 << 2 | DAT_2000030a << 4 |
                 DAT_20000303 << 5 | DAT_2000004c << 6 | DAT_20000313 << 7;
  if ((DAT_20000306 == '\0') && (DAT_20000307 == '\0')) {
    DAT_200002ff = DAT_200002d2 & 0x7f;
  }
  else {
    DAT_200002ff = DAT_200002d2 | 0x80;
  }
  if (DAT_2000030c == '\0') {
    DAT_200002ff = DAT_200002ff & 0xbf;
  }
  else {
    DAT_200002ff = DAT_200002ff | 0x40;
  }
  if (DAT_2000030a == '\0') {
    DAT_200002ff = DAT_200002ff & 0xef;
  }
  else {
    DAT_200002ff = DAT_200002ff | 0x10;
  }
  if (DAT_20000313 == '\0') {
    DAT_200002ff = DAT_200002ff & 0xf7;
  }
  else {
    DAT_200002ff = DAT_200002ff | 8;
  }
  if ((((DAT_200002d2 & 4) == 4) && (DAT_20000304 != '\x01')) && (DAT_20000303 != '\0')) {
    DAT_20000303 = 1;
  }
  else {
    DAT_20000303 = 0;
  }
  if (DAT_20000299 == '\x05') {
    DAT_20000299 = '\x04';
  }
  return;
}

