// rea decompile_all
// name: FUN_0800d162
// address: 0x800d162
// body: available
// range: 0x800d162-0x800d18d inclusive
// range: 0x800d224-0x800d251 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0800d162(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  undefined4 local_28 [4];
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uVar1 = 0;
  local_28[0] = param_1;
  local_28[1] = param_2;
  local_28[2] = param_3;
  local_28[3] = param_4;
  uStack_10 = param_1;
  uStack_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  FUN_0800b990((undefined1 *)local_28,(undefined1 *)((int)&uStack_10 + 2),0x10);
  if ((0x2f < (byte)local_28[0]) && ((byte)local_28[0] < 0x7b)) {
    DAT_20000051 = 1;
    for (; uVar1 < 0x10; uVar1 = uVar1 + 1 & 0xff) {
      *(undefined1 *)(uVar1 + 0x20000cba) = *(undefined1 *)((int)local_28 + uVar1);
    }
    for (uVar1 = 0x10; uVar1 < 0x13; uVar1 = uVar1 + 1 & 0xff) {
      *(undefined1 *)(uVar1 + 0x20000cba) = 0x20;
    }
  }
  return;
}

