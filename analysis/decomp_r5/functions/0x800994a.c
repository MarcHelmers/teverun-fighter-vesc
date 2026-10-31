// rea decompile_all
// name: FUN_0800994a
// address: 0x800994a
// body: available
// range: 0x800994a-0x8009a3d inclusive
// range: 0x8009a58-0x8009ad9 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
FUN_0800994a(uint param_1,uint param_2,uint param_3,uint param_4,uint param_5,uint param_6,
            undefined4 param_7,uint param_8,uint param_9,uint param_10,uint param_11,uint param_12,
            uint param_13)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint local_30;
  
  bVar1 = FUN_08009884();
  if (bVar1) {
    iVar2 = 8;
    local_30 = param_2;
  }
  else {
    uVar3 = ~param_8;
    local_30 = param_9 | (param_10 | param_11 | param_12 | param_13) << 0x10;
    _DAT_40022008 = 0xcdef89ab;
    FUN_080097cc(0x7c);
    iVar2 = FUN_080097a6();
    if (iVar2 == 6) {
      _DAT_40022010 = _DAT_40022010 | 0x60;
      iVar2 = FUN_080097a6();
      if (iVar2 == 6) {
        FUN_080097cc(0x7c);
        _DAT_40022010 = _DAT_40022010 & 0x3fdf | 0x10;
        _DAT_1ffff800 = param_1 | (param_2 | param_3 | param_4 | param_5) << 0x10;
        iVar2 = FUN_080097a6();
        if (iVar2 == 6) {
          FUN_080097cc(0x7c);
          _DAT_1ffff804 = param_6 | param_6 << 0x10;
          iVar2 = FUN_080097a6();
          if (iVar2 == 6) {
            FUN_080097cc(0x7c);
            _DAT_1ffff808 = uVar3 & 0xff | (uVar3 & 0xff00) << 8;
            iVar2 = FUN_080097a6();
            if (iVar2 == 6) {
              FUN_080097cc(0x7c);
              _DAT_1ffff80c = uVar3 >> 8 & 0xff0000 | (uVar3 & 0xffffff) >> 0x10;
              iVar2 = FUN_080097a6();
              if (iVar2 == 6) {
                FUN_080097cc(0x7c);
                _DAT_1ffff810 = local_30;
                iVar2 = FUN_080097a6();
              }
            }
          }
        }
        if (iVar2 != 10) {
          _DAT_40022010 = _DAT_40022010 & 0x3fef;
        }
      }
      else if (iVar2 != 10) {
        _DAT_40022010 = _DAT_40022010 & 0x3fdf;
      }
    }
  }
  return CONCAT44(local_30,iVar2);
}

