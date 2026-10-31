// rea decompile_all
// name: FUN_00013b48
// address: 0x13b48
// body: available
// range: 0x13b48-0x13e8f inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00013b48(void)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  char cVar4;
  
  if (DAT_2000053f != DAT_2000053e) {
    DAT_2000053f = DAT_2000053e;
    FUN_0001e260(0);
    FUN_0001e930(100,0x96,0x104,0x168,0xffff);
    FUN_0001e930(0x65,0x97,0x103,0x167,0xffff);
    FUN_0001e930(0x66,0x98,0x102,0x166,0xffff);
    FUN_0001e930(0x67,0x99,0x101,0x165,0xffff);
    FUN_0001e1ec((undefined4 *)0x3e67c);
    FUN_0002040c(0xffff);
    FUN_00020428(0);
    FUN_0001f1e8(0x20,0x4b,(byte *)0x56d43);
    FUN_0001e1ec((undefined4 *)0x3e6b8);
    FUN_0001f1e8(0x90,0xc3,(byte *)0x56d50);
    FUN_0001f1e8(0x84,0x10e,(byte *)0x56d3e);
    DAT_2000018e = '\0';
  }
  bVar2 = FUN_0002b084();
  cVar1 = DAT_20000a1c;
  bVar3 = FUN_0002c490();
  cVar4 = FUN_0002b668();
  if (bVar2) {
    if (bVar3) {
      FUN_0001e1ec((undefined4 *)0x3e67c);
      FUN_0002040c(0xffff);
      FUN_00020428(0);
      if (cVar4 == '\x02') {
        FUN_0001f1e8(0x20,0x4b,(byte *)0x56cc5);
      }
      else if (cVar4 == '\n') {
        FUN_0001f1e8(0x20,0x4b,(byte *)0x56bd9);
      }
      else if (cVar4 == '\v') {
        FUN_0001f1e8(0x20,0x4b,(byte *)0x56bc6);
      }
      else if (cVar4 == '\x03') {
        FUN_0001f1e8(0x20,0x4b,(byte *)0x56c89);
      }
      else if (cVar4 == '\x05') {
        FUN_0001f1e8(0x20,0x4b,(byte *)0x56c9d);
      }
      else if (cVar4 == '\a') {
        FUN_0001f1e8(0x20,0x4b,(byte *)0x56d17);
      }
      else if (cVar4 == '\b') {
        FUN_0001f1e8(0x20,0x4b,(byte *)0x56d03);
      }
      else if (cVar4 == '\t') {
        FUN_0001f1e8(0x20,0x4b,(byte *)0x56cb1);
      }
      else {
        FUN_0001f1e8(0x20,0x4b,(byte *)0x56cd9);
      }
    }
    else {
      FUN_0001e1ec((undefined4 *)0x3e67c);
      FUN_0002040c(0xffff);
      FUN_00020428(0);
      FUN_0001f1e8(0x20,0x4b,(byte *)0x56c76);
    }
  }
  else {
    FUN_0001e1ec((undefined4 *)0x3e67c);
    FUN_0002040c(0xffff);
    FUN_00020428(0);
    if (DAT_2000018e == '\0') {
      FUN_0001f1e8(0x20,0x4b,(byte *)0x56bfe);
    }
    else {
      FUN_0001f1e8(0x20,0x4b,(byte *)0x56bec);
    }
    if ((cVar1 == '\x03') || (cVar1 == '\x06')) {
      DAT_2000018e = '\x01';
    }
  }
  if ((DAT_2000018e != '\0') && (DAT_200005a5 != '\0')) {
    DAT_2000053e = '\x03';
    DAT_20000578 = 1;
    if (DAT_20000bf2 != '\0') {
      DAT_20000bb4 = 1;
    }
  }
  return;
}

