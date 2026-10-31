// rea decompile_all
// name: FUN_0801c228
// address: 0x801c228
// body: available
// range: 0x801c228-0x801c339 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0801c228(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  if (DAT_20000688 == '\0') {
    DAT_20000688 = '\x01';
    for (uVar1 = 0; uVar1 < 10; uVar1 = uVar1 + 1 & 0xff) {
      *(short *)(uVar1 * 2 + 0x2000260c) = (short)(_DAT_20000048 / 100);
      DAT_20000689 = (byte)(DAT_20000689 + 1) % 10;
    }
    uVar1 = FUN_0801c1d2(_DAT_20000048 / DAT_20000373 & 0xffff,0x65,(ushort *)&DAT_0801d9c2);
    DAT_2000035c = (undefined1)uVar1;
  }
  else {
    uVar1 = (uint)DAT_20000689;
    DAT_20000689 = DAT_20000689 + 1;
    *(short *)(uVar1 * 2 + 0x2000260c) = (short)(_DAT_20000048 / 100);
    DAT_20000689 = DAT_20000689 % 10;
    uVar2 = 0;
    uVar3 = 1000;
    for (uVar1 = 0; uVar1 < 10; uVar1 = uVar1 + 1 & 0xff) {
      if (uVar2 < *(ushort *)(uVar1 * 2 + 0x2000260c)) {
        uVar2 = (uint)*(ushort *)(uVar1 * 2 + 0x2000260c);
      }
      if (*(ushort *)(uVar1 * 2 + 0x2000260c) < uVar3) {
        uVar3 = (uint)*(ushort *)(uVar1 * 2 + 0x2000260c);
      }
    }
    if ((int)(uVar2 - uVar3) < 0xb) {
      _DAT_2000068a = _DAT_2000068a + 1;
      if (0x3c < _DAT_2000068a) {
        _DAT_2000068a = 0;
        uVar1 = FUN_0801c1d2(_DAT_20000048 / DAT_20000373 & 0xffff,0x65,(ushort *)&DAT_0801d9c2);
        DAT_2000035c = (undefined1)uVar1;
      }
    }
    else {
      _DAT_2000068a = 0;
    }
  }
  return;
}

