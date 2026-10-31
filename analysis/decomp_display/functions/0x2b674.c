// rea decompile_all
// name: FUN_0002b674
// address: 0x2b674
// body: available
// range: 0x2b674-0x2b6e3 inclusive
// range: 0x2b6ec-0x2bc73 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined1 FUN_0002b674(void)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  char cVar8;
  char cVar9;
  bool bVar10;
  byte local_b;
  
  switch(DAT_200005b7) {
  case 0:
    DAT_200016fc = 0;
    FUN_0002b0e0(0x20000141,0x200009fc);
    cVar1 = FUN_0002aa30();
    if ((cVar1 == '\0') && (DAT_20000a1c != '\0')) {
      DAT_200005ba = DAT_200005ba + 1;
      if (3 < DAT_200005ba) {
        DAT_200005ba = 0;
        DAT_20000a1c = '\0';
      }
    }
    else {
      DAT_200005ba = 0;
      DAT_20000a1c = cVar1;
    }
    if (DAT_20000c7f != '\0') {
      for (local_b = 0;
          (local_b < 0x10 && (*(char *)(local_b + 0x3e3fa) == *(char *)(local_b + 0x20000c8a)));
          local_b = local_b + 1) {
        if (local_b == 0xf) {
          DAT_200005b6 = '\x01';
        }
        DAT_200005b7 = 1;
      }
      cVar1 = FUN_00013800();
      if (cVar1 != '\0') {
        DAT_200005b7 = 2;
        DAT_20000672 = 0;
        DAT_2000001c = 1;
      }
    }
    break;
  case 1:
    bVar10 = FUN_0002bc74();
    if (bVar10) {
      DAT_200005b5 = DAT_200005b5 + 1;
      if (4 < DAT_200005b5) {
        DAT_200005b5 = 0;
        bVar10 = DAT_200005b6 == '\0';
        if (bVar10) {
          DAT_200005b7 = 0;
        }
        else {
          DAT_200005b7 = 2;
          DAT_200005b6 = '\0';
        }
        DAT_20000672 = !bVar10;
        DAT_2000001c = 1;
      }
    }
    else {
      DAT_200005b5 = 0;
      DAT_200005b7 = 1;
      DAT_20000672 = 0;
      DAT_2000001c = 1;
    }
    break;
  case 2:
    bVar10 = FUN_0002b168();
    if (bVar10) {
      FUN_0002bcd4();
      FUN_0002db08();
      FUN_0002b118(0x20000141,0x200009fc);
      cVar1 = FUN_0002b238(0x3e3fa,0x20000c8a);
      cVar2 = FUN_0002b288(0x20000024,0x20000c8a);
      cVar3 = FUN_0002b2d8(0x3e704,0x20000c8a);
      cVar4 = FUN_0002b2d8(0x3e724,0x20000c8a);
      cVar5 = FUN_0002b2d8(0x3e714,0x20000c8a);
      cVar6 = FUN_0002b328(0x3e6f4,0x20000c8a);
      cVar7 = FUN_0002b378(0x3e842,0x20000c8a);
      cVar8 = FUN_0002b3c8(0x3e734,0x20000c8a);
      cVar9 = FUN_0002b418(0x3e822,0x20000c8a);
      if (cVar1 == '\0') {
        DAT_200005b9 = '\x01';
        DAT_200016fc = 1;
      }
      else {
        if (cVar2 == '\0') {
          DAT_200005b7 = 3;
          DAT_20000672 = 1;
          DAT_200016fc = 9;
          return DAT_200005b8;
        }
        if (cVar3 == '\0') {
          DAT_200005b7 = 3;
          DAT_20000672 = 1;
          DAT_200016fc = 2;
          return DAT_200005b8;
        }
        if (cVar4 == '\0') {
          DAT_200005b7 = 3;
          DAT_20000672 = 1;
          DAT_200016fc = 10;
          return DAT_200005b8;
        }
        if (cVar5 == '\0') {
          DAT_200005b7 = 3;
          DAT_20000672 = 1;
          DAT_200016fc = 0xb;
          return DAT_200005b8;
        }
        if (cVar6 == '\0') {
          DAT_200005b7 = 3;
          DAT_20000672 = 1;
          DAT_200016fc = 7;
          return DAT_200005b8;
        }
        if (cVar7 == '\0') {
          DAT_200005b7 = 3;
          DAT_20000672 = 1;
          DAT_200016fc = 5;
          return DAT_200005b8;
        }
        if (cVar8 == '\0') {
          DAT_200005b7 = 3;
          DAT_20000672 = 1;
          DAT_200016fc = 3;
          return DAT_200005b8;
        }
        if (cVar9 == '\0') {
          DAT_200005b7 = 3;
          DAT_20000672 = 1;
          DAT_200016fc = 8;
          return DAT_200005b8;
        }
        bVar10 = FUN_0002b4f8();
        if (bVar10) {
          FUN_0002b0e0(0x20000141,0x200009fc);
          DAT_200005b8 = 1;
          DAT_200005b7 = 3;
          DAT_20000672 = 1;
          DAT_2000001c = 0;
        }
      }
    }
    if ((DAT_200005b9 != '\0') && (DAT_200005b4 = DAT_200005b4 + 1, 7 < DAT_200005b4)) {
      DAT_200005b9 = '\0';
      DAT_200005b7 = 3;
      DAT_20000672 = 0;
      DAT_200005b4 = 0;
    }
    break;
  case 3:
    bVar10 = FUN_0002bc74();
    if (bVar10) {
      FUN_0002bce4();
      DAT_200005b7 = 0;
      DAT_20000672 = 0;
      DAT_2000001c = 1;
      DAT_200016fc = 0;
    }
  }
  return DAT_200005b8;
}

