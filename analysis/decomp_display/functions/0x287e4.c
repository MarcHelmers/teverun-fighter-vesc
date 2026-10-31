// rea decompile_all
// name: FUN_000287e4
// address: 0x287e4
// body: available
// range: 0x287e4-0x288e7 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_000287e4(void)

{
  uint local_c;
  
  for (local_c = 0; local_c < 5; local_c = local_c + 1) {
    (&DAT_200005c2)[local_c] = *(undefined1 *)(local_c + 0x20000c70);
  }
  DAT_200005c7 = DAT_20000c6f;
  DAT_200005c8 = DAT_20000c75;
  DAT_200005c9 = DAT_20000c76;
  for (local_c = 0; local_c < 5; local_c = local_c + 1) {
    (&DAT_200005ca)[local_c] = *(undefined1 *)(local_c + 0x20000c78);
  }
  DAT_200005cf = DAT_20000c77;
  DAT_200005d0 = DAT_20000c7d;
  DAT_200005d1 = DAT_20000c7e;
  DAT_200005eb = DAT_2000058c;
  DAT_200005ec = DAT_2000058d;
  DAT_200005ed = DAT_2000058e;
  DAT_200005ee = DAT_2000058f;
  DAT_200005ef = DAT_200005a7;
  DAT_200005f0 = DAT_200005a8;
  DAT_200005f1 = DAT_200005a9;
  DAT_200005f2 = DAT_200005aa;
  FUN_00027fc0(0);
  return;
}

