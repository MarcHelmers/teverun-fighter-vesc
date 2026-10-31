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
  
  DAT_20000d40 = 0x41;
  DAT_20000d41 = 0x42;
  DAT_20000d42 = 0x43;
  DAT_20000d43 = 0x44;
  DAT_20000d44 = 0x45;
  DAT_20000d45 = 0x46;
  DAT_20000d46 = 0x47;
  DAT_20000d47 = 0x31;
  DAT_20000d48 = 0x32;
  DAT_20000d49 = 0x33;
  DAT_20000d4a = 0x34;
  DAT_20000d4b = 0x35;
  DAT_20000d4c = 0x36;
  DAT_20000d4d = 0x37;
  DAT_20000d4e = 0x38;
  bVar2 = DAT_200003de + 1;
  iVar3 = bVar2 / 10 + 3000;
  DAT_20000d6e = (undefined1)((uint)iVar3 >> 8);
  DAT_20000d6f = (undefined1)iVar3;
  uVar1 = 3000 - bVar2 / 10 & 0xffff;
  DAT_20000d70 = (undefined1)(uVar1 >> 8);
  DAT_20000d71 = (undefined1)uVar1;
  iVar3 = bVar2 / 10 + 0xc80;
  DAT_20000d72 = (undefined1)((uint)iVar3 >> 8);
  DAT_20000d73 = (undefined1)iVar3;
  uVar1 = 0xc80 - bVar2 / 10 & 0xffff;
  DAT_20000d74 = (undefined1)(uVar1 >> 8);
  DAT_20000d75 = (undefined1)uVar1;
  iVar3 = bVar2 / 10 + 3000;
  DAT_20000d76 = (undefined1)((uint)iVar3 >> 8);
  DAT_20000d77 = (undefined1)iVar3;
  uVar1 = 3000 - bVar2 / 10 & 0xffff;
  DAT_20000d78 = (undefined1)(uVar1 >> 8);
  DAT_20000d79 = (undefined1)uVar1;
  iVar3 = bVar2 / 10 + 0xc1c;
  DAT_20000d7a = (undefined1)((uint)iVar3 >> 8);
  DAT_20000d7b = (undefined1)iVar3;
  uVar1 = 0xc1c - bVar2 / 10 & 0xffff;
  DAT_20000d7c = (undefined1)(uVar1 >> 8);
  DAT_20000d7d = (undefined1)uVar1;
  bVar2 = DAT_200003de + 2;
  iVar3 = bVar2 / 10 + 4000;
  DAT_20000db1 = (undefined1)((uint)iVar3 >> 8);
  DAT_20000db2 = (undefined1)iVar3;
  uVar1 = 4000 - bVar2 / 10 & 0xffff;
  DAT_20000db3 = (undefined1)(uVar1 >> 8);
  DAT_20000db4 = (undefined1)uVar1;
  iVar3 = bVar2 / 10 + 0x1068;
  DAT_20000db5 = (undefined1)((uint)iVar3 >> 8);
  DAT_20000db6 = (undefined1)iVar3;
  uVar1 = 0x1068 - bVar2 / 10 & 0xffff;
  DAT_20000db7 = (undefined1)(uVar1 >> 8);
  DAT_20000db8 = (undefined1)uVar1;
  iVar3 = bVar2 / 10 + 4000;
  DAT_20000db9 = (undefined1)((uint)iVar3 >> 8);
  DAT_20000dba = (undefined1)iVar3;
  uVar1 = 4000 - bVar2 / 10 & 0xffff;
  DAT_20000dbb = (undefined1)(uVar1 >> 8);
  DAT_20000dbc = (undefined1)uVar1;
  iVar3 = bVar2 / 10 + 0x1004;
  DAT_20000dbd = (undefined1)((uint)iVar3 >> 8);
  DAT_20000dbe = (undefined1)iVar3;
  uVar1 = 0x1004 - bVar2 / 10 & 0xffff;
  DAT_20000dbf = (undefined1)(uVar1 >> 8);
  DAT_20000dc0 = (undefined1)uVar1;
  DAT_200003de = DAT_200003de + 3;
  iVar3 = DAT_200003de / 10 + 2000;
  DAT_20000dc1 = (undefined1)((uint)iVar3 >> 8);
  DAT_20000dc2 = (undefined1)iVar3;
  uVar1 = 2000 - DAT_200003de / 10 & 0xffff;
  DAT_20000dc3 = (undefined1)(uVar1 >> 8);
  DAT_20000dc4 = (undefined1)uVar1;
  iVar3 = DAT_200003de / 10 + 0x898;
  DAT_20000dc5 = (undefined1)((uint)iVar3 >> 8);
  DAT_20000dc6 = (undefined1)iVar3;
  uVar1 = 0x898 - DAT_200003de / 10 & 0xffff;
  DAT_20000dc7 = (undefined1)(uVar1 >> 8);
  DAT_20000dc8 = (undefined1)uVar1;
  iVar3 = DAT_200003de / 10 + 2000;
  DAT_20000dc9 = (undefined1)((uint)iVar3 >> 8);
  DAT_20000dca = (undefined1)iVar3;
  uVar1 = 2000 - DAT_200003de / 10 & 0xffff;
  DAT_20000dcb = (undefined1)(uVar1 >> 8);
  DAT_20000dcc = (undefined1)uVar1;
  iVar3 = DAT_200003de / 10 + 0x834;
  DAT_20000dcd = (undefined1)((uint)iVar3 >> 8);
  DAT_20000dce = (undefined1)iVar3;
  uVar1 = 0x834 - DAT_200003de / 10 & 0xffff;
  DAT_20000dcf = (undefined1)(uVar1 >> 8);
  DAT_20000dd0 = (undefined1)uVar1;
  uVar1 = DAT_200003de / 10 + 35000 & 0xffff;
  DAT_20000d7e = (undefined1)(uVar1 / 100 - 100 >> 8);
  DAT_20000d7f = (char)(uVar1 / 100) + -100;
  uVar1 = DAT_200003de / 10 + 34000 & 0xffff;
  DAT_20000d80 = (undefined1)(uVar1 / 100 - 100 >> 8);
  DAT_20000d81 = (char)(uVar1 / 100) + -100;
  DAT_20000d82 = 0x27;
  DAT_20000d83 = 0x1f;
  DAT_20000d84 = DAT_200003de / 10 + 0x32;
  DAT_20000d85 = 100;
  DAT_20000d86 = 0x41;
  DAT_20000d87 = 0x2d;
  DAT_20000d88 = 0x55;
  DAT_20000d89 = 0x42;
  DAT_20000d8a = 0x2e;
  DAT_20000d8b = 0x56;
  DAT_20000d8c = 0x14;
  DAT_20000d8f = 1;
  DAT_20000d90 = 1;
  DAT_20000d91 = 0;
  DAT_20000d92 = 1;
  DAT_20000d93 = 0;
  DAT_20000d94 = 0xaa;
  DAT_20000d95 = 0;
  DAT_20000d96 = 0xe6;
  DAT_20000d9b = DAT_20000373;
  iVar3 = DAT_200003de / 10 + 0x1068;
  DAT_20000d9c = (undefined1)((uint)iVar3 >> 8);
  DAT_20000d9d = (undefined1)iVar3;
  iVar3 = DAT_200003de / 10 + 2000;
  DAT_20000d9e = (undefined1)((uint)iVar3 >> 8);
  DAT_20000d9f = (undefined1)iVar3;
  DAT_20000da0 = (char)(DAT_200003de / 10) - (char)(((int)(DAT_200003de / 10) >> 2) << 2);
  DAT_20000da1 = 0;
  DAT_20000da2 = 0;
  DAT_20000da3 = 0;
  DAT_20000da4 = 0;
  DAT_20000da5 = 0;
  DAT_20000da6 = 0;
  DAT_20000da7 = 0;
  DAT_20000da9 = 0;
  DAT_20000da8 = 0;
  DAT_20000daa = 2;
  DAT_20000dab = 3;
  DAT_20000dac = 0;
  DAT_20000dad = 1;
  DAT_20000dae = 1;
  *(undefined1 *)((uint)DAT_20000299 * 0x10 + 0x20000cc2) = 1;
  *(undefined1 *)((uint)DAT_20000299 * 0x10 + 0x20000cc3) = 1;
  *(undefined1 *)((uint)DAT_20000299 * 0x10 + 0x20000cd0) = 0xe3;
  *(undefined1 *)((uint)DAT_20000299 * 0x10 + 0x20000cc4) = 0xe3;
  *(undefined1 *)((uint)DAT_20000299 * 0x10 + 0x20000cc5) = 0x1e;
  *(undefined1 *)((uint)DAT_20000299 * 0x10 + 0x20000cc6) = 0x50;
  *(undefined1 *)((uint)DAT_20000299 * 0x10 + 0x20000cc7) = 0x14;
  *(undefined1 *)((uint)DAT_20000299 * 0x10 + 0x20000cc8) = 0x33;
  *(undefined1 *)((uint)DAT_20000299 * 0x10 + 0x20000cca) = 100;
  *(undefined1 *)((uint)DAT_20000299 * 0x10 + 0x20000ccb) = 0x50;
  *(undefined1 *)((uint)DAT_20000299 * 0x10 + 0x20000ccc) = 0x3c;
  *(undefined1 *)((uint)DAT_20000299 * 0x10 + 0x20000cce) = 0x2d;
  *(undefined1 *)((uint)DAT_20000299 * 0x10 + 0x20000ccf) = 0x3c;
  *(undefined1 *)((uint)DAT_20000299 * 0x10 + 0x20000cd1) = DAT_200002fe;
  DAT_20000d22 = 0xf0;
  DAT_20000d23 = 0x59;
  DAT_20000d24 = 1;
  DAT_20000d25 = 0x2c;
  DAT_20000d26 = 0x3c;
  DAT_20000d27 = 0;
  DAT_20000d28 = 100;
  DAT_20000d29 = 0x19;
  return;
}

