// rea decompile_all
// name: FUN_0800d252
// address: 0x800d252
// body: available
// range: 0x800d252-0x800d4af inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0800d252(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  bool bVar2;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  uint uStack_4;
  
  local_30 = param_1;
  uStack_2c = param_2;
  uStack_28 = param_3;
  uStack_24 = param_4;
  uStack_10 = param_1;
  uStack_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  FUN_0800b990((undefined1 *)&local_30,(undefined1 *)((int)&uStack_10 + 2),0x10);
  if (((char)local_30 == '\x01') && (DAT_20000301 == '\0')) {
    DAT_20000299 = local_30._1_1_;
    if (5 < local_30._1_1_) {
      DAT_20000299 = 5;
    }
  }
  else {
    bVar2 = (char)local_30 == '\x02';
    do {
      if (!bVar2) {
        if ((char)local_30 == '\x03') {
          if ((uStack_24 & 0x10000) != 0) {
            _DAT_200002cc = 1;
            DAT_200002d0 = (char)local_30;
            DAT_200002d2 = DAT_200002d2 | 1;
            DAT_20000301 = 1;
            return;
          }
          _DAT_200002cc = 1;
          DAT_200002d0 = (char)local_30;
          DAT_200002d2 = DAT_200002d2 & 0xfe;
          DAT_20000301 = 0;
          return;
        }
        if ((char)local_30 == '\x04') {
          if ((uStack_24 & 0x20000) != 0) {
            _DAT_200002cc = 1;
            DAT_200002d0 = (char)local_30;
            DAT_200002d2 = DAT_200002d2 | 2;
            DAT_20000300 = 1;
            return;
          }
          _DAT_200002cc = 1;
          DAT_200002d0 = (char)local_30;
          DAT_200002d2 = DAT_200002d2 & 0xfd;
          DAT_20000300 = 0;
          return;
        }
        if ((char)local_30 != '\x05') {
          _DAT_200002cc = 1;
          DAT_200002d0 = 0;
          return;
        }
        if ((uStack_24 & 0x100000) != 0) {
          _DAT_200002cc = 1;
          DAT_200002d0 = (char)local_30;
          DAT_200002d2 = DAT_200002d2 | 0x10;
          DAT_2000030a = 1;
          return;
        }
        _DAT_200002cc = 1;
        DAT_200002d0 = (char)local_30;
        DAT_200002d2 = DAT_200002d2 & 0xef;
        DAT_2000030a = 0;
        return;
      }
      bVar2 = DAT_20000301 == '\0';
    } while (!bVar2);
    _DAT_200002cc = 1;
    DAT_200002d0 = (char)local_30;
    uVar1 = (uint)local_30._1_1_;
    if (DAT_2000030c == '\0') {
      DAT_200002d1 = local_30._2_1_;
    }
    else {
      DAT_200002d1 = local_30._2_1_ & 0xf9 | DAT_200002d1 & 6;
    }
    DAT_20000302 = (DAT_200002d1 & 4) == 4;
    DAT_2000029a = DAT_200002d1 & 0x7f | uStack_24._3_1_ & 0x80;
    DAT_2000029b = DAT_200002d1;
    if (uVar1 < 6) {
      FUN_0800b990((undefined1 *)(uVar1 * 0x10 + 0x20000c5a),(undefined1 *)&local_30,0x10);
      DAT_2000029e = *(undefined1 *)(uVar1 * 0x10 + 0x20000c5f);
      (&DAT_2000029f)[uVar1] = *(undefined1 *)(uVar1 * 0x10 + 0x20000c61);
      (&DAT_200002ab)[uVar1] = *(undefined1 *)(uVar1 * 0x10 + 0x20000c62);
      DAT_200002b1 = *(undefined1 *)(uVar1 * 0x10 + 0x20000c63);
      (&DAT_200002b2)[uVar1] = *(undefined1 *)(uVar1 * 0x10 + 0x20000c65);
      DAT_200002be = *(undefined1 *)(uVar1 * 0x10 + 0x20000c66);
      DAT_200002bf = *(undefined1 *)(uVar1 * 0x10 + 0x20000c67);
      if ((*(byte *)(uVar1 * 0x10 + 0x20000c68) & 4) == 0) {
        DAT_200002d2 = DAT_200002d2 & 0xfb;
      }
      else {
        DAT_200002d2 = DAT_200002d2 | 4;
      }
      (&DAT_200002a5)[uVar1] = *(undefined1 *)(uVar1 * 0x10 + 0x20000c60);
      (&DAT_200002b8)[uVar1] = *(undefined1 *)(uVar1 * 0x10 + 0x20000c64);
      return;
    }
  }
  DAT_200002d0 = (char)local_30;
  _DAT_200002cc = 1;
  return;
}

