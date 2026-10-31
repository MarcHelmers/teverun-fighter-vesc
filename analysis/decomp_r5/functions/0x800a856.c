// rea decompile_all
// name: FUN_0800a856
// address: 0x800a856
// body: available
// range: 0x800a856-0x800a97b inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0800a856(int param_1,ushort *param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if ((*(uint *)(param_1 + 8) & 0x4000000) != 0x4000000) {
    if ((*(uint *)(param_1 + 8) & 0x8000000) == 0x8000000) {
      iVar1 = 1;
    }
    else if ((*(uint *)(param_1 + 8) & 0x10000000) == 0x10000000) {
      iVar1 = 2;
    }
    else {
      iVar1 = 4;
    }
  }
  if (iVar1 != 4) {
    *(uint *)(param_1 + 0x180 + iVar1 * 0x10) = *(uint *)(param_1 + 0x180 + iVar1 * 0x10) & 1;
    if ((char)param_2[4] == '\0') {
      *(uint *)(param_1 + 0x180 + iVar1 * 0x10) =
           (uint)*(byte *)((int)param_2 + 9) | (uint)*param_2 << 0x15 |
           *(uint *)(param_1 + 0x180 + iVar1 * 0x10);
    }
    else {
      *(uint *)(param_1 + 0x180 + iVar1 * 0x10) =
           (uint)(byte)param_2[4] | *(int *)(param_2 + 2) << 3 | (uint)*(byte *)((int)param_2 + 9) |
           *(uint *)(param_1 + 0x180 + iVar1 * 0x10);
    }
    *(byte *)(param_2 + 5) = (byte)param_2[5] & 0xf;
    *(uint *)(param_1 + iVar1 * 0x10 + 0x184) =
         *(uint *)(param_1 + iVar1 * 0x10 + 0x184) & 0xfffffff0;
    *(uint *)(param_1 + iVar1 * 0x10 + 0x184) =
         *(uint *)(param_1 + iVar1 * 0x10 + 0x184) | (uint)(byte)param_2[5];
    *(uint *)(param_1 + iVar1 * 0x10 + 0x188) =
         (uint)(byte)param_2[7] << 0x18 | (uint)*(byte *)((int)param_2 + 0xd) << 0x10 |
         (uint)(byte)param_2[6] << 8 | (uint)*(byte *)((int)param_2 + 0xb);
    *(uint *)(param_1 + iVar1 * 0x10 + 0x18c) =
         (uint)(byte)param_2[9] << 0x18 | (uint)*(byte *)((int)param_2 + 0x11) << 0x10 |
         (uint)(byte)param_2[8] << 8 | (uint)*(byte *)((int)param_2 + 0xf);
    *(uint *)(param_1 + 0x180 + iVar1 * 0x10) = *(uint *)(param_1 + 0x180 + iVar1 * 0x10) | 1;
  }
  return;
}

