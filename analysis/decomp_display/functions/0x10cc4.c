// rea decompile_all
// name: FUN_00010cc4
// address: 0x10cc4
// body: available
// range: 0x10cc4-0x10d97 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00010cc4(int param_1)

{
  bool bVar1;
  
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  if (param_1 == 0x1e) {
    (*(code *)&SUB_11000430)(0x8949,0xfa1,0xb11ffac);
  }
  else if (param_1 == 0x28) {
    (*(code *)&SUB_11000430)(0x8a49,0x14a9,0xb11ffac);
  }
  else if (param_1 == 0x50) {
    (*(code *)&SUB_11000430)(0xd349,0x294a,0xb11ffac);
  }
  else if (param_1 == 0x78) {
    (*(code *)&SUB_11000430)(&LAB_00011c88_1,0x3d6b,0xb11ffac);
  }
  else {
    (*(code *)&SUB_11000430)(0x16589,0x4c74,0xb11ffac);
  }
  enableIRQinterrupts();
  return;
}

