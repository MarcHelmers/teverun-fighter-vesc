// rea decompile_all
// name: FUN_00021c74
// address: 0x21c74
// body: available
// range: 0x21c74-0x21e99 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00021c74(int param_1,short param_2,short param_3,short param_4,short param_5)

{
  short sVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  char local_9;
  
  iVar4 = FUN_00020444();
  sVar1 = (short)iVar4 + -1;
  iVar4 = FUN_00020454();
  sVar3 = (short)iVar4 + -1;
  if ((param_1 == 0) || (-1 < (int)((uint)*(byte *)(param_1 + 8) * 0x40000000))) {
    local_9 = -1;
  }
  else if ((param_2 < 0) || (0x7fffffff < (uint)(int)param_3)) {
    local_9 = -1;
  }
  else if ((sVar1 < param_4) || (sVar3 < param_5)) {
    local_9 = -1;
  }
  else if ((short)(param_4 - param_2) < 10) {
    local_9 = -1;
  }
  else if ((short)(param_5 - param_3) < 10) {
    local_9 = -1;
  }
  else {
    *(short *)(param_1 + 0xe) = param_2;
    *(short *)(param_1 + 0x10) = param_3;
    *(short *)(param_1 + 0x12) = param_4;
    *(short *)(param_1 + 0x14) = param_5;
    if (((int)((uint)*(byte *)(param_1 + 8) * 0x10000000) < 0) &&
       (*(int *)(_DAT_20000ca0 + 0x14) == param_1)) {
      if (*(short *)(param_1 + 0x10) != 0) {
        FUN_0001e294(0,0,sVar1,*(short *)(param_1 + 0x10) + -1,*(undefined2 *)(_DAT_20000ca0 + 0x46)
                    );
      }
      sVar2 = *(short *)(param_1 + 0x14) + 1;
      if (sVar2 <= sVar3) {
        FUN_0001e294(0,sVar2,sVar1,sVar3,*(undefined2 *)(_DAT_20000ca0 + 0x46));
      }
      if (*(short *)(param_1 + 0xe) != 0) {
        FUN_0001e294(0,*(short *)(param_1 + 0x10),*(short *)(param_1 + 0xe) + -1,
                     *(short *)(param_1 + 0x14),*(undefined2 *)(_DAT_20000ca0 + 0x46));
      }
      sVar3 = *(short *)(param_1 + 0x12) + 1;
      if (sVar3 <= sVar1) {
        FUN_0001e294(sVar3,*(short *)(param_1 + 0x10),sVar1,*(short *)(param_1 + 0x14),
                     *(undefined2 *)(_DAT_20000ca0 + 0x46));
      }
      *(byte *)(param_1 + 8) = *(byte *)(param_1 + 8) & 0xbf;
      *(byte *)(param_1 + 8) = *(byte *)(param_1 + 8) | 0x20;
    }
    local_9 = '\0';
  }
  return (int)local_9;
}

