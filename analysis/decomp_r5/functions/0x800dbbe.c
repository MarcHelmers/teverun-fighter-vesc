// rea decompile_all
// name: FUN_0800dbbe
// address: 0x800dbbe
// body: available
// range: 0x800dbbe-0x800dc43 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0800dbbe(void)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  char local_34;
  undefined1 local_33;
  byte local_32 [18];
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 local_10;
  
  uVar3 = 0;
  bVar1 = FUN_0800db7e(0x2000075c,(undefined4 *)&local_34);
  if (bVar1) {
    if (DAT_200003dc < 0x32) {
      DAT_200003dc = DAT_200003dc + 1;
    }
  }
  else {
    DAT_200003dc = 0;
    uVar2 = FUN_0800bd20((int)&local_34,0x13);
    if ((local_32[0x11] == uVar2) && (local_34 == -0x56)) {
      for (; uVar3 < 0x11; uVar3 = uVar3 + 1) {
        *(byte *)((int)&local_20 + uVar3 + 2) = local_32[uVar3];
      }
      local_20._0_2_ = CONCAT11(local_33,0xaa);
      local_10 = CONCAT13((char)uVar2,(undefined3)local_10);
      FUN_0800da74(local_20,uStack_1c,uStack_18,uStack_14,local_10);
    }
  }
  return;
}

