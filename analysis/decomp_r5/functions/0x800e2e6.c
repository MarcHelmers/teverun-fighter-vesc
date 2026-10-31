// rea decompile_all
// name: FUN_0800e2e6
// address: 0x800e2e6
// body: available
// range: 0x800e2e6-0x800e3ff inclusive
// range: 0x800e54c-0x800e907 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0800e2e6(void)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  
  DAT_20000d58 = 0x41;
  DAT_20000d59 = 0x42;
  DAT_20000d5a = 0x43;
  DAT_20000d5b = 0x44;
  DAT_20000d5c = 0x45;
  DAT_20000d5d = 0x46;
  DAT_20000d5e = 0x47;
  DAT_20000d5f = 0x31;
  DAT_20000d60 = 0x32;
  DAT_20000d61 = 0x33;
  DAT_20000d62 = 0x34;
  DAT_20000d63 = 0x35;
  DAT_20000d64 = 0x36;
  DAT_20000d65 = 0x37;
  DAT_20000d66 = 0x38;
  bVar2 = DAT_200003de + 1;
  iVar3 = bVar2 / 10 + 3000;
  DAT_20000d86 = (undefined1)((uint)iVar3 >> 8);
  DAT_20000d87 = (undefined1)iVar3;
  uVar1 = 3000 - bVar2 / 10 & 0xffff;
  DAT_20000d88 = (undefined1)(uVar1 >> 8);
  DAT_20000d89 = (undefined1)uVar1;
  iVar3 = bVar2 / 10 + 0xc80;
  DAT_20000d8a = (undefined1)((uint)iVar3 >> 8);
  DAT_20000d8b = (undefined1)iVar3;
  uVar1 = 0xc80 - bVar2 / 10 & 0xffff;
  DAT_20000d8c = (undefined1)(uVar1 >> 8);
  DAT_20000d8d = (undefined1)uVar1;
  iVar3 = bVar2 / 10 + 3000;
  DAT_20000d8e = (undefined1)((uint)iVar3 >> 8);
  DAT_20000d8f = (undefined1)iVar3;
  uVar1 = 3000 - bVar2 / 10 & 0xffff;
  DAT_20000d90 = (undefined1)(uVar1 >> 8);
  DAT_20000d91 = (undefined1)uVar1;
  iVar3 = bVar2 / 10 + 0xc1c;
  DAT_20000d92 = (undefined1)((uint)iVar3 >> 8);
  DAT_20000d93 = (undefined1)iVar3;
  uVar1 = 0xc1c - bVar2 / 10 & 0xffff;
  DAT_20000d94 = (undefined1)(uVar1 >> 8);
  DAT_20000d95 = (undefined1)uVar1;
  bVar2 = DAT_200003de + 2;
  iVar3 = bVar2 / 10 + 4000;
  DAT_20000dc9 = (undefined1)((uint)iVar3 >> 8);
  DAT_20000dca = (undefined1)iVar3;
  uVar1 = 4000 - bVar2 / 10 & 0xffff;
  DAT_20000dcb = (undefined1)(uVar1 >> 8);
  DAT_20000dcc = (undefined1)uVar1;
  iVar3 = bVar2 / 10 + 0x1068;
  DAT_20000dcd = (undefined1)((uint)iVar3 >> 8);
  DAT_20000dce = (undefined1)iVar3;
  uVar1 = 0x1068 - bVar2 / 10 & 0xffff;
  DAT_20000dcf = (undefined1)(uVar1 >> 8);
  DAT_20000dd0 = (undefined1)uVar1;
  iVar3 = bVar2 / 10 + 4000;
  DAT_20000dd1 = (undefined1)((uint)iVar3 >> 8);
  DAT_20000dd2 = (undefined1)iVar3;
  uVar1 = 4000 - bVar2 / 10 & 0xffff;
  DAT_20000dd3 = (undefined1)(uVar1 >> 8);
  DAT_20000dd4 = (undefined1)uVar1;
  iVar3 = bVar2 / 10 + 0x1004;
  DAT_20000dd5 = (undefined1)((uint)iVar3 >> 8);
  DAT_20000dd6 = (undefined1)iVar3;
  uVar1 = 0x1004 - bVar2 / 10 & 0xffff;
  DAT_20000dd7 = (undefined1)(uVar1 >> 8);
  DAT_20000dd8 = (undefined1)uVar1;
  DAT_200003de = DAT_200003de + 3;
  iVar3 = DAT_200003de / 10 + 2000;
  DAT_20000dd9 = (undefined1)((uint)iVar3 >> 8);
  DAT_20000dda = (undefined1)iVar3;
  uVar1 = 2000 - DAT_200003de / 10 & 0xffff;
  DAT_20000ddb = (undefined1)(uVar1 >> 8);
  DAT_20000ddc = (undefined1)uVar1;
  iVar3 = DAT_200003de / 10 + 0x898;
  DAT_20000ddd = (undefined1)((uint)iVar3 >> 8);
  DAT_20000dde = (undefined1)iVar3;
  uVar1 = 0x898 - DAT_200003de / 10 & 0xffff;
  DAT_20000ddf = (undefined1)(uVar1 >> 8);
  DAT_20000de0 = (undefined1)uVar1;
  iVar3 = DAT_200003de / 10 + 2000;
  DAT_20000de1 = (undefined1)((uint)iVar3 >> 8);
  DAT_20000de2 = (undefined1)iVar3;
  uVar1 = 2000 - DAT_200003de / 10 & 0xffff;
  DAT_20000de3 = (undefined1)(uVar1 >> 8);
  DAT_20000de4 = (undefined1)uVar1;
  iVar3 = DAT_200003de / 10 + 0x834;
  DAT_20000de5 = (undefined1)((uint)iVar3 >> 8);
  DAT_20000de6 = (undefined1)iVar3;
  uVar1 = 0x834 - DAT_200003de / 10 & 0xffff;
  DAT_20000de7 = (undefined1)(uVar1 >> 8);
  DAT_20000de8 = (undefined1)uVar1;
  uVar1 = DAT_200003de / 10 + 35000 & 0xffff;
  DAT_20000d96 = (undefined1)(uVar1 / 100 - 100 >> 8);
  DAT_20000d97 = (char)(uVar1 / 100) + -100;
  uVar1 = DAT_200003de / 10 + 34000 & 0xffff;
  DAT_20000d98 = (undefined1)(uVar1 / 100 - 100 >> 8);
  DAT_20000d99 = (char)(uVar1 / 100) + -100;
  DAT_20000d9a = 0x27;
  DAT_20000d9b = 0x1f;
  DAT_20000d9c = DAT_200003de / 10 + 0x32;
  DAT_20000d9d = 100;
  DAT_20000d9e = 0x41;
  DAT_20000d9f = 0x2d;
  DAT_20000da0 = 0x55;
  DAT_20000da1 = 0x42;
  DAT_20000da2 = 0x2e;
  DAT_20000da3 = 0x56;
  DAT_20000da4 = 0x14;
  DAT_20000da7 = 1;
  DAT_20000da8 = 1;
  DAT_20000da9 = 0;
  DAT_20000daa = 1;
  DAT_20000dab = 0;
  DAT_20000dac = 0xaa;
  DAT_20000dad = 0;
  DAT_20000dae = 0xe6;
  DAT_20000db3 = DAT_20000373;
  iVar3 = DAT_200003de / 10 + 0x1068;
  DAT_20000db4 = (undefined1)((uint)iVar3 >> 8);
  DAT_20000db5 = (undefined1)iVar3;
  iVar3 = DAT_200003de / 10 + 2000;
  DAT_20000db6 = (undefined1)((uint)iVar3 >> 8);
  DAT_20000db7 = (undefined1)iVar3;
  DAT_20000db8 = (char)(DAT_200003de / 10) - (char)(((int)(DAT_200003de / 10) >> 2) << 2);
  DAT_20000db9 = 0;
  DAT_20000dba = 0;
  DAT_20000dbb = 0;
  DAT_20000dbc = 0;
  DAT_20000dbd = 0;
  DAT_20000dbe = 0;
  DAT_20000dbf = 0;
  DAT_20000dc1 = 0;
  DAT_20000dc0 = 0;
  DAT_20000dc2 = 2;
  DAT_20000dc3 = 3;
  DAT_20000dc4 = 0;
  DAT_20000dc5 = 1;
  DAT_20000dc6 = 1;
  *(undefined1 *)((uint)DAT_20000299 * 0x10 + 0x20000cda) = 1;
  *(undefined1 *)((uint)DAT_20000299 * 0x10 + 0x20000cdb) = 1;
  *(undefined1 *)((uint)DAT_20000299 * 0x10 + 0x20000ce8) = 0xe3;
  *(undefined1 *)((uint)DAT_20000299 * 0x10 + 0x20000cdc) = 0xe3;
  *(undefined1 *)((uint)DAT_20000299 * 0x10 + 0x20000cdd) = 0x1e;
  *(undefined1 *)((uint)DAT_20000299 * 0x10 + 0x20000cde) = 0x50;
  *(undefined1 *)((uint)DAT_20000299 * 0x10 + 0x20000cdf) = 0x14;
  *(undefined1 *)((uint)DAT_20000299 * 0x10 + 0x20000ce0) = 0x33;
  *(undefined1 *)((uint)DAT_20000299 * 0x10 + 0x20000ce2) = 100;
  *(undefined1 *)((uint)DAT_20000299 * 0x10 + 0x20000ce3) = 0x50;
  *(undefined1 *)((uint)DAT_20000299 * 0x10 + 0x20000ce4) = 0x3c;
  *(undefined1 *)((uint)DAT_20000299 * 0x10 + 0x20000ce6) = 0x2d;
  *(undefined1 *)((uint)DAT_20000299 * 0x10 + 0x20000ce7) = 0x3c;
  *(undefined1 *)((uint)DAT_20000299 * 0x10 + 0x20000ce9) = DAT_200002fe;
  DAT_20000d3a = 0xf0;
  DAT_20000d3b = 0x59;
  DAT_20000d3c = 1;
  DAT_20000d3d = 0x2c;
  DAT_20000d3e = 0x3c;
  DAT_20000d3f = 0;
  DAT_20000d40 = 100;
  DAT_20000d41 = 0x19;
  return;
}

