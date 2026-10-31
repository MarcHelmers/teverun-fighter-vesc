// rea decompile_all
// name: FUN_0801b1fc
// address: 0x801b1fc
// body: available
// range: 0x801b1fc-0x801b5ab inclusive
// range: 0x801b64c-0x801b773 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0801b1fc(void)

{
  DAT_200025c0 = 1;
  DAT_200025c1 = 1;
  DAT_200025c2 = 1;
  DAT_200025c3 = 1;
  DAT_200025c4 = 1;
  DAT_200025c5 = 1;
  DAT_200025c6 = 1;
  DAT_200025c7 = 1;
  DAT_200025c8 = 1;
  DAT_200025c9 = 1;
  DAT_200025ca = 1;
  DAT_200025cb = 1;
  DAT_200025cc = 1;
  DAT_200025cd = 1;
  DAT_200025ce = 1;
  DAT_200025cf = 1;
  DAT_200025d0 = 1;
  DAT_200025d1 = 1;
  DAT_200025d3 = 1;
  DAT_200025d4 = 1;
  DAT_200025d5 = 1;
  FUN_08019e6c(0,0x300,0,8,100,0x200005c8,0,0x801b021,0);
  FUN_08019e6c(1,800,0,8,100,0x200005d0,0,0x801afd5,0);
  FUN_08019e6c(2,0x321,0,8,100,0x200005d8,0,0x801af89,0);
  FUN_08019e6c(3,0x310,0,8,100,0x200005e0,0,0x801af33,0);
  FUN_08019e6c(4,0x308,0,8,100,0x200005e8,0,0x801ae9b,0);
  FUN_08019e6c(5,0x309,0,8,100,0x200005f0,0,0x801ae03,0);
  FUN_08019e6c(6,0x30a,0,8,100,0x200005f8,0,0x801ad6b,0);
  FUN_08019e6c(7,0x30b,0,8,100,0x20000600,0,0x801acd3,0);
  FUN_08019e6c(8,0x30c,0,8,100,0x20000608,0,0x801ab65,0);
  FUN_08019e6c(9,0x328,0,8,100,0x20000610,0,0x801aaf7,0);
  FUN_08019e6c(10,0x329,0,8,100,0x20000618,0,0x801aaa5,0);
  FUN_08019e6c(0xb,0x32a,0,8,100,0x20000620,0,0x801aa49,0);
  FUN_08019e6c(0xc,0x32b,0,8,100,0x20000628,0,0x801a9a3,0);
  FUN_08019e6c(0xd,0x34f,0,8,100,0x20000630,0,0x801a92f,0);
  FUN_08019e6c(0xe,0x34e,0,8,100,&DAT_20000638,0,&LAB_0801a886_1,0);
  FUN_08019e6c(0xf,0x350,0,8,100,0x20000640,0,0x801a80d,0);
  FUN_08019e6c(0x10,0x351,0,8,100,0x20000648,0,0x801a687,0);
  FUN_08019e6c(0x11,0x540,0,8,100,&DAT_20000650,0,0x801a59b,0);
  FUN_08019e6c(0x13,0x710,0,8,100,&DAT_20000660,0,0x801a573,0);
  FUN_08019e6c(0x12,0x502,0,8,100,&DAT_20000658,0,0x801a517,0);
  FUN_08019e6c(0x14,0x6e0,0,8,100,&DAT_20000668,0,&LAB_0801a4be_1,0);
  FUN_08019e6c(0x15,0x680,0,8,100,&DAT_20000670,0,&LAB_0801a494_1,0);
  DAT_200025d6 = 1;
  DAT_200025d7 = 1;
  DAT_200025d8 = 1;
  DAT_200025d9 = 1;
  DAT_200025da = 1;
  DAT_200025db = 1;
  DAT_200025dc = 1;
  DAT_200025dd = 1;
  DAT_200025de = 1;
  DAT_200025df = 1;
  DAT_200025e0 = 1;
  DAT_200025e1 = 1;
  FUN_08019efc(0,0x3ee,0,8,0xfa,&DAT_20000568,1,&LAB_0801a3ec_1,0);
  FUN_08019efc(1,0x3ef,0,8,1000,&DAT_20000570,1,&LAB_0801a3ac_1,0);
  FUN_08019efc(2,0x380,0,8,100,0x20000578,1,0x801a249,0);
  FUN_08019efc(3,0x381,0,8,200,0x20000580,1,0x801a1e9,0);
  FUN_08019efc(4,900,0,8,100,0x20000588,1,0x801a187,0);
  FUN_08019efc(5,0x385,0,8,200,0x20000590,1,0x801a127,0);
  FUN_08019efc(6,0x390,0,8,200,0x20000598,1,0x801a0b5,0);
  FUN_08019efc(7,0x388,0,8,200,0x200005a0,1,&LAB_0801a08a_1,0);
  FUN_08019efc(8,0x389,0,8,200,0x200005a8,1,&LAB_0801a060_1,0);
  FUN_08019efc(9,0x4ed,0,8,1000,&DAT_200005b0,1,&LAB_0801a020_1,0);
  FUN_08019efc(10,0x4ee,0,8,1000,&DAT_200005b8,1,&LAB_08019fe0_1,0);
  FUN_08019efc(0xb,0x4ff,0,8,1000,&DAT_200005c0,1,&LAB_08019fb2_1,0);
  return;
}

