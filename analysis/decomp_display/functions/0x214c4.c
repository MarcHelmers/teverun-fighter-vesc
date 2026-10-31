// rea decompile_all
// name: FUN_000214c4
// address: 0x214c4
// body: available
// range: 0x214c4-0x21523 inclusive
// range: 0x2152c-0x21533 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_000214c4(short param_1,short param_2)

{
  short sVar1;
  short in_stack_00000006;
  short in_stack_00000008;
  short in_stack_0000000a;
  short sStack0000001a;
  undefined1 uStack00000020;
  short sStack00000022;
  short sStack00000024;
  int in_stack_00000028;
  
  sStack0000001a = param_1 + param_2 + -1;
  uStack00000020 = *(undefined1 *)(in_stack_00000028 + 0x22);
  sStack00000022 = (short)*(char *)(in_stack_00000028 + 0x20);
  sStack00000024 = (short)*(char *)(in_stack_00000028 + 0x21);
  FUN_0002049c((undefined4 *)&stack0x0000000c);
  sVar1 = in_stack_00000008 + (ushort)*(byte *)(in_stack_00000028 + 0x2c);
  FUN_0001e610(in_stack_0000000a,sVar1,in_stack_00000006,sVar1,_DAT_00056b92);
  return 0;
}

