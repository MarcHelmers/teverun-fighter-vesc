// rea decompile_all
// name: FUN_0002090c
// address: 0x2090c
// body: available
// range: 0x2090c-0x209ef inclusive
// range: 0x209f1-0x20b09 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002090c(byte *param_1)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  short sVar4;
  short sVar5;
  byte bVar6;
  byte *pbVar7;
  byte local_12;
  ushort local_a;
  
  sVar4 = *(short *)(_DAT_20000ca0 + 10);
  sVar5 = *(short *)(_DAT_20000ca0 + 0xc);
  cVar1 = *(char *)(_DAT_20000ca0 + 8);
  bVar2 = *param_1;
  for (local_a = 0; local_a < bVar2; local_a = local_a + 1) {
    pbVar7 = (byte *)(*(int *)(param_1 + 4) + (uint)local_a * 0x20);
    bVar3 = *pbVar7;
    local_12 = pbVar7[1];
    if (((((bVar3 & 1) == 0) && ((int)((uint)bVar3 * 0x40000000) < 0)) &&
        ((int)((uint)bVar3 * 0x10000000) < 0)) && (-1 < (int)((uint)bVar3 * 0x2000000))) {
      if ((cVar1 == '\0') || (sVar4 == -1)) {
        if ((int)((uint)local_12 * 0x2000000) < 0) {
          if ((int)((uint)local_12 * 0x4000000) < 0) {
            if ((int)((uint)local_12 * 0x40000000) < 0) {
              local_12 = local_12 | 0x80;
            }
            local_12 = local_12 | 8;
          }
          else {
            local_12 = local_12 | 0x10;
          }
          if ((int)((uint)local_12 * 0x2000000) < 0) {
            local_12 = local_12 | 1;
          }
          local_12 = local_12 & 0xb9;
        }
      }
      else {
        if (-1 < (int)((uint)local_12 * 0x2000000)) {
          local_12 = local_12 & 0x67 | 5;
        }
        bVar6 = local_12 & 0xdf;
        bVar3 = bVar6;
        if (((*(short *)(pbVar7 + 8) <= sVar4) && (sVar4 <= *(short *)(pbVar7 + 0xc))) &&
           ((*(short *)(pbVar7 + 10) <= sVar5 &&
            ((sVar5 <= *(short *)(pbVar7 + 0xe) &&
             (bVar3 = bVar6 | 0x20, -1 < (int)((uint)(bVar6 | 0x20) * 0x2000000))))))) {
          bVar3 = local_12 & 0xdb | 0x22;
        }
        local_12 = bVar3;
        local_12 = local_12 | 0x40;
      }
    }
    pbVar7[1] = local_12;
  }
  return;
}

