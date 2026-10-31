// rea decompile_all
// name: FUN_0801c278
// address: 0x801c278
// body: available
// range: 0x801c278-0x801c595 inclusive
// range: 0x801c61c-0x801c791 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0801c278(void)

{
  ushort uVar1;
  short sVar2;
  uint uVar3;
  
  DAT_200006a8 = '\x01';
  DAT_20000688 = '\0';
  DAT_20000689 = '\0';
  DAT_2000068a = '\0';
  DAT_2000068b = '\0';
  DAT_2000068c = '\0';
  DAT_2000068d = '\0';
  DAT_2000068e = '\0';
  DAT_2000068f = '\0';
  DAT_20000690 = '\0';
  DAT_20000691 = '\0';
  do {
    while (DAT_200006a8 != '\0') {
      DAT_200006a8 = '\0';
      if (DAT_200006b1 == '\0') {
        FUN_08018594();
        FUN_080185c8();
        FUN_0801c1b8(1);
      }
      if (DAT_200006b1 == '\x02') {
        FUN_080185c4();
        FUN_080185c8();
        FUN_0801c1b8(3);
      }
      if (DAT_200006b1 == '\x04') {
        FUN_080185c6();
        FUN_0801c1b8(5);
        _DAT_200006ac = 0;
      }
      _DAT_20000674 = FUN_08018fce();
      _DAT_20000676 = FUN_08018fce();
      _DAT_20000678 = FUN_08018fce();
      _DAT_2000067a = FUN_08018fce();
      _DAT_2000067c = FUN_08018fce();
      _DAT_2000067e = FUN_08018fce();
      _DAT_20000680 = FUN_08018fce();
      _DAT_20000682 = FUN_08018fce();
      _DAT_20000684 = FUN_08018fce();
      _DAT_20000686 = FUN_08018fce();
    }
    if (DAT_20000688 == '\0') {
      uVar1 = FUN_08018fce();
      uVar3 = (uint)uVar1;
      if (uVar3 < _DAT_20000674) {
        uVar3 = (0xffff - (uint)_DAT_20000674) + uVar3;
      }
      else {
        uVar3 = uVar3 - _DAT_20000674 & 0xffff;
      }
      if (9 < uVar3) {
        DAT_20000688 = '\x01';
        _DAT_20000674 = uVar1;
      }
    }
    if (DAT_20000688 == '\x01') {
      DAT_20000688 = '\0';
      sVar2 = FUN_08018fce();
      FUN_080185e8();
      _DAT_20000692 = FUN_08018fce();
      _DAT_20000692 = _DAT_20000692 - sVar2;
    }
    if (DAT_20000689 == '\0') {
      uVar1 = FUN_08018fce();
      uVar3 = (uint)uVar1;
      if (uVar3 < _DAT_20000676) {
        uVar3 = (0xffff - (uint)_DAT_20000676) + uVar3;
      }
      else {
        uVar3 = uVar3 - _DAT_20000676 & 0xffff;
      }
      if (0x13 < uVar3) {
        DAT_20000689 = '\x01';
        _DAT_20000676 = uVar1;
      }
    }
    if (DAT_20000689 == '\x01') {
      DAT_20000689 = '\0';
      sVar2 = FUN_08018fce();
      FUN_080185f4();
      _DAT_20000694 = FUN_08018fce();
      _DAT_20000694 = _DAT_20000694 - sVar2;
    }
    if (DAT_2000068a == '\0') {
      uVar1 = FUN_08018fce();
      uVar3 = (uint)uVar1;
      if (uVar3 < _DAT_20000678) {
        uVar3 = (0xffff - (uint)_DAT_20000678) + uVar3;
      }
      else {
        uVar3 = uVar3 - _DAT_20000678 & 0xffff;
      }
      if (0x31 < uVar3) {
        DAT_2000068a = '\x01';
        _DAT_20000678 = uVar1;
      }
    }
    if (DAT_2000068a == '\x01') {
      DAT_2000068a = '\0';
      sVar2 = FUN_08018fce();
      FUN_080185f6();
      _DAT_20000696 = FUN_08018fce();
      _DAT_20000696 = _DAT_20000696 - sVar2;
    }
    if (DAT_2000068b == '\0') {
      uVar1 = FUN_08018fce();
      uVar3 = (uint)uVar1;
      if (uVar3 < _DAT_2000067a) {
        uVar3 = (0xffff - (uint)_DAT_2000067a) + uVar3;
      }
      else {
        uVar3 = uVar3 - _DAT_2000067a & 0xffff;
      }
      if (99 < uVar3) {
        DAT_2000068b = '\x01';
        _DAT_2000067a = uVar1;
      }
    }
    if (DAT_2000068b == '\x01') {
      DAT_2000068b = '\0';
      sVar2 = FUN_08018fce();
      FUN_080185f8();
      _DAT_20000698 = FUN_08018fce();
      _DAT_20000698 = _DAT_20000698 - sVar2;
    }
    if (DAT_2000068c == '\0') {
      uVar1 = FUN_08018fce();
      uVar3 = (uint)uVar1;
      if (uVar3 < _DAT_2000067c) {
        uVar3 = (0xffff - (uint)_DAT_2000067c) + uVar3;
      }
      else {
        uVar3 = uVar3 - _DAT_2000067c & 0xffff;
      }
      if (199 < uVar3) {
        DAT_2000068c = '\x01';
        _DAT_2000067c = uVar1;
      }
    }
    if (DAT_2000068c == '\x01') {
      DAT_2000068c = '\0';
      sVar2 = FUN_08018fce();
      FUN_08018610();
      _DAT_2000069a = FUN_08018fce();
      _DAT_2000069a = _DAT_2000069a - sVar2;
    }
    if (DAT_2000068d == '\0') {
      uVar1 = FUN_08018fce();
      uVar3 = (uint)uVar1;
      if (uVar3 < _DAT_2000067e) {
        uVar3 = (0xffff - (uint)_DAT_2000067e) + uVar3;
      }
      else {
        uVar3 = uVar3 - _DAT_2000067e & 0xffff;
      }
      if (499 < uVar3) {
        DAT_2000068d = '\x01';
        _DAT_2000067e = uVar1;
      }
    }
    if (DAT_2000068d == '\x01') {
      DAT_2000068d = '\0';
      sVar2 = FUN_08018fce();
      FUN_08018612();
      _DAT_2000069c = FUN_08018fce();
      _DAT_2000069c = _DAT_2000069c - sVar2;
    }
    if (DAT_2000068e == '\0') {
      uVar1 = FUN_08018fce();
      uVar3 = (uint)uVar1;
      if (uVar3 < _DAT_20000680) {
        uVar3 = (0xffff - (uint)_DAT_20000680) + uVar3;
      }
      else {
        uVar3 = uVar3 - _DAT_20000680 & 0xffff;
      }
      if (999 < uVar3) {
        DAT_2000068e = '\x01';
        _DAT_20000680 = uVar1;
      }
    }
    if (DAT_2000068e == '\x01') {
      DAT_2000068e = '\0';
      sVar2 = FUN_08018fce();
      FUN_0801862a();
      _DAT_2000069e = FUN_08018fce();
      _DAT_2000069e = _DAT_2000069e - sVar2;
    }
    if (DAT_2000068f == '\0') {
      uVar1 = FUN_08018fce();
      uVar3 = (uint)uVar1;
      if (uVar3 < _DAT_20000682) {
        uVar3 = (0xffff - (uint)_DAT_20000682) + uVar3;
      }
      else {
        uVar3 = uVar3 - _DAT_20000682 & 0xffff;
      }
      if (1999 < uVar3) {
        DAT_2000068f = '\x01';
        _DAT_20000682 = uVar1;
      }
    }
    if (DAT_2000068f == '\x01') {
      DAT_2000068f = '\0';
      sVar2 = FUN_08018fce();
      FUN_0801863a();
      _DAT_200006a0 = FUN_08018fce();
      _DAT_200006a0 = _DAT_200006a0 - sVar2;
    }
    if (DAT_20000690 == '\0') {
      uVar1 = FUN_08018fce();
      uVar3 = (uint)uVar1;
      if (uVar3 < _DAT_20000684) {
        uVar3 = (0xffff - (uint)_DAT_20000684) + uVar3;
      }
      else {
        uVar3 = uVar3 - _DAT_20000684 & 0xffff;
      }
      if (4999 < uVar3) {
        DAT_20000690 = '\x01';
        _DAT_20000684 = uVar1;
      }
    }
    if (DAT_20000690 == '\x01') {
      DAT_20000690 = '\0';
      sVar2 = FUN_08018fce();
      FUN_08018650();
      _DAT_200006a2 = FUN_08018fce();
      _DAT_200006a2 = _DAT_200006a2 - sVar2;
    }
    if (DAT_20000691 == '\0') {
      uVar1 = FUN_08018fce();
      uVar3 = (uint)uVar1;
      if (uVar3 < _DAT_20000686) {
        uVar3 = (0xffff - (uint)_DAT_20000686) + uVar3;
      }
      else {
        uVar3 = uVar3 - _DAT_20000686 & 0xffff;
      }
      if (9999 < uVar3) {
        DAT_20000691 = '\x01';
        _DAT_20000686 = uVar1;
      }
    }
    if (DAT_20000691 == '\x01') {
      DAT_20000691 = '\0';
      sVar2 = FUN_08018fce();
      FUN_08018658();
      _DAT_200006a4 = FUN_08018fce();
      _DAT_200006a4 = _DAT_200006a4 - sVar2;
    }
    sVar2 = FUN_08018fce();
    FUN_0801866c();
    _DAT_200006a6 = FUN_08018fce();
    _DAT_200006a6 = _DAT_200006a6 - sVar2;
  } while( true );
}

