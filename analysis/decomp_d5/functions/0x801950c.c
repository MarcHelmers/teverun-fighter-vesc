// rea decompile_all
// name: FUN_0801950c
// address: 0x801950c
// body: available
// range: 0x801950c-0x80195a1 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0801950c(void)

{
  bool bVar1;
  byte local_24 [4];
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 local_18;
  ushort local_14 [4];
  undefined4 local_c;
  
  FUN_080081ca(0x1000,1);
  FUN_0800a552(0,7);
  FUN_08007e4a(0x20000,0x7000);
  FUN_0800795a(local_14);
  local_14[0] = 0x83;
  local_c = 3;
  FUN_08007776((uint *)0x40010800,local_14);
  local_14[0] = 3;
  local_c = 3;
  FUN_08007776((uint *)0x40010c00,local_14);
  local_24[0] = 0;
  local_24[1] = 0;
  local_20 = 0xe0000;
  local_1c = 0;
  local_18 = 1;
  FUN_0800a068(0x40020800,local_24);
  FUN_0800a0ba(0x40020800,1);
  do {
    bVar1 = FUN_0800a51a(0x40020800,0x20);
  } while (!bVar1);
  FUN_0800a0fe(0x40020800);
  do {
    bVar1 = FUN_0800a10c(0x40020800);
  } while (bVar1);
  return;
}

