// rea decompile_all
// name: FUN_0800ea76
// address: 0x800ea76
// body: available
// range: 0x800ea76-0x800eac5 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0800ea76(void)

{
  undefined1 uVar1;
  uint uVar2;
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined3 local_c;
  undefined1 uStack_9;
  
  local_1c = CONCAT22(local_1c._2_2_,0x6255);
  FUN_0800b990((undefined1 *)((int)&local_1c + 2),(undefined1 *)0x200003ad,6);
  for (uVar2 = 6; uVar2 < 0x10; uVar2 = uVar2 + 1 & 0xff) {
    *(undefined1 *)((int)&local_1c + uVar2 + 3) = 0xff;
  }
  uVar1 = FUN_0800bd20((int)&local_1c,0x13);
  _local_c = CONCAT13(uVar1,local_c);
  FUN_0800bcce(local_1c,uStack_18,uStack_14,uStack_10);
  return;
}

