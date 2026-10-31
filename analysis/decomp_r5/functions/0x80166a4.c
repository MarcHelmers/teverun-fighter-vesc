// rea decompile_all
// name: FUN_080166a4
// address: 0x80166a4
// body: available
// range: 0x80166a4-0x8016775 inclusive
// range: 0x80167dc-0x8016995 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_080166a4(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = 0xe;
  iVar1 = FUN_08013326((uint *)0x200016bc,_DAT_200016b4);
  if (iVar1 == 1) {
    FUN_08013320((undefined4 *)0x200016bc);
    if (DAT_200016c1 == '\0') {
      if (DAT_200004c7 < 0x14) {
        uVar3 = FUN_080117ac(0xff0000);
        DAT_200004c0 = (undefined1)uVar3;
        uVar3 = FUN_080117a4(0xff0000);
        DAT_200004c1 = (undefined1)uVar3;
        DAT_200004c2 = FUN_0801179e(0);
        _DAT_200013a4 = 0xff0000;
        _DAT_200013a8 = 0;
      }
      else if (DAT_200004c7 < 0x32) {
        uVar3 = FUN_080117ac(0xffff00);
        DAT_200004c0 = (undefined1)uVar3;
        uVar3 = FUN_080117a4(0xffff00);
        DAT_200004c1 = (undefined1)uVar3;
        DAT_200004c2 = FUN_0801179e(0);
        _DAT_200013a4 = 0xffff00;
        _DAT_200013a8 = 0;
      }
      else if (DAT_200004c7 < 100) {
        uVar3 = FUN_080117ac(0x99ff);
        DAT_200004c0 = (undefined1)uVar3;
        uVar3 = FUN_080117a4(0x99ff);
        DAT_200004c1 = (undefined1)uVar3;
        DAT_200004c2 = FUN_0801179e(0xff);
        _DAT_200013a4 = 0xf5424;
        _DAT_200013a8 = 0;
      }
      else {
        uVar3 = FUN_080117ac(0x99ff);
        DAT_200004c0 = (undefined1)uVar3;
        uVar3 = FUN_080117a4(0x99ff);
        DAT_200004c1 = (undefined1)uVar3;
        DAT_200004c2 = FUN_0801179e(0xff);
        _DAT_200013a4 = 0x99ff;
        _DAT_200013a8 = 0x99ff;
      }
      uVar3 = FUN_080117ac(_DAT_200016ac);
      DAT_200004c3 = (undefined1)uVar3;
      uVar3 = FUN_080117a4(_DAT_200016ac);
      DAT_200004c4 = (undefined1)uVar3;
      DAT_200004c5 = FUN_0801179e((char)_DAT_200016ac);
      DAT_200016b1 = DAT_200016b1 + '\x01';
      DAT_200016c1 = '\x01';
    }
    _DAT_200004c8 = _DAT_200004c8 + 1;
    if (5 < _DAT_200004c8) {
      _DAT_200004c8 = 0;
      DAT_200004c7 = DAT_200004c7 + 1;
      if (100 < DAT_200004c7) {
        DAT_200004c7 = 100;
      }
    }
    if (DAT_200004c7 < 100) {
      uVar3 = (int)(uint)DAT_200004c7 >> 3;
    }
    else {
      uVar3 = 0xe;
    }
    if (0xe < uVar3) {
      uVar3 = 0xe;
    }
    DAT_200004ca = '\x01';
    DAT_200004cb = 0;
    if ((DAT_200016c1 == '\x01') &&
       (DAT_200004c6 = DAT_200004c6 + 1, 0xe - uVar3 < (uint)DAT_200004c6)) {
      DAT_200004c6 = 0;
      DAT_200016c1 = '\0';
    }
  }
  if (DAT_200004ca != '\0') {
    if (DAT_200004cb == 0) {
      for (uVar2 = 0; uVar2 < 0xe; uVar2 = uVar2 + 1 & 0xff) {
        if (uVar3 < uVar2) {
          if (uVar2 < 0xe - DAT_200004c6) {
            FUN_0801315a();
          }
          else {
            FUN_0801315a();
          }
        }
        else {
          FUN_0801315a();
        }
      }
    }
    else if (DAT_200004cb == 1) {
      for (uVar2 = 0; uVar2 < 0xe; uVar2 = uVar2 + 1 & 0xff) {
        if (uVar3 < uVar2) {
          if (uVar2 < 0xe - DAT_200004c6) {
            FUN_08012f7e();
          }
          else {
            FUN_08012f7e();
          }
        }
        else {
          FUN_08012f7e();
        }
      }
    }
    DAT_200004cb = DAT_200004cb + 1;
    if (1 < DAT_200004cb) {
      DAT_200004cb = 0;
      DAT_200004ca = '\0';
    }
  }
  return;
}

