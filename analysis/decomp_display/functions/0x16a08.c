// rea decompile_all
// name: FUN_00016a08
// address: 0x16a08
// body: available
// range: 0x16a08-0x16e3f inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00016a08(void)

{
  byte abStack_1e [12];
  short local_12;
  short local_10;
  short local_e;
  short local_c;
  byte local_9;
  
  _DAT_20000198 = _DAT_20000198 + 1;
  if (DAT_2000053f != DAT_2000053e) {
    DAT_2000053f = DAT_2000053e;
    FUN_0001e260(0);
    local_c = 3;
    local_e = 0;
    local_10 = 0x165;
    local_12 = 0x3e;
    FUN_0001e294(3,0,0x165,0x3e,0x18ce);
    FUN_00020e9c(local_c,local_e,local_10,local_12,(undefined2 *)0x56b94);
    FUN_0001e1ec((undefined4 *)0x3e6b8);
    FUN_0002040c(0xffe0);
    FUN_00020428(0x18ce);
    FUN_0001f1e8(0x60,0xf,(byte *)0x56d6c);
    for (local_9 = 0; local_9 < 0xd; local_9 = local_9 + 1) {
      FUN_0001e294(3,(ushort)local_9 * 0x2b + 0x46,0x165,(ushort)local_9 * 0x2b + 0x69,0x8410);
    }
    DAT_2000019c = '\x01';
    FUN_0001cfdc();
  }
  if ((DAT_20000140 == '\0') && (DAT_2000019c == '\0')) {
    FUN_0002040c(0xffff);
    FUN_00020428(0x8410);
    FUN_0001e224((undefined4 *)0x3e6a4,0x20000055);
    for (local_9 = 0; local_9 < 10; local_9 = local_9 + 1) {
      if (DAT_20000298 == local_9) {
        FUN_0002040c(0x1f);
        FUN_00020428(0x8410);
        FUN_0001f390(3,(ushort)local_9 * 0x2b + 0x4d,(byte *)0x56d3c);
        FUN_0001f390(0x14,(ushort)local_9 * 0x2b + 0x4d,
                     *(byte **)(&DAT_2000029c + (uint)local_9 * 0x14));
        if ((DAT_20000299 == '\x01') && ((_DAT_20000198 >> 2 & 1) == 0)) {
          FUN_00016e40(abStack_1e,(&DAT_200002a8)[(uint)local_9 * 0x14]);
          FUN_0001f554(0x152,(ushort)local_9 * 0x2b + 0x4d,abStack_1e);
        }
        else {
          FUN_00016e98(local_9,(char *)abStack_1e);
          FUN_0001f554(0x152,(ushort)local_9 * 0x2b + 0x4d,abStack_1e);
        }
      }
    }
  }
  else {
    DAT_20000140 = '\0';
    DAT_2000019c = '\0';
    FUN_0002040c(0xffff);
    FUN_00020428(0x8410);
    FUN_0001e224((undefined4 *)0x3e6a4,0x20000055);
    for (local_9 = 0; local_9 < 10; local_9 = local_9 + 1) {
      if (DAT_20000298 == local_9) {
        FUN_0002040c(0x1f);
        FUN_00020428(0x8410);
        FUN_0001f390(3,(ushort)local_9 * 0x2b + 0x4d,(byte *)0x56d3c);
        FUN_0001f390(0x14,(ushort)local_9 * 0x2b + 0x4d,
                     *(byte **)(&DAT_2000029c + (uint)local_9 * 0x14));
        if ((DAT_20000299 == '\x01') && ((_DAT_20000198 >> 2 & 1) == 0)) {
          FUN_00016e40(abStack_1e,(&DAT_200002a8)[(uint)local_9 * 0x14]);
          FUN_0001f554(0x152,(ushort)local_9 * 0x2b + 0x4d,abStack_1e);
        }
        else {
          FUN_00016e98(local_9,(char *)abStack_1e);
          FUN_0001f554(0x152,(ushort)local_9 * 0x2b + 0x4d,abStack_1e);
        }
      }
      else {
        FUN_0002040c(0xffff);
        FUN_00020428(0x8410);
        FUN_0001f390(3,(ushort)local_9 * 0x2b + 0x4d,(byte *)0x56d3a);
        FUN_0001f390(0x14,(ushort)local_9 * 0x2b + 0x4d,
                     *(byte **)(&DAT_2000029c + (uint)local_9 * 0x14));
        FUN_00016e98(local_9,(char *)abStack_1e);
        FUN_0001f554(0x152,(ushort)local_9 * 0x2b + 0x4d,abStack_1e);
      }
    }
  }
  if (DAT_20000101 != '\0') {
    DAT_2000053e = '\n';
  }
  return;
}

