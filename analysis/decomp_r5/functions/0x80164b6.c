// rea decompile_all
// name: FUN_080164b6
// address: 0x80164b6
// body: available
// range: 0x80164b6-0x80166a3 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_080164b6(void)

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
  iVar2 = FUN_08013326((uint *)0x2000148c,_DAT_20001484);
  if (iVar2 == 1) {
    FUN_08013320((undefined4 *)0x2000148c);
    if (DAT_20001491 == 0) {
      DAT_20001491 = 1;
      uVar3 = FUN_080117ac(*(uint *)(&DAT_20001444 +
                                    ((uint)DAT_20001481 -
                                    (uint)DAT_20001480 * ((uint)DAT_20001481 / (uint)DAT_20001480))
                                    * 4));
      DAT_20000470 = (byte)uVar3;
      uVar3 = FUN_080117a4(*(uint *)(&DAT_20001444 +
                                    ((uint)DAT_20001481 -
                                    (uint)DAT_20001480 * ((uint)DAT_20001481 / (uint)DAT_20001480))
                                    * 4));
      DAT_20000471 = (byte)uVar3;
      DAT_20000472 = FUN_0801179e((char)*(undefined4 *)
                                         (&DAT_20001444 +
                                         ((uint)DAT_20001481 -
                                         (uint)DAT_20001480 *
                                         ((uint)DAT_20001481 / (uint)DAT_20001480)) * 4));
      DAT_20001481 = DAT_20001481 + 1;
      FUN_08011430((uint)DAT_20000470,(uint)DAT_20000471,(uint)DAT_20000472,
                   (ulonglong *)&DAT_20000478,(undefined8 *)&DAT_20000480,
                   (undefined8 *)&DAT_20000488);
      _DAT_20000490 = 0;
    }
    FUN_0801126c((uint)_DAT_20000480,(uint)((ulonglong)_DAT_20000480 >> 0x20),(uint)_DAT_20000490,
                 (uint)(_DAT_20000490 >> 0x20),(undefined1 *)&local_14,(undefined1 *)&local_18,
                 (undefined1 *)&local_1c);
    for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
      FUN_0801315a();
    }
    for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
      FUN_08012f7e();
    }
    for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
      FUN_08012db8();
    }
    uVar5 = DAT_20001491 != 0;
    uVar4 = DAT_20001491 == 1;
    uVar3 = (uint)(_DAT_20000490 >> 0x20);
    if ((bool)uVar4) {
      _DAT_20000490 = FUN_0801d090((uint)_DAT_20000490,uVar3,0xeb851eb8,0x3f9eb851);
      FUN_0801d41c((int)_DAT_20000490,(int)(_DAT_20000490 >> 0x20));
      if (!(bool)uVar5 || (bool)uVar4) {
        _DAT_20000490 = _DAT_20000488;
        DAT_20001491 = 2;
      }
    }
    else {
      uVar5 = 1 < DAT_20001491;
      uVar4 = DAT_20001491 == 2;
      if ((bool)uVar4) {
        _DAT_20000490 = FUN_0801d1d2((uint)_DAT_20000490,uVar3,0xeb851eb8,0x3f9eb851);
        FUN_0801d3ec((int)_DAT_20000490,(int)(_DAT_20000490 >> 0x20));
        if (!(bool)uVar5 || (bool)uVar4) {
          _DAT_20000490 = 0;
          DAT_20001491 = 0;
        }
      }
    }
  }
  return;
}

