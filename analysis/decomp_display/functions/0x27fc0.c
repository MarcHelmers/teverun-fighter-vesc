// rea decompile_all
// name: FUN_00027fc0
// address: 0x27fc0
// body: available
// range: 0x27fc0-0x27fd9 inclusive
// range: 0x27fe0-0x28097 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00027fc0(undefined1 param_1)

{
  switch(param_1) {
  case 0:
    _DAT_200005f4 = FUN_00028098(&DAT_200005c2,0x32);
    FUN_00028110(0x600000,0x34,&DAT_200005c2);
    break;
  case 1:
    _DAT_2000063c = FUN_00028098(&DAT_200005f8,0x44);
    FUN_00028110(0x601000,0x48,&DAT_200005f8);
    break;
  case 2:
    _DAT_2000064a = FUN_00028098(&DAT_20000640,10);
    FUN_00028110(0x602000,0xc,&DAT_20000640);
    break;
  case 3:
    _DAT_20000656 = FUN_00028098(&DAT_2000064c,10);
    FUN_00028110(0x603000,0xc,&DAT_2000064c);
    break;
  case 4:
    _DAT_20000668 = FUN_00028098(&DAT_20000658,0x10);
    FUN_00028110(0x604000,0x12,&DAT_20000658);
  }
  return;
}

