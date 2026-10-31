// rea decompile_all
// name: FUN_00026384
// address: 0x26384
// body: available
// range: 0x26384-0x27111 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00026384(void)

{
  if ((DAT_20000c26 & 1) == 0) {
    DAT_20000ba0 = 0;
    DAT_20000ba1 = 0;
  }
  else {
    DAT_20000ba1 = DAT_20000ba1 + 1;
    if (2 < DAT_20000ba1) {
      DAT_20000ba0 = 1;
    }
  }
  if ((DAT_20000c49 & 1) == 0) {
    DAT_20000b9f = 0;
    DAT_20000b9e = 0;
  }
  else {
    DAT_20000b9f = DAT_20000b9f + 1;
    if (2 < DAT_20000b9f) {
      DAT_20000b9e = 1;
    }
  }
  if ((int)((uint)DAT_20000c26 * 0x40000000) < 0) {
    DAT_20000b93 = DAT_20000b93 + 1;
    if (2 < DAT_20000b93) {
      DAT_20000b92 = 1;
    }
  }
  else {
    DAT_20000b93 = 0;
    DAT_20000b92 = 0;
  }
  if ((int)((uint)DAT_20000c49 * 0x40000000) < 0) {
    DAT_20000b91 = DAT_20000b91 + 1;
    if (2 < DAT_20000b91) {
      DAT_20000b90 = 1;
    }
  }
  else {
    DAT_20000b91 = 0;
    DAT_20000b90 = 0;
  }
  if (((DAT_20000c36 & 0x8f) == 0) && ((DAT_20000c59 & 0x8f) == 0)) {
    DAT_20000b9d = 0;
    DAT_20000b9c = 0;
  }
  else {
    DAT_20000b9d = DAT_20000b9d + 1;
    if (2 < DAT_20000b9d) {
      DAT_20000b9c = 1;
    }
  }
  DAT_20000b99 = DAT_20000c36;
  if (((int)((uint)DAT_20000c26 * 0x10000000) < 0) || ((int)((uint)DAT_20000c49 * 0x10000000) < 0))
  {
    DAT_20000ba6 = DAT_20000ba6 + 1;
    if (2 < DAT_20000ba6) {
      DAT_20000ba5 = 1;
    }
  }
  else {
    DAT_20000ba6 = 0;
    DAT_20000ba5 = 0;
  }
  if (((int)((uint)DAT_20000c26 * 0x8000000) < 0) || ((int)((uint)DAT_20000c49 * 0x8000000) < 0)) {
    DAT_20000ba3 = DAT_20000ba3 + 1;
    if (2 < DAT_20000ba3) {
      DAT_20000ba2 = 1;
    }
  }
  else {
    DAT_20000ba3 = 0;
    DAT_20000ba2 = 0;
  }
  if (((int)((uint)DAT_20000c26 * 0x2000000) < 0) || ((int)((uint)DAT_20000c2f * 0x8000000) < 0)) {
    DAT_20000b98 = DAT_20000b98 + 1;
    if (2 < DAT_20000b98) {
      DAT_20000b97 = 1;
    }
  }
  else {
    DAT_20000b98 = 0;
    DAT_20000b97 = 0;
  }
  if (((int)((uint)DAT_20000c49 * 0x2000000) < 0) || ((int)((uint)DAT_20000c52 * 0x8000000) < 0)) {
    DAT_20000b96 = DAT_20000b96 + 1;
    if (2 < DAT_20000b96) {
      DAT_20000b95 = 1;
    }
  }
  else {
    DAT_20000b96 = 0;
    DAT_20000b95 = 0;
  }
  if ((int)((uint)DAT_20000c26 * 0x4000000) < 0) {
    DAT_20000b8f = DAT_20000b8f + 1;
    if (2 < DAT_20000b8f) {
      DAT_20000b8e = 1;
    }
  }
  else {
    DAT_20000b8f = 0;
    DAT_20000b8e = 0;
  }
  if ((int)((uint)DAT_20000c49 * 0x4000000) < 0) {
    DAT_20000b8d = DAT_20000b8d + 1;
    if (2 < DAT_20000b8d) {
      DAT_20000b8c = 1;
    }
  }
  else {
    DAT_20000b8d = 0;
    DAT_20000b8c = 0;
  }
  if (((int)((uint)DAT_20000c26 * 0x1000000) < 0) || ((int)((uint)DAT_20000c49 * 0x1000000) < 0)) {
    DAT_20000b8b = DAT_20000b8b + 1;
    if (2 < DAT_20000b8b) {
      DAT_20000b8a = 1;
    }
  }
  else {
    DAT_20000b8b = 0;
    DAT_20000b8a = 0;
  }
  if (((int)((uint)DAT_20000c36 * 0x8000000) < 0) || ((int)((uint)DAT_20000c59 * 0x8000000) < 0)) {
    DAT_20000b89 = DAT_20000b89 + 1;
    if (2 < DAT_20000b89) {
      DAT_20000b88 = 1;
    }
  }
  else {
    DAT_20000b89 = 0;
    DAT_20000b88 = 0;
  }
  if (((int)((uint)DAT_20000c36 * 0x2000000) < 0) || ((int)((uint)DAT_20000c59 * 0x2000000) < 0)) {
    DAT_20000b9b = DAT_20000b9b + 1;
    if (2 < DAT_20000b9b) {
      DAT_20000b9a = 1;
    }
  }
  else {
    DAT_20000b9b = 0;
    DAT_20000b9a = 0;
  }
  if (((int)((uint)DAT_20000c26 * 0x20000000) < 0) || ((int)((uint)DAT_20000c49 * 0x20000000) < 0))
  {
    DAT_20000c18 = 1;
    DAT_20000bc4 = DAT_20000bc4 & 0x7f;
    DAT_20001724 = 1;
  }
  else {
    DAT_20000c18 = 0;
  }
  if (((int)((uint)DAT_20000c27 * 0x2000000) < 0) || ((int)((uint)DAT_20000c4a * 0x2000000) < 0)) {
    DAT_20000c20 = 1;
  }
  else {
    DAT_20000c20 = 0;
  }
  if (((int)((uint)DAT_20000c27 * 0x4000000) < 0) || ((int)((uint)DAT_20000c4a * 0x4000000) < 0)) {
    DAT_20000c23 = 1;
  }
  else {
    DAT_20000c23 = 0;
  }
  if (((int)((uint)DAT_20000c27 * 0x8000000) < 0) || ((int)((uint)DAT_20000c4a * 0x8000000) < 0)) {
    DAT_20000c16 = 1;
  }
  else {
    DAT_20000c16 = 0;
  }
  DAT_20000c1b = (int)((uint)DAT_20000c27 * 0x10000000) < 0;
  DAT_20000c1a = (int)((uint)DAT_20000c4a * 0x10000000) < 0;
  if (((DAT_20000c27 & 1) == 0) && ((DAT_20000c4a & 1) == 0)) {
    DAT_20000c1c = 0;
  }
  else {
    DAT_20000c1c = 1;
  }
  DAT_20000c1f = (int)((uint)DAT_20000c27 * 0x1000000) < 0;
  DAT_20000c21 = (int)((uint)DAT_20000c27 * 0x20000000) < 0;
  _DAT_20000b84 = CONCAT11(DAT_20000c28,DAT_20000c29);
  _DAT_20000b82 = CONCAT11(DAT_20000c4b,DAT_20000c4c);
  DAT_20000bb0 = DAT_20000c2a;
  DAT_20000baf = DAT_20000c4d;
  _DAT_20000c10 = CONCAT11(DAT_20000c2b,DAT_20000c2c);
  DAT_20000c6e = DAT_20000c2d;
  DAT_20000c6d = DAT_20000c50;
  DAT_20000bd2 = DAT_20000c2e;
  if (5 < DAT_20000c2e) {
    DAT_20000bd2 = 2;
  }
  DAT_20000bd0 = 0;
  DAT_20000bcf = 0;
  DAT_20000049 = DAT_20000c2e;
  if (5 < DAT_20000c2e) {
    DAT_20000049 = 0;
  }
  DAT_20000048 = DAT_20000c51;
  if (5 < DAT_20000c51) {
    DAT_20000048 = 0;
  }
  if (DAT_20000ba4 == '\0') {
    DAT_20000c6c = DAT_20000c30;
    DAT_20000bc5 = DAT_20000c31;
    _DAT_20000bc6 = CONCAT11(DAT_20000c32,DAT_20000c33);
    _DAT_20000b86 = CONCAT11(DAT_20000c34,DAT_20000c35);
  }
  if (_DAT_20000c10 < 5) {
    _DAT_20000c0e = 0x640;
  }
  else {
    _DAT_20000c0e = (undefined2)(((uint)DAT_20000bdb * 0x11f) / (uint)_DAT_20000c10);
    DAT_20000c22 = 1;
    _DAT_20000c14 = _DAT_20000c0e;
  }
  if (2999 < _DAT_20000c10) {
    _DAT_20000c0e = 0;
    DAT_20000c22 = 0;
  }
  _DAT_20000ba8 = CONCAT11(DAT_20000c37,DAT_20000c38);
  _DAT_20000bc0 = CONCAT11(DAT_20000c39,DAT_20000c3a);
  _DAT_200006c6 = CONCAT11(DAT_20000c3b,DAT_20000c3c);
  _DAT_20000570 = ((uint)DAT_20000c3d << 0x10 | (uint)DAT_20000c3e << 8) + (uint)DAT_20000c3f;
  if (0xd2 < _DAT_20000ba8) {
    _DAT_20000ba8 = 0xdc;
  }
  if (0xd2 < _DAT_20000bc0) {
    _DAT_20000bc0 = 0xdc;
  }
  _DAT_20000baa = (undefined2)((uint)_DAT_20000ba8 * 5 >> 3);
  _DAT_20000bc2 = (undefined2)((uint)_DAT_20000bc0 * 5 >> 3);
  _DAT_200006c8 = (undefined2)((uint)_DAT_200006c6 * 5 >> 3);
  _DAT_20000574 = (uint)(_DAT_20000570 * 5) >> 3;
  DAT_20000c24 = (int)((uint)DAT_20000c40 * 0x1000000) < 0;
  DAT_20000c17 = (int)((uint)DAT_20000c40 * 0x2000000) < 0;
  DAT_20000bd7 = (int)((uint)DAT_20000c40 * 0x8000000) < 0;
  DAT_20000c1d = (int)((uint)DAT_20000c40 * 0x4000000) < 0;
  if ((int)((uint)DAT_20000c40 * 0x10000000) < 0) {
    DAT_20000c19 = 2;
  }
  else {
    DAT_20000c19 = (int)((uint)DAT_20000c40 * 0x20000000) < 0;
  }
  DAT_20000c25 = (int)((uint)DAT_20000c40 * 0x40000000) < 0;
  DAT_20000c1e = (DAT_20000c40 & 1) != 0;
  if (DAT_20000bad != '\0') {
    DAT_20000bd3 = (int)((uint)DAT_20000c2f * 0x2000000) < 0;
    DAT_20000bd4 = 0;
    DAT_20000bcc = (int)((uint)DAT_20000c2f * 0x10000000) < 0;
    if ((int)((uint)DAT_20000c2f * 0x40000000) < 0) {
      DAT_20000bcd = 1;
    }
    else if ((int)((uint)DAT_20000c2f * 0x20000000) < 0) {
      DAT_20000bcd = 2;
    }
    else {
      DAT_20000bcd = 0;
    }
    DAT_20000bce = 0;
    DAT_20000bdb = DAT_20000c41;
    DAT_20000bd9 = DAT_20000c42;
    DAT_20000bd5 = DAT_20000c43;
    DAT_20000bd6 = DAT_20000c44;
    DAT_20000bd8 = DAT_20000c47;
  }
  if ((DAT_2000004b != DAT_20000049) && (DAT_20000bad != '\0')) {
    DAT_2000004b = DAT_20000049;
    (&DAT_20000beb)[DAT_20000049] = DAT_20000c45 >> 4;
    (&DAT_20000be5)[DAT_20000049] = DAT_20000c48;
    (&DAT_20000c05)[DAT_20000049] = DAT_20000c45 & 0xf;
    (&DAT_20000bf3)[DAT_20000049] = DAT_20000c46;
  }
  if ((DAT_2000004a != DAT_20000048) && (DAT_20000bac != '\0')) {
    DAT_2000004a = DAT_20000048;
    (&DAT_20000bff)[DAT_20000048] = DAT_20000c68 & 0xf;
    (&DAT_20000bdf)[DAT_20000048] = DAT_20000c6b;
  }
  return;
}

