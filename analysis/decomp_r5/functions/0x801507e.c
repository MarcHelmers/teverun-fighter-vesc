// rea decompile_all
// name: FUN_0801507e
// address: 0x801507e
// body: available
// range: 0x801507e-0x80151c5 inclusive
// range: 0x8015220-0x801534b inclusive
// range: 0x8015356-0x8015395 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0801507e(void)

{
  undefined4 auStack_24 [7];
  
  FUN_0801d048(auStack_24,(undefined4 *)&DAT_0801d6e4,0x1c);
  if (_DAT_200002da < 0x23) {
    if (DAT_20000454 != '\x04') {
      DAT_20000454 = '\x04';
      FUN_08011874(0,0,0);
      _DAT_200013a4 = FUN_080117b4((uint)DAT_20000322,0xff0000);
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
          if (DAT_20000454 != '\t') {
            DAT_20000454 = '\t';
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
        else if (DAT_20000454 != '\0') {
          DAT_20000454 = '\0';
          FUN_08011874(0,0,0);
          FUN_080126b4(0xb);
        }
      }
      else if (DAT_20000454 != '\x01') {
        DAT_20000454 = '\x01';
        FUN_08011874(0,0,0);
        FUN_080118de(6,0,0);
      }
    }
    else if (DAT_20000454 != '\x02') {
      DAT_20000454 = '\x02';
      FUN_08011874(0,0,0);
      FUN_080118de(3,0,0);
    }
  }
  else if (DAT_20000454 != '\x03') {
    DAT_20000454 = '\x03';
    FUN_08011874(0,0,0);
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
  FUN_080133d8();
  _DAT_200004da = _DAT_200004da + 1;
  switch(DAT_20000454) {
  case '\0':
    FUN_08013d62();
    break;
  case '\x01':
    FUN_0801358c();
    break;
  case '\x02':
    FUN_0801358c();
    break;
  case '\x03':
    FUN_080145ee();
    break;
  case '\x04':
    FUN_080145ee();
    break;
  case '\t':
    if ((uint)_DAT_200004da == ((int)(uint)_DAT_200004da >> 1) * 2) {
      FUN_080145ee();
    }
    else {
      FUN_08014dce();
    }
  }
  return;
}

