// rea decompile_all
// name: FUN_08017e08
// address: 0x8017e08
// body: available
// range: 0x8017e08-0x801810b inclusive
// range: 0x801818c-0x8018253 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08017e08(void)

{
  bool bVar1;
  bool bVar2;
  undefined1 auStack_1c [4];
  uint local_18;
  undefined1 auStack_10 [4];
  uint local_c;
  
  if (_DAT_200004fe < _DAT_200002f8) {
    if (10 < _DAT_200002f8 - _DAT_200004fe) {
      _DAT_200004fe = _DAT_200002f8;
      FUN_080170ca(0x88,0xc,auStack_10);
      FUN_080170ca(0x94,0xc,auStack_1c);
      if (local_18 < local_c) {
        _DAT_20001a70 = local_18 + 2;
        FUN_08017da2();
      }
      else {
        _DAT_20001a64 = local_c + 2;
        FUN_08017d90();
      }
    }
  }
  else if (_DAT_200004fe == 0) {
    _DAT_200004fe = _DAT_200002f8;
  }
  if (0x81 < DAT_2000029e) {
    DAT_2000029e = 0x82;
  }
  if (DAT_2000029e < 0x51) {
    DAT_2000029e = 0x50;
  }
  if (5 < DAT_20000500) {
    bVar1 = (DAT_20001a28 & 0xee) == (DAT_2000029b & 0xee);
LAB_08017eac:
    if (bVar1) {
      bVar2 = (DAT_20001a29 & 0xee) == (DAT_2000029a & 0xee);
      while (bVar1 = false, bVar2) {
        bVar1 = DAT_20001a2a == DAT_2000029c;
        while( true ) {
          if (((((!bVar1) || (bVar1 = DAT_20001a2b == DAT_2000029d, !bVar1)) ||
               (bVar1 = DAT_20001a2c == DAT_2000029e, !bVar1)) ||
              (((bVar1 = DAT_20001a2d == DAT_200002b1, !bVar1 ||
                (bVar1 = DAT_20001a2e == DAT_200002be, !bVar1)) ||
               ((bVar1 = DAT_20001a2f == DAT_200002bf, !bVar1 ||
                ((bVar1 = (DAT_20001a30 & 0xfe) == (DAT_200002d2 & 0xfe), !bVar1 ||
                 (bVar1 = DAT_20001a55 == DAT_20000305, !bVar1)))))))) ||
             ((bVar1 = DAT_20001a56 == DAT_2000030a, !bVar1 ||
              ((((bVar1 = DAT_20001a31 == '\0', !bVar1 ||
                 (bVar1 = DAT_20001a32 == DAT_200002ab, !bVar1)) ||
                (bVar1 = DAT_20001a34 == DAT_200002a5, !bVar1)) ||
               ((bVar1 = DAT_20001a33 == DAT_2000029f, !bVar1 ||
                (bVar1 = DAT_20001a36 == DAT_200002b8, !bVar1)))))))) goto LAB_08017eac;
          bVar2 = DAT_20001a35 == DAT_200002b2;
          if ((!bVar2) || (bVar2 = DAT_20001a37 == '\x01', !bVar2)) break;
          bVar1 = false;
          if (DAT_20001a38 == DAT_200002ac) {
            if (((((DAT_20001a3a != DAT_200002a6) || (DAT_20001a39 != DAT_200002a0)) ||
                 (((DAT_20001a3c != DAT_200002b9 ||
                   (((DAT_20001a3b != DAT_200002b3 || (DAT_20001a3d != '\x02')) ||
                    (DAT_20001a3e != DAT_200002ad)))) ||
                  (((DAT_20001a40 != DAT_200002a7 || (DAT_20001a3f != DAT_200002a1)) ||
                   (DAT_20001a42 != DAT_200002ba)))))) ||
                ((DAT_20001a41 != DAT_200002b4 || (DAT_20001a43 != '\x03')))) ||
               (((DAT_20001a44 != DAT_200002ae ||
                 (((DAT_20001a46 != DAT_200002a8 || (DAT_20001a45 != DAT_200002a2)) ||
                  (DAT_20001a48 != DAT_200002bb)))) ||
                (((DAT_20001a47 != DAT_200002b5 || (DAT_20001a49 != '\x04')) ||
                 ((DAT_20001a4a != DAT_200002af ||
                  ((((DAT_20001a4c != DAT_200002a9 || (DAT_20001a4b != DAT_200002a3)) ||
                    ((DAT_20001a4e != DAT_200002bc ||
                     (((((DAT_20001a4d != DAT_200002b6 || (DAT_20001a4f != '\x05')) ||
                        (DAT_20001a50 != DAT_200002b0)) ||
                       ((DAT_20001a52 != DAT_200002aa || (DAT_20001a51 != DAT_200002a4)))) ||
                      (DAT_20001a54 != DAT_200002bd)))))) || (DAT_20001a53 != DAT_200002b7))))))))))
            goto LAB_080181cc;
            goto LAB_080181d0;
          }
        }
      }
      goto LAB_08017eac;
    }
LAB_080181cc:
    FUN_08017c62();
LAB_080181d0:
    if (((DAT_20001a78 != DAT_20000317) || (DAT_20001a79 != DAT_20000318)) ||
       (((DAT_20001a7a != DAT_20000319 ||
         (((DAT_20001a7b != DAT_2000031a || (DAT_20001a7c != DAT_2000031b)) ||
          (_DAT_20001a7e != _DAT_20000320)))) ||
        (((DAT_20001a80 != DAT_20000322 || (DAT_20001a81 != DAT_20000323)) ||
         (DAT_20001a82 != DAT_20000324)))))) {
      FUN_08017db4();
    }
    DAT_20000500 = 0;
  }
  DAT_20000500 = DAT_20000500 + 1;
  return;
}

