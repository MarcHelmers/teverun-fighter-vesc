// rea decompile_all
// name: FUN_08018a48
// address: 0x8018a48
// body: available
// range: 0x8018a48-0x8018ab5 inclusive
// range: 0x8018ae8-0x8018b4b inclusive
// range: 0x8018b4e-0x8018c0d inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08018a48(void)

{
  short sVar1;
  undefined1 uVar2;
  uint uVar3;
  bool bVar4;
  
  uVar3 = FUN_0800b27e(0x40005400);
  if (uVar3 == 0x70080) {
    if (DAT_200004f4 != '\x01') {
      return;
    }
    FUN_0800b092((ushort *)0x40005400,1);
    return;
  }
  if ((int)uVar3 < 0x70081) {
    if (uVar3 == 0x30001) {
      if (DAT_200004f0 == '\0') {
        DAT_20000514 = 2;
      }
      if (DAT_200004f4 == '\x01') {
        if (DAT_200004f1 == '\0') {
          FUN_0800b13e(0x40005400,(ushort)DAT_200004f6,0);
          return;
        }
        FUN_0800b13e(0x40005400,(ushort)DAT_200004f6,1);
        DAT_200004f1 = 0;
        return;
      }
      FUN_0800b13e(0x40005400,(ushort)DAT_200004f6,0);
      return;
    }
    if (uVar3 == 0x30002) {
      return;
    }
    bVar4 = uVar3 == 0x30040;
  }
  else {
    if (uVar3 == 0x70082) {
      if (DAT_200004f0 != '\0') {
        DAT_200004f0 = 0;
        FUN_0800b120(0x40005400,0x700,0);
        FUN_0800b0aa((ushort *)0x40005400,1);
        DAT_20000514 = 0;
        return;
      }
      FUN_0800b132(0x40005400,(ushort)DAT_200004f8);
      DAT_200004f1 = 1;
      return;
    }
    bVar4 = false;
    if (uVar3 == 0x70084) {
      if (DAT_200004f4 != '\0') {
        return;
      }
      if (_DAT_20000510 != 0) {
        uVar3 = (uint)_DAT_2000050e;
        _DAT_2000050e = _DAT_2000050e + 1;
        FUN_0800b132(0x40005400,(ushort)*(byte *)(uVar3 + 0x20000506));
        _DAT_20000510 = _DAT_20000510 + -1;
        return;
      }
      FUN_0800b0aa((ushort *)0x40005400,1);
      _DAT_200004f2 = 3000;
      do {
        bVar4 = FUN_0800b298(0x40005400,0x20000);
        if (!bVar4) break;
        sVar1 = _DAT_200004f2 + -1;
        bVar4 = _DAT_200004f2 != 0;
        _DAT_200004f2 = sVar1;
      } while (bVar4);
      DAT_200004f0 = 1;
      FUN_0800b092((ushort *)0x40005400,1);
      return;
    }
  }
  if (bVar4) {
    uVar2 = FUN_0800b136(0x40005400);
    *_DAT_20000500 = uVar2;
    _DAT_20000500 = _DAT_20000500 + 1;
    _DAT_20000512 = _DAT_20000512 + -1;
    if (_DAT_20000512 == 1) {
      FUN_0800b0c2((ushort *)0x40005400,0);
      FUN_0800b0aa((ushort *)0x40005400,1);
    }
    if (_DAT_20000512 == 0) {
      FUN_0800b120(0x40005400,0x700,0);
      DAT_20000514 = 0;
    }
  }
  return;
}

