// rea decompile_all
// name: FUN_00011cdc
// address: 0x11cdc
// body: available
// range: 0x11cdc-0x11ff5 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00011cdc(int *param_1,uint param_2,ushort param_3,int param_4,int param_5)

{
  if ((((param_1 == (int *)0x40046800) || (param_1 == (int *)0x40046840)) ||
      (param_1 == (int *)0x40046880)) ||
     ((param_1 == (int *)0x400468c0 || (param_1 == (int *)0x40046900)))) {
    _DAT_40000008 = _DAT_40000008 | 0x800;
  }
  else {
    _DAT_4000000c = _DAT_4000000c | 0x400000;
  }
  FUN_00011ff8((int)param_1);
  param_1[2] = param_1[2] & 0xfffffff0;
  param_1[2] = param_1[2] | param_2;
  param_1[0xc] = param_3 - 1;
  *param_1 = param_4 + -1;
  param_1[5] = 1;
  if (param_5 == 0) {
    param_1[4] = param_1[4] & 0xfffffffe;
  }
  else {
    param_1[4] = param_1[4] | 1;
  }
  if (param_1 == (int *)0x40046800) {
    if (param_5 != 0) {
      FUN_00012268('\x02');
    }
  }
  else if (param_1 == (int *)0x40046840) {
    if (param_5 != 0) {
      FUN_00012268('\x03');
    }
  }
  else if (param_1 == (int *)0x40046880) {
    if (param_5 != 0) {
      FUN_00012268('\x14');
    }
  }
  else if (param_1 == (int *)0x400468c0) {
    if (param_5 != 0) {
      FUN_00012268('\x16');
    }
  }
  else if (param_1 == (int *)0x40046900) {
    if (param_5 != 0) {
      FUN_00012268('O');
    }
  }
  else if (param_1 == (int *)0x40048800) {
    if (param_5 != 0) {
      FUN_00012268('\v');
    }
  }
  else if (param_1 == (int *)0x40048840) {
    if (param_5 != 0) {
      FUN_00012268('\x1a');
    }
  }
  else if (param_1 == (int *)0x40048880) {
    if (param_5 != 0) {
      FUN_00012268('\x1d');
    }
  }
  else if (param_1 == (int *)0x400488c0) {
    if (param_5 != 0) {
      FUN_00012268('\x1f');
    }
  }
  else if (param_1 == (int *)0x40048900) {
    if (param_5 != 0) {
      FUN_00012268('P');
    }
  }
  else if (param_1 == (int *)0x40048940) {
    if (param_5 != 0) {
      FUN_00012268('Q');
    }
  }
  else if (param_1 == (int *)0x40048980) {
    if (param_5 != 0) {
      FUN_00012268('R');
    }
  }
  else if (param_1 == (int *)0x400489c0) {
    if (param_5 != 0) {
      FUN_00012268('S');
    }
  }
  else if (param_1 == (int *)0x40048a00) {
    if (param_5 != 0) {
      FUN_00012268('T');
    }
  }
  else if (param_1 == (int *)0x40048a40) {
    if (param_5 != 0) {
      FUN_00012268('U');
    }
  }
  else if (param_1 == (int *)0x40048a80) {
    if (param_5 != 0) {
      FUN_00012268('V');
    }
  }
  else if ((param_1 == (int *)0x40048ac0) && (param_5 != 0)) {
    FUN_00012268('W');
  }
  return;
}

