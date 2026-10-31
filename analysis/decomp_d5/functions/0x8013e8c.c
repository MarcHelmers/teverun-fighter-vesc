// rea decompile_all
// name: FUN_08013e8c
// address: 0x8013e8c
// body: available
// range: 0x8013e8c-0x8013f7b inclusive
// range: 0x8013fcc-0x8014033 inclusive
// range: 0x8014036-0x80140b3 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_08013e8c(void)

{
  byte bVar1;
  uint uVar2;
  
  if (DAT_20000325 != DAT_20000457) {
    DAT_20000457 = DAT_20000325;
    uVar2 = FUN_08011668(*(uint *)(&DAT_200013dc +
                                  ((uint)DAT_20001419 -
                                  (uint)DAT_20001418 * ((uint)DAT_20001419 / (uint)DAT_20001418)) *
                                  4));
    DAT_20000452 = (undefined1)uVar2;
    uVar2 = FUN_08011660(*(uint *)(&DAT_200013dc +
                                  ((uint)DAT_20001419 -
                                  (uint)DAT_20001418 * ((uint)DAT_20001419 / (uint)DAT_20001418)) *
                                  4));
    DAT_20000453 = (undefined1)uVar2;
    DAT_20000454 = FUN_0801165a((char)*(undefined4 *)
                                       (&DAT_200013dc +
                                       ((uint)DAT_20001419 -
                                       (uint)DAT_20001418 *
                                       ((uint)DAT_20001419 / (uint)DAT_20001418)) * 4));
    DAT_20001419 = DAT_20001419 + 1;
    DAT_20000455 = '\x01';
    DAT_20000456 = 0;
  }
  if (DAT_20000455 != '\0') {
    if (DAT_2000142a == '\0') {
      if (DAT_20000456 == 0) {
        for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
          FUN_08013016();
        }
      }
      else if (DAT_20000456 == 1) {
        for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
          FUN_08012c74();
        }
      }
      else if (DAT_20000456 == 2) {
        for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
          FUN_08012e3a();
        }
      }
      DAT_20000456 = DAT_20000456 + 1;
      if (2 < DAT_20000456) {
        DAT_20000456 = 0;
        DAT_20000455 = '\0';
      }
    }
    else if (DAT_2000142a == '\x01') {
      for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
        FUN_08013016();
      }
      DAT_20000456 = 0;
      DAT_20000455 = '\0';
    }
    else if (DAT_2000142a == '\x02') {
      for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
        FUN_08012c74();
      }
      DAT_20000456 = 0;
      DAT_20000455 = '\0';
    }
    else if (DAT_2000142a == '\x03') {
      for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
        FUN_08012e3a();
      }
      DAT_20000456 = 0;
      DAT_20000455 = '\0';
    }
  }
  return;
}

