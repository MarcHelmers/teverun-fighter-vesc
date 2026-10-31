// rea decompile_all
// name: FUN_0002bf1c
// address: 0x2bf1c
// body: available
// range: 0x2bf1c-0x2c129 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined1 FUN_0002bf1c(byte param_1,int param_2,byte param_3,int param_4,int *param_5)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  uint local_24;
  byte local_1d;
  byte local_1b;
  byte local_1a;
  undefined1 local_19;
  
  local_19 = 0xfe;
  local_1a = 0;
  local_1b = 0;
  if (param_1 == 0xc) {
    local_1a = 0x77;
    local_1b = 0x30;
  }
  else if (param_1 == 0xe) {
    local_1a = 0x12;
    local_1b = 0x10;
  }
  FUN_0002bd34(2,local_1a | 0x80);
  FUN_0002bd00(4,0x80);
  FUN_0002bd34(1,0);
  FUN_0002bee8(10,0x80);
  for (local_24 = 0; local_24 < param_3; local_24 = local_24 + 1) {
    FUN_0002bd34(9,*(byte *)(param_2 + local_24));
  }
  FUN_0002bd34(1,param_1);
  if (param_1 == 0xc) {
    FUN_0002bee8(0xd,0x80);
  }
  local_24 = 2000;
  do {
    bVar2 = FUN_0002c1ec('\x04');
    local_24 = local_24 + -1;
    bVar1 = false;
    if ((local_24 != 0) && (bVar1 = false, (bVar2 & 1) == 0)) {
      bVar1 = (bVar2 & local_1b) == 0;
    }
  } while (bVar1);
  FUN_0002bd00(0xd,0x80);
  if (local_24 != 0) {
    bVar3 = FUN_0002c1ec('\x06');
    if ((bVar3 & 0x1b) == 0) {
      local_19 = 0;
      if ((bVar2 & local_1a & 1) != 0) {
        local_19 = 0xff;
      }
      if (param_1 == 0xc) {
        local_1d = FUN_0002c1ec('\n');
        bVar2 = FUN_0002c1ec('\f');
        if ((bVar2 & 7) == 0) {
          *param_5 = (uint)local_1d << 3;
        }
        else {
          *param_5 = (uint)(bVar2 & 7) + (uint)local_1d * 8 + -8;
        }
        if (local_1d == 0) {
          local_1d = 1;
        }
        if (0x12 < local_1d) {
          local_1d = 0x12;
        }
        for (local_24 = 0; local_24 < local_1d; local_24 = local_24 + 1) {
          bVar2 = FUN_0002c1ec('\t');
          *(byte *)(param_4 + local_24) = bVar2;
        }
      }
    }
    else {
      local_19 = 0xfe;
    }
  }
  FUN_0002bee8(0xc,0x80);
  FUN_0002bd34(1,0);
  return local_19;
}

