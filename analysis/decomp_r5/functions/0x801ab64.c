// rea decompile_all
// name: FUN_0801ab64
// address: 0x801ab64
// body: available
// range: 0x801ab64-0x801ab9f inclusive
// range: 0x801ac74-0x801acd1 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0801ab64(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = FUN_0800b8ae(7,1,0x20000608);
  DAT_20000080 = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(0x17,1,0x20000608);
  DAT_20000081 = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(0x27,1,0x20000608);
  DAT_20000082 = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(0x37,1,0x20000608);
  DAT_20000083 = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(8,0xd,0x20000608);
  uVar2 = FUN_0800b8ae(0x18,0xd,0x20000608);
  uVar3 = FUN_0800b8ae(0x28,0xd,0x20000608);
  uVar4 = FUN_0800b8ae(0x38,0xd,0x20000608);
  DAT_20000346 = (char)((uVar1 & 0xffff) >> 8);
  DAT_20000347 = (char)(uVar1 & 0xffff);
  DAT_20000348 = (char)((uVar2 & 0xffff) >> 8);
  DAT_20000349 = (char)(uVar2 & 0xffff);
  DAT_2000034a = (char)((uVar3 & 0xffff) >> 8);
  DAT_2000034b = (char)(uVar3 & 0xffff);
  DAT_2000034c = (char)((uVar4 & 0xffff) >> 8);
  DAT_2000034d = (char)(uVar4 & 0xffff);
  return;
}

