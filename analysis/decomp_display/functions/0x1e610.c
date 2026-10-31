// rea decompile_all
// name: FUN_0001e610
// address: 0x1e610
// body: available
// range: 0x1e610-0x1e855 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001e610(short param_1,short param_2,short param_3,short param_4,undefined2 param_5)

{
  short sVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  short sVar5;
  short local_30;
  short local_2c;
  short local_28;
  short local_26;
  short local_24;
  short local_22;
  short local_14;
  
  if ((-1 < (int)((uint)*(byte *)(_DAT_20000ca0 + 0x14) * 0x40000000)) ||
     (iVar4 = (*(code *)_DAT_20000ca0[0x13])
                        ((int)param_1,(int)param_2,(int)param_3,(int)param_4,param_5), iVar4 != 0))
  {
    sVar1 = param_3 - param_1;
    sVar2 = param_4 - param_2;
    local_2c = sVar1;
    if (sVar1 < 1) {
      local_2c = -sVar1;
    }
    local_30 = sVar2;
    if (sVar2 < 1) {
      local_30 = -sVar2;
    }
    sVar3 = -1;
    sVar5 = -1;
    if (0 < sVar1) {
      sVar5 = 1;
    }
    if (0 < sVar2) {
      sVar3 = 1;
    }
    local_22 = (short)((uint)(int)local_30 >> 1);
    local_24 = (short)((uint)(int)local_2c >> 1);
    (*(code *)*_DAT_20000ca0)((int)param_1,(int)param_2,param_5);
    local_28 = param_2;
    local_26 = param_1;
    if (local_2c < local_30) {
      for (local_14 = 0; local_14 < local_30; local_14 = local_14 + 1) {
        local_22 = local_22 + local_2c;
        if (local_30 <= local_22) {
          local_22 = local_22 - local_30;
          local_26 = local_26 + sVar5;
        }
        local_28 = local_28 + sVar3;
        (*(code *)*_DAT_20000ca0)((int)local_26,(int)local_28,param_5);
      }
    }
    else {
      for (local_14 = 0; local_14 < local_2c; local_14 = local_14 + 1) {
        local_24 = local_24 + local_30;
        if (local_2c <= local_24) {
          local_24 = local_24 - local_2c;
          local_28 = local_28 + sVar3;
        }
        local_26 = local_26 + sVar5;
        (*(code *)*_DAT_20000ca0)((int)local_26,(int)local_28,param_5);
      }
    }
  }
  return;
}

