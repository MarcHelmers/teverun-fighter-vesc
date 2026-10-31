// rea decompile_all
// name: FUN_080147b8
// address: 0x80147b8
// body: available
// range: 0x80147b8-0x8014913 inclusive
// range: 0x8014964-0x8014a3d inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_080147b8(void)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_08013326((uint *)0x2000152c,_DAT_20001524);
  if (iVar1 == 1) {
    FUN_08013320((undefined4 *)0x2000152c);
    if (DAT_20001531 == '\0') {
      uVar2 = FUN_080117ac(*(uint *)(&DAT_200014e4 +
                                    ((uint)DAT_20001521 -
                                    (uint)DAT_20001520 * ((uint)DAT_20001521 / (uint)DAT_20001520))
                                    * 4));
      DAT_200004a6 = (undefined1)uVar2;
      uVar2 = FUN_080117a4(*(uint *)(&DAT_200014e4 +
                                    ((uint)DAT_20001521 -
                                    (uint)DAT_20001520 * ((uint)DAT_20001521 / (uint)DAT_20001520))
                                    * 4));
      DAT_200004a7 = (undefined1)uVar2;
      DAT_200004a8 = FUN_0801179e((char)*(undefined4 *)
                                         (&DAT_200014e4 +
                                         ((uint)DAT_20001521 -
                                         (uint)DAT_20001520 *
                                         ((uint)DAT_20001521 / (uint)DAT_20001520)) * 4));
      DAT_20001521 = DAT_20001521 + 1;
      DAT_20001531 = '\x01';
    }
    for (uVar2 = 0; uVar2 < 0xe; uVar2 = uVar2 + 1 & 0xff) {
      if (DAT_20001530 == '\x01') {
        if (uVar2 < 0xe - DAT_200004a9) {
          FUN_0801315a();
        }
        else {
          FUN_0801315a();
        }
      }
      else if (DAT_200004a9 < uVar2) {
        FUN_0801315a();
      }
      else {
        FUN_0801315a();
      }
    }
    for (uVar2 = 0; uVar2 < 0xe; uVar2 = uVar2 + 1 & 0xff) {
      if (DAT_20001530 == '\x01') {
        if (uVar2 < 0xe - DAT_200004a9) {
          FUN_08012db8();
        }
        else {
          FUN_08012db8();
        }
      }
      else if (DAT_200004a9 < uVar2) {
        FUN_08012db8();
      }
      else {
        FUN_08012db8();
      }
    }
    for (uVar2 = 0; uVar2 < 0xe; uVar2 = uVar2 + 1 & 0xff) {
      if (DAT_20001530 == '\x01') {
        if (uVar2 < 0xe - DAT_200004a9) {
          FUN_08012f7e();
        }
        else {
          FUN_08012f7e();
        }
      }
      else if (DAT_200004a9 < uVar2) {
        FUN_08012f7e();
      }
      else {
        FUN_08012f7e();
      }
    }
    if (DAT_20001531 == '\x01') {
      DAT_200004a9 = DAT_200004a9 + 1;
      if (0xe < DAT_200004a9) {
        DAT_200004a9 = 0xe;
        DAT_200004aa = 0;
        DAT_20001531 = '\x02';
      }
    }
    else if ((DAT_20001531 == '\x02') && (DAT_200004aa = DAT_200004aa + 1, 0x28 < DAT_200004aa)) {
      DAT_200004a9 = 0;
      DAT_200004aa = 0;
      DAT_20001531 = '\0';
    }
  }
  return;
}

