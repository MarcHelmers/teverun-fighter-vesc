// rea decompile_all
// name: FUN_0001257c
// address: 0x1257c
// body: available
// range: 0x1257c-0x12817 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0001257c(int param_1,undefined4 param_2,int param_3,int param_4)

{
  *(undefined4 *)(param_1 + 0x20) = param_2;
  if (param_4 == 0) {
    *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) & 0xfffffffd;
  }
  else {
    *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) | 2;
  }
  *(undefined4 *)(param_1 + 0x14) = 2;
  if (param_3 == 0) {
    *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & 0xfffffffd;
  }
  else {
    *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 2;
  }
  if (param_1 == 0x40046800) {
    if (param_3 != 0) {
      FUN_00012268('\x02');
    }
  }
  else if (param_1 == 0x40046840) {
    if (param_3 != 0) {
      FUN_00012268('\x03');
    }
  }
  else if (param_1 == 0x40046880) {
    if (param_3 != 0) {
      FUN_00012268('\x14');
    }
  }
  else if (param_1 == 0x400468c0) {
    if (param_3 != 0) {
      FUN_00012268('\x16');
    }
  }
  else if (param_1 == 0x40046900) {
    if (param_3 != 0) {
      FUN_00012268('O');
    }
  }
  else if (param_1 == 0x40048800) {
    if (param_3 != 0) {
      FUN_00012268('\v');
    }
  }
  else if (param_1 == 0x40048840) {
    if (param_3 != 0) {
      FUN_00012268('\x1a');
    }
  }
  else if (param_1 == 0x40048880) {
    if (param_3 != 0) {
      FUN_00012268('\x1d');
    }
  }
  else if (param_1 == 0x400488c0) {
    if (param_3 != 0) {
      FUN_00012268('\x1f');
    }
  }
  else if (param_1 == 0x40048900) {
    if (param_3 != 0) {
      FUN_00012268('P');
    }
  }
  else if (param_1 == 0x40048940) {
    if (param_3 != 0) {
      FUN_00012268('Q');
    }
  }
  else if (param_1 == 0x40048980) {
    if (param_3 != 0) {
      FUN_00012268('R');
    }
  }
  else if (param_1 == 0x400489c0) {
    if (param_3 != 0) {
      FUN_00012268('S');
    }
  }
  else if (param_1 == 0x40048a00) {
    if (param_3 != 0) {
      FUN_00012268('T');
    }
  }
  else if (param_1 == 0x40048a40) {
    if (param_3 != 0) {
      FUN_00012268('U');
    }
  }
  else if (param_1 == 0x40048a80) {
    if (param_3 != 0) {
      FUN_00012268('V');
    }
  }
  else if ((param_1 == 0x40048ac0) && (param_3 != 0)) {
    FUN_00012268('W');
  }
  return;
}

