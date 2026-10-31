// rea decompile_all
// name: FUN_0002c594
// address: 0x2c594
// body: available
// range: 0x2c594-0x2cebf inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002c594(void)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint local_14;
  
  DAT_20000549 = '\x01';
  DAT_2000069f = '\0';
  DAT_200006a2 = '\0';
  DAT_200006a5 = '\0';
  DAT_2000069e = '\0';
  DAT_200006a1 = '\0';
  DAT_200006a4 = '\0';
  DAT_2000069d = '\0';
  DAT_200006a0 = '\0';
  DAT_200006a3 = '\0';
  DAT_2000069c = '\0';
  do {
    while (DAT_20000549 != '\0') {
      DAT_20000549 = '\0';
      if (DAT_20000548 == '\0') {
        FUN_0002cec0();
        FUN_0002cf14();
        FUN_0002c4c0(1);
      }
      if (DAT_20000548 == '\x04') {
        FUN_0002cf10();
        FUN_0002c4c0(5);
        _DAT_20000544 = 0;
      }
      _DAT_20000680 = FUN_00012528(0x40046900);
      _DAT_2000068c = FUN_00012528(0x40046900);
      _DAT_20000698 = FUN_00012528(0x40046900);
      _DAT_2000067c = FUN_00012528(0x40046900);
      _DAT_20000688 = FUN_00012528(0x40046900);
      _DAT_20000694 = FUN_00012528(0x40046900);
      _DAT_20000678 = FUN_00012528(0x40046900);
      _DAT_20000684 = FUN_00012528(0x40046900);
      _DAT_20000690 = FUN_00012528(0x40046900);
      _DAT_20000674 = FUN_00012528(0x40046900);
    }
    if (DAT_2000069f == '\0') {
      uVar1 = FUN_00012528(0x40046900);
      if (_DAT_20000680 < uVar1) {
        local_14 = 1000;
      }
      else {
        local_14 = _DAT_20000680 - uVar1;
      }
      if (999 < local_14) {
        DAT_2000069f = '\x01';
        _DAT_20000680 = uVar1;
      }
    }
    if (DAT_2000069f == '\x01') {
      DAT_2000069f = '\0';
      uVar2 = FUN_00012528(0x40046900);
      FUN_0002cf2c();
      uVar3 = FUN_00012528(0x40046900);
      _DAT_20000550 = (short)uVar3 - (short)uVar2;
    }
    if (DAT_200006a2 == '\0') {
      uVar1 = FUN_00012528(0x40046900);
      if (_DAT_2000068c < uVar1) {
        local_14 = 2000;
      }
      else {
        local_14 = _DAT_2000068c - uVar1;
      }
      if (1999 < local_14) {
        DAT_200006a2 = '\x01';
        _DAT_2000068c = uVar1;
      }
    }
    if (DAT_200006a2 == '\x01') {
      DAT_200006a2 = '\0';
      uVar2 = FUN_00012528(0x40046900);
      FUN_0002cf3c();
      uVar3 = FUN_00012528(0x40046900);
      _DAT_20000556 = (short)uVar3 - (short)uVar2;
    }
    if (DAT_200006a5 == '\0') {
      uVar1 = FUN_00012528(0x40046900);
      if (_DAT_20000698 < uVar1) {
        local_14 = 5000;
      }
      else {
        local_14 = _DAT_20000698 - uVar1;
      }
      if (4999 < local_14) {
        DAT_200006a5 = '\x01';
        _DAT_20000698 = uVar1;
      }
    }
    if (DAT_200006a5 == '\x01') {
      DAT_200006a5 = '\0';
      uVar2 = FUN_00012528(0x40046900);
      FUN_0002cf40();
      uVar3 = FUN_00012528(0x40046900);
      _DAT_2000055c = (short)uVar3 - (short)uVar2;
    }
    if (DAT_2000069e == '\0') {
      uVar1 = FUN_00012528(0x40046900);
      if (_DAT_2000067c < uVar1) {
        local_14 = 10000;
      }
      else {
        local_14 = _DAT_2000067c - uVar1;
      }
      if (9999 < local_14) {
        DAT_2000069e = '\x01';
        _DAT_2000067c = uVar1;
      }
    }
    if (DAT_2000069e == '\x01') {
      DAT_2000069e = '\0';
      uVar2 = FUN_00012528(0x40046900);
      FUN_0002cf44();
      uVar3 = FUN_00012528(0x40046900);
      _DAT_2000054e = (short)uVar3 - (short)uVar2;
    }
    if (DAT_200006a1 == '\0') {
      uVar1 = FUN_00012528(0x40046900);
      if (_DAT_20000688 < uVar1) {
        local_14 = 20000;
      }
      else {
        local_14 = _DAT_20000688 - uVar1;
      }
      if (19999 < local_14) {
        DAT_200006a1 = '\x01';
        _DAT_20000688 = uVar1;
      }
    }
    if (DAT_200006a1 == '\x01') {
      DAT_200006a1 = '\0';
      uVar2 = FUN_00012528(0x40046900);
      FUN_0002cf5c();
      uVar3 = FUN_00012528(0x40046900);
      _DAT_20000554 = (short)uVar3 - (short)uVar2;
    }
    if (DAT_200006a4 == '\0') {
      uVar1 = FUN_00012528(0x40046900);
      if (_DAT_20000694 < uVar1) {
        local_14 = 50000;
      }
      else {
        local_14 = _DAT_20000694 - uVar1;
      }
      if (49999 < local_14) {
        DAT_200006a4 = '\x01';
        _DAT_20000694 = uVar1;
      }
    }
    if (DAT_200006a4 == '\x01') {
      DAT_200006a4 = '\0';
      uVar2 = FUN_00012528(0x40046900);
      FUN_0002cf60();
      uVar3 = FUN_00012528(0x40046900);
      _DAT_2000055a = (short)uVar3 - (short)uVar2;
    }
    if (DAT_2000069d == '\0') {
      uVar1 = FUN_00012528(0x40046900);
      if (_DAT_20000678 < uVar1) {
        local_14 = 100000;
      }
      else {
        local_14 = _DAT_20000678 - uVar1;
      }
      if (99999 < local_14) {
        DAT_2000069d = '\x01';
        _DAT_20000678 = uVar1;
      }
    }
    if (DAT_2000069d == '\x01') {
      DAT_2000069d = '\0';
      uVar2 = FUN_00012528(0x40046900);
      FUN_0002cf64();
      uVar3 = FUN_00012528(0x40046900);
      _DAT_2000054c = (short)uVar3 - (short)uVar2;
    }
    if (DAT_200006a0 == '\0') {
      uVar1 = FUN_00012528(0x40046900);
      if (_DAT_20000684 < uVar1) {
        local_14 = 200000;
      }
      else {
        local_14 = _DAT_20000684 - uVar1;
      }
      if (199999 < local_14) {
        DAT_200006a0 = '\x01';
        _DAT_20000684 = uVar1;
      }
    }
    if (DAT_200006a0 == '\x01') {
      DAT_200006a0 = '\0';
      uVar2 = FUN_00012528(0x40046900);
      FUN_0002cf84();
      uVar3 = FUN_00012528(0x40046900);
      _DAT_20000552 = (short)uVar3 - (short)uVar2;
    }
    if (DAT_200006a3 == '\0') {
      uVar1 = FUN_00012528(0x40046900);
      if (_DAT_20000690 < uVar1) {
        local_14 = 500000;
      }
      else {
        local_14 = _DAT_20000690 - uVar1;
      }
      if (499999 < local_14) {
        DAT_200006a3 = '\x01';
        _DAT_20000690 = uVar1;
      }
    }
    if (DAT_200006a3 == '\x01') {
      DAT_200006a3 = '\0';
      uVar2 = FUN_00012528(0x40046900);
      FUN_0002cf90();
      uVar3 = FUN_00012528(0x40046900);
      _DAT_20000558 = (short)uVar3 - (short)uVar2;
    }
    if (DAT_2000069c == '\0') {
      uVar1 = FUN_00012528(0x40046900);
      if (_DAT_20000674 < uVar1) {
        local_14 = 1000000;
      }
      else {
        local_14 = _DAT_20000674 - uVar1;
      }
      if (999999 < local_14) {
        DAT_2000069c = '\x01';
        _DAT_20000674 = uVar1;
      }
    }
    if (DAT_2000069c == '\x01') {
      DAT_2000069c = '\0';
      uVar2 = FUN_00012528(0x40046900);
      FUN_0002cf9c();
      uVar3 = FUN_00012528(0x40046900);
      _DAT_2000054a = (short)uVar3 - (short)uVar2;
    }
    uVar2 = FUN_00012528(0x40046900);
    FUN_0002cfa0();
    uVar3 = FUN_00012528(0x40046900);
    _DAT_2000055e = (short)uVar3 - (short)uVar2;
  } while( true );
}

