// rea decompile_all
// name: FUN_08018e7a
// address: 0x8018e7a
// body: available
// range: 0x8018e7a-0x8018ee3 inclusive
// range: 0x8018f2c-0x8018f55 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_08018e7a(int param_1,byte *param_2,uint param_3)

{
  uint uVar1;
  ushort uVar2;
  undefined4 uVar3;
  uint uVar4;
  
  if ((int)(param_1 + param_3) < 0x1001) {
    _DAT_20001e6a = (ushort)param_1;
    _DAT_20001e6c = param_2;
    do {
      uVar1 = (((int)(uint)_DAT_20001e6a >> 5) + 1) * 0x20;
      uVar4 = param_3 - ((uVar1 & 0xffff) - (uint)_DAT_20001e6a);
      uVar2 = (ushort)uVar1;
      if ((int)uVar4 < 1) {
        _DAT_20001e74 = (ushort)param_3;
        FUN_08018736(_DAT_20001e6c,(uint)_DAT_20001e6a,param_3 & 0xffff);
        param_3 = 0;
      }
      else {
        _DAT_20001e74 = uVar2 - _DAT_20001e6a;
        FUN_08018736(_DAT_20001e6c,(uint)_DAT_20001e6a,(uint)_DAT_20001e74);
        param_3 = uVar4 & 0xffff;
        _DAT_20001e6c = _DAT_20001e6c + _DAT_20001e74;
      }
      _DAT_20001e6a = uVar2;
      FUN_08018fe2(5);
    } while (param_3 != 0);
    uVar3 = 0;
  }
  else {
    uVar3 = 2;
  }
  return uVar3;
}

