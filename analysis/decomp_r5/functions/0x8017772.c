// rea decompile_all
// name: FUN_08017772
// address: 0x8017772
// body: available
// range: 0x8017772-0x801785b inclusive
// range: 0x80178a0-0x801794d inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_08017772(void)

{
  uint uVar1;
  undefined1 auStack_5c [8];
  char local_54;
  char local_53;
  char local_52;
  char local_51;
  char local_50;
  char local_4f;
  char local_4e;
  char local_4d;
  ushort local_e;
  
  FUN_080170ca(0,0x50,auStack_5c);
  uVar1 = FUN_08016fde(auStack_5c,0x4e);
  if (local_e == uVar1) {
    if (((((local_54 == 'V') && (local_53 == 'C')) && (local_52 == 'U')) &&
        ((local_51 == '\x15' && (local_50 == '\x01')))) &&
       ((local_4f == '\x05' && ((local_4e == '\x04' && (local_4d == '\x13')))))) {
      FUN_0800b990(&DAT_200019d8,auStack_5c,0x50);
    }
    else {
      FUN_0800b990(&DAT_200019d8,auStack_5c,0x50);
      DAT_200019e0 = 0x56;
      DAT_200019e1 = 0x43;
      DAT_200019e2 = 0x55;
      DAT_200019e3 = 0x15;
      DAT_200019e4 = 1;
      DAT_200019e5 = 5;
      DAT_200019e6 = 4;
      DAT_200019e7 = 0x13;
      DAT_200019d8 = 0x56;
      DAT_200019d9 = 0x43;
      DAT_200019da = 0x55;
      DAT_200019db = 0;
      DAT_200019dc = 0x53;
      DAT_200019dd = 5;
      DAT_200019de = 0;
      DAT_200019df = 0;
      FUN_0801700c(0);
    }
  }
  else {
    FUN_080173a0();
  }
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

