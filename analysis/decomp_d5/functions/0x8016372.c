// rea decompile_all
// name: FUN_08016372
// address: 0x8016372
// body: available
// range: 0x8016372-0x801655f inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08016372(void)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  local_14 = 0;
  local_18 = 0;
  local_1c = 0;
  iVar2 = FUN_080131e2((uint *)0x20001474,_DAT_2000146c);
  if (iVar2 == 1) {
    FUN_080131dc((undefined4 *)0x20001474);
    if (DAT_20001479 == 0) {
      DAT_20001479 = 1;
      uVar3 = FUN_08011668(*(uint *)(&DAT_2000142c +
                                    ((uint)DAT_20001469 -
                                    (uint)DAT_20001468 * ((uint)DAT_20001469 / (uint)DAT_20001468))
                                    * 4));
      DAT_20000458 = (byte)uVar3;
      uVar3 = FUN_08011660(*(uint *)(&DAT_2000142c +
                                    ((uint)DAT_20001469 -
                                    (uint)DAT_20001468 * ((uint)DAT_20001469 / (uint)DAT_20001468))
                                    * 4));
      DAT_20000459 = (byte)uVar3;
      DAT_2000045a = FUN_0801165a((char)*(undefined4 *)
                                         (&DAT_2000142c +
                                         ((uint)DAT_20001469 -
                                         (uint)DAT_20001468 *
                                         ((uint)DAT_20001469 / (uint)DAT_20001468)) * 4));
      DAT_20001469 = DAT_20001469 + 1;
      FUN_080112ec((uint)DAT_20000458,(uint)DAT_20000459,(uint)DAT_2000045a,
                   (ulonglong *)&DAT_20000460,(undefined8 *)&DAT_20000468,
                   (undefined8 *)&DAT_20000470);
      _DAT_20000478 = 0;
    }
    FUN_08011128((uint)_DAT_20000468,(uint)((ulonglong)_DAT_20000468 >> 0x20),(uint)_DAT_20000478,
                 (uint)(_DAT_20000478 >> 0x20),(undefined1 *)&local_14,(undefined1 *)&local_18,
                 (undefined1 *)&local_1c);
    for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
      FUN_08013016();
    }
    for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
      FUN_08012e3a();
    }
    for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
      FUN_08012c74();
    }
    uVar5 = DAT_20001479 != 0;
    uVar4 = DAT_20001479 == 1;
    uVar3 = (uint)(_DAT_20000478 >> 0x20);
    if ((bool)uVar4) {
      _DAT_20000478 = FUN_0801ceac((uint)_DAT_20000478,uVar3,0xeb851eb8,0x3f9eb851);
      FUN_0801d238((int)_DAT_20000478,(int)(_DAT_20000478 >> 0x20));
      if (!(bool)uVar5 || (bool)uVar4) {
        _DAT_20000478 = _DAT_20000470;
        DAT_20001479 = 2;
      }
    }
    else {
      uVar5 = 1 < DAT_20001479;
      uVar4 = DAT_20001479 == 2;
      if ((bool)uVar4) {
        _DAT_20000478 = FUN_0801cfee((uint)_DAT_20000478,uVar3,0xeb851eb8,0x3f9eb851);
        FUN_0801d208((int)_DAT_20000478,(int)(_DAT_20000478 >> 0x20));
        if (!(bool)uVar5 || (bool)uVar4) {
          _DAT_20000478 = 0;
          DAT_20001479 = 0;
        }
      }
    }
  }
  return;
}

