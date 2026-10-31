// rea decompile_all
// name: FUN_0801bf0c
// address: 0x801bf0c
// body: available
// range: 0x801bf0c-0x801bf55 inclusive
// range: 0x801c0b0-0x801c17d inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0801bf0c(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  if (DAT_20000670 == '\0') {
    DAT_20000670 = '\x01';
    for (uVar1 = 0; uVar1 < 10; uVar1 = uVar1 + 1 & 0xff) {
      *(short *)(uVar1 * 2 + 0x200025f4) = (short)(_DAT_20000048 / 100);
      DAT_20000671 = (byte)(DAT_20000671 + 1) % 10;
    }
    uVar1 = FUN_0801beb6(_DAT_20000048 / DAT_20000373 & 0xffff,0x65,(ushort *)&DAT_0801d7de);
    DAT_2000035c = (undefined1)uVar1;
  }
  else {
    uVar1 = (uint)DAT_20000671;
    DAT_20000671 = DAT_20000671 + 1;
    *(short *)(uVar1 * 2 + 0x200025f4) = (short)(_DAT_20000048 / 100);
    DAT_20000671 = DAT_20000671 % 10;
    uVar2 = 0;
    uVar3 = 1000;
    for (uVar1 = 0; uVar1 < 10; uVar1 = uVar1 + 1 & 0xff) {
      if (uVar2 < *(ushort *)(uVar1 * 2 + 0x200025f4)) {
        uVar2 = (uint)*(ushort *)(uVar1 * 2 + 0x200025f4);
      }
      if (*(ushort *)(uVar1 * 2 + 0x200025f4) < uVar3) {
        uVar3 = (uint)*(ushort *)(uVar1 * 2 + 0x200025f4);
      }
    }
    if ((int)(uVar2 - uVar3) < 0xb) {
      _DAT_20000672 = _DAT_20000672 + 1;
      if (0x3c < _DAT_20000672) {
        _DAT_20000672 = 0;
        uVar1 = FUN_0801beb6(_DAT_20000048 / DAT_20000373 & 0xffff,0x65,(ushort *)&DAT_0801d7de);
        DAT_2000035c = (undefined1)uVar1;
      }
    }
    else {
      _DAT_20000672 = 0;
    }
  }
  return;
}

