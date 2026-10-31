// rea decompile_all
// name: FUN_0001a4fc
// address: 0x1a4fc
// body: available
// range: 0x1a4fc-0x1a519 inclusive
// range: 0x1a520-0x1a643 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0001a4fc(void)

{
  switch(DAT_20000298) {
  case 0:
    DAT_2000057b = (&DAT_200002aa)[(uint)DAT_20000298 * 0x14];
    FUN_0002527c(DAT_2000057b);
    break;
  case 1:
    FUN_000137cc((undefined4 *)0x20000a10);
    DAT_20000bfe = (&DAT_200002aa)[(uint)DAT_20000298 * 0x14];
    DAT_20000bc4 = DAT_20000bc4 & 0xfd | (&DAT_200002aa)[(uint)DAT_20000298 * 0x14] << 1;
    DAT_20000bb5 = 4;
    break;
  case 2:
    DAT_200005ac = (&DAT_200002aa)[(uint)DAT_20000298 * 0x14];
    break;
  case 3:
    FUN_000137cc((undefined4 *)0x20000a10);
    DAT_20000bb5 = 5;
    DAT_20000c0d = (&DAT_200002aa)[(uint)DAT_20000298 * 0x14];
    break;
  case 4:
    FUN_000137cc((undefined4 *)0x20000a10);
    DAT_20000bb5 = 5;
    DAT_20000bda = (&DAT_200002aa)[(uint)DAT_20000298 * 0x14];
    FUN_00028cb4();
  }
  return;
}

