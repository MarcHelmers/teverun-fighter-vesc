// rea decompile_all
// name: FUN_00020fbe
// address: 0x20fbe
// body: available
// range: 0x20fbe-0x210cf inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00020fbe(short param_1,short param_2)

{
  short in_stack_00000008;
  short in_stack_0000000a;
  short in_stack_0000000c;
  short in_stack_0000000e;
  undefined2 *in_stack_00000018;
  
  FUN_0001e610(param_1,param_2 + -1,in_stack_0000000a + -1,param_2 + -1,*in_stack_00000018);
  FUN_0001e610(in_stack_0000000a + -1,in_stack_0000000c + 1,in_stack_0000000a + -1,
               in_stack_00000008 + -2,in_stack_00000018[1]);
  FUN_0001e610(in_stack_0000000e + 2,in_stack_0000000c + 2,in_stack_0000000a + -3,
               in_stack_0000000c + 2,in_stack_00000018[2]);
  FUN_0001e610(in_stack_0000000e + 2,in_stack_0000000c + 3,in_stack_0000000e + 2,
               in_stack_00000008 + -3,in_stack_00000018[3]);
  FUN_0001e610(in_stack_0000000e + 2,in_stack_00000008 + -2,in_stack_0000000a + -2,
               in_stack_00000008 + -2,in_stack_00000018[4]);
  FUN_0001e610(in_stack_0000000a + -2,in_stack_0000000c + 2,in_stack_0000000a + -2,
               in_stack_00000008 + -3,in_stack_00000018[5]);
  return;
}

