// rea decompile_all
// name: FUN_00013e90
// address: 0x13e90
// body: available
// range: 0x13e90-0x13fb3 inclusive
// range: 0x13fb8-0x141cf inclusive
// range: 0x141d6-0x14ba9 inclusive
// range: 0x14bb0-0x14ed3 inclusive
// range: 0x14eda-0x14f65 inclusive
// range: 0x14f6c-0x15025 inclusive
// range: 0x1502e-0x151f1 inclusive
// range: 0x151f6-0x15849 inclusive
// range: 0x15852-0x15b11 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void FUN_00013e90(void)

{
  short sVar1;
  short sVar2;
  char cVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  char local_12;
  char local_11;
  bool local_10;
  char local_f;
  char local_e;
  char local_d;
  
  local_d = '\0';
  local_e = '\0';
  local_10 = false;
  if ((DAT_2000053f != DAT_2000053e) || (DAT_2000000c != DAT_20000579)) {
    DAT_2000053f = DAT_2000053e;
    DAT_2000000c = DAT_20000579;
    FUN_00013acc(3);
    DAT_20000034 = -1;
    DAT_20000037 = -1;
    DAT_2000003e = -1;
    DAT_20000035 = 0xff;
    DAT_20000040 = -1;
    DAT_2000003f = -1;
    DAT_20000036 = -1;
    DAT_20000038 = -1;
    DAT_20000039 = -1;
    DAT_2000003a = -1;
    DAT_2000003b = 0xff;
    DAT_2000003d = -1;
    DAT_2000003c = -1;
    DAT_20000014 = 1;
    DAT_200005bb = '\x01';
    switch(DAT_2000000c) {
    case 0:
      FUN_00024ee8((byte *)0x200017c4,DAT_00056b14,0x56b08);
      FUN_00024e48((byte *)0x200017c4,DAT_00056b14);
      break;
    case 1:
      FUN_00024ee8((byte *)0x200017c4,DAT_00056b00,0x56af4);
      FUN_00024e48((byte *)0x200017c4,DAT_00056b00);
      break;
    case 2:
      FUN_00024ee8((byte *)0x200017c4,DAT_00056aec,0x56ae0);
      FUN_00024e48((byte *)0x200017c4,DAT_00056aec);
      break;
    case 3:
      FUN_00024ee8((byte *)0x200017c4,DAT_00056ad8,0x56acc);
      FUN_00024e48((byte *)0x200017c4,DAT_00056ad8);
    }
    FUN_00021220();
  }
  DAT_20000c9d = DAT_20000c9d + 1;
  if ((DAT_20000c9d & 1) == 0) {
    if (DAT_20000bad == '\0') {
      local_12 = '\0';
    }
    else if (DAT_20000c1f == '\0') {
      if (((_DAT_20000c0e == 0) && (DAT_20000bca == '\x01')) && (DAT_20000c21 == '\x01')) {
        local_12 = '\x01';
      }
      else if (((_DAT_20000c0e == 0) && (DAT_20000bca == '\x01')) && (DAT_20000c21 == '\0')) {
        local_12 = '\x02';
      }
      else {
        if (_DAT_20000c0e != 0) {
          DAT_20000bca = '\0';
        }
        local_12 = '\0';
      }
    }
    else {
      local_12 = '\0';
    }
    if (DAT_2000003c != local_12) {
      DAT_2000003c = local_12;
      if (local_12 == '\0') {
        FUN_00020428(0);
        FUN_0001e1ec((undefined4 *)0x3e668);
        FUN_0001f1e8(0x80,0x30,(byte *)0x56c70);
      }
      else if (local_12 == '\x01') {
        FUN_0002040c(0x7e0);
        FUN_00020428(0);
        FUN_0001e1ec((undefined4 *)0x3e668);
        FUN_0001f1e8(0x80,0x30,(byte *)0x56d9b);
      }
      else if (local_12 == '\x02') {
        FUN_0002040c(0xf800);
        FUN_00020428(0);
        FUN_0001e1ec((undefined4 *)0x3e668);
        FUN_0001f1e8(0x80,0x30,(byte *)0x56d9b);
      }
    }
    FUN_0002040c(0xffff);
    FUN_00020428(0);
    if (DAT_20000bc5 < 100) {
      if (DAT_20000bc5 < 10) {
        DAT_20001718 = ' ';
        DAT_20001719 = DAT_20000bc5 + 0x30;
      }
      else {
        DAT_20001718 = DAT_20000bc5 / 10 + 0x30;
        DAT_20001719 = DAT_20000bc5 % 10 | 0x30;
      }
      DAT_20001717 = 0x20;
    }
    else {
      DAT_20001717 = 0x31;
      DAT_20001718 = '0';
      DAT_20001719 = 0x30;
    }
    DAT_2000171b = 0;
    DAT_2000171a = 0x25;
    FUN_0001e1ec((undefined4 *)0x3e67c);
    FUN_0001f1e8(0x112,0x3d,&DAT_20001717);
    if (DAT_20000ba4 == '\0') {
      if (DAT_20000c25 == '\0') {
        local_10 = _DAT_20000c14 < 1000;
        if (local_10) {
          DAT_20001700 = (byte)(_DAT_20000c14 / 100);
          DAT_20001701 = (byte)(((uint)_DAT_20000c14 % 100) / 10);
          DAT_20001702 = (char)_DAT_20000c14 + (char)(_DAT_20000c14 / 10) * -10;
        }
        else {
          DAT_20001700 = (byte)(_DAT_20000c14 / 1000);
          DAT_20001701 = (byte)(((uint)_DAT_20000c14 % 1000) / 100);
          DAT_20001702 = (byte)(((uint)_DAT_20000c14 % 100) / 10);
        }
      }
      else {
        local_10 = _DAT_20000c12 < 1000;
        if (local_10) {
          DAT_20001700 = (byte)(_DAT_20000c12 / 100);
          DAT_20001701 = (byte)(((uint)_DAT_20000c12 % 100) / 10);
          DAT_20001702 = (char)_DAT_20000c12 + (char)(_DAT_20000c12 / 10) * -10;
        }
        else {
          DAT_20001700 = (byte)(_DAT_20000c12 / 1000);
          DAT_20001701 = (byte)(((uint)_DAT_20000c12 % 1000) / 100);
          DAT_20001702 = (byte)(((uint)_DAT_20000c12 % 100) / 10);
        }
      }
      local_10 = !local_10;
    }
    else {
      _DAT_20000c12 = 0;
      _DAT_20000c0e = 0;
    }
    FUN_0001e1ec((undefined4 *)0x3e6e0);
    FUN_0001f33c(*(byte *)(DAT_20001700 + 0x56e8f),0x14,0x9c,0xffff,0);
    FUN_0001f33c(*(byte *)(DAT_20001701 + 0x56e8f),0x80,0x9c,0xffff,0);
    FUN_0001e1ec((undefined4 *)0x3e6cc);
    FUN_0001f33c(*(byte *)(DAT_20001702 + 0x56e8f),0x10e,0xa0,0xffff,0);
    if (local_10) {
      FUN_0001e294(0xf6,0xe1,0x103,0xee,0);
    }
    else {
      FUN_0001e294(0xf6,0xe1,0x103,0xee,0xffff);
    }
    if (DAT_20000c25 == '\0') {
      FUN_0001e1ec((undefined4 *)0x3e67c);
      FUN_0001f1e8(0xf8,0xf4,&DAT_00056e6b);
    }
    else {
      FUN_0001e1ec((undefined4 *)0x3e67c);
      FUN_0001f1e8(0xf8,0xf4,&DAT_00056e83);
    }
    switch(DAT_200001ae) {
    case 0:
      FUN_00015b14((char *)0x20001703);
      FUN_00015e18((char *)0x2000170d);
      FUN_0002040c(0);
      FUN_00020428(*(undefined2 *)((uint)DAT_20000579 * 2 + 0x3e852));
      FUN_0001e1ec((undefined4 *)0x3e6b8);
      FUN_0001f1e8(0x1e,0x140,(byte *)0x56e0b);
      FUN_0001f1e8(0x1e,0x16c,(byte *)0x56dff);
      FUN_0001e1ec((undefined4 *)0x3e690);
      FUN_0001f1e8(0xb7,0x143,(byte *)0x20001703);
      FUN_0001f1e8(0xb7,0x16f,(byte *)0x2000170d);
      FUN_0002040c(0xffff);
      FUN_00020428(0);
      break;
    case 1:
      FUN_00016100((undefined1 *)0x20001703);
      FUN_00016370((undefined1 *)0x2000170d);
      FUN_0002040c(0);
      FUN_00020428(*(undefined2 *)((uint)DAT_20000579 * 2 + 0x3e852));
      FUN_0001e1ec((undefined4 *)0x3e6b8);
      FUN_0001f1e8(0x1e,0x140,(byte *)0x56e17);
      FUN_0001f1e8(0x1e,0x16c,(byte *)0x56e23);
      FUN_0001e1ec((undefined4 *)0x3e690);
      FUN_0001f1e8(0xb7,0x143,(byte *)0x20001703);
      FUN_0001f1e8(0xb7,0x16f,(byte *)0x2000170d);
      FUN_0002040c(0xffff);
      FUN_00020428(0);
      break;
    case 2:
      FUN_000165e0((undefined1 *)0x20001703);
      FUN_000166d8((undefined1 *)0x2000170d);
      FUN_0002040c(0);
      FUN_00020428(*(undefined2 *)((uint)DAT_20000579 * 2 + 0x3e852));
      FUN_0001e1ec((undefined4 *)0x3e6b8);
      FUN_0001f1e8(0x1e,0x140,(byte *)0x56e3b);
      FUN_0001f1e8(0x1e,0x16c,(byte *)0x56e2f);
      FUN_0001e1ec((undefined4 *)0x3e690);
      FUN_0001f1e8(0xb7,0x143,(byte *)0x20001703);
      FUN_0001f1e8(0xb7,0x16f,(byte *)0x2000170d);
      FUN_0002040c(0xffff);
      FUN_00020428(0);
      break;
    case 3:
      FUN_000167d0((undefined1 *)0x20001703);
      FUN_000168ec((undefined1 *)0x2000170d);
      FUN_0002040c(0);
      FUN_00020428(*(undefined2 *)((uint)DAT_20000579 * 2 + 0x3e852));
      FUN_0001e1ec((undefined4 *)0x3e6b8);
      FUN_0001f1e8(0x1e,0x140,(byte *)0x56e53);
      FUN_0001f1e8(0x1e,0x16c,(byte *)0x56e47);
      FUN_0001e1ec((undefined4 *)0x3e690);
      FUN_0001f1e8(0xb7,0x143,(byte *)0x20001703);
      FUN_0001f1e8(0xb7,0x16f,(byte *)0x2000170d);
      FUN_0002040c(0xffff);
      FUN_00020428(0);
    }
  }
  else {
    if (DAT_20000034 != DAT_20000bd3) {
      DAT_20000034 = DAT_20000bd3;
      if (DAT_20000bd3 == '\0') {
        FUN_00024e98((byte *)0x200017c4,DAT_00056a88);
      }
      else {
        FUN_00024e48((byte *)0x200017c4,DAT_00056a88);
      }
    }
    if (DAT_20000c19 == '\x02') {
      DAT_20000c9b = DAT_20000c9b + 1;
      if (2 < DAT_20000c9b) {
        DAT_20000c9b = 0;
        DAT_20000c9c = DAT_20000c9c == '\0';
        if ((bool)DAT_20000c9c) {
          local_d = '\x01';
        }
        else {
          local_d = '\x02';
        }
      }
    }
    else if (DAT_20000c19 == '\x01') {
      local_d = '\x03';
    }
    else if (DAT_20000bc5 < 10) {
      local_d = '\x04';
    }
    else if (DAT_20000bc5 < 0x1e) {
      local_d = '\x05';
    }
    else {
      local_d = '\x06';
    }
    if (DAT_20000037 != local_d) {
      DAT_20000037 = local_d;
      switch(local_d) {
      case '\x01':
        FUN_00024ee8((byte *)0x200017c4,DAT_00056a38,0x56a2c);
        FUN_00024e48((byte *)0x200017c4,DAT_00056a38);
        break;
      case '\x02':
        FUN_00024ee8((byte *)0x200017c4,DAT_00056a38,0x56a2c);
        FUN_00024e98((byte *)0x200017c4,DAT_00056a38);
        break;
      case '\x03':
        FUN_00024ee8((byte *)0x200017c4,DAT_00056a38,0x56a2c);
        FUN_00024e48((byte *)0x200017c4,DAT_00056a38);
        break;
      case '\x04':
        FUN_00024ee8((byte *)0x200017c4,DAT_00056a4c,0x56a40);
        FUN_00024e48((byte *)0x200017c4,DAT_00056a4c);
        break;
      case '\x05':
        FUN_00024ee8((byte *)0x200017c4,DAT_00056a60,0x56a54);
        FUN_00024e48((byte *)0x200017c4,DAT_00056a60);
        break;
      case '\x06':
        FUN_00024ee8((byte *)0x200017c4,DAT_00056a74,0x56a68);
        FUN_00024e48((byte *)0x200017c4,DAT_00056a74);
      }
    }
    sVar2 = _DAT_00056a4e;
    if (DAT_20000c19 == '\0') {
      if (DAT_20000bc5 < 10) {
        sVar4 = _DAT_00056a50 + 9;
        sVar1 = _DAT_00056a4e + 5 + (ushort)(DAT_20000bc5 >> 1);
        sVar5 = _DAT_00056a50 + 0x1d;
        FUN_0001e294(_DAT_00056a4e + 5,sVar4,sVar1,sVar5,0xc244);
        FUN_0001e294(sVar1,sVar4,sVar2 + 0x37,sVar5,0);
      }
      else if (DAT_20000bc5 < 0x1e) {
        sVar4 = _DAT_00056a50 + 9;
        sVar1 = _DAT_00056a4e + 5 + (ushort)(DAT_20000bc5 >> 1);
        sVar5 = _DAT_00056a50 + 0x1d;
        FUN_0001e294(_DAT_00056a4e + 5,sVar4,sVar1,sVar5,0xf5a6);
        FUN_0001e294(sVar1,sVar4,sVar2 + 0x37,sVar5,0);
      }
      else {
        sVar6 = _DAT_00056a4e + 5;
        sVar4 = _DAT_00056a50 + 9;
        sVar1 = sVar6 + (ushort)(DAT_20000bc5 >> 1);
        sVar5 = _DAT_00056a50 + 0x1d;
        FUN_0001e294(sVar6,sVar4,sVar1,sVar5,0x96ca);
        if ((int)sVar1 != sVar6 + 0x32) {
          FUN_0001e294(sVar1,sVar4,sVar2 + 0x37,sVar5,0);
        }
      }
    }
    if (DAT_2000003f != DAT_20000c20) {
      DAT_2000003f = DAT_20000c20;
      if (DAT_20000c20 == '\0') {
        FUN_00024e98((byte *)0x200017c4,DAT_00056808);
      }
      else {
        FUN_00024e48((byte *)0x200017c4,DAT_00056808);
      }
    }
    if (DAT_20000040 != DAT_20000c23) {
      DAT_20000040 = DAT_20000c23;
      if (DAT_20000c23 == '\0') {
        FUN_00024e98((byte *)0x200017c4,DAT_0005681c);
      }
      else {
        FUN_00024e48((byte *)0x200017c4,DAT_0005681c);
      }
    }
    if (DAT_20000036 != DAT_20000c16) {
      DAT_20000036 = DAT_20000c16;
      if (DAT_20000c16 == '\0') {
        FUN_0002527c(DAT_2000057b);
        FUN_00024e98((byte *)0x200017c4,DAT_00056858);
      }
      else {
        FUN_0002527c(DAT_2000057b);
        FUN_00024e48((byte *)0x200017c4,DAT_00056858);
      }
    }
    if (DAT_20000ba0 == '\0') {
      if (DAT_20000b9e == '\0') {
        if (DAT_20000b9c == '\0') {
          if (DAT_20000ba5 == '\0') {
            if (DAT_20000ba2 == '\0') {
              if ((DAT_20000ba4 == '\0') && (DAT_20000b9a == '\0')) {
                if (DAT_20000b8e == '\0') {
                  if (DAT_20000b8c == '\0') {
                    if (DAT_20000b97 == '\0') {
                      if (DAT_20000b95 == '\0') {
                        if (DAT_20000b8a == '\0') {
                          if (DAT_20000b92 == '\0') {
                            if (DAT_20000b90 == '\0') {
                              if (DAT_20000b88 == '\0') {
                                FUN_00024ee8((byte *)0x200017c4,DAT_000568d0,0x568c4);
                                FUN_00024e98((byte *)0x200017c4,DAT_000568d0);
                              }
                              else {
                                FUN_00024ee8((byte *)0x200017c4,DAT_000568d0,0x568c4);
                                FUN_00024e48((byte *)0x200017c4,DAT_000568d0);
                              }
                            }
                            else {
                              FUN_00024ee8((byte *)0x200017c4,DAT_00056880,0x56874);
                              FUN_00024e48((byte *)0x200017c4,DAT_00056880);
                            }
                          }
                          else {
                            FUN_00024ee8((byte *)0x200017c4,DAT_00056948,0x5693c);
                            FUN_00024e48((byte *)0x200017c4,DAT_00056948);
                          }
                        }
                        else {
                          FUN_00024ee8((byte *)0x200017c4,DAT_000568e4,0x568d8);
                          FUN_00024e48((byte *)0x200017c4,DAT_000568e4);
                        }
                      }
                      else {
                        FUN_00024ee8((byte *)0x200017c4,DAT_000568bc,0x568b0);
                        FUN_00024e48((byte *)0x200017c4,DAT_000568bc);
                      }
                    }
                    else {
                      FUN_00024ee8((byte *)0x200017c4,DAT_0005690c,0x56900);
                      FUN_00024e48((byte *)0x200017c4,DAT_0005690c);
                    }
                  }
                  else {
                    FUN_00024ee8((byte *)0x200017c4,DAT_00056894,0x56888);
                    FUN_00024e48((byte *)0x200017c4,DAT_00056894);
                  }
                }
                else {
                  FUN_00024ee8((byte *)0x200017c4,DAT_0005695c,0x56950);
                  FUN_00024e48((byte *)0x200017c4,DAT_0005695c);
                }
              }
              else {
                FUN_00024ee8((byte *)0x200017c4,DAT_0005686c,0x56860);
                FUN_00024e48((byte *)0x200017c4,DAT_0005686c);
              }
            }
            else {
              FUN_00024ee8((byte *)0x200017c4,DAT_00056920,0x56914);
              FUN_00024e48((byte *)0x200017c4,DAT_00056920);
            }
          }
          else {
            FUN_00024ee8((byte *)0x200017c4,DAT_00056934,0x56928);
            FUN_00024e48((byte *)0x200017c4,DAT_00056934);
          }
        }
        else {
          FUN_00024ee8((byte *)0x200017c4,DAT_000568f8,0x568ec);
          FUN_00024e48((byte *)0x200017c4,DAT_000568f8);
        }
      }
      else {
        FUN_00024ee8((byte *)0x200017c4,DAT_000568a8,0x5689c);
        FUN_00024e48((byte *)0x200017c4,DAT_000568a8);
      }
    }
    else {
      FUN_00024ee8((byte *)0x200017c4,DAT_00056970,0x56964);
      FUN_00024e48((byte *)0x200017c4,DAT_00056970);
    }
    if (DAT_20000c18 == '\0') {
      if (DAT_20000c1d == '\0') {
        FUN_00024ee8((byte *)0x200017c4,DAT_00056984,0x56978);
        FUN_00024e98((byte *)0x200017c4,DAT_00056984);
      }
      else {
        DAT_20000d74 = DAT_20000d74 + 1;
        if (2 < DAT_20000d74) {
          DAT_20000d74 = 0;
          DAT_20000d75 = DAT_20000d75 == '\0';
          if ((bool)DAT_20000d75) {
            FUN_00024ee8((byte *)0x200017c4,DAT_00056984,0x56978);
            FUN_00024e48((byte *)0x200017c4,DAT_00056984);
          }
          else {
            FUN_00024ee8((byte *)0x200017c4,DAT_00056984,0x56978);
            FUN_00024e98((byte *)0x200017c4,DAT_00056984);
          }
        }
      }
    }
    else {
      FUN_00024ee8((byte *)0x200017c4,DAT_00056984,0x56978);
      FUN_00024e48((byte *)0x200017c4,DAT_00056984);
    }
    cVar3 = DAT_20000c1b != '\0';
    if (DAT_20000c1a != '\0') {
      cVar3 = cVar3 + '\x01';
    }
    if (DAT_20000038 != cVar3) {
      DAT_20000038 = cVar3;
      if (cVar3 == '\0') {
        FUN_00024ee8((byte *)0x200017c4,DAT_000569c0,0x569b4);
        FUN_00024e98((byte *)0x200017c4,DAT_000569c0);
      }
      else if (cVar3 == '\x01') {
        FUN_00024ee8((byte *)0x200017c4,DAT_000569ac,0x569a0);
        FUN_00024e48((byte *)0x200017c4,DAT_000569ac);
      }
      else if (cVar3 == '\x02') {
        FUN_00024ee8((byte *)0x200017c4,DAT_00056998,0x5698c);
        FUN_00024e48((byte *)0x200017c4,DAT_00056998);
      }
    }
    if (DAT_20000c1c == '\0') {
      if (DAT_20000bcd == '\x01') {
        local_f = '\x03';
      }
      else if (DAT_20000bcd == '\x02') {
        local_f = '\x04';
      }
      else {
        local_f = '\0';
      }
    }
    else if (DAT_20000bcd == '\x01') {
      local_f = '\x01';
    }
    else if (DAT_20000bcd == '\x02') {
      local_f = '\x02';
    }
    else {
      local_f = '\0';
    }
    if (DAT_20000039 != local_f) {
      DAT_20000039 = local_f;
      switch(local_f) {
      case '\0':
        FUN_00024ee8((byte *)0x200017c4,DAT_00056a24,0x56a18);
        FUN_00024e98((byte *)0x200017c4,DAT_00056a24);
        break;
      case '\x01':
        FUN_00024ee8((byte *)0x200017c4,DAT_000569d4,0x569c8);
        FUN_00024e48((byte *)0x200017c4,DAT_000569d4);
        break;
      case '\x02':
        FUN_00024ee8((byte *)0x200017c4,DAT_000569fc,0x569f0);
        FUN_00024e48((byte *)0x200017c4,DAT_000569fc);
        break;
      case '\x03':
        FUN_00024ee8((byte *)0x200017c4,DAT_000569e8,0x569dc);
        FUN_00024e48((byte *)0x200017c4,DAT_000569e8);
        break;
      case '\x04':
        FUN_00024ee8((byte *)0x200017c4,DAT_00056a10,0x56a04);
        FUN_00024e48((byte *)0x200017c4,DAT_00056a10);
      }
    }
    if (DAT_20000c17 == '\0') {
      DAT_20000c88 = DAT_20000c88 + 1;
      if (2 < DAT_20000c88) {
        DAT_20000c88 = 0;
        DAT_20000c89 = DAT_20000c89 == '\0';
        if ((bool)DAT_20000c89) {
          FUN_00024ee8((byte *)0x200017c4,DAT_000567e0,0x567d4);
          FUN_00024e48((byte *)0x200017c4,DAT_000567e0);
        }
        else {
          FUN_00024ee8((byte *)0x200017c4,DAT_000567f4,0x567e8);
          FUN_00024e98((byte *)0x200017c4,DAT_000567f4);
        }
      }
    }
    else {
      FUN_00024ee8((byte *)0x200017c4,DAT_000567e0,0x567d4);
      FUN_00024e48((byte *)0x200017c4,DAT_000567e0);
    }
    if (DAT_2000003a != DAT_20000bd1) {
      DAT_2000003a = DAT_20000bd1;
      if (DAT_20000bd1 == '\0') {
        FUN_00024ee8((byte *)0x200017c4,DAT_00056844,0x56838);
        FUN_00024e98((byte *)0x200017c4,DAT_00056844);
      }
      else {
        FUN_00024ee8((byte *)0x200017c4,DAT_00056830,0x56824);
        FUN_00024e48((byte *)0x200017c4,DAT_00056830);
      }
    }
    if (DAT_20000014 != 0) {
      DAT_20000014 = DAT_20000014 + 1;
      if (2 < DAT_20000014) {
        DAT_20000014 = 0;
      }
      FUN_0002040c(0);
      FUN_00020428(*(undefined2 *)((uint)DAT_20000579 * 2 + 0x3e852));
      FUN_0001e1ec((undefined4 *)0x3e6b8);
      FUN_0001f1e8(0x7b,0x24d,(byte *)0x56de7);
      FUN_0002040c(0xffff);
      FUN_00020428(0);
    }
    if ((DAT_20000bb4 == '\0') || (DAT_20000bf2 == '\0')) {
      if (DAT_20000c1f == '\0') {
        if (DAT_20000c1e == '\0') {
          if (DAT_2000056e == '\0') {
            if ((DAT_20000bd2 == 0) || (DAT_20000bd2 == 1)) {
              DAT_20000bb5 = 1;
              DAT_20000bd2 = 2;
              DAT_20000bbd = 1;
            }
            switch(DAT_20000bd2) {
            case 0:
              break;
            case 1:
              local_e = '\x01';
              break;
            case 2:
              local_e = '\x02';
              break;
            case 3:
              local_e = '\x03';
              break;
            case 4:
              local_e = '\x04';
              break;
            case 5:
              local_e = '\x04';
            }
          }
          else {
            switch(DAT_20000bbc) {
            case 0:
              local_e = '\0';
              break;
            case 1:
              local_e = '\x01';
              break;
            case 2:
              local_e = '\x02';
              break;
            case 3:
              local_e = '\x03';
              break;
            case 4:
              local_e = '\x04';
              break;
            case 5:
              local_e = '\x05';
            }
          }
        }
        else {
          local_e = '\0';
        }
      }
      else {
        local_e = '\x06';
        DAT_2000003e = -1;
      }
    }
    else {
      local_e = '\x06';
      DAT_2000003e = -1;
    }
    if (DAT_2000003e != local_e) {
      if (DAT_2000003e == '\0') {
        DAT_2000003e = -1;
      }
      else {
        DAT_2000003e = local_e;
      }
      if ((local_e == '\0') || (local_e == '\x01')) {
        FUN_0001e294(0xe9,0x26b,0x161,0x27f,0);
      }
      switch(DAT_2000003e) {
      case '\0':
        break;
      case '\x01':
        FUN_00024ee8((byte *)0x200017c4,DAT_00056a9c,0x56a90);
        FUN_00024e48((byte *)0x200017c4,DAT_00056a9c);
        break;
      case '\x02':
        FUN_0001e1ec((undefined4 *)0x3e654);
        FUN_0001f33c(DAT_00056df3,0xe6,0x1c3,0xffff,0);
        break;
      case '\x03':
        FUN_0001e1ec((undefined4 *)0x3e654);
        FUN_0001f33c(DAT_00056df4,0xe6,0x1c3,0xffff,0);
        break;
      case '\x04':
        FUN_0001e1ec((undefined4 *)0x3e654);
        FUN_0001f33c(DAT_00056df5,0xe6,0x1c3,0xffff,0);
        break;
      case '\x05':
        FUN_0001e1ec((undefined4 *)0x3e654);
        FUN_0001f33c(DAT_00056df9,0xe6,0x1c3,0xf800,0);
        break;
      case '\x06':
        FUN_0001e1ec((undefined4 *)0x3e654);
        FUN_0001f33c(DAT_00056df8,0xe6,0x1c3,0xffff,0);
      }
    }
    if (DAT_20000c24 == '\0') {
      if (((DAT_20000bd7 == '\0') || (DAT_20000bd2 < 2)) || (4 < DAT_20000bd2)) {
        local_11 = '\0';
      }
      else {
        local_11 = '\x01';
      }
    }
    else {
      _DAT_200016fe = _DAT_200016fe + 1;
      if ((uint)_DAT_200016fe % 5 < 2) {
        local_11 = '\x02';
      }
      else {
        local_11 = '\x03';
      }
    }
    if (DAT_2000003d != local_11) {
      DAT_2000003d = local_11;
      switch(local_11) {
      case '\0':
        FUN_0002040c(0xffff);
        FUN_00020428(0);
        FUN_0001e1ec((undefined4 *)0x3e668);
        FUN_0001f1e8(0x80,0x4e,(byte *)0x56c70);
        break;
      case '\x01':
        FUN_0002040c(0xffff);
        FUN_00020428(0);
        FUN_0001e1ec((undefined4 *)0x3e668);
        FUN_0001f1e8(0x80,0x4e,(byte *)0x56d95);
        break;
      case '\x02':
        FUN_0002040c(0xffff);
        FUN_00020428(0);
        FUN_0001e1ec((undefined4 *)0x3e668);
        FUN_0001f1e8(0x80,0x4e,(byte *)0x56c70);
        break;
      case '\x03':
        FUN_0002040c(0xf5a6);
        FUN_00020428(0);
        FUN_0001e1ec((undefined4 *)0x3e668);
        FUN_0001f1e8(0x80,0x4e,(byte *)0x56cfd);
      }
    }
  }
  if (DAT_200005bb == '\x03') {
    DAT_2000053e = '\v';
  }
  return;
}

