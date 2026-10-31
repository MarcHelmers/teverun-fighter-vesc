// rea decompile_all
// name: FUN_0801a80c
// address: 0x801a80c
// body: available
// range: 0x801a80c-0x801a885 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0801a80c(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = FUN_0800b8ae(0,8,0x20000640);
  uVar2 = FUN_0800b8ae(8,8,0x20000640);
  FUN_0800b8ae(0x10,8,0x20000640);
  FUN_0800b8ae(0x18,8,0x20000640);
  uVar3 = FUN_0800b8ae(0x38,0x20,0x20000640);
  DAT_20000363 = (char)uVar1;
  DAT_20000364 = (char)uVar2;
  DAT_2000036f = (char)(uVar3 >> 0x18);
  DAT_20000370 = (char)(uVar3 >> 0x10);
  DAT_20000371 = (char)(uVar3 >> 8);
  DAT_20000372 = (char)uVar3;
  return;
}

