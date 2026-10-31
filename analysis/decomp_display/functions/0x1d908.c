// rea decompile_all
// name: FUN_0001d908
// address: 0x1d908
// body: available
// range: 0x1d908-0x1d9d9 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


ushort FUN_0001d908(ushort param_1,byte param_2,ushort *param_3)

{
  ushort uVar1;
  ushort local_12;
  ushort local_e;
  ushort local_2;
  
  local_e = 0;
  if (param_3[param_2 - 1] < param_1) {
    local_2 = param_2 - 1;
  }
  else {
    local_12 = param_2 - 1;
    uVar1 = local_e;
    if (param_1 < *param_3) {
      local_2 = 0;
    }
    else {
      while (local_e = uVar1, (ushort)(local_e + 1) < local_12) {
        uVar1 = (ushort)(byte)(((uint)local_12 + (uint)local_e) * 0x800000 >> 0x18);
        if (param_1 < param_3[uVar1]) {
          local_12 = uVar1;
          uVar1 = local_e;
        }
      }
      local_2 = local_12;
    }
  }
  return local_2;
}

