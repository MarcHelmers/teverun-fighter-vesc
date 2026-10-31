// rea decompile_all
// name: FUN_00020238
// address: 0x20238
// body: available
// range: 0x20238-0x20391 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00020238(byte *param_1)

{
  byte bVar1;
  uint local_14;
  byte *local_c;
  
  local_c = param_1;
  while (*local_c != 0) {
    bVar1 = *local_c;
    if (bVar1 == 10) {
      *(undefined2 *)(_DAT_20000ca0 + 0x1c) = *(undefined2 *)(_DAT_20000ca0 + 4);
      local_c = local_c + 1;
    }
    else {
      if (*(int *)(_DAT_20000ca0 + 0x3c) == 0) {
        local_14 = (uint)*(short *)(_DAT_20000ca0 + 0x32);
      }
      else {
        local_14 = (uint)*(byte *)(*(int *)(_DAT_20000ca0 + 0x3c) +
                                  ((uint)bVar1 - (uint)*(ushort *)(_DAT_20000ca0 + 0x36)));
      }
      *(ushort *)(_DAT_20000ca0 + 0x1c) =
           *(short *)(_DAT_20000ca0 + 0x1c) +
           (short)*(char *)(_DAT_20000ca0 + 0x40) + (ushort)(byte)local_14;
      if ((int)*(short *)(_DAT_20000ca0 + 0x24) <
          (int)((int)*(short *)(_DAT_20000ca0 + 0x1c) + (local_14 & 0xff))) {
        *(undefined2 *)(_DAT_20000ca0 + 0x1c) = *(undefined2 *)(_DAT_20000ca0 + 0x20);
        *(short *)(_DAT_20000ca0 + 0x1e) =
             *(short *)(_DAT_20000ca0 + 0x1e) +
             (short)*(char *)(_DAT_20000ca0 + 0x41) + *(short *)(_DAT_20000ca0 + 0x34);
      }
      if ((int)*(short *)(_DAT_20000ca0 + 0x26) <
          (int)*(short *)(_DAT_20000ca0 + 0x1e) + (int)*(short *)(_DAT_20000ca0 + 0x34)) {
        *(undefined2 *)(_DAT_20000ca0 + 0x1c) = *(undefined2 *)(_DAT_20000ca0 + 0x20);
        *(undefined2 *)(_DAT_20000ca0 + 0x1e) = *(undefined2 *)(_DAT_20000ca0 + 0x22);
        FUN_0001e294(*(short *)(_DAT_20000ca0 + 0x20),*(short *)(_DAT_20000ca0 + 0x22),
                     *(short *)(_DAT_20000ca0 + 0x24),*(short *)(_DAT_20000ca0 + 0x26),
                     *(undefined2 *)(_DAT_20000ca0 + 0x2a));
      }
      FUN_0001f33c(bVar1,*(short *)(_DAT_20000ca0 + 0x1c),*(short *)(_DAT_20000ca0 + 0x1e),
                   *(ushort *)(_DAT_20000ca0 + 0x28),(uint)*(ushort *)(_DAT_20000ca0 + 0x2a));
      local_c = local_c + 1;
    }
  }
  return;
}

