// rea decompile_all
// name: FUN_00010200
// address: 0x10200
// body: available
// range: 0x10200-0x10381 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00010200(uint *param_1,byte *param_2)

{
  byte bVar1;
  uint local_14;
  
  if (param_1 == (uint *)0x40049000) {
    _DAT_40000000 = _DAT_40000000 & 0xfff0ffff | (uint)*param_2 << 0x10;
    _DAT_40000008 = _DAT_40000008 | 0x4000000;
  }
  else if (param_1 == (uint *)0x40049800) {
    _DAT_40000000 = _DAT_40000000 & 0xff0fffff | (uint)*param_2 << 0x14;
    _DAT_4000000c = _DAT_4000000c | 0x10000;
  }
  FUN_00010384(param_1);
  *param_1 = *param_1 | 8;
  for (local_14 = 0; local_14 >> 5 < 0x4b; local_14 = local_14 + 1) {
  }
  *param_1 = *param_1 & 0xfffffff7;
  *param_1 = *param_1 | 0xf00;
  *param_1 = *param_1 & 0xfffff0ff;
  *param_1 = *param_1 & 0xfffffff9;
  *param_1 = *param_1 | (uint)param_2[1] << 1;
  param_1[2] = 0;
  param_1[3] = 0x3f3f3f3f;
  bVar1 = param_2[2];
  param_1[2] = param_1[2] |
               (bVar1 & 2) << 7 | bVar1 & 1 | (bVar1 >> 2 & 1) << 0x10 | (bVar1 >> 3 & 1) << 0x18;
  bVar1 = param_2[3];
  param_1[2] = param_1[2] |
               (bVar1 & 1) << 2 | (bVar1 >> 1 & 1) << 10 | (bVar1 >> 2 & 1) << 0x12 |
               (bVar1 >> 3 & 1) << 0x1a;
  if (param_1 == (uint *)0x40049000) {
    if (param_2[2] != 0 || param_2[3] != 0) {
      FUN_00010398('\n');
    }
  }
  else if ((param_1 == (uint *)0x40049800) && (param_2[2] != 0 || param_2[3] != 0)) {
    FUN_00010398('\x17');
  }
  return;
}

