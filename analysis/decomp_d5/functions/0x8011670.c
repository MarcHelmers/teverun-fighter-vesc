// rea decompile_all
// name: FUN_08011670
// address: 0x8011670
// body: available
// range: 0x8011670-0x801172f inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int FUN_08011670(uint param_1,uint param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  longlong lVar5;
  ulonglong uVar6;
  byte local_5c [4];
  byte local_58 [4];
  byte local_54 [4];
  undefined8 local_50;
  undefined8 local_48;
  ulonglong local_40 [4];
  
  local_40[0] = 0;
  local_48 = 0;
  local_50 = 0;
  uVar2 = FUN_08011668(param_2);
  uVar3 = FUN_08011660(param_2);
  bVar1 = FUN_0801165a((char)param_2);
  FUN_080112ec(uVar2,uVar3,(uint)bVar1,local_40,&local_48,&local_50);
  uVar6 = FUN_0801d1bc(param_1);
  uVar6 = FUN_0801cffa((uint)uVar6,(uint)(uVar6 >> 0x20),(uint)local_50,
                       (uint)((ulonglong)local_50 >> 0x20));
  uVar6 = FUN_0801d0de((uint)uVar6,(uint)(uVar6 >> 0x20),0,0x4074d000);
  lVar5 = (uVar6 & 0xffffffff00000000) + (uVar6 & 0xffffffff);
  FUN_08011128((uint)local_48,(uint)((ulonglong)local_48 >> 0x20),(uint)lVar5,
               (uint)((ulonglong)lVar5 >> 0x20),local_54,local_58,local_5c);
  iVar4 = FUN_08010fac((uint)local_54[0],(uint)local_58[0],(uint)local_5c[0]);
  return iVar4;
}

