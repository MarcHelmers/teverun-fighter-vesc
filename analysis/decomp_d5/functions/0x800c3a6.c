// rea decompile_all
// name: FUN_0800c3a6
// address: 0x800c3a6
// body: available
// range: 0x800c3a6-0x800c451 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_0800c3a6(int param_1)

{
  uint uVar1;
  bool bVar2;
  undefined1 local_18 [2];
  byte local_16;
  byte local_15;
  
  bVar2 = false;
  _local_18 = CONCAT12(DAT_200003bf,CONCAT11(DAT_200003be,DAT_200003bd));
  _local_18 = CONCAT13(DAT_200003c0,_local_18);
  if (param_1 == 0) {
    bVar2 = true;
  }
  else if (param_1 == 1) {
    bVar2 = _DAT_200003a0 ==
            (_local_18 & 0xff) + (uint)DAT_200003be + (uint)DAT_200003bf + (uint)DAT_200003c0;
  }
  else if (param_1 == 2) {
    uVar1 = FUN_0800bd20((int)local_18,4);
    bVar2 = _DAT_200003a0 == uVar1;
  }
  else if ((param_1 == 3) &&
          (uVar1 = FUN_0800c39e((uint)DAT_200003bd * 0x1000000 + (uint)DAT_200003bd * 0x10000 +
                                (uint)DAT_200003bd * 0x100 + (uint)DAT_200003bd,0xcf1974),
          _DAT_200003a0 == uVar1)) {
    bVar2 = true;
  }
  return bVar2;
}

