// rea decompile_all
// name: FUN_000212b4
// address: 0x212b4
// body: available
// range: 0x212b4-0x213c1 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000212b4(int *param_1)

{
  byte *pbStack00000004;
  
  if (((int)((uint)*(byte *)(*(int *)(*param_1 + 0x18) + 8) * 0x10000000) < 0) &&
     ((((*(short *)(*(int *)(_DAT_20000ca0 + 0x18) + 0xe) !=
         *(short *)(*(int *)(_DAT_20000ca0 + 0x14) + 0xe) ||
        (*(short *)(*(int *)(_DAT_20000ca0 + 0x18) + 0x12) !=
         *(short *)(*(int *)(_DAT_20000ca0 + 0x14) + 0x12))) ||
       (*(short *)(*(int *)(_DAT_20000ca0 + 0x18) + 0x10) !=
        *(short *)(*(int *)(_DAT_20000ca0 + 0x14) + 0x10))) ||
      (*(short *)(*(int *)(_DAT_20000ca0 + 0x18) + 0x14) !=
       *(short *)(*(int *)(_DAT_20000ca0 + 0x14) + 0x14))))) {
    FUN_000213c4(*(int *)(_DAT_20000ca0 + 0x18));
  }
  *(byte *)(*(int *)(_DAT_20000ca0 + 0x14) + 8) =
       *(byte *)(*(int *)(_DAT_20000ca0 + 0x14) + 8) & 0xbf;
  *(byte *)(*(int *)(_DAT_20000ca0 + 0x14) + 8) =
       *(byte *)(*(int *)(_DAT_20000ca0 + 0x14) + 8) | 0x28;
  if (*(int *)(_DAT_20000ca0 + 0x14) != 0) {
    pbStack00000004 = *(byte **)(_DAT_20000ca0 + 0x14);
    if ((int)((uint)pbStack00000004[8] * 0x4000000) < 0) {
      FUN_00021534(pbStack00000004);
    }
    if ((int)((uint)pbStack00000004[8] * 0x10000000) < 0) {
      FUN_0002090c(pbStack00000004);
      FUN_00020b0c(pbStack00000004);
      FUN_00020bc0(pbStack00000004);
    }
  }
  return;
}

