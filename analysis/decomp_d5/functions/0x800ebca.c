// rea decompile_all
// name: FUN_0800ebca
// address: 0x800ebca
// body: available
// range: 0x800ebca-0x800ec0f inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0800ebca(int param_1)

{
  byte bVar1;
  
  if (param_1 != 0xff) {
    bVar1 = (byte)param_1;
    DAT_20000070 = bVar1 & 1;
    DAT_20000071 = bVar1 & 2;
    DAT_20000072 = bVar1 & 4;
    DAT_20000073 = bVar1 & 8;
    DAT_20000074 = bVar1 & 0x10;
    DAT_20000075 = bVar1 & 0x20;
    DAT_20000076 = bVar1 & 0x40;
    DAT_20000077 = bVar1 & 0x80;
  }
  return;
}

