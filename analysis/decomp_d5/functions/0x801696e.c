// rea decompile_all
// name: FUN_0801696e
// address: 0x801696e
// body: available
// range: 0x801696e-0x8016a7f inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0801696e(int param_1,byte *param_2)

{
  uint uVar1;
  
  if (param_1 == 0x711) {
    if (*param_2 == 2) {
      DAT_200017fc = param_2[1];
    }
    if ((*param_2 == 3) && (param_2[1] == 0)) {
      DAT_20001778 = '\0';
      FUN_08016934();
    }
    else if ((*param_2 == 3) && (param_2[1] == 1)) {
      DAT_20001778 = '\x04';
      FUN_08016934();
    }
    else if (*param_2 == 4) {
      if (CONCAT11(param_2[2],param_2[3]) < 0x79) {
        _DAT_200017f2 = (ushort)param_2[1];
        DAT_20001778 = '\x01';
        _DAT_200017f6 = 0;
        _DAT_200017f4 = CONCAT11(param_2[2],param_2[3]);
      }
    }
    else if (((*param_2 & 0xf0) == 0x10) && (DAT_20001778 == '\x01')) {
      if ((*param_2 & 0xf) == _DAT_200017f6) {
        for (uVar1 = 0; (uVar1 < 7 && ((uint)_DAT_200017f6 * 7 + uVar1 < (uint)_DAT_200017f4));
            uVar1 = uVar1 + 1 & 0xff) {
          *(byte *)((uint)_DAT_200017f6 * 7 + uVar1 + 0x20001779) = param_2[uVar1 + 1];
        }
        _DAT_200017f6 = _DAT_200017f6 + 1;
        if (_DAT_200017f2 <= _DAT_200017f6) {
          DAT_20001778 = '\x02';
          _DAT_200017f6 = 0;
        }
      }
      else {
        DAT_20001778 = '\0';
      }
    }
  }
  return;
}

