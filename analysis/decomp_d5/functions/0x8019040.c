// rea decompile_all
// name: FUN_08019040
// address: 0x8019040
// body: available
// range: 0x8019040-0x80191e5 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined8 FUN_08019040(uint param_1,int param_2)

{
  bool bVar1;
  uint unaff_r6;
  uint unaff_r7;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_2c;
  
  local_2c = 0;
  local_34 = 0;
  if ((((param_2 == 0) || (param_2 == 1)) || (param_2 == 2)) || (param_2 == 3)) {
    FUN_08007c68(1);
    bVar1 = FUN_08007c8a();
    if (!bVar1) {
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    local_38 = 1;
    if ((param_2 == 1) || (param_2 == 3)) {
      unaff_r7 = 1;
      unaff_r6 = 8000000;
      if (param_2 == 3) {
        local_2c = 2;
        unaff_r6 = 4000000;
      }
    }
    else if ((param_2 == 0) || (param_2 == 2)) {
      unaff_r7 = 0;
      unaff_r6 = 16000000;
      if (param_2 == 2) {
        local_2c = 2;
        unaff_r6 = 8000000;
      }
    }
  }
  else {
    local_38 = param_1;
    if (((param_2 == 4) || (param_2 == 5)) || ((param_2 == 6 || (param_2 == 7)))) {
      FUN_08007bb4(0x10000);
      bVar1 = FUN_08007c30();
      if (!bVar1) {
        do {
                    /* WARNING: Do nothing block with infinite loop */
        } while( true );
      }
      if ((param_2 == 5) || (param_2 == 7)) {
        unaff_r7 = 0x30000;
        unaff_r6 = 4000000;
        if (param_2 == 7) {
          local_2c = 2;
          unaff_r6 = 2000000;
        }
      }
      else if ((param_2 == 4) || (param_2 == 6)) {
        unaff_r7 = 0x10000;
        unaff_r6 = 8000000;
        if (param_2 == 6) {
          local_2c = 2;
          unaff_r6 = 4000000;
        }
      }
    }
  }
  if (param_1 < 0x337f981) {
    if (param_1 < 0x19bfcc1) {
      uVar3 = 0;
      iVar4 = 0;
    }
    else {
      uVar3 = 0x400;
      iVar4 = 0;
    }
  }
  else {
    uVar3 = 0x500;
    iVar4 = 0x400;
  }
  if (((param_1 == unaff_r6 * (param_1 / unaff_r6)) && (1 < param_1 / unaff_r6)) &&
     (param_1 / unaff_r6 < 0x21)) {
    uVar2 = param_1 / unaff_r6;
    if (uVar2 < 0x11) {
      uVar2 = (uVar2 - 2) * 0x40000;
    }
    else {
      uVar2 = (uVar2 - 0x11) * 0x40000 | 0x8000000;
    }
    bVar1 = FUN_08007bf8(99);
    if (!bVar1) {
      FUN_08007cdc(4,0x60);
      do {
        bVar1 = FUN_08007d14();
      } while (!bVar1);
      local_34 = 1;
    }
    FUN_08007da4(0);
    FUN_08009640(param_1 / 32000000);
    FUN_08007dc0(0);
    FUN_08007de4(iVar4);
    FUN_08007dd2(uVar3);
    FUN_08007d9e(0);
    FUN_08007d66(unaff_r7,uVar2,local_2c);
    FUN_08007d9e(1);
    do {
      bVar1 = FUN_08007bf8(0x39);
    } while (!bVar1);
    FUN_08007da4(3);
    do {
      uVar3 = FUN_08007db6();
    } while (uVar3 != 0xc);
    if (local_34 == 1) {
      FUN_08007cdc(0,0x60);
    }
    return CONCAT44(local_34,local_38);
  }
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

