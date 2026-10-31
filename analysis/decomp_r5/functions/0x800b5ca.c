// rea decompile_all
// name: FUN_0800b5ca
// address: 0x800b5ca
// body: available
// range: 0x800b5ca-0x800b6cb inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0800b5ca(void)

{
  char cVar1;
  ushort uVar2;
  int iVar3;
  
  iVar3 = FUN_08008628((ushort *)0x40004400,0x525);
  if (iVar3 == 0) {
    FUN_0800867c((ushort *)0x40004400,0x525);
  }
  else {
    FUN_0800867c((ushort *)0x40004400,0x525);
    uVar2 = FUN_08008556(0x40004400);
    cVar1 = (char)uVar2;
    uVar2 = FUN_08008556(0x40004400);
    *(char *)((_DAT_20000542 & 0x3fff) + 0x20002020) = (char)uVar2;
    _DAT_20000542 = (ushort)(((uint)(ushort)(_DAT_20000542 + 1) << 0x12) >> 0x12);
    if (199 < _DAT_20000542) {
      _DAT_20000542 = 0;
    }
    if (DAT_20000006 == '\0') {
      if (cVar1 == 'q') {
        DAT_20000006 = '\x01';
        DAT_20000007 = DAT_20000007 + 1;
        DAT_200006ec = 0x71;
      }
      else {
        DAT_20000006 = '\0';
      }
    }
    else if (DAT_20000007 == 0xc) {
      DAT_200006f9 = cVar1;
      FUN_08010cd4(0x20000dfa,(undefined4 *)&DAT_200006ec);
      DAT_20000006 = '\0';
      DAT_20000007 = 0;
    }
    else if (DAT_20000007 < 0xd) {
      (&DAT_200006ec)[DAT_20000007] = cVar1;
      DAT_20000007 = DAT_20000007 + 1;
    }
    else {
      DAT_20000006 = '\0';
      DAT_20000007 = 0;
    }
  }
  iVar3 = FUN_08008628((ushort *)0x40004400,0x360);
  if (iVar3 == 0) {
    FUN_08008556(0x40004400);
    FUN_0800867c((ushort *)0x40004400,0x360);
  }
  else {
    FUN_08008556(0x40004400);
    FUN_0800867c((ushort *)0x40004400,0x360);
  }
  return;
}

