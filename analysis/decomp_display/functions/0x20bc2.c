// rea decompile_all
// name: FUN_00020bc2
// address: 0x20bc2
// body: available
// range: 0x20bc2-0x20c65 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00020bc2(byte *param_1)

{
  byte *local_c;
  ushort local_8;
  ushort local_6;
  byte *local_4;
  
  _DAT_20000c84 = (byte **)0x0;
  DAT_20000c80 = 2;
  local_8 = (ushort)*param_1;
  local_4 = param_1;
  for (local_6 = 0; local_6 < local_8; local_6 = local_6 + 1) {
    local_c = (byte *)(*(int *)(local_4 + 4) + (uint)local_6 * 0x20);
    if ((((*local_c & 1) == 0) && ((int)((uint)*local_c * 0x40000000) < 0)) && (local_c[0x1a] != 0))
    {
      _DAT_20000c84 = &local_c;
      DAT_20000c81 = local_c[0x18];
      DAT_20000c82 = local_c[0x19];
      DAT_20000c83 = local_c[0x1a];
      (**(code **)(local_4 + 0x30))();
      local_c[0x1a] = 0;
    }
  }
  return;
}

