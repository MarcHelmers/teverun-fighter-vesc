// rea decompile_all
// name: FUN_0001a6fc
// address: 0x1a6fc
// body: available
// range: 0x1a6fc-0x1a71f inclusive
// range: 0x1a732-0x1aad3 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Removing unreachable block (ram,0x0001a84a) */

void FUN_0001a6fc(void)

{
  uint uVar1;
  char cVar2;
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
    if (DAT_2000053d == '\0') {
      DAT_2000053d = '\x01';
      if (DAT_20000bb5 == '\x02') {
        uVar1 = (DAT_20000bae & 0x3f) >> 5;
        if (uVar1 == 0) {
          DAT_20000bae = DAT_20000bae & 0xdf;
        }
        else if (uVar1 == 1) {
          DAT_20000bae = DAT_20000bae & 0xdf | 0x20;
        }
      }
      else {
        if (DAT_20000c1b != '\0') {
          local_9 = 2;
        }
        if (DAT_20000c1a != '\0') {
          local_9 = local_9 | 1;
        }
        DAT_20000bd1 = DAT_20000bd1 == '\0';
        if ((bool)DAT_20000bd1) {
          DAT_20000bae = DAT_20000bae & 0x1f | local_9 << 6 | 0x20;
        }
        else {
          DAT_20000bae = DAT_20000bae & 0x1f | local_9 << 6;
        }
      }
      DAT_20000bb5 = '\x02';
    }
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
        cVar2 = (&DAT_200002aa)[(uint)DAT_20000298 * 0x14] + '\x01';
      }
      else {
        cVar2 = (&DAT_200002ac)[(uint)DAT_20000298 * 0x14];
      }
      (&DAT_200002aa)[(uint)DAT_20000298 * 0x14] = cVar2;
      FUN_0001a4fc();
    }
    break;
  default:
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
        cVar2 = (&DAT_2000046a)[(uint)DAT_20000458 * 0x14] + '\x01';
      }
      else {
        cVar2 = (&DAT_2000046c)[(uint)DAT_20000458 * 0x14];
      }
      (&DAT_2000046a)[(uint)DAT_20000458 * 0x14] = cVar2;
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
        cVar2 = (&DAT_200001ca)[(uint)DAT_200001b8 * 0x14] + '\x01';
      }
      else {
        cVar2 = (&DAT_200001cc)[(uint)DAT_200001b8 * 0x14];
      }
      (&DAT_200001ca)[(uint)DAT_200001b8 * 0x14] = cVar2;
    }
  }
  return;
}

