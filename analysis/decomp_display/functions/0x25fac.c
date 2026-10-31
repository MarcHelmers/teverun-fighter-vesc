// rea decompile_all
// name: FUN_00025fac
// address: 0x25fac
// body: available
// range: 0x25fac-0x262f7 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00025fac(void)

{
  bool bVar1;
  char cVar2;
  char local_48;
  char local_47;
  char local_46;
  undefined1 local_45;
  undefined1 local_44;
  undefined1 local_43;
  undefined1 local_42;
  undefined1 local_41;
  undefined1 local_40;
  undefined1 local_3f;
  undefined1 local_3e;
  undefined1 local_3d;
  undefined1 local_3c;
  undefined1 local_3b;
  undefined1 local_3a;
  undefined1 local_39;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  undefined1 local_32;
  undefined1 local_31;
  undefined1 local_30;
  undefined1 local_2f;
  undefined1 local_2e;
  undefined1 local_2d;
  undefined1 local_2c;
  undefined1 local_2b;
  undefined1 local_2a;
  undefined1 local_29;
  undefined1 local_28;
  undefined1 local_27;
  undefined1 local_26;
  undefined1 local_25;
  undefined1 local_24;
  undefined1 local_23;
  byte local_15;
  undefined1 local_12;
  undefined1 local_11;
  undefined4 local_10;
  
  local_10 = 0;
  local_11 = 0;
  local_12 = 0;
  bVar1 = FUN_00025ca4(0x200006ca,(undefined4 *)&local_48);
  if (bVar1) {
    if (_DAT_20000bb2 < 5000) {
      _DAT_20000bb2 = _DAT_20000bb2 + 1;
    }
    else {
      _DAT_20000bb2 = 5000;
    }
  }
  else {
    if ((local_48 == '5') && (local_12 = FUN_000262f8((int)&local_48,0x26,local_15), (bool)local_12)
       ) {
      DAT_20000ba4 = 0;
      _DAT_20000bb2 = 0;
      bVar1 = local_46 != ':';
      if (bVar1) {
        DAT_20000bac = 1;
      }
      else {
        DAT_20000bad = 1;
      }
      (&DAT_20000c26)[(uint)bVar1 * 0x23] = local_45;
      (&DAT_20000c27)[(short)(ushort)bVar1 * 0x23] = local_44;
      (&DAT_20000c28)[(short)(ushort)bVar1 * 0x23] = local_43;
      (&DAT_20000c29)[(short)(ushort)bVar1 * 0x23] = local_42;
      (&DAT_20000c2a)[(short)(ushort)bVar1 * 0x23] = local_41;
      (&DAT_20000c2b)[(short)(ushort)bVar1 * 0x23] = local_40;
      (&DAT_20000c2c)[(short)(ushort)bVar1 * 0x23] = local_3f;
      (&DAT_20000c2d)[(short)(ushort)bVar1 * 0x23] = local_3e;
      (&DAT_20000c2e)[(short)(ushort)bVar1 * 0x23] = local_3d;
      (&DAT_20000c2f)[(short)(ushort)bVar1 * 0x23] = local_3c;
      (&DAT_20000c30)[(short)(ushort)bVar1 * 0x23] = local_3b;
      (&DAT_20000c31)[(short)(ushort)bVar1 * 0x23] = local_3a;
      (&DAT_20000c32)[(short)(ushort)bVar1 * 0x23] = local_39;
      (&DAT_20000c33)[(short)(ushort)bVar1 * 0x23] = local_38;
      (&DAT_20000c34)[(short)(ushort)bVar1 * 0x23] = local_37;
      (&DAT_20000c35)[(short)(ushort)bVar1 * 0x23] = local_36;
      (&DAT_20000c36)[(short)(ushort)bVar1 * 0x23] = local_35;
      (&DAT_20000c37)[(short)(ushort)bVar1 * 0x23] = local_34;
      (&DAT_20000c38)[(short)(ushort)bVar1 * 0x23] = local_33;
      (&DAT_20000c39)[(short)(ushort)bVar1 * 0x23] = local_32;
      (&DAT_20000c3a)[(short)(ushort)bVar1 * 0x23] = local_31;
      (&DAT_20000c3b)[(short)(ushort)bVar1 * 0x23] = local_30;
      (&DAT_20000c3c)[(short)(ushort)bVar1 * 0x23] = local_2f;
      (&DAT_20000c3d)[(short)(ushort)bVar1 * 0x23] = local_2e;
      (&DAT_20000c3e)[(short)(ushort)bVar1 * 0x23] = local_2d;
      (&DAT_20000c3f)[(short)(ushort)bVar1 * 0x23] = local_2c;
      (&DAT_20000c40)[(short)(ushort)bVar1 * 0x23] = local_2b;
      (&DAT_20000c41)[(short)(ushort)bVar1 * 0x23] = local_2a;
      (&DAT_20000c42)[(short)(ushort)bVar1 * 0x23] = local_29;
      (&DAT_20000c43)[(short)(ushort)bVar1 * 0x23] = local_28;
      (&DAT_20000c44)[(short)(ushort)bVar1 * 0x23] = local_27;
      (&DAT_20000c45)[(short)(ushort)bVar1 * 0x23] = local_26;
      (&DAT_20000c46)[(short)(ushort)bVar1 * 0x23] = local_25;
      (&DAT_20000c47)[(short)(ushort)bVar1 * 0x23] = local_24;
      (&DAT_20000c48)[(short)(ushort)bVar1 * 0x23] = local_23;
    }
    cVar2 = FUN_000137f4();
    if (((cVar2 == '\n') && (local_48 == -0x56)) && (local_47 == 'U')) {
      DAT_20000bc9 = local_46;
      DAT_20000bc8 = local_45;
    }
    DAT_20000a53 = 0;
  }
  if (600 < _DAT_20000bb2) {
    DAT_20000ba4 = 1;
  }
  return;
}

