// rea decompile_all
// name: FUN_00024d48
// address: 0x24d48
// body: available
// range: 0x24d48-0x24e2b inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00024d48(int param_1,byte *param_2)

{
  short local_1c;
  short local_1a;
  int *local_14;
  byte *local_10;
  int local_c;
  
  local_14 = *(int **)(param_2 + 0x1c);
  if ((int)((uint)*param_2 * 0x4000000) < 0) {
    local_10 = param_2;
    local_c = param_1;
    if ((int)((uint)*param_2 * 0x10000000) < 0) {
      if ((int)((uint)*param_2 * 0x2000000) < 0) {
        FUN_000227a4(param_1,&local_1c);
        *(short *)(local_10 + 8) = *(short *)(local_10 + 0x10) + local_1c;
        *(short *)(local_10 + 10) = *(short *)(local_10 + 0x12) + local_1a;
        *(short *)(local_10 + 0xc) =
             *(short *)(local_10 + 0x10) + *(short *)(*local_14 + 4) + local_1c;
        *(short *)(local_10 + 0xe) =
             *(short *)(local_10 + 0x12) + *(short *)(*local_14 + 6) + local_1a;
        if ((*local_14 != 0) && ((*(byte *)(local_14 + 1) & 1) != 0)) {
          FUN_000216fc(*(short *)(local_10 + 8),*(short *)(local_10 + 10),(int *)*local_14);
        }
        *local_10 = *local_10 & 0xbf;
      }
    }
    else {
      FUN_0001e294(*(short *)(param_2 + 8),*(short *)(param_2 + 10),*(short *)(param_2 + 0xc),
                   *(short *)(param_2 + 0xe),*(undefined2 *)(param_1 + 0xc));
    }
    *local_10 = *local_10 & 0xdf;
  }
  return;
}

