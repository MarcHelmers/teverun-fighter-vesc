// rea decompile_all
// name: FUN_08007184
// address: 0x8007184
// body: available
// range: 0x8007184-0x8007285 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_08007184(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  uVar2 = 0;
  uVar3 = 0;
  iVar4 = 0;
  uVar5 = _DAT_40021000 | 0x10000;
  do {
    iVar4 = iVar4 + 1;
    if ((int)(uVar5 << 0xe) < 0) break;
  } while (iVar4 != 0x2000);
  if ((int)(uVar5 << 0xe) < 0) {
    _DAT_4002101c = _DAT_4002101c | 0x10000000;
    if ((_DAT_40007000 & 0x600) == 0x400) {
      _DAT_40007000 = _DAT_40007000 | 0x600;
    }
    _DAT_40022000 = _DAT_40022000 & 0xfffffffc | 3;
    uVar3 = _DAT_40021040 & 0xfffffffc;
    uVar2 = _DAT_40021004 & 0xf7c0ffff | 0x82b2500;
    uVar5 = _DAT_40021000 | 0x1010000;
    do {
    } while ((_DAT_40021000 & 0x2000000) == 0);
    do {
      _DAT_40021000 = uVar5;
      uVar1 = _DAT_40021004 & 0xf7c0fffc | 0x82b2503;
      _DAT_40021040 = uVar3;
    } while ((_DAT_40021004 & 0xc) != 0xc);
  }
  else {
    _DAT_20000000 = 4000000;
    _DAT_40021000 = uVar5;
    uVar1 = _DAT_40021004;
  }
  _DAT_40021004 = uVar1;
  return CONCAT44(uVar3,uVar2);
}

