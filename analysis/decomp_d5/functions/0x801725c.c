// rea decompile_all
// name: FUN_0801725c
// address: 0x801725c
// body: available
// range: 0x801725c-0x8017283 inclusive
// range: 0x801731c-0x801762d inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0801725c(void)

{
  uint uVar1;
  
  DAT_200019c0 = 0x56;
  DAT_200019c1 = 0x43;
  DAT_200019c2 = 0x55;
  DAT_200019c3 = 0;
  DAT_200019c4 = 0x53;
  DAT_200019c5 = 5;
  DAT_200019c6 = 0;
  DAT_200019c7 = 0;
  DAT_200019c8 = 0x56;
  DAT_200019c9 = 0x43;
  DAT_200019ca = 0x55;
  DAT_200019cb = 0xb;
  DAT_200019cc = 1;
  DAT_200019cd = 5;
  DAT_200019ce = 4;
  DAT_200019cf = 0xe;
  _DAT_200019d0 = 0x17;
  DAT_200019d2 = 0x30;
  DAT_200019d3 = 0x30;
  DAT_200019d4 = 0x30;
  DAT_200019d5 = 0x30;
  DAT_200019d6 = 0x30;
  DAT_200019d7 = 0x30;
  DAT_200019d8 = 0x30;
  DAT_200019d9 = 0x30;
  DAT_200019da = 0x30;
  DAT_200019db = 0x30;
  DAT_200019dc = 0x30;
  DAT_200019dd = 0x30;
  DAT_200019de = 0x30;
  DAT_200019df = 0x30;
  DAT_200019e0 = 0x30;
  DAT_200019e1 = 0x30;
  DAT_200019e2 = 0x30;
  DAT_200019e3 = 0x30;
  DAT_200019e4 = 0x30;
  DAT_200019e5 = 0x30;
  DAT_200019e6 = 0x30;
  DAT_200019e7 = 0x30;
  DAT_200019e8 = 0x30;
  DAT_200019e9 = 0x30;
  DAT_200019ea = 0x30;
  DAT_200019eb = 0x30;
  DAT_200019ec = 0x30;
  DAT_200019ed = 0x30;
  DAT_200019ee = 0x30;
  DAT_200019ef = 0x14;
  DAT_200019f0 = 0x16;
  DAT_200019f1 = 0xc;
  DAT_200019f2 = 1;
  DAT_200019f3 = 0;
  DAT_200019f4 = 0x41;
  DAT_200019f5 = 0x57;
  DAT_200019f6 = 0x50;
  DAT_200019f7 = 0x45;
  DAT_200019f8 = 0x2d;
  DAT_200019f9 = 0x56;
  DAT_200019fa = 0x43;
  DAT_200019fb = 0x55;
  DAT_200019fc = 0x2d;
  DAT_200019fd = 0x32;
  DAT_200019fe = 0x32;
  DAT_200019ff = 0x30;
  DAT_20001a00 = 0x32;
  DAT_20001a01 = 0x31;
  DAT_20001a02 = 0x32;
  DAT_20001a03 = 0;
  DAT_20001a04 = 0;
  DAT_20001a05 = 0;
  DAT_20001a06 = 0;
  DAT_20001a07 = 0x30;
  DAT_20001a08 = 0x31;
  DAT_20001a09 = 0x44;
  DAT_20001a0a = 0x42;
  DAT_20001a0b = 0x39;
  DAT_20001a0c = 0x39;
  FUN_08016ec8(0);
  for (uVar1 = 0; uVar1 < 5; uVar1 = uVar1 + 1) {
    *(undefined1 *)(uVar1 + 0x20000014) = (&DAT_200019c0)[uVar1];
  }
  DAT_20000019 = DAT_200019c5;
  DAT_2000001a = DAT_200019c6;
  DAT_2000001b = DAT_200019c7;
  for (uVar1 = 0; uVar1 < 5; uVar1 = uVar1 + 1) {
    *(undefined1 *)(uVar1 + 0x2000000c) = (&DAT_200019c8)[uVar1];
  }
  DAT_20000011 = DAT_200019cd;
  DAT_20000012 = DAT_200019ce;
  DAT_20000013 = DAT_200019cf;
  for (uVar1 = 0; uVar1 < 5; uVar1 = uVar1 + 1) {
    (&DAT_2000002c)[uVar1] = (&DAT_200019ef)[uVar1];
  }
  for (uVar1 = 0; uVar1 < 0x13; uVar1 = uVar1 + 1) {
    (&DAT_200006f6)[uVar1] = (&DAT_200019f4)[uVar1];
  }
  return;
}

