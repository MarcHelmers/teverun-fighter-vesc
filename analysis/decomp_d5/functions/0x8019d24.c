// rea decompile_all
// name: FUN_08019d24
// address: 0x8019d24
// body: available
// range: 0x8019d24-0x8019db3 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_08019d24(int param_1,undefined4 param_2,undefined1 param_3,undefined1 param_4,int param_5,
                 undefined4 param_6,undefined1 param_7,undefined4 param_8,undefined4 param_9)

{
  undefined2 uVar1;
  
  if (param_1 < 0x16) {
    *(undefined4 *)(param_1 * 0x20 + 0x20002198) = param_2;
    *(undefined1 *)(param_1 * 0x20 + 0x200021a4) = param_4;
    *(undefined1 *)(param_1 * 0x20 + 0x2000219c) = param_3;
    *(int *)(param_1 * 0x20 + 0x200021a8) = param_5 * 10;
    *(undefined4 *)(param_1 * 0x20 + 0x200021a0) = param_6;
    *(undefined1 *)(param_1 * 0x20 + 0x200021a5) = (&DAT_200025a8)[param_1];
    *(undefined1 *)(param_1 * 0x20 + 0x200021a6) = 0;
    *(undefined1 *)(param_1 * 0x20 + 0x200021a7) = param_7;
    uVar1 = FUN_08018fce();
    *(undefined2 *)(param_1 * 0x20 + 0x200021ac) = uVar1;
    *(undefined4 *)(param_1 * 0x20 + 0x200021b0) = param_8;
    *(undefined4 *)(param_1 * 0x20 + 0x200021b4) = param_9;
  }
  return;
}

