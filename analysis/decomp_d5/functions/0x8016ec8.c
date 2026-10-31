// rea decompile_all
// name: FUN_08016ec8
// address: 0x8016ec8
// body: available
// range: 0x8016ec8-0x8016ed3 inclusive
// range: 0x8016eda-0x8016f59 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08016ec8(undefined4 param_1)

{
  switch(param_1) {
  case 0:
    _DAT_20001a0e = FUN_08016e9a(&DAT_200019c0,0x4e);
    FUN_08016e7c(0,0x50,&DAT_200019c0);
    break;
  case 1:
    _DAT_20001a44 = FUN_08016e9a(&DAT_20001a10,0x34);
    FUN_08016e7c(0x50,0x38,&DAT_20001a10);
    break;
  case 2:
    _DAT_20001a52 = FUN_08016e9a(&DAT_20001a48,10);
    FUN_08016e7c(0x88,0xc,&DAT_20001a48);
    break;
  case 3:
    _DAT_20001a5e = FUN_08016e9a(&DAT_20001a54,10);
    FUN_08016e7c(0x94,0xc,&DAT_20001a54);
    break;
  case 4:
    _DAT_20001a6e = FUN_08016e9a(&DAT_20001a60,0xe);
    FUN_08016e7c(0xa0,0x10,&DAT_20001a60);
  }
  return;
}

