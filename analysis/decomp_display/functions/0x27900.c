// rea decompile_all
// name: FUN_00027900
// address: 0x27900
// body: available
// range: 0x27900-0x27d27 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00027900(void)

{
  ushort uVar1;
  byte abStack_40 [8];
  char local_38;
  char local_37;
  char local_36;
  char local_35;
  char local_34;
  char local_33;
  char local_32;
  char local_31;
  char local_30;
  char local_2f;
  char local_2e;
  char local_2d;
  char local_2c;
  char local_2b;
  char local_2a;
  char local_29;
  char local_28;
  char local_27;
  char local_26;
  char local_25;
  char local_24;
  char local_23;
  ushort local_e;
  uint local_c;
  
  FUN_00029f34(0x600000,0x34,abStack_40);
  uVar1 = FUN_00028098(abStack_40,0x32);
  if (local_e == uVar1) {
    if ((((local_38 == DAT_00056bac) && (local_37 == DAT_00056bad)) && (local_36 == DAT_00056bae))
       && (((local_35 == DAT_00056baf && (local_34 == DAT_00056bb0)) &&
           ((local_33 == DAT_00056bb1 && ((local_32 == DAT_00056bb2 && (local_31 == DAT_00056bb3))))
           )))) {
      if (((((((local_30 == DAT_0003e744) && (local_2f == DAT_0003e745)) &&
             (local_2e == DAT_0003e746)) &&
            ((local_2d == DAT_0003e747 && (local_2c == DAT_0003e748)))) &&
           ((local_2b == DAT_0003e749 && ((local_2a == DAT_0003e74a && (local_29 == DAT_0003e74b))))
           )) && (local_28 == DAT_0003e74c)) &&
         ((((local_27 == DAT_0003e74d && (local_26 == DAT_0003e74e)) && (local_25 == DAT_0003e74f))
          && ((local_24 == DAT_0003e750 && (local_23 == DAT_0003e751)))))) {
        FUN_000276a4(&DAT_200005c2,abStack_40,0x34);
      }
      else {
        FUN_000276a4(&DAT_200005c2,abStack_40,0x34);
        DAT_200005d2 = DAT_0003e744;
        DAT_200005d3 = DAT_0003e745;
        DAT_200005d4 = DAT_0003e746;
        DAT_200005d5 = DAT_0003e747;
        DAT_200005d6 = DAT_0003e748;
        DAT_200005d7 = DAT_0003e749;
        DAT_200005d8 = DAT_0003e74a;
        DAT_200005d9 = DAT_0003e74b;
        DAT_200005da = DAT_0003e74c;
        DAT_200005db = DAT_0003e74d;
        DAT_200005dc = DAT_0003e74e;
        DAT_200005dd = DAT_0003e74f;
        DAT_200005de = DAT_0003e750;
        DAT_200005df = DAT_0003e751;
        DAT_200005e0 = DAT_0003e752;
        DAT_200005e1 = DAT_0003e753;
        DAT_200005e2 = DAT_0003e754;
        DAT_200005e3 = DAT_0003e755;
        DAT_200005e4 = DAT_0003e756;
        DAT_200005e5 = DAT_0003e757;
        FUN_00027fc0(0);
        FUN_000285ec();
      }
    }
    else {
      FUN_000276a4(&DAT_200005c2,abStack_40,0x34);
      DAT_200005ca = DAT_00056bac;
      DAT_200005cb = DAT_00056bad;
      DAT_200005cc = DAT_00056bae;
      DAT_200005cd = DAT_00056baf;
      DAT_200005ce = DAT_00056bb0;
      DAT_200005cf = DAT_00056bb1;
      DAT_200005d0 = DAT_00056bb2;
      DAT_200005d1 = DAT_00056bb3;
      DAT_200005ef = DAT_0003e619;
      DAT_200005f0 = DAT_0003e61a;
      DAT_200005f1 = DAT_0003e61b;
      DAT_200005f2 = DAT_0003e61c;
      FUN_00027fc0(0);
    }
  }
  else {
    FUN_0002837c();
  }
  for (local_c = 0; local_c < 5; local_c = local_c + 1) {
    *(undefined1 *)(local_c + 0x20000c70) = (&DAT_200005c2)[local_c];
  }
  DAT_20000c6f = DAT_200005c7;
  DAT_20000c75 = DAT_200005c8;
  DAT_20000c76 = DAT_200005c9;
  for (local_c = 0; local_c < 5; local_c = local_c + 1) {
    *(undefined1 *)(local_c + 0x20000c78) = (&DAT_200005ca)[local_c];
  }
  DAT_20000c77 = DAT_200005cf;
  DAT_20000c7d = DAT_200005d0;
  DAT_20000c7e = DAT_200005d1;
  DAT_2000058c = DAT_200005eb;
  DAT_2000058d = DAT_200005ec;
  DAT_2000058e = DAT_200005ed;
  DAT_2000058f = DAT_200005ee;
  DAT_200005a7 = DAT_200005ef;
  DAT_200005a8 = DAT_200005f0;
  DAT_200005a9 = DAT_200005f1;
  DAT_200005aa = DAT_200005f2;
  DAT_20000591 = DAT_200005d2;
  DAT_20000592 = DAT_200005d3;
  DAT_20000593 = DAT_200005d4;
  DAT_20000594 = DAT_200005d5;
  DAT_20000595 = DAT_200005d6;
  DAT_20000596 = DAT_200005d7;
  DAT_20000597 = DAT_200005d8;
  DAT_20000598 = DAT_200005d9;
  DAT_20000599 = DAT_200005da;
  DAT_2000059a = DAT_200005db;
  DAT_2000059b = DAT_200005dc;
  DAT_2000059c = DAT_200005dd;
  DAT_2000059d = DAT_200005de;
  DAT_2000059e = DAT_200005df;
  DAT_2000059f = 0;
  return;
}

