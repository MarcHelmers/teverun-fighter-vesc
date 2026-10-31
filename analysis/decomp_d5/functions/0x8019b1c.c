// rea decompile_all
// name: FUN_08019b1c
// address: 0x8019b1c
// body: available
// range: 0x8019b1c-0x8019c17 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08019b1c(void)

{
  int iVar1;
  undefined4 in_r3;
  undefined4 extraout_r3;
  uint uVar2;
  
  uVar2 = 0;
  do {
    if (0xb < uVar2) {
code_r0x08019b88:
      if (DAT_20000540 == '\0') {
        iVar1 = FUN_08016ce6(0x20000530,(ushort *)&DAT_20000538,(int *)&DAT_2000053c,in_r3);
        if (iVar1 == 2) {
          DAT_20000540 = '\x01';
          iVar1 = FUN_0801b886(_DAT_2000053c,0,0x20000530,(uint)DAT_20000538);
          if (iVar1 == 0) {
            DAT_20000540 = '\0';
          }
        }
        else {
          DAT_20000540 = '\0';
        }
      }
      else {
        iVar1 = FUN_0801b886(_DAT_2000053c,0,0x20000530,(uint)DAT_20000538);
        if (iVar1 == 0) {
          DAT_20000540 = '\0';
        }
      }
      if (DAT_2000008a == '\x02') {
        iVar1 = FUN_0801b886(_DAT_20000544,0,0x20000548,8);
        if (iVar1 == 0) {
          DAT_2000008a = '\0';
        }
        DAT_20000541 = DAT_20000541 + 1;
        if (2 < DAT_20000541) {
          DAT_2000008a = '\0';
          DAT_20000541 = 0;
        }
      }
      return;
    }
    if (((*(char *)(uVar2 * 0x1c + 0x20002466) == '\x01') &&
        (*(byte *)(uVar2 * 0x1c + 0x20002464) < 9)) &&
       (iVar1 = FUN_0801b886(*(undefined4 *)(uVar2 * 0x1c + 0x20002458),
                             (uint)*(byte *)(uVar2 * 0x1c + 0x2000245c),
                             *(int *)(uVar2 * 0x1c + 0x20002460),
                             (uint)*(byte *)(uVar2 * 0x1c + 0x20002464)), in_r3 = extraout_r3,
       iVar1 == 0)) {
      *(undefined1 *)(uVar2 * 0x1c + 0x20002466) = 0;
      goto code_r0x08019b88;
    }
    uVar2 = uVar2 + 1 & 0xff;
  } while( true );
}

