// rea decompile_all
// name: FUN_0002aa30
// address: 0x2aa30
// body: available
// range: 0x2aa30-0x2af75 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined1 FUN_0002aa30(void)

{
  undefined2 local_e;
  char local_b;
  byte local_a;
  char local_9;
  
  local_9 = 0;
  local_a = 0;
  local_b = 0;
  local_e = 0;
  DAT_20000c7f = 0;
  local_9 = FUN_0002a5c8(0x52,(undefined1 *)&local_e);
  if (local_9 == '\0') {
    local_9 = FUN_0002a63c(0x200009fc);
    if ((local_9 == '\0') && (local_9 = FUN_0002a6fc(0x200009fc), local_9 == '\0')) {
      local_b = '\x01';
      local_9 = FUN_0002a7a8(0x60,7,0x3e60f,0x200009fc);
      if ((local_9 == '\0') && (local_9 = FUN_0002af78(local_b << 2,0x20000c8a), local_9 == '\0')) {
        DAT_20000c7f = 1;
        FUN_0002b004(0x20000024,0x10);
        DAT_20000671 = 4;
        for (local_a = 0;
            (local_a < 0x10 && (*(char *)(local_a + 0x3e3fa) == *(char *)(local_a + 0x20000c8a)));
            local_a = local_a + 1) {
          if (local_a == 0xf) {
            DAT_20000671 = 1;
          }
        }
        for (local_a = 0; local_a < 0x10; local_a = local_a + 1) {
          if (*(char *)(local_a + 0x20000024) != *(char *)(local_a + 0x20000c8a)) {
            if (DAT_20000c99 == '3') {
              DAT_20000671 = 2;
            }
            break;
          }
          if (local_a == 0xf) {
            DAT_20000671 = 3;
          }
        }
        for (local_a = 0;
            (local_a < 0x10 && (*(char *)(local_a + 0x3e842) == *(char *)(local_a + 0x20000c8a)));
            local_a = local_a + 1) {
          if (local_a == 0xf) {
            DAT_20000671 = 6;
          }
        }
        for (local_a = 0;
            (local_a < 0x10 && (*(char *)(local_a + 0x3e704) == *(char *)(local_a + 0x20000c8a)));
            local_a = local_a + 1) {
          if ((local_a == 0xf) && (DAT_20000671 = 5, DAT_20000a00 != '\0')) {
            local_9 = FUN_0002a868(local_b << 2,0x3e724);
            FUN_0002b048();
          }
        }
        for (local_a = 0;
            (local_a < 0x10 && (*(char *)(local_a + 0x3e724) == *(char *)(local_a + 0x20000c8a)));
            local_a = local_a + 1) {
          if ((local_a == 0xf) && (DAT_20000671 = 5, DAT_20000a00 != '\0')) {
            local_9 = FUN_0002a868(local_b << 2,0x3e714);
            FUN_0002b048();
          }
        }
        for (local_a = 0;
            (local_a < 0x10 && (*(char *)(local_a + 0x3e714) == *(char *)(local_a + 0x20000c8a)));
            local_a = local_a + 1) {
          if ((local_a == 0xf) && (DAT_20000671 = 5, DAT_20000a00 != '\0')) {
            local_9 = FUN_0002a868(local_b << 2,0x3e6f4);
            FUN_0002b048();
          }
        }
        for (local_a = 0;
            (local_a < 0x10 && (*(char *)(local_a + 0x3e734) == *(char *)(local_a + 0x20000c8a)));
            local_a = local_a + 1) {
          if (local_a == 0xf) {
            DAT_20000671 = 7;
          }
        }
        for (local_a = 0;
            (local_a < 0x10 && (*(char *)(local_a + 0x3e822) == *(char *)(local_a + 0x20000c8a)));
            local_a = local_a + 1) {
          if (local_a == 0xf) {
            DAT_20000671 = 8;
          }
        }
        for (local_a = 0;
            (local_a < 0x10 && (*(char *)(local_a + 0x3e6f4) == *(char *)(local_a + 0x20000c8a)));
            local_a = local_a + 1) {
          if (local_a == 0xf) {
            DAT_20000671 = 9;
          }
        }
        for (local_a = 0;
            (local_a < 0x10 && (*(char *)(local_a + 0x3e832) == *(char *)(local_a + 0x20000c8a)));
            local_a = local_a + 1) {
          if (local_a == 0xf) {
            DAT_20000671 = 10;
          }
        }
      }
    }
  }
  else {
    DAT_20000671 = 0;
  }
  return DAT_20000671;
}

