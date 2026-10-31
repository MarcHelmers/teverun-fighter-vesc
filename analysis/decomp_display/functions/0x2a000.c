// rea decompile_all
// name: FUN_0002a000
// address: 0x2a000
// body: available
// range: 0x2a000-0x2a083 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0002a000(void)

{
  ushort local_1c;
  undefined1 local_1a;
  undefined2 local_18;
  undefined1 local_16;
  byte local_14;
  undefined1 local_13;
  undefined1 local_12;
  undefined1 local_11;
  
  FUN_000115e0((uint *)0x400a0020,5,0xf,0);
  FUN_000115e0((uint *)0x400a0020,4,0xf,0);
  local_14 = 0xc;
  local_13 = 0;
  local_12 = local_13;
  local_11 = local_13;
  FUN_00010200((uint *)0x40049000,&local_14);
  local_1c = 6;
  local_1a = 1;
  local_18 = 1;
  local_16 = 0;
  FUN_000103c8(0x40049000,1,&local_1c);
  FUN_0001060c((uint *)0x40049000);
  FUN_00010648(0x40049000);
  DAT_200000e0 = 0;
  return;
}

