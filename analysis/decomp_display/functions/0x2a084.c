// rea decompile_all
// name: FUN_0002a084
// address: 0x2a084
// body: available
// range: 0x2a084-0x2a1f9 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002a084(void)

{
  bool bVar1;
  uint uVar2;
  int local_14;
  uint local_10;
  int local_c;
  
  local_c = 0xfffffff;
  bVar1 = false;
  FUN_000106d4(0x40049000,1);
  do {
    if (-1 < _DAT_40049004 * 0x8000000) goto LAB_0002a0ce;
    local_c = local_c + -1;
  } while (local_c != 0);
  bVar1 = true;
LAB_0002a0ce:
  if (!bVar1) {
    local_c = 0xf;
    do {
      if (_DAT_40049010 * 0x8000000 < 0) goto LAB_0002a146;
      local_10 = FUN_000106fc(0x40049000,1,&local_14);
      uVar2 = local_10;
      if ((local_14 != 4) && (uVar2 = _DAT_20000050, local_14 == 2)) {
        _DAT_2000004c = local_10;
      }
      _DAT_20000050 = uVar2;
      local_c = local_c + -1;
    } while (local_c != 0);
    bVar1 = true;
  }
LAB_0002a146:
  if (!bVar1) {
    if (_DAT_2000004c != 0xaa55aa55) {
      _DAT_200000e4 = (undefined2)((_DAT_2000004c * 0xce4) / 0xfff);
      DAT_200000e0 = 1;
    }
    if (_DAT_20000050 != 0xaa55aa55) {
      _DAT_200000e2 = (undefined2)((_DAT_20000050 * 0xce4) / 0xfff);
      FUN_0002a1fc();
    }
  }
  return;
}

