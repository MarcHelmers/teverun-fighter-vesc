// rea decompile_all
// name: FUN_0800bad2
// address: 0x800bad2
// body: available
// range: 0x800bad2-0x800bb15 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0800bad2(int param_1,int param_2,int param_3)

{
  uint uVar1;
  byte abStack_34 [10];
  undefined1 auStack_2a [22];
  
  uVar1 = 0;
  FUN_0801ce64((undefined4 *)abStack_34,(undefined4 *)"AT+LENAME=1234567890123456789\r\n",0x20);
  if (param_2 == 0x13) {
    for (; uVar1 < 0x13; uVar1 = uVar1 + 1 & 0xff) {
      auStack_2a[uVar1] = *(undefined1 *)(param_1 + uVar1);
    }
    FUN_080199b6(abStack_34,0x1f);
    if (param_3 != 0) {
      DAT_2000004f = 1;
    }
  }
  return;
}

