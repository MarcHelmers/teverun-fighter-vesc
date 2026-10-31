// rea decompile_all
// name: FUN_0800ee0a
// address: 0x800ee0a
// body: available
// range: 0x800ee0a-0x800ef29 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0800ee0a(void)

{
  if (DAT_200003fe == '\x01') {
    DAT_200003fe = '\0';
    if (DAT_20001369 == -0x76) {
      if (DAT_2000136b == '\b') {
        DAT_2000071c = DAT_2000136c;
        DAT_2000071d = DAT_2000136d;
        DAT_2000071e = DAT_2000136e;
        DAT_2000071f = DAT_2000136f;
        DAT_20000720 = DAT_20001370;
        DAT_20000721 = DAT_20001371;
        DAT_20000722 = DAT_20001372;
        DAT_2000009d = '\x01';
      }
      else if (DAT_2000136b == '\t') {
        if (DAT_2000009d == '\x01') {
          DAT_20000723 = DAT_2000136c;
          DAT_20000724 = DAT_2000136d;
          DAT_20000725 = DAT_2000136e;
          DAT_20000726 = DAT_2000136f;
          DAT_20000727 = DAT_20001370;
          DAT_20000728 = DAT_20001371;
          DAT_20000729 = DAT_20001372;
          DAT_2000009d = '\x02';
        }
      }
      else if ((DAT_2000136b == '\n') && (DAT_2000009d == '\x02')) {
        DAT_2000072a = DAT_2000136c;
        DAT_2000072b = DAT_2000136d;
        DAT_2000072c = DAT_2000136e;
        DAT_2000072d = DAT_2000136f;
        DAT_2000072e = DAT_20001370;
        DAT_2000009d = '\0';
        FUN_08018110(0x2000071c);
      }
    }
    else if (DAT_20001369 == -0x75) {
      if (((DAT_2000136b == -0x56) && (DAT_2000136d == -0x56)) && (DAT_2000136f == -0x56)) {
        FUN_08016dc4();
      }
    }
    else if ((((DAT_20001369 == -0x74) && (DAT_2000136b == '\x01')) && (DAT_2000136e == -0x56)) &&
            (DAT_2000136f == -0x56)) {
      FUN_08017cb2();
    }
  }
  return;
}

