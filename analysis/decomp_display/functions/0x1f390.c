// rea decompile_all
// name: FUN_0001f390
// address: 0x1f390
// body: available
// range: 0x1f390-0x1f4fd inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001f390(short param_1,short param_2,byte *param_3)

{
  byte bVar1;
  byte *pbVar2;
  uint local_1c;
  short local_14;
  short local_12;
  byte *local_10;
  
  local_14 = param_2;
  local_12 = param_1;
  local_10 = param_3;
  if (*(int *)(_DAT_20000ca0 + 100) != 0) {
    while (*local_10 != 0) {
      pbVar2 = local_10 + 1;
      bVar1 = *local_10;
      local_10 = pbVar2;
      if ((*(ushort *)(_DAT_20000ca0 + 0x36) <= (ushort)bVar1) &&
         ((ushort)bVar1 <= *(ushort *)(_DAT_20000ca0 + 0x38))) {
        if (bVar1 == 10) {
          local_12 = *(short *)(_DAT_20000ca0 + 4);
        }
        else {
          if (*(int *)(_DAT_20000ca0 + 0x3c) == 0) {
            local_1c = (uint)*(short *)(_DAT_20000ca0 + 0x32);
          }
          else {
            local_1c = (uint)*(byte *)(*(int *)(_DAT_20000ca0 + 0x3c) +
                                      ((uint)bVar1 - (uint)*(ushort *)(_DAT_20000ca0 + 0x36)));
          }
          if (*(short *)(_DAT_20000ca0 + 4) + -1 < (int)((int)local_12 + (local_1c & 0xff))) {
            local_14 = local_14 +
                       (short)*(char *)(_DAT_20000ca0 + 0x41) + *(short *)(_DAT_20000ca0 + 0x34);
            local_12 = param_1;
          }
          FUN_0001f500(bVar1,local_12,local_14,*(ushort *)(_DAT_20000ca0 + 0x42),
                       (uint)*(ushort *)(_DAT_20000ca0 + 0x44));
          local_12 = local_12 +
                     ((ushort)(byte)local_1c -
                     (ushort)*(byte *)(*(int *)(_DAT_20000ca0 + 100) +
                                      ((uint)bVar1 - (uint)*(ushort *)(_DAT_20000ca0 + 0x36))));
        }
      }
    }
  }
  return;
}

