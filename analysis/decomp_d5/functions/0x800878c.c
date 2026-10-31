// rea decompile_all
// name: FUN_0800878c
// address: 0x800878c
// body: available
// range: 0x800878c-0x80088b3 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0800878c(uint *param_1,undefined2 *param_2)

{
  uint uVar1;
  
  uVar1 = *param_1;
  if ((((param_1 == (uint *)0x40012c00) || (param_1 == (uint *)0x40013400)) ||
      (param_1 == (uint *)0x40000000)) ||
     (((param_1 == (uint *)0x40000400 || (param_1 == (uint *)0x40000800)) ||
      ((param_1 == (uint *)0x40000c00 || (param_1 == (uint *)0x40003c00)))))) {
    uVar1 = uVar1 & 0xffffff8f | (uint)(ushort)param_2[1];
  }
  if ((param_1 != (uint *)0x40001000) && (param_1 != (uint *)0x40001400)) {
    uVar1 = uVar1 & 0xfffffcff | (uint)(ushort)param_2[3];
  }
  *param_1 = uVar1;
  *(undefined2 *)(param_1 + 0xb) = param_2[2];
  *(undefined2 *)(param_1 + 10) = *param_2;
  if ((param_1 == (uint *)0x40012c00) || (param_1 == (uint *)0x40013400)) {
    *(ushort *)(param_1 + 0xc) = (ushort)*(byte *)(param_2 + 4);
  }
  *(undefined2 *)(param_1 + 5) = 1;
  uVar1 = *param_1;
  if (((((param_1 == (uint *)0x40012c00) || (param_1 == (uint *)0x40013400)) ||
       (param_1 == (uint *)0x40000000)) ||
      ((param_1 == (uint *)0x40000400 || (param_1 == (uint *)0x40000800)))) ||
     ((param_1 == (uint *)0x40000c00 || (param_1 == (uint *)0x40003c00)))) {
    if (*(char *)((int)param_2 + 9) == '\0') {
      uVar1 = uVar1 & 0xfffff7ff;
    }
    else {
      uVar1 = uVar1 | 0x800;
    }
  }
  if (param_1 == (uint *)0x40003c00) {
    if (*(char *)(param_2 + 5) == '\0') {
      uVar1 = uVar1 & 0xffffefff;
    }
    else {
      uVar1 = uVar1 | 0x1000;
    }
    if (*(char *)((int)param_2 + 0xb) == '\0') {
      uVar1 = uVar1 & 0xffffdfff;
    }
    else {
      uVar1 = uVar1 | 0x2000;
    }
    if (*(char *)(param_2 + 6) == '\0') {
      uVar1 = uVar1 & 0xffffbfff;
    }
    else {
      uVar1 = uVar1 | 0x4000;
    }
  }
  if (((param_1 == (uint *)0x40012c00) || (param_1 == (uint *)0x40013400)) ||
     ((param_1 == (uint *)0x40000000 ||
      (((param_1 == (uint *)0x40000400 || (param_1 == (uint *)0x40000800)) ||
       (param_1 == (uint *)0x40003c00)))))) {
    if (*(char *)((int)param_2 + 0xd) == '\0') {
      uVar1 = uVar1 & 0xffff7fff;
    }
    else {
      uVar1 = uVar1 | 0x8000;
    }
  }
  *param_1 = uVar1;
  uVar1 = param_1[1];
  if ((param_1 == (uint *)0x40000000) || (param_1 == (uint *)0x40000800)) {
    if (*(char *)(param_2 + 7) == '\0') {
      uVar1 = uVar1 & 0xfffffeff;
    }
    else {
      uVar1 = uVar1 | 0x100;
    }
  }
  param_1[1] = uVar1;
  return;
}

