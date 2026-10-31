// rea decompile_all
// name: FUN_0800af4e
// address: 0x800af4e
// body: available
// range: 0x800af4e-0x800b02b inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0800af4e(ushort *param_1,uint *param_2)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  uint auStack_34 [2];
  uint local_2c;
  
  uVar2 = param_1[2];
  FUN_0800809c(auStack_34);
  uVar1 = (ushort)(local_2c / 1000000);
  param_1[2] = uVar2 & 0xffc0 | uVar1;
  *param_1 = *param_1 & 0xfffe;
  if (*param_2 < 0x186a1) {
    local_2c = local_2c / (*param_2 << 1);
    uVar2 = (ushort)local_2c;
    if ((local_2c & 0xffff) < 4) {
      uVar2 = 4;
    }
    param_1[0x10] = uVar1 + 1;
  }
  else {
    if (*(short *)((int)param_2 + 6) == -0x4001) {
      uVar3 = local_2c / (*param_2 * 3) & 0xffff;
    }
    else {
      uVar3 = local_2c / (*param_2 * 0x19) & 0xffff | 0x4000;
    }
    uVar2 = (ushort)uVar3;
    if ((uVar3 & 0xfff) == 0) {
      uVar2 = uVar2 | 1;
    }
    uVar2 = uVar2 | 0x8000;
    param_1[0x10] = (short)(((local_2c / 1000000) * 300) / 1000) + 1;
  }
  param_1[0xe] = uVar2;
  *param_1 = *param_1 | 1;
  *param_1 = *param_1 & 0xfbf5 | (ushort)param_2[1] | *(ushort *)((int)param_2 + 10);
  param_1[4] = (ushort)param_2[3] | (ushort)param_2[2];
  return;
}

