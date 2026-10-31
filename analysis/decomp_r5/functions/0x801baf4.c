// rea decompile_all
// name: FUN_0801baf4
// address: 0x801baf4
// body: available
// range: 0x801baf4-0x801bbcb inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0801baf4(void)

{
  undefined2 uVar1;
  uint uVar2;
  int iVar3;
  
  FUN_08016ab2(_DAT_200025e4,&DAT_200025ef);
  uVar2 = 0;
  while( true ) {
    if (0x15 < uVar2) {
      return;
    }
    iVar3 = _DAT_200025e8;
    if (DAT_200025ec == '\0') {
      iVar3 = _DAT_200025e4;
    }
    if (*(int *)(uVar2 * 0x20 + 0x200021b0) == iVar3) break;
    uVar2 = uVar2 + 1;
  }
  *(undefined1 *)(uVar2 * 0x20 + 0x200021bc) = DAT_200025ee;
  **(undefined1 **)(uVar2 * 0x20 + 0x200021b8) = DAT_200025ef;
  *(undefined1 *)(*(int *)(uVar2 * 0x20 + 0x200021b8) + 1) = DAT_200025f0;
  *(undefined1 *)(*(int *)(uVar2 * 0x20 + 0x200021b8) + 2) = DAT_200025f1;
  *(undefined1 *)(*(int *)(uVar2 * 0x20 + 0x200021b8) + 3) = DAT_200025f2;
  *(undefined1 *)(*(int *)(uVar2 * 0x20 + 0x200021b8) + 4) = DAT_200025f3;
  *(undefined1 *)(*(int *)(uVar2 * 0x20 + 0x200021b8) + 5) = DAT_200025f4;
  *(undefined1 *)(*(int *)(uVar2 * 0x20 + 0x200021b8) + 6) = DAT_200025f5;
  *(undefined1 *)(*(int *)(uVar2 * 0x20 + 0x200021b8) + 7) = DAT_200025f6;
  uVar1 = FUN_08019112();
  *(undefined2 *)(uVar2 * 0x20 + 0x200021c4) = uVar1;
  if (*(int *)(uVar2 * 0x20 + 0x200021c8) == 0) {
    return;
  }
  (**(code **)(uVar2 * 0x20 + 0x200021c8))();
  return;
}

