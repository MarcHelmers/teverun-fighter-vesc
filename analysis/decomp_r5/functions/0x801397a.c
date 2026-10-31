// rea decompile_all
// name: FUN_0801397a
// address: 0x801397a
// body: available
// range: 0x801397a-0x80139a9 inclusive
// range: 0x80139b0-0x8013ca7 inclusive
// range: 0x8013ce0-0x8013d61 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0801397a(void)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar2 = FUN_08013326((uint *)0x2000175c,_DAT_20001754);
  if (iVar2 == 1) {
    FUN_08013320((undefined4 *)0x2000175c);
    switch(DAT_20001751) {
    case 0:
      uVar4 = FUN_080117b4((int)(uint)DAT_20001758 >> 1,_DAT_20001714);
      uVar3 = FUN_080117ac(uVar4);
      DAT_200004cc = (undefined1)uVar3;
      uVar3 = FUN_080117a4(uVar4);
      DAT_200004cd = (undefined1)uVar3;
      DAT_200004ce = FUN_0801179e((char)uVar4);
      uVar4 = FUN_080117ac(0);
      DAT_200004cf = (undefined1)uVar4;
      uVar4 = FUN_080117a4(0);
      DAT_200004d0 = (undefined1)uVar4;
      DAT_200004d1 = FUN_0801179e(0);
      DAT_20001751 = DAT_20001751 + 1;
      _DAT_20000450 = 0;
      DAT_200004d2 = 0;
      break;
    case 1:
      for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
        FUN_08013538(DAT_200004cf,DAT_200004d0,DAT_200004d1);
      }
      _DAT_20000450 = 0;
      *(undefined1 *)((uint)DAT_200004d2 * 3 + 0x20001764) = DAT_200004cc;
      *(undefined1 *)((uint)DAT_200004d2 * 3 + 0x20001765) = DAT_200004cd;
      *(undefined1 *)((uint)DAT_200004d2 * 3 + 0x20001766) = DAT_200004ce;
      *(undefined1 *)((0xd - (uint)DAT_200004d2) * 3 + 0x20001764) = DAT_200004cc;
      *(undefined1 *)((0xd - (uint)DAT_200004d2) * 3 + 0x20001765) = DAT_200004cd;
      *(undefined1 *)((0xd - (uint)DAT_200004d2) * 3 + 0x20001766) = DAT_200004ce;
      DAT_200004d2 = DAT_200004d2 + 1;
      if (0xd < DAT_200004d2) {
        DAT_200004d2 = 0;
        DAT_20001751 = DAT_20001751 + 1;
      }
      break;
    case 2:
      for (uVar4 = 0; uVar4 < 0xe; uVar4 = uVar4 + 1 & 0xff) {
        if ((DAT_200004d2 < uVar4) && (uVar4 < 0xd - DAT_200004d2)) {
          *(undefined1 *)(uVar4 * 3 + 0x20001764) = DAT_200004cf;
          *(undefined1 *)(uVar4 * 3 + 0x20001765) = DAT_200004d0;
          *(undefined1 *)(uVar4 * 3 + 0x20001766) = DAT_200004d1;
        }
        else {
          *(undefined1 *)(uVar4 * 3 + 0x20001764) = DAT_200004cc;
          *(undefined1 *)(uVar4 * 3 + 0x20001765) = DAT_200004cd;
          *(undefined1 *)(uVar4 * 3 + 0x20001766) = DAT_200004ce;
        }
      }
      DAT_200004d2 = DAT_200004d2 + 1;
      if (7 < DAT_200004d2) {
        DAT_200004d2 = 0;
        uVar4 = FUN_080117ac(_DAT_20001714);
        DAT_200004cc = (undefined1)uVar4;
        uVar4 = FUN_080117a4(_DAT_20001714);
        DAT_200004cd = (undefined1)uVar4;
        DAT_200004ce = FUN_0801179e((char)_DAT_20001714);
        uVar4 = FUN_080117b4((int)(uint)DAT_20001758 >> 1,_DAT_20001714);
        uVar3 = FUN_080117ac(uVar4);
        DAT_200004cf = (undefined1)uVar3;
        uVar3 = FUN_080117a4(uVar4);
        DAT_200004d0 = (undefined1)uVar3;
        DAT_200004d1 = FUN_0801179e((char)uVar4);
        DAT_20001751 = DAT_20001751 + 1;
      }
      break;
    case 3:
      for (uVar4 = 0; uVar4 < 0xe; uVar4 = uVar4 + 1 & 0xff) {
        if ((uVar4 < 7 - DAT_200004d2) || (DAT_200004d2 + 7 < uVar4)) {
          *(undefined1 *)(uVar4 * 3 + 0x20001764) = DAT_200004cf;
          *(undefined1 *)(uVar4 * 3 + 0x20001765) = DAT_200004d0;
          *(undefined1 *)(uVar4 * 3 + 0x20001766) = DAT_200004d1;
        }
        else {
          *(undefined1 *)(uVar4 * 3 + 0x20001764) = DAT_200004cc;
          *(undefined1 *)(uVar4 * 3 + 0x20001765) = DAT_200004cd;
          *(undefined1 *)(uVar4 * 3 + 0x20001766) = DAT_200004ce;
        }
      }
      DAT_200004d2 = DAT_200004d2 + 1;
      if (7 < DAT_200004d2) {
        DAT_200004d2 = 0;
        DAT_20001751 = DAT_20001751 + 1;
      }
      break;
    case 4:
    }
    DAT_200004d3 = '\x01';
    DAT_200004d4 = 0;
  }
  if ((DAT_200004d3 != '\0') && (DAT_20001751 < 4)) {
    if (DAT_200004d4 == 0) {
      for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
        FUN_0801315a();
      }
    }
    else if (DAT_200004d4 == 1) {
      for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
        FUN_08012f7e();
      }
    }
    else if (DAT_200004d4 == 2) {
      for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
        FUN_08012db8();
      }
    }
    DAT_200004d4 = DAT_200004d4 + 1;
    if (2 < DAT_200004d4) {
      DAT_200004d4 = 0;
      DAT_200004d3 = '\0';
    }
  }
  return;
}

