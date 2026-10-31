// rea decompile_all
// name: FUN_08016560
// address: 0x8016560
// body: available
// range: 0x8016560-0x8016631 inclusive
// range: 0x8016698-0x8016851 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08016560(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = 0xe;
  iVar1 = FUN_080131e2((uint *)0x200016a4,_DAT_2000169c);
  if (iVar1 == 1) {
    FUN_080131dc((undefined4 *)0x200016a4);
    if (DAT_200016a9 == '\0') {
      if (DAT_200004af < 0x14) {
        uVar3 = FUN_08011668(0xff0000);
        DAT_200004a8 = (undefined1)uVar3;
        uVar3 = FUN_08011660(0xff0000);
        DAT_200004a9 = (undefined1)uVar3;
        DAT_200004aa = FUN_0801165a(0);
        _DAT_2000138c = 0xff0000;
        _DAT_20001390 = 0;
      }
      else if (DAT_200004af < 0x32) {
        uVar3 = FUN_08011668(0xffff00);
        DAT_200004a8 = (undefined1)uVar3;
        uVar3 = FUN_08011660(0xffff00);
        DAT_200004a9 = (undefined1)uVar3;
        DAT_200004aa = FUN_0801165a(0);
        _DAT_2000138c = 0xffff00;
        _DAT_20001390 = 0;
      }
      else if (DAT_200004af < 100) {
        uVar3 = FUN_08011668(0x99ff);
        DAT_200004a8 = (undefined1)uVar3;
        uVar3 = FUN_08011660(0x99ff);
        DAT_200004a9 = (undefined1)uVar3;
        DAT_200004aa = FUN_0801165a(0xff);
        _DAT_2000138c = 0xf5424;
        _DAT_20001390 = 0;
      }
      else {
        uVar3 = FUN_08011668(0x99ff);
        DAT_200004a8 = (undefined1)uVar3;
        uVar3 = FUN_08011660(0x99ff);
        DAT_200004a9 = (undefined1)uVar3;
        DAT_200004aa = FUN_0801165a(0xff);
        _DAT_2000138c = 0x99ff;
        _DAT_20001390 = 0x99ff;
      }
      uVar3 = FUN_08011668(_DAT_20001694);
      DAT_200004ab = (undefined1)uVar3;
      uVar3 = FUN_08011660(_DAT_20001694);
      DAT_200004ac = (undefined1)uVar3;
      DAT_200004ad = FUN_0801165a((char)_DAT_20001694);
      DAT_20001699 = DAT_20001699 + '\x01';
      DAT_200016a9 = '\x01';
    }
    _DAT_200004b0 = _DAT_200004b0 + 1;
    if (5 < _DAT_200004b0) {
      _DAT_200004b0 = 0;
      DAT_200004af = DAT_200004af + 1;
      if (100 < DAT_200004af) {
        DAT_200004af = 100;
      }
    }
    if (DAT_200004af < 100) {
      uVar3 = (int)(uint)DAT_200004af >> 3;
    }
    else {
      uVar3 = 0xe;
    }
    if (0xe < uVar3) {
      uVar3 = 0xe;
    }
    DAT_200004b2 = '\x01';
    DAT_200004b3 = 0;
    if ((DAT_200016a9 == '\x01') &&
       (DAT_200004ae = DAT_200004ae + 1, 0xe - uVar3 < (uint)DAT_200004ae)) {
      DAT_200004ae = 0;
      DAT_200016a9 = '\0';
    }
  }
  if (DAT_200004b2 != '\0') {
    if (DAT_200004b3 == 0) {
      for (uVar2 = 0; uVar2 < 0xe; uVar2 = uVar2 + 1 & 0xff) {
        if (uVar3 < uVar2) {
          if (uVar2 < 0xe - DAT_200004ae) {
            FUN_08013016();
          }
          else {
            FUN_08013016();
          }
        }
        else {
          FUN_08013016();
        }
      }
    }
    else if (DAT_200004b3 == 1) {
      for (uVar2 = 0; uVar2 < 0xe; uVar2 = uVar2 + 1 & 0xff) {
        if (uVar3 < uVar2) {
          if (uVar2 < 0xe - DAT_200004ae) {
            FUN_08012e3a();
          }
          else {
            FUN_08012e3a();
          }
        }
        else {
          FUN_08012e3a();
        }
      }
    }
    DAT_200004b3 = DAT_200004b3 + 1;
    if (1 < DAT_200004b3) {
      DAT_200004b3 = 0;
      DAT_200004b2 = '\0';
    }
  }
  return;
}

