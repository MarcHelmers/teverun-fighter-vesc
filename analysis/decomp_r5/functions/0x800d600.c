// rea decompile_all
// name: FUN_0800d600
// address: 0x800d600
// body: available
// range: 0x800d600-0x800d61f inclusive
// range: 0x800d6cc-0x800d823 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0800d600(void)

{
  if (DAT_200003a5 != -1) {
    if (DAT_200003a5 == '\n') {
      if ((DAT_200003a6 == 1) && (DAT_20000324 == '\0')) {
        DAT_20000323 = DAT_20000317;
        DAT_20000317 = '\0';
        DAT_2000031c = DAT_20000319;
        DAT_2000031d = DAT_2000031a;
        DAT_2000031e = DAT_2000031b;
        DAT_20000319 = 0;
        DAT_2000031a = 0;
        DAT_2000031b = 0;
        FUN_08011874(0,0,0);
        DAT_20000324 = '\x01';
      }
      else if (DAT_20000324 == '\x01') {
        DAT_20000317 = DAT_20000323;
        DAT_20000324 = '\0';
        FUN_08011874((uint)DAT_20000319,(uint)DAT_2000031a,(uint)DAT_2000031b);
      }
      else {
        DAT_20000324 = '\0';
        FUN_08011874((uint)DAT_20000319,(uint)DAT_2000031a,(uint)DAT_2000031b);
      }
    }
    else if (DAT_20000324 == '\0') {
      if (DAT_200003a6 == 0) {
        DAT_20000322 = DAT_200003aa;
      }
      else {
        DAT_20000317 = DAT_200003a5;
        DAT_20000318 = DAT_200003a6;
        DAT_20000319 = DAT_200003a7;
        DAT_2000031a = DAT_200003a8;
        DAT_2000031b = DAT_200003a9;
        _DAT_20000320 = (ushort)DAT_200003ac + (ushort)DAT_200003ab * 0x100;
        FUN_080128ee((uint)DAT_200003a6);
        FUN_080126b4((uint)DAT_20000318);
        FUN_080124ea((uint)DAT_20000318);
        FUN_08011c8e((uint)DAT_20000318);
        FUN_080119aa((uint)DAT_20000318);
        FUN_08011980((uint)DAT_20000318);
        FUN_08011874((uint)DAT_20000319,(uint)DAT_2000031a,(uint)DAT_2000031b);
        FUN_080110e8();
      }
    }
  }
  return;
}

