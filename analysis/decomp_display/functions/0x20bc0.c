// rea decompile_all
// name: FUN_00020bc0
// address: 0x20bc0
// body: available
// range: 0x20bc0-0x20bc1 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00020bc0(byte *param_1)

{
  byte *pbStack_14;
  ushort uStack_10;
  ushort uStack_e;
  byte *pbStack_c;
  
  _DAT_20000c84 = (byte **)0x0;
  DAT_20000c80 = 2;
  uStack_10 = (ushort)*param_1;
  pbStack_c = param_1;
  for (uStack_e = 0; uStack_e < uStack_10; uStack_e = uStack_e + 1) {
    pbStack_14 = (byte *)(*(int *)(pbStack_c + 4) + (uint)uStack_e * 0x20);
    if ((((*pbStack_14 & 1) == 0) && ((int)((uint)*pbStack_14 * 0x40000000) < 0)) &&
       (pbStack_14[0x1a] != 0)) {
      _DAT_20000c84 = &pbStack_14;
      DAT_20000c81 = pbStack_14[0x18];
      DAT_20000c82 = pbStack_14[0x19];
      DAT_20000c83 = pbStack_14[0x1a];
      (**(code **)(pbStack_c + 0x30))();
      pbStack_14[0x1a] = 0;
    }
  }
  return;
}

