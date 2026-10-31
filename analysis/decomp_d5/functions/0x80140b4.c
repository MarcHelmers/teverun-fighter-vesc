// rea decompile_all
// name: FUN_080140b4
// address: 0x80140b4
// body: available
// range: 0x80140b4-0x80143b9 inclusive
// range: 0x80143f0-0x80144a9 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_080140b4(void)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_080131e2((uint *)0x20001654,_DAT_2000164c);
  if (iVar1 == 1) {
    FUN_080131dc((undefined4 *)0x20001654);
    if (DAT_20001659 == '\0') {
      uVar2 = FUN_08011668(*(uint *)(&DAT_2000160c +
                                    ((uint)DAT_20001649 -
                                    (uint)DAT_20001648 * ((uint)DAT_20001649 / (uint)DAT_20001648))
                                    * 4));
      DAT_20000493 = (undefined1)uVar2;
      uVar2 = FUN_08011660(*(uint *)(&DAT_2000160c +
                                    ((uint)DAT_20001649 -
                                    (uint)DAT_20001648 * ((uint)DAT_20001649 / (uint)DAT_20001648))
                                    * 4));
      DAT_20000494 = (undefined1)uVar2;
      DAT_20000495 = FUN_0801165a((char)*(undefined4 *)
                                         (&DAT_2000160c +
                                         ((uint)DAT_20001649 -
                                         (uint)DAT_20001648 *
                                         ((uint)DAT_20001649 / (uint)DAT_20001648)) * 4));
      uVar2 = FUN_08011668(_DAT_20001644);
      DAT_20000496 = (undefined1)uVar2;
      uVar2 = FUN_08011660(_DAT_20001644);
      DAT_20000497 = (undefined1)uVar2;
      DAT_20000498 = FUN_0801165a((char)_DAT_20001644);
      DAT_20001649 = DAT_20001649 + 1;
      DAT_20001659 = '\x01';
    }
    if (DAT_2000165a == '\0') {
      for (uVar2 = 0; uVar2 < 0xe; uVar2 = uVar2 + 1 & 0xff) {
        if (DAT_20001658 == '\x01') {
          if (uVar2 < 0xe - DAT_20000499) {
            FUN_08012c74();
          }
          else {
            FUN_08012c74();
          }
        }
        else if (uVar2 < DAT_20000499) {
          FUN_08012c74();
        }
        else {
          FUN_08012c74();
        }
      }
      for (uVar2 = 0; uVar2 < 0xe; uVar2 = uVar2 + 1 & 0xff) {
        if (DAT_20001658 == '\x01') {
          if (uVar2 < 0xe - DAT_20000499) {
            FUN_08013016();
          }
          else {
            FUN_08013016();
          }
        }
        else if (uVar2 < DAT_20000499) {
          FUN_08013016();
        }
        else {
          FUN_08013016();
        }
      }
      for (uVar2 = 0; uVar2 < 0xe; uVar2 = uVar2 + 1 & 0xff) {
        if (DAT_20001658 == '\x01') {
          if (uVar2 < 0xe - DAT_20000499) {
            FUN_08012e3a();
          }
          else {
            FUN_08012e3a();
          }
        }
        else if (uVar2 < DAT_20000499) {
          FUN_08012e3a();
        }
        else {
          FUN_08012e3a();
        }
      }
    }
    else if (DAT_2000165a == '\x01') {
      for (uVar2 = 0; uVar2 < 0xe; uVar2 = uVar2 + 1 & 0xff) {
        if (DAT_20001658 == '\x01') {
          if (uVar2 < 0xe - DAT_20000499) {
            FUN_08013016();
          }
          else {
            FUN_08013016();
          }
        }
        else if (uVar2 < DAT_20000499) {
          FUN_08013016();
        }
        else {
          FUN_08013016();
        }
      }
    }
    else if (DAT_2000165a == '\x02') {
      for (uVar2 = 0; uVar2 < 0xe; uVar2 = uVar2 + 1 & 0xff) {
        if (DAT_20001658 == '\x01') {
          if (uVar2 < 0xe - DAT_20000499) {
            FUN_08012c74();
          }
          else {
            FUN_08012c74();
          }
        }
        else if (uVar2 < DAT_20000499) {
          FUN_08012c74();
        }
        else {
          FUN_08012c74();
        }
      }
    }
    else if (DAT_2000165a == '\x03') {
      for (uVar2 = 0; uVar2 < 0xe; uVar2 = uVar2 + 1 & 0xff) {
        if (DAT_20001658 == '\x01') {
          if (uVar2 < 0xe - DAT_20000499) {
            FUN_08012e3a();
          }
          else {
            FUN_08012e3a();
          }
        }
        else if (uVar2 < DAT_20000499) {
          FUN_08012e3a();
        }
        else {
          FUN_08012e3a();
        }
      }
    }
    if ((DAT_20001659 == '\x01') && (DAT_20000499 = DAT_20000499 + 1, 0xe < DAT_20000499)) {
      DAT_20000499 = 0;
      DAT_2000049a = 0;
      DAT_20001659 = '\0';
    }
  }
  return;
}

