// rea decompile_all
// name: FUN_0800ed34
// address: 0x800ed34
// body: available
// range: 0x800ed34-0x800ee07 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0800ed34(void)

{
  uint uVar1;
  
  FUN_0800b97a((undefined1 *)0x20000fe6,0,0x194);
  FUN_0800b97a((undefined1 *)0x2000117a,0,0x194);
  FUN_0800b97a(&DAT_2000130e,0,0x27);
  FUN_0800b97a(&DAT_20001335,0,0x13);
  FUN_0800b97a(&DAT_20001348,0,0x14);
  FUN_0800b97a(&DAT_2000135c,0,0xd);
  DAT_20000298 = 0;
  DAT_20000299 = 0;
  DAT_2000029a = 0;
  DAT_2000029b = 0;
  DAT_2000029c = 0;
  DAT_2000029d = 0;
  DAT_2000029e = 0;
  DAT_200002b1 = 0;
  DAT_200002be = 0;
  DAT_200002bf = 0;
  for (uVar1 = 0; uVar1 < 6; uVar1 = uVar1 + 1 & 0xff) {
    (&DAT_200002a5)[uVar1] = 0;
    (&DAT_2000029f)[uVar1] = 0;
    (&DAT_200002ab)[uVar1] = 0;
    (&DAT_200002b8)[uVar1] = 0;
    (&DAT_200002b2)[uVar1] = 0;
  }
  DAT_20000303 = 1;
  DAT_20000306 = 1;
  DAT_20000307 = 0;
  DAT_20000308 = 0;
  DAT_20000309 = 0;
  DAT_200002dc = 0x23;
  _DAT_200002da = 30000;
  DAT_200002c5 = 1;
  DAT_2000030c = 1;
  DAT_200002c6 = 0;
  DAT_200002c7 = 0;
  DAT_200002c8 = 0;
  DAT_20000390 = 0xff;
  return;
}

