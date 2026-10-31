// rea decompile_all
// name: FUN_080154f2
// address: 0x80154f2
// body: available
// range: 0x80154f2-0x801561b inclusive
// range: 0x801566c-0x80156d7 inclusive
// range: 0x80156da-0x8015a97 inclusive
// range: 0x8015ad0-0x8015bff inclusive
// range: 0x8015c0e-0x8015cf7 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_080154f2(void)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  undefined4 auStack_30 [7];
  
  FUN_0801d048(auStack_30,(undefined4 *)&DAT_0801d700,0x1c);
  if (_DAT_200004e2 == 0) {
    if (((_DAT_20000034 < 0x1f5) || (_DAT_20000036 < 0x1f5)) && (DAT_20000389 != '\x03')) {
      if ((_DAT_20000036 < 0x1f5) || ((DAT_200002d3 & 4) != 4)) {
        if (_DAT_20000036 < 0x1f5) {
          if ((_DAT_20000034 < 0x1f5) || ((DAT_200002d3 & 4) != 4)) {
            if (_DAT_20000034 < 0x1f5) {
              if ((DAT_200002d3 & 4) == 4) {
                if (DAT_200004e4 != '\x05') {
                  DAT_200004e4 = '\x05';
                  _DAT_200013a4 = 0xff0000;
                  _DAT_200013a8 = 0;
                  DAT_200013e0 = 2;
                  DAT_200013e1 = 0;
                  DAT_200013f0 = 0;
                  _DAT_200013e4 = 0xf;
                  DAT_200013e8 = 100;
                  DAT_200013f2 = 2;
                  FUN_080110b0((undefined4 *)0x200013ec);
                  bVar1 = FUN_0801179e(0);
                  uVar2 = FUN_080117a4(0xff0000);
                  uVar3 = FUN_080117ac(0xff0000);
                  FUN_08011874(uVar3,uVar2,(uint)bVar1);
                }
              }
              else if (((DAT_20000297 == '\0') && ((DAT_200002d3 & 0x8b) == 0)) &&
                      ((DAT_200002de & 0x8b) == 0)) {
                if (_DAT_200002da < 0x23) {
                  if (DAT_200004e4 != '\x04') {
                    DAT_200004e4 = '\x04';
                    _DAT_200013a4 = 0xff0000;
                    _DAT_200013a8 = 0;
                    DAT_200013e0 = 2;
                    DAT_200013e1 = 0;
                    DAT_200013f0 = 0;
                    _DAT_200013e4 = 0xf;
                    DAT_200013e8 = 100;
                    DAT_200013f2 = 0;
                    FUN_080110b0((undefined4 *)0x200013ec);
                  }
                }
                else if ((_DAT_200002da < 0x23) || (0x2b < _DAT_200002da)) {
                  if ((_DAT_200002da < 0x2c) || (0x84 < _DAT_200002da)) {
                    if ((_DAT_200002da < 0x85) || (0xd48 < _DAT_200002da)) {
                      if (DAT_20000388 == '\x01') {
                        if (DAT_200004e4 != '\t') {
                          DAT_200004e4 = '\t';
                          FUN_08011874(0,0,0);
                          _DAT_200013a4 = 0xf5424;
                          _DAT_200013a8 = 0;
                          DAT_200013e0 = 2;
                          DAT_200013e1 = 0;
                          DAT_200013f0 = 0;
                          _DAT_200013e4 = 0x12;
                          DAT_200013e8 = 100;
                          DAT_200013f2 = 2;
                          FUN_080110b0((undefined4 *)0x200013ec);
                          _DAT_20001674 = 0xf5424;
                          _DAT_200016ac = 0;
                          DAT_200016b0 = 1;
                          DAT_200016b1 = 0;
                          DAT_200016c1 = 0;
                          DAT_200016c0 = 0;
                          _DAT_200016b4 = 8;
                          DAT_200016b8 = 100;
                          DAT_200016c2 = 2;
                          FUN_080110b0((undefined4 *)0x200016bc);
                        }
                      }
                      else if (DAT_200004e4 != '\0') {
                        DAT_200004e4 = '\0';
                        FUN_080126b4(0xb);
                      }
                    }
                    else if (DAT_200004e4 != '\x01') {
                      DAT_200004e4 = '\x01';
                      FUN_080118de(6,0,0);
                    }
                  }
                  else if (DAT_200004e4 != '\x02') {
                    DAT_200004e4 = '\x02';
                    FUN_080118de(3,0,0);
                  }
                }
                else if (DAT_200004e4 != '\x03') {
                  DAT_200004e4 = '\x03';
                  _DAT_200013a4 = FUN_080117b4((uint)DAT_20000322,0xff0000);
                  _DAT_200013a8 = 0;
                  _DAT_200013ac = FUN_080117b4((uint)DAT_20000322,0xff7f00);
                  _DAT_200013b0 = 0;
                  _DAT_200013b4 = FUN_080117b4((uint)DAT_20000322,0xffff00);
                  _DAT_200013b8 = 0;
                  _DAT_200013bc = FUN_080117b4((uint)DAT_20000322,0xff00);
                  _DAT_200013c0 = 0;
                  _DAT_200013c4 = FUN_080117b4((uint)DAT_20000322,0xffff);
                  _DAT_200013c8 = 0;
                  _DAT_200013cc = FUN_080117b4((uint)DAT_20000322,0xff);
                  _DAT_200013d0 = 0;
                  _DAT_200013d4 = FUN_080117b4((uint)DAT_20000322,0xff00ff);
                  _DAT_200013d8 = 0;
                  DAT_200013e0 = 0xe;
                  DAT_200013e1 = 0;
                  DAT_200013f0 = 0;
                  _DAT_200013e4 = 0x19;
                  DAT_200013e8 = 100;
                  DAT_200013f2 = 0;
                  FUN_080110b0((undefined4 *)0x200013ec);
                }
              }
              else if (DAT_200004e4 != '\n') {
                DAT_200004e4 = '\n';
                FUN_08011874(0,0,0);
                _DAT_20001444 = 0xff0000;
                DAT_20001480 = 1;
                DAT_20001481 = 0;
                DAT_20001491 = 0;
                DAT_20001490 = 0;
                _DAT_20001484 = 1;
                DAT_20001488 = 100;
                DAT_20001492 = 0;
                FUN_080110b0((undefined4 *)0x2000148c);
              }
            }
            else if (DAT_200004e4 != '\x06') {
              DAT_200004e4 = '\x06';
              FUN_08011874(0,0,0);
              _DAT_20001624 = FUN_080117b4((uint)DAT_20000322,0xff7f00);
              _DAT_2000165c = 0;
              DAT_20001660 = 1;
              DAT_20001661 = 0;
              DAT_20001671 = 0;
              DAT_20001670 = 1;
              _DAT_20001664 = 6;
              DAT_20001668 = 100;
              DAT_20001672 = 2;
              FUN_080110b0((undefined4 *)0x2000166c);
              _DAT_200013f4 = FUN_080117b4((uint)DAT_20000322,0xff7f00);
              _DAT_200013f8 = 0;
              DAT_20001430 = 2;
              DAT_20001431 = 0;
              DAT_20001440 = 0;
              _DAT_20001434 = 0xd;
              DAT_20001438 = 100;
              DAT_20001442 = 3;
              FUN_080110b0((undefined4 *)0x2000143c);
            }
          }
          else if (DAT_200004e4 != '\f') {
            DAT_200004e4 = '\f';
            FUN_08011874(0,0,0);
            _DAT_20001624 = FUN_080117b4((uint)DAT_20000322,0xff0000);
            _DAT_2000165c = 0;
            DAT_20001660 = 1;
            DAT_20001661 = 0;
            DAT_20001671 = 0;
            DAT_20001670 = 1;
            _DAT_20001664 = 6;
            DAT_20001668 = 100;
            DAT_20001672 = 2;
            FUN_080110b0((undefined4 *)0x2000166c);
            _DAT_200013f4 = FUN_080117b4((uint)DAT_20000322,0xff0000);
            _DAT_200013f8 = 0;
            DAT_20001430 = 2;
            DAT_20001431 = 0;
            DAT_20001440 = 0;
            _DAT_20001434 = 0xd;
            DAT_20001438 = 100;
            DAT_20001442 = 3;
            FUN_080110b0((undefined4 *)0x2000143c);
          }
        }
        else if (DAT_200004e4 != '\a') {
          DAT_200004e4 = '\a';
          FUN_08011874(0,0,0);
          _DAT_20001624 = FUN_080117b4((uint)DAT_20000322,0xff7f00);
          _DAT_2000165c = 0;
          DAT_20001660 = 1;
          DAT_20001661 = 0;
          DAT_20001671 = 0;
          DAT_20001670 = 0;
          _DAT_20001664 = 6;
          DAT_20001668 = 100;
          DAT_20001672 = 2;
          FUN_080110b0((undefined4 *)0x2000166c);
          _DAT_200013f4 = FUN_080117b4((uint)DAT_20000322,0xff7f00);
          _DAT_200013f8 = 0;
          DAT_20001430 = 2;
          DAT_20001431 = 0;
          DAT_20001440 = 0;
          _DAT_20001434 = 0xd;
          DAT_20001438 = 100;
          DAT_20001442 = 1;
          FUN_080110b0((undefined4 *)0x2000143c);
        }
      }
      else if (DAT_200004e4 != '\v') {
        DAT_200004e4 = '\v';
        FUN_08011874(0,0,0);
        _DAT_20001624 = FUN_080117b4((uint)DAT_20000322,0xff0000);
        _DAT_2000165c = 0;
        DAT_20001660 = 1;
        DAT_20001661 = 0;
        DAT_20001671 = 0;
        DAT_20001670 = 0;
        _DAT_20001664 = 6;
        DAT_20001668 = 100;
        DAT_20001672 = 2;
        FUN_080110b0((undefined4 *)0x2000166c);
        _DAT_200013f4 = FUN_080117b4((uint)DAT_20000322,0xff0000);
        _DAT_200013f8 = 0;
        DAT_20001430 = 2;
        DAT_20001431 = 0;
        DAT_20001440 = 0;
        _DAT_20001434 = 0xd;
        DAT_20001438 = 100;
        DAT_20001442 = 1;
        FUN_080110b0((undefined4 *)0x2000143c);
      }
    }
    else if (DAT_200004e4 != '\b') {
      DAT_200004e4 = '\b';
      FUN_08011874(0,0,0);
      _DAT_200013f4 = FUN_080117b4((uint)DAT_20000322,0xff7f00);
      _DAT_200013f8 = 0;
      DAT_20001430 = 2;
      DAT_20001431 = 0;
      DAT_20001440 = 0;
      _DAT_20001434 = 0x19;
      DAT_20001438 = 100;
      DAT_20001442 = 0;
      FUN_080110b0((undefined4 *)0x2000143c);
    }
  }
  else {
    if (DAT_200004e4 != '\r') {
      DAT_200004e4 = '\r';
      FUN_08011874(0,0,0);
      _DAT_20001714 = 0x99ff;
      DAT_20001750 = 1;
      DAT_20001751 = 0;
      DAT_20001760 = 0;
      _DAT_20001754 = 4;
      DAT_20001758 = 100;
      DAT_20001762 = 0;
      FUN_080110b0((undefined4 *)0x2000175c);
    }
    _DAT_200004e2 = _DAT_200004e2 + 1;
    if (0xf9 < _DAT_200004e2) {
      _DAT_200004e2 = 0;
    }
  }
  _DAT_200004e0 = _DAT_200004e0 + 1;
  switch(DAT_200004e4) {
  case '\0':
  case '\x01':
  case '\x02':
  case '\x03':
  case '\x04':
  case '\t':
    if (DAT_200004e5 != '\0') {
      DAT_200004e5 = '\0';
      FUN_08011874((uint)DAT_20000319,(uint)DAT_2000031a,(uint)DAT_2000031b);
    }
    if (DAT_20000317 == '\0') {
      FUN_080133d8();
    }
    else {
      FUN_08015396();
    }
    break;
  case '\x05':
    DAT_200004e5 = '\x01';
    DAT_20000454 = 0xff;
    FUN_080133d8();
    FUN_080145ee();
    break;
  case '\x06':
  case '\f':
    DAT_200004e5 = '\x01';
    DAT_20000454 = 0xff;
    FUN_080133d8();
    if ((uint)_DAT_200004e0 == ((int)(uint)_DAT_200004e0 >> 1) * 2) {
      FUN_08013fd0();
    }
    else {
      FUN_080141f8();
    }
    break;
  case '\a':
  case '\v':
    DAT_200004e5 = '\x01';
    DAT_20000454 = 0xff;
    FUN_080133d8();
    if ((uint)_DAT_200004e0 == ((int)(uint)_DAT_200004e0 >> 1) * 2) {
      FUN_08013fd0();
    }
    else {
      FUN_080141f8();
    }
    break;
  case '\b':
    DAT_200004e5 = '\x01';
    DAT_20000454 = 0xff;
    FUN_080133d8();
    FUN_08013fd0();
    break;
  case '\n':
    DAT_200004e5 = '\x01';
    DAT_20000454 = 0xff;
    FUN_08013d62();
    break;
  case '\r':
    DAT_200004e5 = '\x01';
    DAT_20000454 = 0xff;
    FUN_0801397a();
  }
  return;
}

