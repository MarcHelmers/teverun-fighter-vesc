// rea decompile_all
// name: FUN_00025e2c
// address: 0x25e2c
// body: available
// range: 0x25e2c-0x25fab inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00025e2c(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  uint local_c;
  
  uVar2 = FUN_00013004(0x40042000,0x4010);
  if (uVar2 != 0) {
    while (uVar2 = FUN_00012d6c(0x40042000), uVar2 == 0) {
      iVar3 = FUN_00012d28((uint *)0x40042000,&local_c);
      if (iVar3 == 0) {
        cVar1 = (char)local_c;
        if (DAT_20000a1d == '\0') {
          if ((local_c == 0x35) || (local_c == 0xaa)) {
            DAT_20000a1d = '\x01';
            DAT_20000a1e = DAT_20000a1e + 1;
            DAT_20000a1f = cVar1;
          }
          else {
            DAT_20000a1d = '\0';
          }
        }
        else if ((DAT_20000a1e == 0x26) && (DAT_20000a1f == '5')) {
          DAT_20000a52 = cVar1;
          cRam20000a45 = cVar1;
          FUN_00025d44(0x200006ca,(undefined4 *)&DAT_20000a1f);
          DAT_20000a1d = '\0';
          DAT_20000a1e = 0;
        }
        else if (DAT_20000a1e < 0x2c) {
          (&DAT_20000a1f)[DAT_20000a1e] = cVar1;
          DAT_20000a1e = DAT_20000a1e + 1;
        }
        else {
          DAT_20000a1d = '\0';
          DAT_20000a1e = 0;
        }
      }
    }
    uVar2 = FUN_00013004(0x40042000,0x4000);
    if (uVar2 != 0) {
      FUN_00012fe0(0x40042000,0x4000);
      DAT_20000a53 = 2;
    }
  }
  return;
}

