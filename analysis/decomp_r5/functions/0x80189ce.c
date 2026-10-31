// rea decompile_all
// name: FUN_080189ce
// address: 0x80189ce
// body: available
// range: 0x80189ce-0x8018b8b inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_080189ce(undefined4 param_1)

{
  short sVar1;
  bool bVar2;
  undefined1 uVar3;
  
  _DAT_2000050a = 3000;
  do {
    bVar2 = FUN_0800b298(0x40005400,0x20000);
    if (!bVar2) break;
    sVar1 = _DAT_2000050a + -1;
    bVar2 = _DAT_2000050a != 0;
    _DAT_2000050a = sVar1;
  } while (bVar2);
  FUN_0800b092((ushort *)0x40005400,1);
  _DAT_2000050a = 3000;
  do {
    bVar2 = FUN_0800b254(0x40005400,0x30001);
    if (bVar2) break;
    sVar1 = _DAT_2000050a + -1;
    bVar2 = _DAT_2000050a != 0;
    _DAT_2000050a = sVar1;
  } while (bVar2);
  FUN_0800b13e(0x40005400,0xa0,0);
  _DAT_2000050a = 3000;
  do {
    bVar2 = FUN_0800b254(0x40005400,0x70082);
    if (bVar2) break;
    sVar1 = _DAT_2000050a + -1;
    bVar2 = _DAT_2000050a != 0;
    _DAT_2000050a = sVar1;
  } while (bVar2);
  FUN_0800b04a((ushort *)0x40005400,1);
  FUN_0800b132(0x40005400,(short)((uint)param_1 >> 8));
  _DAT_2000050a = 3000;
  do {
    bVar2 = FUN_0800b254(0x40005400,0x70084);
    if (bVar2) break;
    sVar1 = _DAT_2000050a + -1;
    bVar2 = _DAT_2000050a != 0;
    _DAT_2000050a = sVar1;
  } while (bVar2);
  FUN_0800b132(0x40005400,(ushort)param_1 & 0xff);
  _DAT_2000050a = 3000;
  do {
    bVar2 = FUN_0800b254(0x40005400,0x70084);
    if (bVar2) break;
    sVar1 = _DAT_2000050a + -1;
    bVar2 = _DAT_2000050a != 0;
    _DAT_2000050a = sVar1;
  } while (bVar2);
  FUN_0800b092((ushort *)0x40005400,1);
  _DAT_2000050a = 3000;
  do {
    bVar2 = FUN_0800b254(0x40005400,0x30001);
    if (bVar2) break;
    sVar1 = _DAT_2000050a + -1;
    bVar2 = _DAT_2000050a != 0;
    _DAT_2000050a = sVar1;
  } while (bVar2);
  FUN_0800b13e(0x40005400,0xa0,1);
  _DAT_2000050a = 3000;
  do {
    bVar2 = FUN_0800b298(0x40005400,0x10000002);
    if (bVar2) break;
    sVar1 = _DAT_2000050a + -1;
    bVar2 = _DAT_2000050a != 0;
    _DAT_2000050a = sVar1;
  } while (bVar2);
  FUN_0800b0c2((ushort *)0x40005400,0);
  _DAT_2000050a = 3000;
  do {
    bVar2 = FUN_0800b298(0x40005400,0x10000040);
    if (bVar2) break;
    sVar1 = _DAT_2000050a + -1;
    bVar2 = _DAT_2000050a != 0;
    _DAT_2000050a = sVar1;
  } while (bVar2);
  uVar3 = FUN_0800b136(0x40005400);
  FUN_0800b0aa((ushort *)0x40005400,1);
  return uVar3;
}

