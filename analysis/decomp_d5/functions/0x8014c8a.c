// rea decompile_all
// name: FUN_08014c8a
// address: 0x8014c8a
// body: available
// range: 0x8014c8a-0x8014f39 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08014c8a(void)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_080131e2((uint *)0x200016a4,_DAT_2000169c);
  if (iVar1 == 1) {
    FUN_080131dc((undefined4 *)0x200016a4);
    if (DAT_200016a9 == '\0') {
      if (DAT_2000035c < 0x14) {
        uVar2 = FUN_08011668(0xff0000);
        DAT_2000049b = (undefined1)uVar2;
        uVar2 = FUN_08011660(0xff0000);
        DAT_2000049c = (undefined1)uVar2;
        DAT_2000049d = FUN_0801165a(0);
        _DAT_2000138c = 0xff0000;
        _DAT_20001390 = 0;
      }
      else if (DAT_2000035c < 0x32) {
        uVar2 = FUN_08011668(0xffff00);
        DAT_2000049b = (undefined1)uVar2;
        uVar2 = FUN_08011660(0xffff00);
        DAT_2000049c = (undefined1)uVar2;
        DAT_2000049d = FUN_0801165a(0);
        _DAT_2000138c = 0xffff00;
        _DAT_20001390 = 0;
      }
      else if (DAT_2000035c < 100) {
        uVar2 = FUN_08011668(0x99ff);
        DAT_2000049b = (undefined1)uVar2;
        uVar2 = FUN_08011660(0x99ff);
        DAT_2000049c = (undefined1)uVar2;
        DAT_2000049d = FUN_0801165a(0xff);
        _DAT_2000138c = 0xf5424;
        _DAT_20001390 = 0;
      }
      else {
        uVar2 = FUN_08011668(0x99ff);
        DAT_2000049b = (undefined1)uVar2;
        uVar2 = FUN_08011660(0x99ff);
        DAT_2000049c = (undefined1)uVar2;
        DAT_2000049d = FUN_0801165a(0xff);
        _DAT_2000138c = 0x99ff;
        _DAT_20001390 = 0x99ff;
      }
      uVar2 = FUN_08011668(_DAT_20001694);
      DAT_2000049e = (undefined1)uVar2;
      uVar2 = FUN_08011660(_DAT_20001694);
      DAT_2000049f = (undefined1)uVar2;
      DAT_200004a0 = FUN_0801165a((char)_DAT_20001694);
      DAT_20001699 = DAT_20001699 + '\x01';
      DAT_200016a9 = '\x01';
    }
    DAT_200004a6 = '\x01';
    DAT_200004a7 = '\0';
    _DAT_200004a4 = _DAT_200004a4 + 1;
    if (5 < _DAT_200004a4) {
      _DAT_200004a4 = 0;
      DAT_200004a3 = DAT_200004a3 + 1;
      if (100 < DAT_200004a3) {
        DAT_200004a3 = 100;
      }
    }
    if (DAT_2000035c < 100) {
      DAT_200004a2 = (byte)((int)(uint)DAT_2000035c >> 3);
    }
    else {
      DAT_200004a2 = 0xe;
    }
    if (0xe < DAT_200004a2) {
      DAT_200004a2 = 0xe;
    }
    if ((DAT_200016a9 == '\x01') &&
       (DAT_200004a1 = DAT_200004a1 + 1, 0xe - DAT_200004a2 < (uint)DAT_200004a1)) {
      DAT_200004a1 = 0;
      DAT_200016a9 = '\0';
    }
  }
  if (DAT_200004a6 == '\x01') {
    if (DAT_200004a7 == '\0') {
      for (uVar2 = 0; uVar2 < 0xe; uVar2 = uVar2 + 1 & 0xff) {
        if (DAT_200004a2 < uVar2) {
          if (uVar2 < 0xe - DAT_200004a1) {
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
      DAT_200004a7 = DAT_200004a7 + '\x01';
    }
    else if (DAT_200004a7 == '\x01') {
      for (uVar2 = 0; uVar2 < 0xe; uVar2 = uVar2 + 1 & 0xff) {
        if (DAT_200004a2 < uVar2) {
          if (uVar2 < 0xe - DAT_200004a1) {
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
      DAT_200004a7 = '\0';
      DAT_200004a6 = '\0';
    }
    else {
      DAT_200004a7 = '\0';
      DAT_200004a6 = '\0';
    }
  }
  return;
}

