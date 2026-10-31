// rea decompile_all
// name: FUN_0001c7d8
// address: 0x1c7d8
// body: available
// range: 0x1c7d8-0x1c977 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0001c7d8(void)

{
  bool bVar1;
  
  bVar1 = FUN_0001c978((uint *)0x20000a0c,0x14);
  if (bVar1) {
    FUN_0001c9b8((undefined4 *)0x20000a0c);
    FUN_0001c9c8(1);
  }
  bVar1 = FUN_0001c978((uint *)0x20000a10,0x14);
  if (bVar1) {
    FUN_0001c9b8((undefined4 *)0x20000a10);
    FUN_0001c9c8(2);
  }
  bVar1 = FUN_0001c978((uint *)0x20000a14,2);
  if (bVar1) {
    FUN_0001c9b8((undefined4 *)0x20000a14);
    FUN_0001c9c8(4);
  }
  bVar1 = FUN_0001c978((uint *)0x20000a18,10);
  if (bVar1) {
    FUN_0001c9b8((undefined4 *)0x20000a18);
    FUN_0001c9c8(8);
  }
  if ((DAT_20000a08 & 1) != 0) {
    FUN_0001c9e4(1);
    DAT_2000053e = '\x02';
  }
  if ((int)((uint)DAT_20000a08 * 0x40000000) < 0) {
    FUN_0001c9e4(2);
    DAT_20000bb5 = 0;
    DAT_2000053d = 0;
  }
  if ((int)((uint)DAT_20000a08 * 0x20000000) < 0) {
    FUN_0001c9e4(4);
    FUN_0002527c(DAT_2000057b);
  }
  if (((int)((uint)DAT_20000a08 * 0x10000000) < 0) && (FUN_0001c9e4(8), DAT_2000053e == '\x06')) {
    DAT_20000140 = DAT_20000140 + '\x01';
    DAT_2000053e = '\x04';
  }
  return;
}

