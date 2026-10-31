// rea decompile_all
// name: FUN_0801ca6a
// address: 0x801ca6a
// body: available
// range: 0x801ca6a-0x801cbd9 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0801ca6a(void)

{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  uint in_fpscr;
  uint uVar4;
  float fVar5;
  float fVar6;
  
  if ((DAT_20000299 < 2) || (4 < DAT_20000299)) {
    uVar3 = 0;
    DAT_20002650 = 0;
  }
  else {
    uVar3 = (uint)DAT_200002b1;
    DAT_20002650 = (&DAT_200002a4)[DAT_20000299] & 0xf;
  }
  fVar5 = (float)VectorUnsignedToFloat(uVar3,(byte)(in_fpscr >> 0x16) & 3);
  fVar5 = fVar5 + _DAT_20002624 * 0.016666668;
  uVar4 = in_fpscr & 0xfffffff;
  uVar1 = uVar4 | (uint)(fVar5 < 100.0) << 0x1f | (uint)(fVar5 == 100.0) << 0x1e;
  bVar2 = (byte)(uVar1 >> 0x18);
  if ((bool)(bVar2 >> 6 & 1) || (bool)(bVar2 >> 7) != NAN(fVar5)) {
    if (fVar5 < 2.0) {
      fVar5 = 2.0;
    }
  }
  else {
    fVar5 = 100.0;
    uVar4 = uVar1;
  }
  DAT_2000264e = (0.0 < fVar5) * (char)(int)fVar5;
  fVar5 = (float)VectorUnsignedToFloat(uVar3,(byte)(uVar4 >> 0x16) & 3);
  fVar5 = fVar5 - _DAT_20002624 * 0.016666668;
  uVar4 = uVar4 & 0xfffffff;
  uVar1 = uVar4 | (uint)(fVar5 < 100.0) << 0x1f | (uint)(fVar5 == 100.0) << 0x1e;
  bVar2 = (byte)(uVar1 >> 0x18);
  if ((bool)(bVar2 >> 6 & 1) || (bool)(bVar2 >> 7) != NAN(fVar5)) {
    if (fVar5 < 2.0) {
      fVar5 = 2.0;
    }
  }
  else {
    fVar5 = 100.0;
    uVar4 = uVar1;
  }
  DAT_2000264f = (0.0 < fVar5) * (char)(int)fVar5;
  if (DAT_20002651 == '\0') {
    fVar6 = (float)VectorUnsignedToFloat(uVar3,(byte)(uVar4 >> 0x16) & 3);
    uVar4 = uVar4 & 0xfffffff;
    if (fVar5 < fVar6) {
      DAT_20002651 = '\x01';
    }
  }
  if (DAT_20002651 != '\0') {
    DAT_20002650 = 1;
    fVar6 = (float)VectorUnsignedToFloat(uVar3,(byte)(uVar4 >> 0x16) & 3);
    if (fVar5 == fVar6) {
      _DAT_200006d6 = _DAT_200006d6 + 1;
      if (200 < _DAT_200006d6) {
        _DAT_200006d6 = 0;
        DAT_20002651 = '\0';
      }
    }
    else {
      _DAT_200006d6 = 0;
    }
  }
  return;
}

