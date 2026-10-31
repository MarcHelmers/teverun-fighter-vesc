// rea decompile_all
// name: FUN_08017264
// address: 0x8017264
// body: available
// range: 0x8017264-0x801739f inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_08017264(void)

{
  uint uVar1;
  undefined1 auStack_44 [52];
  ushort local_10;
  
  FUN_080170ca(0x50,0x38,auStack_44);
  uVar1 = FUN_08016fde(auStack_44,0x34);
  if (local_10 == uVar1) {
    FUN_0800b990(&DAT_20001a28,auStack_44,0x38);
  }
  else {
    FUN_0801720a();
  }
  DAT_200002d1 = DAT_20001a28;
  DAT_2000029a = DAT_20001a29;
  DAT_2000029b = DAT_20001a28;
  DAT_2000029e = DAT_20001a2c;
  DAT_200002b1 = DAT_20001a2d;
  DAT_200002be = DAT_20001a2e;
  DAT_200002bf = DAT_20001a2f;
  DAT_200002d2 = DAT_20001a30 & 0xfe;
  DAT_20000299 = DAT_20001a31;
  DAT_20000305 = DAT_20001a55;
  DAT_2000030a = DAT_20001a56;
  DAT_2000029c = 0x1e;
  DAT_2000029d = 100;
  if (1 < DAT_20001a56) {
    DAT_2000030a = 0;
  }
  for (uVar1 = 0; uVar1 < 6; uVar1 = uVar1 + 1 & 0xff) {
    (&DAT_2000029f)[uVar1] = (&DAT_20001a33)[uVar1 * 6];
    (&DAT_200002a5)[uVar1] = (&DAT_20001a34)[uVar1 * 6];
    (&DAT_200002ab)[uVar1] = (&DAT_20001a32)[uVar1 * 6];
    (&DAT_200002b2)[uVar1] = (&DAT_20001a35)[uVar1 * 6];
    (&DAT_200002b8)[uVar1] = (&DAT_20001a36)[uVar1 * 6];
  }
  DAT_20000300 = (DAT_200002d2 & 2) != 0;
  return;
}

