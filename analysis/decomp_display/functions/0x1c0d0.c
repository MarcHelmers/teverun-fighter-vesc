// rea decompile_all
// name: FUN_0001c0d0
// address: 0x1c0d0
// body: available
// range: 0x1c0d0-0x1c0f3 inclusive
// range: 0x1c108-0x1c17b inclusive
// range: 0x1c180-0x1c233 inclusive
// range: 0x1c238-0x1c2c5 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0001c0d0(void)

{
  byte local_9;
  
  local_9 = 0;
  switch(DAT_2000053e) {
  case 0:
    break;
  case 1:
    break;
  case 2:
    break;
  case 3:
    FUN_000137cc((undefined4 *)0x20000a10);
    if ((DAT_20000c22 == '\0') && (DAT_2000053d == '\0')) {
      DAT_2000053d = '\x01';
      if (DAT_20000bb5 == '\x02') {
        switch(DAT_20000bae >> 6) {
        case 0:
          DAT_20000bae = DAT_20000bae & 0x3f | 0x40;
          break;
        case 1:
          DAT_20000bae = DAT_20000bae & 0x3f | 0xc0;
          break;
        case 2:
          DAT_20000bae = DAT_20000bae & 0x3f | 0xc0;
          break;
        case 3:
          DAT_20000bae = DAT_20000bae & 0x3f | 0x80;
        }
      }
      else {
        if (DAT_20000c1b != '\0') {
          local_9 = 2;
        }
        if (DAT_20000c1a != '\0') {
          local_9 = local_9 | 1;
        }
        switch(local_9) {
        case 0:
          DAT_20000bae = DAT_20000bae & 0x3f | 0x40;
          break;
        case 1:
          DAT_20000bae = DAT_20000bae & 0x3f | 0xc0;
          break;
        case 2:
          DAT_20000bae = DAT_20000bae & 0x3f | 0xc0;
          break;
        case 3:
          DAT_20000bae = DAT_20000bae & 0x3f | 0x80;
        }
      }
      DAT_20000bb5 = '\x02';
    }
    break;
  case 4:
    break;
  case 5:
    break;
  case 6:
    break;
  case 7:
    break;
  case 8:
    break;
  case 9:
  }
  return;
}

