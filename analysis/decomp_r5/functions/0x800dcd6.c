// rea decompile_all
// name: FUN_0800dcd6
// address: 0x800dcd6
// body: available
// range: 0x800dcd6-0x800dd55 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_0800dcd6(undefined1 *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  if (DAT_20000394 == DAT_20000395) {
    uVar1 = 0;
  }
  else {
    *param_1 = *(undefined1 *)((uint)DAT_20000394 * 0x14 + 0x2000088b);
    param_1[1] = *(undefined1 *)((uint)DAT_20000394 * 0x14 + 0x2000088c);
    for (uVar2 = 0; uVar2 < 0x11; uVar2 = uVar2 + 1 & 0xff) {
      param_1[uVar2 + 2] = *(undefined1 *)((uint)DAT_20000394 * 0x14 + 0x2000088d + uVar2);
    }
    param_1[0x13] = *(undefined1 *)((uint)DAT_20000394 * 0x14 + 0x2000089e);
    DAT_20000394 = (char)(DAT_20000394 + 1) + (char)((DAT_20000394 + 1) / 0x14) * -0x14;
    uVar1 = 4;
  }
  return uVar1;
}

