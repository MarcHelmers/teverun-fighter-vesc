// rea decompile_all
// name: FUN_0800ad56
// address: 0x800ad56
// body: available
// range: 0x800ad56-0x800ae63 inclusive
// range: 0x800ae66-0x800ae71 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


bool FUN_0800ad56(int param_1,uint param_2)

{
  bool bVar1;
  
  if ((*(uint *)(param_1 + 0x14) & param_2) == 0) {
    bVar1 = false;
  }
  else if (param_2 == 0x100) {
    bVar1 = FUN_0800ad44(*(uint *)(param_1 + 0x18),1);
  }
  else {
    if ((int)param_2 < 0x101) {
      if (param_2 == 8) {
        bVar1 = FUN_0800ad44(*(uint *)(param_1 + 0xc),0x10);
        return bVar1;
      }
      if ((int)param_2 < 9) {
        if (param_2 == 1) {
          bVar1 = FUN_0800ad44(*(uint *)(param_1 + 8),0x10101);
          return bVar1;
        }
        if (param_2 == 2) {
          bVar1 = FUN_0800ad44(*(uint *)(param_1 + 0xc),3);
          return bVar1;
        }
        if (param_2 == 4) {
          bVar1 = FUN_0800ad44(*(uint *)(param_1 + 0xc),8);
          return bVar1;
        }
      }
      else {
        if (param_2 == 0x10) {
          bVar1 = FUN_0800ad44(*(uint *)(param_1 + 0x10),3);
          return bVar1;
        }
        if (param_2 == 0x20) {
          bVar1 = FUN_0800ad44(*(uint *)(param_1 + 0x10),8);
          return bVar1;
        }
        if (param_2 == 0x40) {
          bVar1 = FUN_0800ad44(*(uint *)(param_1 + 0x10),0x10);
          return bVar1;
        }
      }
    }
    else {
      if (param_2 == 0x8000) {
        bVar1 = FUN_0800ad44(*(uint *)(param_1 + 4),4);
        return bVar1;
      }
      if ((int)param_2 < 0x8001) {
        if (param_2 == 0x200) {
          bVar1 = FUN_0800ad44(*(uint *)(param_1 + 0x18),2);
          return bVar1;
        }
        if (param_2 == 0x400) {
          bVar1 = FUN_0800ad44(*(uint *)(param_1 + 0x18),4);
          return bVar1;
        }
        if (param_2 == 0x800) {
          bVar1 = FUN_0800ad44(*(uint *)(param_1 + 0x18),0x70);
          return bVar1;
        }
      }
      else {
        if (param_2 == 0x10000) {
          bVar1 = FUN_0800ad44(*(uint *)(param_1 + 4),8);
          return bVar1;
        }
        if (param_2 == 0x20000) {
          bVar1 = FUN_0800ad44(*(uint *)(param_1 + 4),0x10);
          return bVar1;
        }
      }
    }
    bVar1 = false;
  }
  return bVar1;
}

