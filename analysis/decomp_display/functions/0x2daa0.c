// rea decompile_all
// name: FUN_0002daa0
// address: 0x2daa0
// body: available
// range: 0x2daa0-0x2dac3 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


longlong FUN_0002daa0(void)

{
  uint uVar1;
  uint extraout_r2;
  int extraout_r3;
  undefined4 *puVar2;
  int unaff_r7;
  undefined8 uVar3;
  
  for (puVar2 = (undefined4 *)&DAT_00057138; puVar2 < (undefined4 *)0x57158; puVar2 = puVar2 + 4) {
    (*(code *)puVar2[3])(*puVar2,puVar2[1],puVar2[2]);
  }
  uVar3 = FUN_000101b0();
  uVar1 = (uint)uVar3;
  *(char *)(unaff_r7 + 4) = (char)uVar3;
  *(char *)(extraout_r3 + 5) = (char)uVar3;
  if (0x1f < (int)extraout_r2) {
    return (ulonglong)(uVar1 << (extraout_r2 - 0x20 & 0xff)) << 0x20;
  }
  return CONCAT44((int)((ulonglong)uVar3 >> 0x20) << (extraout_r2 & 0xff) |
                  uVar1 >> (0x20 - extraout_r2 & 0xff),uVar1 << (extraout_r2 & 0xff));
}

