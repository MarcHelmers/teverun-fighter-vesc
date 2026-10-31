// rea decompile_all
// name: FUN_0801358c
// address: 0x801358c
// body: available
// range: 0x801358c-0x80135c1 inclusive
// range: 0x80135ca-0x801368f inclusive
// range: 0x8013692-0x80136bb inclusive
// range: 0x80136c4-0x801387f inclusive
// range: 0x80138b4-0x8013979 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0801358c(void)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = FUN_08013326((uint *)0x2000170c,_DAT_20001704);
  if (iVar2 == 1) {
    FUN_08013320((undefined4 *)0x2000170c);
    if (DAT_20001710 == '\0') {
      switch(DAT_200004a3) {
      case 0:
        DAT_200004a0 = DAT_200016d8;
        DAT_200004a1 = 0;
        DAT_200004a2 = 0;
        DAT_200004a3 = 1;
        break;
      case 1:
        DAT_200004a1 = DAT_200004a1 + 1;
        if (_DAT_200016d8 - 1U < (uint)DAT_200004a1) {
          DAT_200004a1 = DAT_200016d8;
          DAT_200004a3 = 2;
        }
        break;
      case 2:
        DAT_200004a0 = DAT_200004a0 - 1;
        if (DAT_200004a0 == 0) {
          DAT_200004a0 = 0;
          DAT_200004a3 = 3;
        }
        break;
      case 3:
        DAT_200004a2 = DAT_200004a2 + 1;
        if (_DAT_200016d8 - 1U < (uint)DAT_200004a2) {
          DAT_200004a2 = DAT_200016d8;
          DAT_200004a3 = 4;
        }
        break;
      case 4:
        DAT_200004a1 = DAT_200004a1 - 1;
        if (DAT_200004a1 == 0) {
          DAT_200004a1 = 0;
          DAT_200004a3 = 5;
        }
        break;
      case 5:
        DAT_200004a0 = DAT_200004a0 + 1;
        if (_DAT_200016d8 - 1U < (uint)DAT_200004a0) {
          DAT_200004a0 = DAT_200016d8;
          DAT_200004a3 = 6;
        }
        break;
      case 6:
        DAT_200004a2 = DAT_200004a2 - 1;
        if (DAT_200004a2 == 0) {
          DAT_200004a2 = 0;
          DAT_200004a3 = 1;
        }
      }
    }
    else {
      switch(DAT_200004a3) {
      case 0:
        DAT_200004a0 = 0;
        DAT_200004a1 = 0;
        DAT_200004a2 = DAT_200016d8;
        DAT_200004a3 = 1;
        break;
      case 1:
        DAT_200004a1 = DAT_200004a1 + 1;
        if (_DAT_200016d8 - 1U < (uint)DAT_200004a1) {
          DAT_200004a1 = DAT_200016d8;
          DAT_200004a3 = 2;
        }
        break;
      case 2:
        DAT_200004a2 = DAT_200004a2 - 1;
        if (DAT_200004a2 == 0) {
          DAT_200004a2 = 0;
          DAT_200004a3 = 3;
        }
        break;
      case 3:
        DAT_200004a0 = DAT_200004a0 + 1;
        if (_DAT_200016d8 - 1U < (uint)DAT_200004a0) {
          DAT_200004a0 = DAT_200016d8;
          DAT_200004a3 = 4;
        }
        break;
      case 4:
        DAT_200004a1 = DAT_200004a1 - 1;
        if (DAT_200004a1 == 0) {
          DAT_200004a1 = 0;
          DAT_200004a3 = 5;
        }
        break;
      case 5:
        DAT_200004a2 = DAT_200004a2 + 1;
        if (_DAT_200016d8 - 1U < (uint)DAT_200004a2) {
          DAT_200004a2 = DAT_200016d8;
          DAT_200004a3 = 6;
        }
        break;
      case 6:
        DAT_200004a0 = DAT_200004a0 - 1;
        if (DAT_200004a0 == 0) {
          DAT_200004a0 = 0;
          DAT_200004a3 = 1;
        }
      }
    }
    FUN_08013538(DAT_200004a0,DAT_200004a1,DAT_200004a2);
    DAT_200004a4 = '\x01';
    DAT_200004a5 = 0;
  }
  if (DAT_200004a4 != '\0') {
    if (DAT_200004a5 == 0) {
      for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
        FUN_0801315a();
      }
    }
    else if (DAT_200004a5 == 1) {
      for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
        FUN_08012f7e();
      }
    }
    else if (DAT_200004a5 == 2) {
      for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
        FUN_08012db8();
      }
    }
    DAT_200004a5 = DAT_200004a5 + 1;
    if (2 < DAT_200004a5) {
      DAT_200004a5 = 0;
      DAT_200004a4 = '\0';
    }
  }
  return;
}

