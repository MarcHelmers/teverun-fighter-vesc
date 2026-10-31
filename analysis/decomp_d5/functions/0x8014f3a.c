// rea decompile_all
// name: FUN_08014f3a
// address: 0x8014f3a
// body: available
// range: 0x8014f3a-0x8015081 inclusive
// range: 0x80150dc-0x8015207 inclusive
// range: 0x8015212-0x8015251 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08014f3a(void)

{
  undefined4 auStack_24 [7];
  
  FUN_0801ce64(auStack_24,(undefined4 *)&DAT_0801d500,0x1c);
  if (_DAT_200002da < 0x23) {
    if (DAT_2000043c != '\x04') {
      DAT_2000043c = '\x04';
      FUN_08011730(0,0,0);
      _DAT_2000138c = FUN_08011670((uint)DAT_20000322,0xff0000);
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
          if (DAT_2000043c != '\t') {
            DAT_2000043c = '\t';
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
        else if (DAT_2000043c != '\0') {
          DAT_2000043c = '\0';
          FUN_08011730(0,0,0);
          FUN_08012570(0xb);
        }
      }
      else if (DAT_2000043c != '\x01') {
        DAT_2000043c = '\x01';
        FUN_08011730(0,0,0);
        FUN_0801179a(6,0,0);
      }
    }
    else if (DAT_2000043c != '\x02') {
      DAT_2000043c = '\x02';
      FUN_08011730(0,0,0);
      FUN_0801179a(3,0,0);
    }
  }
  else if (DAT_2000043c != '\x03') {
    DAT_2000043c = '\x03';
    FUN_08011730(0,0,0);
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
  FUN_08013294();
  _DAT_200004c2 = _DAT_200004c2 + 1;
  switch(DAT_2000043c) {
  case '\0':
    FUN_08013c1e();
    break;
  case '\x01':
    FUN_08013448();
    break;
  case '\x02':
    FUN_08013448();
    break;
  case '\x03':
    FUN_080144aa();
    break;
  case '\x04':
    FUN_080144aa();
    break;
  case '\t':
    if ((uint)_DAT_200004c2 == ((int)(uint)_DAT_200004c2 >> 1) * 2) {
      FUN_080144aa();
    }
    else {
      FUN_08014c8a();
    }
  }
  return;
}

