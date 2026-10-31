// rea decompile_all
// name: FUN_0801828c
// address: 0x801828c
// body: available
// range: 0x801828c-0x801842d inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0801828c(void)

{
  int iVar1;
  char cVar2;
  char cVar3;
  
  cVar2 = '\0';
  cVar3 = '\0';
  iVar1 = 0;
  if ((DAT_20000501 != 0) && (DAT_20000501 = DAT_20000501 + 1, 5 < DAT_20000501)) {
    DAT_20000501 = 0;
    if ((_DAT_2000003e < 0x12d) || (699 < _DAT_2000003e)) {
      if ((_DAT_2000003e < 0x321) || (0x4af < _DAT_2000003e)) {
        if ((_DAT_2000003e < 0x515) || (0x6a3 < _DAT_2000003e)) {
          if ((_DAT_2000003e < 0x709) || (0x897 < _DAT_2000003e)) {
            if ((_DAT_2000003e < 0x8fd) || (0xa8b < _DAT_2000003e)) {
              if ((_DAT_2000003e < 0xaf1) || (0xc7f < _DAT_2000003e)) {
                iVar1 = 1;
              }
              else {
                cVar2 = '\x06';
              }
            }
            else {
              cVar2 = '\x05';
            }
          }
          else {
            cVar2 = '\x04';
          }
        }
        else {
          cVar2 = '\x03';
        }
      }
      else {
        cVar2 = '\x02';
      }
    }
    else {
      cVar2 = '\x01';
    }
    if (_DAT_20000040 < 200) {
      cVar3 = '\0';
    }
    else if ((_DAT_20000040 < 0x12d) || (699 < _DAT_20000040)) {
      if ((_DAT_20000040 < 0x321) || (0x4af < _DAT_20000040)) {
        if ((_DAT_20000040 < 0x515) || (0x6a3 < _DAT_20000040)) {
          if ((_DAT_20000040 < 0x709) || (0x897 < _DAT_20000040)) {
            if ((_DAT_20000040 < 0x8fd) || (0xa8b < _DAT_20000040)) {
              if ((_DAT_20000040 < 0xaf1) || (0xc7f < _DAT_20000040)) {
                iVar1 = iVar1 + 1;
              }
              else {
                cVar3 = '\x06';
              }
            }
            else {
              cVar3 = '\x05';
            }
          }
          else {
            cVar3 = '\x04';
          }
        }
        else {
          cVar3 = '\x03';
        }
      }
      else {
        cVar3 = '\x02';
      }
    }
    else {
      cVar3 = '\x01';
    }
    if ((iVar1 == 0) && ((DAT_20000019 != cVar2 || (DAT_2000001a != cVar3)))) {
      DAT_200019df = 0;
      DAT_20000019 = cVar2;
      DAT_2000001a = cVar3;
      DAT_200019dd = cVar2;
      DAT_200019de = cVar3;
      FUN_0801700c(0);
    }
  }
  return;
}

