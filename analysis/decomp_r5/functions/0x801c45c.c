// rea decompile_all
// name: FUN_0801c45c
// address: 0x801c45c
// body: available
// range: 0x801c45c-0x801c779 inclusive
// range: 0x801c800-0x801c975 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0801c45c(void)

{
  ushort uVar1;
  short sVar2;
  uint uVar3;
  
  DAT_200006c0 = '\x01';
  DAT_200006a0 = '\0';
  DAT_200006a1 = '\0';
  DAT_200006a2 = '\0';
  DAT_200006a3 = '\0';
  DAT_200006a4 = '\0';
  DAT_200006a5 = '\0';
  DAT_200006a6 = '\0';
  DAT_200006a7 = '\0';
  DAT_200006a8 = '\0';
  DAT_200006a9 = '\0';
  do {
    while (DAT_200006c0 != '\0') {
      DAT_200006c0 = '\0';
      if (DAT_200006c9 == '\0') {
        FUN_080186d8();
        FUN_0801870c();
        FUN_0801c39c(1);
      }
      if (DAT_200006c9 == '\x02') {
        FUN_08018708();
        FUN_0801870c();
        FUN_0801c39c(3);
      }
      if (DAT_200006c9 == '\x04') {
        FUN_0801870a();
        FUN_0801c39c(5);
        _DAT_200006c4 = 0;
      }
      _DAT_2000068c = FUN_08019112();
      _DAT_2000068e = FUN_08019112();
      _DAT_20000690 = FUN_08019112();
      _DAT_20000692 = FUN_08019112();
      _DAT_20000694 = FUN_08019112();
      _DAT_20000696 = FUN_08019112();
      _DAT_20000698 = FUN_08019112();
      _DAT_2000069a = FUN_08019112();
      _DAT_2000069c = FUN_08019112();
      _DAT_2000069e = FUN_08019112();
    }
    if (DAT_200006a0 == '\0') {
      uVar1 = FUN_08019112();
      uVar3 = (uint)uVar1;
      if (uVar3 < _DAT_2000068c) {
        uVar3 = (0xffff - (uint)_DAT_2000068c) + uVar3;
      }
      else {
        uVar3 = uVar3 - _DAT_2000068c & 0xffff;
      }
      if (9 < uVar3) {
        DAT_200006a0 = '\x01';
        _DAT_2000068c = uVar1;
      }
    }
    if (DAT_200006a0 == '\x01') {
      DAT_200006a0 = '\0';
      sVar2 = FUN_08019112();
      FUN_0801872c();
      _DAT_200006aa = FUN_08019112();
      _DAT_200006aa = _DAT_200006aa - sVar2;
    }
    if (DAT_200006a1 == '\0') {
      uVar1 = FUN_08019112();
      uVar3 = (uint)uVar1;
      if (uVar3 < _DAT_2000068e) {
        uVar3 = (0xffff - (uint)_DAT_2000068e) + uVar3;
      }
      else {
        uVar3 = uVar3 - _DAT_2000068e & 0xffff;
      }
      if (0x13 < uVar3) {
        DAT_200006a1 = '\x01';
        _DAT_2000068e = uVar1;
      }
    }
    if (DAT_200006a1 == '\x01') {
      DAT_200006a1 = '\0';
      sVar2 = FUN_08019112();
      FUN_08018738();
      _DAT_200006ac = FUN_08019112();
      _DAT_200006ac = _DAT_200006ac - sVar2;
    }
    if (DAT_200006a2 == '\0') {
      uVar1 = FUN_08019112();
      uVar3 = (uint)uVar1;
      if (uVar3 < _DAT_20000690) {
        uVar3 = (0xffff - (uint)_DAT_20000690) + uVar3;
      }
      else {
        uVar3 = uVar3 - _DAT_20000690 & 0xffff;
      }
      if (0x31 < uVar3) {
        DAT_200006a2 = '\x01';
        _DAT_20000690 = uVar1;
      }
    }
    if (DAT_200006a2 == '\x01') {
      DAT_200006a2 = '\0';
      sVar2 = FUN_08019112();
      FUN_0801873a();
      _DAT_200006ae = FUN_08019112();
      _DAT_200006ae = _DAT_200006ae - sVar2;
    }
    if (DAT_200006a3 == '\0') {
      uVar1 = FUN_08019112();
      uVar3 = (uint)uVar1;
      if (uVar3 < _DAT_20000692) {
        uVar3 = (0xffff - (uint)_DAT_20000692) + uVar3;
      }
      else {
        uVar3 = uVar3 - _DAT_20000692 & 0xffff;
      }
      if (99 < uVar3) {
        DAT_200006a3 = '\x01';
        _DAT_20000692 = uVar1;
      }
    }
    if (DAT_200006a3 == '\x01') {
      DAT_200006a3 = '\0';
      sVar2 = FUN_08019112();
      FUN_0801873c();
      _DAT_200006b0 = FUN_08019112();
      _DAT_200006b0 = _DAT_200006b0 - sVar2;
    }
    if (DAT_200006a4 == '\0') {
      uVar1 = FUN_08019112();
      uVar3 = (uint)uVar1;
      if (uVar3 < _DAT_20000694) {
        uVar3 = (0xffff - (uint)_DAT_20000694) + uVar3;
      }
      else {
        uVar3 = uVar3 - _DAT_20000694 & 0xffff;
      }
      if (199 < uVar3) {
        DAT_200006a4 = '\x01';
        _DAT_20000694 = uVar1;
      }
    }
    if (DAT_200006a4 == '\x01') {
      DAT_200006a4 = '\0';
      sVar2 = FUN_08019112();
      FUN_08018754();
      _DAT_200006b2 = FUN_08019112();
      _DAT_200006b2 = _DAT_200006b2 - sVar2;
    }
    if (DAT_200006a5 == '\0') {
      uVar1 = FUN_08019112();
      uVar3 = (uint)uVar1;
      if (uVar3 < _DAT_20000696) {
        uVar3 = (0xffff - (uint)_DAT_20000696) + uVar3;
      }
      else {
        uVar3 = uVar3 - _DAT_20000696 & 0xffff;
      }
      if (499 < uVar3) {
        DAT_200006a5 = '\x01';
        _DAT_20000696 = uVar1;
      }
    }
    if (DAT_200006a5 == '\x01') {
      DAT_200006a5 = '\0';
      sVar2 = FUN_08019112();
      FUN_08018756();
      _DAT_200006b4 = FUN_08019112();
      _DAT_200006b4 = _DAT_200006b4 - sVar2;
    }
    if (DAT_200006a6 == '\0') {
      uVar1 = FUN_08019112();
      uVar3 = (uint)uVar1;
      if (uVar3 < _DAT_20000698) {
        uVar3 = (0xffff - (uint)_DAT_20000698) + uVar3;
      }
      else {
        uVar3 = uVar3 - _DAT_20000698 & 0xffff;
      }
      if (999 < uVar3) {
        DAT_200006a6 = '\x01';
        _DAT_20000698 = uVar1;
      }
    }
    if (DAT_200006a6 == '\x01') {
      DAT_200006a6 = '\0';
      sVar2 = FUN_08019112();
      FUN_0801876e();
      _DAT_200006b6 = FUN_08019112();
      _DAT_200006b6 = _DAT_200006b6 - sVar2;
    }
    if (DAT_200006a7 == '\0') {
      uVar1 = FUN_08019112();
      uVar3 = (uint)uVar1;
      if (uVar3 < _DAT_2000069a) {
        uVar3 = (0xffff - (uint)_DAT_2000069a) + uVar3;
      }
      else {
        uVar3 = uVar3 - _DAT_2000069a & 0xffff;
      }
      if (1999 < uVar3) {
        DAT_200006a7 = '\x01';
        _DAT_2000069a = uVar1;
      }
    }
    if (DAT_200006a7 == '\x01') {
      DAT_200006a7 = '\0';
      sVar2 = FUN_08019112();
      FUN_0801877e();
      _DAT_200006b8 = FUN_08019112();
      _DAT_200006b8 = _DAT_200006b8 - sVar2;
    }
    if (DAT_200006a8 == '\0') {
      uVar1 = FUN_08019112();
      uVar3 = (uint)uVar1;
      if (uVar3 < _DAT_2000069c) {
        uVar3 = (0xffff - (uint)_DAT_2000069c) + uVar3;
      }
      else {
        uVar3 = uVar3 - _DAT_2000069c & 0xffff;
      }
      if (4999 < uVar3) {
        DAT_200006a8 = '\x01';
        _DAT_2000069c = uVar1;
      }
    }
    if (DAT_200006a8 == '\x01') {
      DAT_200006a8 = '\0';
      sVar2 = FUN_08019112();
      FUN_08018794();
      _DAT_200006ba = FUN_08019112();
      _DAT_200006ba = _DAT_200006ba - sVar2;
    }
    if (DAT_200006a9 == '\0') {
      uVar1 = FUN_08019112();
      uVar3 = (uint)uVar1;
      if (uVar3 < _DAT_2000069e) {
        uVar3 = (0xffff - (uint)_DAT_2000069e) + uVar3;
      }
      else {
        uVar3 = uVar3 - _DAT_2000069e & 0xffff;
      }
      if (9999 < uVar3) {
        DAT_200006a9 = '\x01';
        _DAT_2000069e = uVar1;
      }
    }
    if (DAT_200006a9 == '\x01') {
      DAT_200006a9 = '\0';
      sVar2 = FUN_08019112();
      FUN_0801879c();
      _DAT_200006bc = FUN_08019112();
      _DAT_200006bc = _DAT_200006bc - sVar2;
    }
    sVar2 = FUN_08019112();
    FUN_080187b0();
    _DAT_200006be = FUN_08019112();
    _DAT_200006be = _DAT_200006be - sVar2;
  } while( true );
}

