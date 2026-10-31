// rea decompile_all
// name: FUN_0002837c
// address: 0x2837c
// body: available
// range: 0x2837c-0x285eb inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0002837c(void)

{
  uint local_c;
  
  DAT_200005c2 = DAT_000567ca;
  DAT_200005c3 = DAT_000567cb;
  DAT_200005c4 = DAT_000567cc;
  DAT_200005c5 = DAT_000567cd;
  DAT_200005c6 = DAT_000567ce;
  DAT_200005c7 = DAT_000567cf;
  DAT_200005c8 = DAT_000567d0;
  DAT_200005c9 = DAT_000567d1;
  DAT_200005ca = DAT_00056bac;
  DAT_200005cb = DAT_00056bad;
  DAT_200005cc = DAT_00056bae;
  DAT_200005cd = DAT_00056baf;
  DAT_200005ce = DAT_00056bb0;
  DAT_200005cf = DAT_00056bb1;
  DAT_200005d0 = DAT_00056bb2;
  DAT_200005d1 = DAT_00056bb3;
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
  DAT_200005e6 = DAT_0003e60a;
  DAT_200005e7 = DAT_0003e60b;
  DAT_200005e8 = DAT_0003e60c;
  DAT_200005e9 = DAT_0003e60d;
  DAT_200005ea = DAT_0003e60e;
  DAT_200005eb = DAT_0003e615;
  DAT_200005ec = DAT_0003e616;
  DAT_200005ed = DAT_0003e617;
  DAT_200005ee = DAT_0003e618;
  DAT_200005ef = DAT_0003e619;
  DAT_200005f0 = DAT_0003e61a;
  DAT_200005f1 = DAT_0003e61b;
  DAT_200005f2 = DAT_0003e61c;
  FUN_00027fc0(0);
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

