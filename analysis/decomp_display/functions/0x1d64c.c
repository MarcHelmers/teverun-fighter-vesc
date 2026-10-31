// rea decompile_all
// name: FUN_0001d64c
// address: 0x1d64c
// body: available
// range: 0x1d64c-0x1d907 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001d64c(void)

{
  ushort uVar1;
  uint uVar2;
  undefined1 local_d;
  undefined2 local_c;
  undefined2 local_a;
  
  if ((_DAT_200000e8 < 0x7531) || (DAT_20000578 == '\0')) {
    _DAT_200009da = 0;
  }
  else {
    _DAT_200009da = _DAT_200009da + 1;
  }
  _DAT_20000bc6 = (undefined2)(_DAT_200000e8 / 100);
  if ((DAT_200009dc == '\0') && (5 < _DAT_200009da)) {
    DAT_200009dc = '\x01';
    for (local_d = 0; local_d < 10; local_d = local_d + 1) {
      *(short *)((uint)local_d * 2 + 0x200009e0) = (short)(_DAT_200000e8 / 100);
      DAT_200009f4 = (byte)(DAT_200009f4 + 1) % 10;
    }
    uVar1 = FUN_0001d908((ushort)(_DAT_200000e8 / DAT_200005a6),0x65,(ushort *)0x3e758);
    DAT_20000bc5 = (undefined1)uVar1;
  }
  else if (DAT_200009dc == '\x01') {
    uVar2 = (uint)DAT_200009f4;
    DAT_200009f4 = DAT_200009f4 + 1;
    *(short *)(uVar2 * 2 + 0x200009e0) = (short)(_DAT_200000e8 / 100);
    DAT_200009f4 = DAT_200009f4 % 10;
    local_a = 0;
    local_c = 1000;
    for (local_d = 0; local_d < 10; local_d = local_d + 1) {
      if (local_a < *(ushort *)((uint)local_d * 2 + 0x200009e0)) {
        local_a = *(ushort *)((uint)local_d * 2 + 0x200009e0);
      }
      if (*(ushort *)((uint)local_d * 2 + 0x200009e0) < local_c) {
        local_c = *(ushort *)((uint)local_d * 2 + 0x200009e0);
      }
    }
    if ((int)((uint)local_a - (uint)local_c) < 0xb) {
      _DAT_200009de = _DAT_200009de + 1;
      if (600 < _DAT_200009de) {
        _DAT_200009de = 0;
        uVar1 = FUN_0001d908((ushort)(_DAT_200000e8 / DAT_200005a6),0x65,(ushort *)0x3e758);
        DAT_20000bc5 = (undefined1)uVar1;
      }
    }
    else {
      _DAT_200009de = 0;
    }
  }
  else {
    DAT_20000bc5 = 0;
  }
  return;
}

