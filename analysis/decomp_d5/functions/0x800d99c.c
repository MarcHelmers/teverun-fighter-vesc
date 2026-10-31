// rea decompile_all
// name: FUN_0800d99c
// address: 0x800d99c
// body: available
// range: 0x800d99c-0x800d9c7 inclusive
// range: 0x800d9d2-0x800da73 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0800d99c(void)

{
  int iVar1;
  uint uVar2;
  uint local_1c;
  uint uStack_18;
  undefined4 uStack_14;
  uint uStack_10;
  
  iVar1 = FUN_0800d91c((undefined1 *)&local_1c);
  if (iVar1 == 6) {
    if ((char)local_1c == -0x56) {
      uVar2 = local_1c >> 8 & 0xff;
      if (uVar2 == 0x11) {
        FUN_0800d548(local_1c,uStack_18,uStack_14,uStack_10);
      }
      else if (uVar2 < 0x12) {
        switch(uVar2) {
        case 1:
          FUN_0800d8d6(local_1c,uStack_18);
          break;
        case 2:
          FUN_0800d8ba(local_1c,uStack_18,uStack_14,uStack_10);
          break;
        case 3:
          break;
        case 4:
          FUN_0800d86c(local_1c,uStack_18,uStack_14,uStack_10);
        case 8:
          FUN_0800d824(local_1c,uStack_18,uStack_14,uStack_10);
        }
      }
      else if (uVar2 == 0x12) {
        FUN_0800d4b0(local_1c,uStack_18,uStack_14,uStack_10);
      }
      else if (uVar2 == 0x18) {
        FUN_0800d252(local_1c,uStack_18,uStack_14,uStack_10);
      }
      else if (uVar2 == 0x1a) {
        FUN_0800d0ee(local_1c,uStack_18,uStack_14,uStack_10);
      }
      else if (uVar2 == 0x1f) {
        FUN_0800d162(local_1c,uStack_18,uStack_14,uStack_10);
      }
    }
    FUN_08016b1a((int)&local_1c,0x14);
  }
  return;
}

