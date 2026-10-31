// rea decompile_all
// name: FUN_0801053e
// address: 0x801053e
// body: available
// range: 0x801053e-0x80105dd inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0801053e(void)

{
  if (DAT_20000417 == '\0') {
    if (DAT_20000390 == '\x01') {
      FUN_08010330();
    }
    else if (DAT_20000390 == '\0') {
      FUN_080101a2();
    }
    else if ((uint)DAT_20000418 == ((int)(uint)DAT_20000418 >> 1) * 2) {
      FUN_080101a2();
    }
    else {
      FUN_08010330();
    }
    DAT_20000417 = DAT_20000417 + '\x01';
  }
  else if (DAT_20000417 == '\x01') {
    if (DAT_20000390 == '\x01') {
      FUN_0800fffc();
    }
    else if (DAT_20000390 == '\0') {
      FUN_0800fdcc();
    }
    else {
      if ((uint)DAT_20000418 == ((int)(uint)DAT_20000418 >> 1) * 2) {
        FUN_0800fdcc();
      }
      else {
        FUN_0800fffc();
      }
      DAT_20000418 = DAT_20000418 + 1;
    }
    DAT_20000417 = '\0';
  }
  else {
    DAT_20000417 = '\0';
  }
  return;
}

