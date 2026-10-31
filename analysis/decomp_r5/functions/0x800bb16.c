// rea decompile_all
// name: FUN_0800bb16
// address: 0x800bb16
// body: available
// range: 0x800bb16-0x800bb2b inclusive
// range: 0x800bb32-0x800bc4f inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0800bb16(void)

{
  uint uVar1;
  
  if (DAT_20000051 == '\x01') {
    switch(DAT_200003e2) {
    case '\0':
      if (DAT_2000004c == '\0') {
        DAT_200003e2 = '\x03';
      }
      else {
        DAT_20000050 = 1;
        DAT_200003e2 = DAT_200003e2 + '\x01';
      }
      break;
    case '\x01':
      DAT_20000050 = 0;
      DAT_200003e2 = DAT_200003e2 + '\x01';
      DAT_200003ec = 0;
      break;
    case '\x02':
      DAT_200003ec = DAT_200003ec + 1;
      if (10 < DAT_200003ec) {
        DAT_200003e2 = DAT_200003e2 + '\x01';
        DAT_200003ec = 0;
      }
      break;
    case '\x03':
      DAT_200003e2 = DAT_200003e2 + '\x01';
      _DAT_200003e4 = 0;
      break;
    case '\x04':
      if (DAT_2000004c == '\0') {
        for (uVar1 = 0; uVar1 < 0x10; uVar1 = uVar1 + 1 & 0xff) {
          (&DAT_2000070e)[uVar1] = *(undefined1 *)(uVar1 + 0x20000cba);
        }
        for (uVar1 = 0x10; uVar1 < 0x13; uVar1 = uVar1 + 1 & 0xff) {
          (&DAT_2000070e)[uVar1] = 0x20;
        }
        FUN_08017bde();
        FUN_0800bad2(0x2000070e,0x13,0);
        FUN_0800b9ec(100);
        FUN_0800bad2(0x2000070e,0x13,1);
        DAT_200003e2 = DAT_200003e2 + '\x01';
      }
      else {
        _DAT_200003e4 = _DAT_200003e4 + 1;
        if (5 < _DAT_200003e4) {
          _DAT_200003e4 = 0;
          DAT_200003e2 = '\0';
        }
        _DAT_200003e8 = _DAT_200003e8 + 1;
        if (3 < _DAT_200003e8) {
          _DAT_200003e8 = 0;
          DAT_20000051 = '\0';
          DAT_20000050 = 0;
          DAT_200003e2 = '\0';
        }
      }
      break;
    case '\x05':
      DAT_20000051 = '\0';
      DAT_20000050 = 0;
      DAT_200003e2 = '\0';
    }
  }
  return;
}

