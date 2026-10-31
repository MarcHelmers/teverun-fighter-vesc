// rea decompile_all
// name: FUN_08014dce
// address: 0x8014dce
// body: available
// range: 0x8014dce-0x801507d inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08014dce(void)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_08013326((uint *)0x200016bc,_DAT_200016b4);
  if (iVar1 == 1) {
    FUN_08013320((undefined4 *)0x200016bc);
    if (DAT_200016c1 == '\0') {
      if (DAT_2000035c < 0x14) {
        uVar2 = FUN_080117ac(0xff0000);
        DAT_200004b3 = (undefined1)uVar2;
        uVar2 = FUN_080117a4(0xff0000);
        DAT_200004b4 = (undefined1)uVar2;
        DAT_200004b5 = FUN_0801179e(0);
        _DAT_200013a4 = 0xff0000;
        _DAT_200013a8 = 0;
      }
      else if (DAT_2000035c < 0x32) {
        uVar2 = FUN_080117ac(0xffff00);
        DAT_200004b3 = (undefined1)uVar2;
        uVar2 = FUN_080117a4(0xffff00);
        DAT_200004b4 = (undefined1)uVar2;
        DAT_200004b5 = FUN_0801179e(0);
        _DAT_200013a4 = 0xffff00;
        _DAT_200013a8 = 0;
      }
      else if (DAT_2000035c < 100) {
        uVar2 = FUN_080117ac(0x99ff);
        DAT_200004b3 = (undefined1)uVar2;
        uVar2 = FUN_080117a4(0x99ff);
        DAT_200004b4 = (undefined1)uVar2;
        DAT_200004b5 = FUN_0801179e(0xff);
        _DAT_200013a4 = 0xf5424;
        _DAT_200013a8 = 0;
      }
      else {
        uVar2 = FUN_080117ac(0x99ff);
        DAT_200004b3 = (undefined1)uVar2;
        uVar2 = FUN_080117a4(0x99ff);
        DAT_200004b4 = (undefined1)uVar2;
        DAT_200004b5 = FUN_0801179e(0xff);
        _DAT_200013a4 = 0x99ff;
        _DAT_200013a8 = 0x99ff;
      }
      uVar2 = FUN_080117ac(_DAT_200016ac);
      DAT_200004b6 = (undefined1)uVar2;
      uVar2 = FUN_080117a4(_DAT_200016ac);
      DAT_200004b7 = (undefined1)uVar2;
      DAT_200004b8 = FUN_0801179e((char)_DAT_200016ac);
      DAT_200016b1 = DAT_200016b1 + '\x01';
      DAT_200016c1 = '\x01';
    }
    DAT_200004be = '\x01';
    DAT_200004bf = '\0';
    _DAT_200004bc = _DAT_200004bc + 1;
    if (5 < _DAT_200004bc) {
      _DAT_200004bc = 0;
      DAT_200004bb = DAT_200004bb + 1;
      if (100 < DAT_200004bb) {
        DAT_200004bb = 100;
      }
    }
    if (DAT_2000035c < 100) {
      DAT_200004ba = (byte)((int)(uint)DAT_2000035c >> 3);
    }
    else {
      DAT_200004ba = 0xe;
    }
    if (0xe < DAT_200004ba) {
      DAT_200004ba = 0xe;
    }
    if ((DAT_200016c1 == '\x01') &&
       (DAT_200004b9 = DAT_200004b9 + 1, 0xe - DAT_200004ba < (uint)DAT_200004b9)) {
      DAT_200004b9 = 0;
      DAT_200016c1 = '\0';
    }
  }
  if (DAT_200004be == '\x01') {
    if (DAT_200004bf == '\0') {
      for (uVar2 = 0; uVar2 < 0xe; uVar2 = uVar2 + 1 & 0xff) {
        if (DAT_200004ba < uVar2) {
          if (uVar2 < 0xe - DAT_200004b9) {
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
      DAT_200004bf = DAT_200004bf + '\x01';
    }
    else if (DAT_200004bf == '\x01') {
      for (uVar2 = 0; uVar2 < 0xe; uVar2 = uVar2 + 1 & 0xff) {
        if (DAT_200004ba < uVar2) {
          if (uVar2 < 0xe - DAT_200004b9) {
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
      DAT_200004bf = '\0';
      DAT_200004be = '\0';
    }
    else {
      DAT_200004bf = '\0';
      DAT_200004be = '\0';
    }
  }
  return;
}

