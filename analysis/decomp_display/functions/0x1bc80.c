// rea decompile_all
// name: FUN_0001bc80
// address: 0x1bc80
// body: available
// range: 0x1bc80-0x1bc9d inclusive
// range: 0x1bcae-0x1bf1b inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0001bc80(void)

{
  switch(DAT_20000458) {
  case 0:
    FUN_000137cc((undefined4 *)0x20000a10);
    DAT_20000bfd = (&DAT_2000046a)[(uint)DAT_20000458 * 0x14];
    DAT_20000bb5 = 5;
    break;
  case 1:
    FUN_000137cc((undefined4 *)0x20000a10);
    DAT_20000bb5 = 5;
    DAT_20000bfa = (&DAT_2000046a)[(uint)DAT_20000458 * 0x14];
    break;
  case 2:
    FUN_000137cc((undefined4 *)0x20000a10);
    DAT_20000bb5 = 5;
    DAT_20000bde = (&DAT_2000046a)[(uint)DAT_20000458 * 0x14];
    DAT_20000bae = DAT_20000bae & 0xf9 | DAT_20000bde << 1;
    break;
  case 3:
    FUN_000137cc((undefined4 *)0x20000a10);
    DAT_20000bb5 = 5;
    DAT_20000bdd = (&DAT_2000046a)[(uint)DAT_20000458 * 0x14];
    if (DAT_20000bdd == '\0') {
      DAT_20000bae = DAT_20000bae & 0xf7;
    }
    else {
      DAT_20000bae = DAT_20000bae | 8;
    }
    break;
  case 4:
    FUN_000137cc((undefined4 *)0x20000a10);
    DAT_20000bb5 = 5;
    DAT_20000bf9 = (&DAT_2000046a)[(uint)DAT_20000458 * 0x14];
    if (DAT_20000bf9 == '\0') {
      DAT_20000bae = DAT_20000bae & 0xef;
    }
    else {
      DAT_20000bae = DAT_20000bae | 0x10;
    }
    break;
  case 5:
    FUN_000137cc((undefined4 *)0x20000a10);
    DAT_20000bb5 = 5;
    DAT_20000bfb = (&DAT_2000046a)[(uint)DAT_20000458 * 0x14];
    break;
  case 6:
    FUN_000137cc((undefined4 *)0x20000a10);
    DAT_20000bb5 = 7;
    DAT_20000bfc = (&DAT_2000046a)[(uint)DAT_20000458 * 0x14];
    if (DAT_20000bfc == '\0') {
      DAT_20000bc4 = DAT_20000bc4 & 0xef;
    }
    else {
      DAT_20000bc4 = DAT_20000bc4 | 0x10;
    }
    break;
  case 7:
    FUN_000137cc((undefined4 *)0x20000a10);
    DAT_20000bb5 = 5;
    DAT_20000bf2 = (&DAT_2000046a)[(uint)DAT_20000458 * 0x14];
  }
  return;
}

