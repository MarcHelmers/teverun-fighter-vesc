// rea decompile_all
// name: FUN_0801bc74
// address: 0x801bc74
// body: available
// range: 0x801bc74-0x801bd09 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0801bc74(void)

{
  char cVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 local_40;
  undefined4 uStack_3c;
  ushort local_38 [4];
  undefined1 local_30;
  undefined1 local_2f;
  undefined1 local_2e;
  undefined1 local_2d [13];
  undefined4 local_20;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  undefined1 local_19 [9];
  
  sVar2 = -1;
  local_40 = 0x4030201;
  uStack_3c = 0x8070605;
  local_48 = 0x5060708;
  uStack_44 = 0x1020304;
  local_38[0] = 0x400;
  local_38[1] = 0;
  local_30 = 0;
  local_2f = 0;
  local_2e = 8;
  for (uVar4 = 0; uVar4 < 8; uVar4 = uVar4 + 1 & 0xff) {
    local_2d[uVar4] = *(undefined1 *)((int)&local_40 + uVar4);
  }
  local_20 = 0x12345678;
  local_1c = 4;
  local_1b = 0;
  local_1a = 8;
  for (uVar4 = 0; uVar4 < 8; uVar4 = uVar4 + 1 & 0xff) {
    local_19[uVar4] = *(undefined1 *)((int)&local_48 + uVar4);
  }
  iVar3 = FUN_0800a856(0x40006400,local_38);
  for (; (cVar1 = FUN_0800a97c(0x40006400,iVar3), cVar1 != '\x01' && (sVar2 != 0));
      sVar2 = sVar2 + -1) {
  }
  return;
}

