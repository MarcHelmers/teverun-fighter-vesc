// rea decompile_all
// name: FUN_0801a59a
// address: 0x801a59a
// body: available
// range: 0x801a59a-0x801a5bf inclusive
// range: 0x801a5cc-0x801a685 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0801a59a(void)

{
  byte bVar1;
  
  for (bVar1 = 0; bVar1 < 7; bVar1 = bVar1 + 1) {
  }
  switch(DAT_20000650) {
  case 1:
    break;
  case 2:
    break;
  case 3:
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
    DAT_20000721 = DAT_20000651;
    DAT_20000722 = DAT_20000652;
    DAT_20000723 = DAT_20000653;
    DAT_20000724 = DAT_20000654;
    DAT_20000725 = DAT_20000655;
    DAT_20000726 = DAT_20000656;
    DAT_20000727 = DAT_20000657;
    DAT_2000009c = '\x01';
    break;
  case 9:
    if (DAT_2000009c == '\x01') {
      DAT_20000728 = DAT_20000651;
      DAT_20000729 = DAT_20000652;
      DAT_2000072a = DAT_20000653;
      DAT_2000072b = DAT_20000654;
      DAT_2000072c = DAT_20000655;
      DAT_2000072d = DAT_20000656;
      DAT_2000072e = DAT_20000657;
      DAT_2000009c = '\x02';
    }
    break;
  case 10:
    if (DAT_2000009c == '\x02') {
      DAT_2000072f = DAT_20000651;
      DAT_20000730 = DAT_20000652;
      DAT_20000731 = DAT_20000653;
      DAT_20000732 = DAT_20000654;
      DAT_20000733 = DAT_20000655;
      DAT_2000009c = '\0';
      FUN_08018254(0x20000721);
    }
  }
  return;
}

