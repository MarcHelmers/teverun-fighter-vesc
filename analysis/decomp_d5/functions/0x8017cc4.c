// rea decompile_all
// name: FUN_08017cc4
// address: 0x8017cc4
// body: available
// range: 0x8017cc4-0x8017fc7 inclusive
// range: 0x8018048-0x801810f inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08017cc4(void)

{
  bool bVar1;
  bool bVar2;
  undefined1 auStack_1c [4];
  uint local_18;
  undefined1 auStack_10 [4];
  uint local_c;
  
  if (_DAT_200004e6 < _DAT_200002f8) {
    if (10 < _DAT_200002f8 - _DAT_200004e6) {
      _DAT_200004e6 = _DAT_200002f8;
      FUN_08016f86(0x88,0xc,auStack_10);
      FUN_08016f86(0x94,0xc,auStack_1c);
      if (local_18 < local_c) {
        _DAT_20001a58 = local_18 + 2;
        FUN_08017c5e();
      }
      else {
        _DAT_20001a4c = local_c + 2;
        FUN_08017c4c();
      }
    }
  }
  else if (_DAT_200004e6 == 0) {
    _DAT_200004e6 = _DAT_200002f8;
  }
  if (0x81 < DAT_2000029e) {
    DAT_2000029e = 0x82;
  }
  if (DAT_2000029e < 0x51) {
    DAT_2000029e = 0x50;
  }
  if (5 < DAT_200004e8) {
    bVar1 = (DAT_20001a10 & 0xee) == (DAT_2000029b & 0xee);
LAB_08017d68:
    if (bVar1) {
      bVar2 = (DAT_20001a11 & 0xee) == (DAT_2000029a & 0xee);
      while (bVar1 = false, bVar2) {
        bVar1 = DAT_20001a12 == DAT_2000029c;
        while( true ) {
          if (((((!bVar1) || (bVar1 = DAT_20001a13 == DAT_2000029d, !bVar1)) ||
               (bVar1 = DAT_20001a14 == DAT_2000029e, !bVar1)) ||
              (((bVar1 = DAT_20001a15 == DAT_200002b1, !bVar1 ||
                (bVar1 = DAT_20001a16 == DAT_200002be, !bVar1)) ||
               ((bVar1 = DAT_20001a17 == DAT_200002bf, !bVar1 ||
                ((bVar1 = (DAT_20001a18 & 0xfe) == (DAT_200002d2 & 0xfe), !bVar1 ||
                 (bVar1 = DAT_20001a3d == DAT_20000305, !bVar1)))))))) ||
             ((bVar1 = DAT_20001a3e == DAT_2000030a, !bVar1 ||
              ((((bVar1 = DAT_20001a19 == '\0', !bVar1 ||
                 (bVar1 = DAT_20001a1a == DAT_200002ab, !bVar1)) ||
                (bVar1 = DAT_20001a1c == DAT_200002a5, !bVar1)) ||
               ((bVar1 = DAT_20001a1b == DAT_2000029f, !bVar1 ||
                (bVar1 = DAT_20001a1e == DAT_200002b8, !bVar1)))))))) goto LAB_08017d68;
          bVar2 = DAT_20001a1d == DAT_200002b2;
          if ((!bVar2) || (bVar2 = DAT_20001a1f == '\x01', !bVar2)) break;
          bVar1 = false;
          if (DAT_20001a20 == DAT_200002ac) {
            if (((((DAT_20001a22 != DAT_200002a6) || (DAT_20001a21 != DAT_200002a0)) ||
                 (((DAT_20001a24 != DAT_200002b9 ||
                   (((DAT_20001a23 != DAT_200002b3 || (DAT_20001a25 != '\x02')) ||
                    (DAT_20001a26 != DAT_200002ad)))) ||
                  (((DAT_20001a28 != DAT_200002a7 || (DAT_20001a27 != DAT_200002a1)) ||
                   (DAT_20001a2a != DAT_200002ba)))))) ||
                ((DAT_20001a29 != DAT_200002b4 || (DAT_20001a2b != '\x03')))) ||
               (((DAT_20001a2c != DAT_200002ae ||
                 (((DAT_20001a2e != DAT_200002a8 || (DAT_20001a2d != DAT_200002a2)) ||
                  (DAT_20001a30 != DAT_200002bb)))) ||
                (((DAT_20001a2f != DAT_200002b5 || (DAT_20001a31 != '\x04')) ||
                 ((DAT_20001a32 != DAT_200002af ||
                  ((((DAT_20001a34 != DAT_200002a9 || (DAT_20001a33 != DAT_200002a3)) ||
                    ((DAT_20001a36 != DAT_200002bc ||
                     (((((DAT_20001a35 != DAT_200002b6 || (DAT_20001a37 != '\x05')) ||
                        (DAT_20001a38 != DAT_200002b0)) ||
                       ((DAT_20001a3a != DAT_200002aa || (DAT_20001a39 != DAT_200002a4)))) ||
                      (DAT_20001a3c != DAT_200002bd)))))) || (DAT_20001a3b != DAT_200002b7))))))))))
            goto LAB_08018088;
            goto LAB_0801808c;
          }
        }
      }
      goto LAB_08017d68;
    }
LAB_08018088:
    FUN_08017b1e();
LAB_0801808c:
    if (((DAT_20001a60 != DAT_20000317) || (DAT_20001a61 != DAT_20000318)) ||
       (((DAT_20001a62 != DAT_20000319 ||
         (((DAT_20001a63 != DAT_2000031a || (DAT_20001a64 != DAT_2000031b)) ||
          (_DAT_20001a66 != _DAT_20000320)))) ||
        (((DAT_20001a68 != DAT_20000322 || (DAT_20001a69 != DAT_20000323)) ||
         (DAT_20001a6a != DAT_20000324)))))) {
      FUN_08017c70();
    }
    DAT_200004e8 = 0;
  }
  DAT_200004e8 = DAT_200004e8 + 1;
  return;
}

