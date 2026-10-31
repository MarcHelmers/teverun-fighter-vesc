// rea decompile_all
// name: FUN_0801a452
// address: 0x801a452
// body: available
// range: 0x801a452-0x801a477 inclusive
// range: 0x801a484-0x801a53d inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0801a452(void)

{
  byte bVar1;
  
  for (bVar1 = 0; bVar1 < 7; bVar1 = bVar1 + 1) {
  }
  switch(DAT_20000638) {
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
    DAT_20000709 = DAT_20000639;
    DAT_2000070a = DAT_2000063a;
    DAT_2000070b = DAT_2000063b;
    DAT_2000070c = DAT_2000063c;
    DAT_2000070d = DAT_2000063d;
    DAT_2000070e = DAT_2000063e;
    DAT_2000070f = DAT_2000063f;
    DAT_2000009c = '\x01';
    break;
  case 9:
    if (DAT_2000009c == '\x01') {
      DAT_20000710 = DAT_20000639;
      DAT_20000711 = DAT_2000063a;
      DAT_20000712 = DAT_2000063b;
      DAT_20000713 = DAT_2000063c;
      DAT_20000714 = DAT_2000063d;
      DAT_20000715 = DAT_2000063e;
      DAT_20000716 = DAT_2000063f;
      DAT_2000009c = '\x02';
    }
    break;
  case 10:
    if (DAT_2000009c == '\x02') {
      DAT_20000717 = DAT_20000639;
      DAT_20000718 = DAT_2000063a;
      DAT_20000719 = DAT_2000063b;
      DAT_2000071a = DAT_2000063c;
      DAT_2000071b = DAT_2000063d;
      DAT_2000009c = '\0';
      FUN_08018110(0x20000709);
    }
  }
  return;
}

