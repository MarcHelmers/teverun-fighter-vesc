// rea decompile_all
// name: FUN_0800a594
// address: 0x800a594
// body: available
// range: 0x800a594-0x800a6a7 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_0800a594(uint *param_1,ushort *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  *param_1 = *param_1 & 0xfffffffd;
  *param_1 = *param_1 | 1;
  for (iVar2 = 0; ((param_1[1] & 1) == 0 && (iVar2 != 0xffff)); iVar2 = iVar2 + 1) {
  }
  if ((param_1[1] & 1) == 0) {
    uVar1 = 0;
  }
  else {
    if ((char)param_2[3] == '\x01') {
      *param_1 = *param_1 | 0x80;
    }
    else {
      *param_1 = *param_1 & 0xffffff7f;
    }
    if (*(char *)((int)param_2 + 7) == '\x01') {
      *param_1 = *param_1 | 0x40;
    }
    else {
      *param_1 = *param_1 & 0xffffffbf;
    }
    if ((char)param_2[4] == '\x01') {
      *param_1 = *param_1 | 0x20;
    }
    else {
      *param_1 = *param_1 & 0xffffffdf;
    }
    if (*(char *)((int)param_2 + 9) == '\x01') {
      *param_1 = *param_1 | 0x10;
    }
    else {
      *param_1 = *param_1 & 0xffffffef;
    }
    if ((char)param_2[5] == '\x01') {
      *param_1 = *param_1 | 8;
    }
    else {
      *param_1 = *param_1 & 0xfffffff7;
    }
    if (*(char *)((int)param_2 + 0xb) == '\x01') {
      *param_1 = *param_1 | 4;
    }
    else {
      *param_1 = *param_1 & 0xfffffffb;
    }
    param_1[7] = (uint)(byte)param_2[1] << 0x1e | (uint)*(byte *)((int)param_2 + 3) << 0x18 |
                 (uint)(byte)param_2[2] << 0x10 | (uint)*(byte *)((int)param_2 + 5) << 0x14 |
                 *param_2 - 1;
    *param_1 = *param_1 & 0xfffffffe;
    for (iVar2 = 0; ((param_1[1] & 1) != 0 && (iVar2 != 0xffff)); iVar2 = iVar2 + 1) {
    }
    if ((param_1[1] & 1) == 0) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}

