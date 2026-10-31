// rea decompile_all
// name: FUN_000191c0
// address: 0x191c0
// body: available
// range: 0x191c0-0x193a5 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_000191c0(void)

{
  short sVar1;
  byte local_9;
  
  if (DAT_2000053f != DAT_2000053e) {
    DAT_2000053f = DAT_2000053e;
    FUN_00013acc(5);
    FUN_0001e260(0);
    DAT_2000053c = 0;
    DAT_20000538 = 0x30;
    DAT_20000539 = 0x30;
    DAT_2000053a = 0x30;
    DAT_2000053b = 0x30;
    FUN_0001e260(0);
    FUN_0001e294(3,0,0x165,0x3e,0x18ce);
    FUN_00020e9c(3,0,0x165,0x3e,(undefined2 *)0x56b94);
    FUN_0001e1ec((undefined4 *)0x3e6b8);
    FUN_0002040c(0xffe0);
    FUN_00020428(0x18ce);
    FUN_0001f1e8(0x30,0xf,(byte *)0x56d60);
  }
  FUN_0001e1ec((undefined4 *)0x3e6cc);
  for (local_9 = 0; local_9 < 4; local_9 = local_9 + 1) {
    sVar1 = (ushort)local_9 * 0x46;
    FUN_00020e9c(sVar1 + 0x28,0x10e,(ushort)local_9 * 0x46 + 0x6e,0x172,(undefined2 *)0x56b94);
    if (DAT_2000053c == local_9) {
      FUN_0001f33c((&DAT_20000538)[local_9],sVar1 + 0x2f,0x118,0,0xffff);
    }
    else {
      FUN_0001f33c((&DAT_20000538)[local_9],sVar1 + 0x2f,0x118,0xffff,0);
    }
  }
  if (DAT_20000101 != '\0') {
    DAT_2000053e = '\n';
  }
  return;
}

