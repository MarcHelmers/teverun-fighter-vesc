// rea decompile_all
// name: FUN_08013338
// address: 0x8013338
// body: available
// range: 0x8013338-0x80133f3 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_08013338(void)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  undefined4 auStack_30 [7];
  
  FUN_0801ce64(auStack_30,(undefined4 *)&DAT_0801d538,0x1c);
  if (DAT_20000067 == '\x01') {
    if (DAT_200004d4 != '\x01') {
      DAT_200004d4 = '\x01';
      bVar1 = FUN_0801165a(0);
      uVar2 = FUN_08011660(0xff0000);
      uVar3 = FUN_08011668(0xff0000);
      FUN_08011730(uVar3,uVar2,(uint)bVar1);
    }
  }
  else if (DAT_20000067 == '\x02') {
    if (DAT_200004d4 != '\x02') {
      DAT_200004d4 = '\x02';
      bVar1 = FUN_0801165a(0);
      uVar2 = FUN_08011660(0xffff00);
      uVar3 = FUN_08011668(0xffff00);
      FUN_08011730(uVar3,uVar2,(uint)bVar1);
    }
  }
  else if (DAT_200004d4 != '\0') {
    DAT_200004d4 = '\0';
    FUN_08011730(0,0,0);
  }
  if (((DAT_200004d4 == '\0') || (DAT_200004d4 == '\x01')) || (DAT_200004d4 == '\x02')) {
    FUN_08013294();
  }
  return;
}

