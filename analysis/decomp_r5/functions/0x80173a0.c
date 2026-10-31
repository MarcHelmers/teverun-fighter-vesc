// rea decompile_all
// name: FUN_080173a0
// address: 0x80173a0
// body: available
// range: 0x80173a0-0x80173c7 inclusive
// range: 0x8017460-0x8017771 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_080173a0(void)

{
  uint uVar1;
  
  DAT_200019d8 = 0x56;
  DAT_200019d9 = 0x43;
  DAT_200019da = 0x55;
  DAT_200019db = 0;
  DAT_200019dc = 0x53;
  DAT_200019dd = 5;
  DAT_200019de = 0;
  DAT_200019df = 0;
  DAT_200019e0 = 0x56;
  DAT_200019e1 = 0x43;
  DAT_200019e2 = 0x55;
  DAT_200019e3 = 0x15;
  DAT_200019e4 = 1;
  DAT_200019e5 = 5;
  DAT_200019e6 = 4;
  DAT_200019e7 = 0x13;
  _DAT_200019e8 = 0x17;
  DAT_200019ea = 0x30;
  DAT_200019eb = 0x30;
  DAT_200019ec = 0x30;
  DAT_200019ed = 0x30;
  DAT_200019ee = 0x30;
  DAT_200019ef = 0x30;
  DAT_200019f0 = 0x30;
  DAT_200019f1 = 0x30;
  DAT_200019f2 = 0x30;
  DAT_200019f3 = 0x30;
  DAT_200019f4 = 0x30;
  DAT_200019f5 = 0x30;
  DAT_200019f6 = 0x30;
  DAT_200019f7 = 0x30;
  DAT_200019f8 = 0x30;
  DAT_200019f9 = 0x30;
  DAT_200019fa = 0x30;
  DAT_200019fb = 0x30;
  DAT_200019fc = 0x30;
  DAT_200019fd = 0x30;
  DAT_200019fe = 0x30;
  DAT_200019ff = 0x30;
  DAT_20001a00 = 0x30;
  DAT_20001a01 = 0x30;
  DAT_20001a02 = 0x30;
  DAT_20001a03 = 0x30;
  DAT_20001a04 = 0x30;
  DAT_20001a05 = 0x30;
  DAT_20001a06 = 0x30;
  DAT_20001a07 = 0x14;
  DAT_20001a08 = 0x16;
  DAT_20001a09 = 0xc;
  DAT_20001a0a = 1;
  DAT_20001a0b = 0;
  DAT_20001a0c = 0x41;
  DAT_20001a0d = 0x57;
  DAT_20001a0e = 0x50;
  DAT_20001a0f = 0x45;
  DAT_20001a10 = 0x2d;
  DAT_20001a11 = 0x56;
  DAT_20001a12 = 0x43;
  DAT_20001a13 = 0x55;
  DAT_20001a14 = 0x2d;
  DAT_20001a15 = 0x32;
  DAT_20001a16 = 0x32;
  DAT_20001a17 = 0x30;
  DAT_20001a18 = 0x32;
  DAT_20001a19 = 0x31;
  DAT_20001a1a = 0x32;
  DAT_20001a1b = 0;
  DAT_20001a1c = 0;
  DAT_20001a1d = 0;
  DAT_20001a1e = 0;
  DAT_20001a1f = 0x30;
  DAT_20001a20 = 0x31;
  DAT_20001a21 = 0x44;
  DAT_20001a22 = 0x42;
  DAT_20001a23 = 0x39;
  DAT_20001a24 = 0x39;
  FUN_0801700c(0);
  for (uVar1 = 0; uVar1 < 5; uVar1 = uVar1 + 1) {
    *(undefined1 *)(uVar1 + 0x20000014) = (&DAT_200019d8)[uVar1];
  }
  DAT_20000019 = DAT_200019dd;
  DAT_2000001a = DAT_200019de;
  DAT_2000001b = DAT_200019df;
  for (uVar1 = 0; uVar1 < 5; uVar1 = uVar1 + 1) {
    *(undefined1 *)(uVar1 + 0x2000000c) = (&DAT_200019e0)[uVar1];
  }
  DAT_20000011 = DAT_200019e5;
  DAT_20000012 = DAT_200019e6;
  DAT_20000013 = DAT_200019e7;
  for (uVar1 = 0; uVar1 < 5; uVar1 = uVar1 + 1) {
    (&DAT_2000002c)[uVar1] = (&DAT_20001a07)[uVar1];
  }
  for (uVar1 = 0; uVar1 < 0x13; uVar1 = uVar1 + 1) {
    (&DAT_2000070e)[uVar1] = (&DAT_20001a0c)[uVar1];
  }
  return;
}

