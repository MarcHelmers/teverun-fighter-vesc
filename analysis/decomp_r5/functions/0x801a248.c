// rea decompile_all
// name: FUN_0801a248
// address: 0x801a248
// body: available
// range: 0x801a248-0x801a263 inclusive
// range: 0x801a2fc-0x801a3ab inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0801a248(void)

{
  uint uVar1;
  
  if ((DAT_2000029b & 0x80) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 8;
  }
  if (_DAT_20000034 < 0x1f5) {
    uVar1 = DAT_200002d4 & 0xd7 | uVar1;
  }
  else {
    uVar1 = DAT_200002d4 & 0xf7 | uVar1 | 0x20;
  }
  if (_DAT_20000036 < 0x1f5) {
    uVar1 = uVar1 & 0xbf;
  }
  else {
    uVar1 = uVar1 | 0x40;
  }
  if (_DAT_20000032 < 0x1f5) {
    uVar1 = uVar1 & 0xef;
  }
  else {
    uVar1 = uVar1 | 0x10;
  }
  if (DAT_20000305 == '\0') {
    uVar1 = uVar1 & 0xfd;
  }
  else {
    uVar1 = uVar1 | 2;
  }
  FUN_0800b97a((undefined1 *)0x20000578,0,8);
  FUN_0800b912(0,8,(uint)DAT_200002d3,0x20000578);
  FUN_0800b912(8,8,uVar1,0x20000578);
  FUN_0800b912(0x18,0x10,(uint)_DAT_200002d6,0x20000578);
  FUN_0800b912(0x20,8,(uint)DAT_200002d8,0x20000578);
  FUN_0800b912(0x30,0x10,(uint)_DAT_200002da,0x20000578);
  FUN_0800b912(0x38,8,(uint)DAT_200002dc,0x20000578);
  return;
}

