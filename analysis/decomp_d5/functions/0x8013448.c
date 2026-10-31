// rea decompile_all
// name: FUN_08013448
// address: 0x8013448
// body: available
// range: 0x8013448-0x801347d inclusive
// range: 0x8013486-0x801354b inclusive
// range: 0x801354e-0x8013577 inclusive
// range: 0x8013580-0x801373b inclusive
// range: 0x8013770-0x8013835 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08013448(void)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = FUN_080131e2((uint *)0x200016f4,_DAT_200016ec);
  if (iVar2 == 1) {
    FUN_080131dc((undefined4 *)0x200016f4);
    if (DAT_200016f8 == '\0') {
      switch(DAT_2000048b) {
      case 0:
        DAT_20000488 = DAT_200016c0;
        DAT_20000489 = 0;
        DAT_2000048a = 0;
        DAT_2000048b = 1;
        break;
      case 1:
        DAT_20000489 = DAT_20000489 + 1;
        if (_DAT_200016c0 - 1U < (uint)DAT_20000489) {
          DAT_20000489 = DAT_200016c0;
          DAT_2000048b = 2;
        }
        break;
      case 2:
        DAT_20000488 = DAT_20000488 - 1;
        if (DAT_20000488 == 0) {
          DAT_20000488 = 0;
          DAT_2000048b = 3;
        }
        break;
      case 3:
        DAT_2000048a = DAT_2000048a + 1;
        if (_DAT_200016c0 - 1U < (uint)DAT_2000048a) {
          DAT_2000048a = DAT_200016c0;
          DAT_2000048b = 4;
        }
        break;
      case 4:
        DAT_20000489 = DAT_20000489 - 1;
        if (DAT_20000489 == 0) {
          DAT_20000489 = 0;
          DAT_2000048b = 5;
        }
        break;
      case 5:
        DAT_20000488 = DAT_20000488 + 1;
        if (_DAT_200016c0 - 1U < (uint)DAT_20000488) {
          DAT_20000488 = DAT_200016c0;
          DAT_2000048b = 6;
        }
        break;
      case 6:
        DAT_2000048a = DAT_2000048a - 1;
        if (DAT_2000048a == 0) {
          DAT_2000048a = 0;
          DAT_2000048b = 1;
        }
      }
    }
    else {
      switch(DAT_2000048b) {
      case 0:
        DAT_20000488 = 0;
        DAT_20000489 = 0;
        DAT_2000048a = DAT_200016c0;
        DAT_2000048b = 1;
        break;
      case 1:
        DAT_20000489 = DAT_20000489 + 1;
        if (_DAT_200016c0 - 1U < (uint)DAT_20000489) {
          DAT_20000489 = DAT_200016c0;
          DAT_2000048b = 2;
        }
        break;
      case 2:
        DAT_2000048a = DAT_2000048a - 1;
        if (DAT_2000048a == 0) {
          DAT_2000048a = 0;
          DAT_2000048b = 3;
        }
        break;
      case 3:
        DAT_20000488 = DAT_20000488 + 1;
        if (_DAT_200016c0 - 1U < (uint)DAT_20000488) {
          DAT_20000488 = DAT_200016c0;
          DAT_2000048b = 4;
        }
        break;
      case 4:
        DAT_20000489 = DAT_20000489 - 1;
        if (DAT_20000489 == 0) {
          DAT_20000489 = 0;
          DAT_2000048b = 5;
        }
        break;
      case 5:
        DAT_2000048a = DAT_2000048a + 1;
        if (_DAT_200016c0 - 1U < (uint)DAT_2000048a) {
          DAT_2000048a = DAT_200016c0;
          DAT_2000048b = 6;
        }
        break;
      case 6:
        DAT_20000488 = DAT_20000488 - 1;
        if (DAT_20000488 == 0) {
          DAT_20000488 = 0;
          DAT_2000048b = 1;
        }
      }
    }
    FUN_080133f4(DAT_20000488,DAT_20000489,DAT_2000048a);
    DAT_2000048c = '\x01';
    DAT_2000048d = 0;
  }
  if (DAT_2000048c != '\0') {
    if (DAT_2000048d == 0) {
      for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
        FUN_08013016();
      }
    }
    else if (DAT_2000048d == 1) {
      for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
        FUN_08012e3a();
      }
    }
    else if (DAT_2000048d == 2) {
      for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
        FUN_08012c74();
      }
    }
    DAT_2000048d = DAT_2000048d + 1;
    if (2 < DAT_2000048d) {
      DAT_2000048d = 0;
      DAT_2000048c = '\0';
    }
  }
  return;
}

