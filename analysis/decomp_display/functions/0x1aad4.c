// rea decompile_all
// name: FUN_0001aad4
// address: 0x1aad4
// body: available
// range: 0x1aad4-0x1aaf1 inclusive
// range: 0x1ab06-0x1ab21 inclusive
// range: 0x1ab26-0x1af95 inclusive
// range: 0x1af9a-0x1b095 inclusive
// range: 0x1b09a-0x1b183 inclusive
// range: 0x1b188-0x1b261 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0001aad4(void)

{
  char cVar1;
  
  switch(DAT_2000053e) {
  case 0:
    break;
  case 1:
    break;
  case 2:
    switch(DAT_200001b6) {
    case 0:
      if (DAT_200001b2 < 0x31) {
        DAT_200001b2 = 0x30;
      }
      else {
        DAT_200001b2 = DAT_200001b2 - 1;
      }
      break;
    case 1:
      if (DAT_200001b3 < 0x31) {
        DAT_200001b3 = 0x30;
      }
      else {
        DAT_200001b3 = DAT_200001b3 - 1;
      }
      break;
    case 2:
      if (DAT_200001b4 < 0x31) {
        DAT_200001b4 = 0x30;
      }
      else {
        DAT_200001b4 = DAT_200001b4 - 1;
      }
      break;
    case 3:
      if (DAT_200001b5 < 0x31) {
        DAT_200001b5 = 0x30;
      }
      else {
        DAT_200001b5 = DAT_200001b5 - 1;
      }
    }
    break;
  case 3:
    DAT_2000056e = DAT_2000056e + '\x01';
    FUN_000137cc((undefined4 *)0x20000a10);
    if (DAT_20000bb5 == '\x01') {
      if (DAT_20000bbc < 3) {
        DAT_20000bbc = 2;
      }
      else {
        DAT_20000bbc = DAT_20000bbc - 1;
      }
    }
    else if (DAT_20000bd2 < 3) {
      DAT_20000bbc = 2;
    }
    else {
      DAT_20000bbc = DAT_20000bd2 - 1;
    }
    DAT_20000bb5 = '\x01';
    break;
  case 4:
    DAT_20000140 = DAT_20000140 + '\x01';
    if (DAT_20000299 == '\0') {
      if (DAT_20000298 < 9) {
        DAT_20000298 = DAT_20000298 + 1;
      }
      else {
        DAT_20000298 = 9;
      }
    }
    else {
      if ((byte)(&DAT_200002ab)[(uint)DAT_20000298 * 0x14] <
          (byte)(&DAT_200002aa)[(uint)DAT_20000298 * 0x14]) {
        cVar1 = (&DAT_200002aa)[(uint)DAT_20000298 * 0x14] + -1;
      }
      else {
        cVar1 = (&DAT_200002ab)[(uint)DAT_20000298 * 0x14];
      }
      (&DAT_200002aa)[(uint)DAT_20000298 * 0x14] = cVar1;
      FUN_0001a4fc();
    }
    break;
  case 5:
    switch(DAT_2000053c) {
    case 0:
      if (DAT_20000538 < 0x31) {
        DAT_20000538 = 0x30;
      }
      else {
        DAT_20000538 = DAT_20000538 - 1;
      }
      break;
    case 1:
      if (DAT_20000539 < 0x31) {
        DAT_20000539 = 0x30;
      }
      else {
        DAT_20000539 = DAT_20000539 - 1;
      }
      break;
    case 2:
      if (DAT_2000053a < 0x31) {
        DAT_2000053a = 0x30;
      }
      else {
        DAT_2000053a = DAT_2000053a - 1;
      }
      break;
    case 3:
      if (DAT_2000053b < 0x31) {
        DAT_2000053b = 0x30;
      }
      else {
        DAT_2000053b = DAT_2000053b - 1;
      }
    }
    break;
  case 6:
    if (DAT_20000189 == '\0') {
      switch(DAT_2000018a) {
      case 0:
        if (DAT_20000181 < 0x31) {
          DAT_20000181 = 0x30;
        }
        else {
          DAT_20000181 = DAT_20000181 - 1;
        }
        break;
      case 1:
        if (DAT_20000182 < 0x31) {
          DAT_20000182 = 0x30;
        }
        else {
          DAT_20000182 = DAT_20000182 - 1;
        }
        break;
      case 2:
        if (DAT_20000183 < 0x31) {
          DAT_20000183 = 0x30;
        }
        else {
          DAT_20000183 = DAT_20000183 - 1;
        }
        break;
      case 3:
        if (DAT_20000184 < 0x31) {
          DAT_20000184 = 0x30;
        }
        else {
          DAT_20000184 = DAT_20000184 - 1;
        }
      }
    }
    else {
      switch(DAT_2000018a) {
      case 0:
        if (DAT_20000185 < 0x31) {
          DAT_20000185 = 0x30;
        }
        else {
          DAT_20000185 = DAT_20000185 - 1;
        }
        break;
      case 1:
        if (DAT_20000186 < 0x31) {
          DAT_20000186 = 0x30;
        }
        else {
          DAT_20000186 = DAT_20000186 - 1;
        }
        break;
      case 2:
        if (DAT_20000187 < 0x31) {
          DAT_20000187 = 0x30;
        }
        else {
          DAT_20000187 = DAT_20000187 - 1;
        }
        break;
      case 3:
        if (DAT_20000188 < 0x31) {
          DAT_20000188 = 0x30;
        }
        else {
          DAT_20000188 = DAT_20000188 - 1;
        }
      }
    }
    break;
  case 7:
    DAT_20000140 = DAT_20000140 + '\x01';
    if (DAT_20000459 == '\0') {
      if (DAT_20000458 < 8) {
        DAT_20000458 = DAT_20000458 + 1;
      }
      else {
        DAT_20000458 = 8;
      }
    }
    else {
      if ((byte)(&DAT_2000046b)[(uint)DAT_20000458 * 0x14] <
          (byte)(&DAT_2000046a)[(uint)DAT_20000458 * 0x14]) {
        cVar1 = (&DAT_2000046a)[(uint)DAT_20000458 * 0x14] + -1;
      }
      else {
        cVar1 = (&DAT_2000046b)[(uint)DAT_20000458 * 0x14];
      }
      (&DAT_2000046a)[(uint)DAT_20000458 * 0x14] = cVar1;
    }
    break;
  case 8:
    DAT_20000140 = DAT_20000140 + '\x01';
    if (DAT_200001b9 == '\0') {
      if (DAT_200001b8 < 6) {
        DAT_200001b8 = DAT_200001b8 + 1;
      }
      else {
        DAT_200001b8 = 6;
      }
    }
    else {
      if ((byte)(&DAT_200001cb)[(uint)DAT_200001b8 * 0x14] <
          (byte)(&DAT_200001ca)[(uint)DAT_200001b8 * 0x14]) {
        cVar1 = (&DAT_200001ca)[(uint)DAT_200001b8 * 0x14] + -1;
      }
      else {
        cVar1 = (&DAT_200001cb)[(uint)DAT_200001b8 * 0x14];
      }
      (&DAT_200001ca)[(uint)DAT_200001b8 * 0x14] = cVar1;
    }
    break;
  case 9:
    DAT_20000140 = DAT_20000140 + '\x01';
    if (DAT_20000379 == '\0') {
      if (DAT_20000378 < 5) {
        DAT_20000378 = DAT_20000378 + 1;
      }
      else {
        DAT_20000378 = 5;
      }
    }
    else {
      if ((byte)(&DAT_2000038b)[(uint)DAT_20000378 * 0x14] <
          (byte)(&DAT_2000038a)[(uint)DAT_20000378 * 0x14]) {
        cVar1 = (&DAT_2000038a)[(uint)DAT_20000378 * 0x14] + -1;
      }
      else {
        cVar1 = (&DAT_2000038b)[(uint)DAT_20000378 * 0x14];
      }
      (&DAT_2000038a)[(uint)DAT_20000378 * 0x14] = cVar1;
    }
  }
  return;
}

