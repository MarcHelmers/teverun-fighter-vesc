// rea decompile_all
// name: FUN_0800fae0
// address: 0x800fae0
// body: available
// range: 0x800fae0-0x800fb17 inclusive
// range: 0x800fb78-0x800fe5d inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0800fae0(void)

{
  bool bVar1;
  uint uVar2;
  char local_38;
  undefined1 local_37 [4];
  undefined1 local_33;
  undefined1 local_32;
  undefined1 local_31;
  undefined1 local_30;
  undefined1 local_2f;
  undefined1 local_2e;
  undefined1 local_2d;
  undefined1 local_2c;
  undefined1 local_2b;
  undefined1 local_2a;
  undefined1 local_29;
  undefined1 local_28;
  undefined1 local_27;
  byte local_25;
  char local_24;
  undefined1 local_23;
  char local_22;
  undefined1 local_21;
  undefined1 local_20;
  undefined1 local_1f;
  undefined1 local_1e;
  undefined1 local_1d;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  undefined1 local_19;
  byte local_17;
  
  bVar1 = FUN_0800faa0(0x20000dfa,(undefined4 *)&local_24);
  if (bVar1) {
    if (_DAT_20000404 < 5000) {
      _DAT_20000404 = _DAT_20000404 + 1;
    }
    else {
      _DAT_20000404 = 5000;
    }
    if (_DAT_20000406 < 5000) {
      _DAT_20000406 = _DAT_20000406 + 1;
    }
    else {
      _DAT_20000406 = 5000;
    }
  }
  else if (local_24 == 'q') {
    bVar1 = FUN_0800fa12((int)&local_24,0xc,(uint)local_17);
    if (bVar1) {
      DAT_20001374 = local_24;
      DAT_20001375 = local_23;
      DAT_20001376 = local_22;
      DAT_20001377 = local_21;
      DAT_20001378 = local_20;
      DAT_20001379 = local_1f;
      DAT_2000137a = local_1e;
      DAT_2000137b = local_1d;
      DAT_2000137c = local_1c;
      DAT_2000137d = local_1b;
      DAT_2000137e = local_1a;
      DAT_2000137f = local_19;
      DAT_20001380 = local_17;
      if (local_22 == ':') {
        DAT_20000309 = 0;
        _DAT_20000404 = 0;
      }
      else if (local_22 == ';') {
        DAT_20000308 = 0;
        _DAT_20000406 = 0;
      }
    }
    else {
      if (_DAT_20000404 < 5000) {
        _DAT_20000404 = _DAT_20000404 + 1;
      }
      else {
        _DAT_20000404 = 5000;
      }
      if (_DAT_20000406 < 5000) {
        _DAT_20000406 = _DAT_20000406 + 1;
      }
      else {
        _DAT_20000406 = 5000;
      }
    }
  }
  else {
    if (_DAT_20000404 < 5000) {
      _DAT_20000404 = _DAT_20000404 + 1;
    }
    else {
      _DAT_20000404 = 5000;
    }
    if (_DAT_20000406 < 5000) {
      _DAT_20000406 = _DAT_20000406 + 1;
    }
    else {
      _DAT_20000406 = 5000;
    }
  }
  if (600 < _DAT_20000404) {
    DAT_20000309 = 1;
  }
  if (600 < _DAT_20000406) {
    DAT_20000308 = 1;
  }
  bVar1 = FUN_0800fa4a(0x20000ecf,(undefined4 *)&local_38);
  if (bVar1) {
    if (_DAT_20000402 < 5000) {
      _DAT_20000402 = _DAT_20000402 + 1;
    }
    else {
      _DAT_20000402 = 5000;
    }
  }
  else {
    bVar1 = FUN_0800fa12((int)&local_38,0x12,(uint)local_25);
    if ((bVar1) && (local_38 == 'L')) {
      DAT_20000306 = 0;
      _DAT_20000402 = 0;
      DAT_2000134d = local_38;
      DAT_2000134e = local_37[0];
      DAT_2000134f = local_37[1];
      DAT_20001350 = local_37[2];
      DAT_20001351 = local_37[3];
      DAT_20001352 = local_33;
      DAT_20001353 = local_32;
      DAT_20001354 = local_31;
      DAT_20001355 = local_30;
      DAT_20001356 = local_2f;
      DAT_20001357 = local_2e;
      DAT_20001358 = local_2d;
      DAT_20001359 = local_2c;
      DAT_2000135a = local_2b;
      DAT_2000135b = local_2a;
      DAT_2000135c = local_29;
      DAT_2000135d = local_28;
      DAT_2000135e = local_27;
      DAT_2000135f = local_25;
    }
    else if (local_38 == -0x76) {
      DAT_20001381 = local_38;
      for (uVar2 = 0; uVar2 < 0xb; uVar2 = uVar2 + 1 & 0xff) {
        *(undefined1 *)(uVar2 + 0x20001382) = local_37[uVar2];
      }
      DAT_200003fe = 1;
    }
    else if (local_38 == -0x75) {
      DAT_20001381 = local_38;
      for (uVar2 = 0; uVar2 < 8; uVar2 = uVar2 + 1 & 0xff) {
        *(undefined1 *)(uVar2 + 0x20001382) = local_37[uVar2];
      }
      DAT_200003fe = 1;
    }
    else if (local_38 == -0x74) {
      DAT_20001381 = local_38;
      for (uVar2 = 0; uVar2 < 8; uVar2 = uVar2 + 1 & 0xff) {
        *(undefined1 *)(uVar2 + 0x20001382) = local_37[uVar2];
      }
      DAT_200003fe = 1;
    }
    else if (_DAT_20000402 < 5000) {
      _DAT_20000402 = _DAT_20000402 + 1;
    }
    else {
      _DAT_20000402 = 5000;
    }
  }
  if (600 < _DAT_20000402) {
    DAT_20000306 = 1;
  }
  return 0;
}

