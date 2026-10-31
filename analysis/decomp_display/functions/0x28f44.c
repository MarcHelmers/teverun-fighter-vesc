// rea decompile_all
// name: FUN_00028f44
// address: 0x28f44
// body: available
// range: 0x28f44-0x29f33 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 2068bb4c5374392aa3dcb38f17244e2fffe75b2b231c9707e7b2810034d9bb45
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Windows Ghidra P0 accepts native x86, x86-64, ARMNT (Thumb-2) and ARM64 PE applications and DLLs, and explicitly selected raw 6502 images; managed, hostile, sensitive, and mutable-path targets are unsupported.; The Windows bridge uses authenticated IPv4 loopback because Node path-based IPC does not expose Java AF_UNIX sockets; the endpoint file contains no bearer token.; Windows sessions require the matching packaged Windows x64 native addon, local NTFS targets and runtimes, and Windows 10 or later. Native handles enforce path admission, private DACLs, and Job Object ownership automatically.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00028f44(char param_1)

{
  if (10 < DAT_20000bd6) {
    DAT_20000bd6 = 10;
  }
  if (param_1 == '\0') {
    if (9 < DAT_200005c1) {
      if ((((DAT_200005f9 != DAT_2000057b) || (DAT_200005f8 != DAT_200005ac)) ||
          (DAT_20000605 != DAT_20000bf2)) ||
         (((((DAT_200005fa != DAT_20000579 || (DAT_200005fc != DAT_20000c25)) ||
            ((DAT_200005fd != DAT_20000bdb ||
             ((DAT_200005fe != DAT_20000bd9 || (DAT_200005ff != DAT_20000bd8)))))) ||
           ((DAT_20000600 != DAT_20000bd5 ||
            (((((DAT_20000601 != DAT_20000bcc || (DAT_20000602 != DAT_20000bd3)) ||
               (DAT_20000603 != DAT_20000bd6)) ||
              ((DAT_20000604 != DAT_20000bd7 || (DAT_2000061a != DAT_20000be5)))) ||
             ((DAT_20000619 != DAT_20000bdf ||
              ((DAT_20000618 != DAT_20000bf3 || (DAT_2000061c != DAT_20000c05)))))))))) ||
          ((DAT_2000061b != DAT_20000bff ||
           (((((DAT_2000061d != DAT_20000beb || (DAT_20000620 != DAT_20000be6)) ||
              (DAT_2000061f != DAT_20000be0)) ||
             (((DAT_2000061e != DAT_20000bf4 || (DAT_20000622 != DAT_20000c06)) ||
              ((DAT_20000621 != DAT_20000c00 ||
               ((DAT_20000623 != DAT_20000bec || (DAT_20000626 != DAT_20000be7)))))))) ||
            (((DAT_20000625 != DAT_20000be1 ||
              (((((DAT_20000624 != DAT_20000bf5 || (DAT_20000628 != DAT_20000c07)) ||
                 (DAT_20000627 != DAT_20000c01)) ||
                (((DAT_20000629 != DAT_20000bed || (DAT_2000062c != DAT_20000be8)) ||
                 ((DAT_2000062b != DAT_20000be2 ||
                  ((DAT_2000062a != DAT_20000bf6 || (DAT_2000062e != DAT_20000c08)))))))) ||
               (DAT_2000062d != DAT_20000c02)))) ||
             (((((((DAT_2000062f != DAT_20000bee || (DAT_20000632 != DAT_20000be9)) ||
                  (DAT_20000631 != DAT_20000be3)) ||
                 ((DAT_20000630 != DAT_20000bf7 || (DAT_20000634 != DAT_20000c09)))) ||
                (DAT_20000633 != DAT_20000c03)) ||
               ((DAT_20000635 != DAT_20000bef || (DAT_20000638 != DAT_20000bea)))) ||
              (((DAT_20000637 != DAT_20000be4 ||
                (((DAT_20000636 != DAT_20000bf8 || (DAT_2000063a != DAT_20000c0a)) ||
                 (DAT_20000639 != DAT_20000c04)))) || (DAT_2000063b != DAT_20000bf0)))))))))))))) {
        FUN_000288e8();
      }
      if (((DAT_200005eb != DAT_2000058c) || (DAT_200005ec != DAT_2000058d)) ||
         ((DAT_200005ed != DAT_2000058e || (DAT_200005ee != DAT_2000058f)))) {
        FUN_000287e4();
      }
      if (((DAT_20000658 != DAT_2000057c) || (DAT_20000659 != DAT_2000057d)) ||
         ((((DAT_2000065a != DAT_2000057e ||
            (((DAT_2000065b != DAT_2000057f || (DAT_2000065c != DAT_20000580)) ||
             (DAT_2000065d != DAT_20000581)))) ||
           ((((DAT_2000065e != DAT_20000582 || (DAT_2000065f != DAT_20000583)) ||
             (DAT_20000660 != DAT_20000584)) ||
            ((DAT_20000661 != DAT_20000585 || (DAT_20000662 != DAT_20000586)))))) ||
          ((DAT_20000663 != DAT_20000587 ||
           ((((DAT_20000664 != DAT_20000588 || (DAT_20000665 != DAT_20000589)) ||
             (DAT_20000666 != DAT_2000058a)) || (DAT_20000667 != DAT_2000058b)))))))) {
        FUN_000289ec();
      }
      DAT_200005c1 = 0;
    }
    DAT_200005c1 = DAT_200005c1 + 1;
  }
  else {
    if (((((DAT_200005f9 != DAT_2000057b) || (DAT_200005f8 != DAT_200005ac)) ||
         (((DAT_20000605 != DAT_20000bf2 ||
           ((DAT_200005fa != DAT_20000579 || (DAT_200005fc != DAT_20000c25)))) ||
          (DAT_200005fd != DAT_20000bdb)))) ||
        ((((DAT_200005fe != DAT_20000bd9 || (DAT_200005ff != DAT_20000bd8)) ||
          (DAT_20000600 != DAT_20000bd5)) ||
         ((((((DAT_20000601 != DAT_20000bcc || (DAT_20000602 != DAT_20000bd3)) ||
             ((DAT_20000603 != DAT_20000bd6 ||
              ((DAT_20000604 != DAT_20000bd7 || (DAT_2000061a != DAT_20000be5)))))) ||
            ((DAT_20000619 != DAT_20000bdf ||
             ((((DAT_20000618 != DAT_20000bf3 || (DAT_2000061c != DAT_20000c05)) ||
               (DAT_2000061b != DAT_20000bff)) ||
              ((DAT_2000061d != DAT_20000beb || (DAT_20000620 != DAT_20000be6)))))))) ||
           (((DAT_2000061f != DAT_20000be0 ||
             ((DAT_2000061e != DAT_20000bf4 || (DAT_20000622 != DAT_20000c06)))) ||
            (DAT_20000621 != DAT_20000c00)))) ||
          ((((DAT_20000623 != DAT_20000bec || (DAT_20000626 != DAT_20000be7)) ||
            (DAT_20000625 != DAT_20000be1)) ||
           ((DAT_20000624 != DAT_20000bf5 || (DAT_20000628 != DAT_20000c07)))))))))) ||
       (((((DAT_20000627 != DAT_20000c01 ||
           ((DAT_20000629 != DAT_20000bed || (DAT_2000062c != DAT_20000be8)))) ||
          ((DAT_2000062b != DAT_20000be2 ||
           (((DAT_2000062a != DAT_20000bf6 || (DAT_2000062e != DAT_20000c08)) ||
            (DAT_2000062d != DAT_20000c02)))))) ||
         ((((DAT_2000062f != DAT_20000bee || (DAT_20000632 != DAT_20000be9)) ||
           ((DAT_20000631 != DAT_20000be3 ||
            ((DAT_20000630 != DAT_20000bf7 || (DAT_20000634 != DAT_20000c09)))))) ||
          ((DAT_20000633 != DAT_20000c03 ||
           ((((DAT_20000635 != DAT_20000bef || (DAT_20000638 != DAT_20000bea)) ||
             (DAT_20000637 != DAT_20000be4)) ||
            ((DAT_20000636 != DAT_20000bf8 || (DAT_2000063a != DAT_20000c0a)))))))))) ||
        ((DAT_20000639 != DAT_20000c04 || (DAT_2000063b != DAT_20000bf0)))))) {
      FUN_000288e8();
    }
    if (((DAT_200005eb != DAT_2000058c) || (DAT_200005ec != DAT_2000058d)) ||
       ((DAT_200005ed != DAT_2000058e || (DAT_200005ee != DAT_2000058f)))) {
      FUN_000287e4();
    }
    if ((((((DAT_20000658 != DAT_2000057c) || (DAT_20000659 != DAT_2000057d)) ||
          (DAT_2000065a != DAT_2000057e)) ||
         ((DAT_2000065b != DAT_2000057f || (DAT_2000065c != DAT_20000580)))) ||
        (DAT_2000065d != DAT_20000581)) ||
       (((DAT_2000065e != DAT_20000582 || (DAT_2000065f != DAT_20000583)) ||
        ((((DAT_20000660 != DAT_20000584 ||
           (((DAT_20000661 != DAT_20000585 || (DAT_20000662 != DAT_20000586)) ||
            (DAT_20000663 != DAT_20000587)))) ||
          (((DAT_20000664 != DAT_20000588 || (DAT_20000665 != DAT_20000589)) ||
           (DAT_20000666 != DAT_2000058a)))) || (DAT_20000667 != DAT_2000058b)))))) {
      FUN_000289ec();
    }
    DAT_200005c1 = '\0';
  }
  return;
}

