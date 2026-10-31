// rea decompile_all
// name: FUN_00019d6c
// address: 0x19d6c
// body: available
// range: 0x19d6c-0x19d89 inclusive
// range: 0x19d9e-0x19db9 inclusive
// range: 0x19dbe-0x1a22d inclusive
// range: 0x1a232-0x1a32d inclusive
// range: 0x1a332-0x1a41b inclusive
// range: 0x1a420-0x1a4f9 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00019d6c(void)

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
      if (DAT_200001b2 < 0x39) {
        DAT_200001b2 = DAT_200001b2 + 1;
      }
      else {
        DAT_200001b2 = 0x39;
      }
      break;
    case 1:
      if (DAT_200001b3 < 0x39) {
        DAT_200001b3 = DAT_200001b3 + 1;
      }
      else {
        DAT_200001b3 = 0x39;
      }
      break;
    case 2:
      if (DAT_200001b4 < 0x39) {
        DAT_200001b4 = DAT_200001b4 + 1;
      }
      else {
        DAT_200001b4 = 0x39;
      }
      break;
    case 3:
      if (DAT_200001b5 < 0x39) {
        DAT_200001b5 = DAT_200001b5 + 1;
      }
      else {
        DAT_200001b5 = 0x39;
      }
    }
    break;
  case 3:
    DAT_2000056e = DAT_2000056e + '\x01';
    FUN_000137cc((undefined4 *)0x20000a10);
    if (DAT_20000bb5 == '\x01') {
      if (DAT_20000bbc < 4) {
        DAT_20000bbc = DAT_20000bbc + 1;
      }
      else {
        DAT_20000bbc = 4;
      }
    }
    else if (DAT_20000bd2 < 4) {
      DAT_20000bbc = DAT_20000bd2 + 1;
    }
    else {
      DAT_20000bbc = 4;
    }
    DAT_20000bb5 = '\x01';
    break;
  case 4:
    DAT_20000140 = DAT_20000140 + '\x01';
    if (DAT_20000299 == '\0') {
      if (DAT_20000298 == 0) {
        DAT_20000298 = 0;
      }
      else {
        DAT_20000298 = DAT_20000298 - 1;
      }
    }
    else {
      if ((byte)(&DAT_200002aa)[(uint)DAT_20000298 * 0x14] <
          (byte)(&DAT_200002ac)[(uint)DAT_20000298 * 0x14]) {
        cVar1 = (&DAT_200002aa)[(uint)DAT_20000298 * 0x14] + '\x01';
      }
      else {
        cVar1 = (&DAT_200002ac)[(uint)DAT_20000298 * 0x14];
      }
      (&DAT_200002aa)[(uint)DAT_20000298 * 0x14] = cVar1;
      FUN_0001a4fc();
    }
    break;
  case 5:
    switch(DAT_2000053c) {
    case 0:
      if (DAT_20000538 < 0x39) {
        DAT_20000538 = DAT_20000538 + 1;
      }
      else {
        DAT_20000538 = 0x39;
      }
      break;
    case 1:
      if (DAT_20000539 < 0x39) {
        DAT_20000539 = DAT_20000539 + 1;
      }
      else {
        DAT_20000539 = 0x39;
      }
      break;
    case 2:
      if (DAT_2000053a < 0x39) {
        DAT_2000053a = DAT_2000053a + 1;
      }
      else {
        DAT_2000053a = 0x39;
      }
      break;
    case 3:
      if (DAT_2000053b < 0x39) {
        DAT_2000053b = DAT_2000053b + 1;
      }
      else {
        DAT_2000053b = 0x39;
      }
    }
    break;
  case 6:
    if (DAT_20000189 == '\0') {
      switch(DAT_2000018a) {
      case 0:
        if (DAT_20000181 < 0x39) {
          DAT_20000181 = DAT_20000181 + 1;
        }
        else {
          DAT_20000181 = 0x39;
        }
        break;
      case 1:
        if (DAT_20000182 < 0x39) {
          DAT_20000182 = DAT_20000182 + 1;
        }
        else {
          DAT_20000182 = 0x39;
        }
        break;
      case 2:
        if (DAT_20000183 < 0x39) {
          DAT_20000183 = DAT_20000183 + 1;
        }
        else {
          DAT_20000183 = 0x39;
        }
        break;
      case 3:
        if (DAT_20000184 < 0x39) {
          DAT_20000184 = DAT_20000184 + 1;
        }
        else {
          DAT_20000184 = 0x39;
        }
      }
    }
    else {
      switch(DAT_2000018a) {
      case 0:
        if (DAT_20000185 < 0x39) {
          DAT_20000185 = DAT_20000185 + 1;
        }
        else {
          DAT_20000185 = 0x39;
        }
        break;
      case 1:
        if (DAT_20000186 < 0x39) {
          DAT_20000186 = DAT_20000186 + 1;
        }
        else {
          DAT_20000186 = 0x39;
        }
        break;
      case 2:
        if (DAT_20000187 < 0x39) {
          DAT_20000187 = DAT_20000187 + 1;
        }
        else {
          DAT_20000187 = 0x39;
        }
        break;
      case 3:
        if (DAT_20000188 < 0x39) {
          DAT_20000188 = DAT_20000188 + 1;
        }
        else {
          DAT_20000188 = 0x39;
        }
      }
    }
    break;
  case 7:
    DAT_20000140 = DAT_20000140 + '\x01';
    if (DAT_20000459 == '\0') {
      if (DAT_20000458 == 0) {
        DAT_20000458 = 0;
      }
      else {
        DAT_20000458 = DAT_20000458 - 1;
      }
    }
    else {
      if ((byte)(&DAT_2000046a)[(uint)DAT_20000458 * 0x14] <
          (byte)(&DAT_2000046c)[(uint)DAT_20000458 * 0x14]) {
        cVar1 = (&DAT_2000046a)[(uint)DAT_20000458 * 0x14] + '\x01';
      }
      else {
        cVar1 = (&DAT_2000046c)[(uint)DAT_20000458 * 0x14];
      }
      (&DAT_2000046a)[(uint)DAT_20000458 * 0x14] = cVar1;
    }
    break;
  case 8:
    DAT_20000140 = DAT_20000140 + '\x01';
    if (DAT_200001b9 == '\0') {
      if (DAT_200001b8 == 0) {
        DAT_200001b8 = 0;
      }
      else {
        DAT_200001b8 = DAT_200001b8 - 1;
      }
    }
    else {
      if ((byte)(&DAT_200001ca)[(uint)DAT_200001b8 * 0x14] <
          (byte)(&DAT_200001cc)[(uint)DAT_200001b8 * 0x14]) {
        cVar1 = (&DAT_200001ca)[(uint)DAT_200001b8 * 0x14] + '\x01';
      }
      else {
        cVar1 = (&DAT_200001cc)[(uint)DAT_200001b8 * 0x14];
      }
      (&DAT_200001ca)[(uint)DAT_200001b8 * 0x14] = cVar1;
    }
    break;
  case 9:
    DAT_20000140 = DAT_20000140 + '\x01';
    if (DAT_20000379 == '\0') {
      if (DAT_20000378 == 0) {
        DAT_20000378 = 0;
      }
      else {
        DAT_20000378 = DAT_20000378 - 1;
      }
    }
    else {
      if ((byte)(&DAT_2000038a)[(uint)DAT_20000378 * 0x14] <
          (byte)(&DAT_2000038c)[(uint)DAT_20000378 * 0x14]) {
        cVar1 = (&DAT_2000038a)[(uint)DAT_20000378 * 0x14] + '\x01';
      }
      else {
        cVar1 = (&DAT_2000038c)[(uint)DAT_20000378 * 0x14];
      }
      (&DAT_2000038a)[(uint)DAT_20000378 * 0x14] = cVar1;
    }
  }
  return;
}

