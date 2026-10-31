// rea decompile_all
// name: FUN_00024640
// address: 0x24640
// body: available
// range: 0x24640-0x247a7 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00024640(int param_1,byte *param_2)

{
  undefined4 local_38;
  undefined4 local_34;
  undefined2 local_30;
  undefined2 local_2e;
  undefined2 local_2c;
  undefined2 local_2a;
  undefined2 local_28;
  undefined2 local_26;
  undefined1 local_24;
  short local_22;
  short local_20;
  short local_1c;
  short local_1a;
  undefined4 *local_14;
  byte *local_10;
  int local_c;
  
  local_14 = *(undefined4 **)(param_2 + 0x1c);
  if ((int)((uint)*param_2 * 0x4000000) < 0) {
    local_10 = param_2;
    local_c = param_1;
    if ((int)((uint)*param_2 * 0x10000000) < 0) {
      if ((int)((uint)*param_2 * 0x2000000) < 0) {
        FUN_000227a4(param_1,&local_1c);
        *(short *)(local_10 + 8) = *(short *)(local_10 + 0x10) + local_1c;
        *(short *)(local_10 + 10) = *(short *)(local_10 + 0x12) + local_1a;
        *(short *)(local_10 + 0xc) = *(short *)(local_10 + 0x14) + local_1c;
        *(short *)(local_10 + 0xe) = *(short *)(local_10 + 0x16) + local_1a;
        if (*(short *)(local_c + 0x14) <= *(short *)(local_10 + 0xe)) {
          return;
        }
        if (*(short *)(local_c + 0x12) <= *(short *)(local_10 + 0xc)) {
          return;
        }
        FUN_000210d0(local_c,(int)local_10);
        local_26 = *(undefined2 *)(local_14 + 3);
        local_28 = *(undefined2 *)((int)local_14 + 10);
        FUN_0001e294(*(short *)(local_10 + 8),*(short *)(local_10 + 10),*(short *)(local_10 + 0xc),
                     *(short *)(local_10 + 0xe),local_26);
        local_30 = *(undefined2 *)(local_10 + 8);
        local_2e = *(undefined2 *)(local_10 + 10);
        local_2c = *(undefined2 *)(local_10 + 0xc);
        local_2a = *(undefined2 *)(local_10 + 0xe);
        local_24 = *(undefined1 *)((int)local_14 + 0xe);
        local_34 = local_14[1];
        local_22 = (short)*(char *)((int)local_14 + 0xf);
        local_20 = (short)*(char *)(local_14 + 4);
        local_38 = *local_14;
        FUN_0002049c(&local_38);
        *local_10 = *local_10 & 0xbf;
        FUN_00021104(local_c,(int)local_10);
      }
    }
    else {
      FUN_0001e294(*(short *)(param_2 + 8),*(short *)(param_2 + 10),*(short *)(param_2 + 0xc),
                   *(short *)(param_2 + 0xe),*(undefined2 *)(param_1 + 0xc));
    }
    *local_10 = *local_10 & 0xdf;
  }
  return;
}

