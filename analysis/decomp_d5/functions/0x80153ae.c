// rea decompile_all
// name: FUN_080153ae
// address: 0x80153ae
// body: available
// range: 0x80153ae-0x80154d7 inclusive
// range: 0x8015528-0x8015593 inclusive
// range: 0x8015596-0x8015953 inclusive
// range: 0x801598c-0x8015abb inclusive
// range: 0x8015aca-0x8015bb3 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_080153ae(void)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  undefined4 auStack_30 [7];
  
  FUN_0801ce64(auStack_30,(undefined4 *)&DAT_0801d51c,0x1c);
  if (_DAT_200004ca == 0) {
    if (((_DAT_20000034 < 0x1f5) || (_DAT_20000036 < 0x1f5)) && (DAT_20000389 != '\x03')) {
      if ((_DAT_20000036 < 0x1f5) || ((DAT_200002d3 & 4) != 4)) {
        if (_DAT_20000036 < 0x1f5) {
          if ((_DAT_20000034 < 0x1f5) || ((DAT_200002d3 & 4) != 4)) {
            if (_DAT_20000034 < 0x1f5) {
              if ((DAT_200002d3 & 4) == 4) {
                if (DAT_200004cc != '\x05') {
                  DAT_200004cc = '\x05';
                  _DAT_2000138c = 0xff0000;
                  _DAT_20001390 = 0;
                  DAT_200013c8 = 2;
                  DAT_200013c9 = 0;
                  DAT_200013d8 = 0;
                  _DAT_200013cc = 0xf;
                  DAT_200013d0 = 100;
                  DAT_200013da = 2;
                  FUN_08010f6c((undefined4 *)0x200013d4);
                  bVar1 = FUN_0801165a(0);
                  uVar2 = FUN_08011660(0xff0000);
                  uVar3 = FUN_08011668(0xff0000);
                  FUN_08011730(uVar3,uVar2,(uint)bVar1);
                }
              }
              else if (((DAT_20000297 == '\0') && ((DAT_200002d3 & 0x8b) == 0)) &&
                      ((DAT_200002de & 0x8b) == 0)) {
                if (_DAT_200002da < 0x23) {
                  if (DAT_200004cc != '\x04') {
                    DAT_200004cc = '\x04';
                    _DAT_2000138c = 0xff0000;
                    _DAT_20001390 = 0;
                    DAT_200013c8 = 2;
                    DAT_200013c9 = 0;
                    DAT_200013d8 = 0;
                    _DAT_200013cc = 0xf;
                    DAT_200013d0 = 100;
                    DAT_200013da = 0;
                    FUN_08010f6c((undefined4 *)0x200013d4);
                  }
                }
                else if ((_DAT_200002da < 0x23) || (0x2b < _DAT_200002da)) {
                  if ((_DAT_200002da < 0x2c) || (0x84 < _DAT_200002da)) {
                    if ((_DAT_200002da < 0x85) || (0xd48 < _DAT_200002da)) {
                      if (DAT_20000388 == '\x01') {
                        if (DAT_200004cc != '\t') {
                          DAT_200004cc = '\t';
                          FUN_08011730(0,0,0);
                          _DAT_2000138c = 0xf5424;
                          _DAT_20001390 = 0;
                          DAT_200013c8 = 2;
                          DAT_200013c9 = 0;
                          DAT_200013d8 = 0;
                          _DAT_200013cc = 0x12;
                          DAT_200013d0 = 100;
                          DAT_200013da = 2;
                          FUN_08010f6c((undefined4 *)0x200013d4);
                          _DAT_2000165c = 0xf5424;
                          _DAT_20001694 = 0;
                          DAT_20001698 = 1;
                          DAT_20001699 = 0;
                          DAT_200016a9 = 0;
                          DAT_200016a8 = 0;
                          _DAT_2000169c = 8;
                          DAT_200016a0 = 100;
                          DAT_200016aa = 2;
                          FUN_08010f6c((undefined4 *)0x200016a4);
                        }
                      }
                      else if (DAT_200004cc != '\0') {
                        DAT_200004cc = '\0';
                        FUN_08012570(0xb);
                      }
                    }
                    else if (DAT_200004cc != '\x01') {
                      DAT_200004cc = '\x01';
                      FUN_0801179a(6,0,0);
                    }
                  }
                  else if (DAT_200004cc != '\x02') {
                    DAT_200004cc = '\x02';
                    FUN_0801179a(3,0,0);
                  }
                }
                else if (DAT_200004cc != '\x03') {
                  DAT_200004cc = '\x03';
                  _DAT_2000138c = FUN_08011670((uint)DAT_20000322,0xff0000);
                  _DAT_20001390 = 0;
                  _DAT_20001394 = FUN_08011670((uint)DAT_20000322,0xff7f00);
                  _DAT_20001398 = 0;
                  _DAT_2000139c = FUN_08011670((uint)DAT_20000322,0xffff00);
                  _DAT_200013a0 = 0;
                  _DAT_200013a4 = FUN_08011670((uint)DAT_20000322,0xff00);
                  _DAT_200013a8 = 0;
                  _DAT_200013ac = FUN_08011670((uint)DAT_20000322,0xffff);
                  _DAT_200013b0 = 0;
                  _DAT_200013b4 = FUN_08011670((uint)DAT_20000322,0xff);
                  _DAT_200013b8 = 0;
                  _DAT_200013bc = FUN_08011670((uint)DAT_20000322,0xff00ff);
                  _DAT_200013c0 = 0;
                  DAT_200013c8 = 0xe;
                  DAT_200013c9 = 0;
                  DAT_200013d8 = 0;
                  _DAT_200013cc = 0x19;
                  DAT_200013d0 = 100;
                  DAT_200013da = 0;
                  FUN_08010f6c((undefined4 *)0x200013d4);
                }
              }
              else if (DAT_200004cc != '\n') {
                DAT_200004cc = '\n';
                FUN_08011730(0,0,0);
                _DAT_2000142c = 0xff0000;
                DAT_20001468 = 1;
                DAT_20001469 = 0;
                DAT_20001479 = 0;
                DAT_20001478 = 0;
                _DAT_2000146c = 1;
                DAT_20001470 = 100;
                DAT_2000147a = 0;
                FUN_08010f6c((undefined4 *)0x20001474);
              }
            }
            else if (DAT_200004cc != '\x06') {
              DAT_200004cc = '\x06';
              FUN_08011730(0,0,0);
              _DAT_2000160c = FUN_08011670((uint)DAT_20000322,0xff7f00);
              _DAT_20001644 = 0;
              DAT_20001648 = 1;
              DAT_20001649 = 0;
              DAT_20001659 = 0;
              DAT_20001658 = 1;
              _DAT_2000164c = 6;
              DAT_20001650 = 100;
              DAT_2000165a = 2;
              FUN_08010f6c((undefined4 *)0x20001654);
              _DAT_200013dc = FUN_08011670((uint)DAT_20000322,0xff7f00);
              _DAT_200013e0 = 0;
              DAT_20001418 = 2;
              DAT_20001419 = 0;
              DAT_20001428 = 0;
              _DAT_2000141c = 0xd;
              DAT_20001420 = 100;
              DAT_2000142a = 3;
              FUN_08010f6c((undefined4 *)0x20001424);
            }
          }
          else if (DAT_200004cc != '\f') {
            DAT_200004cc = '\f';
            FUN_08011730(0,0,0);
            _DAT_2000160c = FUN_08011670((uint)DAT_20000322,0xff0000);
            _DAT_20001644 = 0;
            DAT_20001648 = 1;
            DAT_20001649 = 0;
            DAT_20001659 = 0;
            DAT_20001658 = 1;
            _DAT_2000164c = 6;
            DAT_20001650 = 100;
            DAT_2000165a = 2;
            FUN_08010f6c((undefined4 *)0x20001654);
            _DAT_200013dc = FUN_08011670((uint)DAT_20000322,0xff0000);
            _DAT_200013e0 = 0;
            DAT_20001418 = 2;
            DAT_20001419 = 0;
            DAT_20001428 = 0;
            _DAT_2000141c = 0xd;
            DAT_20001420 = 100;
            DAT_2000142a = 3;
            FUN_08010f6c((undefined4 *)0x20001424);
          }
        }
        else if (DAT_200004cc != '\a') {
          DAT_200004cc = '\a';
          FUN_08011730(0,0,0);
          _DAT_2000160c = FUN_08011670((uint)DAT_20000322,0xff7f00);
          _DAT_20001644 = 0;
          DAT_20001648 = 1;
          DAT_20001649 = 0;
          DAT_20001659 = 0;
          DAT_20001658 = 0;
          _DAT_2000164c = 6;
          DAT_20001650 = 100;
          DAT_2000165a = 2;
          FUN_08010f6c((undefined4 *)0x20001654);
          _DAT_200013dc = FUN_08011670((uint)DAT_20000322,0xff7f00);
          _DAT_200013e0 = 0;
          DAT_20001418 = 2;
          DAT_20001419 = 0;
          DAT_20001428 = 0;
          _DAT_2000141c = 0xd;
          DAT_20001420 = 100;
          DAT_2000142a = 1;
          FUN_08010f6c((undefined4 *)0x20001424);
        }
      }
      else if (DAT_200004cc != '\v') {
        DAT_200004cc = '\v';
        FUN_08011730(0,0,0);
        _DAT_2000160c = FUN_08011670((uint)DAT_20000322,0xff0000);
        _DAT_20001644 = 0;
        DAT_20001648 = 1;
        DAT_20001649 = 0;
        DAT_20001659 = 0;
        DAT_20001658 = 0;
        _DAT_2000164c = 6;
        DAT_20001650 = 100;
        DAT_2000165a = 2;
        FUN_08010f6c((undefined4 *)0x20001654);
        _DAT_200013dc = FUN_08011670((uint)DAT_20000322,0xff0000);
        _DAT_200013e0 = 0;
        DAT_20001418 = 2;
        DAT_20001419 = 0;
        DAT_20001428 = 0;
        _DAT_2000141c = 0xd;
        DAT_20001420 = 100;
        DAT_2000142a = 1;
        FUN_08010f6c((undefined4 *)0x20001424);
      }
    }
    else if (DAT_200004cc != '\b') {
      DAT_200004cc = '\b';
      FUN_08011730(0,0,0);
      _DAT_200013dc = FUN_08011670((uint)DAT_20000322,0xff7f00);
      _DAT_200013e0 = 0;
      DAT_20001418 = 2;
      DAT_20001419 = 0;
      DAT_20001428 = 0;
      _DAT_2000141c = 0x19;
      DAT_20001420 = 100;
      DAT_2000142a = 0;
      FUN_08010f6c((undefined4 *)0x20001424);
    }
  }
  else {
    if (DAT_200004cc != '\r') {
      DAT_200004cc = '\r';
      FUN_08011730(0,0,0);
      _DAT_200016fc = 0x99ff;
      DAT_20001738 = 1;
      DAT_20001739 = 0;
      DAT_20001748 = 0;
      _DAT_2000173c = 4;
      DAT_20001740 = 100;
      DAT_2000174a = 0;
      FUN_08010f6c((undefined4 *)0x20001744);
    }
    _DAT_200004ca = _DAT_200004ca + 1;
    if (0xf9 < _DAT_200004ca) {
      _DAT_200004ca = 0;
    }
  }
  _DAT_200004c8 = _DAT_200004c8 + 1;
  switch(DAT_200004cc) {
  case '\0':
  case '\x01':
  case '\x02':
  case '\x03':
  case '\x04':
  case '\t':
    if (DAT_200004cd != '\0') {
      DAT_200004cd = '\0';
      FUN_08011730((uint)DAT_20000319,(uint)DAT_2000031a,(uint)DAT_2000031b);
    }
    if (DAT_20000317 == '\0') {
      FUN_08013294();
    }
    else {
      FUN_08015252();
    }
    break;
  case '\x05':
    DAT_200004cd = '\x01';
    DAT_2000043c = 0xff;
    FUN_08013294();
    FUN_080144aa();
    break;
  case '\x06':
  case '\f':
    DAT_200004cd = '\x01';
    DAT_2000043c = 0xff;
    FUN_08013294();
    if ((uint)_DAT_200004c8 == ((int)(uint)_DAT_200004c8 >> 1) * 2) {
      FUN_08013e8c();
    }
    else {
      FUN_080140b4();
    }
    break;
  case '\a':
  case '\v':
    DAT_200004cd = '\x01';
    DAT_2000043c = 0xff;
    FUN_08013294();
    if ((uint)_DAT_200004c8 == ((int)(uint)_DAT_200004c8 >> 1) * 2) {
      FUN_08013e8c();
    }
    else {
      FUN_080140b4();
    }
    break;
  case '\b':
    DAT_200004cd = '\x01';
    DAT_2000043c = 0xff;
    FUN_08013294();
    FUN_08013e8c();
    break;
  case '\n':
    DAT_200004cd = '\x01';
    DAT_2000043c = 0xff;
    FUN_08013c1e();
    break;
  case '\r':
    DAT_200004cd = '\x01';
    DAT_2000043c = 0xff;
    FUN_08013836();
  }
  return;
}

