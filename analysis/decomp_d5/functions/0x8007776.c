// rea decompile_all
// name: FUN_08007776
// address: 0x8007776
// body: available
// range: 0x8007776-0x8007959 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_08007776(uint *param_1,ushort *param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = 0;
  for (uVar2 = 0; (int)(uint)*param_2 >> (uVar2 & 0xff) != 0; uVar2 = uVar2 + 1) {
    if (((uint)*param_2 & 1 << (uVar2 & 0xff)) != 0) {
      uVar1 = uVar2 << 1;
      if ((((*(int *)(param_2 + 4) == 2) || (*(int *)(param_2 + 4) == 0x12)) ||
          (*(int *)(param_2 + 4) == 0)) || (*(int *)(param_2 + 4) == 3)) {
        if ((uVar2 & 8) == 0) {
          param_1[8] = param_1[8] & ~(0xf << ((uVar2 & 7) << 2)) |
                       *(int *)(param_2 + 6) << ((uVar2 & 7) << 2);
        }
        else {
          param_1[9] = param_1[9] & ~(0xf << ((uVar2 & 7) << 2)) |
                       *(int *)(param_2 + 6) << ((uVar2 & 7) << 2);
        }
      }
      *param_1 = *param_1 & ~(3 << (uVar1 & 0xff)) | ((byte)param_2[4] & 0xf) << (uVar1 & 0xff);
      param_1[3] = param_1[3] & ~(3 << (uVar1 & 0xff)) | ((byte)param_2[2] & 3) << (uVar1 & 0xff);
      if (((param_2[4] & 3) != 0) && (*(int *)(param_2 + 4) != 3)) {
        param_1[0xb] = param_1[0xb] & ~(3 << (uVar1 & 0xff)) |
                       ((byte)param_2[1] & 3) << (uVar1 & 0xff);
      }
      uVar1 = param_1[2] & ~(1 << (uVar2 & 0xff)) |
              (*(byte *)((int)param_2 + 3) & 1) << (uVar2 & 0xff);
      param_1[2] = uVar1;
      if ((char)param_2[2] == '\x02') {
        param_1[10] = param_1[10] | 1 << (uVar2 & 0xff);
      }
      else if ((char)param_2[2] == '\x01') {
        param_1[6] = param_1[6] | 1 << (uVar2 & 0xff);
      }
      if (((*(int *)(param_2 + 4) == 1) || (*(int *)(param_2 + 4) == 2)) ||
         ((*(int *)(param_2 + 4) == 0x11 || (*(int *)(param_2 + 4) == 0x12)))) {
        uVar1 = param_1[1] & ~(1 << (uVar2 & 0xff)) |
                (((byte)param_2[4] & 0x1f) >> 4) << (uVar2 & 0xff);
        param_1[1] = uVar1;
      }
      if ((*(uint *)(param_2 + 4) & 0x10000000) != 0) {
        _DAT_40010400 = _DAT_40010400 & ~(1 << (uVar2 & 0xff));
        if ((*(uint *)(param_2 + 4) & 0x10000) == 0x10000) {
          _DAT_40010400 = _DAT_40010400 | 1 << (uVar2 & 0xff);
        }
        _DAT_40010404 = _DAT_40010404 & ~(1 << (uVar2 & 0xff));
        if ((*(uint *)(param_2 + 4) & 0x20000) == 0x20000) {
          _DAT_40010404 = _DAT_40010404 | 1 << (uVar2 & 0xff);
        }
        _DAT_40010408 = _DAT_40010408 & ~(1 << (uVar2 & 0xff));
        if ((*(uint *)(param_2 + 4) & 0x100000) == 0x100000) {
          _DAT_40010408 = _DAT_40010408 | 1 << (uVar2 & 0xff);
        }
        uVar1 = _DAT_4001040c & ~(1 << (uVar2 & 0xff));
        _DAT_4001040c = uVar1;
        if ((*(uint *)(param_2 + 4) & 0x200000) == 0x200000) {
          uVar1 = uVar1 | 1 << (uVar2 & 0xff);
          _DAT_4001040c = uVar1;
        }
      }
    }
  }
  return uVar1;
}

