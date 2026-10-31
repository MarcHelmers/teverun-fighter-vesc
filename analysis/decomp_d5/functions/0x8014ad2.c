// rea decompile_all
// name: FUN_08014ad2
// address: 0x8014ad2
// body: available
// range: 0x8014ad2-0x8014c1b inclusive
// range: 0x8014c3c-0x8014c89 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08014ad2(void)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = 0;
  iVar2 = FUN_080131e2((uint *)0x200014c4,_DAT_200014bc);
  if (iVar2 == 1) {
    FUN_080131dc((undefined4 *)0x200014c4);
    FUN_08011668(*(uint *)(&DAT_2000147c +
                          ((uint)DAT_200014b9 -
                          (uint)DAT_200014b8 * ((uint)DAT_200014b9 / (uint)DAT_200014b8)) * 4));
    FUN_08011660(*(uint *)(&DAT_2000147c +
                          ((uint)DAT_200014b9 -
                          (uint)DAT_200014b8 * ((uint)DAT_200014b9 / (uint)DAT_200014b8)) * 4));
    FUN_0801165a((char)*(undefined4 *)
                        (&DAT_2000147c +
                        ((uint)DAT_200014b9 -
                        (uint)DAT_200014b8 * ((uint)DAT_200014b9 / (uint)DAT_200014b8)) * 4));
    DAT_200014b9 = DAT_200014b9 + 1;
    if ((uint)DAT_200014b9 == ((int)(uint)DAT_200014b9 >> 1) * 2) {
      for (; bVar1 < 7; bVar1 = bVar1 + 1) {
        FUN_08013016();
        FUN_08013016();
      }
    }
    else {
      for (bVar1 = 0; bVar1 < 7; bVar1 = bVar1 + 1) {
        FUN_08013016();
        FUN_08013016();
      }
    }
    if ((uint)DAT_200014b9 == ((int)(uint)DAT_200014b9 >> 1) * 2) {
      for (bVar1 = 0; bVar1 < 7; bVar1 = bVar1 + 1) {
        FUN_08012c74();
        FUN_08012c74();
      }
    }
    else {
      for (bVar1 = 0; bVar1 < 7; bVar1 = bVar1 + 1) {
        FUN_08012c74();
        FUN_08012c74();
      }
    }
    if ((uint)DAT_200014b9 == ((int)(uint)DAT_200014b9 >> 1) * 2) {
      for (bVar1 = 0; bVar1 < 7; bVar1 = bVar1 + 1) {
        FUN_08012e3a();
        FUN_08012e3a();
      }
    }
    else {
      for (bVar1 = 0; bVar1 < 7; bVar1 = bVar1 + 1) {
        FUN_08012e3a();
        FUN_08012e3a();
      }
    }
  }
  return;
}

