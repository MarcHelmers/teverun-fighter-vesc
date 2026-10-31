// rea decompile_all
// name: FUN_0801b020
// address: 0x801b020
// body: available
// range: 0x801b020-0x801b06f inclusive
// range: 0x801b1ac-0x801b1fb inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0801b020(void)

{
  uint uVar1;
  
  uVar1 = FUN_0800b8ae(0x10,4,0x200005c8);
  DAT_20000380 = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(0x14,4,0x200005c8);
  DAT_20000381 = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(0x18,4,0x200005c8);
  DAT_2000037b = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(0x1c,4,0x200005c8);
  DAT_2000037a = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(0x20,4,0x200005c8);
  DAT_20000379 = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(0x24,4,0x200005c8);
  DAT_20000378 = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(0x28,4,0x200005c8);
  DAT_20000383 = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(0x2c,4,0x200005c8);
  DAT_20000382 = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(0x30,4,0x200005c8);
  DAT_20000386 = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(0x34,4,0x200005c8);
  DAT_20000385 = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(0x38,4,0x200005c8);
  DAT_20000384 = (char)uVar1;
  return;
}

