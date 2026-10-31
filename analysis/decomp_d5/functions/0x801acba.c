// rea decompile_all
// name: FUN_0801acba
// address: 0x801acba
// body: available
// range: 0x801acba-0x801ad51 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0801acba(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = FUN_0800b8ae(7,1,0x200005d8);
  DAT_20000074 = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(0x17,1,0x200005d8);
  DAT_20000075 = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(0x27,1,0x200005d8);
  DAT_20000076 = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(0x37,1,0x200005d8);
  DAT_20000077 = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(8,0xd,0x200005d8);
  uVar2 = FUN_0800b8ae(0x18,0xd,0x200005d8);
  uVar3 = FUN_0800b8ae(0x28,0xd,0x200005d8);
  uVar4 = FUN_0800b8ae(0x38,0xd,0x200005d8);
  DAT_2000032e = (char)((uVar1 & 0xffff) >> 8);
  DAT_2000032f = (char)(uVar1 & 0xffff);
  DAT_20000330 = (char)((uVar2 & 0xffff) >> 8);
  DAT_20000331 = (char)(uVar2 & 0xffff);
  DAT_20000332 = (char)((uVar3 & 0xffff) >> 8);
  DAT_20000333 = (char)(uVar3 & 0xffff);
  DAT_20000334 = (char)((uVar4 & 0xffff) >> 8);
  DAT_20000335 = (char)(uVar4 & 0xffff);
  return;
}

