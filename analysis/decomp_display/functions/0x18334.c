// rea decompile_all
// name: FUN_00018334
// address: 0x18334
// body: available
// range: 0x18334-0x183f3 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00018334(int param_1)

{
  byte local_7;
  
  if (DAT_200004ba == '\0') {
    for (local_7 = 0; (local_7 < 4 && (*(char *)(local_7 + 0x56fdd) != '\0')); local_7 = local_7 + 1
        ) {
      *(undefined1 *)(param_1 + (uint)local_7) = *(undefined1 *)(local_7 + 0x56fdd);
    }
    *(undefined1 *)(param_1 + 4) = 0;
  }
  else if (DAT_200004ba == '\x01') {
    for (local_7 = 0; (local_7 < 4 && (*(char *)(local_7 + 0x56fe9) != '\0')); local_7 = local_7 + 1
        ) {
      *(undefined1 *)(param_1 + (uint)local_7) = *(undefined1 *)(local_7 + 0x56fe9);
    }
    *(undefined1 *)(param_1 + 4) = 0;
  }
  return;
}

