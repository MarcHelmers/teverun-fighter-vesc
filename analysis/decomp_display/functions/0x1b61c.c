// rea decompile_all
// name: FUN_0001b61c
// address: 0x1b61c
// body: available
// range: 0x1b61c-0x1b63f inclusive
// range: 0x1b656-0x1b6b5 inclusive
// range: 0x1b6ba-0x1b76d inclusive
// range: 0x1b772-0x1ba27 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0001b61c(void)

{
  uint uVar1;
  byte local_9;
  
  local_9 = 0;
  switch(DAT_2000053e) {
  case 0:
    break;
  case 1:
    break;
  case 2:
    DAT_200001b6 = DAT_200001b6 + 1 & 3;
    break;
  case 3:
    if (DAT_20000c22 == '\0') {
      DAT_200001ae = DAT_200001ae + 1 & 3;
    }
    else {
      if (DAT_20000bb5 == '\x02') {
        switch(DAT_20000bae >> 6) {
        case 0:
          DAT_20000bae = DAT_20000bae & 0x3f | 0x80;
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
          DAT_20000bae = DAT_20000bae & 0x3f | 0x80;
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
    DAT_20000140 = DAT_20000140 + '\x01';
    if ((&DAT_200002a9)[(uint)DAT_20000298 * 0x14] == '\x01') {
      DAT_20000299 = DAT_20000299 == '\0';
      if (!(bool)DAT_20000299) {
        FUN_0001a4fc();
      }
    }
    else if ((&DAT_200002a9)[(uint)DAT_20000298 * 0x14] == '\x02') {
      FUN_0001ba28();
    }
    else if ((&DAT_200002a9)[(uint)DAT_20000298 * 0x14] == '\x03') {
      DAT_20000299 = DAT_20000299 == '\0';
      DAT_20000bf1 = (&DAT_200002aa)[(uint)DAT_20000298 * 0x14];
      if (!(bool)DAT_20000299) {
        FUN_0001d390();
        FUN_0001ba28();
      }
    }
    break;
  case 5:
    DAT_2000053c = DAT_2000053c + 1 & 3;
    break;
  case 6:
    DAT_2000018a = DAT_2000018a + 1 & 3;
    break;
  case 7:
    DAT_20000140 = DAT_20000140 + '\x01';
    if ((&DAT_20000469)[(uint)DAT_20000458 * 0x14] == '\x01') {
      DAT_20000459 = DAT_20000459 == '\0';
      if (!(bool)DAT_20000459) {
        FUN_0001bc80();
      }
    }
    else if ((&DAT_20000469)[(uint)DAT_20000458 * 0x14] == '\x02') {
      FUN_0001bf1c();
    }
    break;
  case 8:
    DAT_20000140 = DAT_20000140 + '\x01';
    if ((&DAT_200001c9)[(uint)DAT_200001b8 * 0x14] == '\x01') {
      DAT_200001b9 = DAT_200001b9 == '\0';
      if (!(bool)DAT_200001b9) {
        FUN_0001ba98();
      }
    }
    else if ((&DAT_200001c9)[(uint)DAT_200001b8 * 0x14] == '\x02') {
      FUN_0001bc5c();
    }
    break;
  case 9:
    DAT_20000140 = DAT_20000140 + '\x01';
    if ((&DAT_20000389)[(uint)DAT_20000378 * 0x14] == '\x02') {
      FUN_0001bf40();
    }
    break;
  case 10:
    uVar1 = (byte)(DAT_200012f8 + 1U) / 5;
    DAT_200012f8 = (DAT_200012f8 + 1U) - ((char)uVar1 + (char)(uVar1 << 2));
  }
  return;
}

