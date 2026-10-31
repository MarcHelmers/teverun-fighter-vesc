// rea decompile_all
// name: FUN_08012c76
// address: 0x8012c76
// body: available
// range: 0x8012c76-0x8012cdb inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08012c76(void)

{
  FUN_08011874(0,0,0);
  _DAT_40010c28 = 0x2000;
  FUN_080128ee((uint)DAT_20000318);
  FUN_080126b4((uint)DAT_20000318);
  FUN_080124ea((uint)DAT_20000318);
  FUN_08011c8e((uint)DAT_20000318);
  FUN_080119aa((uint)DAT_20000318);
  FUN_08011980((uint)DAT_20000318);
  FUN_08011874((uint)DAT_20000319,(uint)DAT_2000031a,(uint)DAT_2000031b);
  FUN_080110e8();
  FUN_080110b6();
  return;
}

