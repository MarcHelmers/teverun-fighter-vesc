// rea decompile_all
// name: FUN_08013d62
// address: 0x8013d62
// body: available
// range: 0x8013d62-0x8013fcf inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08013d62(void)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = FUN_08013326((uint *)0x2000148c,_DAT_20001484);
  if (iVar2 == 1) {
    FUN_08013320((undefined4 *)0x2000148c);
    if (DAT_20001491 == '\0') {
      DAT_20001491 = '\x01';
      uVar3 = FUN_080117ac(*(uint *)(&DAT_20001444 +
                                    ((uint)DAT_20001481 -
                                    (uint)DAT_20001480 * ((uint)DAT_20001481 / (uint)DAT_20001480))
                                    * 4));
      DAT_20000498 = (byte)uVar3;
      uVar3 = FUN_080117a4(*(uint *)(&DAT_20001444 +
                                    ((uint)DAT_20001481 -
                                    (uint)DAT_20001480 * ((uint)DAT_20001481 / (uint)DAT_20001480))
                                    * 4));
      DAT_20000499 = (byte)uVar3;
      DAT_2000049a = FUN_0801179e((char)*(undefined4 *)
                                         (&DAT_20001444 +
                                         ((uint)DAT_20001481 -
                                         (uint)DAT_20001480 *
                                         ((uint)DAT_20001481 / (uint)DAT_20001480)) * 4));
      DAT_20001481 = DAT_20001481 + 1;
      DAT_2000049b = 0;
      DAT_2000049c = 0;
      DAT_2000049d = 0;
    }
    DAT_2000049e = '\x01';
    if (2 < DAT_2000049f) {
      DAT_2000049f = 0;
    }
    if (DAT_20001491 == '\x01') {
      DAT_2000049b = DAT_2000049b + 2;
      if (DAT_20000498 <= DAT_2000049b) {
        DAT_2000049b = DAT_20000498;
      }
      DAT_2000049c = DAT_2000049c + 2;
      if (DAT_20000499 <= DAT_2000049c) {
        DAT_2000049c = DAT_20000499;
      }
      DAT_2000049d = DAT_2000049d + 2;
      if (DAT_2000049a <= DAT_2000049d) {
        DAT_2000049d = DAT_2000049a;
      }
      if (((DAT_2000049b == DAT_20000498) && (DAT_2000049d == DAT_2000049a)) &&
         (DAT_2000049c == DAT_20000499)) {
        DAT_20001491 = '\x02';
      }
    }
    else if (DAT_20001491 == '\x02') {
      if (DAT_2000049b < 2) {
        DAT_2000049b = 0;
      }
      else {
        DAT_2000049b = DAT_2000049b - 2;
      }
      if (DAT_2000049c < 2) {
        DAT_2000049c = 0;
      }
      else {
        DAT_2000049c = DAT_2000049c - 2;
      }
      if (DAT_2000049d < 2) {
        DAT_2000049d = 0;
      }
      else {
        DAT_2000049d = DAT_2000049d - 2;
      }
      if (((DAT_2000049b == 0) && (DAT_2000049d == 0)) && (DAT_2000049c == 0)) {
        DAT_20001491 = '\0';
      }
    }
  }
  if (DAT_2000049e == '\x01') {
    if (DAT_2000049f == 0) {
      for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
        FUN_0801315a();
      }
      DAT_2000049f = 1;
    }
    else if (DAT_2000049f == 1) {
      for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
        FUN_08012f7e();
      }
      DAT_2000049f = 2;
    }
    else if (DAT_2000049f == 2) {
      for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
        FUN_08012db8();
      }
      DAT_2000049f = 3;
      DAT_2000049e = '\0';
    }
    else {
      DAT_2000049f = 3;
      DAT_2000049e = '\0';
    }
  }
  return;
}

