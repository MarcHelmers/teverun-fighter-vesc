// rea decompile_all
// name: FUN_00017fd4
// address: 0x17fd4
// body: available
// range: 0x17fd4-0x17fef inclusive
// range: 0x17ffa-0x1804d inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00017fd4(undefined1 param_1,char *param_2)

{
  switch(param_1) {
  case 0:
    FUN_00018050(param_2);
    break;
  case 1:
    FUN_0001812c(param_2);
    break;
  case 2:
    FUN_000181ac(param_2);
    break;
  case 3:
    FUN_00018274((int)param_2);
    break;
  case 4:
    FUN_00018334((int)param_2);
    break;
  case 5:
    FUN_000183f4(param_2);
    break;
  case 6:
    FUN_000184ec((int)param_2);
    break;
  case 7:
    FUN_000185ac(param_2);
    break;
  case 8:
    FUN_000186a4(param_2);
    break;
  default:
    *param_2 = '\0';
  }
  return;
}

