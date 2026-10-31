// rea decompile_all
// name: FUN_08018594
// address: 0x8018594
// body: available
// range: 0x8018594-0x80185c3 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_08018594(void)

{
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined8 uVar1;
  
  FUN_0801920a();
  FUN_08018fc6();
  uVar1 = FUN_08019a54();
  FUN_08019368((int)uVar1,(int)((ulonglong)uVar1 >> 0x20),extraout_r2,extraout_r3);
  uVar1 = FUN_0801950c();
  FUN_0801b7f6((int)uVar1,(int)((ulonglong)uVar1 >> 0x20),extraout_r2_00,extraout_r3_00);
  FUN_08019768(0x40013800);
  FUN_08019768(0x40004400);
  FUN_08019768(0x40004800);
  enableIRQinterrupts();
  return;
}

