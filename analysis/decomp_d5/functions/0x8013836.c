// rea decompile_all
// name: FUN_08013836
// address: 0x8013836
// body: available
// range: 0x8013836-0x8013865 inclusive
// range: 0x801386c-0x8013b63 inclusive
// range: 0x8013b9c-0x8013c1d inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08013836(void)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar2 = FUN_080131e2((uint *)0x20001744,_DAT_2000173c);
  if (iVar2 == 1) {
    FUN_080131dc((undefined4 *)0x20001744);
    switch(DAT_20001739) {
    case 0:
      uVar4 = FUN_08011670((int)(uint)DAT_20001740 >> 1,_DAT_200016fc);
      uVar3 = FUN_08011668(uVar4);
      DAT_200004b4 = (undefined1)uVar3;
      uVar3 = FUN_08011660(uVar4);
      DAT_200004b5 = (undefined1)uVar3;
      DAT_200004b6 = FUN_0801165a((char)uVar4);
      uVar4 = FUN_08011668(0);
      DAT_200004b7 = (undefined1)uVar4;
      uVar4 = FUN_08011660(0);
      DAT_200004b8 = (undefined1)uVar4;
      DAT_200004b9 = FUN_0801165a(0);
      DAT_20001739 = DAT_20001739 + 1;
      _DAT_20000438 = 0;
      DAT_200004ba = 0;
      break;
    case 1:
      for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
        FUN_080133f4(DAT_200004b7,DAT_200004b8,DAT_200004b9);
      }
      _DAT_20000438 = 0;
      *(undefined1 *)((uint)DAT_200004ba * 3 + 0x2000174c) = DAT_200004b4;
      *(undefined1 *)((uint)DAT_200004ba * 3 + 0x2000174d) = DAT_200004b5;
      *(undefined1 *)((uint)DAT_200004ba * 3 + 0x2000174e) = DAT_200004b6;
      *(undefined1 *)((0xd - (uint)DAT_200004ba) * 3 + 0x2000174c) = DAT_200004b4;
      *(undefined1 *)((0xd - (uint)DAT_200004ba) * 3 + 0x2000174d) = DAT_200004b5;
      *(undefined1 *)((0xd - (uint)DAT_200004ba) * 3 + 0x2000174e) = DAT_200004b6;
      DAT_200004ba = DAT_200004ba + 1;
      if (0xd < DAT_200004ba) {
        DAT_200004ba = 0;
        DAT_20001739 = DAT_20001739 + 1;
      }
      break;
    case 2:
      for (uVar4 = 0; uVar4 < 0xe; uVar4 = uVar4 + 1 & 0xff) {
        if ((DAT_200004ba < uVar4) && (uVar4 < 0xd - DAT_200004ba)) {
          *(undefined1 *)(uVar4 * 3 + 0x2000174c) = DAT_200004b7;
          *(undefined1 *)(uVar4 * 3 + 0x2000174d) = DAT_200004b8;
          *(undefined1 *)(uVar4 * 3 + 0x2000174e) = DAT_200004b9;
        }
        else {
          *(undefined1 *)(uVar4 * 3 + 0x2000174c) = DAT_200004b4;
          *(undefined1 *)(uVar4 * 3 + 0x2000174d) = DAT_200004b5;
          *(undefined1 *)(uVar4 * 3 + 0x2000174e) = DAT_200004b6;
        }
      }
      DAT_200004ba = DAT_200004ba + 1;
      if (7 < DAT_200004ba) {
        DAT_200004ba = 0;
        uVar4 = FUN_08011668(_DAT_200016fc);
        DAT_200004b4 = (undefined1)uVar4;
        uVar4 = FUN_08011660(_DAT_200016fc);
        DAT_200004b5 = (undefined1)uVar4;
        DAT_200004b6 = FUN_0801165a((char)_DAT_200016fc);
        uVar4 = FUN_08011670((int)(uint)DAT_20001740 >> 1,_DAT_200016fc);
        uVar3 = FUN_08011668(uVar4);
        DAT_200004b7 = (undefined1)uVar3;
        uVar3 = FUN_08011660(uVar4);
        DAT_200004b8 = (undefined1)uVar3;
        DAT_200004b9 = FUN_0801165a((char)uVar4);
        DAT_20001739 = DAT_20001739 + 1;
      }
      break;
    case 3:
      for (uVar4 = 0; uVar4 < 0xe; uVar4 = uVar4 + 1 & 0xff) {
        if ((uVar4 < 7 - DAT_200004ba) || (DAT_200004ba + 7 < uVar4)) {
          *(undefined1 *)(uVar4 * 3 + 0x2000174c) = DAT_200004b7;
          *(undefined1 *)(uVar4 * 3 + 0x2000174d) = DAT_200004b8;
          *(undefined1 *)(uVar4 * 3 + 0x2000174e) = DAT_200004b9;
        }
        else {
          *(undefined1 *)(uVar4 * 3 + 0x2000174c) = DAT_200004b4;
          *(undefined1 *)(uVar4 * 3 + 0x2000174d) = DAT_200004b5;
          *(undefined1 *)(uVar4 * 3 + 0x2000174e) = DAT_200004b6;
        }
      }
      DAT_200004ba = DAT_200004ba + 1;
      if (7 < DAT_200004ba) {
        DAT_200004ba = 0;
        DAT_20001739 = DAT_20001739 + 1;
      }
      break;
    case 4:
    }
    DAT_200004bb = '\x01';
    DAT_200004bc = 0;
  }
  if ((DAT_200004bb != '\0') && (DAT_20001739 < 4)) {
    if (DAT_200004bc == 0) {
      for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
        FUN_08013016();
      }
    }
    else if (DAT_200004bc == 1) {
      for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
        FUN_08012e3a();
      }
    }
    else if (DAT_200004bc == 2) {
      for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
        FUN_08012c74();
      }
    }
    DAT_200004bc = DAT_200004bc + 1;
    if (2 < DAT_200004bc) {
      DAT_200004bc = 0;
      DAT_200004bb = '\0';
    }
  }
  return;
}

