// rea decompile_all
// name: FUN_08013c1e
// address: 0x8013c1e
// body: available
// range: 0x8013c1e-0x8013e8b inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08013c1e(void)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = FUN_080131e2((uint *)0x20001474,_DAT_2000146c);
  if (iVar2 == 1) {
    FUN_080131dc((undefined4 *)0x20001474);
    if (DAT_20001479 == '\0') {
      DAT_20001479 = '\x01';
      uVar3 = FUN_08011668(*(uint *)(&DAT_2000142c +
                                    ((uint)DAT_20001469 -
                                    (uint)DAT_20001468 * ((uint)DAT_20001469 / (uint)DAT_20001468))
                                    * 4));
      DAT_20000480 = (byte)uVar3;
      uVar3 = FUN_08011660(*(uint *)(&DAT_2000142c +
                                    ((uint)DAT_20001469 -
                                    (uint)DAT_20001468 * ((uint)DAT_20001469 / (uint)DAT_20001468))
                                    * 4));
      DAT_20000481 = (byte)uVar3;
      DAT_20000482 = FUN_0801165a((char)*(undefined4 *)
                                         (&DAT_2000142c +
                                         ((uint)DAT_20001469 -
                                         (uint)DAT_20001468 *
                                         ((uint)DAT_20001469 / (uint)DAT_20001468)) * 4));
      DAT_20001469 = DAT_20001469 + 1;
      DAT_20000483 = 0;
      DAT_20000484 = 0;
      DAT_20000485 = 0;
    }
    DAT_20000486 = '\x01';
    if (2 < DAT_20000487) {
      DAT_20000487 = 0;
    }
    if (DAT_20001479 == '\x01') {
      DAT_20000483 = DAT_20000483 + 2;
      if (DAT_20000480 <= DAT_20000483) {
        DAT_20000483 = DAT_20000480;
      }
      DAT_20000484 = DAT_20000484 + 2;
      if (DAT_20000481 <= DAT_20000484) {
        DAT_20000484 = DAT_20000481;
      }
      DAT_20000485 = DAT_20000485 + 2;
      if (DAT_20000482 <= DAT_20000485) {
        DAT_20000485 = DAT_20000482;
      }
      if (((DAT_20000483 == DAT_20000480) && (DAT_20000485 == DAT_20000482)) &&
         (DAT_20000484 == DAT_20000481)) {
        DAT_20001479 = '\x02';
      }
    }
    else if (DAT_20001479 == '\x02') {
      if (DAT_20000483 < 2) {
        DAT_20000483 = 0;
      }
      else {
        DAT_20000483 = DAT_20000483 - 2;
      }
      if (DAT_20000484 < 2) {
        DAT_20000484 = 0;
      }
      else {
        DAT_20000484 = DAT_20000484 - 2;
      }
      if (DAT_20000485 < 2) {
        DAT_20000485 = 0;
      }
      else {
        DAT_20000485 = DAT_20000485 - 2;
      }
      if (((DAT_20000483 == 0) && (DAT_20000485 == 0)) && (DAT_20000484 == 0)) {
        DAT_20001479 = '\0';
      }
    }
  }
  if (DAT_20000486 == '\x01') {
    if (DAT_20000487 == 0) {
      for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
        FUN_08013016();
      }
      DAT_20000487 = 1;
    }
    else if (DAT_20000487 == 1) {
      for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
        FUN_08012e3a();
      }
      DAT_20000487 = 2;
    }
    else if (DAT_20000487 == 2) {
      for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
        FUN_08012c74();
      }
      DAT_20000487 = 3;
      DAT_20000486 = '\0';
    }
    else {
      DAT_20000487 = 3;
      DAT_20000486 = '\0';
    }
  }
  return;
}

