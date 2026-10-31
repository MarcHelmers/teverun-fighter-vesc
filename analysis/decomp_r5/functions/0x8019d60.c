// rea decompile_all
// name: FUN_08019d60
// address: 0x8019d60
// body: available
// range: 0x8019d60-0x8019e41 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_08019d60(void)

{
  short sVar1;
  uint uVar2;
  
  sVar1 = FUN_08019112();
  for (uVar2 = 0; uVar2 < 0xc; uVar2 = uVar2 + 1 & 0xff) {
    if ((((*(char *)(uVar2 * 0x1c + 0x2000247d) == '\x01') &&
         (*(char *)(uVar2 * 0x1c + 0x2000247f) == '\x01')) &&
        (*(char *)(uVar2 * 0x1c + 0x2000247e) == '\0')) &&
       (*(ushort *)(uVar2 * 0x1c + 0x20002480) <
        (ushort)(sVar1 - *(short *)(uVar2 * 0x1c + 0x20002482)))) {
      if (*(int *)(uVar2 * 0x1c + 0x20002484) != 0) {
        (**(code **)(uVar2 * 0x1c + 0x20002484))();
      }
      *(undefined1 *)(uVar2 * 0x1c + 0x2000247e) = 1;
      *(short *)(uVar2 * 0x1c + 0x20002482) = sVar1;
    }
  }
  for (uVar2 = 0; uVar2 < 0x16; uVar2 = uVar2 + 1 & 0xff) {
    if (((*(char *)(uVar2 * 0x20 + 0x200021bd) == '\x01') &&
        (*(char *)(uVar2 * 0x20 + 0x200021bf) == '\x01')) &&
       (((uint)(*(int *)(uVar2 * 0x20 + 0x200021c0) << 2) <
         (uint)(ushort)(sVar1 - *(short *)(uVar2 * 0x20 + 0x200021c4)) &&
        (*(int *)(uVar2 * 0x20 + 0x200021cc) != 0)))) {
      (**(code **)(uVar2 * 0x20 + 0x200021cc))();
    }
  }
  return;
}

