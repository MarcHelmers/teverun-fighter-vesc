// rea decompile_all
// name: FUN_0801b886
// address: 0x801b886
// body: available
// range: 0x801b886-0x801b9cf inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0801b886(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  char cVar1;
  short sVar2;
  int iVar3;
  int extraout_r1;
  int extraout_r2;
  int iVar4;
  undefined4 extraout_r3;
  undefined4 uVar5;
  uint uVar6;
  undefined4 local_38;
  undefined4 local_34;
  undefined1 local_30;
  undefined1 local_2f;
  undefined1 local_2e;
  undefined1 local_2d [9];
  
  iVar3 = param_2;
  iVar4 = param_3;
  uVar5 = param_4;
  if (0x13 < _DAT_2000038a) {
    FUN_0801b748((uint)_DAT_2000038a,param_2,param_3,param_4);
    FUN_0800ab40(0x40006400,0);
    FUN_0800ab40(0x40006400,1);
    FUN_0800aa06(0x40006400,0);
    FUN_0800aa06(0x40006400,1);
    FUN_0800aa06(0x40006400,2);
    FUN_0800ad10(0x40006400,0x30f00070);
    iVar3 = extraout_r1;
    iVar4 = extraout_r2;
    uVar5 = extraout_r3;
  }
  if (0x31 < _DAT_2000038c) {
    FUN_0801b748((uint)_DAT_2000038c,iVar3,iVar4,uVar5);
    FUN_0800ab40(0x40006400,0);
    FUN_0800ab40(0x40006400,1);
    FUN_0800aa06(0x40006400,0);
    FUN_0800aa06(0x40006400,1);
    FUN_0800aa06(0x40006400,2);
    FUN_0800ad10(0x40006400,0x30f00070);
  }
  if (param_2 == 1) {
    local_30 = 4;
    local_34 = param_1;
  }
  else {
    local_30 = 0;
    local_38 = param_1;
  }
  local_2e = (undefined1)param_4;
  local_2f = 0;
  for (uVar6 = 0; uVar6 < 8; uVar6 = uVar6 + 1 & 0xff) {
    local_2d[uVar6] = *(undefined1 *)(param_3 + uVar6);
  }
  iVar3 = FUN_0800a856(0x40006400,(ushort *)&local_38);
  sVar2 = 0xfff;
  while( true ) {
    cVar1 = FUN_0800a97c(0x40006400,iVar3);
    if (cVar1 == '\x01') {
      _DAT_2000038a = 0;
      _DAT_2000038c = 0;
      return 0;
    }
    if (cVar1 == '\0') break;
    sVar2 = sVar2 + -1;
    if (sVar2 == 0) {
      _DAT_2000038c = _DAT_2000038c + 1;
      if (299 < _DAT_2000038c) {
        _DAT_2000038c = 300;
      }
      return 0;
    }
  }
  if ((ushort)(_DAT_2000038a + 1) < 300) {
    _DAT_2000038a = _DAT_2000038a + 1;
    return 0;
  }
  _DAT_2000038a = 300;
  return 0;
}

