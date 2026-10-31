// rea decompile_all
// name: FUN_0800f510
// address: 0x800f510
// body: available
// range: 0x800f510-0x800f609 inclusive
// range: 0x800f614-0x800f635 inclusive
// range: 0x800f71c-0x800f7eb inclusive
// range: 0x800f7ee-0x800f9f7 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0800f510(void)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  
  bVar2 = DAT_2000029b;
  if (DAT_20001376 == ':') {
    DAT_200002d3 = DAT_20001377;
    DAT_200002d4 = DAT_20001378;
    _DAT_200002d6 = CONCAT11(DAT_20001379,DAT_2000137a);
    DAT_200002d8 = DAT_2000137b;
    _DAT_200002da = CONCAT11(DAT_2000137c,DAT_2000137d);
    DAT_200002dc = DAT_2000137e;
    DAT_200002dd = DAT_2000137f;
    DAT_200003fd = 1;
    if ((DAT_2000137f & 1) == 0) {
      DAT_20000390 = 0;
    }
    else {
      DAT_20000390 = 1;
    }
  }
  else if (DAT_20001376 == ';') {
    DAT_200002de = DAT_20001377;
    DAT_200002df = DAT_20001378;
    _DAT_200002e0 = CONCAT11(DAT_20001379,DAT_2000137a);
    DAT_200002e2 = DAT_2000137b;
    _DAT_200002e4 = CONCAT11(DAT_2000137c,DAT_2000137d);
    DAT_200002e6 = DAT_2000137e;
    DAT_200002e7 = DAT_2000137f;
    DAT_200003fd = 3;
  }
  if (DAT_2000134f == '5') {
    DAT_200002d0 = DAT_20001350;
    DAT_20000307 = (DAT_20001353 & 0x40) != 0;
    switch(DAT_20001350) {
    case 0:
      break;
    case 1:
      if ((DAT_20000301 == '\0') && (DAT_20000299 = DAT_20001351, 5 < DAT_20001351)) {
        DAT_20000299 = 5;
      }
      break;
    case 2:
      if (DAT_20000301 == '\0') {
        bVar3 = DAT_2000029b & 0xfe;
        if ((DAT_20001352 & 0x80) == 0x80) {
          DAT_2000029b = bVar3 | DAT_20001352 & 1 | 0x80;
        }
        else {
          DAT_2000029b = DAT_2000029b & 0x7e | DAT_20001352 & 1;
        }
        if ((DAT_20001352 & 0x40) == 0x40) {
          DAT_2000029a = bVar3 | DAT_20001352 & 1 | 0x80;
        }
        else {
          DAT_2000029a = bVar2 & 0x7e | DAT_20001352 & 1;
        }
        if ((DAT_20001352 & 1) != 0) {
          DAT_20000302 = 3;
        }
        if ((DAT_20001352 & 0x20) == 0x20) {
          DAT_20000305 = 1;
        }
        else {
          DAT_20000305 = 0;
        }
      }
      break;
    case 3:
      bVar1 = (DAT_20001353 & 1) == 0;
      if (bVar1) {
        DAT_200002d2 = DAT_200002d2 & 0xfe;
      }
      else {
        DAT_200002d2 = DAT_200002d2 | 1;
      }
      DAT_20000301 = !bVar1;
      break;
    case 4:
      bVar1 = (DAT_20001353 & 2) == 0;
      if (bVar1) {
        DAT_200002d2 = DAT_200002d2 & 0xfd;
      }
      else {
        DAT_200002d2 = DAT_200002d2 | 2;
      }
      DAT_20000300 = !bVar1;
      break;
    case 5:
      if ((DAT_20001352 & 0x10) == 0x10) {
        DAT_2000029b = DAT_2000029b | 0x40;
        DAT_2000029a = DAT_2000029a | 0x40;
      }
      else {
        DAT_2000029b = DAT_2000029b & 0xbf;
        DAT_2000029a = DAT_2000029a & 0xbf;
      }
      if ((DAT_20001352 & 8) == 8) {
        DAT_2000029b = DAT_2000029b | 8;
        DAT_2000029a = DAT_2000029a | 8;
      }
      else {
        DAT_2000029b = DAT_2000029b & 0xf7;
        DAT_2000029a = DAT_2000029a & 0xf7;
      }
      if (DAT_2000030c == '\0') {
        DAT_2000029b = DAT_20001352 & 6 | DAT_2000029b & 0xf9;
        DAT_2000029a = DAT_20001352 & 6 | DAT_2000029a & 0xf9;
      }
      DAT_2000029e = DAT_20001356 * '\x05' + 'P';
      (&DAT_2000029f)[DAT_20001351] = DAT_20001357;
      (&DAT_200002a5)[DAT_20001351] = DAT_20001357 & 0xf0 | DAT_20001358 & 0xf;
      (&DAT_200002ab)[DAT_20001351] = DAT_20001359;
      DAT_200002b1 = DAT_2000135a;
      (&DAT_200002b2)[DAT_20001351] = DAT_2000135b;
      (&DAT_200002b8)[DAT_20001351] = DAT_2000135c;
      DAT_200002be = DAT_2000135d;
      DAT_200002bf = DAT_2000135e;
      break;
    default:
      break;
    case 7:
      DAT_2000030a = (DAT_20001353 & 0x10) == 0x10;
      break;
    case 9:
      DAT_20000316 = (DAT_20001353 & 8) == 8;
    }
    if (((DAT_2000070e == 'T') && (DAT_2000070f == 'D')) && (DAT_20000710 == 'E')) {
      DAT_2000030c = '\x01';
    }
    else if ((DAT_20001353 & 4) == 4) {
      DAT_2000030c = '\x01';
    }
    else {
      DAT_2000030c = '\0';
    }
    DAT_200002c5 = (DAT_20001353 & 0x80) == 0x80;
    DAT_200003fc = 1;
  }
  return;
}

