// rea decompile_all
// name: FUN_0800eef2
// address: 0x800eef2
// body: available
// range: 0x800eef2-0x800f011 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0800eef2(void)

{
  if (DAT_200003fe == '\x01') {
    DAT_200003fe = '\0';
    if (DAT_20001381 == -0x76) {
      if (DAT_20001383 == '\b') {
        DAT_20000734 = DAT_20001384;
        DAT_20000735 = DAT_20001385;
        DAT_20000736 = DAT_20001386;
        DAT_20000737 = DAT_20001387;
        DAT_20000738 = DAT_20001388;
        DAT_20000739 = DAT_20001389;
        DAT_2000073a = DAT_2000138a;
        DAT_2000009d = '\x01';
      }
      else if (DAT_20001383 == '\t') {
        if (DAT_2000009d == '\x01') {
          DAT_2000073b = DAT_20001384;
          DAT_2000073c = DAT_20001385;
          DAT_2000073d = DAT_20001386;
          DAT_2000073e = DAT_20001387;
          DAT_2000073f = DAT_20001388;
          DAT_20000740 = DAT_20001389;
          DAT_20000741 = DAT_2000138a;
          DAT_2000009d = '\x02';
        }
      }
      else if ((DAT_20001383 == '\n') && (DAT_2000009d == '\x02')) {
        DAT_20000742 = DAT_20001384;
        DAT_20000743 = DAT_20001385;
        DAT_20000744 = DAT_20001386;
        DAT_20000745 = DAT_20001387;
        DAT_20000746 = DAT_20001388;
        DAT_2000009d = '\0';
        FUN_08018254(0x20000734);
      }
    }
    else if (DAT_20001381 == -0x75) {
      if (((DAT_20001383 == -0x56) && (DAT_20001385 == -0x56)) && (DAT_20001387 == -0x56)) {
        FUN_08016f08();
      }
    }
    else if ((((DAT_20001381 == -0x74) && (DAT_20001383 == '\x01')) && (DAT_20001386 == -0x56)) &&
            (DAT_20001387 == -0x56)) {
      FUN_08017df6();
    }
  }
  return;
}

