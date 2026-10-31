// rea decompile_all
// name: FUN_0002d772
// address: 0x2d772
// body: available
// range: 0x2d772-0x2d80d inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


ulonglong FUN_0002d772(uint param_1,int param_2,uint param_3,uint param_4,uint param_5,int param_6,
                      int param_7)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  longlong lVar7;
  
  if (param_2 == 0) {
    uVar2 = LZCOUNT(param_1) + 0x20;
  }
  else {
    uVar2 = LZCOUNT(param_2);
  }
  uVar5 = FUN_0002dac4(param_1,param_2,uVar2);
  uVar3 = (uint)(uVar5 >> 0x20);
  if (((uint)uVar5 != 0 || param_3 != 0) || (uVar3 != 0 || param_4 != 0)) {
    if (param_3 != 0 || param_4 != 0) {
      uVar6 = FUN_0002d734(param_3,param_4,0x40 - uVar2);
      lVar7 = FUN_0002dac4(param_3,param_4,uVar2);
      uVar5 = CONCAT44(uVar3 | (uint)(uVar6 >> 0x20),(uint)uVar5 | (uint)uVar6 | (uint)(lVar7 != 0))
      ;
    }
    uVar3 = (uint)(uVar5 >> 0xb);
    iVar1 = (param_7 - uVar2) + 10;
    if (-1 < iVar1) {
      uVar2 = uVar3 + param_5;
      iVar1 = iVar1 * 0x100000 + (int)((uVar5 >> 0xb) >> 0x20) + param_6 +
              (uint)CARRY4(uVar3,param_5);
      if ((int)uVar5 * 0x200000 < 0) {
        bVar4 = 0xfffffffe < uVar2;
        uVar2 = uVar2 + 1;
        iVar1 = iVar1 + (uint)bVar4;
        if ((uVar5 & 0x3ff) == 0) {
          uVar2 = uVar2 & 0xfffffffe;
        }
      }
      return CONCAT44(iVar1,uVar2);
    }
    uVar5 = 0;
  }
  return uVar5;
}

