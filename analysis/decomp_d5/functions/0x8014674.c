// rea decompile_all
// name: FUN_08014674
// address: 0x8014674
// body: available
// range: 0x8014674-0x80147cf inclusive
// range: 0x8014820-0x80148f9 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08014674(void)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_080131e2((uint *)0x20001514,_DAT_2000150c);
  if (iVar1 == 1) {
    FUN_080131dc((undefined4 *)0x20001514);
    if (DAT_20001519 == '\0') {
      uVar2 = FUN_08011668(*(uint *)(&DAT_200014cc +
                                    ((uint)DAT_20001509 -
                                    (uint)DAT_20001508 * ((uint)DAT_20001509 / (uint)DAT_20001508))
                                    * 4));
      DAT_2000048e = (undefined1)uVar2;
      uVar2 = FUN_08011660(*(uint *)(&DAT_200014cc +
                                    ((uint)DAT_20001509 -
                                    (uint)DAT_20001508 * ((uint)DAT_20001509 / (uint)DAT_20001508))
                                    * 4));
      DAT_2000048f = (undefined1)uVar2;
      DAT_20000490 = FUN_0801165a((char)*(undefined4 *)
                                         (&DAT_200014cc +
                                         ((uint)DAT_20001509 -
                                         (uint)DAT_20001508 *
                                         ((uint)DAT_20001509 / (uint)DAT_20001508)) * 4));
      DAT_20001509 = DAT_20001509 + 1;
      DAT_20001519 = '\x01';
    }
    for (uVar2 = 0; uVar2 < 0xe; uVar2 = uVar2 + 1 & 0xff) {
      if (DAT_20001518 == '\x01') {
        if (uVar2 < 0xe - DAT_20000491) {
          FUN_08013016();
        }
        else {
          FUN_08013016();
        }
      }
      else if (DAT_20000491 < uVar2) {
        FUN_08013016();
      }
      else {
        FUN_08013016();
      }
    }
    for (uVar2 = 0; uVar2 < 0xe; uVar2 = uVar2 + 1 & 0xff) {
      if (DAT_20001518 == '\x01') {
        if (uVar2 < 0xe - DAT_20000491) {
          FUN_08012c74();
        }
        else {
          FUN_08012c74();
        }
      }
      else if (DAT_20000491 < uVar2) {
        FUN_08012c74();
      }
      else {
        FUN_08012c74();
      }
    }
    for (uVar2 = 0; uVar2 < 0xe; uVar2 = uVar2 + 1 & 0xff) {
      if (DAT_20001518 == '\x01') {
        if (uVar2 < 0xe - DAT_20000491) {
          FUN_08012e3a();
        }
        else {
          FUN_08012e3a();
        }
      }
      else if (DAT_20000491 < uVar2) {
        FUN_08012e3a();
      }
      else {
        FUN_08012e3a();
      }
    }
    if (DAT_20001519 == '\x01') {
      DAT_20000491 = DAT_20000491 + 1;
      if (0xe < DAT_20000491) {
        DAT_20000491 = 0xe;
        DAT_20000492 = 0;
        DAT_20001519 = '\x02';
      }
    }
    else if ((DAT_20001519 == '\x02') && (DAT_20000492 = DAT_20000492 + 1, 0x28 < DAT_20000492)) {
      DAT_20000491 = 0;
      DAT_20000492 = 0;
      DAT_20001519 = '\0';
    }
  }
  return;
}

