// rea decompile_all
// name: FUN_00019630
// address: 0x19630
// body: available
// range: 0x19630-0x196d5 inclusive
// range: 0x196e0-0x19949 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00019630(void)

{
  if (DAT_2000053f != DAT_2000053e) {
    DAT_2000053f = DAT_2000053e;
    DAT_2000018f = '\0';
    DAT_200012f8 = '\0';
    DAT_200000c8 = '\0';
    DAT_20000bc8 = '\0';
  }
  if (DAT_200000c8 != DAT_200012f8) {
    DAT_2000018f = '\0';
    DAT_200000c8 = DAT_200012f8;
  }
  switch(DAT_200012f8) {
  case '\0':
    if (DAT_2000018f == '\0') {
      DAT_2000018f = '\x01';
      FUN_0001e260(0);
      FUN_0001e294(3,0,0x165,0x3e,0x18ce);
      FUN_00020e9c(3,0,0x165,0x3e,(undefined2 *)0x56b94);
      FUN_0001e1ec((undefined4 *)0x3e6b8);
      FUN_0002040c(0xffe0);
      FUN_00020428(0x18ce);
      FUN_0001f1e8(0x3c,0xf,(byte *)0x56d74);
      DAT_200000cd = DAT_20000c77 + '0';
      DAT_200000cf = DAT_20000c7d + '0';
      DAT_200000d1 = DAT_20000c7e + '0';
      DAT_200000d4 = DAT_20000c7b + '0';
      DAT_200000b8 = DAT_20000591;
      DAT_200000b9 = DAT_20000592;
      DAT_200000ba = DAT_20000593;
      DAT_200000bb = DAT_20000594;
      DAT_200000bc = DAT_20000595;
      DAT_200000bd = DAT_20000596;
      DAT_200000be = DAT_20000597;
      DAT_200000bf = DAT_20000598;
      DAT_200000c0 = DAT_20000599;
      DAT_200000c1 = DAT_2000059a;
      DAT_200000c2 = DAT_2000059b;
      DAT_200000c3 = DAT_2000059c;
      DAT_200000c4 = DAT_2000059d;
      DAT_200000c5 = DAT_2000059e;
      DAT_200000c6 = 0;
      FUN_0001e1ec((undefined4 *)0x3e67c);
      FUN_0002040c(0xffff);
      FUN_00020428(0);
      FUN_0001f1e8(0x10,100,(byte *)0x200000b4);
      FUN_0001f1e8(0x10,0x8c,(byte *)0x200000c9);
    }
    if ((DAT_2000018f == '\x01') && (DAT_20000bc8 == 'U')) {
      DAT_2000018f = '\x02';
      FUN_0001e1ec((undefined4 *)0x3e67c);
      FUN_0002040c(0xffff);
      FUN_00020428(0);
      FUN_0001f1e8(0x32,0x140,(byte *)0x56d88);
    }
    break;
  case '\x01':
    if (DAT_2000018f == '\0') {
      DAT_2000018f = '\x01';
      FUN_0001e260(0xf800);
    }
    break;
  case '\x02':
    if (DAT_2000018f == '\0') {
      DAT_2000018f = '\x01';
      FUN_0001e260(0x7e0);
    }
    break;
  case '\x03':
    if (DAT_2000018f == '\0') {
      DAT_2000018f = '\x01';
      FUN_0001e260(0x1f);
    }
    break;
  case '\x04':
    if (DAT_2000018f == '\0') {
      DAT_2000018f = '\x01';
      FUN_0001e260(0xffff);
    }
  }
  return;
}

