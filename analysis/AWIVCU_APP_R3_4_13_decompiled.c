/* =====================================================================
 *  IVCU-Firmware AWIVCU_APP_R3_4_13  -  dekcompilierte, kommentierte Quelle
 *  ---------------------------------------------------------------------
 *  Ziel      : Teverun Fighter Mini/Pro/ECO, IVCU 'Box C' (HW V5.x)
 *  Quelle    : Intel-HEX 'AWIVCU_APP_R3_4_13.hex'
 *  SHA-256   : 613ee4166800c02039a247ed7c39c320b14d9442202cb9ac79c1c609bc5b1318
 *  Werkzeuge : REA + Ghidra 12.1.4 (headless), eigene HEX/Binary-Tools
 *  Code-Basis: 0x08007000 (Thumb-2, Cortex-M4F/GD32F303-Klasse, STM32F1-artige Peripherie)
 *  Funktionen: 671  ·  Funktionsbytes: 77826 von 93627 = 83.1%
 *  Restbytes : 21988 in 155 Regionen (Daten/Pools/Fragmente, siehe Anhang)
 *  ---------------------------------------------------------------------
 *  WICHTIG: Dieser Text ist Dekompilat (Pseudocode), KEIN Original-Quelltext.
 *  Typen wie undefined1/uint sind Ghidra-Artefakte; DAT_xxxxxxxx = RAM/ROM-
 *  Adresse 0xXXXXXXXX. Nicht ohne Anpassung kompilierbar. Adressen/Bytes
 *  entstammen der statischen Analyse; keine Laufzeitbeobachtung.
 * ===================================================================== */

#include <stdint.h>

/* --- Ghidra-Ersatztypen --- */
typedef unsigned char  undefined1;
typedef unsigned short undefined2;
typedef unsigned int   undefined4;
typedef unsigned long long undefined8;
typedef uint8_t byte;
typedef uint16_t ushort;
typedef uint32_t uint;
typedef uint8_t uchar;
typedef uint8_t code;

/* =====================================================================
 *  GLOSSAR: Speicherkarte & wichtige Adressen
 * =====================================================================
 * PERIPHERIE (STM32F1-Klasse):
 *   0x40000000 TIM2 (Zeitbasis)      0x40005400 I2C1 (EEPROM)
 *   0x40004400 USART2 (ESC, 9600)    0x40004800 USART3 (Display, 9600)
 *   0x40006400 CAN1 (+0x6600 Filter) 0x40013800 USART1 (BLE, 115200)
 *   0x40010004 AFIO  0x40010800..0x40011400 GPIOA..D  0x40020000 DMA1
 *   0x40021000 RCC   0x40022000 FLASH 0xE000E000 NVIC/SCB
 *
 * RAM (wichtigste Objekte):
 *   0x2000070C BLE-RX-Framepuffer (0xAA, 20B)   0x20000720 ESC-RX (0x71, 12B)
 *   0x2000072E Display-RX-Frame                 0x2000078E BLE-Queue (15x20B)
 *   0x20000E2C ESC-Queue   0x20000F01 Display-Queue
 *   0x20000D8A..0x20000E2A BLE-TX-Aufbau (55xx)
 *   0x200010FA ESC-TX-Puffer (Laenge 0x200011C2)
 *   0x2000128E Display-TX-Puffer (Laenge 0x20001356)
 *   0x20001358 Display-TX-Arbeitspuffer 0x35-Frame (39B)
 *   0x2000137F Schatten Display-0x4C-Frame (19B) [S.2=Cmd 0x35, S.5/Bit5=Clamp-Latch, S.6/Bit2=Clamp-Ind]
 *   0x200013A6 Schatten ESC-0x71 (12B)     0x200013B3 Schatten Display-0x8A/8B/8C
 *   0x2000029B..0x200002DA Laufzeit-Settings  0x200002A1 Gang, 0x200002A4 Polpaare,
 *   0x200002A5 Wheel, 0x200002A6 Temp-Schwelle, 0x200002B9 Power-Limit, 0x200002C6/C7 Spannung
 *   0x200002A7/AD/B3/BA/C0[6] Per-Gang-Arrays (Start/EABS/Limit/Stroeme)
 *   0x2000030D Clamp/Scale-Latch (aus Display-Frame)   0x20000314 Clamp-Indikator (Display)
 *   0x2000030E Display-Timeout  0x20000310/0x20000311 ESC-Timeouts  0x20000398 Dual/Single
 *   0x20001A08 Schatten EEPROM-Block0 (Identitaet/Version)  0x20001A58 Schatten Block1 (Settings)
 *
 * EEPROM (extern, I2C): Block0@0x00 (80B Identitaet), Block1@0x50 (56B Settings,
 *   XOR ueber 0x34B + Halbwort@0x34), Block2/3@0x88/0x94 (Odometer, wear-leveled),
 *   Block4@0xA0 (16B Motor-Kalibrierung). Fabriktabelle ROM @0x0801DA40.
 *
 * PROTOKOLLE:
 *   BLE/App : 20B-Frames [0]=0xAA [1]=Cmd [2..18]=Payload [19]=CRC; 55xx-Telemetrie
 *   ESC     : VCU->ESC '4A 11/14 3A/3B' (17/20B, XOR); ESC->VCU '71 ...' (12B, 3A/3B)
 *   Display : VCU->Display '35 27 3A/3B' (39B, XOR ueber 38B); Display->VCU
 *             0x4C=19B (XOR), 0x8A=11B, 0x8B=8B, 0x8C=8B; Keep-Alive 10B an ESC+Display
 * ===================================================================== */


/* =====================================================================
 *  SEKTION: 0x08007000 - Vektortabelle/Vorlauf & Startup
 * ===================================================================== */

/* ---------------------------------------------------------------------
 * FUN_08007000   (0x08007000, 219 Bytes)
 * Body: 0x08007000-0x080070DB
 * --------------------------------------------------------------------- */
/* WARNING: Control flow encountered bad instruction data */

void FUN_08007000(undefined4 param_1,undefined1 param_2,undefined4 param_3,char param_4)

{
  char cVar1;
  int unaff_r4;
  int unaff_r6;
  int unaff_r7;
  
  cVar1 = param_4 + 'p';
  *(undefined1 *)(unaff_r4 + 5) = param_2;
  *(char *)(unaff_r6 + 5) = (char)unaff_r7;
  *(char *)(unaff_r7 + 5) = cVar1;
  *(char *)(unaff_r7 + 5) = cVar1;
  *(char *)(unaff_r7 + 5) = cVar1;
  *(char *)(unaff_r7 + 5) = cVar1;
  *(char *)(unaff_r7 + 5) = cVar1;
  *(char *)(unaff_r7 + 5) = cVar1;
  *(char *)(unaff_r7 + 5) = cVar1;
  *(char *)(unaff_r7 + 5) = cVar1;
  *(char *)(unaff_r7 + 5) = cVar1;
  *(char *)(unaff_r7 + 5) = cVar1;
  *(char *)(unaff_r7 + 5) = cVar1;
  *(char *)(unaff_r7 + 5) = cVar1;
  *(char *)(unaff_r7 + 5) = cVar1;
  *(char *)(unaff_r7 + 5) = cVar1;
  *(char *)(unaff_r7 + 5) = cVar1;
  *(char *)(unaff_r7 + 5) = cVar1;
  *(char *)(unaff_r7 + 5) = cVar1;
  *(char *)(unaff_r7 + 5) = cVar1;
  *(char *)(unaff_r7 + 5) = cVar1;
  *(char *)(unaff_r7 + 5) = cVar1;
  *(char *)(unaff_r7 + 5) = cVar1;
  *(char *)(unaff_r7 + 5) = cVar1;
  *(char *)(unaff_r7 + 5) = cVar1;
  *(char *)(unaff_r7 + 5) = cVar1;
  *(char *)(unaff_r7 + 5) = cVar1;
  *(char *)(unaff_r7 + 5) = cVar1;
  *(char *)(unaff_r7 + 5) = cVar1;
  *(char *)(unaff_r7 + 5) = cVar1;
  *(char *)(unaff_r7 + 5) = cVar1;
  *(char *)(unaff_r7 + 5) = cVar1;
  *(char *)(unaff_r7 + 5) = cVar1;
  *(char *)(unaff_r7 + 5) = cVar1;
  *(char *)(unaff_r7 + 5) = cVar1;
  *(char *)(unaff_r7 + 5) = cVar1;
  *(char *)(unaff_r7 + 5) = cVar1;
  *(char *)(unaff_r7 + 5) = cVar1;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* =====================================================================
 *  SEKTION: 0x08007144 - Startup & Clock
 * ===================================================================== */

/* ---------------------------------------------------------------------
 * thunk_FUN_0800b882   (0x08007150, 3 Bytes)
 * Body: 0x08007150-0x08007153
 * --------------------------------------------------------------------- */
void thunk_FUN_0800b882(void)

{
  thunk_FUN_0800b882();
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08007160   (0x08007160, 7 Bytes)
 * Body: 0x08007160-0x08007167
 * --------------------------------------------------------------------- */
/* WARNING: This function may have set the stack pointer */

void FUN_08007160(void)

{
  FUN_08007286();
  FUN_0801d81c();
  thunk_FUN_0800b882();
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08007176   (0x08007176, 1 Bytes)
 * Body: 0x08007176-0x08007177
 * --------------------------------------------------------------------- */
void FUN_08007176(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


/* ---------------------------------------------------------------------
 * FUN_0800717a   (0x0800717A, 1 Bytes)
 * Body: 0x0800717A-0x0800717B
 * --------------------------------------------------------------------- */
void FUN_0800717a(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


/* ---------------------------------------------------------------------
 * FUN_08007184   (0x08007184, 257 Bytes)
 * Clock-Init: HSE an, PLL (HSE/2 x12), SW=PLL, PWR/FLASH-Anpassung
 * Body: 0x08007184-0x08007285
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_08007184(void)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  puVar1 = _FUN_08007420;
  uVar3 = 0;
  uVar4 = 0;
  iVar5 = 0;
  _DAT_40021000 = _DAT_40021000 | 0x10000;
  do {
    iVar5 = iVar5 + 1;
    if ((int)(_DAT_40021000 << 0xe) < 0) break;
  } while (iVar5 != 0x2000);
  if ((int)(_DAT_40021000 << 0xe) < 0) {
    _DAT_4002101c = _DAT_4002101c | 0x10000000;
    if ((_DAT_40007000 & 0x600) == 0x400) {
      _DAT_40007000 = _DAT_40007000 | 0x600;
    }
    *_FUN_08007420 = *_FUN_08007420 & 0xfffffffc;
    *puVar1 = *puVar1 | 3;
    uVar4 = _DAT_40021040 & 0xfffffffc;
    uVar3 = _DAT_40021004 & 0xf7c0ffff | 0x82b2500;
    uVar6 = _DAT_40021000 | 0x1000000;
    do {
    } while ((_DAT_40021000 & 0x2000000) == 0);
    do {
      _DAT_40021000 = uVar6;
      uVar2 = _DAT_40021004 & 0xf7c0fffc | 0x82b2503;
      _DAT_40021040 = uVar4;
    } while ((_DAT_40021004 & 0xc) != 0xc);
  }
  else {
    _DAT_20000000 = 4000000;
    uVar2 = _DAT_40021004;
  }
  _DAT_40021004 = uVar2;
  return CONCAT44(uVar4,uVar3);
}


/* ---------------------------------------------------------------------
 * FUN_08007286   (0x08007286, 157 Bytes)
 * Body: 0x08007286-0x08007323
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08007286(void)

{
  uint *puVar1;
  
  puVar1 = _FUN_08007420;
  _DAT_e000ed88 = _DAT_e000ed88 | 0xf00000;
  _DAT_40021024 = _DAT_40021024 | 4;
  _DAT_40021000 = _DAT_40021000 & 0xfef2ffff;
  _DAT_40021004 = _DAT_40021004 & 0xc000;
  _DAT_4002102c = 0;
  _DAT_40021030 = 0x3800;
  _DAT_40021034 = 0;
  _DAT_40021040 = 0;
  _DAT_40021008 = 0x4bf8000;
  _DAT_4002101c = _DAT_4002101c & 0xefffffff;
  *_FUN_08007420 = *_FUN_08007420 | 0x90;
  if ((*puVar1 & 0x100) != 0) {
    *puVar1 = *puVar1 & 0xfffffdff;
  }
  FUN_08007184();
  _DAT_e000ed08 = &DAT_08007000;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08007324   (0x08007324, 235 Bytes)
 * Body: 0x08007324-0x0800740F
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_08007324(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = 0;
  uVar2 = _DAT_40021004 & 0xc;
  uVar3 = (_DAT_40021024 & 0x7f) >> 4;
  if (uVar2 == 0) {
    _DAT_20000000 = *(uint *)(uVar3 * 4 + 0x801d8cc);
  }
  else if (uVar2 == 4) {
    _DAT_20000000 = 16000000;
  }
  else if (uVar2 == 8) {
    _DAT_20000000 = 8000000;
  }
  else if (uVar2 == 0xc) {
    if ((_DAT_40021004 & 0x8000000) == 0) {
      iVar1 = ((_DAT_40021004 & 0x83c0000) >> 0x12) + 2;
    }
    else {
      iVar1 = ((_DAT_40021004 & 0x83c0000) >> 0x12) - 0x1ef;
    }
    if ((_DAT_40021004 & 0x10000) == 0) {
      if ((_DAT_40021040 & 2) == 0) {
        _DAT_20000000 = iVar1 * 16000000;
      }
      else {
        _DAT_20000000 = iVar1 * 8000000;
      }
    }
    else if ((_DAT_40021004 & 0x20000) == 0) {
      _DAT_20000000 = iVar1 * 8000000;
    }
    else {
      _DAT_20000000 = iVar1 * 4000000;
    }
    if ((_DAT_40021040 & 2) == 2) {
      _DAT_20000000 = _DAT_20000000 >> 1;
    }
  }
  else {
    _DAT_20000000 = *(uint *)(uVar3 * 4 + 0x801d8cc);
  }
  _DAT_20000000 = _DAT_20000000 >> (&DAT_0801d8b4)[(_DAT_40021004 & 0xff) >> 4];
  return iVar1;
}


/* ---------------------------------------------------------------------
 * FUN_0800740e   (0x0800740E, 1 Bytes)
 * Body: 0x0800740E-0x0800740F
 * --------------------------------------------------------------------- */
void FUN_0800740e(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08007420   (0x08007420, 3 Bytes)
 * Literalpool (RCC/FLASH/PWR/SCB-Adressen)
 * Body: 0x08007420-0x08007423
 * --------------------------------------------------------------------- */
/* WARNING: Control flow encountered bad instruction data */

void FUN_08007420(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* ---------------------------------------------------------------------
 * FUN_08007422   (0x08007422, 1 Bytes)
 * Literalpool (RCC/FLASH/PWR/SCB-Adressen)
 * Body: 0x08007422-0x08007423
 * --------------------------------------------------------------------- */
/* WARNING: Control flow encountered bad instruction data */

void FUN_08007422(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* =====================================================================
 *  SEKTION: 0x08007458 - Low-Level-Treiber (GPIO/UART/DMA/I2C/CAN-Helfer)
 * ===================================================================== */

/* ---------------------------------------------------------------------
 * FUN_08007458   (0x08007458, 9 Bytes)
 * Body: 0x08007458-0x08007461
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08007458(uint param_1)

{
  _DAT_e000ed0c = param_1 | 0x5fa0000;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08007462   (0x08007462, 99 Bytes)
 * Body: 0x08007462-0x080074C5
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08007462(byte *param_1)

{
  uint uVar1;
  
  if (param_1[3] == 0) {
    *(int *)(((int)(uint)*param_1 >> 5) * 4 + -0x1fff1e80) = 1 << (*param_1 & 0x1f);
  }
  else {
    uVar1 = 0x700 - (_DAT_e000ed0c & 0x700) >> 8;
    *(char *)(*param_1 + 0xe000e400) =
         (char)(((uint)param_1[1] << (4 - uVar1 & 0xff) | (uint)param_1[2] & 0xfU >> (uVar1 & 0xff))
               << 4);
    *(int *)(((int)(uint)*param_1 >> 5) * 4 + -0x1fff1f00) = 1 << (*param_1 & 0x1f);
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_080074c4   (0x080074C4, 1 Bytes)
 * Body: 0x080074C4-0x080074C5
 * --------------------------------------------------------------------- */
void FUN_080074c4(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800767c   (0x0800767C, 3 Bytes)
 * Body: 0x0800767C-0x0800767F
 * --------------------------------------------------------------------- */
void FUN_0800767c(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08007730   (0x08007730, 226 Bytes, 2 Teile)
 * Body: 0x0800767C-0x0800767F, 0x08007682-0x08007761
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08007730(void)

{
  int iVar1;
  uint *unaff_r4;
  uint unaff_r5;
  uint uVar2;
  uint unaff_r8;
  
  do {
    unaff_r4[8] = unaff_r4[8] | 0xf << ((unaff_r5 & 7) << 2);
    while( true ) {
      unaff_r4[1] = unaff_r4[1] & ~(1 << (unaff_r5 & 0xff));
      unaff_r4[3] = unaff_r4[3] & ~(3 << ((unaff_r5 & 0x7f) << 1));
      do {
        unaff_r5 = unaff_r5 + 1;
        if (unaff_r8 >> (unaff_r5 & 0xff) == 0) {
          return;
        }
        uVar2 = 1 << (unaff_r5 & 0xff) & unaff_r8;
      } while (uVar2 == 0);
      if (unaff_r4 == (uint *)0x40010800) {
        iVar1 = 0;
      }
      else if (unaff_r4 == (uint *)0x40010c00) {
        iVar1 = 1;
      }
      else if (unaff_r4 == (uint *)0x40011000) {
        iVar1 = 2;
      }
      else {
        iVar1 = 3;
      }
      if (iVar1 << ((unaff_r5 & 3) << 2) ==
          (*(uint *)((unaff_r5 & 0xfffffffc) + 0x40010004) & 0xf << ((unaff_r5 & 3) << 2))) {
        _DAT_40010400 = _DAT_40010400 & ~uVar2;
        _DAT_40010404 = _DAT_40010404 & ~uVar2;
        _DAT_40010408 = _DAT_40010408 & ~uVar2;
        _DAT_4001040c = _DAT_4001040c & ~uVar2;
        *(uint *)((unaff_r5 & 0xfffffffc) + 0x40010004) =
             *(uint *)((unaff_r5 & 0xfffffffc) + 0x40010004) & ~(0xf << ((unaff_r5 & 3) << 2));
      }
      *unaff_r4 = *unaff_r4 & ~(3 << (unaff_r5 * 2 & 0xff));
      if ((unaff_r5 & 8) == 0) break;
      unaff_r4[9] = unaff_r4[9] | 0xf << ((unaff_r5 & 7) << 2);
    }
  } while( true );
}


/* ---------------------------------------------------------------------
 * thunk_FUN_0800767c   (0x08007760, 1 Bytes)
 * Body: 0x08007760-0x08007761
 * --------------------------------------------------------------------- */
void thunk_FUN_0800767c(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08007776   (0x08007776, 483 Bytes)
 * Body: 0x08007776-0x08007959
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_08007776(uint *param_1,ushort *param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = 0;
  for (uVar2 = 0; (int)(uint)*param_2 >> (uVar2 & 0xff) != 0; uVar2 = uVar2 + 1) {
    if (((uint)*param_2 & 1 << (uVar2 & 0xff)) != 0) {
      uVar1 = uVar2 << 1;
      if ((((*(int *)(param_2 + 4) == 2) || (*(int *)(param_2 + 4) == 0x12)) ||
          (*(int *)(param_2 + 4) == 0)) || (*(int *)(param_2 + 4) == 3)) {
        if ((uVar2 & 8) == 0) {
          param_1[8] = param_1[8] & ~(0xf << ((uVar2 & 7) << 2)) |
                       *(int *)(param_2 + 6) << ((uVar2 & 7) << 2);
        }
        else {
          param_1[9] = param_1[9] & ~(0xf << ((uVar2 & 7) << 2)) |
                       *(int *)(param_2 + 6) << ((uVar2 & 7) << 2);
        }
      }
      *param_1 = *param_1 & ~(3 << (uVar1 & 0xff)) | ((byte)param_2[4] & 0xf) << (uVar1 & 0xff);
      param_1[3] = param_1[3] & ~(3 << (uVar1 & 0xff)) | ((byte)param_2[2] & 3) << (uVar1 & 0xff);
      if (((param_2[4] & 3) != 0) && (*(int *)(param_2 + 4) != 3)) {
        param_1[0xb] = param_1[0xb] & ~(3 << (uVar1 & 0xff)) |
                       ((byte)param_2[1] & 3) << (uVar1 & 0xff);
      }
      uVar1 = param_1[2] & ~(1 << (uVar2 & 0xff)) |
              (*(byte *)((int)param_2 + 3) & 1) << (uVar2 & 0xff);
      param_1[2] = uVar1;
      if ((char)param_2[2] == '\x02') {
        param_1[10] = param_1[10] | 1 << (uVar2 & 0xff);
      }
      else if ((char)param_2[2] == '\x01') {
        param_1[6] = param_1[6] | 1 << (uVar2 & 0xff);
      }
      if (((*(int *)(param_2 + 4) == 1) || (*(int *)(param_2 + 4) == 2)) ||
         ((*(int *)(param_2 + 4) == 0x11 || (*(int *)(param_2 + 4) == 0x12)))) {
        uVar1 = param_1[1] & ~(1 << (uVar2 & 0xff)) |
                (((byte)param_2[4] & 0x1f) >> 4) << (uVar2 & 0xff);
        param_1[1] = uVar1;
      }
      if ((*(uint *)(param_2 + 4) & 0x10000000) != 0) {
        _DAT_40010400 = _DAT_40010400 & ~(1 << (uVar2 & 0xff));
        if ((*(uint *)(param_2 + 4) & 0x10000) == 0x10000) {
          _DAT_40010400 = _DAT_40010400 | 1 << (uVar2 & 0xff);
        }
        _DAT_40010404 = _DAT_40010404 & ~(1 << (uVar2 & 0xff));
        if ((*(uint *)(param_2 + 4) & 0x20000) == 0x20000) {
          _DAT_40010404 = _DAT_40010404 | 1 << (uVar2 & 0xff);
        }
        _DAT_40010408 = _DAT_40010408 & ~(1 << (uVar2 & 0xff));
        if ((*(uint *)(param_2 + 4) & 0x100000) == 0x100000) {
          _DAT_40010408 = _DAT_40010408 | 1 << (uVar2 & 0xff);
        }
        uVar1 = _DAT_4001040c & ~(1 << (uVar2 & 0xff));
        _DAT_4001040c = uVar1;
        if ((*(uint *)(param_2 + 4) & 0x200000) == 0x200000) {
          uVar1 = uVar1 | 1 << (uVar2 & 0xff);
          _DAT_4001040c = uVar1;
        }
      }
    }
  }
  return uVar1;
}


/* ---------------------------------------------------------------------
 * FUN_0800795a   (0x0800795A, 23 Bytes)
 * Body: 0x0800795A-0x08007971
 * --------------------------------------------------------------------- */
void FUN_0800795a(undefined2 *param_1)

{
  *param_1 = 0xffff;
  *(undefined1 *)((int)param_1 + 3) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 6) = 0xf;
  *(undefined1 *)(param_1 + 2) = 0;
  *(undefined1 *)(param_1 + 1) = 0;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08007972   (0x08007972, 17 Bytes)
 * Body: 0x08007972-0x08007983
 * --------------------------------------------------------------------- */
bool FUN_08007972(int param_1,uint param_2)

{
  return (*(uint *)(param_1 + 0x10) & param_2) != 0;
}


/* ---------------------------------------------------------------------
 * FUN_0800798c   (0x0800798C, 17 Bytes)
 * Body: 0x0800798C-0x0800799D
 * --------------------------------------------------------------------- */
bool FUN_0800798c(int param_1,uint param_2)

{
  return (*(uint *)(param_1 + 0x14) & param_2) != 0;
}


/* ---------------------------------------------------------------------
 * FUN_080079a6   (0x080079A6, 3 Bytes)
 * Body: 0x080079A6-0x080079A9
 * --------------------------------------------------------------------- */
void FUN_080079a6(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x18) = param_2;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_080079ae   (0x080079AE, 3 Bytes)
 * Body: 0x080079AE-0x080079B1
 * --------------------------------------------------------------------- */
void FUN_080079ae(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x28) = param_2;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_080079b2   (0x080079B2, 9 Bytes)
 * Body: 0x080079B2-0x080079BB
 * --------------------------------------------------------------------- */
void FUN_080079b2(int param_1,undefined4 param_2,int param_3)

{
  if (param_3 == 0) {
    *(undefined4 *)(param_1 + 0x28) = param_2;
  }
  else {
    *(undefined4 *)(param_1 + 0x18) = param_2;
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_080079ba   (0x080079BA, 1 Bytes)
 * Body: 0x080079BA-0x080079BB
 * --------------------------------------------------------------------- */
void FUN_080079ba(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_080079d2   (0x080079D2, 92 Bytes, 2 Teile)
 * Body: 0x080079D2-0x08007A15, 0x08007A30-0x08007A49
 * --------------------------------------------------------------------- */
void FUN_080079d2(int param_1,uint param_2,int param_3)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = 0x40010800;
  }
  else if (param_1 == 1) {
    iVar1 = 0x40010c00;
  }
  else if (param_1 == 2) {
    iVar1 = 0x40011000;
  }
  else {
    iVar1 = 0x40011400;
  }
  if ((param_2 & 8) == 0) {
    *(uint *)(iVar1 + 0x20) =
         *(uint *)(iVar1 + 0x20) & ~(0xf << ((param_2 & 7) << 2)) | param_3 << ((param_2 & 7) << 2);
  }
  else {
    *(uint *)(iVar1 + 0x24) =
         *(uint *)(iVar1 + 0x24) & ~(0xf << ((param_2 & 7) << 2)) | param_3 << ((param_2 & 7) << 2);
  }
  return;
}


/* ---------------------------------------------------------------------
 * thunk_FUN_08007a48   (0x08007A14, 1 Bytes)
 * Body: 0x08007A14-0x08007A15
 * --------------------------------------------------------------------- */
void thunk_FUN_08007a48(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08007a48   (0x08007A48, 1 Bytes)
 * Body: 0x08007A48-0x08007A49
 * --------------------------------------------------------------------- */
void FUN_08007a48(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08007a4a   (0x08007A4A, 83 Bytes)
 * Body: 0x08007A4A-0x08007A9D
 * --------------------------------------------------------------------- */
void FUN_08007a4a(int param_1,uint param_2)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = 0x40010800;
  }
  else if (param_1 == 1) {
    iVar1 = 0x40010c00;
  }
  else if (param_1 == 2) {
    iVar1 = 0x40011000;
  }
  else {
    iVar1 = 0x40011400;
  }
  if ((param_2 & 8) == 0) {
    *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) & ~(0xf << ((param_2 & 7) << 2)) | 3;
  }
  else {
    *(uint *)(iVar1 + 0x24) = *(uint *)(iVar1 + 0x24) & ~(0xf << ((param_2 & 7) << 2)) | 3;
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08007aa4   (0x08007AA4, 57 Bytes)
 * Body: 0x08007AA4-0x08007ADD
 * --------------------------------------------------------------------- */
void FUN_08007aa4(int param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = (int)param_2 >> 2;
  *(uint *)(iVar1 * 4 + 0x40010004) =
       *(uint *)(iVar1 * 4 + 0x40010004) & ~(3 << ((param_2 & 3) << 2));
  *(uint *)(iVar1 * 4 + 0x40010004) =
       param_1 << ((param_2 & 3) << 2) | *(uint *)(iVar1 * 4 + 0x40010004);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08007adc   (0x08007ADC, 1 Bytes)
 * Body: 0x08007ADC-0x08007ADD
 * --------------------------------------------------------------------- */
void FUN_08007adc(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08007bb4   (0x08007BB4, 67 Bytes)
 * Body: 0x08007BB4-0x08007BF7
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08007bb4(int param_1)

{
  _DAT_40021000 = _DAT_40021000 & 0xfffaffff;
  if (param_1 == 0x10000) {
    _DAT_40021000 = _DAT_40021000 | 0x10000;
  }
  else if (param_1 == 0x40000) {
    _DAT_40021000 = _DAT_40021000 | 0x50000;
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08007bf8   (0x08007BF8, 55 Bytes)
 * Body: 0x08007BF8-0x08007C2F
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_08007bf8(uint param_1)

{
  uint uVar1;
  
  uVar1 = _DAT_40021000;
  if (((int)param_1 >> 5 != 1) && (uVar1 = _DAT_40021024, (int)param_1 >> 5 == 2)) {
    uVar1 = _DAT_40021020;
  }
  return (1 << (param_1 & 0x1f) & uVar1) != 0;
}


/* ---------------------------------------------------------------------
 * FUN_08007c30   (0x08007C30, 55 Bytes)
 * Body: 0x08007C30-0x08007C67
 * --------------------------------------------------------------------- */
bool FUN_08007c30(void)

{
  bool bVar1;
  int local_10;
  
  local_10 = 0;
  do {
    bVar1 = FUN_08007bf8(0x31);
    local_10 = local_10 + 1;
    if (local_10 == 0x2000) break;
  } while (!bVar1);
  bVar1 = FUN_08007bf8(0x31);
  return bVar1;
}


/* ---------------------------------------------------------------------
 * FUN_08007c68   (0x08007C68, 33 Bytes)
 * Body: 0x08007C68-0x08007C89
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08007c68(int param_1)

{
  _DAT_40021000 = _DAT_40021000 & 0xfffffffe;
  if (param_1 == 1) {
    _DAT_40021000 = _DAT_40021000 | 1;
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08007c8a   (0x08007C8A, 55 Bytes)
 * Body: 0x08007C8A-0x08007CC1
 * --------------------------------------------------------------------- */
bool FUN_08007c8a(void)

{
  bool bVar1;
  int local_10;
  
  local_10 = 0;
  do {
    bVar1 = FUN_08007bf8(0x21);
    local_10 = local_10 + 1;
    if (local_10 == 0x500) break;
  } while (!bVar1);
  bVar1 = FUN_08007bf8(0x21);
  return bVar1;
}


/* ---------------------------------------------------------------------
 * FUN_08007cc0   (0x08007CC0, 1 Bytes)
 * Body: 0x08007CC0-0x08007CC1
 * --------------------------------------------------------------------- */
void FUN_08007cc0(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08007cdc   (0x08007CDC, 55 Bytes)
 * Body: 0x08007CDC-0x08007D13
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08007cdc(int param_1,uint param_2)

{
  _DAT_40021024 = _DAT_40021024 & 0xffffff8f | param_2;
  if (param_1 == 0) {
    _DAT_40021024 = _DAT_40021024 & 0xfffffffb;
  }
  else if (param_1 == 4) {
    _DAT_40021024 = _DAT_40021024 | 4;
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08007d14   (0x08007D14, 55 Bytes)
 * Body: 0x08007D14-0x08007D4B
 * --------------------------------------------------------------------- */
bool FUN_08007d14(void)

{
  bool bVar1;
  int local_10;
  
  local_10 = 0;
  do {
    bVar1 = FUN_08007bf8(99);
    local_10 = local_10 + 1;
    if (local_10 == 0x500) break;
  } while (!bVar1);
  bVar1 = FUN_08007bf8(99);
  return bVar1;
}


/* ---------------------------------------------------------------------
 * FUN_08007d4a   (0x08007D4A, 1 Bytes)
 * Body: 0x08007D4A-0x08007D4B
 * --------------------------------------------------------------------- */
void FUN_08007d4a(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08007d66   (0x08007D66, 55 Bytes)
 * Body: 0x08007D66-0x08007D9D
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08007d66(uint param_1,uint param_2,uint param_3)

{
  if ((param_1 == 0) || (param_1 == 1)) {
    param_3 = param_1 | param_3;
  }
  else {
    param_2 = param_1 | param_2;
  }
  _DAT_40021004 = _DAT_40021004 & 0xf7c0ffff | param_2;
  _DAT_40021040 = _DAT_40021040 & 0xfffffffc | param_3;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08007d9e   (0x08007D9E, 5 Bytes)
 * Body: 0x08007D9E-0x08007DA3
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08007d9e(undefined4 param_1)

{
  _DAT_42420060 = param_1;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08007da4   (0x08007DA4, 17 Bytes)
 * Body: 0x08007DA4-0x08007DB5
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08007da4(uint param_1)

{
  _DAT_40021004 = _DAT_40021004 & 0xfffffffc | param_1;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08007db6   (0x08007DB6, 9 Bytes)
 * Body: 0x08007DB6-0x08007DBF
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_08007db6(void)

{
  return _DAT_40021004 & 0xc;
}


/* ---------------------------------------------------------------------
 * FUN_08007dc0   (0x08007DC0, 17 Bytes)
 * Body: 0x08007DC0-0x08007DD1
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08007dc0(uint param_1)

{
  _DAT_40021004 = _DAT_40021004 & 0xffffff0f | param_1;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08007dd2   (0x08007DD2, 17 Bytes)
 * Body: 0x08007DD2-0x08007DE3
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08007dd2(uint param_1)

{
  _DAT_40021004 = _DAT_40021004 & 0xfffff8ff | param_1;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08007de4   (0x08007DE4, 19 Bytes)
 * Body: 0x08007DE4-0x08007DF7
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08007de4(int param_1)

{
  _DAT_40021004 = _DAT_40021004 & 0xffffc7ff | param_1 << 3;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08007df6   (0x08007DF6, 1 Bytes)
 * Body: 0x08007DF6-0x08007DF7
 * --------------------------------------------------------------------- */
void FUN_08007df6(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08007e4a   (0x08007E4A, 23 Bytes)
 * Body: 0x08007E4A-0x08007E61
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08007e4a(uint param_1,uint param_2)

{
  _DAT_4002102c = _DAT_4002102c & 0xfffc0fff | param_1 | param_2;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08007e62   (0x08007E62, 29 Bytes)
 * Body: 0x08007E62-0x08007E7F
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08007e62(uint param_1,int param_2)

{
  if (param_2 == 0) {
    param_1 = param_1 & 0xfffffeff;
  }
  _DAT_4002102c = _DAT_4002102c & 0xfffffe0f | param_1;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08007e80   (0x08007E80, 17 Bytes)
 * Body: 0x08007E80-0x08007E91
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08007e80(uint param_1)

{
  _DAT_4002102c = _DAT_4002102c & 0xfffffff0 | param_1;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08007e90   (0x08007E90, 1 Bytes)
 * Body: 0x08007E90-0x08007E91
 * --------------------------------------------------------------------- */
void FUN_08007e90(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08007ec8   (0x08007EC8, 45 Bytes)
 * Body: 0x08007EC8-0x08007EF5
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08007ec8(uint param_1,int param_2)

{
  _DAT_40021030 = _DAT_40021030 & 0xfffffdff | param_1;
  if (param_2 == 0) {
    _DAT_40021030 = _DAT_40021030 & 0xffffff7f;
  }
  else {
    _DAT_40021030 = _DAT_40021030 | 0x80;
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08007ef4   (0x08007EF4, 1 Bytes)
 * Body: 0x08007EF4-0x08007EF5
 * --------------------------------------------------------------------- */
void FUN_08007ef4(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08007f40   (0x08007F40, 24 Bytes, 2 Teile)
 * Body: 0x08007F40-0x08007F4D, 0x08007F6C-0x08007F77
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08007f40(uint param_1,int param_2)

{
  if (param_2 == 0) {
    _DAT_4002101c = _DAT_4002101c & ~param_1;
  }
  else {
    _DAT_4002101c = _DAT_4002101c | param_1;
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08007f58   (0x08007F58, 0 Bytes)
 * Body: 0x08007F58-0x08007F58
 * --------------------------------------------------------------------- */
/* WARNING: Control flow encountered bad instruction data */

void FUN_08007f58(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* ---------------------------------------------------------------------
 * FUN_08007f78   (0x08007F78, 39 Bytes)
 * Body: 0x08007F78-0x08007F9F
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08007f78(uint param_1)

{
  FUN_08007f40(0x10000000,1);
  _DAT_40007000 = _DAT_40007000 | 0x100;
  _DAT_40021034 = _DAT_40021034 & 0xfffffff8 | param_1;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08007f9e   (0x08007F9E, 1 Bytes)
 * Body: 0x08007F9E-0x08007F9F
 * --------------------------------------------------------------------- */
void FUN_08007f9e(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08008006   (0x08008006, 79 Bytes)
 * Body: 0x08008006-0x08008055
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08008006(int param_1)

{
  FUN_08007f40(0x10000000,1);
  _DAT_40007000 = _DAT_40007000 | 0x100;
  _DAT_40021020 = _DAT_40021020 & 0xfffffff2;
  if (param_1 == 1) {
    _DAT_40021020 = _DAT_40021020 | 1;
  }
  else if (param_1 == 4) {
    _DAT_40021020 = _DAT_40021020 | 5;
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08008054   (0x08008054, 1 Bytes)
 * Body: 0x08008054-0x08008055
 * --------------------------------------------------------------------- */
void FUN_08008054(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800809c   (0x0800809C, 301 Bytes)
 * Body: 0x0800809C-0x080081C9
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0800809c(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = (_DAT_40021024 & 0x7f) >> 4;
  if ((_DAT_40021004 & 0x8000000) == 0) {
    iVar3 = ((_DAT_40021004 & 0x83c0000) >> 0x12) + 2;
  }
  else {
    iVar3 = ((_DAT_40021004 & 0x83c0000) >> 0x12) - 0x1ef;
  }
  if ((_DAT_40021004 & 0x10000) == 0) {
    if ((_DAT_40021040 & 1) == 0) {
      uVar2 = iVar3 * 16000000;
    }
    else {
      uVar2 = iVar3 * 8000000;
    }
  }
  else if ((_DAT_40021004 & 0x20000) == 0) {
    uVar2 = iVar3 * 8000000;
  }
  else {
    uVar2 = iVar3 * 4000000;
  }
  if ((_DAT_40021040 & 2) != 0) {
    uVar2 = uVar2 >> 1;
  }
  uVar1 = _DAT_40021004 & 0xc;
  if (uVar1 == 0) {
    *param_1 = *(uint *)(uVar4 * 4 + 0x801d928);
  }
  else if (uVar1 == 4) {
    *param_1 = 16000000;
  }
  else if (uVar1 == 8) {
    *param_1 = 8000000;
  }
  else if (uVar1 == 0xc) {
    *param_1 = uVar2;
  }
  else {
    *param_1 = *(uint *)(uVar4 * 4 + 0x801d928);
  }
  param_1[1] = *param_1 >> *(sbyte *)(((_DAT_40021004 & 0xf0) >> 4) + 0x801d8e8);
  param_1[2] = param_1[1] >> *(sbyte *)(((_DAT_40021004 & 0x700) >> 8) + 0x801d8e8);
  param_1[3] = param_1[1] >> *(sbyte *)(((_DAT_40021004 & 0x3800) >> 0xb) + 0x801d8e8);
  param_1[5] = param_1[1] / (uint)*(byte *)((_DAT_4002102c & 0xf) + 0x801d8f8);
  param_1[4] = uVar2 / *(ushort *)(((_DAT_4002102c & 0x1f0) >> 4 & 0xf) * 2 + 0x801d908);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_080081ca   (0x080081CA, 25 Bytes)
 * Body: 0x080081CA-0x080081E3
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_080081ca(uint param_1,int param_2)

{
  if (param_2 == 0) {
    _DAT_40021014 = _DAT_40021014 & ~param_1;
  }
  else {
    _DAT_40021014 = _DAT_40021014 | param_1;
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_080081e4   (0x080081E4, 25 Bytes)
 * Body: 0x080081E4-0x080081FD
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_080081e4(uint param_1,int param_2)

{
  if (param_2 == 0) {
    _DAT_40021018 = _DAT_40021018 & ~param_1;
  }
  else {
    _DAT_40021018 = _DAT_40021018 | param_1;
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_080081fc   (0x080081FC, 1 Bytes)
 * Body: 0x080081FC-0x080081FD
 * --------------------------------------------------------------------- */
void FUN_080081fc(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08008218   (0x08008218, 25 Bytes)
 * Body: 0x08008218-0x08008231
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08008218(uint param_1,int param_2)

{
  if (param_2 == 0) {
    _DAT_4002100c = _DAT_4002100c & ~param_1;
  }
  else {
    _DAT_4002100c = _DAT_4002100c | param_1;
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08008232   (0x08008232, 25 Bytes)
 * Body: 0x08008232-0x0800824B
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08008232(uint param_1,int param_2)

{
  if (param_2 == 0) {
    _DAT_40021010 = _DAT_40021010 & ~param_1;
  }
  else {
    _DAT_40021010 = _DAT_40021010 | param_1;
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800824a   (0x0800824A, 1 Bytes)
 * Body: 0x0800824A-0x0800824B
 * --------------------------------------------------------------------- */
void FUN_0800824a(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08008386   (0x08008386, 167 Bytes)
 * Body: 0x08008386-0x0800842D
 * --------------------------------------------------------------------- */
void FUN_08008386(int param_1,int *param_2)

{
  uint uVar1;
  uint auStack_38 [2];
  int local_30;
  int local_2c;
  
  *(ushort *)(param_1 + 0x10) = *(ushort *)(param_1 + 0x10) & 0xcfff | *(ushort *)((int)param_2 + 6)
  ;
  *(ushort *)(param_1 + 0xc) =
       *(ushort *)(param_1 + 0xc) & 0xe9f3 |
       *(ushort *)(param_2 + 1) | *(ushort *)(param_2 + 2) | *(ushort *)((int)param_2 + 10);
  *(ushort *)(param_1 + 0x14) = *(ushort *)(param_1 + 0x14) & 0xfcff | *(ushort *)(param_2 + 3);
  FUN_0800809c(auStack_38);
  if (((param_1 != 0x40013800) && (param_1 != 0x40015000)) && (param_1 != 0x40015400)) {
    local_2c = local_30;
  }
  uVar1 = (uint)(local_2c * 0x19) / (uint)(*param_2 << 2);
  *(ushort *)(param_1 + 8) =
       (ushort)(uVar1 / 100 << 4) | (ushort)(((uVar1 % 100) * 0x10 + 0x32) / 100) & 0xf;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800842e   (0x0800842E, 23 Bytes)
 * Body: 0x0800842E-0x08008445
 * --------------------------------------------------------------------- */
void FUN_0800842e(undefined4 *param_1)

{
  *param_1 = 0x2580;
  *(undefined2 *)(param_1 + 1) = 0;
  *(undefined2 *)((int)param_1 + 6) = 0;
  *(undefined2 *)(param_1 + 2) = 0;
  *(undefined2 *)((int)param_1 + 10) = 0xc;
  *(undefined2 *)(param_1 + 3) = 0;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08008446   (0x08008446, 33 Bytes)
 * Body: 0x08008446-0x08008467
 * --------------------------------------------------------------------- */
void FUN_08008446(int param_1,ushort *param_2)

{
  *(ushort *)(param_1 + 0x10) =
       *(ushort *)(param_1 + 0x10) & 0xf0ff | *param_2 | param_2[1] | param_2[2] | param_2[3];
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08008474   (0x08008474, 23 Bytes)
 * Body: 0x08008474-0x0800848B
 * --------------------------------------------------------------------- */
void FUN_08008474(int param_1,int param_2)

{
  if (param_2 == 0) {
    *(ushort *)(param_1 + 0xc) = *(ushort *)(param_1 + 0xc) & 0xdfff;
  }
  else {
    *(ushort *)(param_1 + 0xc) = *(ushort *)(param_1 + 0xc) | 0x2000;
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800848c   (0x0800848C, 73 Bytes)
 * Body: 0x0800848C-0x080084D5
 * --------------------------------------------------------------------- */
void FUN_0800848c(int param_1,uint param_2,int param_3)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = (param_2 & 0xff) >> 5;
  uVar3 = 1 << (param_2 & 0x1f);
  if (uVar2 == 1) {
    puVar1 = (uint *)(param_1 + 0xc);
  }
  else if (uVar2 == 2) {
    puVar1 = (uint *)(param_1 + 0x10);
  }
  else {
    puVar1 = (uint *)(param_1 + 0x14);
  }
  if (param_3 == 0) {
    *puVar1 = *puVar1 & ~uVar3;
  }
  else {
    *puVar1 = *puVar1 | uVar3;
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_080084d4   (0x080084D4, 1 Bytes)
 * Body: 0x080084D4-0x080084D5
 * --------------------------------------------------------------------- */
void FUN_080084d4(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800854e   (0x0800854E, 7 Bytes)
 * Body: 0x0800854E-0x08008555
 * --------------------------------------------------------------------- */
void FUN_0800854e(int param_1,int param_2)

{
  *(ushort *)(param_1 + 4) = (ushort)((uint)(param_2 << 0x17) >> 0x17);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08008556   (0x08008556, 9 Bytes)
 * Body: 0x08008556-0x0800855F
 * --------------------------------------------------------------------- */
ushort FUN_08008556(int param_1)

{
  return (ushort)(((uint)*(ushort *)(param_1 + 4) << 0x17) >> 0x17);
}


/* ---------------------------------------------------------------------
 * FUN_0800855e   (0x0800855E, 1 Bytes)
 * Body: 0x0800855E-0x0800855F
 * --------------------------------------------------------------------- */
void FUN_0800855e(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_080085fc   (0x080085FC, 25 Bytes)
 * Body: 0x080085FC-0x08008615
 * --------------------------------------------------------------------- */
bool FUN_080085fc(ushort *param_1,ushort param_2)

{
  return (*param_1 & param_2) != 0;
}


/* ---------------------------------------------------------------------
 * FUN_08008614   (0x08008614, 1 Bytes)
 * Body: 0x08008614-0x08008615
 * --------------------------------------------------------------------- */
void FUN_08008614(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08008628   (0x08008628, 83 Bytes)
 * Body: 0x08008628-0x0800867B
 * --------------------------------------------------------------------- */
undefined4 FUN_08008628(ushort *param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = (param_2 & 0xff) >> 5;
  uVar2 = 1 << (param_2 & 0x1f);
  if (uVar3 == 1) {
    uVar2 = uVar2 & param_1[6];
  }
  else if (uVar3 == 2) {
    uVar2 = uVar2 & param_1[8];
  }
  else {
    uVar2 = uVar2 & param_1[10];
  }
  if ((uVar2 == 0) || ((1 << ((int)param_2 >> 8 & 0xffU) & (uint)*param_1) == 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


/* ---------------------------------------------------------------------
 * FUN_0800867c   (0x0800867C, 29 Bytes)
 * Body: 0x0800867C-0x08008699
 * --------------------------------------------------------------------- */
void FUN_0800867c(ushort *param_1,int param_2)

{
  *param_1 = ~(ushort)(1 << (param_2 >> 8 & 0xffU));
  return;
}


/* ---------------------------------------------------------------------
 * FUN_080086a0   (0x080086A0, 235 Bytes)
 * Body: 0x080086A0-0x0800878B
 * --------------------------------------------------------------------- */
/* WARNING: Removing unreachable block (ram,0x08008762) */
/* WARNING: Removing unreachable block (ram,0x08008732) */
/* WARNING: Removing unreachable block (ram,0x08008702) */
/* WARNING: Removing unreachable block (ram,0x0800871a) */
/* WARNING: Removing unreachable block (ram,0x0800874a) */
/* WARNING: Removing unreachable block (ram,0x0800877a) */
/* WARNING: Removing unreachable block (ram,0x080086d2) */
/* WARNING: Removing unreachable block (ram,0x080086ea) */
/* WARNING: Removing unreachable block (ram,0x080086ba) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_080086a0(void)

{
  _DAT_8002a000 = 0x40015000;
  uRam08008ab4 = 0x40000400;
  _FUN_08008ab0 = 0x40012c00;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800878c   (0x0800878C, 295 Bytes)
 * Body: 0x0800878C-0x080088B3
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0800878c(uint *param_1,undefined2 *param_2)

{
  uint uVar1;
  
  uVar1 = *param_1;
  if ((((param_1 == (uint *)0x40012c00) || (param_1 == (uint *)0x40013400)) ||
      (param_1 == (uint *)0x40000000)) ||
     (((param_1 == (uint *)0x40000400 || (param_1 == (uint *)0x40000800)) ||
      ((param_1 == (uint *)0x40000c00 || (param_1 == (uint *)0x40003c00)))))) {
    uVar1 = uVar1 & 0xffffff8f | (uint)(ushort)param_2[1];
  }
  if ((param_1 != (uint *)0x40001000) && (param_1 != (uint *)0x40001400)) {
    uVar1 = uVar1 & 0xfffffcff | (uint)(ushort)param_2[3];
  }
  *param_1 = uVar1;
  *(undefined2 *)(param_1 + 0xb) = param_2[2];
  *(undefined2 *)(param_1 + 10) = *param_2;
  if ((param_1 == (uint *)0x40012c00) || (param_1 == (uint *)0x40013400)) {
    *(ushort *)(param_1 + 0xc) = (ushort)*(byte *)(param_2 + 4);
  }
  *(undefined2 *)(param_1 + 5) = 1;
  uVar1 = *param_1;
  if (((((param_1 == (uint *)0x40012c00) || (param_1 == (uint *)0x40013400)) ||
       (param_1 == (uint *)0x40000000)) ||
      ((param_1 == (uint *)0x40000400 || (param_1 == (uint *)0x40000800)))) ||
     ((param_1 == (uint *)0x40000c00 || (param_1 == (uint *)0x40003c00)))) {
    if (*(char *)((int)param_2 + 9) == '\0') {
      uVar1 = uVar1 & 0xfffff7ff;
    }
    else {
      uVar1 = uVar1 | 0x800;
    }
  }
  if (param_1 == (uint *)0x40003c00) {
    if (*(char *)(param_2 + 5) == '\0') {
      uVar1 = uVar1 & 0xffffefff;
    }
    else {
      uVar1 = uVar1 | 0x1000;
    }
    if (*(char *)((int)param_2 + 0xb) == '\0') {
      uVar1 = uVar1 & 0xffffdfff;
    }
    else {
      uVar1 = uVar1 | 0x2000;
    }
    if (*(char *)(param_2 + 6) == '\0') {
      uVar1 = uVar1 & 0xffffbfff;
    }
    else {
      uVar1 = uVar1 | 0x4000;
    }
  }
  if (((param_1 == (uint *)0x40012c00) || (param_1 == (uint *)0x40013400)) ||
     ((param_1 == (uint *)0x40000000 ||
      (((param_1 == (uint *)0x40000400 || (param_1 == (uint *)0x40000800)) ||
       (param_1 == (uint *)0x40003c00)))))) {
    if (*(char *)((int)param_2 + 0xd) == '\0') {
      uVar1 = uVar1 & 0xffff7fff;
    }
    else {
      uVar1 = uVar1 | 0x8000;
    }
  }
  *param_1 = uVar1;
  uVar1 = param_1[1];
  if ((param_1 == (uint *)0x40000000) || (param_1 == (uint *)0x40000800)) {
    if (*(char *)(param_2 + 7) == '\0') {
      uVar1 = uVar1 & 0xfffffeff;
    }
    else {
      uVar1 = uVar1 | 0x100;
    }
  }
  param_1[1] = uVar1;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_080088b4   (0x080088B4, 105 Bytes)
 * Body: 0x080088B4-0x0800891D
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_080088b4(int param_1,ushort *param_2)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  
  *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfffffffe;
  uVar3 = *(uint *)(param_1 + 4);
  uVar1 = *param_2;
  uVar2 = *(uint *)(param_1 + 0x20) & 0xfffffffd | (uint)param_2[4] | (uint)param_2[1];
  if ((param_1 == _FUN_08008ab0) || (param_1 == 0x40013400)) {
    uVar2 = (uVar2 & 0xfffffff7 | (uint)param_2[5]) & 0xfffffffb | (uint)param_2[2];
    uVar3 = uVar3 & 0xfffffcff | (uint)param_2[6] | (uint)param_2[7];
  }
  *(uint *)(param_1 + 4) = uVar3;
  *(ushort *)(param_1 + 0x18) = *(ushort *)(param_1 + 0x18) & 0xff8c | uVar1;
  *(ushort *)(param_1 + 0x34) = param_2[3];
  *(uint *)(param_1 + 0x20) = uVar2;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800891e   (0x0800891E, 125 Bytes)
 * Body: 0x0800891E-0x0800899B
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0800891e(int param_1,short *param_2)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  
  *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xffffffef;
  uVar3 = *(uint *)(param_1 + 4);
  sVar1 = *param_2;
  uVar2 = *(uint *)(param_1 + 0x20) & 0xffffffdf | (uint)(ushort)param_2[4] << 4 |
          (uint)(ushort)param_2[1] << 4;
  if ((param_1 == _FUN_08008ab0) || (param_1 == 0x40013400)) {
    uVar2 = (uVar2 & 0xffffff7f | (uint)(ushort)param_2[5] << 4) & 0xffffffbf |
            (uint)(ushort)param_2[2] << 4;
    uVar3 = uVar3 & 0xfffff3ff | (uint)(ushort)param_2[6] << 2 | (uint)(ushort)param_2[7] << 2;
  }
  *(uint *)(param_1 + 4) = uVar3;
  *(ushort *)(param_1 + 0x18) = *(ushort *)(param_1 + 0x18) & 0x8cff | sVar1 << 8;
  *(short *)(param_1 + 0x38) = param_2[3];
  *(uint *)(param_1 + 0x20) = uVar2;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800899c   (0x0800899C, 117 Bytes)
 * Body: 0x0800899C-0x08008A11
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0800899c(int param_1,ushort *param_2)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  
  *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfffffeff;
  uVar3 = *(uint *)(param_1 + 4);
  uVar1 = *param_2;
  uVar2 = *(uint *)(param_1 + 0x20) & 0xfffffdff | (uint)param_2[4] << 8 | (uint)param_2[1] << 8;
  if ((param_1 == _FUN_08008ab0) || (param_1 == 0x40013400)) {
    uVar2 = (uVar2 & 0xfffff7ff | (uint)param_2[5] << 8) & 0xfffffbff | (uint)param_2[2] << 8;
    uVar3 = uVar3 & 0xffffcfff | (uint)param_2[6] << 4 | (uint)param_2[7] << 4;
  }
  *(uint *)(param_1 + 4) = uVar3;
  *(ushort *)(param_1 + 0x1c) = *(ushort *)(param_1 + 0x1c) & 0xff8c | uVar1;
  *(ushort *)(param_1 + 0x3c) = param_2[3];
  *(uint *)(param_1 + 0x20) = uVar2;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08008a10   (0x08008A10, 1 Bytes)
 * Body: 0x08008A10-0x08008A11
 * --------------------------------------------------------------------- */
void FUN_08008a10(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08008a12   (0x08008A12, 97 Bytes)
 * Body: 0x08008A12-0x08008A73
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08008a12(int param_1,short *param_2)

{
  short sVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  
  *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xffffefff;
  uVar4 = *(uint *)(param_1 + 4);
  sVar1 = *param_2;
  uVar2 = param_2[4];
  uVar3 = param_2[1];
  if ((param_1 == _FUN_08008ab0) || (param_1 == 0x40013400)) {
    uVar4 = uVar4 & 0xffffbfff | (uint)(ushort)param_2[6] << 6;
  }
  *(uint *)(param_1 + 4) = uVar4;
  *(ushort *)(param_1 + 0x1c) = *(ushort *)(param_1 + 0x1c) & 0x8cff | sVar1 << 8;
  *(short *)(param_1 + 0x40) = param_2[3];
  *(uint *)(param_1 + 0x20) =
       *(uint *)(param_1 + 0x20) & 0xffffdfff | (uint)uVar2 << 0xc | (uint)uVar3 << 0xc;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08008a74   (0x08008A74, 59 Bytes)
 * Body: 0x08008A74-0x08008AAF
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08008a74(int param_1,ushort *param_2)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  
  *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfffeffff;
  uVar4 = *(uint *)(param_1 + 4);
  uVar1 = *param_2;
  uVar2 = param_2[4];
  uVar3 = param_2[1];
  if ((param_1 == _FUN_08008ab0) || (param_1 == 0x40013400)) {
    uVar4 = uVar4 & 0xfffeffff | (uint)param_2[6] << 8;
  }
  *(uint *)(param_1 + 4) = uVar4;
  *(ushort *)(param_1 + 0x54) = *(ushort *)(param_1 + 0x54) & 0xff8f | uVar1;
  *(ushort *)(param_1 + 0x58) = param_2[3];
  *(uint *)(param_1 + 0x20) =
       *(uint *)(param_1 + 0x20) & 0xfffdffff | (uint)uVar2 << 0x10 | (uint)uVar3 << 0x10;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08008ab0   (0x08008AB0, 61 Bytes)
 * Body: 0x08008AB0-0x08008AED
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08008ab0(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  undefined2 unaff_r4;
  int unaff_r5;
  
  if (unaff_r5 == 0) {
    param_4 = param_4 & 0xfffeffff | (uint)uRam0000000c << 8;
  }
  uRam00000004 = param_4;
  uVar1 = uRam00000004;
  _DAT_00000054 = unaff_r4;
  uRam00000004._2_2_ = (undefined2)(param_4 >> 0x10);
  uRam00000058 = uRam00000004._2_2_;
  uRam00000020 = param_3;
  uRam00000004 = uVar1;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08008aee   (0x08008AEE, 95 Bytes)
 * Body: 0x08008AEE-0x08008B4D
 * --------------------------------------------------------------------- */
void FUN_08008aee(int param_1,short *param_2)

{
  short sVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  
  *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xffefffff;
  uVar4 = *(uint *)(param_1 + 4);
  sVar1 = *param_2;
  uVar2 = param_2[4];
  uVar3 = param_2[1];
  if ((param_1 == 0x40012c00) || (param_1 == 0x40013400)) {
    uVar4 = uVar4 & 0xfffbffff | (uint)(ushort)param_2[6] << 10;
  }
  *(uint *)(param_1 + 4) = uVar4;
  *(ushort *)(param_1 + 0x54) = *(ushort *)(param_1 + 0x54) & 0x8fff | sVar1 << 8;
  *(short *)(param_1 + 0x5c) = param_2[3];
  *(uint *)(param_1 + 0x20) =
       *(uint *)(param_1 + 0x20) & 0xffdfffff | (uint)uVar2 << 0x14 | (uint)uVar3 << 0x14;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08008b4e   (0x08008B4E, 25 Bytes)
 * Body: 0x08008B4E-0x08008B67
 * --------------------------------------------------------------------- */
void FUN_08008b4e(int param_1,short param_2)

{
  *(ushort *)(param_1 + 0x1c) = *(ushort *)(param_1 + 0x1c) & 0xf3ff;
  *(ushort *)(param_1 + 0x1c) = *(ushort *)(param_1 + 0x1c) | param_2 << 8;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08008b68   (0x08008B68, 121 Bytes)
 * Body: 0x08008B68-0x08008BE1
 * --------------------------------------------------------------------- */
void FUN_08008b68(int param_1,uint param_2,short param_3,short param_4)

{
  uint uVar1;
  
  *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xffffefff;
  if ((((param_1 == 0x40012c00) || (param_1 == 0x40013400)) || (param_1 == 0x40000000)) ||
     (((param_1 == 0x40000400 || (param_1 == 0x40000800)) ||
      ((param_1 == 0x40000c00 || (param_1 == 0x40003c00)))))) {
    uVar1 = *(uint *)(param_1 + 0x20) & 0xffffdfff | param_2 << 0xc | 0x1000;
  }
  else {
    uVar1 = *(uint *)(param_1 + 0x20) & 0xffffdfff | param_2 | 0x1000;
  }
  *(ushort *)(param_1 + 0x1c) = *(ushort *)(param_1 + 0x1c) & 0xcff | param_3 << 8 | param_4 << 0xc;
  *(uint *)(param_1 + 0x20) = uVar1;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08008be2   (0x08008BE2, 17 Bytes)
 * Body: 0x08008BE2-0x08008BF3
 * --------------------------------------------------------------------- */
void FUN_08008be2(int param_1,ushort param_2)

{
  *(ushort *)(param_1 + 0x1c) = *(ushort *)(param_1 + 0x1c) & 0xfff3;
  *(ushort *)(param_1 + 0x1c) = *(ushort *)(param_1 + 0x1c) | param_2;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08008bf4   (0x08008BF4, 113 Bytes)
 * Body: 0x08008BF4-0x08008C65
 * --------------------------------------------------------------------- */
void FUN_08008bf4(int param_1,uint param_2,ushort param_3,short param_4)

{
  uint uVar1;
  
  *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfffffeff;
  if ((((param_1 == 0x40012c00) || (param_1 == 0x40013400)) || (param_1 == 0x40000000)) ||
     (((param_1 == 0x40000400 || (param_1 == 0x40000800)) ||
      ((param_1 == 0x40000c00 || (param_1 == 0x40003c00)))))) {
    uVar1 = *(uint *)(param_1 + 0x20) & 0xfffffdff | param_2 << 8 | 0x100;
  }
  else {
    uVar1 = *(uint *)(param_1 + 0x20) & 0xfffff5ff | param_2 | 0x100;
  }
  *(ushort *)(param_1 + 0x1c) = *(ushort *)(param_1 + 0x1c) & 0xff0c | param_4 << 4 | param_3;
  *(uint *)(param_1 + 0x20) = uVar1;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08008c66   (0x08008C66, 25 Bytes)
 * Body: 0x08008C66-0x08008C7F
 * --------------------------------------------------------------------- */
void FUN_08008c66(int param_1,short param_2)

{
  *(ushort *)(param_1 + 0x18) = *(ushort *)(param_1 + 0x18) & 0xf3ff;
  *(ushort *)(param_1 + 0x18) = *(ushort *)(param_1 + 0x18) | param_2 << 8;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08008c80   (0x08008C80, 121 Bytes)
 * Body: 0x08008C80-0x08008CF9
 * --------------------------------------------------------------------- */
void FUN_08008c80(int param_1,uint param_2,short param_3,short param_4)

{
  uint uVar1;
  
  *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xffffffef;
  if ((((param_1 == 0x40012c00) || (param_1 == 0x40013400)) || (param_1 == 0x40000000)) ||
     (((param_1 == 0x40000400 || (param_1 == 0x40000800)) ||
      ((param_1 == 0x40000c00 || (param_1 == 0x40003c00)))))) {
    uVar1 = *(uint *)(param_1 + 0x20) & 0xffffffdf | param_2 << 4 | 0x10;
  }
  else {
    uVar1 = *(uint *)(param_1 + 0x20) & 0xffffff5f | param_2 | 0x10;
  }
  *(ushort *)(param_1 + 0x18) = *(ushort *)(param_1 + 0x18) & 0xcff | param_4 << 0xc | param_3 << 8;
  *(uint *)(param_1 + 0x20) = uVar1;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08008cfa   (0x08008CFA, 17 Bytes)
 * Body: 0x08008CFA-0x08008D0B
 * --------------------------------------------------------------------- */
void FUN_08008cfa(int param_1,ushort param_2)

{
  *(ushort *)(param_1 + 0x18) = *(ushort *)(param_1 + 0x18) & 0xfff3;
  *(ushort *)(param_1 + 0x18) = *(ushort *)(param_1 + 0x18) | param_2;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08008d0c   (0x08008D0C, 109 Bytes)
 * Body: 0x08008D0C-0x08008D79
 * --------------------------------------------------------------------- */
void FUN_08008d0c(int param_1,uint param_2,ushort param_3,short param_4)

{
  uint uVar1;
  
  *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfffffffe;
  if ((((param_1 == 0x40012c00) || (param_1 == 0x40013400)) || (param_1 == 0x40000000)) ||
     (((param_1 == 0x40000400 || (param_1 == 0x40000800)) ||
      ((param_1 == 0x40000c00 || (param_1 == 0x40003c00)))))) {
    uVar1 = *(uint *)(param_1 + 0x20) & 0xfffffffd | param_2 | 1;
  }
  else {
    uVar1 = *(uint *)(param_1 + 0x20) & 0xfffffff5 | param_2 | 1;
  }
  *(ushort *)(param_1 + 0x18) = *(ushort *)(param_1 + 0x18) & 0xff0c | param_4 << 4 | param_3;
  *(uint *)(param_1 + 0x20) = uVar1;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08008d7a   (0x08008D7A, 155 Bytes)
 * Body: 0x08008D7A-0x08008E15
 * --------------------------------------------------------------------- */
void FUN_08008d7a(int param_1,short *param_2)

{
  if (*param_2 == 0) {
    FUN_08008d0c(param_1,(uint)(ushort)param_2[1],param_2[2],param_2[4]);
    FUN_08008cfa(param_1,param_2[3]);
  }
  else if (*param_2 == 4) {
    FUN_08008c80(param_1,(uint)(ushort)param_2[1],param_2[2],param_2[4]);
    FUN_08008c66(param_1,param_2[3]);
  }
  else if (*param_2 == 8) {
    FUN_08008bf4(param_1,(uint)(ushort)param_2[1],param_2[2],param_2[4]);
    FUN_08008be2(param_1,param_2[3]);
  }
  else {
    FUN_08008b68(param_1,(uint)(ushort)param_2[1],param_2[2],param_2[4]);
    FUN_08008b4e(param_1,param_2[3]);
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08008e16   (0x08008E16, 123 Bytes)
 * Body: 0x08008E16-0x08008E91
 * --------------------------------------------------------------------- */
void FUN_08008e16(int param_1,short *param_2)

{
  uint uVar1;
  ushort uVar2;
  
  if (param_2[1] == 0) {
    uVar1 = 2;
  }
  else {
    uVar1 = 0;
  }
  if (param_2[2] == 1) {
    uVar2 = 2;
  }
  else {
    uVar2 = 1;
  }
  if (*param_2 == 0) {
    FUN_08008d0c(param_1,(uint)(ushort)param_2[1],param_2[2],param_2[4]);
    FUN_08008cfa(param_1,param_2[3]);
    FUN_08008c80(param_1,uVar1,uVar2,param_2[4]);
    FUN_08008c66(param_1,param_2[3]);
  }
  else {
    FUN_08008c80(param_1,(uint)(ushort)param_2[1],param_2[2],param_2[4]);
    FUN_08008c66(param_1,param_2[3]);
    FUN_08008d0c(param_1,uVar1,uVar2,param_2[4]);
    FUN_08008cfa(param_1,param_2[3]);
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08008e92   (0x08008E92, 81 Bytes)
 * Body: 0x08008E92-0x08008EE3
 * --------------------------------------------------------------------- */
void FUN_08008e92(uint *param_1,ushort *param_2)

{
  uint uVar1;
  
  *(ushort *)(param_1 + 0x11) =
       *param_2 | param_2[1] | param_2[2] | param_2[3] | param_2[4] | param_2[5] | param_2[6];
  if ((char)param_2[7] == '\0') {
    uVar1 = *param_1 | 0x400;
  }
  else {
    uVar1 = *param_1 & 0xfffffbff;
  }
  if (*(char *)((int)param_2 + 0xf) == '\0') {
    uVar1 = uVar1 & 0xfffeffff;
  }
  else {
    uVar1 = uVar1 | 0x10000;
  }
  if ((char)param_2[8] == '\0') {
    uVar1 = uVar1 & 0xfffdffff;
  }
  else {
    uVar1 = uVar1 | 0x20000;
  }
  *param_1 = uVar1;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08008ee2   (0x08008EE2, 1 Bytes)
 * Body: 0x08008EE2-0x08008EE3
 * --------------------------------------------------------------------- */
void FUN_08008ee2(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08008f54   (0x08008F54, 21 Bytes)
 * Body: 0x08008F54-0x08008F69
 * --------------------------------------------------------------------- */
void FUN_08008f54(uint *param_1,int param_2)

{
  if (param_2 == 0) {
    *param_1 = *param_1 & 0xfffffffe;
  }
  else {
    *param_1 = *param_1 | 1;
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08008f68   (0x08008F68, 1 Bytes)
 * Body: 0x08008F68-0x08008F69
 * --------------------------------------------------------------------- */
void FUN_08008f68(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08008f88   (0x08008F88, 17 Bytes)
 * Body: 0x08008F88-0x08008F99
 * --------------------------------------------------------------------- */
void FUN_08008f88(int param_1,ushort param_2,int param_3)

{
  if (param_3 == 0) {
    *(ushort *)(param_1 + 0xc) = *(ushort *)(param_1 + 0xc) & ~param_2;
  }
  else {
    *(ushort *)(param_1 + 0xc) = *(ushort *)(param_1 + 0xc) | param_2;
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08008f98   (0x08008F98, 1 Bytes)
 * Body: 0x08008F98-0x08008F99
 * --------------------------------------------------------------------- */
void FUN_08008f98(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08008fc6   (0x08008FC6, 17 Bytes)
 * Body: 0x08008FC6-0x08008FD7
 * --------------------------------------------------------------------- */
void FUN_08008fc6(int param_1,ushort param_2)

{
  *(ushort *)(param_1 + 8) = *(ushort *)(param_1 + 8) & 0xff8f | param_2;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08008fd8   (0x08008FD8, 23 Bytes)
 * Body: 0x08008FD8-0x08008FEF
 * --------------------------------------------------------------------- */
void FUN_08008fd8(int param_1,ushort param_2)

{
  FUN_08008fc6(param_1,param_2);
  *(ushort *)(param_1 + 8) = *(ushort *)(param_1 + 8) | 7;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08008ff0   (0x08008FF0, 61 Bytes)
 * Body: 0x08008FF0-0x0800902D
 * --------------------------------------------------------------------- */
void FUN_08008ff0(int param_1,int param_2,uint param_3,short param_4)

{
  if (param_2 == 0x60) {
    FUN_08008c80(param_1,param_3,1,param_4);
  }
  else {
    FUN_08008d0c(param_1,param_3,1,param_4);
  }
  FUN_08008fc6(param_1,(ushort)param_2);
  *(ushort *)(param_1 + 8) = *(ushort *)(param_1 + 8) | 7;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800902e   (0x0800902E, 27 Bytes)
 * Body: 0x0800902E-0x08009049
 * --------------------------------------------------------------------- */
void FUN_0800902e(int param_1,ushort param_2,ushort param_3,short param_4)

{
  *(ushort *)(param_1 + 8) = *(ushort *)(param_1 + 8) & 0xff | param_4 << 8 | param_3 | param_2;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800904a   (0x0800904A, 53 Bytes)
 * Body: 0x0800904A-0x0800907F
 * --------------------------------------------------------------------- */
void FUN_0800904a(int param_1,ushort param_2,ushort param_3,short param_4)

{
  FUN_0800902e(param_1,param_2,param_3,param_4);
  *(ushort *)(param_1 + 8) = *(ushort *)(param_1 + 8) & 0xff88 | 0x77;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08009080   (0x08009080, 31 Bytes)
 * Body: 0x08009080-0x0800909F
 * --------------------------------------------------------------------- */
void FUN_08009080(int param_1,ushort param_2,ushort param_3,short param_4)

{
  FUN_0800902e(param_1,param_2,param_3,param_4);
  *(ushort *)(param_1 + 8) = *(ushort *)(param_1 + 8) | 0x4000;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_080090a0   (0x080090A0, 5 Bytes)
 * Body: 0x080090A0-0x080090A5
 * --------------------------------------------------------------------- */
void FUN_080090a0(int param_1,undefined2 param_2,undefined2 param_3)

{
  *(undefined2 *)(param_1 + 0x28) = param_2;
  *(undefined2 *)(param_1 + 0x14) = param_3;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_080090a4   (0x080090A4, 1 Bytes)
 * Body: 0x080090A4-0x080090A5
 * --------------------------------------------------------------------- */
void FUN_080090a4(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_080090a6   (0x080090A6, 15 Bytes)
 * Body: 0x080090A6-0x080090B5
 * --------------------------------------------------------------------- */
void FUN_080090a6(uint *param_1,uint param_2)

{
  *param_1 = *param_1 & 0xffffff8f | param_2;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_080090b6   (0x080090B6, 63 Bytes)
 * Body: 0x080090B6-0x080090F5
 * --------------------------------------------------------------------- */
void FUN_080090b6(int param_1,ushort param_2,uint param_3,uint param_4)

{
  *(ushort *)(param_1 + 8) = *(ushort *)(param_1 + 8) & 0xfff8 | param_2;
  *(ushort *)(param_1 + 0x18) = *(ushort *)(param_1 + 0x18) & 0xfcfc | 0x101;
  *(uint *)(param_1 + 0x20) =
       *(uint *)(param_1 + 0x20) & 0xffffffdd | (param_4 & 0xfff) << 4 | param_3;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_080090f4   (0x080090F4, 1 Bytes)
 * Body: 0x080090F4-0x080090F5
 * --------------------------------------------------------------------- */
void FUN_080090f4(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08009234   (0x08009234, 19 Bytes)
 * Body: 0x08009234-0x08009247
 * --------------------------------------------------------------------- */
void FUN_08009234(int param_1,undefined4 param_2,ushort param_3)

{
  *(ushort *)(param_1 + 0x54) = *(ushort *)(param_1 + 0x54) & 0xfff7 | param_3;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_080093a8   (0x080093A8, 1 Bytes)
 * Body: 0x080093A8-0x080093A9
 * --------------------------------------------------------------------- */
void FUN_080093a8(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800958a   (0x0800958A, 5 Bytes)
 * Body: 0x0800958A-0x0800958F
 * --------------------------------------------------------------------- */
undefined2 FUN_0800958a(int param_1)

{
  return *(undefined2 *)(param_1 + 0x24);
}


/* ---------------------------------------------------------------------
 * FUN_0800958e   (0x0800958E, 1 Bytes)
 * Body: 0x0800958E-0x0800958F
 * --------------------------------------------------------------------- */
void FUN_0800958e(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_080095a4   (0x080095A4, 65 Bytes)
 * Body: 0x080095A4-0x080095E5
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_080095a4(undefined4 param_1,uint param_2,int param_3)

{
  char in_ZR;
  
  if ((in_ZR == '\0') && (param_3 != 0x40013400)) {
    if (((param_3 == 0x40000000) ||
        (((param_3 == 0x40000400 || (param_3 == 0x40000800)) || (param_3 == 0x40000c00)))) ||
       (param_3 == 0x40003c00)) {
      if ((*(uint *)(param_3 + 0x20) & param_2) == 0) {
        param_1 = 0;
      }
      else {
        param_1 = 1;
      }
    }
  }
  else if ((*(uint *)(param_3 + 0x20) & param_2) == 0) {
    param_1 = 0;
  }
  else {
    param_1 = 1;
  }
  FUN_08009628 = 0x40013400;
  return param_1;
}


/* ---------------------------------------------------------------------
 * FUN_080095fe   (0x080095FE, 33 Bytes)
 * Body: 0x080095FE-0x0800961F
 * --------------------------------------------------------------------- */
undefined4 FUN_080095fe(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (((*(uint *)(param_1 + 0x10) & param_2) == 0) || ((*(ushort *)(param_1 + 0xc) & param_2) == 0))
  {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


/* ---------------------------------------------------------------------
 * FUN_08009620   (0x08009620, 5 Bytes)
 * Body: 0x08009620-0x08009625
 * --------------------------------------------------------------------- */
void FUN_08009620(int param_1,uint param_2)

{
  *(uint *)(param_1 + 0x10) = ~param_2;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08009628   (0x08009628, 23 Bytes)
 * Body: 0x08009628-0x0800963F
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08009628(void)

{
  *_FUN_08009a40 = *_FUN_08009a40 & 0xf8;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08009640   (0x08009640, 17 Bytes)
 * Body: 0x08009640-0x08009651
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08009640(uint param_1)

{
  *_FUN_08009a40 = *_FUN_08009a40 & 0xf8 | param_1;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08009650   (0x08009650, 1 Bytes)
 * Body: 0x08009650-0x08009651
 * --------------------------------------------------------------------- */
void FUN_08009650(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_080096f8   (0x080096F8, 71 Bytes)
 * Body: 0x080096F8-0x0800973F
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_080096f8(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_8;
  
  iVar2 = 0;
  local_8 = 0;
  uVar1 = 0;
  if ((*FUN_08009a40 & 2) == 0) {
    *FUN_08009a40 = *FUN_08009a40 | 1;
    do {
      local_8 = local_8 + 1;
      if ((int)(*FUN_08009a40 << 0x1e) < 0) break;
    } while (local_8 != 0x500);
    iVar2 = -((int)(*FUN_08009a40 << 0x1e) >> 0x1f);
    if (iVar2 == 0) {
      uVar1 = 1;
    }
  }
  return CONCAT44(iVar2,uVar1);
}


/* ---------------------------------------------------------------------
 * FUN_08009740   (0x08009740, 11 Bytes)
 * Body: 0x08009740-0x0800974B
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08009740(void)

{
  _DAT_40022004 = 0xcdef89ab;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800974c   (0x0800974C, 13 Bytes)
 * Body: 0x0800974C-0x08009759
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0800974c(void)

{
  *(uint *)(_FUN_08009a40 + 0x10) = *(uint *)(_FUN_08009a40 + 0x10) | 0x80;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800975a   (0x0800975A, 75 Bytes)
 * Body: 0x0800975A-0x080097A5
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0800975a(void)

{
  undefined4 uVar1;
  
  if ((*(uint *)(_FUN_08009a40 + 0xc) & 1) == 0) {
    if ((*(uint *)(_FUN_08009a40 + 0xc) & 4) == 0) {
      if ((*(uint *)(_FUN_08009a40 + 0xc) & 8) == 0) {
        if ((*(uint *)(_FUN_08009a40 + 0xc) & 0x10) == 0) {
          if ((*(uint *)(_FUN_08009a40 + 0xc) & 0x40) == 0) {
            uVar1 = 6;
          }
          else {
            uVar1 = 7;
          }
        }
        else {
          uVar1 = 5;
        }
      }
      else {
        uVar1 = 4;
      }
    }
    else {
      uVar1 = 3;
    }
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


/* ---------------------------------------------------------------------
 * FUN_080097a6   (0x080097A6, 37 Bytes)
 * Body: 0x080097A6-0x080097CB
 * --------------------------------------------------------------------- */
int FUN_080097a6(void)

{
  int iVar1;
  int extraout_r2;
  int extraout_r2_00;
  int iVar2;
  
  iVar1 = FUN_0800975a();
  iVar2 = extraout_r2;
  while ((iVar1 == 1 && (iVar2 != 0))) {
    iVar1 = FUN_0800975a();
    iVar2 = extraout_r2_00 + -1;
  }
  if (iVar2 == 0) {
    iVar1 = 10;
  }
  return iVar1;
}


/* ---------------------------------------------------------------------
 * FUN_080097cc   (0x080097CC, 11 Bytes)
 * Body: 0x080097CC-0x080097D7
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_080097cc(uint param_1)

{
  *(uint *)(_FUN_08009a40 + 0xc) = *(uint *)(_FUN_08009a40 + 0xc) | param_1;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_080097d8   (0x080097D8, 77 Bytes)
 * Body: 0x080097D8-0x08009825
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_080097d8(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  FUN_080097cc(0x7c);
  iVar2 = FUN_080097a6();
  iVar1 = _FUN_08009a40;
  if (iVar2 == 6) {
    *(uint *)(_FUN_08009a40 + 0x10) = *(uint *)(_FUN_08009a40 + 0x10) | 2;
    *(undefined4 *)(iVar1 + 0x14) = param_1;
    *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) | 0x40;
    iVar2 = FUN_080097a6();
    *(uint *)(_FUN_08009a40 + 0x10) = *(uint *)(_FUN_08009a40 + 0x10) & 0x3ffd;
  }
  return iVar2;
}


/* ---------------------------------------------------------------------
 * FUN_08009826   (0x08009826, 73 Bytes)
 * Body: 0x08009826-0x0800986F
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_08009826(void)

{
  int iVar1;
  int iVar2;
  
  FUN_080097cc(0x7c);
  iVar2 = FUN_080097a6();
  iVar1 = _FUN_08009a40;
  if (iVar2 == 6) {
    *(uint *)(_FUN_08009a40 + 0x10) = *(uint *)(_FUN_08009a40 + 0x10) | 4;
    *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) | 0x40;
    iVar2 = FUN_080097a6();
    *(uint *)(_FUN_08009a40 + 0x10) = *(uint *)(_FUN_08009a40 + 0x10) & 0x3ffb;
  }
  return iVar2;
}


/* ---------------------------------------------------------------------
 * FUN_08009870   (0x08009870, 19 Bytes)
 * Body: 0x08009870-0x08009883
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_08009870(void)

{
  return (*(uint *)(_FUN_08009a40 + 0x1c) & 2) != 0;
}


/* ---------------------------------------------------------------------
 * FUN_08009884   (0x08009884, 19 Bytes)
 * Body: 0x08009884-0x08009897
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_08009884(void)

{
  return (*(uint *)(_FUN_08009a40 + 0x1c) & 0x80000000) != 0;
}


/* ---------------------------------------------------------------------
 * FUN_08009898   (0x08009898, 177 Bytes)
 * Body: 0x08009898-0x08009949
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_08009898(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0xffff00a5;
  bVar1 = FUN_08009884();
  if (bVar1) {
    iVar2 = 8;
  }
  else {
    bVar1 = FUN_08009870();
    if (bVar1) {
      uVar3 = 0xff0000;
    }
    FUN_080097cc(0x7c);
    iVar2 = FUN_080097a6();
    if (iVar2 == 6) {
      _DAT_40022008 = 0xcdef89ab;
      _DAT_40022010 = _DAT_40022010 | 0x60;
      iVar2 = FUN_080097a6();
      if (iVar2 == 6) {
        FUN_080097cc(0x7c);
        _DAT_40022010 = _DAT_40022010 & 0x3fdf | 0x10;
        _DAT_1ffff800 = uVar3;
        iVar2 = FUN_080097a6();
        if (iVar2 != 10) {
          _DAT_40022010 = _DAT_40022010 & 0x3fef;
        }
      }
      else if (iVar2 != 10) {
        _DAT_40022010 = _DAT_40022010 & 0x3fdf;
      }
    }
  }
  return iVar2;
}


/* ---------------------------------------------------------------------
 * FUN_0800994a   (0x0800994A, 260 Bytes, 2 Teile)
 * Body: 0x0800994A-0x08009A3D, 0x08009AC4-0x08009AD5
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
FUN_0800994a(uint param_1,uint param_2,uint param_3,uint param_4,uint param_5,uint param_6,
            undefined4 param_7,uint param_8,uint param_9,uint param_10,uint param_11,uint param_12,
            uint param_13)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint local_30;
  
  bVar1 = FUN_08009884();
  if (bVar1) {
    iVar2 = 8;
    local_30 = param_2;
  }
  else {
    uVar3 = ~param_8;
    local_30 = param_9 | (param_10 | param_11 | param_12 | param_13) << 0x10;
    _DAT_40022008 = 0xcdef89ab;
    FUN_080097cc(0x7c);
    iVar2 = FUN_080097a6();
    if (iVar2 == 6) {
      _DAT_40022010 = _DAT_40022010 | 0x60;
      iVar2 = FUN_080097a6();
      if (iVar2 == 6) {
        FUN_080097cc(0x7c);
        _DAT_40022010 = _DAT_40022010 & 0x3fdf | 0x10;
        _DAT_1ffff800 = param_1 | (param_2 | param_3 | param_4 | param_5) << 0x10;
        iVar2 = FUN_080097a6();
        if (iVar2 == 6) {
          FUN_080097cc(0x7c);
          _DAT_1ffff804 = param_6 | param_6 << 0x10;
          iVar2 = FUN_080097a6();
          if (iVar2 == 6) {
            FUN_080097cc(0x7c);
            _DAT_1ffff808 = uVar3 & 0xff | (uVar3 & 0xff00) << 8;
            iVar2 = FUN_080097a6();
            if (iVar2 == 6) {
              FUN_080097cc(0x7c);
              _DAT_1ffff80c = uVar3 >> 8 & 0xff0000 | (uVar3 & 0xffffff) >> 0x10;
              iVar2 = FUN_080097a6();
              if (iVar2 == 6) {
                FUN_080097cc(0x7c);
                _DAT_1ffff810 = local_30;
                iVar2 = FUN_080097a6();
              }
            }
          }
        }
        if (iVar2 != 10) {
          *(uint *)(_FUN_08009e68 + 0x10) = *(uint *)(_FUN_08009e68 + 0x10) & 0x3fef;
        }
      }
      else if (iVar2 != 10) {
        *(uint *)(_FUN_08009e68 + 0x10) = *(uint *)(_FUN_08009e68 + 0x10) & 0x3fdf;
      }
    }
  }
  return CONCAT44(local_30,iVar2);
}


/* ---------------------------------------------------------------------
 * FUN_08009a40   (0x08009A40, 134 Bytes, 2 Teile)
 * Body: 0x08009A40-0x08009AC3, 0x08009AD6-0x08009AD9
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_08009a40(void)

{
  int iVar1;
  undefined4 *unaff_r5;
  undefined4 unaff_r11;
  undefined4 unaff_pc;
  undefined4 in_stack_00000000;
  undefined4 in_stack_00000004;
  
  VectorTableLookup(*unaff_r5,unaff_pc,1);
  iVar1 = FUN_080097a6();
  if (iVar1 == 6) {
    FUN_080097cc(0x7c);
    _DAT_1ffff808 = in_stack_00000004;
    iVar1 = FUN_080097a6();
    if (iVar1 == 6) {
      FUN_080097cc(0x7c);
      _DAT_1ffff80c = unaff_r11;
      iVar1 = FUN_080097a6();
      if (iVar1 == 6) {
        FUN_080097cc(0x7c);
        _DAT_1ffff810 = in_stack_00000000;
        iVar1 = FUN_080097a6();
      }
    }
  }
  if (iVar1 != 10) {
    *(uint *)(_FUN_08009e68 + 0x10) = *(uint *)(_FUN_08009e68 + 0x10) & 0x3fef;
  }
  return CONCAT44(in_stack_00000000,iVar1);
}


/* ---------------------------------------------------------------------
 * FUN_08009ada   (0x08009ADA, 85 Bytes)
 * Body: 0x08009ADA-0x08009B2F
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_08009ada(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  
  if (((uint)param_1 & 3) == 0) {
    FUN_080097cc(0x7c);
    iVar1 = FUN_080097a6();
    if (iVar1 == 6) {
      *(uint *)(_FUN_08009e68 + 0x10) = *(uint *)(_FUN_08009e68 + 0x10) | 1;
      *param_1 = param_2;
      iVar1 = FUN_080097a6();
      *(uint *)(_FUN_08009e68 + 0x10) = *(uint *)(_FUN_08009e68 + 0x10) & 0x3ffe;
    }
  }
  else {
    iVar1 = 9;
  }
  return iVar1;
}


/* ---------------------------------------------------------------------
 * FUN_08009b30   (0x08009B30, 93 Bytes)
 * Body: 0x08009B30-0x08009B8D
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_08009b30(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  
  bVar2 = FUN_08009884();
  if (bVar2) {
    iVar3 = 8;
  }
  else {
    FUN_080097cc(0x7c);
    iVar3 = FUN_080097a6();
    iVar1 = _FUN_08009e68;
    if (iVar3 == 6) {
      *(undefined4 *)(_FUN_08009e68 + 8) = FUN_08009e68;
      *(undefined4 *)(iVar1 + 8) = 0xcdef89ab;
      *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) | 0x10;
      *param_1 = param_2;
      iVar3 = FUN_080097a6();
      if (iVar3 != 10) {
        *(uint *)(_FUN_08009e68 + 0x10) = *(uint *)(_FUN_08009e68 + 0x10) & 0x3fef;
      }
    }
  }
  return iVar3;
}


/* ---------------------------------------------------------------------
 * FUN_08009b8e   (0x08009B8E, 171 Bytes)
 * Body: 0x08009B8E-0x08009C39
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_08009b8e(uint param_1)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  bVar2 = FUN_08009884();
  if (bVar2) {
    iVar3 = 8;
  }
  else {
    uVar4 = ~param_1;
    uVar5 = (uVar4 & 0xffff) >> 8;
    uVar6 = (uVar4 & 0xffffff) >> 0x10;
    FUN_080097cc(0x7c);
    iVar3 = FUN_080097a6();
    iVar1 = _FUN_08009e68;
    if (iVar3 == 6) {
      *(undefined4 *)(_FUN_08009e68 + 8) = FUN_08009e68;
      *(undefined4 *)(iVar1 + 8) = 0xcdef89ab;
      *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) | 0x10;
      if (((uVar4 & 0xff) != 0xff) || (uVar5 != 0xff)) {
        _DAT_1ffff808 = uVar4 & 0xff | uVar5 << 0x10;
        iVar3 = FUN_080097a6();
      }
      if (((uVar6 != 0xff) || (uVar4 >> 0x18 != 0xff)) && (iVar3 == 6)) {
        _DAT_1ffff80c = uVar6 | (uVar4 >> 0x18) << 0x10;
        iVar3 = FUN_080097a6();
      }
      if (iVar3 != 10) {
        *(uint *)(_FUN_08009e68 + 0x10) = *(uint *)(_FUN_08009e68 + 0x10) & 0x3fef;
      }
    }
  }
  return iVar3;
}


/* ---------------------------------------------------------------------
 * FUN_08009c3a   (0x08009C3A, 197 Bytes)
 * Body: 0x08009C3A-0x08009CFF
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_08009c3a(int param_1)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = (_DAT_4002201c & 0x1c) << 0xe;
  bVar2 = FUN_08009884();
  if (bVar2) {
    iVar3 = 8;
  }
  else {
    FUN_080097cc(0x7c);
    iVar3 = FUN_080097a6();
    iVar1 = _FUN_08009e68;
    if (iVar3 == 6) {
      *(undefined4 *)(_FUN_08009e68 + 8) = uRam08009e6c;
      *(undefined4 *)(iVar1 + 8) = 0xcdef89ab;
      *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) | 0x20;
      *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) | 0x40;
      iVar3 = FUN_080097a6();
      if (iVar3 == 6) {
        FUN_080097cc(0x7c);
        _DAT_40022010 = _DAT_40022010 & 0x3fdf | 0x10;
        _DAT_1ffff800 = uVar4;
        if (param_1 == 0) {
          _DAT_1ffff800 = uVar4 | 0xa5;
        }
        iVar3 = FUN_080097a6();
        if (iVar3 != 10) {
          _DAT_40022010 = _DAT_40022010 & 0x3fef;
        }
      }
      else if (iVar3 != 10) {
        _DAT_40022010 = _DAT_40022010 & 0x3fdf;
      }
    }
  }
  return iVar3;
}


/* ---------------------------------------------------------------------
 * FUN_08009c54   (0x08009C54, 1 Bytes)
 * Body: 0x08009C54-0x08009C55
 * --------------------------------------------------------------------- */
void FUN_08009c54(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * thunk_FUN_08009c54   (0x08009CFE, 1 Bytes)
 * Body: 0x08009CFE-0x08009CFF
 * --------------------------------------------------------------------- */
void thunk_FUN_08009c54(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08009e68   (0x08009E68, 13 Bytes)
 * Body: 0x08009E68-0x08009E75
 * --------------------------------------------------------------------- */
/* WARNING: Control flow encountered bad instruction data */

void FUN_08009e68(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* ---------------------------------------------------------------------
 * FUN_08009e74   (0x08009E74, 1 Bytes)
 * Body: 0x08009E74-0x08009E75
 * --------------------------------------------------------------------- */
/* WARNING: Control flow encountered bad instruction data */

void FUN_08009e74(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* ---------------------------------------------------------------------
 * FUN_0800a03c   (0x0800A03C, 5 Bytes)
 * Body: 0x0800A03C-0x0800A041
 * --------------------------------------------------------------------- */
/* WARNING: Control flow encountered bad instruction data */

void FUN_0800a03c(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* ---------------------------------------------------------------------
 * FUN_0800a040   (0x0800A040, 1 Bytes)
 * Body: 0x0800A040-0x0800A041
 * --------------------------------------------------------------------- */
/* WARNING: Control flow encountered bad instruction data */

void FUN_0800a040(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* ---------------------------------------------------------------------
 * FUN_0800a068   (0x0800A068, 65 Bytes)
 * Body: 0x0800A068-0x0800A0A9
 * --------------------------------------------------------------------- */
void FUN_0800a068(int param_1,byte *param_2)

{
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xfff0feff | (uint)*param_2 << 8;
  *(uint *)(param_1 + 8) =
       *(uint *)(param_1 + 8) & 0xfff1f7fd |
       *(uint *)(param_2 + 8) | *(uint *)(param_2 + 4) | (uint)param_2[1] << 1;
  *(uint *)(param_1 + 0x2c) =
       *(uint *)(param_1 + 0x2c) & 0xff0fffff | (param_2[0xc] - 1 & 0xff) << 0x14;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800a0a8   (0x0800A0A8, 1 Bytes)
 * Body: 0x0800A0A8-0x0800A0A9
 * --------------------------------------------------------------------- */
void FUN_0800a0a8(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800a0ba   (0x0800A0BA, 21 Bytes)
 * Body: 0x0800A0BA-0x0800A0CF
 * --------------------------------------------------------------------- */
void FUN_0800a0ba(int param_1,int param_2)

{
  if (param_2 == 0) {
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xfffffffe;
  }
  else {
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | 1;
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800a0ce   (0x0800A0CE, 1 Bytes)
 * Body: 0x0800A0CE-0x0800A0CF
 * --------------------------------------------------------------------- */
void FUN_0800a0ce(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800a0fe   (0x0800A0FE, 13 Bytes)
 * Body: 0x0800A0FE-0x0800A10B
 * --------------------------------------------------------------------- */
void FUN_0800a0fe(int param_1)

{
  if (*(int *)(param_1 + 0x54) == 0) {
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | 4;
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800a10c   (0x0800A10C, 25 Bytes)
 * Body: 0x0800A10C-0x0800A125
 * --------------------------------------------------------------------- */
bool FUN_0800a10c(int param_1)

{
  return *(int *)(param_1 + 0x54) == 0 && (*(uint *)(param_1 + 8) & 4) != 0;
}


/* ---------------------------------------------------------------------
 * FUN_0800a126   (0x0800A126, 21 Bytes)
 * Body: 0x0800A126-0x0800A13B
 * --------------------------------------------------------------------- */
void FUN_0800a126(int param_1,int param_2)

{
  if (param_2 == 0) {
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xffafffff;
  }
  else {
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | 0x500000;
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800a13a   (0x0800A13A, 1 Bytes)
 * Body: 0x0800A13A-0x0800A13B
 * --------------------------------------------------------------------- */
void FUN_0800a13a(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800a150   (0x0800A150, 23 Bytes)
 * Body: 0x0800A150-0x0800A167
 * --------------------------------------------------------------------- */
void FUN_0800a150(int param_1,int param_2)

{
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xffff1fff | (param_2 + -1) * 0x2000;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800a166   (0x0800A166, 1 Bytes)
 * Body: 0x0800A166-0x0800A167
 * --------------------------------------------------------------------- */
void FUN_0800a166(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800a17e   (0x0800A17E, 197 Bytes)
 * Body: 0x0800A17E-0x0800A243
 * --------------------------------------------------------------------- */
void FUN_0800a17e(int param_1,int param_2,int param_3,uint param_4)

{
  if (param_2 == 0x12) {
    *(uint *)(param_1 + 0x5c) = *(uint *)(param_1 + 0x5c) & 0xfffffff8 | param_4;
  }
  if (param_2 < 10) {
    *(uint *)(param_1 + 0x10) =
         *(uint *)(param_1 + 0x10) & ~(7 << (param_2 * 3 & 0xffU)) |
         param_4 << (param_2 * 3 & 0xffU);
  }
  else {
    *(uint *)(param_1 + 0xc) =
         *(uint *)(param_1 + 0xc) & ~(7 << ((param_2 + -10) * 3 & 0xffU)) |
         param_4 << ((param_2 + -10) * 3 & 0xffU);
  }
  if (param_3 < 7) {
    *(uint *)(param_1 + 0x34) =
         *(uint *)(param_1 + 0x34) & ~(0x1f << ((param_3 + -1) * 5 & 0xffU)) |
         param_2 << ((param_3 + -1) * 5 & 0xffU);
  }
  else if (param_3 < 0xd) {
    *(uint *)(param_1 + 0x30) =
         *(uint *)(param_1 + 0x30) & ~(0x1f << ((param_3 + -7) * 5 & 0xffU)) |
         param_2 << ((param_3 + -7) * 5 & 0xffU);
  }
  else {
    *(uint *)(param_1 + 0x2c) =
         *(uint *)(param_1 + 0x2c) & ~(0x1f << ((param_3 + -0xd) * 5 & 0xffU)) |
         param_2 << ((param_3 + -0xd) * 5 & 0xffU);
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800a242   (0x0800A242, 1 Bytes)
 * Body: 0x0800A242-0x0800A243
 * --------------------------------------------------------------------- */
void FUN_0800a242(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800a25a   (0x0800A25A, 7 Bytes)
 * Body: 0x0800A25A-0x0800A261
 * --------------------------------------------------------------------- */
uint FUN_0800a25a(int param_1)

{
  return *(uint *)(param_1 + 0x4c) & 0xffff;
}


/* ---------------------------------------------------------------------
 * FUN_0800a260   (0x0800A260, 1 Bytes)
 * Body: 0x0800A260-0x0800A261
 * --------------------------------------------------------------------- */
void FUN_0800a260(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800a2de   (0x0800A2DE, 145 Bytes)
 * Body: 0x0800A2DE-0x0800A36F
 * --------------------------------------------------------------------- */
void FUN_0800a2de(int param_1,int param_2,int param_3,uint param_4)

{
  uint uVar1;
  
  if (param_2 == 0x12) {
    *(uint *)(param_1 + 0x5c) = *(uint *)(param_1 + 0x5c) & 0xfffffff8 | param_4;
  }
  else if (param_2 < 10) {
    *(uint *)(param_1 + 0x10) =
         *(uint *)(param_1 + 0x10) & ~(7 << (param_2 * 3 & 0xffU)) |
         param_4 << (param_2 * 3 & 0xffU);
  }
  else {
    *(uint *)(param_1 + 0xc) =
         *(uint *)(param_1 + 0xc) & ~(7 << ((param_2 + -10) * 3 & 0xffU)) |
         param_4 << ((param_2 + -10) * 3 & 0xffU);
  }
  uVar1 = (*(uint *)(param_1 + 0x38) & 0x3fffff) >> 0x14;
  *(uint *)(param_1 + 0x38) =
       *(uint *)(param_1 + 0x38) & ~(0x1f << (((param_3 + 3) - (uVar1 + 1)) * 5 & 0xff)) |
       param_2 << (((param_3 + 3) - (uVar1 + 1)) * 5 & 0xff);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800a370   (0x0800A370, 23 Bytes)
 * Body: 0x0800A370-0x0800A387
 * --------------------------------------------------------------------- */
void FUN_0800a370(int param_1,int param_2)

{
  *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) & 0xffcfffff | (param_2 + -1) * 0x100000;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800a388   (0x0800A388, 19 Bytes)
 * Body: 0x0800A388-0x0800A39B
 * --------------------------------------------------------------------- */
void FUN_0800a388(int param_1,int param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + param_2) = param_3;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800a39c   (0x0800A39C, 27 Bytes)
 * Body: 0x0800A39C-0x0800A3B7
 * --------------------------------------------------------------------- */
uint FUN_0800a39c(int param_1,int param_2)

{
  return *(uint *)(param_2 + 0x28 + param_1) & 0xffff;
}


/* ---------------------------------------------------------------------
 * FUN_0800a3b6   (0x0800A3B6, 1 Bytes)
 * Body: 0x0800A3B6-0x0800A3B7
 * --------------------------------------------------------------------- */
void FUN_0800a3b6(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800a450   (0x0800A450, 3 Bytes)
 * Body: 0x0800A450-0x0800A453
 * --------------------------------------------------------------------- */
bool FUN_0800a450(uint *param_1,uint param_2)

{
  return (*param_1 & param_2) != 0;
}


/* ---------------------------------------------------------------------
 * FUN_0800a454   (0x0800A454, 17 Bytes)
 * Body: 0x0800A454-0x0800A465
 * --------------------------------------------------------------------- */
bool FUN_0800a454(uint *param_1,uint param_2)

{
  return (*param_1 & param_2) != 0;
}


/* ---------------------------------------------------------------------
 * FUN_0800a466   (0x0800A466, 7 Bytes)
 * Body: 0x0800A466-0x0800A46D
 * --------------------------------------------------------------------- */
void FUN_0800a466(uint *param_1,uint param_2)

{
  *param_1 = ~param_2 & 0x7f;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800a46e   (0x0800A46E, 35 Bytes)
 * Body: 0x0800A46E-0x0800A491
 * --------------------------------------------------------------------- */
undefined4 FUN_0800a46e(uint *param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (((*param_1 & (int)param_2 >> 8) == 0) || ((param_1[1] & param_2 & 0xff) == 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


/* ---------------------------------------------------------------------
 * FUN_0800a490   (0x0800A490, 1 Bytes)
 * Body: 0x0800A490-0x0800A491
 * --------------------------------------------------------------------- */
void FUN_0800a490(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800a51a   (0x0800A51A, 17 Bytes)
 * Body: 0x0800A51A-0x0800A52B
 * --------------------------------------------------------------------- */
bool FUN_0800a51a(int param_1,uint param_2)

{
  return (*(uint *)(param_1 + 0x58) & param_2) != 0;
}


/* ---------------------------------------------------------------------
 * FUN_0800a534   (0x0800A534, 8 Bytes, 2 Teile)
 * Body: 0x0800A534-0x0800A539, 0x0800A53E-0x0800A541
 * --------------------------------------------------------------------- */
void FUN_0800a534(int param_1,uint param_2)

{
  *(uint *)(param_1 + 0x58) = param_2 | 0x80;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800a540   (0x0800A540, 1 Bytes)
 * Body: 0x0800A540-0x0800A541
 * --------------------------------------------------------------------- */
void FUN_0800a540(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800a552   (0x0800A552, 41 Bytes)
 * Body: 0x0800A552-0x0800A57B
 * --------------------------------------------------------------------- */
void FUN_0800a552(int param_1,uint param_2)

{
  if (param_1 == 0) {
    FUN_08007e62(0x100,0);
    FUN_08007e80(param_2);
  }
  else {
    FUN_08007e62(param_2,1);
    FUN_08007e80(0);
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800a57c   (0x0800A57C, 23 Bytes)
 * Body: 0x0800A57C-0x0800A593
 * --------------------------------------------------------------------- */
void FUN_0800a57c(void)

{
  FUN_08008232(0x2000000,1);
  FUN_08008232(0x2000000,0);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800a594   (0x0800A594, 275 Bytes)
 * Body: 0x0800A594-0x0800A6A7
 * --------------------------------------------------------------------- */
undefined4 FUN_0800a594(uint *param_1,ushort *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  *param_1 = *param_1 & 0xfffffffd;
  *param_1 = *param_1 | 1;
  for (iVar2 = 0; ((param_1[1] & 1) == 0 && (iVar2 != 0xffff)); iVar2 = iVar2 + 1) {
  }
  if ((param_1[1] & 1) == 0) {
    uVar1 = 0;
  }
  else {
    if ((char)param_2[3] == '\x01') {
      *param_1 = *param_1 | 0x80;
    }
    else {
      *param_1 = *param_1 & 0xffffff7f;
    }
    if (*(char *)((int)param_2 + 7) == '\x01') {
      *param_1 = *param_1 | 0x40;
    }
    else {
      *param_1 = *param_1 & 0xffffffbf;
    }
    if ((char)param_2[4] == '\x01') {
      *param_1 = *param_1 | 0x20;
    }
    else {
      *param_1 = *param_1 & 0xffffffdf;
    }
    if (*(char *)((int)param_2 + 9) == '\x01') {
      *param_1 = *param_1 | 0x10;
    }
    else {
      *param_1 = *param_1 & 0xffffffef;
    }
    if ((char)param_2[5] == '\x01') {
      *param_1 = *param_1 | 8;
    }
    else {
      *param_1 = *param_1 & 0xfffffff7;
    }
    if (*(char *)((int)param_2 + 0xb) == '\x01') {
      *param_1 = *param_1 | 4;
    }
    else {
      *param_1 = *param_1 & 0xfffffffb;
    }
    param_1[7] = (uint)(byte)param_2[1] << 0x1e | (uint)*(byte *)((int)param_2 + 3) << 0x18 |
                 (uint)(byte)param_2[2] << 0x10 | (uint)*(byte *)((int)param_2 + 5) << 0x14 |
                 *param_2 - 1;
    *param_1 = *param_1 & 0xfffffffe;
    for (iVar2 = 0; ((param_1[1] & 1) != 0 && (iVar2 != 0xffff)); iVar2 = iVar2 + 1) {
    }
    if ((param_1[1] & 1) == 0) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}


/* ---------------------------------------------------------------------
 * FUN_0800a6a8   (0x0800A6A8, 257 Bytes)
 * Body: 0x0800A6A8-0x0800A7A9
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0800a6a8(undefined2 *param_1)

{
  uint uVar1;
  
  uVar1 = 1 << *(sbyte *)(param_1 + 5);
  _DAT_4000661c = _DAT_4000661c & ~uVar1;
  if (*(char *)(param_1 + 6) == '\0') {
    _DAT_4000660c = _DAT_4000660c & ~uVar1;
    *(uint *)((uint)*(byte *)(param_1 + 5) * 8 + 0x40006640) = CONCAT22(param_1[3],param_1[1]);
    *(uint *)((uint)*(byte *)(param_1 + 5) * 8 + 0x40006644) = CONCAT22(param_1[2],*param_1);
  }
  if (*(char *)(param_1 + 6) == '\x01') {
    _DAT_4000660c = _DAT_4000660c | uVar1;
    *(uint *)((uint)*(byte *)(param_1 + 5) * 8 + 0x40006640) = CONCAT22(*param_1,param_1[1]);
    *(uint *)((uint)*(byte *)(param_1 + 5) * 8 + 0x40006644) = CONCAT22(param_1[2],param_1[3]);
  }
  if (*(char *)((int)param_1 + 0xb) == '\0') {
    _DAT_40006604 = _DAT_40006604 & ~uVar1;
  }
  else {
    _DAT_40006604 = _DAT_40006604 | uVar1;
  }
  if (param_1[4] == 0) {
    _DAT_40006614 = _DAT_40006614 & ~uVar1;
  }
  if (param_1[4] == 1) {
    _DAT_40006614 = _DAT_40006614 | uVar1;
  }
  if (*(char *)((int)param_1 + 0xd) == '\x01') {
    _DAT_4000661c = _DAT_4000661c | uVar1;
  }
  _DAT_40006600 = _DAT_40006600 & 0xfffffffe;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800a7aa   (0x0800A7AA, 31 Bytes)
 * Body: 0x0800A7AA-0x0800A7C9
 * --------------------------------------------------------------------- */
void FUN_0800a7aa(undefined2 *param_1)

{
  *(undefined1 *)(param_1 + 3) = 0;
  *(undefined1 *)((int)param_1 + 7) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  *(undefined1 *)((int)param_1 + 9) = 0;
  *(undefined1 *)(param_1 + 5) = 0;
  *(undefined1 *)((int)param_1 + 0xb) = 0;
  *(undefined1 *)(param_1 + 1) = 0;
  *(undefined1 *)((int)param_1 + 3) = 0;
  *(undefined1 *)(param_1 + 2) = 3;
  *(undefined1 *)((int)param_1 + 5) = 2;
  *param_1 = 1;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800a7c8   (0x0800A7C8, 1 Bytes)
 * Body: 0x0800A7C8-0x0800A7C9
 * --------------------------------------------------------------------- */
void FUN_0800a7c8(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800a856   (0x0800A856, 293 Bytes)
 * Body: 0x0800A856-0x0800A97B
 * --------------------------------------------------------------------- */
void FUN_0800a856(int param_1,ushort *param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if ((*(uint *)(param_1 + 8) & 0x4000000) != 0x4000000) {
    if ((*(uint *)(param_1 + 8) & 0x8000000) == 0x8000000) {
      iVar1 = 1;
    }
    else if ((*(uint *)(param_1 + 8) & 0x10000000) == 0x10000000) {
      iVar1 = 2;
    }
    else {
      iVar1 = 4;
    }
  }
  if (iVar1 != 4) {
    *(uint *)(param_1 + 0x180 + iVar1 * 0x10) = *(uint *)(param_1 + 0x180 + iVar1 * 0x10) & 1;
    if ((char)param_2[4] == '\0') {
      *(uint *)(param_1 + 0x180 + iVar1 * 0x10) =
           (uint)*(byte *)((int)param_2 + 9) | (uint)*param_2 << 0x15 |
           *(uint *)(param_1 + 0x180 + iVar1 * 0x10);
    }
    else {
      *(uint *)(param_1 + 0x180 + iVar1 * 0x10) =
           (uint)(byte)param_2[4] | *(int *)(param_2 + 2) << 3 | (uint)*(byte *)((int)param_2 + 9) |
           *(uint *)(param_1 + 0x180 + iVar1 * 0x10);
    }
    *(byte *)(param_2 + 5) = (byte)param_2[5] & 0xf;
    *(uint *)(param_1 + iVar1 * 0x10 + 0x184) =
         *(uint *)(param_1 + iVar1 * 0x10 + 0x184) & 0xfffffff0;
    *(uint *)(param_1 + iVar1 * 0x10 + 0x184) =
         *(uint *)(param_1 + iVar1 * 0x10 + 0x184) | (uint)(byte)param_2[5];
    *(uint *)(param_1 + iVar1 * 0x10 + 0x188) =
         (uint)(byte)param_2[7] << 0x18 | (uint)*(byte *)((int)param_2 + 0xd) << 0x10 |
         (uint)(byte)param_2[6] << 8 | (uint)*(byte *)((int)param_2 + 0xb);
    *(uint *)(param_1 + iVar1 * 0x10 + 0x18c) =
         (uint)(byte)param_2[9] << 0x18 | (uint)*(byte *)((int)param_2 + 0x11) << 0x10 |
         (uint)(byte)param_2[8] << 8 | (uint)*(byte *)((int)param_2 + 0xf);
    *(uint *)(param_1 + 0x180 + iVar1 * 0x10) = *(uint *)(param_1 + 0x180 + iVar1 * 0x10) | 1;
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800a97c   (0x0800A97C, 137 Bytes)
 * Body: 0x0800A97C-0x0800AA05
 * --------------------------------------------------------------------- */
undefined1 FUN_0800a97c(int param_1,int param_2)

{
  undefined *puVar1;
  
  if (param_2 == 0) {
    puVar1 = (undefined *)(*(uint *)(param_1 + 8) & 0x4000003);
  }
  else if (param_2 == 1) {
    puVar1 = (undefined *)(*(uint *)(param_1 + 8) & 0x8000300);
  }
  else if (param_2 == 2) {
    puVar1 = (undefined *)(*(uint *)(param_1 + 8) & 0x10030000);
  }
  else {
    puVar1 = (undefined *)0x0;
  }
  if (puVar1 == (undefined *)0x8000100) {
    return 0;
  }
  if (puVar1 < (undefined *)0x8000101) {
    if (puVar1 == (undefined *)0x0) {
      return 2;
    }
    if (puVar1 == (undefined *)0x4000001) {
      return 0;
    }
    if (puVar1 == (undefined *)0x4000003) {
      return 1;
    }
  }
  else {
    if (puVar1 == &UNK_08000300) {
      return 1;
    }
    if (puVar1 == (undefined *)0x10010000) {
      return 0;
    }
    if (puVar1 == (undefined *)0x10030000) {
      return 1;
    }
  }
  return 0;
}


/* ---------------------------------------------------------------------
 * FUN_0800aa06   (0x0800AA06, 47 Bytes)
 * Body: 0x0800AA06-0x0800AA35
 * --------------------------------------------------------------------- */
void FUN_0800aa06(int param_1,int param_2)

{
  if (param_2 == 0) {
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | 0x80;
  }
  else if (param_2 == 1) {
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | 0x8000;
  }
  else if (param_2 == 2) {
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | 0x800000;
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800aa36   (0x0800AA36, 240 Bytes, 2 Teile)
 * Body: 0x0800AA36-0x0800AAAF, 0x0800AAC8-0x0800AB3F
 * --------------------------------------------------------------------- */
void FUN_0800aa36(int param_1,int param_2,uint *param_3)

{
  *(byte *)(param_3 + 2) = (byte)*(undefined4 *)(param_1 + 0x1b0 + param_2 * 0x10) & 4;
  if ((char)param_3[2] == '\0') {
    *param_3 = *(uint *)(param_1 + 0x1b0 + param_2 * 0x10) >> 0x15;
  }
  else {
    param_3[1] = *(uint *)(param_1 + 0x1b0 + param_2 * 0x10) >> 3;
  }
  *(byte *)((int)param_3 + 9) = (byte)*(undefined4 *)(param_1 + 0x1b0 + param_2 * 0x10) & 2;
  *(byte *)((int)param_3 + 10) = (byte)*(undefined4 *)(param_1 + param_2 * 0x10 + 0x1b4) & 0xf;
  *(char *)((int)param_3 + 0x13) =
       (char)((uint)*(undefined4 *)(param_1 + param_2 * 0x10 + 0x1b4) >> 8);
  *(char *)((int)param_3 + 0xb) = (char)*(undefined4 *)(param_1 + param_2 * 0x10 + 0x1b8);
  *(char *)(param_3 + 3) = (char)((uint)*(undefined4 *)(param_1 + param_2 * 0x10 + 0x1b8) >> 8);
  *(char *)((int)param_3 + 0xd) =
       (char)((uint)*(undefined4 *)(param_1 + param_2 * 0x10 + 0x1b8) >> 0x10);
  *(char *)((int)param_3 + 0xe) =
       (char)((uint)*(undefined4 *)(param_1 + param_2 * 0x10 + 0x1b8) >> 0x18);
  *(char *)((int)param_3 + 0xf) = (char)*(undefined4 *)(param_1 + param_2 * 0x10 + 0x1bc);
  *(char *)(param_3 + 4) = (char)((uint)*(undefined4 *)(param_1 + param_2 * 0x10 + 0x1bc) >> 8);
  *(char *)((int)param_3 + 0x11) =
       (char)((uint)*(undefined4 *)(param_1 + param_2 * 0x10 + 0x1bc) >> 0x10);
  *(char *)((int)param_3 + 0x12) =
       (char)((uint)*(undefined4 *)(param_1 + param_2 * 0x10 + 0x1bc) >> 0x18);
  if (param_2 == 0) {
    *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 0x20;
  }
  else {
    *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 0x20;
  }
  return;
}


/* ---------------------------------------------------------------------
 * thunk_FUN_0800aac8   (0x0800AAAE, 1 Bytes)
 * Body: 0x0800AAAE-0x0800AAAF
 * --------------------------------------------------------------------- */
void thunk_FUN_0800aac8(int param_1,int param_2,int param_3,undefined1 param_4)

{
  *(undefined1 *)(param_3 + 0xb) = param_4;
  *(char *)(param_3 + 0xc) = (char)((uint)*(undefined4 *)(param_1 + param_2 * 0x10 + 0x1b8) >> 8);
  *(char *)(param_3 + 0xd) = (char)((uint)*(undefined4 *)(param_1 + param_2 * 0x10 + 0x1b8) >> 0x10)
  ;
  *(char *)(param_3 + 0xe) = (char)((uint)*(undefined4 *)(param_1 + param_2 * 0x10 + 0x1b8) >> 0x18)
  ;
  *(char *)(param_3 + 0xf) = (char)*(undefined4 *)(param_1 + param_2 * 0x10 + 0x1bc);
  *(char *)(param_3 + 0x10) = (char)((uint)*(undefined4 *)(param_1 + param_2 * 0x10 + 0x1bc) >> 8);
  *(char *)(param_3 + 0x11) =
       (char)((uint)*(undefined4 *)(param_1 + param_2 * 0x10 + 0x1bc) >> 0x10);
  *(char *)(param_3 + 0x12) =
       (char)((uint)*(undefined4 *)(param_1 + param_2 * 0x10 + 0x1bc) >> 0x18);
  if (param_2 == 0) {
    *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 0x20;
  }
  else {
    *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 0x20;
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800aac8   (0x0800AAC8, 119 Bytes)
 * Body: 0x0800AAC8-0x0800AB3F
 * --------------------------------------------------------------------- */
void FUN_0800aac8(int param_1,int param_2,int param_3,undefined1 param_4)

{
  *(undefined1 *)(param_3 + 0xb) = param_4;
  *(char *)(param_3 + 0xc) = (char)((uint)*(undefined4 *)(param_1 + param_2 * 0x10 + 0x1b8) >> 8);
  *(char *)(param_3 + 0xd) = (char)((uint)*(undefined4 *)(param_1 + param_2 * 0x10 + 0x1b8) >> 0x10)
  ;
  *(char *)(param_3 + 0xe) = (char)((uint)*(undefined4 *)(param_1 + param_2 * 0x10 + 0x1b8) >> 0x18)
  ;
  *(char *)(param_3 + 0xf) = (char)*(undefined4 *)(param_1 + param_2 * 0x10 + 0x1bc);
  *(char *)(param_3 + 0x10) = (char)((uint)*(undefined4 *)(param_1 + param_2 * 0x10 + 0x1bc) >> 8);
  *(char *)(param_3 + 0x11) =
       (char)((uint)*(undefined4 *)(param_1 + param_2 * 0x10 + 0x1bc) >> 0x10);
  *(char *)(param_3 + 0x12) =
       (char)((uint)*(undefined4 *)(param_1 + param_2 * 0x10 + 0x1bc) >> 0x18);
  if (param_2 == 0) {
    *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 0x20;
  }
  else {
    *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 0x20;
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800ab40   (0x0800AB40, 21 Bytes)
 * Body: 0x0800AB40-0x0800AB55
 * --------------------------------------------------------------------- */
void FUN_0800ab40(int param_1,int param_2)

{
  if (param_2 == 0) {
    *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 0x20;
  }
  else {
    *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 0x20;
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800ab5a   (0x0800AB5A, 25 Bytes)
 * Body: 0x0800AB5A-0x0800AB73
 * --------------------------------------------------------------------- */
uint FUN_0800ab5a(undefined4 param_1,int param_2,int param_3)

{
  uint uVar1;
  
  if (param_2 == 0) {
    uVar1 = *(uint *)(param_3 + 0xc) & 3;
  }
  else if (param_2 == 1) {
    uVar1 = *(uint *)(param_3 + 0x10) & 3;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


/* ---------------------------------------------------------------------
 * FUN_0800ab74   (0x0800AB74, 161 Bytes)
 * Body: 0x0800AB74-0x0800AC15
 * --------------------------------------------------------------------- */
undefined4 FUN_0800ab74(uint *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = 0xffff;
  if (param_2 == 0) {
    *param_1 = *param_1 & 0xfffffffd | 1;
    for (; ((param_1[1] & 3) != 1 && (iVar2 != 0)); iVar2 = iVar2 + -1) {
    }
    if ((param_1[1] & 3) == 1) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else if (param_2 == 1) {
    *param_1 = *param_1 & 0xfffffffc;
    for (; ((param_1[1] & 3) != 0 && (iVar2 != 0)); iVar2 = iVar2 + -1) {
    }
    if ((param_1[1] & 3) == 0) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else if (param_2 == 2) {
    *param_1 = *param_1 & 0xfffffffe | 2;
    for (; ((param_1[1] & 3) != 2 && (iVar2 != 0)); iVar2 = iVar2 + -1) {
    }
    if ((param_1[1] & 3) == 2) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


/* ---------------------------------------------------------------------
 * FUN_0800ac14   (0x0800AC14, 1 Bytes)
 * Body: 0x0800AC14-0x0800AC15
 * --------------------------------------------------------------------- */
void FUN_0800ac14(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800ac86   (0x0800AC86, 17 Bytes)
 * Body: 0x0800AC86-0x0800AC97
 * --------------------------------------------------------------------- */
void FUN_0800ac86(int param_1,uint param_2,int param_3)

{
  if (param_3 == 0) {
    *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) & ~param_2;
  }
  else {
    *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | param_2;
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800ac98   (0x0800AC98, 119 Bytes)
 * Body: 0x0800AC98-0x0800AD0F
 * --------------------------------------------------------------------- */
undefined4 FUN_0800ac98(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  if ((param_2 & 0xf00000) == 0) {
    if ((param_2 & 0x1000000) == 0) {
      if ((param_2 & 0x8000000) == 0) {
        if ((param_2 & 0x2000000) == 0) {
          if ((*(uint *)(param_1 + 0x10) & param_2 & 0xfffff) == 0) {
            uVar1 = 0;
          }
          else {
            uVar1 = 1;
          }
        }
        else if ((*(uint *)(param_1 + 0xc) & param_2 & 0xfffff) == 0) {
          uVar1 = 0;
        }
        else {
          uVar1 = 1;
        }
      }
      else if ((*(uint *)(param_1 + 8) & param_2 & 0xfffff) == 0) {
        uVar1 = 0;
      }
      else {
        uVar1 = 1;
      }
    }
    else if ((*(uint *)(param_1 + 4) & param_2 & 0xfffff) == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  else if ((*(uint *)(param_1 + 0x18) & param_2 & 0xfffff) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


/* ---------------------------------------------------------------------
 * FUN_0800ad10   (0x0800AD10, 51 Bytes)
 * Body: 0x0800AD10-0x0800AD43
 * --------------------------------------------------------------------- */
void FUN_0800ad10(int param_1,uint param_2)

{
  uint uVar1;
  
  if (param_2 == 0x30f00070) {
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  else {
    uVar1 = param_2 & 0xfffff;
    if ((param_2 & 0x2000000) == 0) {
      if ((param_2 & 0x4000000) == 0) {
        if ((param_2 & 0x8000000) == 0) {
          *(uint *)(param_1 + 4) = uVar1;
        }
        else {
          *(uint *)(param_1 + 8) = uVar1;
        }
      }
      else {
        *(uint *)(param_1 + 0x10) = uVar1;
      }
    }
    else {
      *(uint *)(param_1 + 0xc) = uVar1;
    }
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800ad44   (0x0800AD44, 17 Bytes)
 * Body: 0x0800AD44-0x0800AD55
 * --------------------------------------------------------------------- */
bool FUN_0800ad44(uint param_1,uint param_2)

{
  return (param_1 & param_2) != 0;
}


/* ---------------------------------------------------------------------
 * FUN_0800ad56   (0x0800AD56, 280 Bytes, 2 Teile)
 * Body: 0x0800AD56-0x0800AE63, 0x0800AE66-0x0800AE71
 * --------------------------------------------------------------------- */
bool FUN_0800ad56(int param_1,uint param_2)

{
  bool bVar1;
  
  if ((*(uint *)(param_1 + 0x14) & param_2) == 0) {
    bVar1 = false;
  }
  else if (param_2 == 0x100) {
    bVar1 = FUN_0800ad44(*(uint *)(param_1 + 0x18),1);
  }
  else {
    if ((int)param_2 < 0x101) {
      if (param_2 == 8) {
        bVar1 = FUN_0800ad44(*(uint *)(param_1 + 0xc),0x10);
        return bVar1;
      }
      if ((int)param_2 < 9) {
        if (param_2 == 1) {
          bVar1 = FUN_0800ad44(*(uint *)(param_1 + 8),0x10101);
          return bVar1;
        }
        if (param_2 == 2) {
          bVar1 = FUN_0800ad44(*(uint *)(param_1 + 0xc),3);
          return bVar1;
        }
        if (param_2 == 4) {
          bVar1 = FUN_0800ad44(*(uint *)(param_1 + 0xc),8);
          return bVar1;
        }
      }
      else {
        if (param_2 == 0x10) {
          bVar1 = FUN_0800ad44(*(uint *)(param_1 + 0x10),3);
          return bVar1;
        }
        if (param_2 == 0x20) {
          bVar1 = FUN_0800ad44(*(uint *)(param_1 + 0x10),8);
          return bVar1;
        }
        if (param_2 == 0x40) {
          bVar1 = FUN_0800ad44(*(uint *)(param_1 + 0x10),0x10);
          return bVar1;
        }
      }
    }
    else {
      if (param_2 == 0x8000) {
        bVar1 = FUN_0800ad44(*(uint *)(param_1 + 4),4);
        return bVar1;
      }
      if ((int)param_2 < 0x8001) {
        if (param_2 == 0x200) {
          bVar1 = FUN_0800ad44(*(uint *)(param_1 + 0x18),2);
          return bVar1;
        }
        if (param_2 == 0x400) {
          bVar1 = FUN_0800ad44(*(uint *)(param_1 + 0x18),4);
          return bVar1;
        }
        if (param_2 == 0x800) {
          bVar1 = FUN_0800ad44(*(uint *)(param_1 + 0x18),0x70);
          return bVar1;
        }
      }
      else {
        if (param_2 == 0x10000) {
          bVar1 = FUN_0800ad44(*(uint *)(param_1 + 4),8);
          return bVar1;
        }
        if (param_2 == 0x20000) {
          bVar1 = FUN_0800ad44(*(uint *)(param_1 + 4),0x10);
          return bVar1;
        }
      }
    }
    bVar1 = false;
  }
  return bVar1;
}


/* ---------------------------------------------------------------------
 * FUN_0800ae70   (0x0800AE70, 1 Bytes)
 * Body: 0x0800AE70-0x0800AE71
 * --------------------------------------------------------------------- */
void FUN_0800ae70(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800af1c   (0x0800AF1C, 49 Bytes)
 * Body: 0x0800AF1C-0x0800AF4D
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0800af1c(int param_1)

{
  if (param_1 == _FUN_0800b300) {
    FUN_08008232(0x200000,1);
    FUN_08008232(0x200000,0);
  }
  else {
    FUN_08008232(0x400000,1);
    FUN_08008232(0x400000,0);
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800af4e   (0x0800AF4E, 221 Bytes)
 * Body: 0x0800AF4E-0x0800B02B
 * --------------------------------------------------------------------- */
void FUN_0800af4e(ushort *param_1,uint *param_2)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  uint auStack_34 [2];
  uint local_2c;
  
  uVar2 = param_1[2];
  FUN_0800809c(auStack_34);
  uVar1 = (ushort)(local_2c / 1000000);
  param_1[2] = uVar2 & 0xffc0 | uVar1;
  *param_1 = *param_1 & 0xfffe;
  if (*param_2 < 0x186a1) {
    local_2c = local_2c / (*param_2 << 1);
    uVar2 = (ushort)local_2c;
    if ((local_2c & 0xffff) < 4) {
      uVar2 = 4;
    }
    param_1[0x10] = uVar1 + 1;
  }
  else {
    if (*(short *)((int)param_2 + 6) == -0x4001) {
      uVar3 = local_2c / (*param_2 * 3) & 0xffff;
    }
    else {
      uVar3 = local_2c / (*param_2 * 0x19) & 0xffff | 0x4000;
    }
    uVar2 = (ushort)uVar3;
    if ((uVar3 & 0xfff) == 0) {
      uVar2 = uVar2 | 1;
    }
    uVar2 = uVar2 | 0x8000;
    param_1[0x10] = (short)(((local_2c / 1000000) * 300) / 1000) + 1;
  }
  param_1[0xe] = uVar2;
  *param_1 = *param_1 | 1;
  *param_1 = *param_1 & 0xfbf5 | (ushort)param_2[1] | *(ushort *)((int)param_2 + 10);
  param_1[4] = (ushort)param_2[3] | (ushort)param_2[2];
  return;
}



/* =====================================================================
 *  SEKTION: 0x0800B000 - Interrupt-Handler & BLE-AT-Schicht
 * ===================================================================== */

/* ---------------------------------------------------------------------
 * FUN_0800b04a   (0x0800B04A, 23 Bytes)
 * Body: 0x0800B04A-0x0800B061
 * --------------------------------------------------------------------- */
void FUN_0800b04a(ushort *param_1,int param_2)

{
  if (param_2 == 0) {
    *param_1 = *param_1 & 0xfffe;
  }
  else {
    *param_1 = *param_1 | 1;
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800b062   (0x0800B062, 23 Bytes)
 * Body: 0x0800B062-0x0800B079
 * --------------------------------------------------------------------- */
void FUN_0800b062(int param_1,int param_2)

{
  if (param_2 == 0) {
    *(ushort *)(param_1 + 4) = *(ushort *)(param_1 + 4) & 0xf7ff;
  }
  else {
    *(ushort *)(param_1 + 4) = *(ushort *)(param_1 + 4) | 0x800;
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800b078   (0x0800B078, 1 Bytes)
 * Body: 0x0800B078-0x0800B079
 * --------------------------------------------------------------------- */
void FUN_0800b078(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800b092   (0x0800B092, 23 Bytes)
 * Body: 0x0800B092-0x0800B0A9
 * --------------------------------------------------------------------- */
void FUN_0800b092(ushort *param_1,int param_2)

{
  if (param_2 == 0) {
    *param_1 = *param_1 & 0xfeff;
  }
  else {
    *param_1 = *param_1 | 0x100;
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800b0aa   (0x0800B0AA, 23 Bytes)
 * Body: 0x0800B0AA-0x0800B0C1
 * --------------------------------------------------------------------- */
void FUN_0800b0aa(ushort *param_1,int param_2)

{
  if (param_2 == 0) {
    *param_1 = *param_1 & 0xfdff;
  }
  else {
    *param_1 = *param_1 | 0x200;
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800b0c2   (0x0800B0C2, 23 Bytes)
 * Body: 0x0800B0C2-0x0800B0D9
 * --------------------------------------------------------------------- */
void FUN_0800b0c2(ushort *param_1,int param_2)

{
  if (param_2 == 0) {
    *param_1 = *param_1 & 0xfbff;
  }
  else {
    *param_1 = *param_1 | 0x400;
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800b0d8   (0x0800B0D8, 1 Bytes)
 * Body: 0x0800B0D8-0x0800B0D9
 * --------------------------------------------------------------------- */
void FUN_0800b0d8(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800b120   (0x0800B120, 17 Bytes)
 * Body: 0x0800B120-0x0800B131
 * --------------------------------------------------------------------- */
void FUN_0800b120(int param_1,ushort param_2,int param_3)

{
  if (param_3 == 0) {
    *(ushort *)(param_1 + 4) = *(ushort *)(param_1 + 4) & ~param_2;
  }
  else {
    *(ushort *)(param_1 + 4) = *(ushort *)(param_1 + 4) | param_2;
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800b132   (0x0800B132, 3 Bytes)
 * Body: 0x0800B132-0x0800B135
 * --------------------------------------------------------------------- */
void FUN_0800b132(int param_1,undefined2 param_2)

{
  *(undefined2 *)(param_1 + 0x10) = param_2;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800b136   (0x0800B136, 7 Bytes)
 * Body: 0x0800B136-0x0800B13D
 * --------------------------------------------------------------------- */
undefined1 FUN_0800b136(int param_1)

{
  return (char)*(undefined2 *)(param_1 + 0x10);
}


/* ---------------------------------------------------------------------
 * FUN_0800b13e   (0x0800B13E, 17 Bytes)
 * Body: 0x0800B13E-0x0800B14F
 * --------------------------------------------------------------------- */
void FUN_0800b13e(int param_1,ushort param_2,int param_3)

{
  ushort uVar1;
  
  if (param_3 == 0) {
    uVar1 = param_2 & 0xfffe;
  }
  else {
    uVar1 = param_2 | 1;
  }
  *(ushort *)(param_1 + 0x10) = uVar1;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800b150   (0x0800B150, 21 Bytes)
 * Body: 0x0800B150-0x0800B165
 * --------------------------------------------------------------------- */
undefined2 FUN_0800b150(int param_1,int param_2)

{
  return *(undefined2 *)(param_1 + param_2);
}


/* ---------------------------------------------------------------------
 * FUN_0800b180   (0x0800B180, 23 Bytes)
 * Body: 0x0800B180-0x0800B197
 * --------------------------------------------------------------------- */
void FUN_0800b180(ushort *param_1)

{
  char in_ZR;
  
  if (in_ZR == '\0') {
    *param_1 = *param_1 & 0xf7ff;
  }
  else {
    *param_1 = *param_1 | 0x800;
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800b254   (0x0800B254, 41 Bytes)
 * Body: 0x0800B254-0x0800B27D
 * --------------------------------------------------------------------- */
bool FUN_0800b254(int param_1,uint param_2)

{
  return (CONCAT22(*(undefined2 *)(param_1 + 0x18),*(undefined2 *)(param_1 + 0x14)) & 0xffffff &
         param_2) == param_2;
}


/* ---------------------------------------------------------------------
 * FUN_0800b27e   (0x0800B27E, 25 Bytes)
 * Body: 0x0800B27E-0x0800B297
 * --------------------------------------------------------------------- */
uint FUN_0800b27e(int param_1)

{
  return CONCAT22(*(undefined2 *)(param_1 + 0x18),*(undefined2 *)(param_1 + 0x14)) & 0xffffff;
}


/* ---------------------------------------------------------------------
 * FUN_0800b298   (0x0800B298, 57 Bytes)
 * Body: 0x0800B298-0x0800B2D1
 * --------------------------------------------------------------------- */
bool FUN_0800b298(int param_1,uint param_2)

{
  uint uVar1;
  uint *local_c;
  
  uVar1 = param_2 & 0xffffff;
  if (param_2 >> 0x1c == 0) {
    uVar1 = uVar1 >> 0x10;
    local_c = (uint *)(param_1 + 0x18);
  }
  else {
    local_c = (uint *)(param_1 + 0x14);
  }
  return (*local_c & uVar1) != 0;
}


/* ---------------------------------------------------------------------
 * FUN_0800b2d2   (0x0800B2D2, 11 Bytes)
 * Body: 0x0800B2D2-0x0800B2DD
 * --------------------------------------------------------------------- */
void FUN_0800b2d2(int param_1,ushort param_2)

{
  *(ushort *)(param_1 + 0x14) = ~param_2;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800b2de   (0x0800B2DE, 33 Bytes)
 * Body: 0x0800B2DE-0x0800B2FF
 * --------------------------------------------------------------------- */
undefined4 FUN_0800b2de(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  if ((((uint)*(ushort *)(param_1 + 0x14) & param_2 & 0xffffff) == 0) ||
     (((uint)*(ushort *)(param_1 + 4) & (param_2 & 0x7000000) >> 0x10) == 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


/* ---------------------------------------------------------------------
 * FUN_0800b300   (0x0800B300, 19 Bytes)
 * Body: 0x0800B300-0x0800B313
 * --------------------------------------------------------------------- */
longlong FUN_0800b300(int param_1)

{
  int unaff_r4;
  
  *(char *)(param_1 * 2) = (char)param_1;
  *(short *)(unaff_r4 + 0x34) = (short)-(param_1 >> 8);
  return (ulonglong)(uint)-(param_1 >> 8) << 0x20;
}


/* ---------------------------------------------------------------------
 * FUN_0800b312   (0x0800B312, 1 Bytes)
 * Body: 0x0800B312-0x0800B313
 * --------------------------------------------------------------------- */
void FUN_0800b312(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800b458   (0x0800B458, 23 Bytes)
 * Body: 0x0800B458-0x0800B46F
 * --------------------------------------------------------------------- */
void FUN_0800b458(uint *param_1,int param_2)

{
  if (param_2 == 0) {
    *param_1 = *param_1 & 0xfffe;
  }
  else {
    *param_1 = *param_1 | 1;
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800b46e   (0x0800B46E, 1 Bytes)
 * Body: 0x0800B46E-0x0800B46F
 * --------------------------------------------------------------------- */
void FUN_0800b46e(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800b48e   (0x0800B48E, 23 Bytes)
 * Body: 0x0800B48E-0x0800B4A5
 * --------------------------------------------------------------------- */
bool FUN_0800b48e(uint param_1,uint *param_2)

{
  return (*param_2 & param_1) != 0;
}


/* ---------------------------------------------------------------------
 * FUN_0800b4a6   (0x0800B4A6, 3 Bytes)
 * Body: 0x0800B4A6-0x0800B4A9
 * --------------------------------------------------------------------- */
void FUN_0800b4a6(undefined4 param_1,int param_2)

{
  *(undefined4 *)(param_2 + 4) = param_1;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800b4aa   (0x0800B4AA, 23 Bytes)
 * Body: 0x0800B4AA-0x0800B4C1
 * --------------------------------------------------------------------- */
bool FUN_0800b4aa(uint param_1,uint *param_2)

{
  return (*param_2 & param_1) != 0;
}


/* ---------------------------------------------------------------------
 * FUN_0800b4c0   (0x0800B4C0, 1 Bytes)
 * Body: 0x0800B4C0-0x0800B4C1
 * --------------------------------------------------------------------- */
void FUN_0800b4c0(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800b4d8   (0x0800B4D8, 1 Bytes)
 * Body: 0x0800B4D8-0x0800B4D9
 * --------------------------------------------------------------------- */
void FUN_0800b4d8(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * thunk_FUN_0800b4dc   (0x0800B4DA, 1 Bytes)
 * Body: 0x0800B4DA-0x0800B4DB
 * --------------------------------------------------------------------- */
void thunk_FUN_0800b4dc(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


/* ---------------------------------------------------------------------
 * FUN_0800b4dc   (0x0800B4DC, 1 Bytes)
 * Body: 0x0800B4DC-0x0800B4DD
 * --------------------------------------------------------------------- */
void FUN_0800b4dc(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


/* ---------------------------------------------------------------------
 * thunk_FUN_0800b4e0   (0x0800B4DE, 1 Bytes)
 * Body: 0x0800B4DE-0x0800B4DF
 * --------------------------------------------------------------------- */
void thunk_FUN_0800b4e0(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


/* ---------------------------------------------------------------------
 * FUN_0800b4e0   (0x0800B4E0, 1 Bytes)
 * Body: 0x0800B4E0-0x0800B4E1
 * --------------------------------------------------------------------- */
void FUN_0800b4e0(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


/* ---------------------------------------------------------------------
 * thunk_FUN_0800b4e4   (0x0800B4E2, 1 Bytes)
 * Body: 0x0800B4E2-0x0800B4E3
 * --------------------------------------------------------------------- */
void thunk_FUN_0800b4e4(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


/* ---------------------------------------------------------------------
 * FUN_0800b4e4   (0x0800B4E4, 1 Bytes)
 * Body: 0x0800B4E4-0x0800B4E5
 * --------------------------------------------------------------------- */
void FUN_0800b4e4(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


/* ---------------------------------------------------------------------
 * thunk_FUN_0800b4e8   (0x0800B4E6, 1 Bytes)
 * Body: 0x0800B4E6-0x0800B4E7
 * --------------------------------------------------------------------- */
void thunk_FUN_0800b4e8(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


/* ---------------------------------------------------------------------
 * FUN_0800b4e8   (0x0800B4E8, 1 Bytes)
 * Body: 0x0800B4E8-0x0800B4E9
 * --------------------------------------------------------------------- */
void FUN_0800b4e8(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


/* ---------------------------------------------------------------------
 * FUN_0800b4ea   (0x0800B4EA, 1 Bytes)
 * Body: 0x0800B4EA-0x0800B4EB
 * --------------------------------------------------------------------- */
void FUN_0800b4ea(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800b4ec   (0x0800B4EC, 1 Bytes)
 * Body: 0x0800B4EC-0x0800B4ED
 * --------------------------------------------------------------------- */
void FUN_0800b4ec(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800b4ee   (0x0800B4EE, 1 Bytes)
 * Body: 0x0800B4EE-0x0800B4EF
 * --------------------------------------------------------------------- */
void FUN_0800b4ee(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800b4f0   (0x0800B4F0, 11 Bytes)
 * TIM2-IRQ (Zeitbasis; loescht nur Update-Flag)
 * Body: 0x0800B4F0-0x0800B4FB
 * --------------------------------------------------------------------- */
void FUN_0800b4f0(void)

{
  FUN_08009620(0x40000000,1);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800b4fe   (0x0800B4FE, 203 Bytes)
 * USART1-IRQ: BLE-Empfang, 0xAA-20B-Frameparser + 200B-Ringpuffer (DMA5)
 * Body: 0x0800B4FE-0x0800B5C9
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0800b4fe(void)

{
  char cVar1;
  ushort uVar2;
  int iVar3;
  
  iVar3 = FUN_08008628((ushort *)0x40013800,0x525);
  if (iVar3 != 0) {
    FUN_0800867c((ushort *)0x40013800,0x525);
    uVar2 = FUN_08008556(0x40013800);
    cVar1 = (char)uVar2;
    uVar2 = FUN_08008556(0x40013800);
    *(char *)((_DAT_20000540 & 0x3fff) + 0x20001f88) = (char)uVar2;
    _DAT_20000540 = (ushort)(((uint)(ushort)(_DAT_20000540 + 1) << 0x12) >> 0x12);
    if (199 < _DAT_20000540) {
      _DAT_20000540 = 0;
    }
    if (DAT_20000004 == '\0') {
      if (cVar1 == -0x56) {
        DAT_20000004 = '\x01';
        DAT_20000005 = DAT_20000005 + 1;
        DAT_2000070c = 0xaa;
      }
      else {
        DAT_20000004 = '\0';
      }
    }
    else if (DAT_20000005 == 0x13) {
      DAT_2000071f = cVar1;
      FUN_0800deaa(0x2000078e,(undefined4 *)&DAT_2000070c);
      DAT_20000004 = '\0';
      DAT_20000005 = 0;
    }
    else if (DAT_20000005 == 1) {
      DAT_20000005 = 2;
      DAT_2000070d = cVar1;
    }
    else {
      (&DAT_2000070c)[DAT_20000005] = cVar1;
      DAT_20000005 = DAT_20000005 + 1;
    }
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800b5ca   (0x0800B5CA, 257 Bytes)
 * USART2-IRQ: ESC-Empfang, 0x71-Frameparser (12B), Queue 0x20000E2C
 * Body: 0x0800B5CA-0x0800B6CB
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0800b5ca(void)

{
  char cVar1;
  ushort uVar2;
  int iVar3;
  
  iVar3 = FUN_08008628((ushort *)0x40004400,0x525);
  if (iVar3 == 0) {
    FUN_0800867c((ushort *)0x40004400,0x525);
  }
  else {
    FUN_0800867c((ushort *)0x40004400,0x525);
    uVar2 = FUN_08008556(0x40004400);
    cVar1 = (char)uVar2;
    uVar2 = FUN_08008556(0x40004400);
    *(char *)((_DAT_20000542 & 0x3fff) + 0x20002050) = (char)uVar2;
    _DAT_20000542 = (ushort)(((uint)(ushort)(_DAT_20000542 + 1) << 0x12) >> 0x12);
    if (199 < _DAT_20000542) {
      _DAT_20000542 = 0;
    }
    if (DAT_20000006 == '\0') {
      if (cVar1 == 'q') {
        DAT_20000006 = '\x01';
        DAT_20000007 = DAT_20000007 + 1;
        DAT_20000720 = 0x71;
      }
      else {
        DAT_20000006 = '\0';
      }
    }
    else if (DAT_20000007 == 0xc) {
      DAT_2000072d = cVar1;
      FUN_08010c10(0x20000e2c,(undefined4 *)&DAT_20000720);
      DAT_20000006 = '\0';
      DAT_20000007 = 0;
    }
    else if (DAT_20000007 < 0xd) {
      (&DAT_20000720)[DAT_20000007] = cVar1;
      DAT_20000007 = DAT_20000007 + 1;
    }
    else {
      DAT_20000006 = '\0';
      DAT_20000007 = 0;
    }
  }
  iVar3 = FUN_08008628((ushort *)0x40004400,0x360);
  if (iVar3 == 0) {
    FUN_08008556(0x40004400);
    FUN_0800867c((ushort *)0x40004400,0x360);
  }
  else {
    FUN_08008556(0x40004400);
    FUN_0800867c((ushort *)0x40004400,0x360);
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800b6cc   (0x0800B6CC, 339 Bytes)
 * USART3-IRQ: Display-Empfang, Parser 0x4C/0x8A/0x8B/0x8C (DMA7)
 * Body: 0x0800B6CC-0x0800B81F
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0800b6cc(void)

{
  char cVar1;
  ushort uVar2;
  int iVar3;
  
  iVar3 = FUN_08008628((ushort *)0x40004800,0x525);
  if (iVar3 == 0) {
    FUN_0800867c((ushort *)0x40004800,0x525);
  }
  else {
    FUN_0800867c((ushort *)0x40004800,0x525);
    uVar2 = FUN_08008556(0x40004800);
    cVar1 = (char)uVar2;
    uVar2 = FUN_08008556(0x40004800);
    *(char *)((_DAT_20000544 & 0x3fff) + 0x20002118) = (char)uVar2;
    _DAT_20000544 = (ushort)(((uint)(ushort)(_DAT_20000544 + 1) << 0x12) >> 0x12);
    if (199 < _DAT_20000544) {
      _DAT_20000544 = 0;
    }
    if (DAT_20000008 == '\0') {
      if ((((cVar1 == 'L') || (cVar1 == -0x76)) || (cVar1 == -0x75)) || (cVar1 == -0x74)) {
        DAT_20000008 = '\x01';
        DAT_20000009 = DAT_20000009 + 1;
        DAT_2000072e = cVar1;
      }
      else {
        DAT_20000008 = '\0';
      }
    }
    else if ((((DAT_20000009 == 0x12) && (DAT_2000072e == 'L')) ||
             ((DAT_20000009 == 10 && (DAT_2000072e == -0x76)))) ||
            (((DAT_20000009 == 7 && (DAT_2000072e == -0x75)) ||
             ((DAT_20000009 == 7 && (DAT_2000072e == -0x74)))))) {
      (&DAT_2000072e)[DAT_20000009] = cVar1;
      DAT_20000741 = cVar1;
      FUN_08010c72(0x20000f01,&DAT_2000072e);
      DAT_20000008 = '\0';
      DAT_20000009 = 0;
    }
    else if (DAT_20000009 < 0x13) {
      (&DAT_2000072e)[DAT_20000009] = cVar1;
      DAT_20000009 = DAT_20000009 + 1;
    }
    else {
      DAT_20000008 = '\0';
      DAT_20000009 = 0;
    }
  }
  iVar3 = FUN_08008628((ushort *)0x40004800,0x360);
  if (iVar3 == 0) {
    FUN_08008556(0x40004800);
    FUN_0800867c((ushort *)0x40004800,0x360);
  }
  else {
    FUN_08008556(0x40004800);
    FUN_0800867c((ushort *)0x40004800,0x360);
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800b81e   (0x0800B81E, 1 Bytes)
 * Body: 0x0800B81E-0x0800B81F
 * --------------------------------------------------------------------- */
void FUN_0800b81e(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * thunk_FUN_0800b882   (0x0800B87C, 1 Bytes)
 * thunk -> __main/Ablaufstart (Sprung in Mainloop)
 * Body: 0x0800B87C-0x0800B87D
 * --------------------------------------------------------------------- */
void thunk_FUN_0800b882(void)

{
  do {
    FUN_0801c700();
  } while( true );
}


/* ---------------------------------------------------------------------
 * FUN_0800b882   (0x0800B882, 5 Bytes)
 * Body: 0x0800B87E-0x0800B883
 * --------------------------------------------------------------------- */
void FUN_0800b882(void)

{
  do {
    FUN_0801c700();
  } while( true );
}


/* ---------------------------------------------------------------------
 * FUN_0800b884   (0x0800B884, 41 Bytes)
 * Body: 0x0800B884-0x0800B8AD
 * --------------------------------------------------------------------- */
void FUN_0800b884(byte *param_1,int param_2,uint param_3,int param_4)

{
  uint uVar1;
  
  uVar1 = param_3 & 7;
  *param_1 = *param_1 & ~((char)(1 << (uVar1 + param_4 & 0xff)) - (char)(1 << uVar1));
  *param_1 = *param_1 | (byte)(param_2 << uVar1);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800b8ae   (0x0800B8AE, 99 Bytes)
 * Body: 0x0800B8AE-0x0800B911
 * --------------------------------------------------------------------- */
uint FUN_0800b8ae(uint param_1,uint param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = 0;
  iVar1 = (int)param_1 >> 3;
  for (uVar3 = iVar1 - ((int)((param_1 & 7) + param_2 + -1) >> 3); uVar3 = uVar3 & 0xff,
      (int)uVar3 <= iVar1; uVar3 = uVar3 + 1) {
    uVar2 = uVar2 + ((uint)*(byte *)(param_3 + uVar3) << ((iVar1 - uVar3 & 0x1f) << 3));
  }
  return (1 << (param_2 & 0xff)) - 1U & uVar2 >> (param_1 & 7);
}


/* ---------------------------------------------------------------------
 * FUN_0800b912   (0x0800B912, 103 Bytes)
 * Body: 0x0800B912-0x0800B979
 * --------------------------------------------------------------------- */
void FUN_0800b912(uint param_1,uint param_2,uint param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = (int)param_1 >> 3;
  uVar2 = 8 - (param_1 & 7);
  if ((int)param_2 <= (int)uVar2) {
    uVar2 = param_2;
  }
  while (FUN_0800b884((byte *)(param_4 + uVar3),(1 << (uVar2 & 0xff)) - 1U & param_3 & 0xff,param_1,
                      uVar2), uVar2 != param_2) {
    uVar1 = uVar3 - 1;
    uVar3 = uVar1 & 0xff;
    param_1 = (uVar1 & 0x1f) << 3;
    param_3 = param_3 >> (uVar2 & 0xff);
    param_2 = param_2 - uVar2 & 0xff;
    uVar2 = param_2;
    if (8 < param_2) {
      uVar2 = 8;
    }
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800b97a   (0x0800B97A, 21 Bytes)
 * Body: 0x0800B97A-0x0800B98F
 * --------------------------------------------------------------------- */
void FUN_0800b97a(undefined1 *param_1,undefined1 param_2,uint param_3)

{
  while (0 < (int)param_3) {
    *param_1 = param_2;
    param_3 = param_3 - 1 & 0xffff;
    param_1 = param_1 + 1;
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800b990   (0x0800B990, 27 Bytes)
 * Body: 0x0800B990-0x0800B9AB
 * --------------------------------------------------------------------- */
void FUN_0800b990(undefined1 *param_1,undefined1 *param_2,uint param_3)

{
  while (0 < (int)param_3) {
    *param_1 = *param_2;
    param_3 = param_3 - 1 & 0xffff;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800b9ac   (0x0800B9AC, 39 Bytes)
 * Body: 0x0800B9AC-0x0800B9D3
 * --------------------------------------------------------------------- */
undefined4 FUN_0800b9ac(char *param_1,char *param_2,uint param_3)

{
  char cVar1;
  char cVar2;
  
  do {
    if ((int)param_3 < 1) {
      return 1;
    }
    cVar1 = *param_1;
    cVar2 = *param_2;
    param_3 = param_3 - 1 & 0xffff;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  } while (cVar1 == cVar2);
  return 0;
}


/* ---------------------------------------------------------------------
 * FUN_0800b9d4   (0x0800B9D4, 23 Bytes)
 * Body: 0x0800B9D4-0x0800B9EB
 * --------------------------------------------------------------------- */
void FUN_0800b9d4(int param_1,int param_2)

{
  uint uVar1;
  
  for (uVar1 = 0; (int)uVar1 < param_2; uVar1 = uVar1 + 1 & 0xffff) {
    *(undefined1 *)(param_1 + uVar1) = 0;
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800b9ec   (0x0800B9EC, 23 Bytes)
 * Body: 0x0800B9EC-0x0800BA03
 * --------------------------------------------------------------------- */
void FUN_0800b9ec(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  for (uVar1 = 0; uVar1 < param_1; uVar1 = uVar1 + 1) {
    for (uVar2 = 0; uVar2 < 1000; uVar2 = uVar2 + 1) {
    }
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800ba04   (0x0800BA04, 27 Bytes)
 * Body: 0x0800BA04-0x0800BA1F
 * --------------------------------------------------------------------- */
char FUN_0800ba04(int param_1,int param_2)

{
  uint uVar1;
  char cVar2;
  
  cVar2 = '\0';
  for (uVar1 = 0; (int)uVar1 < param_2; uVar1 = uVar1 + 1 & 0xff) {
    cVar2 = *(char *)(param_1 + uVar1) + cVar2;
  }
  return cVar2;
}


/* ---------------------------------------------------------------------
 * FUN_0800ba20   (0x0800BA20, 105 Bytes)
 * Body: 0x0800BA20-0x0800BA89
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0800ba20(void)

{
  uint uVar1;
  
  FUN_08016a42();
  _DAT_200002d4 = 0;
  DAT_200002d8 = 0;
  DAT_200002a1 = 0;
  DAT_200002d9 = 0;
  DAT_200002a4 = 0;
  DAT_200002a5 = 0;
  DAT_200002a6 = 0;
  DAT_200002b9 = 0;
  DAT_200002c6 = 0;
  DAT_200002c7 = 0;
  for (uVar1 = 0; uVar1 < 6; uVar1 = uVar1 + 1 & 0xff) {
    (&DAT_200002ad)[uVar1] = 0;
    (&DAT_200002a7)[uVar1] = 0;
    (&DAT_200002b3)[uVar1] = 0;
    (&DAT_200002c0)[uVar1] = 0;
    (&DAT_200002ba)[uVar1] = 0;
  }
  DAT_2000030c = 0;
  DAT_200003a4 = 2;
  DAT_20000051 = 0;
  DAT_20000052 = 0;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800ba8c   (0x0800BA8C, 69 Bytes)
 * BLE-AT: sendet zyklisch 'AT+FC=1' (Flow-Control), Max ~20 Versuche
 * Body: 0x0800BA8C-0x0800BAD1
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0800ba8c(void)

{
  byte local_18 [12];
  
  local_18[0] = 0x41;
  local_18[1] = 0x54;
  local_18[2] = 0x2b;
  local_18[3] = 0x46;
  local_18[4] = 0x43;
  local_18[5] = 0x3d;
  local_18[6] = 0x31;
  local_18[7] = 0xd;
  local_18[8] = 10;
  local_18[9] = 0;
  local_18[10] = 0;
  local_18[0xb] = 0;
  _DAT_20000404 = _DAT_20000404 + 1;
  if (((_DAT_20000404 % 5 == 1) && (DAT_200003cd == '\0')) &&
     (FUN_08019b3a(local_18,9), 0x14 < _DAT_20000404)) {
    DAT_200003cd = '\x01';
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800bad2   (0x0800BAD2, 111 Bytes)
 * Body: 0x0800BAD2-0x0800BB41
 * --------------------------------------------------------------------- */
undefined4 FUN_0800bad2(char *param_1)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  bVar1 = false;
  uVar2 = FUN_0801d334(param_1);
  uVar2 = uVar2 & 0xff;
  if (0x13 < uVar2) {
    uVar2 = 0x13;
  }
  if (uVar2 < 6) {
    uVar4 = 1;
  }
  else {
    for (uVar3 = 0; uVar3 < uVar2; uVar3 = uVar3 + 1 & 0xff) {
      if (((((param_1[uVar3] != ' ') || (uVar3 < 6)) &&
           (((byte)param_1[uVar3] < 0x30 || (0x39 < (byte)param_1[uVar3])))) &&
          (((byte)param_1[uVar3] < 0x41 || (0x5a < (byte)param_1[uVar3])))) &&
         (((byte)param_1[uVar3] < 0x61 || (0x7a < (byte)param_1[uVar3])))) {
        bVar1 = true;
        break;
      }
    }
  }
  if (bVar1) {
    uVar4 = 2;
  }
  return uVar4;
}


/* ---------------------------------------------------------------------
 * FUN_0800bb42   (0x0800BB42, 89 Bytes)
 * BLE-AT: FIN-Umbenennung (Cmd 0x1F) -> 'AT+LENAME=<19 Zeichen>'
 * Body: 0x0800BB42-0x0800BB9B
 * --------------------------------------------------------------------- */
void FUN_0800bb42(char *param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  byte abStack_38 [10];
  char acStack_2e [22];
  
  uVar2 = 0;
  FUN_0801d2ec((undefined4 *)abStack_38,(undefined4 *)"AT+LENAME=1234567890123456789\r\n",0x20);
  iVar1 = FUN_0800bad2(param_1);
  if ((iVar1 == 0) && (param_2 == 0x13)) {
    for (; uVar2 < 0x13; uVar2 = uVar2 + 1 & 0xff) {
      acStack_2e[uVar2] = param_1[uVar2];
    }
    FUN_08019b3a(abStack_38,0x1f);
    if (param_3 != 0) {
      DAT_2000004f = 1;
    }
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800bb9c   (0x0800BB9C, 306 Bytes, 2 Teile)
 * Body: 0x0800BB9C-0x0800BBB1, 0x0800BBB8-0x0800BCD5
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0800bb9c(void)

{
  uint uVar1;
  
  if (DAT_20000051 == '\x01') {
    switch(DAT_200003ee) {
    case '\0':
      if (DAT_2000004c == '\0') {
        DAT_200003ee = '\x03';
      }
      else {
        DAT_20000050 = 1;
        DAT_200003ee = DAT_200003ee + '\x01';
      }
      break;
    case '\x01':
      DAT_20000050 = 0;
      DAT_200003ee = DAT_200003ee + '\x01';
      DAT_200003f8 = 0;
      break;
    case '\x02':
      DAT_200003f8 = DAT_200003f8 + 1;
      if (10 < DAT_200003f8) {
        DAT_200003ee = DAT_200003ee + '\x01';
        DAT_200003f8 = 0;
      }
      break;
    case '\x03':
      DAT_200003ee = DAT_200003ee + '\x01';
      _DAT_200003f0 = 0;
      break;
    case '\x04':
      if (DAT_2000004c == '\0') {
        for (uVar1 = 0; uVar1 < 0x11; uVar1 = uVar1 + 1 & 0xff) {
          (&DAT_20000742)[uVar1] = *(undefined1 *)(uVar1 + 0x20000cea);
        }
        for (uVar1 = 0x11; uVar1 < 0x13; uVar1 = uVar1 + 1 & 0xff) {
          (&DAT_20000742)[uVar1] = 0x20;
        }
        FUN_08017c08();
        FUN_0800bb42(&DAT_20000742,0x13,0);
        FUN_0800b9ec(100);
        FUN_0800bb42(&DAT_20000742,0x13,1);
        DAT_200003ee = DAT_200003ee + '\x01';
      }
      else {
        _DAT_200003f0 = _DAT_200003f0 + 1;
        if (5 < _DAT_200003f0) {
          _DAT_200003f0 = 0;
          DAT_200003ee = '\0';
        }
        _DAT_200003f4 = _DAT_200003f4 + 1;
        if (3 < _DAT_200003f4) {
          _DAT_200003f4 = 0;
          DAT_20000051 = '\0';
          DAT_20000050 = 0;
          DAT_200003ee = '\0';
        }
      }
      break;
    case '\x05':
      DAT_20000051 = '\0';
      DAT_20000050 = 0;
      DAT_200003ee = '\0';
    }
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800bcd6   (0x0800BCD6, 35 Bytes)
 * Body: 0x0800BCD6-0x0800BCF9
 * --------------------------------------------------------------------- */
void FUN_0800bcd6(void)

{
  if ((DAT_2000004d == '\x01') && (DAT_200003f9 = DAT_200003f9 + '\x01', DAT_200003f9 == '\n')) {
    DAT_200003f9 = '\0';
    DAT_2000004d = '\0';
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800bcfa   (0x0800BCFA, 89 Bytes)
 * Body: 0x0800BCFA-0x0800BD53
 * --------------------------------------------------------------------- */
void FUN_0800bcfa(void)

{
  if (DAT_2000004f == '\x01') {
    if (DAT_200003ed == '\0') {
      DAT_20000050 = 0;
      DAT_200003ed = '\x01';
    }
    else if (DAT_200003ed == '\x01') {
      DAT_20000050 = 1;
      DAT_200003ed = '\x02';
    }
    else if (DAT_200003ed == '\x02') {
      DAT_20000050 = 0;
      FUN_08019438();
      DAT_2000004f = '\0';
      DAT_200003ed = '\0';
    }
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800bd54   (0x0800BD54, 81 Bytes)
 * Body: 0x0800BD54-0x0800BDA5
 * --------------------------------------------------------------------- */
undefined4 FUN_0800bd54(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if ((DAT_200003a1 + 1) % 0x14 == (uint)DAT_200003a0) {
    uVar1 = 1;
  }
  else {
    uStack_10 = param_1;
    uStack_c = param_2;
    uStack_8 = param_3;
    uStack_4 = param_4;
    FUN_0801d2ec((undefined4 *)((uint)DAT_200003a1 * 0x14 + 0x200008bd),&uStack_10,0x14);
    DAT_200003a1 = (char)(DAT_200003a1 + 1) + (char)((DAT_200003a1 + 1) / 0x14) * -0x14;
    uVar1 = 4;
  }
  return uVar1;
}


/* ---------------------------------------------------------------------
 * FUN_0800bda6   (0x0800BDA6, 57 Bytes)
 * Body: 0x0800BDA6-0x0800BDDF
 * --------------------------------------------------------------------- */
void FUN_0800bda6(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = 0;
  iVar2 = 0;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    uVar1 = uVar1 ^ *(byte *)(param_1 + iVar2);
    iVar2 = iVar2 + 1;
    for (iVar3 = 0; iVar3 < 8; iVar3 = iVar3 + 1) {
      if ((uVar1 & 0x80) == 0x80) {
        uVar1 = (uVar1 & 0x7f) << 1 ^ 7;
      }
      else {
        uVar1 = (uVar1 & 0x7f) << 1;
      }
    }
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800bde0   (0x0800BDE0, 118 Bytes, 2 Teile)
 * Body: 0x0800BDE0-0x0800BE0B, 0x0800BECC-0x0800BF17
 * --------------------------------------------------------------------- */
void FUN_0800bde0(void)

{
  undefined1 uVar1;
  uint uVar2;
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined3 local_c;
  undefined1 uStack_9;
  
  local_1c = CONCAT22(local_1c._2_2_,0x4355);
  for (uVar2 = 0; uVar2 < 4; uVar2 = uVar2 + 1 & 0xff) {
    *(undefined1 *)((int)&local_1c + uVar2 + 2) = (&DAT_20000dac)[uVar2];
  }
  for (uVar2 = 0; uVar2 < 4; uVar2 = uVar2 + 1 & 0xff) {
    *(undefined1 *)((int)&uStack_18 + uVar2 + 2) = (&DAT_20000db0)[uVar2];
  }
  for (uVar2 = 0; uVar2 < 4; uVar2 = uVar2 + 1 & 0xff) {
    *(undefined1 *)((int)&uStack_14 + uVar2 + 2) = (&DAT_20000db4)[uVar2];
  }
  uVar1 = FUN_0800bda6((int)&local_1c,0x13);
  _local_c = CONCAT13(uVar1,local_c);
  FUN_0800bd54(local_1c,uStack_18,uStack_14,uStack_10);
  return;
}


/* ---------------------------------------------------------------------
 * thunk_FUN_0800bedc   (0x0800BE0A, 1 Bytes)
 * Body: 0x0800BE0A-0x0800BE0B
 * --------------------------------------------------------------------- */
void thunk_FUN_0800bedc(void)

{
  undefined1 uVar1;
  uint unaff_r4;
  uint uVar2;
  undefined4 uStack00000000;
  undefined4 in_stack_00000004;
  undefined4 in_stack_00000008;
  undefined4 in_stack_0000000c;
  undefined4 in_stack_00000010;
  undefined3 uStack00000014;
  
  for (; (int)unaff_r4 < 4; unaff_r4 = unaff_r4 + 1 & 0xff) {
    *(undefined1 *)((int)&stack0x00000008 + unaff_r4 + 2) = (&DAT_20000db0)[unaff_r4];
  }
  for (uVar2 = 0; uVar2 < 4; uVar2 = uVar2 + 1 & 0xff) {
    *(undefined1 *)((int)&stack0x0000000c + uVar2 + 2) = (&DAT_20000db4)[uVar2];
  }
  uVar1 = FUN_0800bda6((int)&stack0x00000004,0x13);
  _uStack00000014 = CONCAT13(uVar1,uStack00000014);
  uStack00000000 = _uStack00000014;
  FUN_0800bd54(in_stack_00000004,in_stack_00000008,in_stack_0000000c,in_stack_00000010);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800bec2   (0x0800BEC2, 25 Bytes)
 * Body: 0x0800BEC2-0x0800BEDB
 * --------------------------------------------------------------------- */
void FUN_0800bec2(void)

{
  undefined1 uVar1;
  uint uVar2;
  uint unaff_r7;
  undefined4 uStack00000000;
  undefined4 in_stack_00000004;
  undefined4 in_stack_00000008;
  undefined4 in_stack_0000000c;
  undefined4 in_stack_00000010;
  undefined3 uStack00000014;
  
  uVar2 = unaff_r7 >> 0x18;
  do {
    *(undefined1 *)((int)&stack0x00000008 + uVar2 + 2) = (&DAT_20000db0)[uVar2];
    uVar2 = uVar2 + 1 & 0xff;
  } while (uVar2 < 4);
  for (uVar2 = 0; uVar2 < 4; uVar2 = uVar2 + 1 & 0xff) {
    *(undefined1 *)((int)&stack0x0000000c + uVar2 + 2) = (&DAT_20000db4)[uVar2];
  }
  uVar1 = FUN_0800bda6((int)&stack0x00000004,0x13);
  _uStack00000014 = CONCAT13(uVar1,uStack00000014);
  uStack00000000 = _uStack00000014;
  FUN_0800bd54(in_stack_00000004,in_stack_00000008,in_stack_0000000c,in_stack_00000010);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800bedc   (0x0800BEDC, 59 Bytes)
 * Body: 0x0800BEDC-0x0800BF17
 * --------------------------------------------------------------------- */
void FUN_0800bedc(void)

{
  undefined1 uVar1;
  uint unaff_r4;
  uint uVar2;
  undefined4 uStack00000000;
  undefined4 in_stack_00000004;
  undefined4 in_stack_00000008;
  undefined4 in_stack_0000000c;
  undefined4 in_stack_00000010;
  undefined3 uStack00000014;
  
  for (; (int)unaff_r4 < 4; unaff_r4 = unaff_r4 + 1 & 0xff) {
    *(undefined1 *)((int)&stack0x00000008 + unaff_r4 + 2) = (&DAT_20000db0)[unaff_r4];
  }
  for (uVar2 = 0; uVar2 < 4; uVar2 = uVar2 + 1 & 0xff) {
    *(undefined1 *)((int)&stack0x0000000c + uVar2 + 2) = (&DAT_20000db4)[uVar2];
  }
  uVar1 = FUN_0800bda6((int)&stack0x00000004,0x13);
  _uStack00000014 = CONCAT13(uVar1,uStack00000014);
  uStack00000000 = _uStack00000014;
  FUN_0800bd54(in_stack_00000004,in_stack_00000008,in_stack_0000000c,in_stack_00000010);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800bf18   (0x0800BF18, 79 Bytes)
 * Body: 0x0800BF18-0x0800BF67
 * --------------------------------------------------------------------- */
void FUN_0800bf18(void)

{
  undefined1 uVar1;
  uint uVar2;
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined3 local_c;
  undefined1 uStack_9;
  
  local_1c = CONCAT22(local_1c._2_2_,0x7355);
  FUN_0800b990((undefined1 *)((int)&local_1c + 2),&DAT_20000d7b,0xf);
  for (uVar2 = 0xf; uVar2 < 0x10; uVar2 = uVar2 + 1 & 0xff) {
    *(undefined1 *)((int)&local_1c + uVar2 + 3) = 0xff;
  }
  uVar1 = FUN_0800bda6((int)&local_1c,0x13);
  _local_c = CONCAT13(uVar1,local_c);
  FUN_0800bd54(local_1c,uStack_18,uStack_14,uStack_10);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800bf68   (0x0800BF68, 79 Bytes)
 * Body: 0x0800BF68-0x0800BFB7
 * --------------------------------------------------------------------- */
void FUN_0800bf68(void)

{
  undefined1 uVar1;
  uint uVar2;
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined3 local_c;
  undefined1 uStack_9;
  
  local_1c = CONCAT22(local_1c._2_2_,0x7255);
  FUN_0800b990((undefined1 *)((int)&local_1c + 2),&DAT_20000d6b,0x10);
  for (uVar2 = 0x10; uVar2 < 0x10; uVar2 = uVar2 + 1 & 0xff) {
    *(undefined1 *)((int)&local_1c + uVar2 + 3) = 0xff;
  }
  uVar1 = FUN_0800bda6((int)&local_1c,0x13);
  _local_c = CONCAT13(uVar1,local_c);
  FUN_0800bd54(local_1c,uStack_18,uStack_14,uStack_10);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800bfb8   (0x0800BFB8, 87 Bytes)
 * Body: 0x0800BFB8-0x0800C00F
 * --------------------------------------------------------------------- */
void FUN_0800bfb8(void)

{
  undefined1 uVar1;
  uint uVar2;
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined3 local_c;
  undefined1 uStack_9;
  
  local_1c = CONCAT22(local_1c._2_2_,0x7155);
  FUN_0800b990((undefined1 *)((int)&local_1c + 2),
               (undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d0b),0x10);
  for (uVar2 = 0x10; uVar2 < 0x10; uVar2 = uVar2 + 1 & 0xff) {
    *(undefined1 *)((int)&local_1c + uVar2 + 3) = 0xff;
  }
  uVar1 = FUN_0800bda6((int)&local_1c,0x13);
  _local_c = CONCAT13(uVar1,local_c);
  FUN_0800bd54(local_1c,uStack_18,uStack_14,uStack_10);
  return;
}



/* =====================================================================
 *  SEKTION: 0x0800C000 - BLE-Telemetrie, RX-Consumer, Kommandoverarbeitung
 * ===================================================================== */

/* ---------------------------------------------------------------------
 * FUN_0800c010   (0x0800C010, 79 Bytes)
 * Body: 0x0800C010-0x0800C05F
 * --------------------------------------------------------------------- */
void FUN_0800c010(void)

{
  undefined1 uVar1;
  uint uVar2;
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined3 local_c;
  undefined1 uStack_9;
  
  local_1c = CONCAT22(local_1c._2_2_,0x5655);
  FUN_0800b990((undefined1 *)((int)&local_1c + 2),&DAT_20000e0b,0x10);
  for (uVar2 = 0x10; uVar2 < 0x10; uVar2 = uVar2 + 1 & 0xff) {
    *(undefined1 *)((int)&local_1c + uVar2 + 3) = 0xff;
  }
  uVar1 = FUN_0800bda6((int)&local_1c,0x13);
  _local_c = CONCAT13(uVar1,local_c);
  FUN_0800bd54(local_1c,uStack_18,uStack_14,uStack_10);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800c060   (0x0800C060, 77 Bytes)
 * Body: 0x0800C060-0x0800C0AD
 * --------------------------------------------------------------------- */
void FUN_0800c060(void)

{
  undefined1 uVar1;
  uint uVar2;
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined3 local_c;
  undefined1 uStack_9;
  
  local_1c = CONCAT22(local_1c._2_2_,0x5555);
  FUN_0800b990((undefined1 *)((int)&local_1c + 2),&DAT_20000dfb,0x10);
  for (uVar2 = 0x10; uVar2 < 0x10; uVar2 = uVar2 + 1 & 0xff) {
    *(undefined1 *)((int)&local_1c + uVar2 + 3) = 0xff;
  }
  uVar1 = FUN_0800bda6((int)&local_1c,0x13);
  _local_c = CONCAT13(uVar1,local_c);
  FUN_0800bd54(local_1c,uStack_18,uStack_14,uStack_10);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800c0ae   (0x0800C0AE, 67 Bytes)
 * Body: 0x0800C0AE-0x0800C0F1
 * --------------------------------------------------------------------- */
void FUN_0800c0ae(void)

{
  undefined1 uVar1;
  uint uVar2;
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined3 local_c;
  undefined1 uStack_9;
  
  local_1c = CONCAT22(local_1c._2_2_,0x4255);
  for (uVar2 = 0; uVar2 < 0x11; uVar2 = uVar2 + 1 & 0xff) {
    *(undefined1 *)((int)&local_1c + uVar2 + 2) = *(undefined1 *)(uVar2 + 0x20000d9b);
  }
  uVar1 = FUN_0800bda6((int)&local_1c,0x13);
  _local_c = CONCAT13(uVar1,local_c);
  FUN_0800bd54(local_1c,uStack_18,uStack_14,uStack_10);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800c0f2   (0x0800C0F2, 79 Bytes)
 * Body: 0x0800C0F2-0x0800C141
 * --------------------------------------------------------------------- */
void FUN_0800c0f2(void)

{
  undefined1 uVar1;
  uint uVar2;
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined3 local_c;
  undefined1 uStack_9;
  
  local_1c = CONCAT22(local_1c._2_2_,0x5455);
  FUN_0800b990((undefined1 *)((int)&local_1c + 2),&DAT_20000dea,0x11);
  for (uVar2 = 0x11; uVar2 < 0x10; uVar2 = uVar2 + 1 & 0xff) {
    *(undefined1 *)((int)&local_1c + uVar2 + 3) = 0xff;
  }
  uVar1 = FUN_0800bda6((int)&local_1c,0x13);
  _local_c = CONCAT13(uVar1,local_c);
  FUN_0800bd54(local_1c,uStack_18,uStack_14,uStack_10);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800c142   (0x0800C142, 79 Bytes)
 * Body: 0x0800C142-0x0800C191
 * --------------------------------------------------------------------- */
void FUN_0800c142(void)

{
  undefined1 uVar1;
  uint uVar2;
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined3 local_c;
  undefined1 uStack_9;
  
  local_1c = CONCAT22(local_1c._2_2_,0x5355);
  FUN_0800b990((undefined1 *)((int)&local_1c + 2),&DAT_20000dd9,0x11);
  for (uVar2 = 0x11; uVar2 < 0x10; uVar2 = uVar2 + 1 & 0xff) {
    *(undefined1 *)((int)&local_1c + uVar2 + 3) = 0xff;
  }
  uVar1 = FUN_0800bda6((int)&local_1c,0x13);
  _local_c = CONCAT13(uVar1,local_c);
  FUN_0800bd54(local_1c,uStack_18,uStack_14,uStack_10);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800c192   (0x0800C192, 67 Bytes)
 * Body: 0x0800C192-0x0800C1D5
 * --------------------------------------------------------------------- */
void FUN_0800c192(void)

{
  undefined1 uVar1;
  uint uVar2;
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined3 local_c;
  undefined1 uStack_9;
  
  local_1c = CONCAT22(local_1c._2_2_,0x4155);
  for (uVar2 = 0; uVar2 < 0x11; uVar2 = uVar2 + 1 & 0xff) {
    *(undefined1 *)((int)&local_1c + uVar2 + 2) = (&DAT_20000d8a)[uVar2];
  }
  uVar1 = FUN_0800bda6((int)&local_1c,0x13);
  _local_c = CONCAT13(uVar1,local_c);
  FUN_0800bd54(local_1c,uStack_18,uStack_14,uStack_10);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800c1d6   (0x0800C1D6, 79 Bytes)
 * Body: 0x0800C1D6-0x0800C225
 * --------------------------------------------------------------------- */
void FUN_0800c1d6(void)

{
  undefined1 uVar1;
  uint uVar2;
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined3 local_c;
  undefined1 uStack_9;
  
  local_1c = CONCAT22(local_1c._2_2_,0x5255);
  FUN_0800b990((undefined1 *)((int)&local_1c + 2),&DAT_20000dc8,0x11);
  for (uVar2 = 0x11; uVar2 < 0x10; uVar2 = uVar2 + 1 & 0xff) {
    *(undefined1 *)((int)&local_1c + uVar2 + 3) = 0xff;
  }
  uVar1 = FUN_0800bda6((int)&local_1c,0x13);
  _local_c = CONCAT13(uVar1,local_c);
  FUN_0800bd54(local_1c,uStack_18,uStack_14,uStack_10);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800c226   (0x0800C226, 79 Bytes)
 * Body: 0x0800C226-0x0800C275
 * --------------------------------------------------------------------- */
void FUN_0800c226(void)

{
  undefined1 uVar1;
  uint uVar2;
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined3 local_c;
  undefined1 uStack_9;
  
  local_1c = CONCAT22(local_1c._2_2_,0x5155);
  FUN_0800b990((undefined1 *)((int)&local_1c + 2),&DAT_20000db8,0x10);
  for (uVar2 = 0x10; uVar2 < 0x10; uVar2 = uVar2 + 1 & 0xff) {
    *(undefined1 *)((int)&local_1c + uVar2 + 3) = 0xff;
  }
  uVar1 = FUN_0800bda6((int)&local_1c,0x13);
  _local_c = CONCAT13(uVar1,local_c);
  FUN_0800bd54(local_1c,uStack_18,uStack_14,uStack_10);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800c276   (0x0800C276, 277 Bytes, 3 Teile)
 * BLE-TX-State: Frame-Sender (State) fuer 0x55xx
 * Body: 0x0800C276-0x0800C283, 0x0800C294-0x0800C2B3, 0x0800C2EC-0x0800C3D5
 * --------------------------------------------------------------------- */
void FUN_0800c276(void)

{
  switch(DAT_200003fc) {
  case '\0':
    FUN_0800c226();
    DAT_200003fc = DAT_200003fc + '\x01';
    break;
  case '\x01':
    FUN_0800c1d6();
    DAT_200003fc = DAT_200003fc + '\x01';
    break;
  case '\x02':
    FUN_0800bfb8();
    DAT_200003fc = DAT_200003fc + '\x01';
    break;
  case '\x03':
    FUN_0800bf68();
    DAT_200003fc = DAT_200003fc + '\x01';
    break;
  case '\x04':
    FUN_0800c192();
    DAT_200003fc = DAT_200003fc + '\x01';
    break;
  case '\x05':
    FUN_0800c142();
    DAT_200003fc = DAT_200003fc + '\x01';
    break;
  case '\x06':
    FUN_0800c0f2();
    DAT_200003fc = DAT_200003fc + '\x01';
    break;
  case '\a':
    FUN_0800bfb8();
    DAT_200003fc = DAT_200003fc + '\x01';
    break;
  case '\b':
    FUN_0800bf68();
    DAT_200003fc = DAT_200003fc + '\x01';
    break;
  case '\t':
    FUN_0800c0ae();
    DAT_200003fc = DAT_200003fc + '\x01';
    break;
  case '\n':
    FUN_0800c060();
    DAT_200003fc = DAT_200003fc + '\x01';
    break;
  case '\v':
    FUN_0800c010();
    DAT_200003fc = DAT_200003fc + '\x01';
    break;
  case '\f':
    FUN_0800bfb8();
    DAT_200003fc = DAT_200003fc + '\x01';
    break;
  case '\r':
    FUN_0800bf68();
    DAT_200003fc = DAT_200003fc + '\x01';
    break;
  case '\x0e':
    FUN_0800bf18();
    DAT_200003fc = DAT_200003fc + '\x01';
    break;
  case '\x0f':
    FUN_0800bde0();
    DAT_200003fc = '\0';
    break;
  default:
    DAT_200003fc = '\0';
  }
  return;
}


/* ---------------------------------------------------------------------
 * thunk_FUN_0800c3d2   (0x0800C2B2, 1 Bytes)
 * Body: 0x0800C2B2-0x0800C2B3
 * --------------------------------------------------------------------- */
void thunk_FUN_0800c3d2(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800c3d2   (0x0800C3D2, 3 Bytes)
 * Body: 0x0800C3D2-0x0800C3D5
 * --------------------------------------------------------------------- */
void FUN_0800c3d2(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800c3d6   (0x0800C3D6, 77 Bytes)
 * Body: 0x0800C3D6-0x0800C423
 * --------------------------------------------------------------------- */
void FUN_0800c3d6(void)

{
  undefined1 uVar1;
  uint uVar2;
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined3 local_c;
  undefined1 uStack_9;
  
  local_1c = CONCAT22(local_1c._2_2_,0x8155);
  FUN_0800b990((undefined1 *)((int)&local_1c + 2),&DAT_200003c7,6);
  for (uVar2 = 6; uVar2 < 0x10; uVar2 = uVar2 + 1 & 0xff) {
    *(undefined1 *)((int)&local_1c + uVar2 + 2) = 0xff;
  }
  uVar1 = FUN_0800bda6((int)&local_1c,0x13);
  _local_c = CONCAT13(uVar1,local_c);
  FUN_0800bd54(local_1c,uStack_18,uStack_14,uStack_10);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800c424   (0x0800C424, 7 Bytes)
 * Body: 0x0800C424-0x0800C42B
 * --------------------------------------------------------------------- */
uint FUN_0800c424(uint param_1,uint param_2)

{
  return param_1 ^ param_2;
}


/* ---------------------------------------------------------------------
 * FUN_0800c42c   (0x0800C42C, 171 Bytes)
 * Body: 0x0800C42C-0x0800C4D7
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_0800c42c(int param_1)

{
  uint uVar1;
  bool bVar2;
  undefined1 local_18 [2];
  byte local_16;
  byte local_15;
  
  bVar2 = false;
  _local_18 = CONCAT12(DAT_200003cb,CONCAT11(DAT_200003ca,DAT_200003c9));
  _local_18 = CONCAT13(DAT_200003cc,_local_18);
  if (param_1 == 0) {
    bVar2 = true;
  }
  else if (param_1 == 1) {
    bVar2 = _DAT_200003ac ==
            (_local_18 & 0xff) + (uint)DAT_200003ca + (uint)DAT_200003cb + (uint)DAT_200003cc;
  }
  else if (param_1 == 2) {
    uVar1 = FUN_0800bda6((int)local_18,4);
    bVar2 = _DAT_200003ac == uVar1;
  }
  else if ((param_1 == 3) &&
          (uVar1 = FUN_0800c424((uint)DAT_200003c9 * 0x1000000 + (uint)DAT_200003c9 * 0x10000 +
                                (uint)DAT_200003c9 * 0x100 + (uint)DAT_200003c9,0xcf1974),
          _DAT_200003ac == uVar1)) {
    bVar2 = true;
  }
  return bVar2;
}


/* ---------------------------------------------------------------------
 * FUN_0800c4d8   (0x0800C4D8, 27 Bytes)
 * Body: 0x0800C4D8-0x0800C4F3
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0800c4d8(void)

{
  return _DAT_20000530 * 0xd + (_DAT_20000530 & 0xffff) * 0x30000;
}


/* ---------------------------------------------------------------------
 * FUN_0800c4f4   (0x0800C4F4, 195 Bytes)
 * BLE-TX-State: Sonderversand
 * Body: 0x0800C4F4-0x0800C5B7
 * --------------------------------------------------------------------- */
void FUN_0800c4f4(void)

{
  bool bVar1;
  int iVar2;
  
  if (DAT_200003a9 == '\0') {
    DAT_200003c7 = DAT_2000030c;
    DAT_200003c8 = 0xff;
    DAT_200003c9 = 0xff;
    DAT_200003ca = 0xff;
    DAT_200003cb = 0xff;
    DAT_200003cc = 0xff;
    DAT_200003a5 = '\x01';
  }
  else if (DAT_200003a9 == '\x01') {
    if (DAT_200003a5 == '\x01') {
      DAT_200003c7 = DAT_2000030c;
      DAT_200003c8 = 1;
      iVar2 = FUN_0800c4d8();
      DAT_200003c9 = (undefined1)((uint)iVar2 >> 0x18);
      DAT_200003ca = (undefined1)((uint)iVar2 >> 0x10);
      DAT_200003cb = (undefined1)((uint)iVar2 >> 8);
      DAT_200003cc = (undefined1)iVar2;
      DAT_200003a5 = '\x02';
    }
  }
  else if ((DAT_200003a9 == '\x02') && (DAT_200003a5 == '\x02')) {
    bVar1 = FUN_0800c42c(1);
    if ((bVar1) || (DAT_2000030c == '\x01')) {
      DAT_2000030c = '\x01';
    }
    else {
      DAT_200003a6 = DAT_200003a6 + 1;
      if (3 < DAT_200003a6) {
        DAT_2000030c = '\x02';
      }
    }
    DAT_200003c7 = DAT_2000030c;
    DAT_200003c8 = 0xff;
    DAT_200003c9 = 0xff;
    DAT_200003ca = 0xff;
    DAT_200003cb = 0xff;
    DAT_200003cc = 0xff;
    DAT_200003a5 = '\x03';
  }
  FUN_0800c3d6();
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800c5b8   (0x0800C5B8, 79 Bytes)
 * BLE-TX-Dispatcher: state 0x200003A4 (0/1/2/3/0x10)
 * Body: 0x0800C5B8-0x0800C607
 * --------------------------------------------------------------------- */
void FUN_0800c5b8(void)

{
  if (DAT_200003cd == '\x01') {
    if (DAT_200003a4 == 2) {
      FUN_0800c276();
    }
    else {
      if (DAT_200003a4 < 3) {
        if (DAT_200003a4 == 0) {
          return;
        }
        if (DAT_200003a4 == 1) {
          FUN_0800c276();
          return;
        }
      }
      else {
        if (DAT_200003a4 == 3) {
          FUN_0800c276();
          return;
        }
        if (DAT_200003a4 == 0x10) {
          FUN_0800c4f4();
          DAT_200003a4 = 2;
          return;
        }
      }
      FUN_0800c276();
    }
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800c608   (0x0800C608, 2271 Bytes, 3 Teile)
 * Builder '55 43' Hardwareinfo: Version 0x20000011-13 (3.4.13), Identitaets-/Board-Bytes
 * Body: 0x0800C608-0x0800C6E9, 0x0800C764-0x0800CB61, 0x0800CD40-0x0800D141
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0800c608(void)

{
  uint uVar1;
  byte bVar2;
  
  for (uVar1 = 0; uVar1 < 0x11; uVar1 = uVar1 + 1 & 0xff) {
    (&DAT_20000d8a)[uVar1] = (&DAT_2000077d)[uVar1];
    *(undefined1 *)(uVar1 + 0x20000d9b) = (&DAT_20000744)[uVar1];
  }
  DAT_20000dac = DAT_20000011;
  DAT_20000dad = DAT_20000012;
  DAT_20000dae = DAT_20000013;
  DAT_20000daf = DAT_2000000f;
  DAT_20000db0 = DAT_20000019;
  DAT_20000db1 = DAT_2000001a;
  DAT_20000db2 = DAT_2000001b;
  DAT_20000db3 = DAT_20000017;
  DAT_20000db4 = DAT_2000002c;
  DAT_20000db5 = DAT_2000002d;
  DAT_20000db6 = DAT_2000002e;
  DAT_20000db7 = DAT_2000002f;
  DAT_20000db8 = DAT_2000032e;
  DAT_20000db9 = DAT_2000032f;
  DAT_20000dba = DAT_20000330;
  DAT_20000dbb = DAT_20000331;
  DAT_20000dbc = DAT_20000332;
  DAT_20000dbd = DAT_20000333;
  DAT_20000dbe = DAT_20000334;
  DAT_20000dbf = DAT_20000335;
  DAT_20000dc0 = DAT_20000336;
  DAT_20000dc1 = DAT_20000337;
  DAT_20000dc2 = DAT_20000338;
  DAT_20000dc3 = DAT_20000339;
  DAT_20000dc4 = DAT_2000033a;
  DAT_20000dc5 = DAT_2000033b;
  DAT_20000dc6 = DAT_2000033c;
  DAT_20000dc7 = DAT_2000033d;
  DAT_20000dc8 = DAT_2000035e;
  DAT_20000dc9 = DAT_2000035f;
  DAT_20000dca = DAT_20000360;
  DAT_20000dcb = DAT_20000361;
  DAT_20000dcc = DAT_20000362;
  DAT_20000dcd = DAT_20000363;
  DAT_20000dce = DAT_20000364;
  DAT_20000dcf = DAT_20000365;
  DAT_20000dd0 = DAT_20000366;
  DAT_20000dd1 = DAT_20000367;
  DAT_20000dd2 = DAT_20000367;
  DAT_20000dd3 = DAT_20000369;
  DAT_20000dd4 = DAT_2000036a;
  DAT_20000dd5 = DAT_2000036b;
  DAT_20000dd6 = DAT_2000036c;
  DAT_20000dd7 = DAT_2000036d;
  DAT_20000dd8 = DAT_2000036e;
  DAT_20000dd9 = DAT_2000036f;
  DAT_20000dda = DAT_20000370;
  DAT_20000ddb = DAT_20000371;
  DAT_20000ddc = DAT_20000372;
  DAT_20000ddd = DAT_20000373;
  DAT_20000dde = DAT_20000374;
  DAT_20000ddf = DAT_20000375;
  DAT_20000de0 = DAT_20000376;
  DAT_20000de1 = 0;
  DAT_20000de2 = 0;
  DAT_20000de3 = (undefined1)((ushort)_DAT_200002f0 >> 8);
  DAT_20000de4 = DAT_200002f0;
  DAT_20000de5 = DAT_2000037b;
  DAT_20000de6 = DAT_2000037c;
  DAT_20000de7 = DAT_2000037d;
  DAT_20000de8 = DAT_2000037e;
  DAT_20000de9 = DAT_2000037f;
  DAT_20000dea = DAT_2000029f;
  if (DAT_20000380 == '\x03') {
    DAT_20000dea = 3;
  }
  DAT_20000deb = DAT_20000381;
  DAT_20000dec = DAT_20000382;
  DAT_20000ded = DAT_20000383;
  DAT_20000dee = DAT_20000384;
  DAT_20000def = DAT_20000385;
  DAT_20000df0 = DAT_20000386;
  DAT_20000df1 = DAT_20000387;
  DAT_20000df2 = DAT_20000388;
  DAT_20000df3 = DAT_20000389;
  DAT_20000df4 = DAT_2000038a;
  DAT_20000df5 = DAT_2000038b;
  DAT_20000df6 = DAT_2000038c;
  DAT_20000df7 = DAT_2000038d;
  DAT_20000df8 = DAT_2000038e;
  DAT_20000df9 = DAT_20000390;
  DAT_20000dfa = DAT_20000064 ^ 1;
  DAT_20000dfb = DAT_2000033e;
  DAT_20000dfc = DAT_2000033f;
  DAT_20000dfd = DAT_20000340;
  DAT_20000dfe = DAT_20000341;
  DAT_20000dff = DAT_20000342;
  DAT_20000e00 = DAT_20000343;
  DAT_20000e01 = DAT_20000344;
  DAT_20000e02 = DAT_20000345;
  DAT_20000e03 = DAT_20000346;
  DAT_20000e04 = DAT_20000347;
  DAT_20000e05 = DAT_20000348;
  DAT_20000e06 = DAT_20000349;
  DAT_20000e07 = DAT_2000034a;
  DAT_20000e08 = DAT_2000034b;
  DAT_20000e09 = DAT_2000034c;
  DAT_20000e0a = DAT_2000034d;
  DAT_20000e0b = DAT_2000034e;
  DAT_20000e0c = DAT_2000034f;
  DAT_20000e0d = DAT_20000350;
  DAT_20000e0e = DAT_20000351;
  DAT_20000e0f = DAT_20000352;
  DAT_20000e10 = DAT_20000353;
  DAT_20000e11 = DAT_20000354;
  DAT_20000e12 = DAT_20000355;
  DAT_20000e13 = DAT_20000356;
  DAT_20000e14 = DAT_20000357;
  DAT_20000e15 = DAT_20000358;
  DAT_20000e16 = DAT_20000359;
  DAT_20000e17 = DAT_2000035a;
  DAT_20000e18 = DAT_2000035b;
  DAT_20000e19 = DAT_2000035c;
  DAT_20000e1a = DAT_2000035d;
  _DAT_20000e22 = _DAT_2000018e;
  _DAT_20000e1c = _DAT_2000012e;
  _DAT_20000e24 = _DAT_200001a6;
  _DAT_20000e1e = _DAT_20000146;
  _DAT_20000e26 = _DAT_20000176;
  _DAT_20000e20 = _DAT_20000116;
  _DAT_20000e2a = _DAT_200001d0;
  _DAT_20000e28 = _DAT_20000200;
  DAT_200003c1 = DAT_200000e6;
  DAT_200003c2 = DAT_200000fe;
  DAT_200003bf = DAT_200000b6;
  DAT_200003c0 = DAT_200000ce;
  DAT_200003c5 = DAT_2000027e;
  DAT_200003c6 = DAT_20000296;
  DAT_200003c3 = DAT_2000024e;
  DAT_200003c4 = DAT_20000266;
  bVar2 = DAT_200002a1;
  if (DAT_20000309 != '\0') {
    bVar2 = 0;
  }
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d0b) = DAT_200002a0;
  *(byte *)((uint)DAT_200002a1 * 0x10 + 0x20000d0c) = bVar2;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d19) = DAT_200002a2;
  *(byte *)((uint)DAT_200002a1 * 0x10 + 0x20000d0d) = DAT_200002a3;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d0e) = DAT_200002a4;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d0f) = DAT_200002a5;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d10) = DAT_200002a6;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d11) = (&DAT_200002ad)[DAT_200002a1];
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d12) = (&DAT_200002a7)[DAT_200002a1];
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d13) = (&DAT_200002b3)[DAT_200002a1];
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d14) = DAT_200002b9;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d16) = (&DAT_200002ba)[DAT_200002a1];
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d15) = (&DAT_200002c0)[DAT_200002a1];
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d17) = DAT_200002c6;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d18) = DAT_200002c7;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d1a) = DAT_20000307;
  DAT_20000d73 = DAT_200002db;
  if ((DAT_200002a3 & 0x80) == 0) {
    bVar2 = 0;
  }
  else {
    bVar2 = 8;
  }
  DAT_20000d74 = DAT_200002dc & 0xf7 | bVar2;
  DAT_200003ec = DAT_200003ec + 1;
  uVar1 = ((int)(uint)DAT_200003ec >> 2) + ((int)(uint)DAT_200003ec >> 3) * -2 & 0xff;
  if ((500 < _DAT_20000034) && (uVar1 == 1)) {
    DAT_20000d74 = DAT_20000d74 | 0x20;
  }
  if ((500 < _DAT_20000036) && (uVar1 == 1)) {
    DAT_20000d74 = DAT_20000d74 | 0x40;
  }
  if (500 < _DAT_20000032) {
    DAT_20000d74 = DAT_20000d74 | 0x10;
  }
  if (DAT_200002cd == '\0') {
    DAT_20000d74 = DAT_20000d74 & 0x7f;
  }
  else {
    DAT_20000d74 = DAT_20000d74 | 0x80;
  }
  DAT_20000d75 = (char)((ushort)_DAT_200002de >> 8);
  DAT_20000d76 = (char)_DAT_200002de;
  DAT_20000d77 = DAT_200002e0;
  DAT_20000d78 = (char)((ushort)_DAT_200002e2 >> 8);
  DAT_20000d79 = (char)_DAT_200002e2;
  DAT_20000d7a = DAT_200002e4;
  DAT_20000d6b = DAT_200002e6;
  DAT_20000d6c = DAT_200002dc & 0xf7 | DAT_200002e7 & 8;
  if ((500 < _DAT_20000034) && (uVar1 == 1)) {
    DAT_20000d6c = DAT_20000d6c | 0x20;
  }
  if ((500 < _DAT_20000036) && (uVar1 == 1)) {
    DAT_20000d6c = DAT_20000d6c | 0x40;
  }
  if (500 < _DAT_20000032) {
    DAT_20000d6c = DAT_20000d6c | 0x10;
  }
  if (DAT_200002cd == '\0') {
    DAT_20000d6c = DAT_20000d6c & 0x7f;
  }
  else {
    DAT_20000d6c = DAT_20000d6c | 0x80;
  }
  DAT_20000d6d = (char)((ushort)_DAT_200002e8 >> 8);
  DAT_20000d6e = (char)_DAT_200002e8;
  DAT_20000d6f = DAT_200002ea;
  DAT_20000d70 = (char)((ushort)_DAT_200002ec >> 8);
  DAT_20000d71 = (char)_DAT_200002ec;
  DAT_20000d72 = DAT_200002ee;
  DAT_20000d7b = (char)((ushort)_DAT_200002f4 >> 8);
  DAT_20000d7c = (char)_DAT_200002f4;
  DAT_20000d7d = (char)((ushort)_DAT_200002f8 >> 8);
  DAT_20000d7e = (char)_DAT_200002f8;
  DAT_20000d7f = (char)((ushort)_DAT_200002fe >> 8);
  DAT_20000d80 = DAT_200002fe;
  DAT_20000d81 = (char)(_DAT_20000300 / 10 >> 0x10);
  DAT_20000d82 = (char)(_DAT_20000300 / 10 >> 8);
  DAT_20000d83 = (char)(_DAT_20000300 / 10);
  DAT_20000d84 = (char)((ushort)_DAT_20000304 >> 8);
  DAT_20000d85 = DAT_20000304;
  DAT_20000d86 = DAT_200002ce;
  DAT_20000d87 = DAT_200002cf;
  DAT_20000d88 = DAT_200002d0;
  DAT_20000d89 = 0;
  return;
}


/* ---------------------------------------------------------------------
 * thunk_FUN_0800c764   (0x0800C6E8, 1 Bytes)
 * Body: 0x0800C6E8-0x0800C6E9
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thunk_FUN_0800c764(void)

{
  uint uVar1;
  byte bVar2;
  undefined1 unaff_r7;
  int in_r12;
  
  *(undefined1 *)(in_r12 + 4) = unaff_r7;
  *(undefined1 *)(in_r12 + 5) = DAT_20000333;
  *(undefined1 *)(in_r12 + 6) = DAT_20000334;
  *(undefined1 *)(in_r12 + 7) = DAT_20000335;
  *(undefined1 *)(in_r12 + 8) = DAT_20000336;
  *(undefined1 *)(in_r12 + 9) = DAT_20000337;
  *(undefined1 *)(in_r12 + 10) = DAT_20000338;
  *(undefined1 *)(in_r12 + 0xb) = DAT_20000339;
  *(undefined1 *)(in_r12 + 0xc) = DAT_2000033a;
  *(undefined1 *)(in_r12 + 0xd) = DAT_2000033b;
  *(undefined1 *)(in_r12 + 0xe) = DAT_2000033c;
  *(undefined1 *)(in_r12 + 0xf) = DAT_2000033d;
  DAT_20000dc8 = DAT_2000035e;
  DAT_20000dc9 = DAT_2000035f;
  DAT_20000dca = DAT_20000360;
  DAT_20000dcb = DAT_20000361;
  DAT_20000dcc = DAT_20000362;
  DAT_20000dcd = DAT_20000363;
  DAT_20000dce = DAT_20000364;
  DAT_20000dcf = DAT_20000365;
  DAT_20000dd0 = DAT_20000366;
  DAT_20000dd1 = DAT_20000367;
  DAT_20000dd2 = DAT_20000367;
  DAT_20000dd3 = DAT_20000369;
  DAT_20000dd4 = DAT_2000036a;
  DAT_20000dd5 = DAT_2000036b;
  DAT_20000dd6 = DAT_2000036c;
  DAT_20000dd7 = DAT_2000036d;
  DAT_20000dd8 = DAT_2000036e;
  DAT_20000dd9 = DAT_2000036f;
  DAT_20000dda = DAT_20000370;
  DAT_20000ddb = DAT_20000371;
  DAT_20000ddc = DAT_20000372;
  DAT_20000ddd = DAT_20000373;
  DAT_20000dde = DAT_20000374;
  DAT_20000ddf = DAT_20000375;
  DAT_20000de0 = DAT_20000376;
  DAT_20000de1 = 0;
  DAT_20000de2 = 0;
  DAT_20000de3 = (undefined1)((ushort)_DAT_200002f0 >> 8);
  DAT_20000de4 = DAT_200002f0;
  DAT_20000de5 = DAT_2000037b;
  DAT_20000de6 = DAT_2000037c;
  DAT_20000de7 = DAT_2000037d;
  DAT_20000de8 = DAT_2000037e;
  DAT_20000de9 = DAT_2000037f;
  DAT_20000dea = DAT_2000029f;
  if (DAT_20000380 == '\x03') {
    DAT_20000dea = 3;
  }
  DAT_20000deb = DAT_20000381;
  DAT_20000dec = DAT_20000382;
  DAT_20000ded = DAT_20000383;
  DAT_20000dee = DAT_20000384;
  DAT_20000def = DAT_20000385;
  DAT_20000df0 = DAT_20000386;
  DAT_20000df1 = DAT_20000387;
  DAT_20000df2 = DAT_20000388;
  DAT_20000df3 = DAT_20000389;
  DAT_20000df4 = DAT_2000038a;
  DAT_20000df5 = DAT_2000038b;
  DAT_20000df6 = DAT_2000038c;
  DAT_20000df7 = DAT_2000038d;
  DAT_20000df8 = DAT_2000038e;
  DAT_20000df9 = DAT_20000390;
  DAT_20000dfa = DAT_20000064 ^ 1;
  DAT_20000dfb = DAT_2000033e;
  DAT_20000dfc = DAT_2000033f;
  DAT_20000dfd = DAT_20000340;
  DAT_20000dfe = DAT_20000341;
  DAT_20000dff = DAT_20000342;
  DAT_20000e00 = DAT_20000343;
  DAT_20000e01 = DAT_20000344;
  DAT_20000e02 = DAT_20000345;
  DAT_20000e03 = DAT_20000346;
  DAT_20000e04 = DAT_20000347;
  DAT_20000e05 = DAT_20000348;
  DAT_20000e06 = DAT_20000349;
  DAT_20000e07 = DAT_2000034a;
  DAT_20000e08 = DAT_2000034b;
  DAT_20000e09 = DAT_2000034c;
  DAT_20000e0a = DAT_2000034d;
  DAT_20000e0b = DAT_2000034e;
  DAT_20000e0c = DAT_2000034f;
  DAT_20000e0d = DAT_20000350;
  DAT_20000e0e = DAT_20000351;
  DAT_20000e0f = DAT_20000352;
  DAT_20000e10 = DAT_20000353;
  DAT_20000e11 = DAT_20000354;
  DAT_20000e12 = DAT_20000355;
  DAT_20000e13 = DAT_20000356;
  DAT_20000e14 = DAT_20000357;
  DAT_20000e15 = DAT_20000358;
  DAT_20000e16 = DAT_20000359;
  DAT_20000e17 = DAT_2000035a;
  DAT_20000e18 = DAT_2000035b;
  DAT_20000e19 = DAT_2000035c;
  DAT_20000e1a = DAT_2000035d;
  _DAT_20000e22 = _DAT_2000018e;
  _DAT_20000e1c = _DAT_2000012e;
  _DAT_20000e24 = _DAT_200001a6;
  _DAT_20000e1e = _DAT_20000146;
  _DAT_20000e26 = _DAT_20000176;
  _DAT_20000e20 = _DAT_20000116;
  _DAT_20000e2a = _DAT_200001d0;
  _DAT_20000e28 = _DAT_20000200;
  DAT_200003c1 = DAT_200000e6;
  DAT_200003c2 = DAT_200000fe;
  DAT_200003bf = DAT_200000b6;
  DAT_200003c0 = DAT_200000ce;
  DAT_200003c5 = *_FUN_0800cd1c;
  DAT_200003c6 = *puRam0800cd20;
  DAT_200003c3 = DAT_2000024e;
  DAT_200003c4 = DAT_20000266;
  bVar2 = DAT_200002a1;
  if (DAT_20000309 != '\0') {
    bVar2 = 0;
  }
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d0b) = DAT_200002a0;
  *(byte *)((uint)DAT_200002a1 * 0x10 + 0x20000d0c) = bVar2;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d19) = DAT_200002a2;
  *(byte *)((uint)DAT_200002a1 * 0x10 + 0x20000d0d) = DAT_200002a3;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d0e) = DAT_200002a4;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d0f) = DAT_200002a5;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d10) = DAT_200002a6;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d11) = (&DAT_200002ad)[DAT_200002a1];
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d12) = (&DAT_200002a7)[DAT_200002a1];
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d13) = (&DAT_200002b3)[DAT_200002a1];
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d14) = DAT_200002b9;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d16) = (&DAT_200002ba)[DAT_200002a1];
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d15) = (&DAT_200002c0)[DAT_200002a1];
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d17) = DAT_200002c6;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d18) = DAT_200002c7;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d1a) = DAT_20000307;
  DAT_20000d73 = DAT_200002db;
  if ((DAT_200002a3 & 0x80) == 0) {
    bVar2 = 0;
  }
  else {
    bVar2 = 8;
  }
  DAT_20000d74 = DAT_200002dc & 0xf7 | bVar2;
  DAT_200003ec = DAT_200003ec + 1;
  uVar1 = ((int)(uint)DAT_200003ec >> 2) + ((int)(uint)DAT_200003ec >> 3) * -2 & 0xff;
  if ((500 < _DAT_20000034) && (uVar1 == 1)) {
    DAT_20000d74 = DAT_20000d74 | 0x20;
  }
  if ((500 < _DAT_20000036) && (uVar1 == 1)) {
    DAT_20000d74 = DAT_20000d74 | 0x40;
  }
  if (500 < _DAT_20000032) {
    DAT_20000d74 = DAT_20000d74 | 0x10;
  }
  if (DAT_200002cd == '\0') {
    DAT_20000d74 = DAT_20000d74 & 0x7f;
  }
  else {
    DAT_20000d74 = DAT_20000d74 | 0x80;
  }
  DAT_20000d75 = (char)((ushort)_DAT_200002de >> 8);
  DAT_20000d76 = (char)_DAT_200002de;
  DAT_20000d77 = DAT_200002e0;
  DAT_20000d78 = (char)((ushort)_DAT_200002e2 >> 8);
  DAT_20000d79 = (char)_DAT_200002e2;
  DAT_20000d7a = DAT_200002e4;
  DAT_20000d6b = DAT_200002e6;
  DAT_20000d6c = DAT_200002dc & 0xf7 | DAT_200002e7 & 8;
  if ((500 < _DAT_20000034) && (uVar1 == 1)) {
    DAT_20000d6c = DAT_20000d6c | 0x20;
  }
  if ((500 < _DAT_20000036) && (uVar1 == 1)) {
    DAT_20000d6c = DAT_20000d6c | 0x40;
  }
  if (500 < _DAT_20000032) {
    DAT_20000d6c = DAT_20000d6c | 0x10;
  }
  if (DAT_200002cd == '\0') {
    DAT_20000d6c = DAT_20000d6c & 0x7f;
  }
  else {
    DAT_20000d6c = DAT_20000d6c | 0x80;
  }
  DAT_20000d6d = (char)((ushort)_DAT_200002e8 >> 8);
  DAT_20000d6e = (char)_DAT_200002e8;
  DAT_20000d6f = DAT_200002ea;
  DAT_20000d70 = (char)((ushort)_DAT_200002ec >> 8);
  DAT_20000d71 = (char)_DAT_200002ec;
  DAT_20000d72 = DAT_200002ee;
  DAT_20000d7b = (char)((ushort)_DAT_200002f4 >> 8);
  DAT_20000d7c = (char)_DAT_200002f4;
  DAT_20000d7d = (char)((ushort)_DAT_200002f8 >> 8);
  DAT_20000d7e = (char)_DAT_200002f8;
  DAT_20000d7f = (char)((ushort)_DAT_200002fe >> 8);
  DAT_20000d80 = DAT_200002fe;
  DAT_20000d81 = (char)(_DAT_20000300 / 10 >> 0x10);
  DAT_20000d82 = (char)(_DAT_20000300 / 10 >> 8);
  DAT_20000d83 = (char)(_DAT_20000300 / 10);
  DAT_20000d84 = (char)((ushort)_DAT_20000304 >> 8);
  DAT_20000d85 = DAT_20000304;
  DAT_20000d86 = DAT_200002ce;
  DAT_20000d87 = DAT_200002cf;
  DAT_20000d88 = DAT_200002d0;
  DAT_20000d89 = 0;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800c764   (0x0800C764, 1019 Bytes)
 * Body: 0x0800C764-0x0800CB5F
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0800c764(void)

{
  uint uVar1;
  byte bVar2;
  undefined1 unaff_r7;
  int in_r12;
  
  *(undefined1 *)(in_r12 + 4) = unaff_r7;
  *(undefined1 *)(in_r12 + 5) = DAT_20000333;
  *(undefined1 *)(in_r12 + 6) = DAT_20000334;
  *(undefined1 *)(in_r12 + 7) = DAT_20000335;
  *(undefined1 *)(in_r12 + 8) = DAT_20000336;
  *(undefined1 *)(in_r12 + 9) = DAT_20000337;
  *(undefined1 *)(in_r12 + 10) = DAT_20000338;
  *(undefined1 *)(in_r12 + 0xb) = DAT_20000339;
  *(undefined1 *)(in_r12 + 0xc) = DAT_2000033a;
  *(undefined1 *)(in_r12 + 0xd) = DAT_2000033b;
  *(undefined1 *)(in_r12 + 0xe) = DAT_2000033c;
  *(undefined1 *)(in_r12 + 0xf) = DAT_2000033d;
  DAT_20000dc8 = DAT_2000035e;
  DAT_20000dc9 = DAT_2000035f;
  DAT_20000dca = DAT_20000360;
  DAT_20000dcb = DAT_20000361;
  DAT_20000dcc = DAT_20000362;
  DAT_20000dcd = DAT_20000363;
  DAT_20000dce = DAT_20000364;
  DAT_20000dcf = DAT_20000365;
  DAT_20000dd0 = DAT_20000366;
  DAT_20000dd1 = DAT_20000367;
  DAT_20000dd2 = DAT_20000367;
  DAT_20000dd3 = DAT_20000369;
  DAT_20000dd4 = DAT_2000036a;
  DAT_20000dd5 = DAT_2000036b;
  DAT_20000dd6 = DAT_2000036c;
  DAT_20000dd7 = DAT_2000036d;
  DAT_20000dd8 = DAT_2000036e;
  DAT_20000dd9 = DAT_2000036f;
  DAT_20000dda = DAT_20000370;
  DAT_20000ddb = DAT_20000371;
  DAT_20000ddc = DAT_20000372;
  DAT_20000ddd = DAT_20000373;
  DAT_20000dde = DAT_20000374;
  DAT_20000ddf = DAT_20000375;
  DAT_20000de0 = DAT_20000376;
  DAT_20000de1 = 0;
  DAT_20000de2 = 0;
  DAT_20000de3 = (undefined1)((ushort)_DAT_200002f0 >> 8);
  DAT_20000de4 = DAT_200002f0;
  DAT_20000de5 = DAT_2000037b;
  DAT_20000de6 = DAT_2000037c;
  DAT_20000de7 = DAT_2000037d;
  DAT_20000de8 = DAT_2000037e;
  DAT_20000de9 = DAT_2000037f;
  DAT_20000dea = DAT_2000029f;
  if (DAT_20000380 == '\x03') {
    DAT_20000dea = 3;
  }
  DAT_20000deb = DAT_20000381;
  DAT_20000dec = DAT_20000382;
  DAT_20000ded = DAT_20000383;
  DAT_20000dee = DAT_20000384;
  DAT_20000def = DAT_20000385;
  DAT_20000df0 = DAT_20000386;
  DAT_20000df1 = DAT_20000387;
  DAT_20000df2 = DAT_20000388;
  DAT_20000df3 = DAT_20000389;
  DAT_20000df4 = DAT_2000038a;
  DAT_20000df5 = DAT_2000038b;
  DAT_20000df6 = DAT_2000038c;
  DAT_20000df7 = DAT_2000038d;
  DAT_20000df8 = DAT_2000038e;
  DAT_20000df9 = DAT_20000390;
  DAT_20000dfa = DAT_20000064 ^ 1;
  DAT_20000dfb = DAT_2000033e;
  DAT_20000dfc = DAT_2000033f;
  DAT_20000dfd = DAT_20000340;
  DAT_20000dfe = DAT_20000341;
  DAT_20000dff = DAT_20000342;
  DAT_20000e00 = DAT_20000343;
  DAT_20000e01 = DAT_20000344;
  DAT_20000e02 = DAT_20000345;
  DAT_20000e03 = DAT_20000346;
  DAT_20000e04 = DAT_20000347;
  DAT_20000e05 = DAT_20000348;
  DAT_20000e06 = DAT_20000349;
  DAT_20000e07 = DAT_2000034a;
  DAT_20000e08 = DAT_2000034b;
  DAT_20000e09 = DAT_2000034c;
  DAT_20000e0a = DAT_2000034d;
  DAT_20000e0b = DAT_2000034e;
  DAT_20000e0c = DAT_2000034f;
  DAT_20000e0d = DAT_20000350;
  DAT_20000e0e = DAT_20000351;
  DAT_20000e0f = DAT_20000352;
  DAT_20000e10 = DAT_20000353;
  DAT_20000e11 = DAT_20000354;
  DAT_20000e12 = DAT_20000355;
  DAT_20000e13 = DAT_20000356;
  DAT_20000e14 = DAT_20000357;
  DAT_20000e15 = DAT_20000358;
  DAT_20000e16 = DAT_20000359;
  DAT_20000e17 = DAT_2000035a;
  DAT_20000e18 = DAT_2000035b;
  DAT_20000e19 = DAT_2000035c;
  DAT_20000e1a = DAT_2000035d;
  _DAT_20000e22 = _DAT_2000018e;
  _DAT_20000e1c = _DAT_2000012e;
  _DAT_20000e24 = _DAT_200001a6;
  _DAT_20000e1e = _DAT_20000146;
  _DAT_20000e26 = _DAT_20000176;
  _DAT_20000e20 = _DAT_20000116;
  _DAT_20000e2a = _DAT_200001d0;
  _DAT_20000e28 = _DAT_20000200;
  DAT_200003c1 = DAT_200000e6;
  DAT_200003c2 = DAT_200000fe;
  DAT_200003bf = DAT_200000b6;
  DAT_200003c0 = DAT_200000ce;
  DAT_200003c5 = *_FUN_0800cd1c;
  DAT_200003c6 = *puRam0800cd20;
  DAT_200003c3 = DAT_2000024e;
  DAT_200003c4 = DAT_20000266;
  bVar2 = DAT_200002a1;
  if (DAT_20000309 != '\0') {
    bVar2 = 0;
  }
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d0b) = DAT_200002a0;
  *(byte *)((uint)DAT_200002a1 * 0x10 + 0x20000d0c) = bVar2;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d19) = DAT_200002a2;
  *(byte *)((uint)DAT_200002a1 * 0x10 + 0x20000d0d) = DAT_200002a3;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d0e) = DAT_200002a4;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d0f) = DAT_200002a5;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d10) = DAT_200002a6;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d11) = (&DAT_200002ad)[DAT_200002a1];
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d12) = (&DAT_200002a7)[DAT_200002a1];
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d13) = (&DAT_200002b3)[DAT_200002a1];
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d14) = DAT_200002b9;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d16) = (&DAT_200002ba)[DAT_200002a1];
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d15) = (&DAT_200002c0)[DAT_200002a1];
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d17) = DAT_200002c6;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d18) = DAT_200002c7;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d1a) = DAT_20000307;
  DAT_20000d73 = DAT_200002db;
  if ((DAT_200002a3 & 0x80) == 0) {
    bVar2 = 0;
  }
  else {
    bVar2 = 8;
  }
  DAT_20000d74 = DAT_200002dc & 0xf7 | bVar2;
  DAT_200003ec = DAT_200003ec + 1;
  uVar1 = ((int)(uint)DAT_200003ec >> 2) + ((int)(uint)DAT_200003ec >> 3) * -2 & 0xff;
  if ((500 < _DAT_20000034) && (uVar1 == 1)) {
    DAT_20000d74 = DAT_20000d74 | 0x20;
  }
  if ((500 < _DAT_20000036) && (uVar1 == 1)) {
    DAT_20000d74 = DAT_20000d74 | 0x40;
  }
  if (500 < _DAT_20000032) {
    DAT_20000d74 = DAT_20000d74 | 0x10;
  }
  if (DAT_200002cd == '\0') {
    DAT_20000d74 = DAT_20000d74 & 0x7f;
  }
  else {
    DAT_20000d74 = DAT_20000d74 | 0x80;
  }
  DAT_20000d75 = (char)((ushort)_DAT_200002de >> 8);
  DAT_20000d76 = (char)_DAT_200002de;
  DAT_20000d77 = DAT_200002e0;
  DAT_20000d78 = (char)((ushort)_DAT_200002e2 >> 8);
  DAT_20000d79 = (char)_DAT_200002e2;
  DAT_20000d7a = DAT_200002e4;
  DAT_20000d6b = DAT_200002e6;
  DAT_20000d6c = DAT_200002dc & 0xf7 | DAT_200002e7 & 8;
  if ((500 < _DAT_20000034) && (uVar1 == 1)) {
    DAT_20000d6c = DAT_20000d6c | 0x20;
  }
  if ((500 < _DAT_20000036) && (uVar1 == 1)) {
    DAT_20000d6c = DAT_20000d6c | 0x40;
  }
  if (500 < _DAT_20000032) {
    DAT_20000d6c = DAT_20000d6c | 0x10;
  }
  if (DAT_200002cd == '\0') {
    DAT_20000d6c = DAT_20000d6c & 0x7f;
  }
  else {
    DAT_20000d6c = DAT_20000d6c | 0x80;
  }
  DAT_20000d6d = (char)((ushort)_DAT_200002e8 >> 8);
  DAT_20000d6e = (char)_DAT_200002e8;
  DAT_20000d6f = DAT_200002ea;
  DAT_20000d70 = (char)((ushort)_DAT_200002ec >> 8);
  DAT_20000d71 = (char)_DAT_200002ec;
  DAT_20000d72 = DAT_200002ee;
  DAT_20000d7b = (char)((ushort)_DAT_200002f4 >> 8);
  DAT_20000d7c = (char)_DAT_200002f4;
  DAT_20000d7d = (char)((ushort)_DAT_200002f8 >> 8);
  DAT_20000d7e = (char)_DAT_200002f8;
  DAT_20000d7f = (char)((ushort)_DAT_200002fe >> 8);
  DAT_20000d80 = DAT_200002fe;
  DAT_20000d81 = (char)(_DAT_20000300 / 10 >> 0x10);
  DAT_20000d82 = (char)(_DAT_20000300 / 10 >> 8);
  DAT_20000d83 = (char)(_DAT_20000300 / 10);
  DAT_20000d84 = (char)((ushort)_DAT_20000304 >> 8);
  DAT_20000d85 = DAT_20000304;
  DAT_20000d86 = DAT_200002ce;
  DAT_20000d87 = DAT_200002cf;
  DAT_20000d88 = DAT_200002d0;
  DAT_20000d89 = 0;
  return;
}


/* ---------------------------------------------------------------------
 * thunk_FUN_0800cd40   (0x0800CB60, 1 Bytes)
 * Body: 0x0800CB60-0x0800CB61
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thunk_FUN_0800cd40(void)

{
  uint uVar1;
  undefined1 unaff_r7;
  byte *unaff_r8;
  byte bVar2;
  int in_r12;
  
  *(undefined1 *)(in_r12 + (uint)*unaff_r8 * 0x10 + 0xe) = unaff_r7;
  *(byte *)((uint)DAT_200002a1 * 0x10 + 0x20000d0d) = DAT_200002a3;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d0e) = DAT_200002a4;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d0f) = DAT_200002a5;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d10) = DAT_200002a6;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d11) = (&DAT_200002ad)[DAT_200002a1];
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d12) = (&DAT_200002a7)[DAT_200002a1];
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d13) = (&DAT_200002b3)[DAT_200002a1];
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d14) = DAT_200002b9;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d16) = (&DAT_200002ba)[DAT_200002a1];
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d15) = (&DAT_200002c0)[DAT_200002a1];
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d17) = DAT_200002c6;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d18) = DAT_200002c7;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d1a) = DAT_20000307;
  DAT_20000d73 = DAT_200002db;
  if ((DAT_200002a3 & 0x80) == 0) {
    bVar2 = 0;
  }
  else {
    bVar2 = 8;
  }
  DAT_20000d74 = DAT_200002dc & 0xf7 | bVar2;
  DAT_200003ec = DAT_200003ec + 1;
  uVar1 = ((int)(uint)DAT_200003ec >> 2) + ((int)(uint)DAT_200003ec >> 3) * -2 & 0xff;
  if ((500 < _DAT_20000034) && (uVar1 == 1)) {
    DAT_20000d74 = DAT_20000d74 | 0x20;
  }
  if ((500 < _DAT_20000036) && (uVar1 == 1)) {
    DAT_20000d74 = DAT_20000d74 | 0x40;
  }
  if (500 < _DAT_20000032) {
    DAT_20000d74 = DAT_20000d74 | 0x10;
  }
  if (DAT_200002cd == '\0') {
    DAT_20000d74 = DAT_20000d74 & 0x7f;
  }
  else {
    DAT_20000d74 = DAT_20000d74 | 0x80;
  }
  DAT_20000d75 = (char)((ushort)_DAT_200002de >> 8);
  DAT_20000d76 = (char)_DAT_200002de;
  DAT_20000d77 = DAT_200002e0;
  DAT_20000d78 = (char)((ushort)_DAT_200002e2 >> 8);
  DAT_20000d79 = (char)_DAT_200002e2;
  DAT_20000d7a = DAT_200002e4;
  DAT_20000d6b = DAT_200002e6;
  DAT_20000d6c = DAT_200002dc & 0xf7 | DAT_200002e7 & 8;
  if ((500 < _DAT_20000034) && (uVar1 == 1)) {
    DAT_20000d6c = DAT_20000d6c | 0x20;
  }
  if ((500 < _DAT_20000036) && (uVar1 == 1)) {
    DAT_20000d6c = DAT_20000d6c | 0x40;
  }
  if (500 < _DAT_20000032) {
    DAT_20000d6c = DAT_20000d6c | 0x10;
  }
  if (DAT_200002cd == '\0') {
    DAT_20000d6c = DAT_20000d6c & 0x7f;
  }
  else {
    DAT_20000d6c = DAT_20000d6c | 0x80;
  }
  DAT_20000d6d = (char)((ushort)_DAT_200002e8 >> 8);
  DAT_20000d6e = (char)_DAT_200002e8;
  DAT_20000d6f = DAT_200002ea;
  DAT_20000d70 = (char)((ushort)_DAT_200002ec >> 8);
  DAT_20000d71 = (char)_DAT_200002ec;
  DAT_20000d72 = DAT_200002ee;
  DAT_20000d7b = (char)((ushort)_DAT_200002f4 >> 8);
  DAT_20000d7c = (char)_DAT_200002f4;
  DAT_20000d7d = (char)((ushort)_DAT_200002f8 >> 8);
  DAT_20000d7e = (char)_DAT_200002f8;
  DAT_20000d7f = (char)((ushort)_DAT_200002fe >> 8);
  DAT_20000d80 = DAT_200002fe;
  DAT_20000d81 = (char)(_DAT_20000300 / 10 >> 0x10);
  DAT_20000d82 = (char)(_DAT_20000300 / 10 >> 8);
  DAT_20000d83 = (char)(_DAT_20000300 / 10);
  DAT_20000d84 = (char)((ushort)_DAT_20000304 >> 8);
  DAT_20000d85 = DAT_20000304;
  DAT_20000d86 = DAT_200002ce;
  DAT_20000d87 = DAT_200002cf;
  DAT_20000d88 = DAT_200002d0;
  DAT_20000d89 = 0;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800cd1c   (0x0800CD1C, 35 Bytes)
 * Body: 0x0800CD1C-0x0800CD3F
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0800cd1c(void)

{
  uint uVar1;
  undefined1 unaff_r7;
  byte *unaff_r8;
  byte bVar2;
  int in_r12;
  
  *(undefined1 *)(in_r12 + (uint)*unaff_r8 * 0x10 + 0xe) = unaff_r7;
  *(byte *)((uint)DAT_200002a1 * 0x10 + 0x20000d0d) = DAT_200002a3;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d0e) = DAT_200002a4;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d0f) = DAT_200002a5;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d10) = DAT_200002a6;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d11) = (&DAT_200002ad)[DAT_200002a1];
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d12) = (&DAT_200002a7)[DAT_200002a1];
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d13) = (&DAT_200002b3)[DAT_200002a1];
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d14) = DAT_200002b9;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d16) = (&DAT_200002ba)[DAT_200002a1];
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d15) = (&DAT_200002c0)[DAT_200002a1];
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d17) = DAT_200002c6;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d18) = DAT_200002c7;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d1a) = DAT_20000307;
  DAT_20000d73 = DAT_200002db;
  if ((DAT_200002a3 & 0x80) == 0) {
    bVar2 = 0;
  }
  else {
    bVar2 = 8;
  }
  DAT_20000d74 = DAT_200002dc & 0xf7 | bVar2;
  DAT_200003ec = DAT_200003ec + 1;
  uVar1 = ((int)(uint)DAT_200003ec >> 2) + ((int)(uint)DAT_200003ec >> 3) * -2 & 0xff;
  if ((500 < _DAT_20000034) && (uVar1 == 1)) {
    DAT_20000d74 = DAT_20000d74 | 0x20;
  }
  if ((500 < _DAT_20000036) && (uVar1 == 1)) {
    DAT_20000d74 = DAT_20000d74 | 0x40;
  }
  if (500 < _DAT_20000032) {
    DAT_20000d74 = DAT_20000d74 | 0x10;
  }
  if (DAT_200002cd == '\0') {
    DAT_20000d74 = DAT_20000d74 & 0x7f;
  }
  else {
    DAT_20000d74 = DAT_20000d74 | 0x80;
  }
  DAT_20000d75 = (char)((ushort)_DAT_200002de >> 8);
  DAT_20000d76 = (char)_DAT_200002de;
  DAT_20000d77 = DAT_200002e0;
  DAT_20000d78 = (char)((ushort)_DAT_200002e2 >> 8);
  DAT_20000d79 = (char)_DAT_200002e2;
  DAT_20000d7a = DAT_200002e4;
  DAT_20000d6b = DAT_200002e6;
  DAT_20000d6c = DAT_200002dc & 0xf7 | DAT_200002e7 & 8;
  if ((500 < _DAT_20000034) && (uVar1 == 1)) {
    DAT_20000d6c = DAT_20000d6c | 0x20;
  }
  if ((500 < _DAT_20000036) && (uVar1 == 1)) {
    DAT_20000d6c = DAT_20000d6c | 0x40;
  }
  if (500 < _DAT_20000032) {
    DAT_20000d6c = DAT_20000d6c | 0x10;
  }
  if (DAT_200002cd == '\0') {
    DAT_20000d6c = DAT_20000d6c & 0x7f;
  }
  else {
    DAT_20000d6c = DAT_20000d6c | 0x80;
  }
  DAT_20000d6d = (char)((ushort)_DAT_200002e8 >> 8);
  DAT_20000d6e = (char)_DAT_200002e8;
  DAT_20000d6f = DAT_200002ea;
  DAT_20000d70 = (char)((ushort)_DAT_200002ec >> 8);
  DAT_20000d71 = (char)_DAT_200002ec;
  DAT_20000d72 = DAT_200002ee;
  DAT_20000d7b = (char)((ushort)_DAT_200002f4 >> 8);
  DAT_20000d7c = (char)_DAT_200002f4;
  DAT_20000d7d = (char)((ushort)_DAT_200002f8 >> 8);
  DAT_20000d7e = (char)_DAT_200002f8;
  DAT_20000d7f = (char)((ushort)_DAT_200002fe >> 8);
  DAT_20000d80 = DAT_200002fe;
  DAT_20000d81 = (char)(_DAT_20000300 / 10 >> 0x10);
  DAT_20000d82 = (char)(_DAT_20000300 / 10 >> 8);
  DAT_20000d83 = (char)(_DAT_20000300 / 10);
  DAT_20000d84 = (char)((ushort)_DAT_20000304 >> 8);
  DAT_20000d85 = DAT_20000304;
  DAT_20000d86 = DAT_200002ce;
  DAT_20000d87 = DAT_200002cf;
  DAT_20000d88 = DAT_200002d0;
  DAT_20000d89 = 0;
  return 0;
}


/* ---------------------------------------------------------------------
 * FUN_0800cd40   (0x0800CD40, 1023 Bytes, 2 Teile)
 * Body: 0x0800CD40-0x0800D13F, 0x0800D141-0x0800D141
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0800cd40(void)

{
  uint uVar1;
  undefined1 unaff_r7;
  byte *unaff_r8;
  byte bVar2;
  int in_r12;
  
  *(undefined1 *)(in_r12 + (uint)*unaff_r8 * 0x10 + 0xe) = unaff_r7;
  *(byte *)((uint)DAT_200002a1 * 0x10 + 0x20000d0d) = DAT_200002a3;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d0e) = DAT_200002a4;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d0f) = DAT_200002a5;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d10) = DAT_200002a6;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d11) = (&DAT_200002ad)[DAT_200002a1];
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d12) = (&DAT_200002a7)[DAT_200002a1];
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d13) = (&DAT_200002b3)[DAT_200002a1];
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d14) = DAT_200002b9;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d16) = (&DAT_200002ba)[DAT_200002a1];
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d15) = (&DAT_200002c0)[DAT_200002a1];
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d17) = DAT_200002c6;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d18) = DAT_200002c7;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d1a) = DAT_20000307;
  DAT_20000d73 = DAT_200002db;
  if ((DAT_200002a3 & 0x80) == 0) {
    bVar2 = 0;
  }
  else {
    bVar2 = 8;
  }
  DAT_20000d74 = DAT_200002dc & 0xf7 | bVar2;
  DAT_200003ec = DAT_200003ec + 1;
  uVar1 = ((int)(uint)DAT_200003ec >> 2) + ((int)(uint)DAT_200003ec >> 3) * -2 & 0xff;
  if ((500 < _DAT_20000034) && (uVar1 == 1)) {
    DAT_20000d74 = DAT_20000d74 | 0x20;
  }
  if ((500 < _DAT_20000036) && (uVar1 == 1)) {
    DAT_20000d74 = DAT_20000d74 | 0x40;
  }
  if (500 < _DAT_20000032) {
    DAT_20000d74 = DAT_20000d74 | 0x10;
  }
  if (DAT_200002cd == '\0') {
    DAT_20000d74 = DAT_20000d74 & 0x7f;
  }
  else {
    DAT_20000d74 = DAT_20000d74 | 0x80;
  }
  DAT_20000d75 = (char)((ushort)_DAT_200002de >> 8);
  DAT_20000d76 = (char)_DAT_200002de;
  DAT_20000d77 = DAT_200002e0;
  DAT_20000d78 = (char)((ushort)_DAT_200002e2 >> 8);
  DAT_20000d79 = (char)_DAT_200002e2;
  DAT_20000d7a = DAT_200002e4;
  DAT_20000d6b = DAT_200002e6;
  DAT_20000d6c = DAT_200002dc & 0xf7 | DAT_200002e7 & 8;
  if ((500 < _DAT_20000034) && (uVar1 == 1)) {
    DAT_20000d6c = DAT_20000d6c | 0x20;
  }
  if ((500 < _DAT_20000036) && (uVar1 == 1)) {
    DAT_20000d6c = DAT_20000d6c | 0x40;
  }
  if (500 < _DAT_20000032) {
    DAT_20000d6c = DAT_20000d6c | 0x10;
  }
  if (DAT_200002cd == '\0') {
    DAT_20000d6c = DAT_20000d6c & 0x7f;
  }
  else {
    DAT_20000d6c = DAT_20000d6c | 0x80;
  }
  DAT_20000d6d = (char)((ushort)_DAT_200002e8 >> 8);
  DAT_20000d6e = (char)_DAT_200002e8;
  DAT_20000d6f = DAT_200002ea;
  DAT_20000d70 = (char)((ushort)_DAT_200002ec >> 8);
  DAT_20000d71 = (char)_DAT_200002ec;
  DAT_20000d72 = DAT_200002ee;
  DAT_20000d7b = (char)((ushort)_DAT_200002f4 >> 8);
  DAT_20000d7c = (char)_DAT_200002f4;
  DAT_20000d7d = (char)((ushort)_DAT_200002f8 >> 8);
  DAT_20000d7e = (char)_DAT_200002f8;
  DAT_20000d7f = (char)((ushort)_DAT_200002fe >> 8);
  DAT_20000d80 = DAT_200002fe;
  DAT_20000d81 = (char)(_DAT_20000300 / 10 >> 0x10);
  DAT_20000d82 = (char)(_DAT_20000300 / 10 >> 8);
  DAT_20000d83 = (char)(_DAT_20000300 / 10);
  DAT_20000d84 = (char)((ushort)_DAT_20000304 >> 8);
  DAT_20000d85 = DAT_20000304;
  DAT_20000d86 = DAT_200002ce;
  DAT_20000d87 = DAT_200002cf;
  DAT_20000d88 = DAT_200002d0;
  DAT_20000d89 = 0;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800d1ec   (0x0800D1EC, 127 Bytes)
 * Body: 0x0800D1EC-0x0800D26B
 * --------------------------------------------------------------------- */
void FUN_0800d1ec(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_20;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  local_20 = param_4;
  uStack_10 = param_1;
  uStack_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  FUN_0800b990((undefined1 *)&local_20,(undefined1 *)((int)&uStack_10 + 2),4);
  if ((((char)local_20 != -1) || (local_20._1_1_ != 0xff)) || (local_20._2_1_ != 0xff)) {
    DAT_200002ce = (char)local_20;
    DAT_200002cf = local_20._1_1_;
    DAT_200002d0 = local_20._2_1_;
    if ((0x19 < local_20._1_1_) || ((local_20._1_1_ != 0 && (local_20._1_1_ < 10)))) {
      DAT_200002cf = 0;
    }
    if (100 < local_20._2_1_) {
      DAT_200002d0 = 0;
    }
  }
  if (local_20._3_1_ == -0x78) {
    FUN_08017e1a();
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800d26c   (0x0800D26C, 111 Bytes)
 * Body: 0x0800D26C-0x0800D2DB
 * --------------------------------------------------------------------- */
void FUN_0800d26c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  byte local_2c [16];
  byte local_1c;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uVar1 = 0;
  uStack_10 = param_1;
  uStack_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  FUN_0800b990(local_2c,(undefined1 *)((int)&uStack_10 + 2),0x11);
  if ((0x2f < local_2c[0]) && (local_2c[0] < 0x7b)) {
    DAT_20000051 = 1;
    for (; uVar1 < 0x10; uVar1 = uVar1 + 1 & 0xff) {
      *(byte *)(uVar1 + 0x20000cea) = local_2c[uVar1];
    }
    for (uVar1 = 0x10; uVar1 < 0x13; uVar1 = uVar1 + 1 & 0xff) {
      *(undefined1 *)(uVar1 + 0x20000cea) = 0x20;
    }
    if ((0x2f < local_1c) && (local_1c < 0x7b)) {
      DAT_20000cfa = local_1c;
    }
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800d2dc   (0x0800D2DC, 597 Bytes)
 * Body: 0x0800D2DC-0x0800D531
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0800d2dc(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  bool bVar2;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  uint uStack_4;
  
  local_30 = param_1;
  uStack_2c = param_2;
  uStack_28 = param_3;
  uStack_24 = param_4;
  uStack_10 = param_1;
  uStack_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  FUN_0800b990((undefined1 *)&local_30,(undefined1 *)((int)&uStack_10 + 2),0x10);
  if (((char)local_30 == '\x01') && (DAT_20000309 == '\0')) {
    DAT_200002a1 = local_30._1_1_;
    if (5 < local_30._1_1_) {
      DAT_200002a1 = 5;
    }
  }
  else {
    bVar2 = (char)local_30 == '\x02';
    do {
      if (!bVar2) {
        if ((char)local_30 == '\x03') {
          if ((uStack_24 & 0x10000) != 0) {
            _DAT_200002d4 = 1;
            DAT_200002d8 = (char)local_30;
            DAT_200002da = DAT_200002da | 1;
            DAT_20000309 = 1;
            return;
          }
          _DAT_200002d4 = 1;
          DAT_200002d8 = (char)local_30;
          DAT_200002da = DAT_200002da & 0xfe;
          DAT_20000309 = 0;
          return;
        }
        if ((char)local_30 == '\x04') {
          if ((uStack_24 & 0x20000) != 0) {
            _DAT_200002d4 = 1;
            DAT_200002d8 = (char)local_30;
            DAT_200002da = DAT_200002da | 2;
            DAT_20000308 = 1;
            return;
          }
          _DAT_200002d4 = 1;
          DAT_200002d8 = (char)local_30;
          DAT_200002da = DAT_200002da & 0xfd;
          DAT_20000308 = 0;
          return;
        }
        if ((char)local_30 != '\x05') {
          _DAT_200002d4 = 1;
          DAT_200002d8 = 0;
          return;
        }
        if ((uStack_24 & 0x100000) != 0) {
          _DAT_200002d4 = 1;
          DAT_200002d8 = (char)local_30;
          DAT_200002da = DAT_200002da | 0x10;
          DAT_20000312 = 1;
          return;
        }
        _DAT_200002d4 = 1;
        DAT_200002d8 = (char)local_30;
        DAT_200002da = DAT_200002da & 0xef;
        DAT_20000312 = 0;
        return;
      }
      bVar2 = DAT_20000309 == '\0';
    } while (!bVar2);
    _DAT_200002d4 = 1;
    DAT_200002d8 = (char)local_30;
    uVar1 = (uint)local_30._1_1_;
    DAT_200002d9 = local_30._2_1_;
    DAT_2000030a = (local_30._2_1_ & 4) == 4;
    DAT_200002a2 = local_30._2_1_ & 0x7f | uStack_24._3_1_ & 0x80;
    DAT_200002a3 = local_30._2_1_;
    if (uVar1 < 6) {
      FUN_0800b990((undefined1 *)(uVar1 * 0x10 + 0x20000c8a),(undefined1 *)&local_30,0x10);
      DAT_200002a4 = *(undefined1 *)(uVar1 * 0x10 + 0x20000c8d);
      DAT_200002a5 = *(undefined1 *)(uVar1 * 0x10 + 0x20000c8e);
      DAT_200002a6 = *(undefined1 *)(uVar1 * 0x10 + 0x20000c8f);
      (&DAT_200002a7)[uVar1] = *(undefined1 *)(uVar1 * 0x10 + 0x20000c91);
      (&DAT_200002b3)[uVar1] = *(undefined1 *)(uVar1 * 0x10 + 0x20000c92);
      DAT_200002b9 = *(undefined1 *)(uVar1 * 0x10 + 0x20000c93);
      (&DAT_200002ba)[uVar1] = *(undefined1 *)(uVar1 * 0x10 + 0x20000c95);
      DAT_200002c6 = *(undefined1 *)(uVar1 * 0x10 + 0x20000c96);
      DAT_200002c7 = *(undefined1 *)(uVar1 * 0x10 + 0x20000c97);
      if ((*(byte *)(uVar1 * 0x10 + 0x20000c98) & 4) == 0) {
        DAT_200002da = DAT_200002da & 0xfb;
      }
      else {
        DAT_200002da = DAT_200002da | 4;
      }
      (&DAT_200002ad)[uVar1] = *(undefined1 *)(uVar1 * 0x10 + 0x20000c90);
      (&DAT_200002c0)[uVar1] = *(undefined1 *)(uVar1 * 0x10 + 0x20000c94);
      return;
    }
  }
  DAT_200002d8 = (char)local_30;
  _DAT_200002d4 = 1;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800d532   (0x0800D532, 151 Bytes)
 * Body: 0x0800D532-0x0800D5C9
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0800d532(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_10 = param_1;
  uStack_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  FUN_0800b990(&DAT_20000c80,(undefined1 *)((int)&uStack_10 + 2),10);
  if (DAT_20000c80 != 0xff) {
    _DAT_200000b6 = (ushort)DAT_20000c80;
  }
  if (DAT_20000c81 != 0xff) {
    _DAT_200000ce = (ushort)DAT_20000c81;
  }
  if (DAT_20000c82 != 0xff) {
    _DAT_200000e6 = (ushort)DAT_20000c82;
  }
  if (DAT_20000c83 != 0xff) {
    _DAT_200000fe = (ushort)DAT_20000c83;
  }
  if (DAT_20000c84 != 0xff) {
    _DAT_2000024e = (ushort)DAT_20000c84;
  }
  if (DAT_20000c85 != 0xff) {
    _DAT_20000266 = (ushort)DAT_20000c85;
  }
  if (DAT_20000c86 != 0xff) {
    _DAT_2000027e = (ushort)DAT_20000c86;
  }
  if (DAT_20000c87 != 0xff) {
    _DAT_20000296 = (ushort)DAT_20000c87;
  }
  return 6;
}


/* ---------------------------------------------------------------------
 * FUN_0800d5ca   (0x0800D5CA, 184 Bytes, 2 Teile)
 * Body: 0x0800D5CA-0x0800D613, 0x0800D6B4-0x0800D723
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0800d5ca(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_10 = param_1;
  uStack_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  FUN_0800b990(&DAT_20000c70,(undefined1 *)((int)&uStack_10 + 2),0x10);
  if (_DAT_20000c70 != -1) {
    _DAT_2000012e = _DAT_20000c70;
  }
  if (_DAT_20000c72 != -1) {
    _DAT_20000146 = _DAT_20000c72;
  }
  if (_DAT_20000c74 != -1) {
    _DAT_20000116 = _DAT_20000c74;
  }
  if (_DAT_20000c76 != -1) {
    _DAT_2000018e = _DAT_20000c76;
  }
  if (_DAT_20000c78 != -1) {
    _DAT_200001a6 = _DAT_20000c78;
  }
  if (_DAT_20000c7a != -1) {
    _DAT_20000176 = _DAT_20000c7a;
  }
  if (_DAT_20000c7c != 0xffff) {
    _DAT_20000200 = (uint)_DAT_20000c7c;
  }
  if (_DAT_20000c7e != 0xffff) {
    _DAT_200001d0 = (uint)_DAT_20000c7e;
  }
  return 6;
}


/* ---------------------------------------------------------------------
 * thunk_FUN_0800d6b4   (0x0800D612, 1 Bytes)
 * Body: 0x0800D612-0x0800D613
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thunk_FUN_0800d6b4(undefined2 param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  
  if (_DAT_20000c76 != -1) {
    _DAT_2000018e = _DAT_20000c76;
  }
  if (_DAT_20000c78 != -1) {
    _DAT_200001a6 = _DAT_20000c78;
  }
  if (_DAT_20000c7a != -1) {
    _DAT_20000176 = _DAT_20000c7a;
  }
  if (_DAT_20000c7c != 0xffff) {
    _DAT_20000200 = (uint)_DAT_20000c7c;
  }
  if (_DAT_20000c7e != 0xffff) {
    _DAT_200001d0 = (uint)_DAT_20000c7e;
  }
  _DAT_20000116 = param_1;
                    /* WARNING: Could not recover jumptable at 0x0800d720. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(6);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800d6b4   (0x0800D6B4, 111 Bytes)
 * Body: 0x0800D6B4-0x0800D723
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0800d6b4(undefined2 param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  
  if (_DAT_20000c76 != -1) {
    _DAT_2000018e = _DAT_20000c76;
  }
  if (_DAT_20000c78 != -1) {
    _DAT_200001a6 = _DAT_20000c78;
  }
  if (_DAT_20000c7a != -1) {
    _DAT_20000176 = _DAT_20000c7a;
  }
  if (_DAT_20000c7c != 0xffff) {
    _DAT_20000200 = (uint)_DAT_20000c7c;
  }
  if (_DAT_20000c7e != 0xffff) {
    _DAT_200001d0 = (uint)_DAT_20000c7e;
  }
  _DAT_20000116 = param_1;
                    /* WARNING: Could not recover jumptable at 0x0800d720. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(6);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800d724   (0x0800D724, 365 Bytes)
 * Body: 0x0800D724-0x0800D891
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0800d724(void)

{
  if (DAT_200003b1 != -1) {
    if (DAT_200003b1 == '\n') {
      if ((DAT_200003b2 == 1) && (DAT_2000032c == '\0')) {
        DAT_2000032b = DAT_2000031f;
        DAT_2000031f = '\0';
        DAT_20000324 = DAT_20000321;
        DAT_20000325 = DAT_20000322;
        DAT_20000326 = DAT_20000323;
        DAT_20000321 = 0;
        DAT_20000322 = 0;
        DAT_20000323 = 0;
        FUN_080117bc(0,0,0);
        DAT_2000032c = '\x01';
      }
      else if (DAT_2000032c == '\x01') {
        DAT_2000031f = DAT_2000032b;
        DAT_2000032c = '\0';
        FUN_080117bc((uint)DAT_20000321,(uint)DAT_20000322,(uint)DAT_20000323);
      }
      else {
        DAT_2000032c = '\0';
        FUN_080117bc((uint)DAT_20000321,(uint)DAT_20000322,(uint)DAT_20000323);
      }
    }
    else if (DAT_2000032c == '\0') {
      if (DAT_200003b2 == 0) {
        DAT_2000032a = DAT_200003b6;
      }
      else {
        DAT_2000031f = DAT_200003b1;
        DAT_20000320 = DAT_200003b2;
        DAT_20000321 = DAT_200003b3;
        DAT_20000322 = DAT_200003b4;
        DAT_20000323 = DAT_200003b5;
        _DAT_20000328 = (ushort)DAT_200003b8 + (ushort)DAT_200003b7 * 0x100;
        FUN_08012836((uint)DAT_200003b2);
        FUN_080125fc((uint)DAT_20000320);
        FUN_08012432((uint)DAT_20000320);
        FUN_08011bd6((uint)DAT_20000320);
        FUN_080118f2((uint)DAT_20000320);
        FUN_080118c8((uint)DAT_20000320);
        FUN_080117bc((uint)DAT_20000321,(uint)DAT_20000322,(uint)DAT_20000323);
        FUN_08011030();
      }
    }
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800d892   (0x0800D892, 27 Bytes)
 * Body: 0x0800D892-0x0800D8AD
 * --------------------------------------------------------------------- */
undefined4 FUN_0800d892(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_10 = param_1;
  uStack_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  FUN_0800b990(&DAT_200003b1,(undefined1 *)((int)&uStack_10 + 2),8);
  FUN_0800d724();
  return 6;
}


/* ---------------------------------------------------------------------
 * FUN_0800d8ae   (0x0800D8AE, 43 Bytes)
 * Body: 0x0800D8AE-0x0800D8D9
 * --------------------------------------------------------------------- */
void FUN_0800d8ae(void)

{
  if ((((DAT_200003b0 != -1) && (DAT_200003b0 != '\x01')) && (DAT_200003b0 != '\x02')) &&
     (DAT_200003b0 == '\x03')) {
    FUN_08016ec0();
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800d8da   (0x0800D8DA, 27 Bytes)
 * Body: 0x0800D8DA-0x0800D8F5
 * --------------------------------------------------------------------- */
undefined4 FUN_0800d8da(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_10 = param_1;
  uStack_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  FUN_0800b990(&DAT_200003b0,(undefined1 *)((int)&uStack_10 + 2),1);
  FUN_0800d8ae();
  return 6;
}


/* ---------------------------------------------------------------------
 * FUN_0800d8f6   (0x0800D8F6, 39 Bytes)
 * Body: 0x0800D8F6-0x0800D91D
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0800d8f6(void)

{
  if ((DAT_20000c67 != -1) || (DAT_20000c68 != -1)) {
    _DAT_2000009c = CONCAT11(DAT_20000c67,DAT_20000c68);
    DAT_2000009e = 1;
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800d91e   (0x0800D91E, 27 Bytes)
 * Body: 0x0800D91E-0x0800D939
 * --------------------------------------------------------------------- */
undefined4 FUN_0800d91e(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_10 = param_1;
  uStack_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  FUN_0800b990((undefined1 *)0x20000c61,(undefined1 *)((int)&uStack_10 + 2),0xe);
  FUN_0800d8f6();
  return 6;
}


/* ---------------------------------------------------------------------
 * FUN_0800d93a   (0x0800D93A, 49 Bytes)
 * Body: 0x0800D93A-0x0800D96B
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_0800d93a(void)

{
  ushort uVar1;
  
  uVar1 = 0;
  if (((DAT_20000c5e != -1) && (uVar1 = CONCAT11(DAT_2000037c,DAT_2000037d), _DAT_200002fc < 4)) &&
     (uVar1 < 0xf3c)) {
    DAT_2000008b = DAT_20000c5e;
  }
  return uVar1;
}


/* ---------------------------------------------------------------------
 * FUN_0800d96c   (0x0800D96C, 27 Bytes)
 * Body: 0x0800D96C-0x0800D987
 * --------------------------------------------------------------------- */
undefined4 FUN_0800d96c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_10 = param_1;
  uStack_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  FUN_0800b990((undefined1 *)0x20000c55,(undefined1 *)((int)&uStack_10 + 2),0xc);
  FUN_0800d93a();
  return 6;
}


/* ---------------------------------------------------------------------
 * FUN_0800d988   (0x0800D988, 69 Bytes)
 * Body: 0x0800D988-0x0800D9CD
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0800d988(undefined4 param_1,uint param_2)

{
  undefined1 local_e;
  undefined1 local_d;
  
  local_e = (char)((uint)param_1 >> 0x10);
  if (local_e != -1) {
    DAT_200003a8 = local_e;
    local_d = (undefined1)((uint)param_1 >> 0x18);
    DAT_200003a9 = local_d;
    _DAT_200003ac =
         (param_2 >> 0x18) +
         param_2 * 0x1000000 + (param_2 >> 8 & 0xff) * 0x10000 + (param_2 >> 0x10 & 0xff) * 0x100;
  }
  DAT_200003a4 = DAT_200003a8;
  return 6;
}


/* ---------------------------------------------------------------------
 * FUN_0800d9ce   (0x0800D9CE, 127 Bytes)
 * Body: 0x0800D9CE-0x0800DA4D
 * --------------------------------------------------------------------- */
undefined4 FUN_0800d9ce(undefined1 *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  if (DAT_200003a2 == DAT_200003a3) {
    uVar1 = 2;
  }
  else {
    *param_1 = *(undefined1 *)((uint)DAT_200003a2 * 0x14 + 0x20000a4d);
    for (uVar2 = 0; uVar2 < 0x11; uVar2 = uVar2 + 1 & 0xff) {
      param_1[uVar2 + 2] = *(undefined1 *)((uint)DAT_200003a2 * 0x14 + 0x20000a4f + uVar2);
    }
    param_1[1] = *(undefined1 *)((uint)DAT_200003a2 * 0x14 + 0x20000a4e);
    param_1[0x13] = *(undefined1 *)((uint)DAT_200003a2 * 0x14 + 0x20000a60);
    DAT_200003a2 = (char)(DAT_200003a2 + 1) + (char)((DAT_200003a2 + 1) / 0x14) * -0x14;
    uVar1 = 6;
  }
  return uVar1;
}


/* ---------------------------------------------------------------------
 * FUN_0800da4e   (0x0800DA4E, 226 Bytes, 4 Teile)
 * Body: 0x0800DA4E-0x0800DA79, 0x0800DA84-0x0800DA97, 0x0800DB20-0x0800DB6B, 0x0800DB6E-0x0800DBC7
 * --------------------------------------------------------------------- */
void FUN_0800da4e(void)

{
  int iVar1;
  uint uVar2;
  uint local_1c;
  uint uStack_18;
  undefined4 uStack_14;
  uint uStack_10;
  
  iVar1 = FUN_0800d9ce((undefined1 *)&local_1c);
  if (iVar1 == 6) {
    if ((char)local_1c == -0x56) {
      uVar2 = local_1c >> 8 & 0xff;
      if (uVar2 == 0x11) {
        FUN_0800d5ca(local_1c,uStack_18,uStack_14,uStack_10);
      }
      else if (uVar2 < 0x12) {
        switch(uVar2) {
        case 1:
          FUN_0800d988(local_1c,uStack_18);
          break;
        case 2:
          FUN_0800d96c(local_1c,uStack_18,uStack_14,uStack_10);
          break;
        case 3:
          FUN_0800d91e(local_1c,uStack_18,uStack_14,uStack_10);
          break;
        case 4:
          FUN_0800d8da(local_1c,uStack_18,uStack_14,uStack_10);
        case 8:
          FUN_0800d892(local_1c,uStack_18,uStack_14,uStack_10);
        }
      }
      else if (uVar2 == 0x12) {
        FUN_0800d532(local_1c,uStack_18,uStack_14,uStack_10);
      }
      else if (uVar2 == 0x18) {
        FUN_0800d2dc(local_1c,uStack_18,uStack_14,uStack_10);
      }
      else if (uVar2 == 0x1a) {
        FUN_0800d1ec(local_1c,uStack_18,uStack_14,uStack_10);
      }
      else if (uVar2 == 0x1f) {
        FUN_0800d26c(local_1c,uStack_18,uStack_14,uStack_10);
      }
    }
    FUN_08016c16((int)&local_1c,0x14);
  }
  return;
}


/* ---------------------------------------------------------------------
 * thunk_FUN_0800dbc4   (0x0800DA96, 1 Bytes)
 * Body: 0x0800DA96-0x0800DA97
 * --------------------------------------------------------------------- */
void thunk_FUN_0800dbc4(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800dbc4   (0x0800DBC4, 3 Bytes)
 * Body: 0x0800DBC4-0x0800DBC7
 * --------------------------------------------------------------------- */
void FUN_0800dbc4(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800dbc8   (0x0800DBC8, 147 Bytes)
 * Body: 0x0800DBC8-0x0800DC5B
 * --------------------------------------------------------------------- */
undefined4
FUN_0800dbc8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  uint uVar2;
  undefined1 local_10;
  undefined1 local_f;
  undefined1 local_e [2];
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_4 = param_4;
  uStack_8 = param_3;
  uStack_c = param_2;
  if ((DAT_200003a3 + 1) % 0x14 == (uint)DAT_200003a2) {
    uVar1 = 3;
  }
  else {
    local_f = (undefined1)((uint)param_1 >> 8);
    *(undefined1 *)((uint)DAT_200003a3 * 0x14 + 0x20000a4e) = local_f;
    local_10 = (undefined1)param_1;
    *(undefined1 *)((uint)DAT_200003a3 * 0x14 + 0x20000a4d) = local_10;
    for (uVar2 = 0; uVar2 < 0x11; uVar2 = uVar2 + 1 & 0xff) {
      *(undefined1 *)((uint)DAT_200003a2 * 0x14 + 0x20000a4f + uVar2) = local_e[uVar2];
    }
    *(undefined1 *)((uint)DAT_200003a3 * 0x14 + 0x20000a60) = param_5._3_1_;
    DAT_200003a3 = (char)(DAT_200003a3 + 1) + (char)((DAT_200003a3 + 1) / 0x14) * -0x14;
    uVar1 = 6;
  }
  return uVar1;
}


/* ---------------------------------------------------------------------
 * FUN_0800dc5c   (0x0800DC5C, 21 Bytes)
 * Body: 0x0800DC5C-0x0800DC71
 * --------------------------------------------------------------------- */
bool FUN_0800dc5c(int param_1)

{
  return *(char *)(param_1 + 300) == *(char *)(param_1 + 0x12d);
}


/* ---------------------------------------------------------------------
 * FUN_0800dc72   (0x0800DC72, 63 Bytes)
 * Body: 0x0800DC72-0x0800DCB1
 * --------------------------------------------------------------------- */
bool FUN_0800dc72(int param_1,undefined4 *param_2)

{
  bool bVar1;
  uint uVar2;
  
  bVar1 = FUN_0800dc5c(param_1);
  if (!bVar1) {
    FUN_0801d2ec(param_2,(undefined4 *)(param_1 + (uint)*(byte *)(param_1 + 300) * 0x14),0x14);
    uVar2 = *(byte *)(param_1 + 300) + 1;
    *(char *)(param_1 + 300) = (char)uVar2 + (char)(uVar2 / 0xf) * -0xf;
  }
  return bVar1;
}


/* ---------------------------------------------------------------------
 * FUN_0800dcb2   (0x0800DCB2, 133 Bytes)
 * Body: 0x0800DCB2-0x0800DD37
 * --------------------------------------------------------------------- */
void FUN_0800dcb2(void)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  char local_34;
  undefined1 local_33;
  byte local_32 [18];
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 local_10;
  
  uVar3 = 0;
  bVar1 = FUN_0800dc72(0x2000078e,(undefined4 *)&local_34);
  if (bVar1) {
    if (DAT_200003e8 < 0x32) {
      DAT_200003e8 = DAT_200003e8 + 1;
    }
  }
  else {
    DAT_200003e8 = 0;
    uVar2 = FUN_0800bda6((int)&local_34,0x13);
    if ((local_32[0x11] == uVar2) && (local_34 == -0x56)) {
      for (; uVar3 < 0x11; uVar3 = uVar3 + 1) {
        *(byte *)((int)&local_20 + uVar3 + 2) = local_32[uVar3];
      }
      local_20._0_2_ = CONCAT11(local_33,0xaa);
      local_10 = CONCAT13((char)uVar2,(undefined3)local_10);
      FUN_0800dbc8(local_20,uStack_1c,uStack_18,uStack_14,local_10);
    }
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800dd38   (0x0800DD38, 67 Bytes)
 * Body: 0x0800DD38-0x0800DD7B
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0800dd38(void)

{
  FUN_0800dcb2();
  FUN_0800da4e();
  FUN_0800c608();
  FUN_0800c5b8();
  FUN_0800bcfa();
  FUN_0800bcd6();
  FUN_0800bb9c();
  FUN_0800ba8c();
  if ((_DAT_200002d4 != 0) && (_DAT_200002d4 = _DAT_200002d4 + 1, 0x18 < _DAT_200002d4)) {
    _DAT_200002d4 = 0;
    DAT_200002d8 = 0;
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800dd7c   (0x0800DD7C, 77 Bytes)
 * BLE-20B-Sender (aus 16/20B-Struktur)
 * Body: 0x0800DD7C-0x0800DDC9
 * --------------------------------------------------------------------- */
void FUN_0800dd7c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  byte local_2c;
  undefined1 local_2b;
  undefined1 auStack_2a [18];
  undefined4 local_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  local_10 = param_1;
  uStack_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  FUN_0801d31e(&local_2c,0x14);
  local_2c = (byte)local_10;
  local_2b = local_10._1_1_;
  for (uVar1 = 0; uVar1 < 0x11; uVar1 = uVar1 + 1 & 0xff) {
    auStack_2a[uVar1] = *(undefined1 *)((int)&local_10 + uVar1 + 2);
  }
  FUN_08019b3a(&local_2c,0x14);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800ddca   (0x0800DDCA, 127 Bytes)
 * Body: 0x0800DDCA-0x0800DE49
 * --------------------------------------------------------------------- */
undefined4 FUN_0800ddca(undefined1 *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  if (DAT_200003a0 == DAT_200003a1) {
    uVar1 = 0;
  }
  else {
    *param_1 = *(undefined1 *)((uint)DAT_200003a0 * 0x14 + 0x200008bd);
    param_1[1] = *(undefined1 *)((uint)DAT_200003a0 * 0x14 + 0x200008be);
    for (uVar2 = 0; uVar2 < 0x11; uVar2 = uVar2 + 1 & 0xff) {
      param_1[uVar2 + 2] = *(undefined1 *)((uint)DAT_200003a0 * 0x14 + 0x200008bf + uVar2);
    }
    param_1[0x13] = *(undefined1 *)((uint)DAT_200003a0 * 0x14 + 0x200008d0);
    DAT_200003a0 = (char)(DAT_200003a0 + 1) + (char)((DAT_200003a0 + 1) / 0x14) * -0x14;
    uVar1 = 4;
  }
  return uVar1;
}


/* ---------------------------------------------------------------------
 * FUN_0800de4a   (0x0800DE4A, 61 Bytes)
 * BLE-20B-Sender (Variante)
 * Body: 0x0800DE4A-0x0800DE87
 * --------------------------------------------------------------------- */
void FUN_0800de4a(void)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  ushort local_20 [2];
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  cVar1 = FUN_08016e3c();
  if (cVar1 == '\0') {
    iVar2 = FUN_0800ddca((undefined1 *)&local_1c);
    if (iVar2 != 0) {
      FUN_0800dd7c(local_1c,uStack_18,uStack_14,uStack_10);
    }
  }
  else {
    uVar3 = FUN_08016d36(0x20000bdd,local_20);
    if ((int)uVar3 == 2) {
      FUN_08019b3a((byte *)0x20000bdd,(uint)local_20[0]);
    }
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800de88   (0x0800DE88, 33 Bytes)
 * Queue-Helfer: 'voll?'
 * Body: 0x0800DE88-0x0800DEA9
 * --------------------------------------------------------------------- */
bool FUN_0800de88(int param_1)

{
  return (*(byte *)(param_1 + 0x12d) + 1) % 0xf == (uint)*(byte *)(param_1 + 300);
}


/* ---------------------------------------------------------------------
 * FUN_0800deaa   (0x0800DEAA, 63 Bytes)
 * Queue-Enqueue (20B-Frames, 15 Slots, BLE-Queue 0x2000078E)
 * Body: 0x0800DEAA-0x0800DEE9
 * --------------------------------------------------------------------- */
undefined4 FUN_0800deaa(int param_1,undefined4 *param_2)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  
  bVar1 = FUN_0800de88(param_1);
  if (bVar1) {
    uVar3 = 2;
  }
  else {
    FUN_0801d2ec((undefined4 *)(param_1 + (uint)*(byte *)(param_1 + 0x12d) * 0x14),param_2,0x14);
    uVar2 = *(byte *)(param_1 + 0x12d) + 1;
    *(char *)(param_1 + 0x12d) = (char)uVar2 + (char)(uVar2 / 0xf) * -0xf;
    uVar3 = 0;
  }
  return uVar3;
}


/* ---------------------------------------------------------------------
 * FUN_0800deea   (0x0800DEEA, 1034 Bytes, 2 Teile)
 * Telemetrie-Builder: Settings-Echo + Fahrwerte -> BLE-TX-Puffer 0x20000D8A
 * Body: 0x0800DEEA-0x0800DFC3, 0x0800E074-0x0800E3A5
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0800deea(void)

{
  uint uVar1;
  
  for (uVar1 = 0; uVar1 < 0xe; uVar1 = uVar1 + 1 & 0xff) {
    (&DAT_20000d8a)[uVar1] = (char)uVar1 + '0';
  }
  DAT_20000db8 = DAT_2000032e;
  DAT_20000db9 = DAT_2000032f;
  DAT_20000dba = DAT_20000330;
  DAT_20000dbb = DAT_20000331;
  DAT_20000dbc = DAT_20000332;
  DAT_20000dbd = DAT_20000333;
  DAT_20000dbe = DAT_20000334;
  DAT_20000dbf = DAT_20000335;
  DAT_20000dc0 = DAT_20000336;
  DAT_20000dc1 = DAT_20000337;
  DAT_20000dc2 = DAT_20000338;
  DAT_20000dc3 = DAT_20000339;
  DAT_20000dc4 = DAT_2000033a;
  DAT_20000dc5 = DAT_2000033b;
  DAT_20000dc6 = DAT_2000033c;
  DAT_20000dc7 = DAT_2000033d;
  DAT_20000dc8 = DAT_2000035e;
  DAT_20000dc9 = DAT_2000035f;
  DAT_20000dca = DAT_20000360;
  DAT_20000dcb = DAT_20000361;
  DAT_20000dcc = DAT_20000362;
  DAT_20000dcd = DAT_20000363;
  DAT_20000dce = DAT_20000364;
  DAT_20000dcf = DAT_20000365;
  DAT_20000dd0 = DAT_20000366;
  DAT_20000dd1 = DAT_20000367;
  DAT_20000dd2 = DAT_20000368;
  DAT_20000dd3 = DAT_20000369;
  DAT_20000dd4 = DAT_2000036a;
  DAT_20000dd5 = DAT_2000036b;
  DAT_20000dd6 = DAT_2000036c;
  DAT_20000dd7 = DAT_2000036d;
  DAT_20000dd8 = DAT_2000036e;
  DAT_20000dd9 = DAT_2000036f;
  DAT_20000dda = DAT_20000370;
  DAT_20000ddb = DAT_20000371;
  DAT_20000ddc = DAT_20000372;
  DAT_20000ddd = DAT_20000373;
  DAT_20000dde = DAT_20000374;
  DAT_20000ddf = DAT_20000375;
  DAT_20000de0 = DAT_20000376;
  DAT_20000de5 = DAT_2000037b;
  DAT_20000de6 = DAT_2000037c;
  DAT_20000de8 = DAT_2000037e;
  DAT_20000de7 = DAT_2000037d;
  DAT_20000dea = DAT_2000029f;
  if (DAT_2000029f < DAT_20000380) {
    DAT_20000dea = DAT_20000380;
  }
  DAT_20000deb = DAT_20000381;
  DAT_20000dec = DAT_20000382;
  DAT_20000ded = DAT_20000383;
  DAT_20000dee = DAT_20000384;
  DAT_20000def = DAT_20000385;
  DAT_20000df0 = DAT_20000386;
  DAT_20000df1 = DAT_20000387;
  DAT_20000df2 = DAT_20000388;
  DAT_20000df3 = DAT_20000389;
  DAT_20000df4 = DAT_2000038a;
  DAT_20000df5 = DAT_2000038b;
  DAT_20000df6 = DAT_2000038c;
  DAT_20000df7 = DAT_2000038d;
  DAT_20000df8 = DAT_2000038e;
  DAT_20000df9 = DAT_20000390;
  DAT_20000dfb = DAT_2000033e;
  DAT_20000dfc = DAT_2000033f;
  DAT_20000dfd = DAT_20000340;
  DAT_20000dfe = DAT_20000341;
  DAT_20000dff = DAT_20000342;
  DAT_20000e00 = DAT_20000343;
  DAT_20000e01 = DAT_20000344;
  DAT_20000e02 = DAT_20000345;
  DAT_20000e03 = DAT_20000346;
  DAT_20000e04 = DAT_20000347;
  DAT_20000e05 = DAT_20000348;
  DAT_20000e06 = DAT_20000349;
  DAT_20000e07 = DAT_2000034a;
  DAT_20000e08 = DAT_2000034b;
  DAT_20000e09 = DAT_2000034c;
  DAT_20000e0a = DAT_2000034d;
  DAT_20000e0b = DAT_2000034e;
  DAT_20000e0c = DAT_2000034f;
  DAT_20000e0d = DAT_20000350;
  DAT_20000e0e = DAT_20000351;
  DAT_20000e0f = DAT_20000352;
  DAT_20000e10 = DAT_20000353;
  DAT_20000e11 = DAT_20000354;
  DAT_20000e12 = DAT_20000355;
  DAT_20000e13 = DAT_20000356;
  DAT_20000e14 = DAT_20000357;
  DAT_20000e15 = DAT_20000358;
  DAT_20000e16 = DAT_20000359;
  DAT_20000e17 = DAT_2000035a;
  DAT_20000e18 = DAT_2000035b;
  DAT_20000e19 = DAT_2000035c;
  DAT_20000e1a = DAT_2000035d;
  _DAT_20000e22 = _DAT_2000018e;
  _DAT_20000e1c = _DAT_2000012e;
  _DAT_20000e24 = _DAT_200001a6;
  _DAT_20000e1e = _DAT_20000146;
  _DAT_20000e26 = _DAT_20000176;
  _DAT_20000e20 = _DAT_20000116;
  _DAT_20000e2a = _DAT_200001d0;
  _DAT_20000e28 = _DAT_20000200;
  DAT_200003c1 = DAT_200000e6;
  DAT_200003c2 = *FUN_0800e5ae;
  DAT_200003bf = *puRam0800e5b4;
  DAT_200003c0 = DAT_200000ce;
  DAT_200003c5 = DAT_2000027e;
  DAT_200003c6 = DAT_20000296;
  DAT_200003c3 = DAT_2000024e;
  DAT_200003c4 = DAT_20000266;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d0b) = 1;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d0c) = 1;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d19) = 0xe3;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d0d) = 0xe3;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d0e) = 0x1e;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d0f) = 0x50;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d10) = 0x14;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d11) = 0x33;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d13) = 100;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d14) = 0x50;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d15) = 0x3c;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d17) = 0x2d;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d18) = 0x3c;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d1a) = DAT_20000306;
  DAT_20000d6c = 9;
  if (2000 < _DAT_20000034) {
    DAT_20000d6c = 0x29;
  }
  if (2000 < _DAT_20000036) {
    DAT_20000d6c = DAT_20000d6c | 0x40;
  }
  if (2000 < _DAT_20000032) {
    DAT_20000d6c = DAT_20000d6c | 0x10;
  }
  DAT_20000d6d = 1;
  DAT_20000d6f = 0x3c;
  DAT_20000d70 = 0;
  DAT_20000d6e = 100;
  DAT_20000d6b = 0x19;
  return;
}


/* ---------------------------------------------------------------------
 * thunk_FUN_0800e074   (0x0800DFC2, 1 Bytes)
 * Body: 0x0800DFC2-0x0800DFC3
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thunk_FUN_0800e074(void)

{
  undefined1 in_r3;
  int unaff_r4;
  
  *(undefined1 *)(unaff_r4 + 0xd) = in_r3;
  DAT_20000dd6 = DAT_2000036c;
  DAT_20000dd7 = DAT_2000036d;
  DAT_20000dd8 = DAT_2000036e;
  DAT_20000dd9 = DAT_2000036f;
  DAT_20000dda = DAT_20000370;
  DAT_20000ddb = DAT_20000371;
  DAT_20000ddc = DAT_20000372;
  DAT_20000ddd = DAT_20000373;
  DAT_20000dde = DAT_20000374;
  DAT_20000ddf = DAT_20000375;
  DAT_20000de0 = DAT_20000376;
  DAT_20000de5 = DAT_2000037b;
  DAT_20000de6 = DAT_2000037c;
  DAT_20000de8 = DAT_2000037e;
  DAT_20000de7 = DAT_2000037d;
  DAT_20000dea = DAT_2000029f;
  if (DAT_2000029f < DAT_20000380) {
    DAT_20000dea = DAT_20000380;
  }
  DAT_20000deb = DAT_20000381;
  DAT_20000dec = DAT_20000382;
  DAT_20000ded = DAT_20000383;
  DAT_20000dee = DAT_20000384;
  DAT_20000def = DAT_20000385;
  DAT_20000df0 = DAT_20000386;
  DAT_20000df1 = DAT_20000387;
  DAT_20000df2 = DAT_20000388;
  DAT_20000df3 = DAT_20000389;
  DAT_20000df4 = DAT_2000038a;
  DAT_20000df5 = DAT_2000038b;
  DAT_20000df6 = DAT_2000038c;
  DAT_20000df7 = DAT_2000038d;
  DAT_20000df8 = DAT_2000038e;
  DAT_20000df9 = DAT_20000390;
  DAT_20000dfb = DAT_2000033e;
  DAT_20000dfc = DAT_2000033f;
  DAT_20000dfd = DAT_20000340;
  DAT_20000dfe = DAT_20000341;
  DAT_20000dff = DAT_20000342;
  DAT_20000e00 = DAT_20000343;
  DAT_20000e01 = DAT_20000344;
  DAT_20000e02 = DAT_20000345;
  DAT_20000e03 = DAT_20000346;
  DAT_20000e04 = DAT_20000347;
  DAT_20000e05 = DAT_20000348;
  DAT_20000e06 = DAT_20000349;
  DAT_20000e07 = DAT_2000034a;
  DAT_20000e08 = DAT_2000034b;
  DAT_20000e09 = DAT_2000034c;
  DAT_20000e0a = DAT_2000034d;
  DAT_20000e0b = DAT_2000034e;
  DAT_20000e0c = DAT_2000034f;
  DAT_20000e0d = DAT_20000350;
  DAT_20000e0e = DAT_20000351;
  DAT_20000e0f = DAT_20000352;
  DAT_20000e10 = DAT_20000353;
  DAT_20000e11 = DAT_20000354;
  DAT_20000e12 = DAT_20000355;
  DAT_20000e13 = DAT_20000356;
  DAT_20000e14 = DAT_20000357;
  DAT_20000e15 = DAT_20000358;
  DAT_20000e16 = DAT_20000359;
  DAT_20000e17 = DAT_2000035a;
  DAT_20000e18 = DAT_2000035b;
  DAT_20000e19 = DAT_2000035c;
  DAT_20000e1a = DAT_2000035d;
  _DAT_20000e22 = _DAT_2000018e;
  _DAT_20000e1c = _DAT_2000012e;
  _DAT_20000e24 = _DAT_200001a6;
  _DAT_20000e1e = _DAT_20000146;
  _DAT_20000e26 = _DAT_20000176;
  _DAT_20000e20 = _DAT_20000116;
  _DAT_20000e2a = _DAT_200001d0;
  _DAT_20000e28 = _DAT_20000200;
  DAT_200003c1 = DAT_200000e6;
  DAT_200003c2 = *FUN_0800e5ae;
  DAT_200003bf = *puRam0800e5b4;
  DAT_200003c0 = DAT_200000ce;
  DAT_200003c5 = DAT_2000027e;
  DAT_200003c6 = DAT_20000296;
  DAT_200003c3 = DAT_2000024e;
  DAT_200003c4 = DAT_20000266;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d0b) = 1;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d0c) = 1;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d19) = 0xe3;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d0d) = 0xe3;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d0e) = 0x1e;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d0f) = 0x50;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d10) = 0x14;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d11) = 0x33;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d13) = 100;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d14) = 0x50;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d15) = 0x3c;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d17) = 0x2d;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d18) = 0x3c;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d1a) = DAT_20000306;
  DAT_20000d6c = 9;
  if (2000 < _DAT_20000034) {
    DAT_20000d6c = 0x29;
  }
  if (2000 < _DAT_20000036) {
    DAT_20000d6c = DAT_20000d6c | 0x40;
  }
  if (2000 < _DAT_20000032) {
    DAT_20000d6c = DAT_20000d6c | 0x10;
  }
  DAT_20000d6d = 1;
  DAT_20000d6f = 0x3c;
  DAT_20000d70 = 0;
  DAT_20000d6e = 100;
  DAT_20000d6b = 0x19;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800e074   (0x0800E074, 817 Bytes)
 * Body: 0x0800E074-0x0800E3A5
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0800e074(void)

{
  undefined1 in_r3;
  int unaff_r4;
  
  *(undefined1 *)(unaff_r4 + 0xd) = in_r3;
  DAT_20000dd6 = DAT_2000036c;
  DAT_20000dd7 = DAT_2000036d;
  DAT_20000dd8 = DAT_2000036e;
  DAT_20000dd9 = DAT_2000036f;
  DAT_20000dda = DAT_20000370;
  DAT_20000ddb = DAT_20000371;
  DAT_20000ddc = DAT_20000372;
  DAT_20000ddd = DAT_20000373;
  DAT_20000dde = DAT_20000374;
  DAT_20000ddf = DAT_20000375;
  DAT_20000de0 = DAT_20000376;
  DAT_20000de5 = DAT_2000037b;
  DAT_20000de6 = DAT_2000037c;
  DAT_20000de8 = DAT_2000037e;
  DAT_20000de7 = DAT_2000037d;
  DAT_20000dea = DAT_2000029f;
  if (DAT_2000029f < DAT_20000380) {
    DAT_20000dea = DAT_20000380;
  }
  DAT_20000deb = DAT_20000381;
  DAT_20000dec = DAT_20000382;
  DAT_20000ded = DAT_20000383;
  DAT_20000dee = DAT_20000384;
  DAT_20000def = DAT_20000385;
  DAT_20000df0 = DAT_20000386;
  DAT_20000df1 = DAT_20000387;
  DAT_20000df2 = DAT_20000388;
  DAT_20000df3 = DAT_20000389;
  DAT_20000df4 = DAT_2000038a;
  DAT_20000df5 = DAT_2000038b;
  DAT_20000df6 = DAT_2000038c;
  DAT_20000df7 = DAT_2000038d;
  DAT_20000df8 = DAT_2000038e;
  DAT_20000df9 = DAT_20000390;
  DAT_20000dfb = DAT_2000033e;
  DAT_20000dfc = DAT_2000033f;
  DAT_20000dfd = DAT_20000340;
  DAT_20000dfe = DAT_20000341;
  DAT_20000dff = DAT_20000342;
  DAT_20000e00 = DAT_20000343;
  DAT_20000e01 = DAT_20000344;
  DAT_20000e02 = DAT_20000345;
  DAT_20000e03 = DAT_20000346;
  DAT_20000e04 = DAT_20000347;
  DAT_20000e05 = DAT_20000348;
  DAT_20000e06 = DAT_20000349;
  DAT_20000e07 = DAT_2000034a;
  DAT_20000e08 = DAT_2000034b;
  DAT_20000e09 = DAT_2000034c;
  DAT_20000e0a = DAT_2000034d;
  DAT_20000e0b = DAT_2000034e;
  DAT_20000e0c = DAT_2000034f;
  DAT_20000e0d = DAT_20000350;
  DAT_20000e0e = DAT_20000351;
  DAT_20000e0f = DAT_20000352;
  DAT_20000e10 = DAT_20000353;
  DAT_20000e11 = DAT_20000354;
  DAT_20000e12 = DAT_20000355;
  DAT_20000e13 = DAT_20000356;
  DAT_20000e14 = DAT_20000357;
  DAT_20000e15 = DAT_20000358;
  DAT_20000e16 = DAT_20000359;
  DAT_20000e17 = DAT_2000035a;
  DAT_20000e18 = DAT_2000035b;
  DAT_20000e19 = DAT_2000035c;
  DAT_20000e1a = DAT_2000035d;
  _DAT_20000e22 = _DAT_2000018e;
  _DAT_20000e1c = _DAT_2000012e;
  _DAT_20000e24 = _DAT_200001a6;
  _DAT_20000e1e = _DAT_20000146;
  _DAT_20000e26 = _DAT_20000176;
  _DAT_20000e20 = _DAT_20000116;
  _DAT_20000e2a = _DAT_200001d0;
  _DAT_20000e28 = _DAT_20000200;
  DAT_200003c1 = DAT_200000e6;
  DAT_200003c2 = *FUN_0800e5ae;
  DAT_200003bf = *puRam0800e5b4;
  DAT_200003c0 = DAT_200000ce;
  DAT_200003c5 = DAT_2000027e;
  DAT_200003c6 = DAT_20000296;
  DAT_200003c3 = DAT_2000024e;
  DAT_200003c4 = DAT_20000266;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d0b) = 1;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d0c) = 1;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d19) = 0xe3;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d0d) = 0xe3;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d0e) = 0x1e;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d0f) = 0x50;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d10) = 0x14;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d11) = 0x33;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d13) = 100;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d14) = 0x50;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d15) = 0x3c;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d17) = 0x2d;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d18) = 0x3c;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d1a) = DAT_20000306;
  DAT_20000d6c = 9;
  if (2000 < _DAT_20000034) {
    DAT_20000d6c = 0x29;
  }
  if (2000 < _DAT_20000036) {
    DAT_20000d6c = DAT_20000d6c | 0x40;
  }
  if (2000 < _DAT_20000032) {
    DAT_20000d6c = DAT_20000d6c | 0x10;
  }
  DAT_20000d6d = 1;
  DAT_20000d6f = 0x3c;
  DAT_20000d70 = 0;
  DAT_20000d6e = 100;
  DAT_20000d6b = 0x19;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800e3a6   (0x0800E3A6, 201 Bytes)
 * Body: 0x0800E3A6-0x0800E46F
 * --------------------------------------------------------------------- */
void FUN_0800e3a6(void)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  
  DAT_20000d8a = 0x41;
  DAT_20000d8b = 0x42;
  DAT_20000d8c = 0x43;
  DAT_20000d8d = 0x44;
  DAT_20000d8e = 0x45;
  DAT_20000d8f = 0x46;
  DAT_20000d90 = 0x47;
  DAT_20000d91 = 0x31;
  DAT_20000d92 = 0x32;
  DAT_20000d93 = 0x33;
  DAT_20000d94 = 0x34;
  DAT_20000d95 = 0x35;
  DAT_20000d96 = 0x36;
  DAT_20000d97 = 0x37;
  DAT_20000d98 = 0x38;
  bVar2 = DAT_200003ea + 1;
  iVar3 = bVar2 / 10 + 3000;
  DAT_20000db8 = (undefined1)((uint)iVar3 >> 8);
  DAT_20000db9 = (undefined1)iVar3;
  uVar1 = 3000 - bVar2 / 10 & 0xffff;
  DAT_20000dba = (undefined1)(uVar1 >> 8);
  DAT_20000dbb = (undefined1)uVar1;
  iVar3 = bVar2 / 10 + 0xc80;
  DAT_20000dbc = (undefined1)((uint)iVar3 >> 8);
  DAT_20000dbd = (undefined1)iVar3;
  uVar1 = 0xc80 - bVar2 / 10 & 0xffff;
  DAT_20000dbe = (undefined1)(uVar1 >> 8);
  DAT_20000dbf = (undefined1)uVar1;
  iVar3 = bVar2 / 10 + 3000;
  DAT_20000dc0 = (undefined1)((uint)iVar3 >> 8);
  DAT_20000dc1 = (undefined1)iVar3;
  uVar1 = 3000 - bVar2 / 10 & 0xffff;
  DAT_20000dc2 = (undefined1)(uVar1 >> 8);
  DAT_20000dc3 = (undefined1)uVar1;
  iVar3 = bVar2 / 10 + 0xc1c;
  DAT_20000dc4 = (undefined1)((uint)iVar3 >> 8);
  DAT_20000dc5 = (undefined1)iVar3;
  uVar1 = 0xc1c - bVar2 / 10 & 0xffff;
  DAT_20000dc6 = (undefined1)(uVar1 >> 8);
  DAT_20000dc7 = (undefined1)uVar1;
  bVar2 = DAT_200003ea + 2;
  iVar3 = bVar2 / 10 + 4000;
  DAT_20000dfb = (undefined1)((uint)iVar3 >> 8);
  DAT_20000dfc = (undefined1)iVar3;
  uVar1 = 4000 - bVar2 / 10 & 0xffff;
  DAT_20000dfd = (undefined1)(uVar1 >> 8);
  DAT_20000dfe = (undefined1)uVar1;
  iVar3 = bVar2 / 10 + 0x1068;
  DAT_20000dff = (undefined1)((uint)iVar3 >> 8);
  DAT_20000e00 = (undefined1)iVar3;
  uVar1 = 0x1068 - bVar2 / 10 & 0xffff;
  DAT_20000e01 = (undefined1)(uVar1 >> 8);
  DAT_20000e02 = (undefined1)uVar1;
  iVar3 = bVar2 / 10 + 4000;
  DAT_20000e03 = (undefined1)((uint)iVar3 >> 8);
  DAT_20000e04 = (undefined1)iVar3;
  uVar1 = 4000 - bVar2 / 10 & 0xffff;
  DAT_20000e05 = (undefined1)(uVar1 >> 8);
  DAT_20000e06 = (undefined1)uVar1;
  iVar3 = bVar2 / 10 + 0x1004;
  DAT_20000e07 = (undefined1)((uint)iVar3 >> 8);
  DAT_20000e08 = (undefined1)iVar3;
  uVar1 = 0x1004 - bVar2 / 10 & 0xffff;
  DAT_20000e09 = (undefined1)(uVar1 >> 8);
  DAT_20000e0a = (undefined1)uVar1;
  DAT_200003ea = DAT_200003ea + 3;
  iVar3 = DAT_200003ea / 10 + 2000;
  DAT_20000e0b = (undefined1)((uint)iVar3 >> 8);
  DAT_20000e0c = (undefined1)iVar3;
  uVar1 = 2000 - DAT_200003ea / 10 & 0xffff;
  DAT_20000e0d = (undefined1)(uVar1 >> 8);
  DAT_20000e0e = (undefined1)uVar1;
  iVar3 = DAT_200003ea / 10 + 0x898;
  DAT_20000e0f = (undefined1)((uint)iVar3 >> 8);
  DAT_20000e10 = (undefined1)iVar3;
  uVar1 = 0x898 - DAT_200003ea / 10 & 0xffff;
  DAT_20000e11 = (undefined1)(uVar1 >> 8);
  DAT_20000e12 = (undefined1)uVar1;
  iVar3 = DAT_200003ea / 10 + 2000;
  DAT_20000e13 = (undefined1)((uint)iVar3 >> 8);
  DAT_20000e14 = (undefined1)iVar3;
  uVar1 = 2000 - DAT_200003ea / 10 & 0xffff;
  DAT_20000e15 = (undefined1)(uVar1 >> 8);
  DAT_20000e16 = (undefined1)uVar1;
  iVar3 = DAT_200003ea / 10 + 0x834;
  DAT_20000e17 = (undefined1)((uint)iVar3 >> 8);
  DAT_20000e18 = (undefined1)iVar3;
  uVar1 = 0x834 - DAT_200003ea / 10 & 0xffff;
  DAT_20000e19 = (undefined1)(uVar1 >> 8);
  DAT_20000e1a = (undefined1)uVar1;
  uVar1 = DAT_200003ea / 10 + 35000 & 0xffff;
  DAT_20000dc8 = (undefined1)(uVar1 / 100 - 100 >> 8);
  DAT_20000dc9 = (char)(uVar1 / 100) + -100;
  uVar1 = DAT_200003ea / 10 + 34000 & 0xffff;
  DAT_20000dca = (undefined1)(uVar1 / 100 - 100 >> 8);
  DAT_20000dcb = (char)(uVar1 / 100) + -100;
  DAT_20000dcc = 0x27;
  DAT_20000dcd = 0x1f;
  DAT_20000dce = DAT_200003ea / 10 + 0x32;
  DAT_20000dcf = 100;
  DAT_20000dd0 = 0x41;
  DAT_20000dd1 = 0x2d;
  DAT_20000dd2 = 0x55;
  DAT_20000dd3 = 0x42;
  DAT_20000dd4 = 0x2e;
  DAT_20000dd5 = 0x56;
  DAT_20000dd6 = 0x14;
  DAT_20000dd9 = 1;
  DAT_20000dda = 1;
  DAT_20000ddb = 0;
  DAT_20000ddc = 1;
  DAT_20000ddd = 0;
  DAT_20000dde = 0xaa;
  DAT_20000ddf = 0;
  DAT_20000de0 = 0xe6;
  DAT_20000de5 = DAT_2000037b;
  iVar3 = DAT_200003ea / 10 + 0x1068;
  DAT_20000de6 = (undefined1)((uint)iVar3 >> 8);
  DAT_20000de7 = (undefined1)iVar3;
  iVar3 = DAT_200003ea / 10 + 2000;
  DAT_20000de8 = (undefined1)((uint)iVar3 >> 8);
  DAT_20000de9 = (undefined1)iVar3;
  DAT_20000dea = (char)(DAT_200003ea / 10) - (char)(((int)(DAT_200003ea / 10) >> 2) << 2);
  DAT_20000deb = 0;
  DAT_20000dec = 0;
  DAT_20000ded = 0;
  DAT_20000dee = 0;
  DAT_20000def = 0;
  DAT_20000df0 = 0;
  DAT_20000df1 = 0;
  DAT_20000df3 = 0;
  DAT_20000df2 = 0;
  DAT_20000df4 = 2;
  DAT_20000df5 = 3;
  DAT_20000df6 = 0;
  DAT_20000df7 = 1;
  DAT_20000df8 = 1;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d0b) = 1;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d0c) = 1;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d19) = 0xe3;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d0d) = 0xe3;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d0e) = 0x1e;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d0f) = 0x50;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d10) = 0x14;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d11) = 0x33;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d13) = 100;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d14) = 0x50;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d15) = 0x3c;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d17) = 0x2d;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d18) = 0x3c;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d1a) = DAT_20000306;
  DAT_20000d6b = 0xf0;
  DAT_20000d6c = 0x59;
  DAT_20000d6d = 1;
  DAT_20000d6e = 0x2c;
  DAT_20000d6f = 0x3c;
  DAT_20000d70 = 0;
  DAT_20000d71 = 100;
  DAT_20000d72 = 0x19;
  return;
}


/* ---------------------------------------------------------------------
 * thunk_FUN_0800e5f4   (0x0800E46E, 1 Bytes)
 * Body: 0x0800E46E-0x0800E46F
 * --------------------------------------------------------------------- */
void thunk_FUN_0800e5f4(void)

{
  uint uVar1;
  byte bVar2;
  byte *in_r3;
  int iVar3;
  
  uVar1 = 3000 - *in_r3 / 10 & 0xffff;
  DAT_20000dc2 = (undefined1)(uVar1 >> 8);
  DAT_20000dc3 = (undefined1)uVar1;
  iVar3 = DAT_200003ea / 10 + 0xc1c;
  DAT_20000dc4 = (undefined1)((uint)iVar3 >> 8);
  DAT_20000dc5 = (undefined1)iVar3;
  uVar1 = 0xc1c - DAT_200003ea / 10 & 0xffff;
  DAT_20000dc6 = (undefined1)(uVar1 >> 8);
  DAT_20000dc7 = (undefined1)uVar1;
  bVar2 = DAT_200003ea + 1;
  iVar3 = bVar2 / 10 + 4000;
  DAT_20000dfb = (undefined1)((uint)iVar3 >> 8);
  DAT_20000dfc = (undefined1)iVar3;
  uVar1 = 4000 - bVar2 / 10 & 0xffff;
  DAT_20000dfd = (undefined1)(uVar1 >> 8);
  DAT_20000dfe = (undefined1)uVar1;
  iVar3 = bVar2 / 10 + 0x1068;
  DAT_20000dff = (undefined1)((uint)iVar3 >> 8);
  DAT_20000e00 = (undefined1)iVar3;
  uVar1 = 0x1068 - bVar2 / 10 & 0xffff;
  DAT_20000e01 = (undefined1)(uVar1 >> 8);
  DAT_20000e02 = (undefined1)uVar1;
  iVar3 = bVar2 / 10 + 4000;
  DAT_20000e03 = (undefined1)((uint)iVar3 >> 8);
  DAT_20000e04 = (undefined1)iVar3;
  uVar1 = 4000 - bVar2 / 10 & 0xffff;
  DAT_20000e05 = (undefined1)(uVar1 >> 8);
  DAT_20000e06 = (undefined1)uVar1;
  iVar3 = bVar2 / 10 + 0x1004;
  DAT_20000e07 = (undefined1)((uint)iVar3 >> 8);
  DAT_20000e08 = (undefined1)iVar3;
  uVar1 = 0x1004 - bVar2 / 10 & 0xffff;
  DAT_20000e09 = (undefined1)(uVar1 >> 8);
  DAT_20000e0a = (undefined1)uVar1;
  DAT_200003ea = DAT_200003ea + 2;
  iVar3 = DAT_200003ea / 10 + 2000;
  DAT_20000e0b = (undefined1)((uint)iVar3 >> 8);
  DAT_20000e0c = (undefined1)iVar3;
  uVar1 = 2000 - DAT_200003ea / 10 & 0xffff;
  DAT_20000e0d = (undefined1)(uVar1 >> 8);
  DAT_20000e0e = (undefined1)uVar1;
  iVar3 = DAT_200003ea / 10 + 0x898;
  DAT_20000e0f = (undefined1)((uint)iVar3 >> 8);
  DAT_20000e10 = (undefined1)iVar3;
  uVar1 = 0x898 - DAT_200003ea / 10 & 0xffff;
  DAT_20000e11 = (undefined1)(uVar1 >> 8);
  DAT_20000e12 = (undefined1)uVar1;
  iVar3 = DAT_200003ea / 10 + 2000;
  DAT_20000e13 = (undefined1)((uint)iVar3 >> 8);
  DAT_20000e14 = (undefined1)iVar3;
  uVar1 = 2000 - DAT_200003ea / 10 & 0xffff;
  DAT_20000e15 = (undefined1)(uVar1 >> 8);
  DAT_20000e16 = (undefined1)uVar1;
  iVar3 = DAT_200003ea / 10 + 0x834;
  DAT_20000e17 = (undefined1)((uint)iVar3 >> 8);
  DAT_20000e18 = (undefined1)iVar3;
  uVar1 = 0x834 - DAT_200003ea / 10 & 0xffff;
  DAT_20000e19 = (undefined1)(uVar1 >> 8);
  DAT_20000e1a = (undefined1)uVar1;
  uVar1 = DAT_200003ea / 10 + 35000 & 0xffff;
  DAT_20000dc8 = (undefined1)(uVar1 / 100 - 100 >> 8);
  DAT_20000dc9 = (char)(uVar1 / 100) + -100;
  uVar1 = DAT_200003ea / 10 + 34000 & 0xffff;
  DAT_20000dca = (undefined1)(uVar1 / 100 - 100 >> 8);
  DAT_20000dcb = (char)(uVar1 / 100) + -100;
  DAT_20000dcc = 0x27;
  DAT_20000dcd = 0x1f;
  DAT_20000dce = DAT_200003ea / 10 + 0x32;
  DAT_20000dcf = 100;
  DAT_20000dd0 = 0x41;
  DAT_20000dd1 = 0x2d;
  DAT_20000dd2 = 0x55;
  DAT_20000dd3 = 0x42;
  DAT_20000dd4 = 0x2e;
  DAT_20000dd5 = 0x56;
  DAT_20000dd6 = 0x14;
  DAT_20000dd9 = 1;
  DAT_20000dda = 1;
  DAT_20000ddb = 0;
  DAT_20000ddc = 1;
  DAT_20000ddd = 0;
  DAT_20000dde = 0xaa;
  DAT_20000ddf = 0;
  DAT_20000de0 = 0xe6;
  DAT_20000de5 = DAT_2000037b;
  iVar3 = DAT_200003ea / 10 + 0x1068;
  DAT_20000de6 = (undefined1)((uint)iVar3 >> 8);
  DAT_20000de7 = (undefined1)iVar3;
  iVar3 = DAT_200003ea / 10 + 2000;
  DAT_20000de8 = (undefined1)((uint)iVar3 >> 8);
  DAT_20000de9 = (undefined1)iVar3;
  DAT_20000dea = (char)(DAT_200003ea / 10) - (char)(((int)(DAT_200003ea / 10) >> 2) << 2);
  DAT_20000deb = 0;
  DAT_20000dec = 0;
  DAT_20000ded = 0;
  DAT_20000dee = 0;
  DAT_20000def = 0;
  DAT_20000df0 = 0;
  DAT_20000df1 = 0;
  DAT_20000df3 = 0;
  DAT_20000df2 = 0;
  DAT_20000df4 = 2;
  DAT_20000df5 = 3;
  DAT_20000df6 = 0;
  DAT_20000df7 = 1;
  DAT_20000df8 = 1;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d0b) = 1;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d0c) = 1;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d19) = 0xe3;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d0d) = 0xe3;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d0e) = 0x1e;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d0f) = 0x50;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d10) = 0x14;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d11) = 0x33;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d13) = 100;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d14) = 0x50;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d15) = 0x3c;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d17) = 0x2d;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d18) = 0x3c;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d1a) = DAT_20000306;
  DAT_20000d6b = 0xf0;
  DAT_20000d6c = 0x59;
  DAT_20000d6d = 1;
  DAT_20000d6e = 0x2c;
  DAT_20000d6f = 0x3c;
  DAT_20000d70 = 0;
  DAT_20000d71 = 100;
  DAT_20000d72 = 0x19;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800e5ae   (0x0800E5AE, 1105 Bytes)
 * Body: 0x0800E5AE-0x0800E9FF
 * --------------------------------------------------------------------- */
void FUN_0800e5ae(void)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  uint unaff_r5;
  
  uVar1 = 3000 - *(byte *)(unaff_r5 >> 0x15) / 10 & 0xffff;
  DAT_20000dc2 = (undefined1)(uVar1 >> 8);
  DAT_20000dc3 = (undefined1)uVar1;
  iVar3 = DAT_200003ea / 10 + 0xc1c;
  DAT_20000dc4 = (undefined1)((uint)iVar3 >> 8);
  DAT_20000dc5 = (undefined1)iVar3;
  uVar1 = 0xc1c - DAT_200003ea / 10 & 0xffff;
  DAT_20000dc6 = (undefined1)(uVar1 >> 8);
  DAT_20000dc7 = (undefined1)uVar1;
  bVar2 = DAT_200003ea + 1;
  iVar3 = bVar2 / 10 + 4000;
  DAT_20000dfb = (undefined1)((uint)iVar3 >> 8);
  DAT_20000dfc = (undefined1)iVar3;
  uVar1 = 4000 - bVar2 / 10 & 0xffff;
  DAT_20000dfd = (undefined1)(uVar1 >> 8);
  DAT_20000dfe = (undefined1)uVar1;
  iVar3 = bVar2 / 10 + 0x1068;
  DAT_20000dff = (undefined1)((uint)iVar3 >> 8);
  DAT_20000e00 = (undefined1)iVar3;
  uVar1 = 0x1068 - bVar2 / 10 & 0xffff;
  DAT_20000e01 = (undefined1)(uVar1 >> 8);
  DAT_20000e02 = (undefined1)uVar1;
  iVar3 = bVar2 / 10 + 4000;
  DAT_20000e03 = (undefined1)((uint)iVar3 >> 8);
  DAT_20000e04 = (undefined1)iVar3;
  uVar1 = 4000 - bVar2 / 10 & 0xffff;
  DAT_20000e05 = (undefined1)(uVar1 >> 8);
  DAT_20000e06 = (undefined1)uVar1;
  iVar3 = bVar2 / 10 + 0x1004;
  DAT_20000e07 = (undefined1)((uint)iVar3 >> 8);
  DAT_20000e08 = (undefined1)iVar3;
  uVar1 = 0x1004 - bVar2 / 10 & 0xffff;
  DAT_20000e09 = (undefined1)(uVar1 >> 8);
  DAT_20000e0a = (undefined1)uVar1;
  DAT_200003ea = DAT_200003ea + 2;
  iVar3 = DAT_200003ea / 10 + 2000;
  DAT_20000e0b = (undefined1)((uint)iVar3 >> 8);
  DAT_20000e0c = (undefined1)iVar3;
  uVar1 = 2000 - DAT_200003ea / 10 & 0xffff;
  DAT_20000e0d = (undefined1)(uVar1 >> 8);
  DAT_20000e0e = (undefined1)uVar1;
  iVar3 = DAT_200003ea / 10 + 0x898;
  DAT_20000e0f = (undefined1)((uint)iVar3 >> 8);
  DAT_20000e10 = (undefined1)iVar3;
  uVar1 = 0x898 - DAT_200003ea / 10 & 0xffff;
  DAT_20000e11 = (undefined1)(uVar1 >> 8);
  DAT_20000e12 = (undefined1)uVar1;
  iVar3 = DAT_200003ea / 10 + 2000;
  DAT_20000e13 = (undefined1)((uint)iVar3 >> 8);
  DAT_20000e14 = (undefined1)iVar3;
  uVar1 = 2000 - DAT_200003ea / 10 & 0xffff;
  DAT_20000e15 = (undefined1)(uVar1 >> 8);
  DAT_20000e16 = (undefined1)uVar1;
  iVar3 = DAT_200003ea / 10 + 0x834;
  DAT_20000e17 = (undefined1)((uint)iVar3 >> 8);
  DAT_20000e18 = (undefined1)iVar3;
  uVar1 = 0x834 - DAT_200003ea / 10 & 0xffff;
  DAT_20000e19 = (undefined1)(uVar1 >> 8);
  DAT_20000e1a = (undefined1)uVar1;
  uVar1 = DAT_200003ea / 10 + 35000 & 0xffff;
  DAT_20000dc8 = (undefined1)(uVar1 / 100 - 100 >> 8);
  DAT_20000dc9 = (char)(uVar1 / 100) + -100;
  uVar1 = DAT_200003ea / 10 + 34000 & 0xffff;
  DAT_20000dca = (undefined1)(uVar1 / 100 - 100 >> 8);
  DAT_20000dcb = (char)(uVar1 / 100) + -100;
  DAT_20000dcc = 0x27;
  DAT_20000dcd = 0x1f;
  DAT_20000dce = DAT_200003ea / 10 + 0x32;
  DAT_20000dcf = 100;
  DAT_20000dd0 = 0x41;
  DAT_20000dd1 = 0x2d;
  DAT_20000dd2 = 0x55;
  DAT_20000dd3 = 0x42;
  DAT_20000dd4 = 0x2e;
  DAT_20000dd5 = 0x56;
  DAT_20000dd6 = 0x14;
  DAT_20000dd9 = 1;
  DAT_20000dda = 1;
  DAT_20000ddb = 0;
  DAT_20000ddc = 1;
  DAT_20000ddd = 0;
  DAT_20000dde = 0xaa;
  DAT_20000ddf = 0;
  DAT_20000de0 = 0xe6;
  DAT_20000de5 = DAT_2000037b;
  iVar3 = DAT_200003ea / 10 + 0x1068;
  DAT_20000de6 = (undefined1)((uint)iVar3 >> 8);
  DAT_20000de7 = (undefined1)iVar3;
  iVar3 = DAT_200003ea / 10 + 2000;
  DAT_20000de8 = (undefined1)((uint)iVar3 >> 8);
  DAT_20000de9 = (undefined1)iVar3;
  DAT_20000dea = (char)(DAT_200003ea / 10) - (char)(((int)(DAT_200003ea / 10) >> 2) << 2);
  DAT_20000deb = 0;
  DAT_20000dec = 0;
  DAT_20000ded = 0;
  DAT_20000dee = 0;
  DAT_20000def = 0;
  DAT_20000df0 = 0;
  DAT_20000df1 = 0;
  DAT_20000df3 = 0;
  DAT_20000df2 = 0;
  DAT_20000df4 = 2;
  DAT_20000df5 = 3;
  DAT_20000df6 = 0;
  DAT_20000df7 = 1;
  DAT_20000df8 = 1;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d0b) = 1;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d0c) = 1;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d19) = 0xe3;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d0d) = 0xe3;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d0e) = 0x1e;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d0f) = 0x50;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d10) = 0x14;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d11) = 0x33;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d13) = 100;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d14) = 0x50;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d15) = 0x3c;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d17) = 0x2d;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d18) = 0x3c;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d1a) = DAT_20000306;
  DAT_20000d6b = 0xf0;
  DAT_20000d6c = 0x59;
  DAT_20000d6d = 1;
  DAT_20000d6e = 0x2c;
  DAT_20000d6f = 0x3c;
  DAT_20000d70 = 0;
  DAT_20000d71 = 100;
  DAT_20000d72 = 0x19;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800e5f4   (0x0800E5F4, 1033 Bytes)
 * Body: 0x0800E5F4-0x0800E9FD
 * --------------------------------------------------------------------- */
void FUN_0800e5f4(void)

{
  uint uVar1;
  byte bVar2;
  byte *in_r3;
  int iVar3;
  
  uVar1 = 3000 - *in_r3 / 10 & 0xffff;
  DAT_20000dc2 = (undefined1)(uVar1 >> 8);
  DAT_20000dc3 = (undefined1)uVar1;
  iVar3 = DAT_200003ea / 10 + 0xc1c;
  DAT_20000dc4 = (undefined1)((uint)iVar3 >> 8);
  DAT_20000dc5 = (undefined1)iVar3;
  uVar1 = 0xc1c - DAT_200003ea / 10 & 0xffff;
  DAT_20000dc6 = (undefined1)(uVar1 >> 8);
  DAT_20000dc7 = (undefined1)uVar1;
  bVar2 = DAT_200003ea + 1;
  iVar3 = bVar2 / 10 + 4000;
  DAT_20000dfb = (undefined1)((uint)iVar3 >> 8);
  DAT_20000dfc = (undefined1)iVar3;
  uVar1 = 4000 - bVar2 / 10 & 0xffff;
  DAT_20000dfd = (undefined1)(uVar1 >> 8);
  DAT_20000dfe = (undefined1)uVar1;
  iVar3 = bVar2 / 10 + 0x1068;
  DAT_20000dff = (undefined1)((uint)iVar3 >> 8);
  DAT_20000e00 = (undefined1)iVar3;
  uVar1 = 0x1068 - bVar2 / 10 & 0xffff;
  DAT_20000e01 = (undefined1)(uVar1 >> 8);
  DAT_20000e02 = (undefined1)uVar1;
  iVar3 = bVar2 / 10 + 4000;
  DAT_20000e03 = (undefined1)((uint)iVar3 >> 8);
  DAT_20000e04 = (undefined1)iVar3;
  uVar1 = 4000 - bVar2 / 10 & 0xffff;
  DAT_20000e05 = (undefined1)(uVar1 >> 8);
  DAT_20000e06 = (undefined1)uVar1;
  iVar3 = bVar2 / 10 + 0x1004;
  DAT_20000e07 = (undefined1)((uint)iVar3 >> 8);
  DAT_20000e08 = (undefined1)iVar3;
  uVar1 = 0x1004 - bVar2 / 10 & 0xffff;
  DAT_20000e09 = (undefined1)(uVar1 >> 8);
  DAT_20000e0a = (undefined1)uVar1;
  DAT_200003ea = DAT_200003ea + 2;
  iVar3 = DAT_200003ea / 10 + 2000;
  DAT_20000e0b = (undefined1)((uint)iVar3 >> 8);
  DAT_20000e0c = (undefined1)iVar3;
  uVar1 = 2000 - DAT_200003ea / 10 & 0xffff;
  DAT_20000e0d = (undefined1)(uVar1 >> 8);
  DAT_20000e0e = (undefined1)uVar1;
  iVar3 = DAT_200003ea / 10 + 0x898;
  DAT_20000e0f = (undefined1)((uint)iVar3 >> 8);
  DAT_20000e10 = (undefined1)iVar3;
  uVar1 = 0x898 - DAT_200003ea / 10 & 0xffff;
  DAT_20000e11 = (undefined1)(uVar1 >> 8);
  DAT_20000e12 = (undefined1)uVar1;
  iVar3 = DAT_200003ea / 10 + 2000;
  DAT_20000e13 = (undefined1)((uint)iVar3 >> 8);
  DAT_20000e14 = (undefined1)iVar3;
  uVar1 = 2000 - DAT_200003ea / 10 & 0xffff;
  DAT_20000e15 = (undefined1)(uVar1 >> 8);
  DAT_20000e16 = (undefined1)uVar1;
  iVar3 = DAT_200003ea / 10 + 0x834;
  DAT_20000e17 = (undefined1)((uint)iVar3 >> 8);
  DAT_20000e18 = (undefined1)iVar3;
  uVar1 = 0x834 - DAT_200003ea / 10 & 0xffff;
  DAT_20000e19 = (undefined1)(uVar1 >> 8);
  DAT_20000e1a = (undefined1)uVar1;
  uVar1 = DAT_200003ea / 10 + 35000 & 0xffff;
  DAT_20000dc8 = (undefined1)(uVar1 / 100 - 100 >> 8);
  DAT_20000dc9 = (char)(uVar1 / 100) + -100;
  uVar1 = DAT_200003ea / 10 + 34000 & 0xffff;
  DAT_20000dca = (undefined1)(uVar1 / 100 - 100 >> 8);
  DAT_20000dcb = (char)(uVar1 / 100) + -100;
  DAT_20000dcc = 0x27;
  DAT_20000dcd = 0x1f;
  DAT_20000dce = DAT_200003ea / 10 + 0x32;
  DAT_20000dcf = 100;
  DAT_20000dd0 = 0x41;
  DAT_20000dd1 = 0x2d;
  DAT_20000dd2 = 0x55;
  DAT_20000dd3 = 0x42;
  DAT_20000dd4 = 0x2e;
  DAT_20000dd5 = 0x56;
  DAT_20000dd6 = 0x14;
  DAT_20000dd9 = 1;
  DAT_20000dda = 1;
  DAT_20000ddb = 0;
  DAT_20000ddc = 1;
  DAT_20000ddd = 0;
  DAT_20000dde = 0xaa;
  DAT_20000ddf = 0;
  DAT_20000de0 = 0xe6;
  DAT_20000de5 = DAT_2000037b;
  iVar3 = DAT_200003ea / 10 + 0x1068;
  DAT_20000de6 = (undefined1)((uint)iVar3 >> 8);
  DAT_20000de7 = (undefined1)iVar3;
  iVar3 = DAT_200003ea / 10 + 2000;
  DAT_20000de8 = (undefined1)((uint)iVar3 >> 8);
  DAT_20000de9 = (undefined1)iVar3;
  DAT_20000dea = (char)(DAT_200003ea / 10) - (char)(((int)(DAT_200003ea / 10) >> 2) << 2);
  DAT_20000deb = 0;
  DAT_20000dec = 0;
  DAT_20000ded = 0;
  DAT_20000dee = 0;
  DAT_20000def = 0;
  DAT_20000df0 = 0;
  DAT_20000df1 = 0;
  DAT_20000df3 = 0;
  DAT_20000df2 = 0;
  DAT_20000df4 = 2;
  DAT_20000df5 = 3;
  DAT_20000df6 = 0;
  DAT_20000df7 = 1;
  DAT_20000df8 = 1;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d0b) = 1;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d0c) = 1;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d19) = 0xe3;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d0d) = 0xe3;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d0e) = 0x1e;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d0f) = 0x50;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d10) = 0x14;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d11) = 0x33;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d13) = 100;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d14) = 0x50;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d15) = 0x3c;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d17) = 0x2d;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d18) = 0x3c;
  *(undefined1 *)((uint)DAT_200002a1 * 0x10 + 0x20000d1a) = DAT_20000306;
  DAT_20000d6b = 0xf0;
  DAT_20000d6c = 0x59;
  DAT_20000d6d = 1;
  DAT_20000d6e = 0x2c;
  DAT_20000d6f = 0x3c;
  DAT_20000d70 = 0;
  DAT_20000d71 = 100;
  DAT_20000d72 = 0x19;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800e9fe   (0x0800E9FE, 1 Bytes)
 * Body: 0x0800E9FE-0x0800E9FF
 * --------------------------------------------------------------------- */
void FUN_0800e9fe(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800ea34   (0x0800EA34, 53 Bytes)
 * Body: 0x0800EA34-0x0800EA69
 * --------------------------------------------------------------------- */
void FUN_0800ea34(void)

{
  if (DAT_200003fa == '\0') {
    FUN_0800c192();
    DAT_200003fa = DAT_200003fa + '\x01';
  }
  else if (DAT_200003fa == '\x01') {
    FUN_0800c0ae();
    DAT_200003fa = '\0';
  }
  else {
    DAT_200003fa = '\0';
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800ea68   (0x0800EA68, 1 Bytes)
 * Body: 0x0800EA68-0x0800EA69
 * --------------------------------------------------------------------- */
void FUN_0800ea68(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800ea6a   (0x0800EA6A, 116 Bytes, 2 Teile)
 * Body: 0x0800EA6A-0x0800EA77, 0x0800EA7E-0x0800EAE5
 * --------------------------------------------------------------------- */
void FUN_0800ea6a(void)

{
  switch(DAT_200003fb) {
  case '\0':
    FUN_0800c226();
    DAT_200003fb = DAT_200003fb + '\x01';
    break;
  case '\x01':
    FUN_0800c1d6();
    DAT_200003fb = DAT_200003fb + '\x01';
    break;
  case '\x02':
    FUN_0800c142();
    DAT_200003fb = DAT_200003fb + '\x01';
    break;
  case '\x03':
    FUN_0800c0f2();
    DAT_200003fb = DAT_200003fb + '\x01';
    break;
  case '\x04':
    FUN_0800c060();
    DAT_200003fb = DAT_200003fb + '\x01';
    break;
  case '\x05':
    FUN_0800c010();
    DAT_200003fb = '\0';
    break;
  default:
    DAT_200003fb = '\0';
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800eae6   (0x0800EAE6, 53 Bytes)
 * Body: 0x0800EAE6-0x0800EB1B
 * --------------------------------------------------------------------- */
void FUN_0800eae6(void)

{
  if (DAT_200003fd == '\0') {
    FUN_0800bfb8();
    DAT_200003fd = DAT_200003fd + '\x01';
  }
  else if (DAT_200003fd == '\x01') {
    FUN_0800bf68();
    DAT_200003fd = '\0';
  }
  else {
    DAT_200003fd = '\0';
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800eb50   (0x0800EB50, 27 Bytes)
 * Body: 0x0800EB50-0x0800EB6B
 * --------------------------------------------------------------------- */
void FUN_0800eb50(void)

{
  undefined1 uVar1;
  undefined4 uStack00000000;
  undefined4 in_stack_00000004;
  undefined4 in_stack_00000008;
  undefined4 in_stack_0000000c;
  undefined4 in_stack_00000010;
  undefined3 uStack00000014;
  
  uVar1 = FUN_0800bda6((int)&stack0x00000004,0x13);
  _uStack00000014 = CONCAT13(uVar1,uStack00000014);
  uStack00000000 = _uStack00000014;
  FUN_0800bd54(in_stack_00000004,in_stack_00000008,in_stack_0000000c,in_stack_00000010);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800eb6c   (0x0800EB6C, 79 Bytes)
 * Body: 0x0800EB6C-0x0800EBBB
 * --------------------------------------------------------------------- */
void FUN_0800eb6c(void)

{
  undefined1 uVar1;
  uint uVar2;
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined3 local_c;
  undefined1 uStack_9;
  
  local_1c = CONCAT22(local_1c._2_2_,0x6255);
  FUN_0800b990((undefined1 *)((int)&local_1c + 2),(undefined1 *)0x200003b9,6);
  for (uVar2 = 6; uVar2 < 0x10; uVar2 = uVar2 + 1 & 0xff) {
    *(undefined1 *)((int)&local_1c + uVar2 + 3) = 0xff;
  }
  uVar1 = FUN_0800bda6((int)&local_1c,0x13);
  _local_c = CONCAT13(uVar1,local_c);
  FUN_0800bd54(local_1c,uStack_18,uStack_14,uStack_10);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800ebba   (0x0800EBBA, 1 Bytes)
 * Body: 0x0800EBBA-0x0800EBBB
 * --------------------------------------------------------------------- */
void FUN_0800ebba(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800eda0   (0x0800EDA0, 211 Bytes)
 * Body: 0x0800EDA0-0x0800EE73
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0800eda0(void)

{
  uint uVar1;
  
  FUN_0800b97a((undefined1 *)0x20001030,0,0x194);
  FUN_0800b97a((undefined1 *)0x200011c4,0,0x194);
  FUN_0800b97a(&DAT_20001358,0,0x27);
  FUN_0800b97a(&DAT_2000137f,0,0x13);
  FUN_0800b97a(&DAT_20001392,0,0x14);
  FUN_0800b97a(&DAT_200013a6,0,0xd);
  DAT_200002a0 = 0;
  DAT_200002a1 = 0;
  DAT_200002a2 = 0;
  DAT_200002a3 = 0;
  DAT_200002a4 = 0;
  DAT_200002a5 = 0;
  DAT_200002a6 = 0;
  DAT_200002b9 = 0;
  DAT_200002c6 = 0;
  DAT_200002c7 = 0;
  for (uVar1 = 0; uVar1 < 6; uVar1 = uVar1 + 1 & 0xff) {
    (&DAT_200002ad)[uVar1] = 0;
    (&DAT_200002a7)[uVar1] = 0;
    (&DAT_200002b3)[uVar1] = 0;
    (&DAT_200002c0)[uVar1] = 0;
    (&DAT_200002ba)[uVar1] = 0;
  }
  DAT_2000030b = 1;
  DAT_2000030e = 1;
  DAT_2000030f = 0;
  DAT_20000310 = 0;
  DAT_20000311 = 0;
  DAT_200002e4 = 0x23;
  _DAT_200002e2 = 30000;
  DAT_200002cd = 1;
  DAT_20000314 = 1;
  DAT_200002ce = 0;
  DAT_200002cf = 0;
  DAT_200002d0 = 0;
  DAT_20000398 = 0xff;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800ee76   (0x0800EE76, 287 Bytes)
 * Display-Frames 0x8A/0x8B/0x8C: Datenuebernahme (3-stufig) + Sonderbefehle
 * Body: 0x0800EE76-0x0800EF95
 * --------------------------------------------------------------------- */
void FUN_0800ee76(void)

{
  if (DAT_2000040a == '\x01') {
    DAT_2000040a = '\0';
    if (DAT_200013b3 == -0x76) {
      if (DAT_200013b5 == '\b') {
        DAT_20000768 = DAT_200013b6;
        DAT_20000769 = DAT_200013b7;
        DAT_2000076a = DAT_200013b8;
        DAT_2000076b = DAT_200013b9;
        DAT_2000076c = DAT_200013ba;
        DAT_2000076d = DAT_200013bb;
        DAT_2000076e = DAT_200013bc;
        DAT_200000a4 = '\x01';
      }
      else if (DAT_200013b5 == '\t') {
        if (DAT_200000a4 == '\x01') {
          DAT_2000076f = DAT_200013b6;
          DAT_20000770 = DAT_200013b7;
          DAT_20000771 = DAT_200013b8;
          DAT_20000772 = DAT_200013b9;
          DAT_20000773 = DAT_200013ba;
          DAT_20000774 = DAT_200013bb;
          DAT_20000775 = DAT_200013bc;
          DAT_200000a4 = '\x02';
        }
      }
      else if ((DAT_200013b5 == '\n') && (DAT_200000a4 == '\x02')) {
        DAT_20000776 = DAT_200013b6;
        DAT_20000777 = DAT_200013b7;
        DAT_20000778 = DAT_200013b8;
        DAT_20000779 = DAT_200013b9;
        DAT_2000077a = DAT_200013ba;
        DAT_200000a4 = '\0';
        FUN_08018236(0x20000768);
      }
    }
    else if (DAT_200013b3 == -0x75) {
      if (((DAT_200013b5 == -0x56) && (DAT_200013b7 == -0x56)) && (DAT_200013b9 == -0x56)) {
        FUN_08016ec0();
      }
    }
    else if ((((DAT_200013b3 == -0x74) && (DAT_200013b5 == '\x01')) && (DAT_200013b8 == -0x56)) &&
            (DAT_200013b9 == -0x56)) {
      FUN_08017e1a();
    }
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800ef96   (0x0800EF96, 1094 Bytes, 2 Teile)
 * Fahrzeug-State-Machine (100ms): Flags, Modi, Statusbyte 0x20000306
 * Body: 0x0800EF96-0x0800F1A3, 0x0800F2C0-0x0800F4F9
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0800ef96(void)

{
  uint uVar1;
  uint uVar2;
  
  _DAT_200002f0 =
       (undefined2)
       ((ulonglong)
        (((uint)DAT_20000377 << 0x18 | (uint)DAT_20000378 << 0x10 | (uint)DAT_20000379 << 8 |
         (uint)DAT_2000037a) * 5) / ((ulonglong)CONCAT11(DAT_20000375,DAT_20000376) << 2));
  if (_DAT_2000041a == 0) {
    _DAT_20000304 = 0;
    _DAT_2000041a = 1;
    _DAT_2000041c = 0;
  }
  else {
    uVar2 = (uint)CONCAT11(DAT_20000362,DAT_20000363);
    if ((((5000 < uVar2) && (uVar2 < 0x2706)) && (DAT_20000390 == '\0')) &&
       (_DAT_2000041c = (uint)DAT_200002c7 * (10000 - uVar2) + _DAT_2000041c, 299999 < _DAT_2000041c
       )) {
      _DAT_20000304 = _DAT_20000304 + 1;
      _DAT_2000041c = _DAT_2000041c - 300000;
    }
  }
  if ((DAT_2000029f == '\0') && (0x68 < DAT_2000036d)) {
    DAT_2000029f = '\x02';
  }
  else if ((DAT_2000029f != '\0') && (DAT_2000036d < 0x67)) {
    DAT_2000029f = '\0';
  }
  DAT_200002f2 = 0;
  if ((DAT_20000386 == '\x03') || (DAT_20000384 == '\x03')) {
    DAT_200002f2 = 1;
  }
  if ((DAT_20000387 == '\x03') || (DAT_20000385 == '\x03')) {
    DAT_200002f2 = DAT_200002f2 | 2;
  }
  if ((((DAT_20000380 == '\x03') || (DAT_20000382 == '\x03')) || (DAT_2000038d == '\x03')) ||
     (DAT_2000038e == '\x03')) {
    DAT_200002f2 = DAT_200002f2 | 4;
  }
  if ((DAT_20000389 == '\x03') || (DAT_20000388 == '\x03')) {
    DAT_200002f2 = DAT_200002f2 | 8;
  }
  if (DAT_2000029f != '\0') {
    DAT_200002f2 = DAT_200002f2 | 0x10;
  }
  if (DAT_20000064 == '\0') {
    DAT_200002f2 = DAT_200002f2 | 0x80;
  }
  if (DAT_2000030e != '\0') {
    DAT_200002f2 = DAT_200002f2 | 0x40;
  }
  if (4 < _DAT_200002e2) {
    _DAT_200002fc = (ushort)(((uint)DAT_200002a5 * 0x11f) / (uint)_DAT_200002e2);
  }
  if (0x63f < _DAT_200002fc) {
    _DAT_200002fc = 0x640;
  }
  if (4 < _DAT_200002ec) {
    _DAT_20000316 = (ushort)(((uint)DAT_200002a5 * 0x11f) / (uint)_DAT_200002ec);
  }
  if (0x63f < _DAT_20000316) {
    _DAT_20000316 = 0x640;
  }
  _DAT_20000318 = _DAT_200002fc;
  if (_DAT_200002f8 < _DAT_200002fc) {
    _DAT_200002f8 = _DAT_200002fc;
  }
  _DAT_200002fa = (undefined2)((uint)_DAT_200002f8 * 0xa000 >> 0x10);
  if (_DAT_200002e8 < 5) {
    _DAT_200002e8 = 0;
  }
  if (_DAT_200002de < 5) {
    _DAT_200002de = 0;
  }
  _DAT_20000412 = _DAT_200002fc;
  uVar2 = (uint)_DAT_20000418;
  _DAT_20000418 = _DAT_20000418 + 1;
  *(ushort *)(uVar2 * 2 + 0x200013c0) = _DAT_200002fc;
  if (_DAT_20000418 == 10) {
    _DAT_20000418 = 0;
  }
  uVar1 = 0;
  for (uVar2 = 0; uVar2 < 10; uVar2 = uVar2 + 1 & 0xff) {
    uVar1 = uVar1 + (int)*(short *)(uVar2 * 2 + 0x200013c0);
  }
  _DAT_200002f4 = (ushort)(uVar1 / 10);
  if (_DAT_200002f4 < 2) {
    _DAT_200002f4 = 0;
  }
  _DAT_200002f6 = (short)((uint)_DAT_200002f4 * 0xa000 >> 0x10);
  if (DAT_20000310 == '\0') {
    DAT_200002a2 = DAT_200002a2 & 0xef;
  }
  else {
    DAT_200002a2 = DAT_200002a2 | 0x10;
  }
  if (DAT_20000311 == '\0') {
    DAT_200002a3 = DAT_200002a3 & 0xef;
  }
  else {
    DAT_200002a3 = DAT_200002a3 | 0x10;
  }
  if (((DAT_2000039a == '\0') && (DAT_20000399 == '\x01')) && (_DAT_200002f4 < 0x3c)) {
    DAT_2000039a = '\x01';
  }
  else if ((DAT_2000039a != '\0') && (DAT_20000399 == '\0')) {
    DAT_2000039a = '\0';
  }
  DAT_20000306 = DAT_20000309 | DAT_20000308 << 1 | DAT_20000390 << 2 | DAT_20000312 << 4 |
                 DAT_20000399 << 5 | DAT_2000004c << 6 | DAT_2000031b << 7;
  if ((DAT_2000030e == '\0') && (*_FUN_0800f720 == '\0')) {
    DAT_20000307 = DAT_200002da & 0x7f;
  }
  else {
    DAT_20000307 = DAT_200002da | 0x80;
  }
  if (*pcRam0800f724 == '\0') {
    DAT_20000307 = DAT_20000307 & 0xbf;
  }
  else {
    DAT_20000307 = DAT_20000307 | 0x40;
  }
  if (DAT_20000312 == '\0') {
    DAT_20000307 = DAT_20000307 & 0xef;
  }
  else {
    DAT_20000307 = DAT_20000307 | 0x10;
  }
  if (DAT_2000031b == '\0') {
    DAT_20000307 = DAT_20000307 & 0xf7;
  }
  else {
    DAT_20000307 = DAT_20000307 | 8;
  }
  if (DAT_2000039a == '\0') {
    DAT_20000307 = DAT_20000307 & 0xfb;
  }
  else {
    DAT_20000307 = DAT_20000307 | 4;
  }
  if ((((DAT_200002da & 4) == 4) && (DAT_2000030c != '\x01')) && (DAT_2000030b != '\0')) {
    DAT_2000030b = 1;
  }
  else {
    DAT_2000030b = 0;
  }
  return;
}



/* =====================================================================
 *  SEKTION: 0x0800F000 - ESC-/Display-Builder, Queues, TX-Pump
 * ===================================================================== */

/* ---------------------------------------------------------------------
 * thunk_FUN_0800f2c0   (0x0800F1A2, 1 Bytes)
 * Body: 0x0800F1A2-0x0800F1A3
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thunk_FUN_0800f2c0(void)

{
  uint uVar1;
  uint uVar2;
  char in_NG;
  bool in_ZR;
  char in_OV;
  
  if (!in_ZR && in_NG == in_OV) {
    _DAT_200002f8 = _DAT_200002fc;
  }
  _DAT_200002fa = (undefined2)((uint)_DAT_200002f8 * 0xa000 >> 0x10);
  if (_DAT_200002e8 < 5) {
    _DAT_200002e8 = 0;
  }
  if (_DAT_200002de < 5) {
    _DAT_200002de = 0;
  }
  _DAT_20000412 = _DAT_200002fc;
  uVar2 = (uint)_DAT_20000418;
  _DAT_20000418 = _DAT_20000418 + 1;
  *(ushort *)(uVar2 * 2 + 0x200013c0) = _DAT_200002fc;
  if (_DAT_20000418 == 10) {
    _DAT_20000418 = 0;
  }
  uVar1 = 0;
  for (uVar2 = 0; uVar2 < 10; uVar2 = uVar2 + 1 & 0xff) {
    uVar1 = uVar1 + (int)*(short *)(uVar2 * 2 + 0x200013c0);
  }
  _DAT_200002f4 = (ushort)(uVar1 / 10);
  if (_DAT_200002f4 < 2) {
    _DAT_200002f4 = 0;
  }
  _DAT_200002f6 = (short)((uint)_DAT_200002f4 * 0xa000 >> 0x10);
  if (DAT_20000310 == '\0') {
    DAT_200002a2 = DAT_200002a2 & 0xef;
  }
  else {
    DAT_200002a2 = DAT_200002a2 | 0x10;
  }
  if (DAT_20000311 == '\0') {
    DAT_200002a3 = DAT_200002a3 & 0xef;
  }
  else {
    DAT_200002a3 = DAT_200002a3 | 0x10;
  }
  if (((DAT_2000039a == '\0') && (DAT_20000399 == '\x01')) && (_DAT_200002f4 < 0x3c)) {
    DAT_2000039a = '\x01';
  }
  else if ((DAT_2000039a != '\0') && (DAT_20000399 == '\0')) {
    DAT_2000039a = '\0';
  }
  DAT_20000306 = DAT_20000309 | DAT_20000308 << 1 | DAT_20000390 << 2 | DAT_20000312 << 4 |
                 DAT_20000399 << 5 | DAT_2000004c << 6 | DAT_2000031b << 7;
  if ((DAT_2000030e == '\0') && (*_FUN_0800f720 == '\0')) {
    DAT_20000307 = DAT_200002da & 0x7f;
  }
  else {
    DAT_20000307 = DAT_200002da | 0x80;
  }
  if (*pcRam0800f724 == '\0') {
    DAT_20000307 = DAT_20000307 & 0xbf;
  }
  else {
    DAT_20000307 = DAT_20000307 | 0x40;
  }
  if (DAT_20000312 == '\0') {
    DAT_20000307 = DAT_20000307 & 0xef;
  }
  else {
    DAT_20000307 = DAT_20000307 | 0x10;
  }
  if (DAT_2000031b == '\0') {
    DAT_20000307 = DAT_20000307 & 0xf7;
  }
  else {
    DAT_20000307 = DAT_20000307 | 8;
  }
  if (DAT_2000039a == '\0') {
    DAT_20000307 = DAT_20000307 & 0xfb;
  }
  else {
    DAT_20000307 = DAT_20000307 | 4;
  }
  if ((((DAT_200002da & 4) == 4) && (DAT_2000030c != '\x01')) && (DAT_2000030b != '\0')) {
    DAT_2000030b = 1;
  }
  else {
    DAT_2000030b = 0;
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800f2c0   (0x0800F2C0, 569 Bytes)
 * Body: 0x0800F2C0-0x0800F4F9
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0800f2c0(void)

{
  uint uVar1;
  uint uVar2;
  char in_NG;
  bool in_ZR;
  char in_OV;
  
  if (!in_ZR && in_NG == in_OV) {
    _DAT_200002f8 = _DAT_200002fc;
  }
  _DAT_200002fa = (undefined2)((uint)_DAT_200002f8 * 0xa000 >> 0x10);
  if (_DAT_200002e8 < 5) {
    _DAT_200002e8 = 0;
  }
  if (_DAT_200002de < 5) {
    _DAT_200002de = 0;
  }
  _DAT_20000412 = _DAT_200002fc;
  uVar2 = (uint)_DAT_20000418;
  _DAT_20000418 = _DAT_20000418 + 1;
  *(ushort *)(uVar2 * 2 + 0x200013c0) = _DAT_200002fc;
  if (_DAT_20000418 == 10) {
    _DAT_20000418 = 0;
  }
  uVar1 = 0;
  for (uVar2 = 0; uVar2 < 10; uVar2 = uVar2 + 1 & 0xff) {
    uVar1 = uVar1 + (int)*(short *)(uVar2 * 2 + 0x200013c0);
  }
  _DAT_200002f4 = (ushort)(uVar1 / 10);
  if (_DAT_200002f4 < 2) {
    _DAT_200002f4 = 0;
  }
  _DAT_200002f6 = (short)((uint)_DAT_200002f4 * 0xa000 >> 0x10);
  if (DAT_20000310 == '\0') {
    DAT_200002a2 = DAT_200002a2 & 0xef;
  }
  else {
    DAT_200002a2 = DAT_200002a2 | 0x10;
  }
  if (DAT_20000311 == '\0') {
    DAT_200002a3 = DAT_200002a3 & 0xef;
  }
  else {
    DAT_200002a3 = DAT_200002a3 | 0x10;
  }
  if (((DAT_2000039a == '\0') && (DAT_20000399 == '\x01')) && (_DAT_200002f4 < 0x3c)) {
    DAT_2000039a = '\x01';
  }
  else if ((DAT_2000039a != '\0') && (DAT_20000399 == '\0')) {
    DAT_2000039a = '\0';
  }
  DAT_20000306 = DAT_20000309 | DAT_20000308 << 1 | DAT_20000390 << 2 | DAT_20000312 << 4 |
                 DAT_20000399 << 5 | DAT_2000004c << 6 | DAT_2000031b << 7;
  if ((DAT_2000030e == '\0') && (*_FUN_0800f720 == '\0')) {
    DAT_20000307 = DAT_200002da & 0x7f;
  }
  else {
    DAT_20000307 = DAT_200002da | 0x80;
  }
  if (*pcRam0800f724 == '\0') {
    DAT_20000307 = DAT_20000307 & 0xbf;
  }
  else {
    DAT_20000307 = DAT_20000307 | 0x40;
  }
  if (DAT_20000312 == '\0') {
    DAT_20000307 = DAT_20000307 & 0xef;
  }
  else {
    DAT_20000307 = DAT_20000307 | 0x10;
  }
  if (DAT_2000031b == '\0') {
    DAT_20000307 = DAT_20000307 & 0xf7;
  }
  else {
    DAT_20000307 = DAT_20000307 | 8;
  }
  if (DAT_2000039a == '\0') {
    DAT_20000307 = DAT_20000307 & 0xfb;
  }
  else {
    DAT_20000307 = DAT_20000307 | 4;
  }
  if ((((DAT_200002da & 4) == 4) && (DAT_2000030c != '\x01')) && (DAT_2000030b != '\0')) {
    DAT_2000030b = 1;
  }
  else {
    DAT_2000030b = 0;
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800f4fa   (0x0800F4FA, 907 Bytes, 3 Teile)
 * Kommandoprozessor: ESC-0x71(':'/';') + Display-0x4C (Cmd 1..9: Gang/Eco/Dual/Clamp/Settings-Write)
 * Body: 0x0800F4FA-0x0800F5F3, 0x0800F5FE-0x0800F6B7, 0x0800F794-0x0800F96D
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0800f4fa(void)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  
  bVar2 = DAT_200002a3;
  if (DAT_200013a8 == ':') {
    DAT_200002db = DAT_200013a9;
    DAT_200002dc = DAT_200013aa;
    _DAT_200002de = CONCAT11(DAT_200013ab,DAT_200013ac);
    DAT_200002e0 = DAT_200013ad;
    _DAT_200002e2 = CONCAT11(DAT_200013ae,DAT_200013af);
    DAT_200002e4 = DAT_200013b0;
    DAT_200002e5 = DAT_200013b1;
    DAT_20000409 = 1;
    if ((DAT_200013b1 & 1) == 0) {
      DAT_20000398 = 0;
    }
    else {
      DAT_20000398 = 1;
    }
  }
  else if (DAT_200013a8 == ';') {
    DAT_200002e6 = DAT_200013a9;
    DAT_200002e7 = DAT_200013aa;
    _DAT_200002e8 = CONCAT11(DAT_200013ab,DAT_200013ac);
    DAT_200002ea = DAT_200013ad;
    _DAT_200002ec = CONCAT11(DAT_200013ae,DAT_200013af);
    DAT_200002ee = DAT_200013b0;
    DAT_200002ef = DAT_200013b1;
    DAT_20000409 = 3;
  }
  if (DAT_20001381 == '5') {
    DAT_200002d8 = DAT_20001382;
    DAT_2000030f = (DAT_20001385 & 0x40) != 0;
    switch(DAT_20001382) {
    case 0:
      break;
    case 1:
      if ((DAT_20000309 == '\0') && (DAT_200002a1 = DAT_20001383, 5 < DAT_20001383)) {
        DAT_200002a1 = 5;
      }
      break;
    case 2:
      if (DAT_20000309 == '\0') {
        bVar3 = DAT_200002a3 & 0xfe;
        if ((DAT_20001384 & 0x80) == 0x80) {
          DAT_200002a3 = bVar3 | DAT_20001384 & 1 | 0x80;
        }
        else {
          DAT_200002a3 = DAT_200002a3 & 0x7e | DAT_20001384 & 1;
        }
        if ((DAT_20001384 & 0x40) == 0x40) {
          DAT_200002a2 = bVar3 | DAT_20001384 & 1 | 0x80;
        }
        else {
          DAT_200002a2 = bVar2 & 0x7e | DAT_20001384 & 1;
        }
        if ((DAT_20001384 & 1) != 0) {
          DAT_2000030a = 3;
        }
        if ((DAT_20001384 & 0x20) == 0x20) {
          DAT_2000030d = 1;
        }
        else {
          DAT_2000030d = 0;
        }
      }
      break;
    case 3:
      bVar1 = (DAT_20001385 & 1) == 0;
      if (bVar1) {
        DAT_200002da = DAT_200002da & 0xfe;
      }
      else {
        DAT_200002da = DAT_200002da | 1;
      }
      DAT_20000309 = !bVar1;
      break;
    case 4:
      bVar1 = (DAT_20001385 & 2) == 0;
      if (bVar1) {
        DAT_200002da = DAT_200002da & 0xfd;
      }
      else {
        DAT_200002da = DAT_200002da | 2;
      }
      DAT_20000308 = !bVar1;
      break;
    case 5:
      if ((DAT_20001384 & 0x10) == 0x10) {
        DAT_200002a3 = DAT_200002a3 | 0x40;
        DAT_200002a2 = DAT_200002a2 | 0x40;
      }
      else {
        DAT_200002a3 = DAT_200002a3 & 0xbf;
        DAT_200002a2 = DAT_200002a2 & 0xbf;
      }
      if ((DAT_20001384 & 8) == 8) {
        DAT_200002a3 = DAT_200002a3 | 8;
        DAT_200002a2 = DAT_200002a2 | 8;
      }
      else {
        DAT_200002a3 = DAT_200002a3 & 0xf7;
        DAT_200002a2 = DAT_200002a2 & 0xf7;
      }
      DAT_200002a3 = DAT_20001384 & 6 | DAT_200002a3 & 0xf9;
      DAT_200002a2 = DAT_20001384 & 6 | DAT_200002a2 & 0xf9;
      DAT_200002a4 = DAT_20001386;
      DAT_200002a5 = DAT_20001387;
      DAT_200002a6 = DAT_20001388 * '\x05' + 'P';
      (&DAT_200002a7)[DAT_20001383] = DAT_20001389;
      (&DAT_200002ad)[DAT_20001383] = DAT_20001389 & 0xf0 | DAT_2000138a & 0xf;
      (&DAT_200002b3)[DAT_20001383] = DAT_2000138b;
      DAT_200002b9 = DAT_2000138c;
      (&DAT_200002ba)[DAT_20001383] = DAT_2000138d;
      (&DAT_200002c0)[DAT_20001383] = DAT_2000138e;
      DAT_200002c6 = DAT_2000138f;
      DAT_200002c7 = DAT_20001390;
      break;
    default:
      break;
    case 7:
      DAT_20000312 = (DAT_20001385 & 0x10) == 0x10;
      break;
    case 9:
      DAT_2000031e = (DAT_20001385 & 8) == 8;
    }
    DAT_20000314 = (DAT_20001385 & 4) == 4;
    DAT_200002cd = (DAT_20001385 & 0x80) == 0x80;
    DAT_20000408 = 1;
  }
  return;
}


/* ---------------------------------------------------------------------
 * thunk_FUN_0800f96e   (0x0800F6B6, 1 Bytes)
 * Body: 0x0800F6B6-0x0800F6B7
 * --------------------------------------------------------------------- */
void thunk_FUN_0800f96e(void)

{
  DAT_20000314 = (DAT_20001385 & 4) == 4;
  DAT_200002cd = (DAT_20001385 & 0x80) == 0x80;
  DAT_20000408 = 1;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800f720   (0x0800F720, 176 Bytes, 2 Teile)
 * Body: 0x0800F720-0x0800F793, 0x0800F96E-0x0800F9AB
 * --------------------------------------------------------------------- */
/* WARNING: Removing unreachable block (ram,0x0800f784) */

void FUN_0800f720(void)

{
  DAT_2000030d = 0;
  DAT_20000314 = (DAT_20001385 & 4) == 4;
  DAT_200002cd = (DAT_20001385 & 0x80) == 0x80;
  DAT_20000408 = 1;
  return;
}


/* ---------------------------------------------------------------------
 * thunk_FUN_0800f96e   (0x0800F792, 1 Bytes)
 * Body: 0x0800F792-0x0800F793
 * --------------------------------------------------------------------- */
void thunk_FUN_0800f96e(void)

{
  DAT_20000314 = (DAT_20001385 & 4) == 4;
  DAT_200002cd = (DAT_20001385 & 0x80) == 0x80;
  DAT_20000408 = 1;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800f96e   (0x0800F96E, 61 Bytes)
 * Body: 0x0800F96E-0x0800F9AB
 * --------------------------------------------------------------------- */
void FUN_0800f96e(void)

{
  DAT_20000314 = (DAT_20001385 & 4) == 4;
  DAT_200002cd = (DAT_20001385 & 0x80) == 0x80;
  DAT_20000408 = 1;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800f9ac   (0x0800F9AC, 25 Bytes)
 * XOR-Checksumme ueber N Bytes (Frame-Pruefsummen)
 * Body: 0x0800F9AC-0x0800F9C5
 * --------------------------------------------------------------------- */
byte FUN_0800f9ac(int param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = 0;
  for (uVar2 = 0; (int)uVar2 < param_2; uVar2 = uVar2 + 1 & 0xffff) {
    bVar1 = bVar1 ^ *(byte *)(param_1 + uVar2);
  }
  return bVar1;
}


/* ---------------------------------------------------------------------
 * FUN_0800f9c6   (0x0800F9C6, 33 Bytes)
 * Frame-Check: prueft uebergebene Checksumme gegen XOR
 * Body: 0x0800F9C6-0x0800F9E7
 * --------------------------------------------------------------------- */
bool FUN_0800f9c6(int param_1,int param_2,uint param_3)

{
  byte bVar1;
  
  bVar1 = FUN_0800f9ac(param_1,param_2);
  return param_3 == bVar1;
}


/* ---------------------------------------------------------------------
 * FUN_0800f9e8   (0x0800F9E8, 21 Bytes)
 * Body: 0x0800F9E8-0x0800F9FD
 * --------------------------------------------------------------------- */
bool FUN_0800f9e8(int param_1)

{
  return *(char *)(param_1 + 300) == *(char *)(param_1 + 0x12d);
}


/* ---------------------------------------------------------------------
 * FUN_0800f9fe   (0x0800F9FE, 63 Bytes)
 * Body: 0x0800F9FE-0x0800FA3D
 * --------------------------------------------------------------------- */
bool FUN_0800f9fe(int param_1,undefined4 *param_2)

{
  bool bVar1;
  uint uVar2;
  
  bVar1 = FUN_0800f9e8(param_1);
  if (!bVar1) {
    FUN_0801d2ec(param_2,(undefined4 *)(param_1 + (uint)*(byte *)(param_1 + 300) * 0x14),0x14);
    uVar2 = *(byte *)(param_1 + 300) + 1;
    *(char *)(param_1 + 300) = (char)uVar2 + (char)(uVar2 / 0xf) * -0xf;
  }
  return bVar1;
}


/* ---------------------------------------------------------------------
 * FUN_0800fa3e   (0x0800FA3E, 21 Bytes)
 * Body: 0x0800FA3E-0x0800FA53
 * --------------------------------------------------------------------- */
bool FUN_0800fa3e(int param_1)

{
  return *(char *)(param_1 + 0xd2) == *(char *)(param_1 + 0xd3);
}


/* ---------------------------------------------------------------------
 * FUN_0800fa54   (0x0800FA54, 63 Bytes)
 * Body: 0x0800FA54-0x0800FA93
 * --------------------------------------------------------------------- */
bool FUN_0800fa54(int param_1,undefined4 *param_2)

{
  bool bVar1;
  uint uVar2;
  
  bVar1 = FUN_0800fa3e(param_1);
  if (!bVar1) {
    FUN_0801d2ec(param_2,(undefined4 *)(param_1 + (uint)*(byte *)(param_1 + 0xd2) * 0xe),0xe);
    uVar2 = *(byte *)(param_1 + 0xd2) + 1;
    *(char *)(param_1 + 0xd2) = (char)uVar2 + (char)(uVar2 / 0xf) * -0xf;
  }
  return bVar1;
}


/* ---------------------------------------------------------------------
 * FUN_0800fa94   (0x0800FA94, 794 Bytes, 2 Teile)
 * RX-Consumer (100ms): ESC- und Display-Queues, Timeouts (600ms/5000ms)
 * Body: 0x0800FA94-0x0800FB79, 0x0800FBF0-0x0800FE25
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0800fa94(void)

{
  bool bVar1;
  uint uVar2;
  char local_38;
  undefined1 local_37 [4];
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
  byte local_25;
  char local_24;
  undefined1 local_23;
  char local_22;
  undefined1 local_21;
  undefined1 local_20;
  undefined1 local_1f;
  undefined1 local_1e;
  undefined1 local_1d;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  undefined1 local_19;
  byte local_17;
  
  bVar1 = FUN_0800fa54(0x20000e2c,(undefined4 *)&local_24);
  if (bVar1) {
    if (_DAT_2000040e < 5000) {
      _DAT_2000040e = _DAT_2000040e + 1;
    }
    else {
      _DAT_2000040e = 5000;
    }
    if (_DAT_20000410 < 5000) {
      _DAT_20000410 = _DAT_20000410 + 1;
    }
    else {
      _DAT_20000410 = 5000;
    }
  }
  else if (local_24 == 'q') {
    bVar1 = FUN_0800f9c6((int)&local_24,0xc,(uint)local_17);
    if (bVar1) {
      DAT_200013a6 = local_24;
      DAT_200013a7 = local_23;
      DAT_200013a8 = local_22;
      DAT_200013a9 = local_21;
      DAT_200013aa = local_20;
      DAT_200013ab = local_1f;
      DAT_200013ac = local_1e;
      DAT_200013ad = local_1d;
      DAT_200013ae = local_1c;
      DAT_200013af = local_1b;
      DAT_200013b0 = local_1a;
      DAT_200013b1 = local_19;
      DAT_200013b2 = local_17;
      if (local_22 == ':') {
        DAT_20000311 = 0;
        _DAT_2000040e = 0;
      }
      else if (local_22 == ';') {
        DAT_20000310 = 0;
        _DAT_20000410 = 0;
      }
    }
    else {
      if (_DAT_2000040e < 5000) {
        _DAT_2000040e = _DAT_2000040e + 1;
      }
      else {
        _DAT_2000040e = 5000;
      }
      if (_DAT_20000410 < 5000) {
        _DAT_20000410 = _DAT_20000410 + 1;
      }
      else {
        _DAT_20000410 = 5000;
      }
    }
  }
  else {
    if (_DAT_2000040e < 5000) {
      _DAT_2000040e = _DAT_2000040e + 1;
    }
    else {
      _DAT_2000040e = 5000;
    }
    if (_DAT_20000410 < 5000) {
      _DAT_20000410 = _DAT_20000410 + 1;
    }
    else {
      _DAT_20000410 = 5000;
    }
  }
  if (600 < _DAT_2000040e) {
    DAT_20000311 = 1;
  }
  if (600 < _DAT_20000410) {
    DAT_20000310 = 1;
  }
  bVar1 = FUN_0800f9fe(0x20000f01,(undefined4 *)&local_38);
  if (bVar1) {
    if (_DAT_2000040c < 5000) {
      _DAT_2000040c = _DAT_2000040c + 1;
    }
    else {
      _DAT_2000040c = 5000;
    }
  }
  else {
    bVar1 = FUN_0800f9c6((int)&local_38,0x12,(uint)local_25);
    if ((bVar1) && (local_38 == 'L')) {
      DAT_2000030e = 0;
      _DAT_2000040c = 0;
      DAT_2000137f = local_38;
      DAT_20001380 = local_37[0];
      DAT_20001381 = local_37[1];
      DAT_20001382 = local_37[2];
      DAT_20001383 = local_37[3];
      DAT_20001384 = local_33;
      DAT_20001385 = local_32;
      DAT_20001386 = local_31;
      DAT_20001387 = local_30;
      DAT_20001388 = local_2f;
      DAT_20001389 = local_2e;
      DAT_2000138a = local_2d;
      DAT_2000138b = local_2c;
      DAT_2000138c = local_2b;
      DAT_2000138d = local_2a;
      DAT_2000138e = local_29;
      DAT_2000138f = local_28;
      DAT_20001390 = local_27;
      DAT_20001391 = local_25;
    }
    else if (local_38 == -0x76) {
      DAT_200013b3 = local_38;
      for (uVar2 = 0; uVar2 < 0xb; uVar2 = uVar2 + 1 & 0xff) {
        *(undefined1 *)(uVar2 + 0x200013b4) = local_37[uVar2];
      }
      DAT_2000040a = 1;
    }
    else if (local_38 == -0x75) {
      DAT_200013b3 = local_38;
      for (uVar2 = 0; uVar2 < 8; uVar2 = uVar2 + 1 & 0xff) {
        *(undefined1 *)(uVar2 + 0x200013b4) = local_37[uVar2];
      }
      DAT_2000040a = 1;
    }
    else if (local_38 == -0x74) {
      DAT_200013b3 = local_38;
      for (uVar2 = 0; uVar2 < 8; uVar2 = uVar2 + 1 & 0xff) {
        *(undefined1 *)(uVar2 + 0x200013b4) = local_37[uVar2];
      }
      DAT_2000040a = 1;
    }
    else if (_DAT_2000040c < 5000) {
      _DAT_2000040c = _DAT_2000040c + 1;
    }
    else {
      _DAT_2000040c = 5000;
    }
  }
  if (600 < _DAT_2000040c) {
    DAT_2000030e = 1;
  }
  return 0;
}


/* ---------------------------------------------------------------------
 * thunk_FUN_0800fbfa   (0x0800FB78, 1 Bytes)
 * Body: 0x0800FB78-0x0800FB79
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thunk_FUN_0800fbfa(void)

{
  bool bVar1;
  uint uVar2;
  char in_stack_00000000;
  undefined1 in_stack_00000001;
  undefined1 in_stack_00000002;
  undefined1 in_stack_00000003;
  undefined1 in_stack_00000004;
  undefined1 in_stack_00000005;
  undefined1 in_stack_00000006;
  undefined1 in_stack_00000007;
  undefined1 in_stack_00000008;
  undefined1 in_stack_00000009;
  undefined1 in_stack_0000000a;
  undefined1 in_stack_0000000b;
  undefined1 in_stack_0000000c;
  undefined1 in_stack_0000000d;
  undefined1 in_stack_0000000e;
  undefined1 in_stack_0000000f;
  undefined1 in_stack_00000010;
  undefined1 in_stack_00000011;
  byte in_stack_00000013;
  
  if (_DAT_2000040e < 5000) {
    _DAT_2000040e = _DAT_2000040e + 1;
  }
  else {
    _DAT_2000040e = 5000;
  }
  if (_DAT_20000410 < 5000) {
    _DAT_20000410 = _DAT_20000410 + 1;
  }
  else {
    _DAT_20000410 = 5000;
  }
  if (600 < _DAT_2000040e) {
    DAT_20000311 = 1;
  }
  if (600 < _DAT_20000410) {
    DAT_20000310 = 1;
  }
  bVar1 = FUN_0800f9fe(0x20000f01,(undefined4 *)&stack0x00000000);
  if (bVar1) {
    if (_DAT_2000040c < 5000) {
      _DAT_2000040c = _DAT_2000040c + 1;
    }
    else {
      _DAT_2000040c = 5000;
    }
  }
  else {
    bVar1 = FUN_0800f9c6((int)&stack0x00000000,0x12,(uint)in_stack_00000013);
    if ((bVar1) && (in_stack_00000000 == 'L')) {
      DAT_2000030e = 0;
      _DAT_2000040c = 0;
      DAT_2000137f = in_stack_00000000;
      DAT_20001380 = in_stack_00000001;
      DAT_20001381 = in_stack_00000002;
      DAT_20001382 = in_stack_00000003;
      DAT_20001383 = in_stack_00000004;
      DAT_20001384 = in_stack_00000005;
      DAT_20001385 = in_stack_00000006;
      DAT_20001386 = in_stack_00000007;
      DAT_20001387 = in_stack_00000008;
      DAT_20001388 = in_stack_00000009;
      DAT_20001389 = in_stack_0000000a;
      DAT_2000138a = in_stack_0000000b;
      DAT_2000138b = in_stack_0000000c;
      DAT_2000138c = in_stack_0000000d;
      DAT_2000138d = in_stack_0000000e;
      DAT_2000138e = in_stack_0000000f;
      DAT_2000138f = in_stack_00000010;
      DAT_20001390 = in_stack_00000011;
      DAT_20001391 = in_stack_00000013;
    }
    else if (in_stack_00000000 == -0x76) {
      DAT_200013b3 = in_stack_00000000;
      for (uVar2 = 0; uVar2 < 0xb; uVar2 = uVar2 + 1 & 0xff) {
        *(undefined1 *)(uVar2 + 0x200013b4) = (&stack0x00000001)[uVar2];
      }
      DAT_2000040a = 1;
    }
    else if (in_stack_00000000 == -0x75) {
      DAT_200013b3 = in_stack_00000000;
      for (uVar2 = 0; uVar2 < 8; uVar2 = uVar2 + 1 & 0xff) {
        *(undefined1 *)(uVar2 + 0x200013b4) = (&stack0x00000001)[uVar2];
      }
      DAT_2000040a = 1;
    }
    else if (in_stack_00000000 == -0x74) {
      DAT_200013b3 = in_stack_00000000;
      for (uVar2 = 0; uVar2 < 8; uVar2 = uVar2 + 1 & 0xff) {
        *(undefined1 *)(uVar2 + 0x200013b4) = (&stack0x00000001)[uVar2];
      }
      DAT_2000040a = 1;
    }
    else if (_DAT_2000040c < 5000) {
      _DAT_2000040c = _DAT_2000040c + 1;
    }
    else {
      _DAT_2000040c = 5000;
    }
  }
  if (600 < _DAT_2000040c) {
    DAT_2000030e = 1;
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800fbfa   (0x0800FBFA, 490 Bytes, 2 Teile)
 * Body: 0x0800FBFA-0x0800FC3B, 0x0800FC7C-0x0800FE25
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0800fbfa(void)

{
  bool bVar1;
  uint uVar2;
  char in_stack_00000000;
  undefined1 in_stack_00000001;
  undefined1 in_stack_00000002;
  undefined1 in_stack_00000003;
  undefined1 in_stack_00000004;
  undefined1 in_stack_00000005;
  undefined1 in_stack_00000006;
  undefined1 in_stack_00000007;
  undefined1 in_stack_00000008;
  undefined1 in_stack_00000009;
  undefined1 in_stack_0000000a;
  undefined1 in_stack_0000000b;
  undefined1 in_stack_0000000c;
  undefined1 in_stack_0000000d;
  undefined1 in_stack_0000000e;
  undefined1 in_stack_0000000f;
  undefined1 in_stack_00000010;
  undefined1 in_stack_00000011;
  byte in_stack_00000013;
  
  if (_DAT_2000040e < 5000) {
    _DAT_2000040e = _DAT_2000040e + 1;
  }
  else {
    _DAT_2000040e = 5000;
  }
  if (_DAT_20000410 < 5000) {
    _DAT_20000410 = _DAT_20000410 + 1;
  }
  else {
    _DAT_20000410 = 5000;
  }
  if (600 < _DAT_2000040e) {
    DAT_20000311 = 1;
  }
  if (600 < _DAT_20000410) {
    DAT_20000310 = 1;
  }
  bVar1 = FUN_0800f9fe(0x20000f01,(undefined4 *)&stack0x00000000);
  if (bVar1) {
    if (_DAT_2000040c < 5000) {
      _DAT_2000040c = _DAT_2000040c + 1;
    }
    else {
      _DAT_2000040c = 5000;
    }
  }
  else {
    bVar1 = FUN_0800f9c6((int)&stack0x00000000,0x12,(uint)in_stack_00000013);
    if ((bVar1) && (in_stack_00000000 == 'L')) {
      DAT_2000030e = 0;
      _DAT_2000040c = 0;
      DAT_2000137f = in_stack_00000000;
      DAT_20001380 = in_stack_00000001;
      DAT_20001381 = in_stack_00000002;
      DAT_20001382 = in_stack_00000003;
      DAT_20001383 = in_stack_00000004;
      DAT_20001384 = in_stack_00000005;
      DAT_20001385 = in_stack_00000006;
      DAT_20001386 = in_stack_00000007;
      DAT_20001387 = in_stack_00000008;
      DAT_20001388 = in_stack_00000009;
      DAT_20001389 = in_stack_0000000a;
      DAT_2000138a = in_stack_0000000b;
      DAT_2000138b = in_stack_0000000c;
      DAT_2000138c = in_stack_0000000d;
      DAT_2000138d = in_stack_0000000e;
      DAT_2000138e = in_stack_0000000f;
      DAT_2000138f = in_stack_00000010;
      DAT_20001390 = in_stack_00000011;
      DAT_20001391 = in_stack_00000013;
    }
    else if (in_stack_00000000 == -0x76) {
      DAT_200013b3 = in_stack_00000000;
      for (uVar2 = 0; uVar2 < 0xb; uVar2 = uVar2 + 1 & 0xff) {
        *(undefined1 *)(uVar2 + 0x200013b4) = (&stack0x00000001)[uVar2];
      }
      DAT_2000040a = 1;
    }
    else if (in_stack_00000000 == -0x75) {
      DAT_200013b3 = in_stack_00000000;
      for (uVar2 = 0; uVar2 < 8; uVar2 = uVar2 + 1 & 0xff) {
        *(undefined1 *)(uVar2 + 0x200013b4) = (&stack0x00000001)[uVar2];
      }
      DAT_2000040a = 1;
    }
    else if (in_stack_00000000 == -0x74) {
      DAT_200013b3 = in_stack_00000000;
      for (uVar2 = 0; uVar2 < 8; uVar2 = uVar2 + 1 & 0xff) {
        *(undefined1 *)(uVar2 + 0x200013b4) = (&stack0x00000001)[uVar2];
      }
      DAT_2000040a = 1;
    }
    else if (_DAT_2000040c < 5000) {
      _DAT_2000040c = _DAT_2000040c + 1;
    }
    else {
      _DAT_2000040c = 5000;
    }
  }
  if (600 < _DAT_2000040c) {
    DAT_2000030e = 1;
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800fe26   (0x0800FE26, 19 Bytes)
 * 100ms-Kette: RX-Consumer -> Kommandos -> State -> Frame-Builder
 * Body: 0x0800FE26-0x0800FE39
 * --------------------------------------------------------------------- */
void FUN_0800fe26(void)

{
  FUN_0800fa94();
  FUN_0800f4fa();
  FUN_0800ef96();
  FUN_0800ee76();
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800fe3a   (0x0800FE3A, 91 Bytes)
 * TX-Pump: sendet Display-Puffer 0x2000128E (USART3) und ESC-Puffer 0x200010FA (USART2)
 * Body: 0x0800FE3A-0x0800FE95
 * --------------------------------------------------------------------- */
void FUN_0800fe3a(void)

{
  bool bVar1;
  bool bVar2;
  
  bVar1 = DAT_20001356 != 0;
  if (bVar1) {
    FUN_08019b5e((byte *)0x2000128e,(uint)DAT_20001356);
    DAT_20001356 = 0;
  }
  bVar2 = DAT_200011c2 != 0;
  DAT_20001357 = bVar1;
  if (bVar2) {
    FUN_08019b4c((byte *)0x200010fa,(uint)DAT_200011c2);
    DAT_200011c2 = 0;
  }
  DAT_200011c3 = bVar2;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0800fe96   (0x0800FE96, 390 Bytes, 2 Teile)
 * ESC-Builder '4A 11 3B' (17B, XOR) - Motor-Kommandoframe
 * Body: 0x0800FE96-0x0800FFEF, 0x0801007C-0x080100A9
 * --------------------------------------------------------------------- */
void FUN_0800fe96(void)

{
  byte bVar1;
  uint uVar2;
  
  if (DAT_20000309 == '\0') {
    uVar2 = (uint)DAT_200002a1;
  }
  else {
    uVar2 = 0;
  }
  DAT_2000139b = (&DAT_200002ad)[uVar2];
  DAT_2000139c = (&DAT_200002b3)[uVar2];
  DAT_2000139e = (&DAT_200002c0)[uVar2];
  if ((0x6b < DAT_2000036d) && (0xf < DAT_2000139e)) {
    DAT_2000139e = 0xf;
  }
  bVar1 = DAT_200002a2;
  if ((DAT_2000030a & 2) == 2) {
    DAT_2000030a = DAT_2000030a & 0xfd;
    bVar1 = DAT_200002a2 | 1;
    DAT_200002a2 = DAT_200002a2 & 0xfe;
  }
  if (DAT_20000313 == '\x02') {
    DAT_2000139b = DAT_2000139b & DAT_200002c8 - 0x10U;
    bVar1 = bVar1 | 0x80;
    DAT_2000139d = DAT_200002ca;
  }
  else {
    DAT_2000139d = DAT_200002b9;
    if (DAT_20000313 == '\x03') {
      bVar1 = bVar1 | 0x80;
    }
    else if (DAT_20000313 == '\x01') {
      bVar1 = bVar1 & 0x7f;
    }
  }
  if (4 < uVar2) {
    bVar1 = bVar1 | 0x80;
  }
  DAT_20001396 = DAT_200002a1;
  if (DAT_20000309 != '\0') {
    DAT_20001396 = 0;
  }
  if (DAT_2000030d == '\0') {
    DAT_20001397 = bVar1 & 0xdf;
  }
  else {
    DAT_20001397 = bVar1 | 0x20;
  }
  if (DAT_20000390 == '\x01') {
    DAT_2000139d = 0;
    DAT_2000139e = 0;
    DAT_20001397 = DAT_20001397 & 0x7f;
  }
  if (DAT_2000039a != '\0') {
    DAT_2000139d = 0;
    DAT_2000139e = 0;
    DAT_20001397 = DAT_20001397 & 0x7f;
  }
  if (DAT_200002cd == '\0') {
    DAT_200013a1 = 0;
  }
  else {
    DAT_200013a1 = 0x80;
  }
  if (DAT_20000314 != '\0') {
    DAT_200013a1 = DAT_200013a1 | 0x20;
  }
  DAT_20001392 = 0x4a;
  DAT_20001393 = 0x11;
  DAT_20001394 = 0x3b;
  DAT_20001395 = 0;
  DAT_20001398 = DAT_200002a4;
  DAT_20001399 = DAT_200002a5;
  DAT_2000139a = DAT_200002a6;
  DAT_2000139f = DAT_200002c6;
  DAT_200013a0 = DAT_200002c7;
  DAT_200013a5 = FUN_0800f9ac(0x20001392,0x13);
  FUN_0800b990((undefined1 *)0x200010fa,&DAT_20001392,0x10);
  DAT_2000110a = DAT_200013a5;
  DAT_200011c2 = 0x11;
  return;
}


/* ---------------------------------------------------------------------
 * thunk_FUN_0801007c   (0x0800FFEE, 1 Bytes)
 * Body: 0x0800FFEE-0x0800FFEF
 * --------------------------------------------------------------------- */
void thunk_FUN_0801007c(int param_1)

{
  undefined1 unaff_r6;
  
  *(undefined1 *)(param_1 + 0xf) = unaff_r6;
  DAT_200013a5 = FUN_0800f9ac(param_1,0x13);
  FUN_0800b990((undefined1 *)0x200010fa,&DAT_20001392,0x10);
  DAT_2000110a = DAT_200013a5;
  DAT_200011c2 = 0x11;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801007c   (0x0801007C, 45 Bytes)
 * Body: 0x0801007C-0x080100A9
 * --------------------------------------------------------------------- */
void FUN_0801007c(int param_1)

{
  undefined1 unaff_r6;
  
  *(undefined1 *)(param_1 + 0xf) = unaff_r6;
  DAT_200013a5 = FUN_0800f9ac(param_1,0x13);
  FUN_0800b990((undefined1 *)0x200010fa,&DAT_20001392,0x10);
  DAT_2000110a = DAT_200013a5;
  DAT_200011c2 = 0x11;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_080100aa   (0x080100AA, 397 Bytes)
 * ESC-Builder '4A 14 3B' (20B, XOR)
 * Body: 0x080100AA-0x08010237
 * --------------------------------------------------------------------- */
void FUN_080100aa(void)

{
  byte bVar1;
  uint uVar2;
  
  if (DAT_20000309 == '\0') {
    uVar2 = (uint)DAT_200002a1;
  }
  else {
    uVar2 = 0;
  }
  DAT_2000139b = (&DAT_200002ad)[uVar2];
  DAT_2000139c = (&DAT_200002b3)[uVar2];
  DAT_2000139e = (&DAT_200002c0)[uVar2];
  if ((0x6b < DAT_2000036d) && (0xf < DAT_2000139e)) {
    DAT_2000139e = 0xf;
  }
  bVar1 = DAT_200002a2;
  if ((DAT_2000030a & 2) == 2) {
    DAT_2000030a = DAT_2000030a & 0xfd;
    bVar1 = DAT_200002a2 | 1;
    DAT_200002a2 = DAT_200002a2 & 0xfe;
  }
  if (DAT_20000313 == '\x02') {
    DAT_2000139b = DAT_2000139b & DAT_200002c8 - 0x10U;
    bVar1 = bVar1 | 0x80;
    DAT_2000139d = DAT_200002ca;
  }
  else {
    DAT_2000139d = DAT_200002b9;
    if (DAT_20000313 == '\x03') {
      bVar1 = bVar1 | 0x80;
    }
    else if (DAT_20000313 == '\x01') {
      bVar1 = bVar1 & 0x7f;
    }
  }
  if (4 < uVar2) {
    bVar1 = bVar1 | 0x80;
  }
  DAT_20001396 = DAT_200002a1;
  if (DAT_20000309 != '\0') {
    DAT_20001396 = 0;
  }
  if (DAT_2000030d == '\0') {
    DAT_20001397 = bVar1 & 0xdf;
  }
  else {
    DAT_20001397 = bVar1 | 0x20;
  }
  if (DAT_20000390 == '\x01') {
    DAT_2000139d = 0;
    DAT_2000139e = 0;
    DAT_20001397 = DAT_20001397 & 0x7f;
  }
  if (DAT_2000039a != '\0') {
    DAT_2000139d = 0;
    DAT_2000139e = 0;
    DAT_20001397 = DAT_20001397 & 0x7f;
  }
  if (DAT_200002cd == '\0') {
    DAT_200013a1 = 0;
  }
  else {
    DAT_200013a1 = 0x80;
  }
  if (DAT_20000314 != '\0') {
    DAT_200013a1 = DAT_200013a1 | 0x20;
  }
  DAT_20001392 = 0x4a;
  DAT_20001393 = 0x14;
  DAT_20001394 = 0x3b;
  DAT_20001395 = 0;
  DAT_20001398 = DAT_200002a4;
  DAT_20001399 = DAT_200002a5;
  DAT_2000139a = DAT_200002a6;
  DAT_2000139f = DAT_200002c6;
  DAT_200013a0 = DAT_200002c7;
  DAT_200013a2 = DAT_200002ce;
  DAT_200013a3 = DAT_200002cf;
  DAT_200013a4 = DAT_200002d0;
  DAT_200013a5 = FUN_0800f9ac(0x20001392,0x13);
  FUN_0800b990((undefined1 *)0x200010fa,&DAT_20001392,0x14);
  DAT_200011c2 = 0x14;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08010238   (0x08010238, 369 Bytes, 2 Teile)
 * ESC-Builder '4A 11 3A' (17B, XOR)
 * Body: 0x08010238-0x080103A9, 0x080103AB-0x080103AB
 * --------------------------------------------------------------------- */
void FUN_08010238(void)

{
  byte bVar1;
  uint uVar2;
  
  if (DAT_20000309 == '\0') {
    uVar2 = (uint)DAT_200002a1;
  }
  else {
    uVar2 = 0;
  }
  DAT_2000139b = (&DAT_200002a7)[uVar2];
  DAT_2000139c = (&DAT_200002b3)[uVar2];
  DAT_2000139e = (&DAT_200002ba)[uVar2];
  bVar1 = DAT_200002a3;
  if ((DAT_2000030a & 1) != 0) {
    DAT_2000030a = DAT_2000030a & 0xfe;
    bVar1 = DAT_200002a3 | 1;
    DAT_200002a3 = DAT_200002a3 & 0xfe;
  }
  if (((DAT_200002a3 & 0x80) == 0) && ((DAT_200002e7 & 8) == 0)) {
    bVar1 = bVar1 | 0x80;
  }
  if (DAT_20000313 == '\x02') {
    bVar1 = bVar1 | 0x80;
    DAT_2000139d = DAT_200002ca;
  }
  else {
    DAT_2000139d = DAT_200002b9;
    if (DAT_20000313 == '\x01') {
      bVar1 = bVar1 | 0x80;
    }
  }
  if (4 < uVar2) {
    bVar1 = bVar1 | 0x80;
  }
  if ((0x6b < DAT_2000036d) && (0xf < DAT_2000139e)) {
    DAT_2000139e = 0xf;
  }
  if (DAT_2000030d == '\0') {
    DAT_20001397 = bVar1 & 0xdf;
  }
  else {
    DAT_20001397 = bVar1 | 0x20;
  }
  if (DAT_20000390 == '\x01') {
    DAT_2000139d = 0;
    DAT_2000139e = 0;
    DAT_20001397 = DAT_20001397 & 0x7f;
  }
  if (DAT_2000039a != '\0') {
    DAT_2000139d = 0;
    DAT_2000139e = 0;
    DAT_20001397 = DAT_20001397 & 0x7f;
  }
  if (DAT_200002cd == '\0') {
    DAT_200013a1 = 0;
  }
  else {
    DAT_200013a1 = 0x80;
  }
  if (DAT_20000314 != '\0') {
    DAT_200013a1 = DAT_200013a1 | 0x20;
  }
  DAT_20001392 = 0x4a;
  DAT_20001393 = 0x11;
  DAT_20001394 = 0x3a;
  DAT_20001395 = 0;
  DAT_20001396 = (undefined1)uVar2;
  DAT_20001398 = DAT_200002a4;
  DAT_20001399 = DAT_200002a5;
  DAT_2000139a = DAT_200002a6;
  DAT_2000139f = DAT_200002c6;
  DAT_200013a0 = DAT_200002c7;
  DAT_200013a5 = FUN_0800f9ac(0x20001392,0x13);
  FUN_0800b990((undefined1 *)0x200010fa,&DAT_20001392,0x10);
  DAT_2000110a = DAT_200013a5;
  DAT_200011c2 = 0x11;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_080103aa   (0x080103AA, 1 Bytes)
 * ESC-Builder '4A 14 3A' (20B, XOR; erweitert)
 * Body: 0x080103AA-0x080103AB
 * --------------------------------------------------------------------- */
void FUN_080103aa(undefined2 param_1)

{
  byte bVar1;
  uint uVar2;
  int unaff_r6;
  
  *(undefined2 *)(unaff_r6 + 0x3e) = param_1;
  if (DAT_20000309 == '\0') {
    uVar2 = (uint)DAT_200002a1;
  }
  else {
    uVar2 = 0;
  }
  DAT_2000139b = (&DAT_200002a7)[uVar2];
  DAT_2000139c = (&DAT_200002b3)[uVar2];
  DAT_2000139e = (&DAT_200002ba)[uVar2];
  bVar1 = DAT_200002a3;
  if ((DAT_2000030a & 1) != 0) {
    DAT_2000030a = DAT_2000030a & 0xfe;
    bVar1 = DAT_200002a3 | 1;
    DAT_200002a3 = DAT_200002a3 & 0xfe;
  }
  if (((DAT_200002a3 & 0x80) == 0) && ((DAT_200002e7 & 8) == 0)) {
    bVar1 = bVar1 | 0x80;
  }
  if (DAT_20000313 == '\x02') {
    bVar1 = bVar1 | 0x80;
    DAT_2000139d = DAT_200002ca;
  }
  else {
    DAT_2000139d = DAT_200002b9;
    if (DAT_20000313 == '\x01') {
      bVar1 = bVar1 | 0x80;
    }
  }
  if (4 < uVar2) {
    bVar1 = bVar1 | 0x80;
  }
  if ((0x6b < DAT_2000036d) && (0xf < DAT_2000139e)) {
    DAT_2000139e = 0xf;
  }
  if (DAT_2000030d == '\0') {
    DAT_20001397 = bVar1 & 0xdf;
  }
  else {
    DAT_20001397 = bVar1 | 0x20;
  }
  if (DAT_20000390 == '\x01') {
    DAT_2000139d = 0;
    DAT_2000139e = 0;
    DAT_20001397 = DAT_20001397 & 0x7f;
  }
  if (DAT_2000039a != '\0') {
    DAT_2000139d = 0;
    DAT_2000139e = 0;
    DAT_20001397 = DAT_20001397 & 0x7f;
  }
  if (DAT_200002cd == '\0') {
    DAT_200013a1 = 0;
  }
  else {
    DAT_200013a1 = 0x80;
  }
  if (DAT_20000314 != '\0') {
    DAT_200013a1 = DAT_200013a1 | 0x20;
  }
  DAT_20001392 = 0x4a;
  DAT_20001393 = 0x14;
  DAT_20001394 = 0x3a;
  DAT_20001395 = 0;
  DAT_20001396 = (undefined1)uVar2;
  DAT_20001398 = DAT_200002a4;
  DAT_20001399 = DAT_200002a5;
  DAT_2000139a = DAT_200002a6;
  DAT_2000139f = DAT_200002c6;
  DAT_200013a0 = DAT_200002c7;
  DAT_200013a2 = DAT_200002ce;
  DAT_200013a3 = DAT_200002cf;
  DAT_200013a4 = DAT_200002d0;
  DAT_200013a5 = FUN_0800f9ac(0x20001392,0x13);
  FUN_0800b990((undefined1 *)0x200010fa,&DAT_20001392,0x14);
  DAT_200011c2 = 0x14;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_080103ac   (0x080103AC, 382 Bytes, 2 Teile)
 * ESC-Builder '4A 14 3A' (20B, XOR)
 * Body: 0x080103AC-0x08010463, 0x080104E0-0x080105A7
 * --------------------------------------------------------------------- */
void FUN_080103ac(void)

{
  byte bVar1;
  uint uVar2;
  
  if (DAT_20000309 == '\0') {
    uVar2 = (uint)DAT_200002a1;
  }
  else {
    uVar2 = 0;
  }
  DAT_2000139b = (&DAT_200002a7)[uVar2];
  DAT_2000139c = (&DAT_200002b3)[uVar2];
  DAT_2000139e = (&DAT_200002ba)[uVar2];
  bVar1 = DAT_200002a3;
  if ((DAT_2000030a & 1) != 0) {
    DAT_2000030a = DAT_2000030a & 0xfe;
    bVar1 = DAT_200002a3 | 1;
    DAT_200002a3 = DAT_200002a3 & 0xfe;
  }
  if (((DAT_200002a3 & 0x80) == 0) && ((DAT_200002e7 & 8) == 0)) {
    bVar1 = bVar1 | 0x80;
  }
  if (DAT_20000313 == '\x02') {
    bVar1 = bVar1 | 0x80;
    DAT_2000139d = DAT_200002ca;
  }
  else {
    DAT_2000139d = DAT_200002b9;
    if (DAT_20000313 == '\x01') {
      bVar1 = bVar1 | 0x80;
    }
  }
  if (4 < uVar2) {
    bVar1 = bVar1 | 0x80;
  }
  if ((0x6b < DAT_2000036d) && (0xf < DAT_2000139e)) {
    DAT_2000139e = 0xf;
  }
  if (DAT_2000030d == '\0') {
    DAT_20001397 = bVar1 & 0xdf;
  }
  else {
    DAT_20001397 = bVar1 | 0x20;
  }
  if (DAT_20000390 == '\x01') {
    DAT_2000139d = 0;
    DAT_2000139e = 0;
    DAT_20001397 = DAT_20001397 & 0x7f;
  }
  if (DAT_2000039a != '\0') {
    DAT_2000139d = 0;
    DAT_2000139e = 0;
    DAT_20001397 = DAT_20001397 & 0x7f;
  }
  if (DAT_200002cd == '\0') {
    DAT_200013a1 = 0;
  }
  else {
    DAT_200013a1 = 0x80;
  }
  if (DAT_20000314 != '\0') {
    DAT_200013a1 = DAT_200013a1 | 0x20;
  }
  DAT_20001392 = 0x4a;
  DAT_20001393 = 0x14;
  DAT_20001394 = 0x3a;
  DAT_20001395 = 0;
  DAT_20001396 = (undefined1)uVar2;
  DAT_20001398 = DAT_200002a4;
  DAT_20001399 = DAT_200002a5;
  DAT_2000139a = DAT_200002a6;
  DAT_2000139f = DAT_200002c6;
  DAT_200013a0 = DAT_200002c7;
  DAT_200013a2 = DAT_200002ce;
  DAT_200013a3 = DAT_200002cf;
  DAT_200013a4 = DAT_200002d0;
  DAT_200013a5 = FUN_0800f9ac(0x20001392,0x13);
  FUN_0800b990((undefined1 *)0x200010fa,&DAT_20001392,0x14);
  DAT_200011c2 = 0x14;
  return;
}


/* ---------------------------------------------------------------------
 * thunk_FUN_080104e0   (0x08010462, 1 Bytes)
 * Body: 0x08010462-0x08010463
 * --------------------------------------------------------------------- */
void thunk_FUN_080104e0(void)

{
  byte unaff_r4;
  undefined1 unaff_r5;
  byte unaff_r6;
  byte bVar1;
  undefined1 unaff_r7;
  undefined1 unaff_r8;
  undefined1 unaff_r9;
  undefined1 unaff_r10;
  
  DAT_20001397 = unaff_r4 & 0xdf;
  if (DAT_20000390 == '\x01') {
    unaff_r8 = 0;
    unaff_r7 = 0;
    DAT_20001397 = unaff_r4 & 0x5f;
  }
  if (DAT_2000039a != '\0') {
    unaff_r8 = 0;
    unaff_r7 = 0;
    DAT_20001397 = DAT_20001397 & 0x7f;
  }
  if (DAT_200002cd == '\0') {
    bVar1 = unaff_r6 & 0x7f;
  }
  else {
    bVar1 = unaff_r6 | 0x80;
  }
  if (DAT_20000314 == '\0') {
    bVar1 = bVar1 & 0xdf;
  }
  else {
    bVar1 = bVar1 | 0x20;
  }
  DAT_200013a1 = bVar1 & 0xf7;
  DAT_20001392 = 0x4a;
  DAT_20001393 = 0x14;
  DAT_20001394 = 0x3a;
  DAT_20001395 = 0;
  DAT_20001398 = DAT_200002a4;
  DAT_20001399 = DAT_200002a5;
  DAT_2000139a = DAT_200002a6;
  DAT_2000139f = DAT_200002c6;
  DAT_200013a0 = DAT_200002c7;
  DAT_200013a2 = DAT_200002ce;
  DAT_200013a3 = DAT_200002cf;
  DAT_200013a4 = DAT_200002d0;
  DAT_20001396 = unaff_r5;
  DAT_2000139b = unaff_r9;
  DAT_2000139c = unaff_r10;
  DAT_2000139d = unaff_r8;
  DAT_2000139e = unaff_r7;
  DAT_200013a5 = FUN_0800f9ac(0x20001392,0x13);
  FUN_0800b990((undefined1 *)0x200010fa,&DAT_20001392,0x14);
  DAT_200011c2 = 0x14;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_080104e0   (0x080104E0, 199 Bytes)
 * Body: 0x080104E0-0x080105A7
 * --------------------------------------------------------------------- */
void FUN_080104e0(void)

{
  byte unaff_r4;
  undefined1 unaff_r5;
  byte unaff_r6;
  byte bVar1;
  undefined1 unaff_r7;
  undefined1 unaff_r8;
  undefined1 unaff_r9;
  undefined1 unaff_r10;
  
  DAT_20001397 = unaff_r4 & 0xdf;
  if (DAT_20000390 == '\x01') {
    unaff_r8 = 0;
    unaff_r7 = 0;
    DAT_20001397 = unaff_r4 & 0x5f;
  }
  if (DAT_2000039a != '\0') {
    unaff_r8 = 0;
    unaff_r7 = 0;
    DAT_20001397 = DAT_20001397 & 0x7f;
  }
  if (DAT_200002cd == '\0') {
    bVar1 = unaff_r6 & 0x7f;
  }
  else {
    bVar1 = unaff_r6 | 0x80;
  }
  if (DAT_20000314 == '\0') {
    bVar1 = bVar1 & 0xdf;
  }
  else {
    bVar1 = bVar1 | 0x20;
  }
  DAT_200013a1 = bVar1 & 0xf7;
  DAT_20001392 = 0x4a;
  DAT_20001393 = 0x14;
  DAT_20001394 = 0x3a;
  DAT_20001395 = 0;
  DAT_20001398 = DAT_200002a4;
  DAT_20001399 = DAT_200002a5;
  DAT_2000139a = DAT_200002a6;
  DAT_2000139f = DAT_200002c6;
  DAT_200013a0 = DAT_200002c7;
  DAT_200013a2 = DAT_200002ce;
  DAT_200013a3 = DAT_200002cf;
  DAT_200013a4 = DAT_200002d0;
  DAT_20001396 = unaff_r5;
  DAT_2000139b = unaff_r9;
  DAT_2000139c = unaff_r10;
  DAT_2000139d = unaff_r8;
  DAT_2000139e = unaff_r7;
  DAT_200013a5 = FUN_0800f9ac(0x20001392,0x13);
  FUN_0800b990((undefined1 *)0x200010fa,&DAT_20001392,0x14);
  DAT_200011c2 = 0x14;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_080105a8   (0x080105A8, 159 Bytes)
 * Motor-Scheduler: Round-Robin der ESC-Frames (3A/3B, Dual/Single 0x20000398)
 * Body: 0x080105A8-0x08010647
 * --------------------------------------------------------------------- */
void FUN_080105a8(void)

{
  if (DAT_20000423 == '\0') {
    if (DAT_20000398 == '\x01') {
      FUN_080103ac();
    }
    else if (DAT_20000398 == '\0') {
      FUN_08010238();
    }
    else if ((uint)DAT_20000424 == ((int)(uint)DAT_20000424 >> 1) * 2) {
      FUN_08010238();
    }
    else {
      FUN_080103ac();
    }
    DAT_20000423 = DAT_20000423 + '\x01';
  }
  else if (DAT_20000423 == '\x01') {
    if (DAT_20000398 == '\x01') {
      FUN_080100aa();
    }
    else if (DAT_20000398 == '\0') {
      FUN_0800fe96();
    }
    else {
      if ((uint)DAT_20000424 == ((int)(uint)DAT_20000424 >> 1) * 2) {
        FUN_0800fe96();
      }
      else {
        FUN_080100aa();
      }
      DAT_20000424 = DAT_20000424 + 1;
    }
    DAT_20000423 = '\0';
  }
  else {
    DAT_20000423 = '\0';
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08010648   (0x08010648, 401 Bytes)
 * Display-Builder '35 27 3B' (39B, XOR)
 * Body: 0x08010648-0x080107D9
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08010648(void)

{
  uint uVar1;
  
  if (DAT_20000309 == '\0') {
    uVar1 = (uint)DAT_200002a1;
  }
  else {
    uVar1 = 0;
  }
  DAT_20001358 = 0x35;
  DAT_20001359 = 0x27;
  DAT_2000135a = 0x3b;
  DAT_2000135b = DAT_200002e6;
  DAT_2000135c = DAT_200002e7;
  DAT_2000135d = (undefined1)((ushort)_DAT_200002e8 >> 8);
  DAT_2000135e = DAT_200002e8;
  DAT_2000135f = DAT_200002ea;
  DAT_20001360 = (undefined1)((ushort)_DAT_200002ec >> 8);
  DAT_20001361 = DAT_200002ec;
  DAT_20001362 = DAT_200002ee;
  DAT_20001363 = (undefined1)uVar1;
  DAT_20001364 = DAT_200002a2 & 0xfe;
  if (DAT_2000036d < 0x29) {
    DAT_20001365 = '\0';
  }
  else {
    DAT_20001365 = DAT_2000036d - 0x28;
  }
  DAT_20001366 = DAT_20000364;
  DAT_20001367 = DAT_2000035e;
  DAT_20001368 = DAT_2000035f;
  DAT_20001369 = (undefined1)((ushort)_DAT_200002f0 >> 8);
  DAT_2000136a = DAT_200002f0;
  DAT_2000136b = DAT_200002f2 & 0x5f;
  DAT_2000136c = (undefined1)((ushort)_DAT_200002f4 >> 8);
  DAT_2000136d = (undefined1)_DAT_200002f4;
  DAT_2000136e = (undefined1)((ushort)_DAT_200002f8 >> 8);
  DAT_2000136f = (undefined1)_DAT_200002f8;
  DAT_20001370 = (undefined1)((ushort)_DAT_200002fe >> 8);
  DAT_20001371 = DAT_200002fe;
  DAT_20001372 = (undefined1)(_DAT_20000300 / 10 >> 0x10);
  DAT_20001373 = (undefined1)(_DAT_20000300 / 10 >> 8);
  DAT_20001374 = (undefined1)(_DAT_20000300 / 10);
  DAT_20001375 = DAT_20000306;
  DAT_20001376 = DAT_200002a5;
  DAT_20001377 = DAT_200002c7;
  DAT_20001378 = DAT_200002a4;
  DAT_20001379 = (undefined1)((int)(DAT_200002a6 - 0x50) / 5);
  DAT_2000137a = (&DAT_200002ad)[uVar1];
  DAT_2000137b = (&DAT_200002b3)[uVar1];
  DAT_2000137c = DAT_200002b9;
  DAT_2000137d = (&DAT_200002c0)[uVar1];
  DAT_2000137e = FUN_0800f9ac(0x20001358,0x26);
  FUN_0800b990((undefined1 *)0x2000128e,&DAT_20001358,0x27);
  DAT_20001356 = 0x27;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_080107da   (0x080107DA, 604 Bytes, 2 Teile)
 * Display-Builder '35 27 3A' (39B, XOR): Status/Clamp-Bit, Wheel, Limit, Stroeme, Odometer
 * Body: 0x080107DA-0x080108BD, 0x08010990-0x08010B09
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_080107da(void)

{
  uint uVar1;
  byte bVar2;
  
  if (DAT_20000309 == '\0') {
    uVar1 = (uint)DAT_200002a1;
  }
  else {
    uVar1 = 0;
  }
  if ((DAT_200002a3 & 0x80) == 0) {
    bVar2 = 0;
  }
  else {
    bVar2 = 8;
  }
  if ((DAT_200002e5 & 0x80) == 0x80) {
    bVar2 = DAT_200002dc & 0xf7 | bVar2 | 0x80;
  }
  else {
    bVar2 = DAT_200002dc & 0x77 | bVar2;
  }
  if ((DAT_200002e5 & 0x20) == 0x20) {
    bVar2 = bVar2 | 4;
  }
  else {
    bVar2 = bVar2 & 0xfb;
  }
  DAT_20001364 = DAT_200002a3 & 0xfe;
  DAT_20001358 = 0x35;
  DAT_20001359 = 0x27;
  DAT_2000135a = 0x3a;
  DAT_2000135b = DAT_200002db;
  if ((_DAT_20000034 < 0x1f5) || (DAT_2000032d == DAT_20000421)) {
    DAT_2000135c = bVar2 & 0xdf;
  }
  else {
    DAT_2000135c = bVar2 | 0x20;
  }
  if ((_DAT_20000036 < 0x1f5) || (DAT_2000032d == DAT_20000421)) {
    DAT_2000135c = DAT_2000135c & 0xbf;
  }
  else {
    DAT_2000135c = DAT_2000135c | 0x40;
  }
  if (_DAT_20000032 < 0x1f5) {
    DAT_2000135c = DAT_2000135c & 0xef;
  }
  else {
    DAT_2000135c = DAT_2000135c | 0x10;
  }
  if (DAT_2000030d == '\0') {
    DAT_2000135c = DAT_2000135c & 0xfd;
  }
  else {
    DAT_2000135c = DAT_2000135c | 2;
  }
  DAT_2000135d = (undefined1)((ushort)_DAT_200002de >> 8);
  DAT_2000135e = DAT_200002de;
  DAT_2000135f = DAT_200002e0;
  DAT_20001360 = (undefined1)((ushort)_DAT_200002e2 >> 8);
  DAT_20001361 = DAT_200002e2;
  DAT_20001362 = DAT_200002e4;
  DAT_20001363 = (undefined1)uVar1;
  if (DAT_2000036d < 0x29) {
    DAT_20001365 = '\0';
  }
  else {
    DAT_20001365 = DAT_2000036d - 0x28;
  }
  DAT_20001366 = DAT_20000364;
  DAT_20001367 = DAT_2000035e;
  DAT_20001368 = DAT_2000035f;
  DAT_20001369 = (undefined1)((ushort)_DAT_200002f0 >> 8);
  DAT_2000136a = DAT_200002f0;
  DAT_2000136b = DAT_200002f2 & 0x5f;
  DAT_2000136c = (undefined1)((ushort)_DAT_200002f4 >> 8);
  DAT_2000136d = (undefined1)_DAT_200002f4;
  DAT_2000136e = (undefined1)((ushort)_DAT_200002f8 >> 8);
  DAT_2000136f = (undefined1)_DAT_200002f8;
  DAT_20001370 = (undefined1)((ushort)_DAT_200002fe >> 8);
  DAT_20001371 = DAT_200002fe;
  DAT_20001372 = (undefined1)(_DAT_20000300 / 10 >> 0x10);
  DAT_20001373 = (undefined1)(_DAT_20000300 / 10 >> 8);
  DAT_20001374 = (undefined1)(_DAT_20000300 / 10);
  DAT_20001375 = DAT_20000306;
  DAT_20001376 = DAT_200002a5;
  DAT_20001377 = DAT_200002c7;
  DAT_20001378 = DAT_200002a4;
  DAT_20001379 = (undefined1)((int)(DAT_200002a6 - 0x50) / 5);
  DAT_2000137a = (&DAT_200002a7)[uVar1];
  DAT_2000137b = (&DAT_200002b3)[uVar1];
  DAT_2000137c = DAT_200002b9;
  DAT_2000137d = (&DAT_200002ba)[uVar1];
  DAT_2000137e = FUN_0800f9ac(0x20001358,0x26);
  FUN_0800b990((undefined1 *)0x2000128e,&DAT_20001358,0x27);
  DAT_20001356 = 0x27;
  return;
}


/* ---------------------------------------------------------------------
 * thunk_FUN_0801099c   (0x080108BC, 1 Bytes)
 * Body: 0x080108BC-0x080108BD
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thunk_FUN_0801099c(void)

{
  int unaff_r4;
  undefined4 unaff_r6;
  undefined4 unaff_r7;
  undefined1 unaff_r9;
  
  if (_DAT_20000032 < 0x1f5) {
    DAT_2000135c = DAT_2000135c & 0xef;
  }
  else {
    DAT_2000135c = DAT_2000135c | 0x10;
  }
  if (DAT_2000030d == '\0') {
    DAT_2000135c = DAT_2000135c & 0xfd;
  }
  else {
    DAT_2000135c = DAT_2000135c | 2;
  }
  DAT_2000135d = (undefined1)((ushort)_DAT_200002de >> 8);
  DAT_2000135e = DAT_200002de;
  DAT_2000135f = DAT_200002e0;
  DAT_20001360 = (undefined1)((ushort)_DAT_200002e2 >> 8);
  DAT_20001361 = DAT_200002e2;
  DAT_20001362 = DAT_200002e4;
  DAT_20001363 = (undefined1)unaff_r4;
  if (DAT_2000036d < 0x29) {
    DAT_20001365 = '\0';
  }
  else {
    DAT_20001365 = DAT_2000036d - 0x28;
  }
  DAT_20001366 = DAT_20000364;
  DAT_20001367 = DAT_2000035e;
  DAT_20001368 = DAT_2000035f;
  DAT_20001369 = (undefined1)((ushort)_DAT_200002f0 >> 8);
  DAT_2000136a = DAT_200002f0;
  DAT_2000136b = DAT_200002f2 & 0x5f;
  DAT_2000136c = (undefined1)((uint)unaff_r6 >> 8);
  DAT_2000136d = (undefined1)unaff_r6;
  DAT_2000136e = (undefined1)((uint)unaff_r7 >> 8);
  DAT_2000136f = (undefined1)unaff_r7;
  DAT_20001370 = (undefined1)((ushort)_DAT_200002fe >> 8);
  DAT_20001371 = DAT_200002fe;
  DAT_20001372 = (undefined1)(_DAT_20000300 / 10 >> 0x10);
  DAT_20001373 = (undefined1)(_DAT_20000300 / 10 >> 8);
  DAT_20001374 = (undefined1)(_DAT_20000300 / 10);
  DAT_20001375 = DAT_20000306;
  DAT_20001376 = DAT_200002a5;
  DAT_20001377 = DAT_200002c7;
  DAT_20001378 = DAT_200002a4;
  DAT_20001379 = (undefined1)((int)(DAT_200002a6 - 0x50) / 5);
  DAT_2000137a = (&DAT_200002a7)[unaff_r4];
  DAT_2000137b = (&DAT_200002b3)[unaff_r4];
  DAT_2000137c = DAT_200002b9;
  DAT_2000137d = (&DAT_200002ba)[unaff_r4];
  DAT_20001364 = unaff_r9;
  DAT_2000137e = FUN_0800f9ac(0x20001358,0x26);
  FUN_0800b990((undefined1 *)0x2000128e,&DAT_20001358,0x27);
  DAT_20001356 = 0x27;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801099c   (0x0801099C, 365 Bytes)
 * Body: 0x0801099C-0x08010B09
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0801099c(void)

{
  int unaff_r4;
  undefined4 unaff_r6;
  undefined4 unaff_r7;
  undefined1 unaff_r9;
  
  if (_DAT_20000032 < 0x1f5) {
    DAT_2000135c = DAT_2000135c & 0xef;
  }
  else {
    DAT_2000135c = DAT_2000135c | 0x10;
  }
  if (DAT_2000030d == '\0') {
    DAT_2000135c = DAT_2000135c & 0xfd;
  }
  else {
    DAT_2000135c = DAT_2000135c | 2;
  }
  DAT_2000135d = (undefined1)((ushort)_DAT_200002de >> 8);
  DAT_2000135e = DAT_200002de;
  DAT_2000135f = DAT_200002e0;
  DAT_20001360 = (undefined1)((ushort)_DAT_200002e2 >> 8);
  DAT_20001361 = DAT_200002e2;
  DAT_20001362 = DAT_200002e4;
  DAT_20001363 = (undefined1)unaff_r4;
  if (DAT_2000036d < 0x29) {
    DAT_20001365 = '\0';
  }
  else {
    DAT_20001365 = DAT_2000036d - 0x28;
  }
  DAT_20001366 = DAT_20000364;
  DAT_20001367 = DAT_2000035e;
  DAT_20001368 = DAT_2000035f;
  DAT_20001369 = (undefined1)((ushort)_DAT_200002f0 >> 8);
  DAT_2000136a = DAT_200002f0;
  DAT_2000136b = DAT_200002f2 & 0x5f;
  DAT_2000136c = (undefined1)((uint)unaff_r6 >> 8);
  DAT_2000136d = (undefined1)unaff_r6;
  DAT_2000136e = (undefined1)((uint)unaff_r7 >> 8);
  DAT_2000136f = (undefined1)unaff_r7;
  DAT_20001370 = (undefined1)((ushort)_DAT_200002fe >> 8);
  DAT_20001371 = DAT_200002fe;
  DAT_20001372 = (undefined1)(_DAT_20000300 / 10 >> 0x10);
  DAT_20001373 = (undefined1)(_DAT_20000300 / 10 >> 8);
  DAT_20001374 = (undefined1)(_DAT_20000300 / 10);
  DAT_20001375 = DAT_20000306;
  DAT_20001376 = DAT_200002a5;
  DAT_20001377 = DAT_200002c7;
  DAT_20001378 = DAT_200002a4;
  DAT_20001379 = (undefined1)((int)(DAT_200002a6 - 0x50) / 5);
  DAT_2000137a = (&DAT_200002a7)[unaff_r4];
  DAT_2000137b = (&DAT_200002b3)[unaff_r4];
  DAT_2000137c = DAT_200002b9;
  DAT_2000137d = (&DAT_200002ba)[unaff_r4];
  DAT_20001364 = unaff_r9;
  DAT_2000137e = FUN_0800f9ac(0x20001358,0x26);
  FUN_0800b990((undefined1 *)0x2000128e,&DAT_20001358,0x27);
  DAT_20001356 = 0x27;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08010b0a   (0x08010B0A, 53 Bytes)
 * Body: 0x08010B0A-0x08010B3F
 * --------------------------------------------------------------------- */
void FUN_08010b0a(void)

{
  if (DAT_20000422 == '\0') {
    FUN_080107da();
    DAT_20000422 = DAT_20000422 + '\x01';
  }
  else if (DAT_20000422 == '\x01') {
    FUN_08010648();
    DAT_20000422 = '\0';
  }
  else {
    DAT_20000422 = '\0';
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08010b40   (0x08010B40, 81 Bytes)
 * Body: 0x08010B40-0x08010B91
 * --------------------------------------------------------------------- */
void FUN_08010b40(void)

{
  DAT_2000040b = (DAT_2000040b + 1U) - (char)(((int)(uint)(byte)(DAT_2000040b + 1U) >> 2) << 2);
  if (DAT_2000040b == '\0') {
    FUN_08010b0a();
  }
  else if (DAT_2000040b == '\x01') {
    FUN_080105a8();
  }
  else if (DAT_2000040b == '\x02') {
    FUN_08010b0a();
  }
  else if (DAT_2000040b == '\x03') {
    FUN_080105a8();
  }
  FUN_0800fe3a();
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08010b92   (0x08010B92, 57 Bytes)
 * Body: 0x08010B92-0x08010BCB
 * --------------------------------------------------------------------- */
void FUN_08010b92(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = 0;
  iVar3 = 0;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    uVar1 = uVar1 ^ *(byte *)(param_1 + iVar3);
    iVar3 = iVar3 + 1;
    for (iVar2 = 0; iVar2 < 8; iVar2 = iVar2 + 1) {
      if ((uVar1 & 0x80) == 0x80) {
        uVar1 = (uVar1 & 0x7f) << 1 ^ 7;
      }
      else {
        uVar1 = (uVar1 & 0x7f) << 1;
      }
    }
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08010bcc   (0x08010BCC, 33 Bytes)
 * Body: 0x08010BCC-0x08010BED
 * --------------------------------------------------------------------- */
bool FUN_08010bcc(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = FUN_08010b92(param_1,param_2);
  return param_3 == iVar1;
}


/* ---------------------------------------------------------------------
 * FUN_08010bee   (0x08010BEE, 33 Bytes)
 * Body: 0x08010BEE-0x08010C0F
 * --------------------------------------------------------------------- */
bool FUN_08010bee(int param_1)

{
  return (*(byte *)(param_1 + 0xd3) + 1) % 0xf == (uint)*(byte *)(param_1 + 0xd2);
}


/* ---------------------------------------------------------------------
 * FUN_08010c10   (0x08010C10, 63 Bytes)
 * Body: 0x08010C10-0x08010C4F
 * --------------------------------------------------------------------- */
undefined4 FUN_08010c10(int param_1,undefined4 *param_2)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  
  bVar1 = FUN_08010bee(param_1);
  if (bVar1) {
    uVar3 = 2;
  }
  else {
    FUN_0801d2ec((undefined4 *)(param_1 + (uint)*(byte *)(param_1 + 0xd3) * 0xe),param_2,0xe);
    uVar2 = *(byte *)(param_1 + 0xd3) + 1;
    *(char *)(param_1 + 0xd3) = (char)uVar2 + (char)(uVar2 / 0xf) * -0xf;
    uVar3 = 0;
  }
  return uVar3;
}


/* ---------------------------------------------------------------------
 * FUN_08010c50   (0x08010C50, 33 Bytes)
 * Display-Queue: 'voll?'
 * Body: 0x08010C50-0x08010C71
 * --------------------------------------------------------------------- */
bool FUN_08010c50(int param_1)

{
  return (*(byte *)(param_1 + 0x12d) + 1) % 0xf == (uint)*(byte *)(param_1 + 300);
}


/* ---------------------------------------------------------------------
 * FUN_08010c72   (0x08010C72, 3 Bytes)
 * Display-Queue: Enqueue
 * Body: 0x08010C72-0x08010C75
 * --------------------------------------------------------------------- */
undefined4 FUN_08010c72(int param_1,undefined4 *param_2)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  
  bVar1 = FUN_08010c50(param_1);
  if (bVar1) {
    uVar3 = 2;
  }
  else {
    FUN_0801d2ec((undefined4 *)(param_1 + (uint)*(byte *)(param_1 + 0x12d) * 0x14),param_2,0x14);
    uVar2 = *(byte *)(param_1 + 0x12d) + 1;
    *(char *)(param_1 + 0x12d) = (char)uVar2 + (char)(uVar2 / 0xf) * -0xf;
    uVar3 = 0;
  }
  return uVar3;
}


/* ---------------------------------------------------------------------
 * FUN_08010c76   (0x08010C76, 59 Bytes)
 * Display-Queue: Enqueue
 * Body: 0x08010C76-0x08010CB1
 * --------------------------------------------------------------------- */
undefined4 FUN_08010c76(undefined4 param_1,undefined4 *param_2)

{
  bool bVar1;
  uint uVar2;
  int unaff_r4;
  undefined4 uVar3;
  
  bVar1 = FUN_08010c50(unaff_r4);
  if (bVar1) {
    uVar3 = 2;
  }
  else {
    FUN_0801d2ec((undefined4 *)(unaff_r4 + (uint)*(byte *)(unaff_r4 + 0x12d) * 0x14),param_2,0x14);
    uVar2 = *(byte *)(unaff_r4 + 0x12d) + 1;
    *(char *)(unaff_r4 + 0x12d) = (char)uVar2 + (char)(uVar2 / 0xf) * -0xf;
    uVar3 = 0;
  }
  return uVar3;
}


/* ---------------------------------------------------------------------
 * FUN_08010cb4   (0x08010CB4, 202 Bytes, 2 Teile)
 * Ringpuffer->Staging: Display-Ring (0x20002118) und ESC/weitere Quelle verschieben
 * Body: 0x08010CB4-0x08010D75, 0x08010DF8-0x08010E01
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08010cb4(undefined4 param_1,short *param_2)

{
  uint uVar1;
  
  if (*param_2 == 0) {
    DAT_200010f9 = 0;
  }
  else {
    for (uVar1 = 0;
        (uVar1 < _DAT_20000544 &&
        (*(undefined1 *)(DAT_200010f8 + uVar1 + 0x20001030) = *(undefined1 *)(uVar1 + 0x20002118),
        DAT_200010f8 + uVar1 < 199)); uVar1 = uVar1 + 1 & 0xff) {
    }
    DAT_200010f8 = DAT_200010f8 + DAT_20000544;
    _DAT_20000544 = 0;
    DAT_200010f9 = 1;
  }
  if (_DAT_20000542 == 0) {
    DAT_2000128d = 0;
  }
  else {
    for (uVar1 = 0;
        (uVar1 < _DAT_20000542 &&
        (*(undefined1 *)(DAT_2000128c + uVar1 + 0x200011c4) = *(undefined1 *)(uVar1 + 0x20002050),
        DAT_2000128c + uVar1 < 199)); uVar1 = uVar1 + 1 & 0xff) {
    }
    DAT_2000128c = DAT_2000128c + DAT_20000542;
    _DAT_20000542 = 0;
    DAT_2000128d = 1;
  }
  return;
}


/* ---------------------------------------------------------------------
 * thunk_FUN_08010df8   (0x08010D74, 1 Bytes)
 * Body: 0x08010D74-0x08010D75
 * --------------------------------------------------------------------- */
void thunk_FUN_08010df8(void)

{
  DAT_2000128d = 0;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08010df8   (0x08010DF8, 9 Bytes)
 * Body: 0x08010DF8-0x08010E01
 * --------------------------------------------------------------------- */
void FUN_08010df8(void)

{
  DAT_2000128d = 0;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08010e02   (0x08010E02, 137 Bytes)
 * Body: 0x08010E02-0x08010E8B
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08010e02(void)

{
  if ((_DAT_200002fc != 0) && (_DAT_20000428 = _DAT_20000428 + _DAT_200002fc, 36000 < _DAT_20000428)
     ) {
    if ((uint)_DAT_200002fe < -(_DAT_20000428 / 36000) - 1) {
      _DAT_200002fe = (short)(_DAT_20000428 / 36000) + _DAT_200002fe;
      _DAT_20000300 = _DAT_20000428 / 36000 + _DAT_20000300;
    }
    else {
      _DAT_200002fe = 0xffff;
      _DAT_20000300 = -1;
    }
    _DAT_20000428 = _DAT_20000428 % 36000;
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08010e8c   (0x08010E8C, 293 Bytes)
 * Body: 0x08010E8C-0x08010FB1
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08010e8c(void)

{
  if ((DAT_2000038f == '\x01') && (0x2706 < _DAT_2000039c)) {
    _DAT_20000444 = _DAT_20000444 + 1;
    DAT_20000390 = '\0';
    if (2 < _DAT_20000444) {
      _DAT_20000444 = 2;
    }
  }
  else {
    _DAT_20000444 = 0;
    DAT_20000390 = DAT_2000038f;
  }
  if (DAT_20000438 == '\0') {
    if (((_DAT_200002e2 < 3000) && (_DAT_200002e2 != 0)) && ((DAT_200002db & 4) == 4)) {
      _DAT_2000043c = _DAT_2000043c + 1;
      if (4 < _DAT_2000043c) {
        _DAT_2000043c = 0;
        DAT_20000438 = '\x01';
      }
    }
    else {
      _DAT_2000043c = 0;
    }
  }
  else if (((_DAT_200002e2 < 3000) && (_DAT_200002e2 != 0)) && ((DAT_200002db & 4) == 4)) {
    _DAT_20000440 = 0;
  }
  else {
    _DAT_20000440 = _DAT_20000440 + 1;
    if (0x1d < _DAT_20000440) {
      _DAT_20000440 = 0;
      DAT_20000438 = '\0';
    }
  }
  if (DAT_20000430 == '\0') {
    if (DAT_20000438 == '\0') {
      _DAT_20000434 = 0;
    }
    else {
      _DAT_20000434 = _DAT_20000434 + 1;
      if (2 < _DAT_20000434) {
        _DAT_2000042c = 5;
      }
    }
    if (_DAT_2000042c == 0) {
      if (DAT_20000390 != '\0') {
        DAT_20000430 = '\x01';
      }
    }
    else {
      _DAT_2000042c = _DAT_2000042c + -1;
      DAT_20000390 = '\0';
    }
  }
  else if (DAT_20000390 == '\0') {
    DAT_20000430 = '\0';
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08010fb0   (0x08010FB0, 1 Bytes)
 * Body: 0x08010FB0-0x08010FB1
 * --------------------------------------------------------------------- */
void FUN_08010fb0(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08010ff8   (0x08010FF8, 5 Bytes)
 * Body: 0x08010FF8-0x08010FFD
 * --------------------------------------------------------------------- */
void FUN_08010ff8(undefined4 *param_1)

{
  *param_1 = 1;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08010ffe   (0x08010FFE, 49 Bytes)
 * Body: 0x08010FFE-0x0801102F
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08010ffe(void)

{
  _DAT_20001604 = 0;
  DAT_20001640 = 1;
  DAT_20001641 = 0;
  DAT_20001651 = 0;
  DAT_20001650 = 0;
  _DAT_20001644 = 2;
  DAT_20001648 = 100;
  FUN_08010ff8((undefined4 *)0x2000164c);
  return;
}



/* =====================================================================
 *  SEKTION: 0x08011000 - Kennlinien/Filter/Regel-Helfer (teilweise unbenannt)
 * ===================================================================== */

/* ---------------------------------------------------------------------
 * FUN_08011030   (0x08011030, 7 Bytes)
 * Body: 0x08011030-0x08011037
 * --------------------------------------------------------------------- */
void FUN_08011030(void)

{
  DAT_2000044c = 0xff;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08011038   (0x08011038, 11 Bytes)
 * Body: 0x08011038-0x08011043
 * --------------------------------------------------------------------- */
int FUN_08011038(int param_1,int param_2,int param_3)

{
  return param_1 * 0x10000 + param_2 * 0x100 + param_3;
}


/* ---------------------------------------------------------------------
 * FUN_08011044   (0x08011044, 367 Bytes)
 * Body: 0x08011044-0x080111B3
 * --------------------------------------------------------------------- */
void FUN_08011044(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  char in_CY;
  undefined8 in_d0;
  uint uVar2;
  uint uVar3;
  longlong lVar4;
  uint uVar5;
  ulonglong uVar6;
  
  uVar2 = (uint)((ulonglong)in_d0 >> 0x20);
  lVar4 = CONCAT44(param_4,param_3);
  FUN_0801d6a0(param_3,param_4);
  if (in_CY == '\0') {
    uVar6 = FUN_0801d342(param_3,param_4,0,0x3ff00000);
    lVar4 = (uVar6 & 0xffffffff00000000) + (uVar6 & 0xffffffff);
  }
  uVar1 = (uint)((ulonglong)lVar4 >> 0x20);
  FUN_0801d6d0((uint)lVar4,uVar1);
  if (in_CY == '\0') {
    uVar6 = FUN_0801d484((uint)lVar4,uVar1,0,0x3ff00000);
    lVar4 = (uVar6 & 0xffffffff00000000) + (uVar6 & 0xffffffff);
  }
  uVar1 = (uint)((ulonglong)lVar4 >> 0x20);
  uVar3 = (uint)lVar4;
  uVar6 = FUN_0801d490(0,0x40180000,uVar3,uVar1);
  FUN_0801d6a0((int)uVar6,(int)(uVar6 >> 0x20));
  uVar5 = (uint)in_d0;
  if (in_CY == '\0') {
    uVar6 = FUN_0801d48a(uVar5,uVar2,param_1,param_2);
    uVar6 = FUN_0801d490((uint)uVar6,(uint)(uVar6 >> 0x20),0,0x40180000);
    uVar6 = FUN_0801d490((uint)uVar6,(uint)(uVar6 >> 0x20),uVar3,uVar1);
    FUN_0801d342((uint)uVar6,(uint)(uVar6 >> 0x20),uVar5,uVar2);
  }
  else {
    uVar6 = FUN_0801d490(0,0x40000000,uVar3,uVar1);
    FUN_0801d6a0((int)uVar6,(int)(uVar6 >> 0x20));
    if (in_CY != '\0') {
      uVar6 = FUN_0801d490(0,0x40080000,uVar3,uVar1);
      FUN_0801d6a0((int)uVar6,(int)(uVar6 >> 0x20));
      if (in_CY == '\0') {
        uVar6 = FUN_0801d484(0x55555555,0x3fe55555,uVar3,uVar1);
        lVar4 = (uVar6 & 0xffffffff00000000) + (uVar6 & 0xffffffff);
        uVar6 = FUN_0801d48a(uVar5,uVar2,param_1,param_2);
        uVar6 = FUN_0801d490((uint)uVar6,(uint)(uVar6 >> 0x20),(uint)lVar4,
                             (uint)((ulonglong)lVar4 >> 0x20));
        uVar6 = FUN_0801d490((uint)uVar6,(uint)(uVar6 >> 0x20),0,0x40180000);
        FUN_0801d342((uint)uVar6,(uint)(uVar6 >> 0x20),uVar5,uVar2);
      }
    }
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_080111b4   (0x080111B4, 451 Bytes)
 * Body: 0x080111B4-0x08011377
 * --------------------------------------------------------------------- */
void FUN_080111b4(uint param_1,uint param_2,uint param_3,uint param_4,undefined1 *param_5,
                 undefined1 *param_6,undefined1 *param_7)

{
  uint uVar1;
  uint uVar2;
  char in_ZR;
  undefined1 in_CY;
  undefined8 in_d0;
  uint uVar3;
  uint extraout_s1;
  uint extraout_s1_00;
  uint extraout_s1_01;
  uint uVar4;
  longlong lVar5;
  ulonglong uVar6;
  undefined4 local_60;
  undefined4 uStack_5c;
  undefined4 local_58;
  undefined4 uStack_54;
  
  uVar1 = (uint)in_d0;
  uVar3 = (uint)((ulonglong)in_d0 >> 0x20);
  FUN_0801d6a0(param_1,param_2);
  local_58 = param_3;
  uStack_54 = param_4;
  local_60 = param_3;
  uStack_5c = param_4;
  if (in_ZR == '\0') {
    FUN_0801d6a0(param_3,param_4);
    if ((bool)in_CY && !(bool)in_ZR) {
      uVar6 = FUN_0801d490(param_3,param_4,param_1,param_2);
      lVar5 = (uVar6 & 0xffffffff00000000) + (uVar6 & 0xffffffff);
      uVar6 = FUN_0801d342(param_3,param_4,param_1,param_2);
      uVar6 = FUN_0801d484((uint)uVar6,(uint)(uVar6 >> 0x20),(uint)lVar5,
                           (uint)((ulonglong)lVar5 >> 0x20));
      lVar5 = (uVar6 & 0xffffffff00000000) + (uVar6 & 0xffffffff);
    }
    else {
      uVar6 = FUN_0801d342(0,0x3ff00000,param_1,param_2);
      uVar6 = FUN_0801d490((uint)uVar6,(uint)(uVar6 >> 0x20),param_3,param_4);
      lVar5 = (uVar6 & 0xffffffff00000000) + (uVar6 & 0xffffffff);
    }
    uVar6 = FUN_0801d490(0,0x40000000,param_3,param_4);
    uVar2 = (uint)((ulonglong)lVar5 >> 0x20);
    uVar4 = (uint)lVar5;
    uVar6 = FUN_0801d484((uint)uVar6,(uint)(uVar6 >> 0x20),uVar4,uVar2);
    lVar5 = (uVar6 & 0xffffffff00000000) + (uVar6 & 0xffffffff);
    FUN_0801d484(uVar4,uVar2,(uint)lVar5,(uint)((ulonglong)lVar5 >> 0x20));
    uVar6 = FUN_0801d342(uVar1,uVar3,0x55555555,0x3fd55555);
    lVar5 = (uVar6 & 0xffffffff00000000) + (uVar6 & 0xffffffff);
    local_58 = FUN_08011044(uVar4,uVar2,(uint)lVar5,(uint)((ulonglong)lVar5 >> 0x20));
    local_60 = FUN_08011044(uVar4,uVar2,uVar1,uVar3);
    uVar6 = FUN_0801d484(uVar1,uVar3,0x55555555,0x3fd55555);
    lVar5 = (uVar6 & 0xffffffff00000000) + (uVar6 & 0xffffffff);
    param_3 = FUN_08011044(uVar4,uVar2,(uint)lVar5,(uint)((ulonglong)lVar5 >> 0x20));
    param_4 = extraout_s1_01;
    uStack_54 = extraout_s1;
    uStack_5c = extraout_s1_00;
  }
  uVar6 = FUN_0801d490(local_58,uStack_54,0,0x406fe000);
  uVar6 = FUN_0801d66c((uint)uVar6,(uint)(uVar6 >> 0x20));
  *param_5 = (char)uVar6;
  uVar6 = FUN_0801d490(local_60,uStack_5c,0,0x406fe000);
  uVar6 = FUN_0801d66c((uint)uVar6,(uint)(uVar6 >> 0x20));
  *param_6 = (char)uVar6;
  uVar6 = FUN_0801d490(param_3,param_4,0,0x406fe000);
  uVar6 = FUN_0801d66c((uint)uVar6,(uint)(uVar6 >> 0x20));
  *param_7 = (char)uVar6;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08011378   (0x08011378, 796 Bytes, 2 Teile)
 * Body: 0x08011378-0x080113F3, 0x08011444-0x080116E5
 * --------------------------------------------------------------------- */
void FUN_08011378(uint param_1,uint param_2,uint param_3,ulonglong *param_4,undefined8 *param_5,
                 undefined8 *param_6)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  char in_ZR;
  char in_CY;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  longlong lVar9;
  longlong lVar10;
  uint uVar11;
  uint uVar12;
  longlong lVar13;
  uint uVar14;
  longlong lVar15;
  ulonglong uVar16;
  undefined8 uVar17;
  
  uVar16 = FUN_0801d652(param_1);
  uVar16 = FUN_0801d574((uint)uVar16,(uint)(uVar16 >> 0x20),0,0x406fe000);
  lVar13 = (uVar16 & 0xffffffff00000000) + (uVar16 & 0xffffffff);
  uVar16 = FUN_0801d652(param_2);
  uVar16 = FUN_0801d574((uint)uVar16,(uint)(uVar16 >> 0x20),0,0x406fe000);
  lVar9 = (uVar16 & 0xffffffff00000000) + (uVar16 & 0xffffffff);
  uVar16 = FUN_0801d652(param_3);
  uVar16 = FUN_0801d574((uint)uVar16,(uint)(uVar16 >> 0x20),0,0x406fe000);
  lVar10 = (uVar16 & 0xffffffff00000000) + (uVar16 & 0xffffffff);
  uVar1 = (uint)((ulonglong)lVar9 >> 0x20);
  uVar8 = (uint)lVar9;
  FUN_0801d6a0(uVar8,uVar1);
  uVar2 = (uint)((ulonglong)lVar13 >> 0x20);
  uVar12 = (uint)lVar13;
  FUN_0801d6a0(uVar12,uVar2);
  uVar11 = (uint)((ulonglong)lVar10 >> 0x20);
  lVar15 = lVar13;
  if ((in_CY != '\0') && (FUN_0801d6a0(uVar8,uVar1), lVar15 = lVar10, in_CY == '\0')) {
    lVar15 = lVar9;
  }
  uVar6 = (uint)((ulonglong)lVar15 >> 0x20);
  uVar4 = (uint)lVar15;
  FUN_0801d6d0(uVar8,uVar1);
  FUN_0801d6d0(uVar12,uVar2);
  if ((in_CY != '\0') && (FUN_0801d6d0(uVar8,uVar1), lVar13 = lVar10, in_CY == '\0')) {
    lVar13 = lVar9;
  }
  uVar7 = (uint)((ulonglong)lVar13 >> 0x20);
  uVar5 = (uint)lVar13;
  uVar16 = FUN_0801d484(uVar5,uVar7,uVar4,uVar6);
  lVar15 = (uVar16 & 0xffffffff00000000) + (uVar16 & 0xffffffff);
  uVar16 = FUN_0801d342(uVar5,uVar7,uVar4,uVar6);
  uVar17 = FUN_0801d574((uint)uVar16,(uint)(uVar16 >> 0x20),0,0x40000000);
  *param_6 = uVar17;
  FUN_0801d6a0(uVar5,uVar7);
  if (in_ZR == '\0') {
    FUN_0801d6a0(uVar5,uVar7);
    uVar14 = (uint)lVar15;
    uVar3 = (uint)((ulonglong)lVar15 >> 0x20);
    if (in_ZR == '\0') {
      FUN_0801d6a0(uVar5,uVar7);
      if (in_ZR == '\0') {
        FUN_0801d6a0(uVar5,uVar7);
        if (in_ZR != '\0') {
          uVar16 = FUN_0801d484(uVar12,uVar2,uVar8,uVar1);
          uVar17 = FUN_0801d574((uint)uVar16,(uint)(uVar16 >> 0x20),uVar14,uVar3);
          uVar17 = FUN_0801d574((uint)uVar17,(uint)((ulonglong)uVar17 >> 0x20),0,0x40180000);
          uVar16 = FUN_0801d342((uint)uVar17,(uint)((ulonglong)uVar17 >> 0x20),0x55555555,0x3fe55555
                               );
          *param_4 = uVar16;
        }
      }
      else {
        uVar16 = FUN_0801d484((uint)lVar10,uVar11,uVar12,uVar2);
        uVar17 = FUN_0801d574((uint)uVar16,(uint)(uVar16 >> 0x20),uVar14,uVar3);
        uVar17 = FUN_0801d574((uint)uVar17,(uint)((ulonglong)uVar17 >> 0x20),0,0x40180000);
        uVar16 = FUN_0801d342((uint)uVar17,(uint)((ulonglong)uVar17 >> 0x20),0x55555555,0x3fd55555);
        *param_4 = uVar16;
      }
    }
    else {
      uVar16 = FUN_0801d484(uVar8,uVar1,(uint)lVar10,uVar11);
      uVar17 = FUN_0801d574((uint)uVar16,(uint)(uVar16 >> 0x20),uVar14,uVar3);
      uVar16 = FUN_0801d574((uint)uVar17,(uint)((ulonglong)uVar17 >> 0x20),0,0x40180000);
      *param_4 = uVar16;
    }
    FUN_0801d6a0((int)*param_4,(int)(*param_4 >> 0x20));
    if (in_CY == '\0') {
      uVar16 = FUN_0801d342((uint)*param_4,(uint)(*param_4 >> 0x20),0,0x3ff00000);
      *param_4 = uVar16;
    }
    FUN_0801d6d0((int)*param_6,(int)((ulonglong)*param_6 >> 0x20));
    if (in_CY == '\0') {
      uVar16 = FUN_0801d484(0,0x40000000,uVar5,uVar7);
      uVar16 = FUN_0801d484((uint)uVar16,(uint)(uVar16 >> 0x20),uVar4,uVar6);
      lVar15 = (uVar16 & 0xffffffff00000000) + (uVar16 & 0xffffffff);
      uVar17 = FUN_0801d574(uVar14,uVar3,(uint)lVar15,(uint)((ulonglong)lVar15 >> 0x20));
      *param_5 = uVar17;
    }
    else {
      uVar16 = FUN_0801d342(uVar5,uVar7,uVar4,uVar6);
      lVar15 = (uVar16 & 0xffffffff00000000) + (uVar16 & 0xffffffff);
      uVar17 = FUN_0801d574(uVar14,uVar3,(uint)lVar15,(uint)((ulonglong)lVar15 >> 0x20));
      *param_5 = uVar17;
    }
  }
  else {
    *param_4 = 0;
    *param_5 = 0;
  }
  return;
}


/* ---------------------------------------------------------------------
 * thunk_FUN_0801144c   (0x080113F2, 1 Bytes)
 * Body: 0x080113F2-0x080113F3
 * --------------------------------------------------------------------- */
void thunk_FUN_0801144c(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  ulonglong *unaff_r4;
  undefined8 *unaff_r5;
  undefined8 *unaff_r8;
  char in_ZR;
  char in_CY;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined8 unaff_d9;
  uint uVar9;
  undefined8 unaff_d10;
  uint uVar10;
  uint uVar11;
  undefined8 unaff_d11;
  uint uVar12;
  longlong lVar13;
  ulonglong uVar14;
  undefined8 uVar15;
  
  uVar1 = (uint)((ulonglong)unaff_d11 >> 0x20);
  uVar11 = (uint)unaff_d11;
  FUN_0801d6a0(uVar11,uVar1);
  uVar8 = (uint)unaff_d9;
  uVar2 = (uint)((ulonglong)unaff_d9 >> 0x20);
  uVar9 = (uint)unaff_d10;
  uVar10 = (uint)((ulonglong)unaff_d10 >> 0x20);
  uVar4 = uVar11;
  uVar6 = uVar1;
  if ((in_CY != '\0') && (FUN_0801d6a0(uVar8,uVar2), uVar4 = uVar9, uVar6 = uVar10, in_CY == '\0'))
  {
    uVar4 = uVar8;
    uVar6 = uVar2;
  }
  FUN_0801d6d0(uVar8,uVar2);
  FUN_0801d6d0(uVar11,uVar1);
  uVar5 = uVar11;
  uVar7 = uVar1;
  if ((in_CY != '\0') && (FUN_0801d6d0(uVar8,uVar2), uVar5 = uVar9, uVar7 = uVar10, in_CY == '\0'))
  {
    uVar5 = uVar8;
    uVar7 = uVar2;
  }
  uVar14 = FUN_0801d484(uVar5,uVar7,uVar4,uVar6);
  lVar13 = (uVar14 & 0xffffffff00000000) + (uVar14 & 0xffffffff);
  uVar14 = FUN_0801d342(uVar5,uVar7,uVar4,uVar6);
  uVar15 = FUN_0801d574((uint)uVar14,(uint)(uVar14 >> 0x20),0,0x40000000);
  *unaff_r8 = uVar15;
  FUN_0801d6a0(uVar5,uVar7);
  if (in_ZR == '\0') {
    FUN_0801d6a0(uVar5,uVar7);
    uVar12 = (uint)lVar13;
    uVar3 = (uint)((ulonglong)lVar13 >> 0x20);
    if (in_ZR == '\0') {
      FUN_0801d6a0(uVar5,uVar7);
      if (in_ZR == '\0') {
        FUN_0801d6a0(uVar5,uVar7);
        if (in_ZR != '\0') {
          uVar14 = FUN_0801d484(uVar11,uVar1,uVar8,uVar2);
          uVar15 = FUN_0801d574((uint)uVar14,(uint)(uVar14 >> 0x20),uVar12,uVar3);
          uVar15 = FUN_0801d574((uint)uVar15,(uint)((ulonglong)uVar15 >> 0x20),0,0x40180000);
          uVar14 = FUN_0801d342((uint)uVar15,(uint)((ulonglong)uVar15 >> 0x20),0x55555555,0x3fe55555
                               );
          *unaff_r4 = uVar14;
        }
      }
      else {
        uVar14 = FUN_0801d484(uVar9,uVar10,uVar11,uVar1);
        uVar15 = FUN_0801d574((uint)uVar14,(uint)(uVar14 >> 0x20),uVar12,uVar3);
        uVar15 = FUN_0801d574((uint)uVar15,(uint)((ulonglong)uVar15 >> 0x20),0,0x40180000);
        uVar14 = FUN_0801d342((uint)uVar15,(uint)((ulonglong)uVar15 >> 0x20),0x55555555,0x3fd55555);
        *unaff_r4 = uVar14;
      }
    }
    else {
      uVar14 = FUN_0801d484(uVar8,uVar2,uVar9,uVar10);
      uVar15 = FUN_0801d574((uint)uVar14,(uint)(uVar14 >> 0x20),uVar12,uVar3);
      uVar14 = FUN_0801d574((uint)uVar15,(uint)((ulonglong)uVar15 >> 0x20),0,0x40180000);
      *unaff_r4 = uVar14;
    }
    FUN_0801d6a0((int)*unaff_r4,(int)(*unaff_r4 >> 0x20));
    if (in_CY == '\0') {
      uVar14 = FUN_0801d342((uint)*unaff_r4,(uint)(*unaff_r4 >> 0x20),0,0x3ff00000);
      *unaff_r4 = uVar14;
    }
    FUN_0801d6d0((int)*unaff_r8,(int)((ulonglong)*unaff_r8 >> 0x20));
    if (in_CY == '\0') {
      uVar14 = FUN_0801d484(0,0x40000000,uVar5,uVar7);
      uVar14 = FUN_0801d484((uint)uVar14,(uint)(uVar14 >> 0x20),uVar4,uVar6);
      lVar13 = (uVar14 & 0xffffffff00000000) + (uVar14 & 0xffffffff);
      uVar15 = FUN_0801d574(uVar12,uVar3,(uint)lVar13,(uint)((ulonglong)lVar13 >> 0x20));
      *unaff_r5 = uVar15;
    }
    else {
      uVar14 = FUN_0801d342(uVar5,uVar7,uVar4,uVar6);
      lVar13 = (uVar14 & 0xffffffff00000000) + (uVar14 & 0xffffffff);
      uVar15 = FUN_0801d574(uVar12,uVar3,(uint)lVar13,(uint)((ulonglong)lVar13 >> 0x20));
      *unaff_r5 = uVar15;
    }
  }
  else {
    *unaff_r4 = 0;
    *unaff_r5 = 0;
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801144c   (0x0801144C, 665 Bytes)
 * Body: 0x0801144C-0x080116E5
 * --------------------------------------------------------------------- */
void FUN_0801144c(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  ulonglong *unaff_r4;
  undefined8 *unaff_r5;
  undefined8 *unaff_r8;
  char in_ZR;
  char in_CY;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined8 unaff_d9;
  uint uVar9;
  undefined8 unaff_d10;
  uint uVar10;
  uint uVar11;
  undefined8 unaff_d11;
  uint uVar12;
  longlong lVar13;
  ulonglong uVar14;
  undefined8 uVar15;
  
  uVar1 = (uint)((ulonglong)unaff_d11 >> 0x20);
  uVar11 = (uint)unaff_d11;
  FUN_0801d6a0(uVar11,uVar1);
  uVar8 = (uint)unaff_d9;
  uVar2 = (uint)((ulonglong)unaff_d9 >> 0x20);
  uVar9 = (uint)unaff_d10;
  uVar10 = (uint)((ulonglong)unaff_d10 >> 0x20);
  uVar4 = uVar11;
  uVar6 = uVar1;
  if ((in_CY != '\0') && (FUN_0801d6a0(uVar8,uVar2), uVar4 = uVar9, uVar6 = uVar10, in_CY == '\0'))
  {
    uVar4 = uVar8;
    uVar6 = uVar2;
  }
  FUN_0801d6d0(uVar8,uVar2);
  FUN_0801d6d0(uVar11,uVar1);
  uVar5 = uVar11;
  uVar7 = uVar1;
  if ((in_CY != '\0') && (FUN_0801d6d0(uVar8,uVar2), uVar5 = uVar9, uVar7 = uVar10, in_CY == '\0'))
  {
    uVar5 = uVar8;
    uVar7 = uVar2;
  }
  uVar14 = FUN_0801d484(uVar5,uVar7,uVar4,uVar6);
  lVar13 = (uVar14 & 0xffffffff00000000) + (uVar14 & 0xffffffff);
  uVar14 = FUN_0801d342(uVar5,uVar7,uVar4,uVar6);
  uVar15 = FUN_0801d574((uint)uVar14,(uint)(uVar14 >> 0x20),0,0x40000000);
  *unaff_r8 = uVar15;
  FUN_0801d6a0(uVar5,uVar7);
  if (in_ZR == '\0') {
    FUN_0801d6a0(uVar5,uVar7);
    uVar12 = (uint)lVar13;
    uVar3 = (uint)((ulonglong)lVar13 >> 0x20);
    if (in_ZR == '\0') {
      FUN_0801d6a0(uVar5,uVar7);
      if (in_ZR == '\0') {
        FUN_0801d6a0(uVar5,uVar7);
        if (in_ZR != '\0') {
          uVar14 = FUN_0801d484(uVar11,uVar1,uVar8,uVar2);
          uVar15 = FUN_0801d574((uint)uVar14,(uint)(uVar14 >> 0x20),uVar12,uVar3);
          uVar15 = FUN_0801d574((uint)uVar15,(uint)((ulonglong)uVar15 >> 0x20),0,0x40180000);
          uVar14 = FUN_0801d342((uint)uVar15,(uint)((ulonglong)uVar15 >> 0x20),0x55555555,0x3fe55555
                               );
          *unaff_r4 = uVar14;
        }
      }
      else {
        uVar14 = FUN_0801d484(uVar9,uVar10,uVar11,uVar1);
        uVar15 = FUN_0801d574((uint)uVar14,(uint)(uVar14 >> 0x20),uVar12,uVar3);
        uVar15 = FUN_0801d574((uint)uVar15,(uint)((ulonglong)uVar15 >> 0x20),0,0x40180000);
        uVar14 = FUN_0801d342((uint)uVar15,(uint)((ulonglong)uVar15 >> 0x20),0x55555555,0x3fd55555);
        *unaff_r4 = uVar14;
      }
    }
    else {
      uVar14 = FUN_0801d484(uVar8,uVar2,uVar9,uVar10);
      uVar15 = FUN_0801d574((uint)uVar14,(uint)(uVar14 >> 0x20),uVar12,uVar3);
      uVar14 = FUN_0801d574((uint)uVar15,(uint)((ulonglong)uVar15 >> 0x20),0,0x40180000);
      *unaff_r4 = uVar14;
    }
    FUN_0801d6a0((int)*unaff_r4,(int)(*unaff_r4 >> 0x20));
    if (in_CY == '\0') {
      uVar14 = FUN_0801d342((uint)*unaff_r4,(uint)(*unaff_r4 >> 0x20),0,0x3ff00000);
      *unaff_r4 = uVar14;
    }
    FUN_0801d6d0((int)*unaff_r8,(int)((ulonglong)*unaff_r8 >> 0x20));
    if (in_CY == '\0') {
      uVar14 = FUN_0801d484(0,0x40000000,uVar5,uVar7);
      uVar14 = FUN_0801d484((uint)uVar14,(uint)(uVar14 >> 0x20),uVar4,uVar6);
      lVar13 = (uVar14 & 0xffffffff00000000) + (uVar14 & 0xffffffff);
      uVar15 = FUN_0801d574(uVar12,uVar3,(uint)lVar13,(uint)((ulonglong)lVar13 >> 0x20));
      *unaff_r5 = uVar15;
    }
    else {
      uVar14 = FUN_0801d342(uVar5,uVar7,uVar4,uVar6);
      lVar13 = (uVar14 & 0xffffffff00000000) + (uVar14 & 0xffffffff);
      uVar15 = FUN_0801d574(uVar12,uVar3,(uint)lVar13,(uint)((ulonglong)lVar13 >> 0x20));
      *unaff_r5 = uVar15;
    }
  }
  else {
    *unaff_r4 = 0;
    *unaff_r5 = 0;
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_080116e6   (0x080116E6, 5 Bytes)
 * Body: 0x080116E6-0x080116EB
 * --------------------------------------------------------------------- */
undefined1 FUN_080116e6(undefined1 param_1)

{
  return param_1;
}


/* ---------------------------------------------------------------------
 * FUN_080116ec   (0x080116EC, 7 Bytes)
 * Body: 0x080116EC-0x080116F3
 * --------------------------------------------------------------------- */
uint FUN_080116ec(uint param_1)

{
  return (param_1 & 0xffff) >> 8;
}


/* ---------------------------------------------------------------------
 * FUN_080116f4   (0x080116F4, 7 Bytes)
 * Body: 0x080116F4-0x080116FB
 * --------------------------------------------------------------------- */
uint FUN_080116f4(uint param_1)

{
  return (param_1 & 0xffffff) >> 0x10;
}


/* ---------------------------------------------------------------------
 * FUN_080116fc   (0x080116FC, 191 Bytes)
 * Body: 0x080116FC-0x080117BB
 * --------------------------------------------------------------------- */
int FUN_080116fc(uint param_1,uint param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  longlong lVar5;
  ulonglong uVar6;
  byte local_5c [4];
  byte local_58 [4];
  byte local_54 [4];
  undefined8 local_50;
  undefined8 local_48;
  ulonglong local_40 [4];
  
  local_40[0] = 0;
  local_48 = 0;
  local_50 = 0;
  uVar2 = FUN_080116f4(param_2);
  uVar3 = FUN_080116ec(param_2);
  bVar1 = FUN_080116e6((char)param_2);
  FUN_08011378(uVar2,uVar3,(uint)bVar1,local_40,&local_48,&local_50);
  uVar6 = FUN_0801d652(param_1);
  uVar6 = FUN_0801d490((uint)uVar6,(uint)(uVar6 >> 0x20),(uint)local_50,
                       (uint)((ulonglong)local_50 >> 0x20));
  uVar6 = FUN_0801d574((uint)uVar6,(uint)(uVar6 >> 0x20),0,0x4074d000);
  lVar5 = (uVar6 & 0xffffffff00000000) + (uVar6 & 0xffffffff);
  FUN_080111b4((uint)local_48,(uint)((ulonglong)local_48 >> 0x20),(uint)lVar5,
               (uint)((ulonglong)lVar5 >> 0x20),local_54,local_58,local_5c);
  iVar4 = FUN_08011038((uint)local_54[0],(uint)local_58[0],(uint)local_5c[0]);
  return iVar4;
}


/* ---------------------------------------------------------------------
 * FUN_080117bc   (0x080117BC, 105 Bytes)
 * Body: 0x080117BC-0x08011825
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_080117bc(int param_1,uint param_2,uint param_3)

{
  _DAT_200015b4 = (param_1 << 8 | param_2) << 8 | param_3;
  _DAT_200015b4 = FUN_080116fc((uint)DAT_2000032a,_DAT_200015b4);
  DAT_200015f0 = 1;
  DAT_200015f1 = 0;
  DAT_20001601 = 0;
  DAT_20001600 = 0;
  _DAT_200015f4 = 2;
  DAT_200015f8 = 100;
  DAT_20001602 = 0;
  FUN_08010ff8((undefined4 *)0x200015fc);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08011826   (0x08011826, 161 Bytes)
 * Body: 0x08011826-0x080118C7
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08011826(undefined4 param_1,undefined1 param_2,undefined1 param_3)

{
  _DAT_200016f4 = FUN_080116fc((uint)DAT_2000032a,0xff0000);
  _DAT_200016f8 = FUN_080116fc((uint)DAT_2000032a,0xff7f00);
  _DAT_200016fc = FUN_080116fc((uint)DAT_2000032a,0xffff00);
  _DAT_20001700 = FUN_080116fc((uint)DAT_2000032a,0xff00);
  _DAT_20001704 = FUN_080116fc((uint)DAT_2000032a,0xffff);
  _DAT_20001708 = FUN_080116fc((uint)DAT_2000032a,0xff);
  _DAT_2000170c = FUN_080116fc((uint)DAT_2000032a,0xff00ff);
  DAT_20001730 = 7;
  DAT_20001741 = 0;
  DAT_20001738 = 100;
  DAT_20001742 = 0;
  DAT_20001731 = param_2;
  _DAT_20001734 = param_1;
  DAT_20001740 = param_3;
  FUN_08010ff8((undefined4 *)0x2000173c);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_080118c8   (0x080118C8, 41 Bytes)
 * Body: 0x080118C8-0x080118F1
 * --------------------------------------------------------------------- */
void FUN_080118c8(int param_1)

{
  if (param_1 == 2) {
    FUN_08011826(5,0,0);
  }
  else if (param_1 == 3) {
    FUN_08011826(5,0,1);
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_080118f2   (0x080118F2, 696 Bytes, 4 Teile)
 * Body: 0x080118F2-0x08011901, 0x08011908-0x08011AF5, 0x08011AF8-0x08011B53, 0x08011B74-0x08011BD5
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_080118f2(undefined4 param_1)

{
  switch(param_1) {
  case 0x1e:
    _DAT_20001564 = FUN_080116fc((uint)DAT_2000032a,0xff0000);
    _DAT_20001568 = FUN_080116fc((uint)DAT_2000032a,0xff7f00);
    _DAT_2000156c = FUN_080116fc((uint)DAT_2000032a,0xffff00);
    _DAT_20001570 = FUN_080116fc((uint)DAT_2000032a,0xff00);
    _DAT_20001574 = FUN_080116fc((uint)DAT_2000032a,0xffff);
    _DAT_20001578 = FUN_080116fc((uint)DAT_2000032a,0xff);
    _DAT_2000157c = FUN_080116fc((uint)DAT_2000032a,0xff00ff);
    DAT_200015a0 = 7;
    DAT_200015a1 = 0;
    DAT_200015b1 = 0;
    DAT_200015b0 = 0;
    _DAT_200015a4 = 5;
    DAT_200015a8 = 100;
    DAT_200015b2 = 0;
    FUN_08010ff8((undefined4 *)0x200015ac);
    break;
  case 0x1f:
    _DAT_2000157c = FUN_080116fc((uint)DAT_2000032a,0xff0000);
    _DAT_20001578 = FUN_080116fc((uint)DAT_2000032a,0xff7f00);
    _DAT_20001574 = FUN_080116fc((uint)DAT_2000032a,0xffff00);
    _DAT_20001570 = FUN_080116fc((uint)DAT_2000032a,0xff00);
    _DAT_2000156c = FUN_080116fc((uint)DAT_2000032a,0xffff);
    _DAT_20001568 = FUN_080116fc((uint)DAT_2000032a,0xff);
    _DAT_20001564 = FUN_080116fc((uint)DAT_2000032a,0xff00ff);
    DAT_200015a0 = 7;
    DAT_200015a1 = 0;
    DAT_200015b1 = 0;
    DAT_200015b0 = 1;
    _DAT_200015a4 = 5;
    DAT_200015a8 = 100;
    DAT_200015b2 = 0;
    FUN_08010ff8((undefined4 *)0x200015ac);
    break;
  case 0x20:
    _DAT_20001564 = FUN_080116fc((uint)DAT_2000032a,0xff0000);
    _DAT_20001568 = FUN_080116fc((uint)DAT_2000032a,0xff00);
    _DAT_2000156c = FUN_080116fc((uint)DAT_2000032a,0xff);
    DAT_200015a0 = 3;
    DAT_200015a1 = 0;
    DAT_200015b1 = 0;
    DAT_200015b0 = 0;
    _DAT_200015a4 = 5;
    DAT_200015a8 = 100;
    DAT_200015b2 = 0;
    FUN_08010ff8((undefined4 *)0x200015ac);
    break;
  case 0x21:
    _DAT_2000156c = FUN_080116fc((uint)DAT_2000032a,0xff0000);
    _DAT_20001568 = FUN_080116fc((uint)DAT_2000032a,0xff00);
    _DAT_20001564 = FUN_080116fc((uint)DAT_2000032a,0xff);
    DAT_200015a0 = 3;
    DAT_200015a1 = 0;
    DAT_200015b1 = 0;
    DAT_200015b0 = 1;
    _DAT_200015a4 = 5;
    DAT_200015a8 = 100;
    DAT_200015b2 = 0;
    FUN_08010ff8((undefined4 *)0x200015ac);
    break;
  case 0x22:
    _DAT_20001564 = FUN_080116fc((uint)DAT_2000032a,0xffff00);
    _DAT_20001568 = FUN_080116fc((uint)DAT_2000032a,0xffff);
    _DAT_2000156c = FUN_080116fc((uint)DAT_2000032a,0xff00ff);
    DAT_200015a0 = 3;
    DAT_200015a1 = 0;
    DAT_200015b1 = 0;
    DAT_200015b0 = 0;
    _DAT_200015a4 = 5;
    DAT_200015a8 = 100;
    DAT_200015b2 = 0;
    FUN_08010ff8((undefined4 *)0x200015ac);
    break;
  case 0x23:
    _DAT_2000156c = FUN_080116fc((uint)DAT_2000032a,0xffff00);
    _DAT_20001568 = FUN_080116fc((uint)DAT_2000032a,0xffff);
    _DAT_20001564 = FUN_080116fc((uint)DAT_2000032a,0xff00ff);
    DAT_200015a0 = 3;
    DAT_200015a1 = 0;
    DAT_200015b1 = 0;
    DAT_200015b0 = 1;
    _DAT_200015a4 = 5;
    DAT_200015a8 = 100;
    DAT_200015b2 = 0;
    FUN_08010ff8((undefined4 *)0x200015ac);
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08011bd2   (0x08011BD2, 3 Bytes)
 * Body: 0x08011BD2-0x08011BD5
 * --------------------------------------------------------------------- */
void FUN_08011bd2(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08011bd6   (0x08011BD6, 2050 Bytes, 4 Teile)
 * Body: 0x08011BD6-0x08011BE5, 0x08011C16-0x08011F53, 0x08011F68-0x08012361, 0x08012374-0x08012431
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08011bd6(undefined4 param_1)

{
  switch(param_1) {
  case 0x18:
    _DAT_20001514 = FUN_080116fc((uint)DAT_2000032a,0xff0000);
    _DAT_20001518 = FUN_080116fc((uint)DAT_2000032a,0xff7f00);
    _DAT_2000151c = FUN_080116fc((uint)DAT_2000032a,0xffff00);
    _DAT_20001520 = FUN_080116fc((uint)DAT_2000032a,0xff00);
    _DAT_20001524 = FUN_080116fc((uint)DAT_2000032a,0xffff);
    _DAT_20001528 = FUN_080116fc((uint)DAT_2000032a,0xff);
    _DAT_2000152c = FUN_080116fc((uint)DAT_2000032a,0xff00ff);
    DAT_20001550 = 7;
    DAT_20001551 = 0;
    DAT_20001561 = 0;
    DAT_20001560 = 0;
    _DAT_20001554 = 2;
    DAT_20001558 = 100;
    DAT_20001562 = 0;
    FUN_08010ff8((undefined4 *)0x2000155c);
  default:
    break;
  case 0x19:
    _DAT_20001514 = FUN_080116fc((uint)DAT_2000032a,0xff0000);
    _DAT_20001518 = FUN_080116fc((uint)DAT_2000032a,0xff7f00);
    _DAT_2000151c = FUN_080116fc((uint)DAT_2000032a,0xffff00);
    _DAT_20001520 = FUN_080116fc((uint)DAT_2000032a,0xff00);
    _DAT_20001524 = FUN_080116fc((uint)DAT_2000032a,0xffff);
    _DAT_20001528 = FUN_080116fc((uint)DAT_2000032a,0xff);
    _DAT_2000152c = FUN_080116fc((uint)DAT_2000032a,0xff00ff);
    DAT_20001550 = 7;
    DAT_20001551 = 0;
    DAT_20001561 = 0;
    DAT_20001560 = 1;
    _DAT_20001554 = 2;
    DAT_20001558 = 100;
    DAT_20001562 = 0;
    FUN_08010ff8((undefined4 *)0x2000155c);
    break;
  case 0x1a:
    _DAT_20001514 = FUN_080116fc((uint)DAT_2000032a,0xff0000);
    _DAT_20001518 = FUN_080116fc((uint)DAT_2000032a,0xff00);
    _DAT_2000151c = FUN_080116fc((uint)DAT_2000032a,0xff);
    DAT_20001550 = 3;
    DAT_20001551 = 0;
    DAT_20001561 = 0;
    DAT_20001560 = 0;
    _DAT_20001554 = 2;
    DAT_20001558 = 100;
    DAT_20001562 = 0;
    FUN_08010ff8((undefined4 *)0x2000155c);
    break;
  case 0x1b:
    _DAT_20001514 = FUN_080116fc((uint)DAT_2000032a,0xff0000);
    _DAT_20001518 = FUN_080116fc((uint)DAT_2000032a,0xff00);
    _DAT_2000151c = FUN_080116fc((uint)DAT_2000032a,0xff);
    DAT_20001550 = 3;
    DAT_20001551 = 0;
    DAT_20001561 = 0;
    DAT_20001560 = 1;
    _DAT_20001554 = 2;
    DAT_20001558 = 100;
    DAT_20001562 = 0;
    FUN_08010ff8((undefined4 *)0x2000155c);
    break;
  case 0x1c:
    _DAT_20001514 = FUN_080116fc((uint)DAT_2000032a,0xffff00);
    _DAT_20001518 = FUN_080116fc((uint)DAT_2000032a,0xffff);
    _DAT_2000151c = FUN_080116fc((uint)DAT_2000032a,0xff00ff);
    DAT_20001550 = 3;
    DAT_20001551 = 0;
    DAT_20001561 = 0;
    DAT_20001560 = 0;
    _DAT_20001554 = 2;
    DAT_20001558 = 100;
    DAT_20001562 = 0;
    FUN_08010ff8((undefined4 *)0x2000155c);
    break;
  case 0x1d:
    _DAT_20001514 = FUN_080116fc((uint)DAT_2000032a,0xffff00);
    _DAT_20001518 = FUN_080116fc((uint)DAT_2000032a,0xffff);
    _DAT_2000151c = FUN_080116fc((uint)DAT_2000032a,0xff00ff);
    DAT_20001550 = 3;
    DAT_20001551 = 0;
    DAT_20001561 = 0;
    DAT_20001560 = 1;
    _DAT_20001554 = 2;
    DAT_20001558 = 100;
    DAT_20001562 = 0;
    FUN_08010ff8((undefined4 *)0x2000155c);
    break;
  case 0x24:
    _DAT_20001514 = FUN_080116fc((uint)DAT_2000032a,0xff0000);
    _DAT_20001518 = FUN_080116fc((uint)DAT_2000032a,0xff7f00);
    _DAT_2000151c = FUN_080116fc((uint)DAT_2000032a,0xffff00);
    _DAT_20001520 = FUN_080116fc((uint)DAT_2000032a,0xff00);
    _DAT_20001524 = FUN_080116fc((uint)DAT_2000032a,0xffff);
    _DAT_20001528 = FUN_080116fc((uint)DAT_2000032a,0xff);
    _DAT_2000152c = FUN_080116fc((uint)DAT_2000032a,0xff00ff);
    DAT_20001550 = 7;
    DAT_20001551 = 0;
    DAT_20001561 = 0;
    DAT_20001560 = 0;
    _DAT_20001554 = 5;
    DAT_20001558 = 100;
    DAT_20001562 = 0;
    FUN_08010ff8((undefined4 *)0x2000155c);
    break;
  case 0x25:
    _DAT_20001514 = FUN_080116fc((uint)DAT_2000032a,0xff0000);
    _DAT_20001518 = FUN_080116fc((uint)DAT_2000032a,0xff7f00);
    _DAT_2000151c = FUN_080116fc((uint)DAT_2000032a,0xffff00);
    _DAT_20001520 = FUN_080116fc((uint)DAT_2000032a,0xff00);
    _DAT_20001524 = FUN_080116fc((uint)DAT_2000032a,0xffff);
    _DAT_20001528 = FUN_080116fc((uint)DAT_2000032a,0xff);
    _DAT_2000152c = FUN_080116fc((uint)DAT_2000032a,0xff00ff);
    DAT_20001550 = 7;
    DAT_20001551 = 0;
    DAT_20001561 = 0;
    DAT_20001560 = 1;
    _DAT_20001554 = 5;
    DAT_20001558 = 100;
    DAT_20001562 = 0;
    FUN_08010ff8((undefined4 *)0x2000155c);
    break;
  case 0x26:
    _DAT_20001514 = FUN_080116fc((uint)DAT_2000032a,0xff0000);
    _DAT_20001518 = FUN_080116fc((uint)DAT_2000032a,0xff00);
    _DAT_2000151c = FUN_080116fc((uint)DAT_2000032a,0xff);
    DAT_20001550 = 3;
    DAT_20001551 = 0;
    DAT_20001561 = 0;
    DAT_20001560 = 0;
    _DAT_20001554 = 5;
    DAT_20001558 = 100;
    DAT_20001562 = 0;
    FUN_08010ff8((undefined4 *)0x2000155c);
    break;
  case 0x27:
    _DAT_20001514 = FUN_080116fc((uint)DAT_2000032a,0xff0000);
    _DAT_20001518 = FUN_080116fc((uint)DAT_2000032a,0xff00);
    _DAT_2000151c = FUN_080116fc((uint)DAT_2000032a,0xff);
    DAT_20001550 = 3;
    DAT_20001551 = 0;
    DAT_20001561 = 0;
    DAT_20001560 = 1;
    _DAT_20001554 = 5;
    DAT_20001558 = 100;
    DAT_20001562 = 0;
    FUN_08010ff8((undefined4 *)0x2000155c);
    break;
  case 0x28:
    _DAT_20001514 = FUN_080116fc((uint)DAT_2000032a,0xffff00);
    _DAT_20001518 = FUN_080116fc((uint)DAT_2000032a,0xffff);
    _DAT_2000151c = FUN_080116fc((uint)DAT_2000032a,0xff00ff);
    DAT_20001550 = 3;
    DAT_20001551 = 0;
    DAT_20001561 = 0;
    DAT_20001560 = 0;
    _DAT_20001554 = 5;
    DAT_20001558 = 100;
    DAT_20001562 = 0;
    FUN_08010ff8((undefined4 *)0x2000155c);
    break;
  case 0x29:
    _DAT_20001514 = FUN_080116fc((uint)DAT_2000032a,0xffff00);
    _DAT_20001518 = FUN_080116fc((uint)DAT_2000032a,0xffff);
    _DAT_2000151c = FUN_080116fc((uint)DAT_2000032a,0xff00ff);
    DAT_20001550 = 3;
    DAT_20001551 = 0;
    DAT_20001561 = 0;
    DAT_20001560 = 1;
    _DAT_20001554 = 5;
    DAT_20001558 = 100;
    DAT_20001562 = 0;
    FUN_08010ff8((undefined4 *)0x2000155c);
    break;
  case 0x2a:
    _DAT_20001514 = FUN_080116fc((uint)DAT_2000032a,0xff0000);
    _DAT_20001518 = FUN_080116fc((uint)DAT_2000032a,0xff7f00);
    _DAT_2000151c = FUN_080116fc((uint)DAT_2000032a,0xffff00);
    _DAT_20001520 = FUN_080116fc((uint)DAT_2000032a,0xff00);
    _DAT_20001524 = FUN_080116fc((uint)DAT_2000032a,0xffff);
    _DAT_20001528 = FUN_080116fc((uint)DAT_2000032a,0xff);
    _DAT_2000152c = FUN_080116fc((uint)DAT_2000032a,0xff00ff);
    DAT_20001550 = 7;
    DAT_20001551 = 0;
    DAT_20001561 = 0;
    DAT_20001560 = 0;
    _DAT_20001554 = 10;
    DAT_20001558 = 100;
    DAT_20001562 = 0;
    FUN_08010ff8((undefined4 *)0x2000155c);
    break;
  case 0x2b:
    _DAT_20001514 = FUN_080116fc((uint)DAT_2000032a,0xff0000);
    _DAT_20001518 = FUN_080116fc((uint)DAT_2000032a,0xff7f00);
    _DAT_2000151c = FUN_080116fc((uint)DAT_2000032a,0xffff00);
    _DAT_20001520 = FUN_080116fc((uint)DAT_2000032a,0xff00);
    _DAT_20001524 = FUN_080116fc((uint)DAT_2000032a,0xffff);
    _DAT_20001528 = FUN_080116fc((uint)DAT_2000032a,0xff);
    _DAT_2000152c = FUN_080116fc((uint)DAT_2000032a,0xff00ff);
    DAT_20001550 = 7;
    DAT_20001551 = 0;
    DAT_20001561 = 0;
    DAT_20001560 = 1;
    _DAT_20001554 = 10;
    DAT_20001558 = 100;
    DAT_20001562 = 0;
    FUN_08010ff8((undefined4 *)0x2000155c);
    break;
  case 0x2c:
    _DAT_20001514 = FUN_080116fc((uint)DAT_2000032a,0xff0000);
    _DAT_20001518 = FUN_080116fc((uint)DAT_2000032a,0xff00);
    _DAT_2000151c = FUN_080116fc((uint)DAT_2000032a,0xff);
    DAT_20001550 = 3;
    DAT_20001551 = 0;
    DAT_20001561 = 0;
    DAT_20001560 = 0;
    _DAT_20001554 = 10;
    DAT_20001558 = 100;
    DAT_20001562 = 0;
    FUN_08010ff8((undefined4 *)0x2000155c);
    break;
  case 0x2d:
    _DAT_20001514 = FUN_080116fc((uint)DAT_2000032a,0xff0000);
    _DAT_20001518 = FUN_080116fc((uint)DAT_2000032a,0xff00);
    _DAT_2000151c = FUN_080116fc((uint)DAT_2000032a,0xff);
    DAT_20001550 = 3;
    DAT_20001551 = 0;
    DAT_20001561 = 0;
    DAT_20001560 = 1;
    _DAT_20001554 = 10;
    DAT_20001558 = 100;
    DAT_20001562 = 0;
    FUN_08010ff8((undefined4 *)0x2000155c);
    break;
  case 0x2e:
    _DAT_20001514 = FUN_080116fc((uint)DAT_2000032a,0xffff00);
    _DAT_20001518 = FUN_080116fc((uint)DAT_2000032a,0xffff);
    _DAT_2000151c = FUN_080116fc((uint)DAT_2000032a,0xff00ff);
    DAT_20001550 = 3;
    DAT_20001551 = 0;
    DAT_20001561 = 0;
    DAT_20001560 = 0;
    _DAT_20001554 = 10;
    DAT_20001558 = 100;
    DAT_20001562 = 0;
    FUN_08010ff8((undefined4 *)0x2000155c);
    break;
  case 0x2f:
    _DAT_20001514 = FUN_080116fc((uint)DAT_2000032a,0xffff00);
    _DAT_20001518 = FUN_080116fc((uint)DAT_2000032a,0xffff);
    _DAT_2000151c = FUN_080116fc((uint)DAT_2000032a,0xff00ff);
    DAT_20001550 = 3;
    DAT_20001551 = 0;
    DAT_20001561 = 0;
    DAT_20001560 = 1;
    _DAT_20001554 = 10;
    DAT_20001558 = 100;
    DAT_20001562 = 0;
    FUN_08010ff8((undefined4 *)0x2000155c);
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801242e   (0x0801242E, 3 Bytes)
 * Body: 0x0801242E-0x08012431
 * --------------------------------------------------------------------- */
void FUN_0801242e(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08012432   (0x08012432, 448 Bytes, 2 Teile)
 * Body: 0x08012432-0x08012441, 0x0801244A-0x080125FB
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08012432(undefined4 param_1)

{
  switch(param_1) {
  case 0x11:
    _DAT_200014c4 = FUN_080116fc((uint)DAT_2000032a,0xff0000);
    DAT_20001500 = 1;
    DAT_20001501 = 0;
    DAT_20001511 = 0;
    DAT_20001510 = 0;
    _DAT_20001504 = 10;
    DAT_20001508 = 100;
    DAT_20001512 = 0;
    FUN_08010ff8((undefined4 *)0x2000150c);
    break;
  case 0x12:
    _DAT_200014c4 = FUN_080116fc((uint)DAT_2000032a,0xff00);
    DAT_20001500 = 1;
    DAT_20001501 = 0;
    DAT_20001511 = 0;
    DAT_20001510 = 0;
    _DAT_20001504 = 10;
    DAT_20001508 = 100;
    DAT_20001512 = 0;
    FUN_08010ff8((undefined4 *)0x2000150c);
    break;
  case 0x13:
    _DAT_200014c4 = FUN_080116fc((uint)DAT_2000032a,0xff);
    DAT_20001500 = 1;
    DAT_20001501 = 0;
    DAT_20001511 = 0;
    DAT_20001510 = 0;
    _DAT_20001504 = 10;
    DAT_20001508 = 100;
    DAT_20001512 = 0;
    FUN_08010ff8((undefined4 *)0x2000150c);
    break;
  case 0x14:
    _DAT_200014c4 = FUN_080116fc((uint)DAT_2000032a,0xffff00);
    DAT_20001500 = 1;
    DAT_20001501 = 0;
    DAT_20001511 = 0;
    DAT_20001510 = 0;
    _DAT_20001504 = 10;
    DAT_20001508 = 100;
    DAT_20001512 = 0;
    FUN_08010ff8((undefined4 *)0x2000150c);
    break;
  case 0x15:
    _DAT_200014c4 = FUN_080116fc((uint)DAT_2000032a,0xffff);
    DAT_20001500 = 1;
    DAT_20001501 = 0;
    DAT_20001511 = 0;
    DAT_20001510 = 0;
    _DAT_20001504 = 10;
    DAT_20001508 = 100;
    DAT_20001512 = 0;
    FUN_08010ff8((undefined4 *)0x2000150c);
    break;
  case 0x16:
    _DAT_200014c4 = FUN_080116fc((uint)DAT_2000032a,0xff00ff);
    DAT_20001500 = 1;
    DAT_20001501 = 0;
    DAT_20001511 = 0;
    DAT_20001510 = 0;
    _DAT_20001504 = 10;
    DAT_20001508 = 100;
    DAT_20001512 = 0;
    FUN_08010ff8((undefined4 *)0x2000150c);
    break;
  case 0x17:
    _DAT_200014c4 = FUN_080116fc((uint)DAT_2000032a,0xffffff);
    DAT_20001500 = 1;
    DAT_20001501 = 0;
    DAT_20001511 = 0;
    DAT_20001510 = 0;
    _DAT_20001504 = 10;
    DAT_20001508 = 100;
    DAT_20001512 = 0;
    FUN_08010ff8((undefined4 *)0x2000150c);
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_080125fc   (0x080125FC, 541 Bytes, 3 Teile)
 * Body: 0x080125FC-0x0801260B, 0x08012612-0x0801276B, 0x08012780-0x08012835
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_080125fc(undefined4 param_1)

{
  switch(param_1) {
  case 0xb:
    _DAT_20001474 = FUN_080116fc((uint)DAT_2000032a,0xff0000);
    _DAT_20001478 = FUN_080116fc((uint)DAT_2000032a,0xffff00);
    _DAT_2000147c = FUN_080116fc((uint)DAT_2000032a,0xff00);
    _DAT_20001480 = FUN_080116fc((uint)DAT_2000032a,0xffff);
    _DAT_20001484 = FUN_080116fc((uint)DAT_2000032a,0xff);
    _DAT_20001488 = FUN_080116fc((uint)DAT_2000032a,0xff00ff);
    DAT_200014b0 = 6;
    DAT_200014b1 = 0;
    DAT_200014c1 = 0;
    DAT_200014c0 = 0;
    _DAT_200014b4 = 6;
    DAT_200014b8 = 100;
    DAT_200014c2 = 0;
    FUN_08010ff8((undefined4 *)0x200014bc);
    break;
  case 0xc:
    _DAT_20001474 = FUN_080116fc((uint)DAT_2000032a,0xff0000);
    _DAT_20001478 = FUN_080116fc((uint)DAT_2000032a,0xffff00);
    DAT_200014b0 = 2;
    DAT_200014b1 = 0;
    DAT_200014c1 = 0;
    DAT_200014c0 = 0;
    _DAT_200014b4 = 6;
    DAT_200014b8 = 100;
    DAT_200014c2 = 0;
    FUN_08010ff8((undefined4 *)0x200014bc);
    break;
  case 0xd:
    _DAT_20001474 = FUN_080116fc((uint)DAT_2000032a,0xff0000);
    _DAT_20001478 = FUN_080116fc((uint)DAT_2000032a,0xff00ff);
    DAT_200014b0 = 2;
    DAT_200014b1 = 0;
    DAT_200014c1 = 0;
    DAT_200014c0 = 0;
    _DAT_200014b4 = 6;
    DAT_200014b8 = 100;
    DAT_200014c2 = 0;
    FUN_08010ff8((undefined4 *)0x200014bc);
    break;
  case 0xe:
    _DAT_20001474 = FUN_080116fc((uint)DAT_2000032a,0xff00);
    _DAT_20001478 = FUN_080116fc((uint)DAT_2000032a,0xffff);
    DAT_200014b0 = 2;
    DAT_200014b1 = 0;
    DAT_200014c1 = 0;
    DAT_200014c0 = 0;
    _DAT_200014b4 = 6;
    DAT_200014b8 = 100;
    DAT_200014c2 = 0;
    FUN_08010ff8((undefined4 *)0x200014bc);
    break;
  case 0xf:
    _DAT_20001474 = FUN_080116fc((uint)DAT_2000032a,0xff00);
    _DAT_20001478 = FUN_080116fc((uint)DAT_2000032a,0xffff00);
    DAT_200014b0 = 2;
    DAT_200014b1 = 0;
    DAT_200014c1 = 0;
    DAT_200014c0 = 0;
    _DAT_200014b4 = 6;
    DAT_200014b8 = 100;
    DAT_200014c2 = 0;
    FUN_08010ff8((undefined4 *)0x200014bc);
    break;
  case 0x10:
    _DAT_20001474 = FUN_080116fc((uint)DAT_2000032a,0xff);
    _DAT_20001478 = FUN_080116fc((uint)DAT_2000032a,0xff00ff);
    DAT_200014b0 = 2;
    DAT_200014b1 = 0;
    DAT_200014c1 = 0;
    DAT_200014c0 = 0;
    _DAT_200014b4 = 6;
    DAT_200014b8 = 100;
    DAT_200014c2 = 0;
    FUN_08010ff8((undefined4 *)0x200014bc);
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08012836   (0x08012836, 868 Bytes, 4 Teile)
 * Body: 0x08012836-0x08012843, 0x0801284C-0x08012A27, 0x08012A2A-0x08012B95, 0x08012BAC-0x08012BBD
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08012836(undefined4 param_1)

{
  switch(param_1) {
  case 4:
    _DAT_200013d4 = FUN_080116fc((uint)DAT_2000032a,0xff0000);
    _DAT_200013d8 = FUN_080116fc((uint)DAT_2000032a,0xff7f00);
    _DAT_200013dc = FUN_080116fc((uint)DAT_2000032a,0xffff00);
    _DAT_200013e0 = FUN_080116fc((uint)DAT_2000032a,0xff00);
    _DAT_200013e4 = FUN_080116fc((uint)DAT_2000032a,0xffff);
    _DAT_200013e8 = FUN_080116fc((uint)DAT_2000032a,0xff);
    _DAT_200013ec = FUN_080116fc((uint)DAT_2000032a,0xff00ff);
    DAT_20001410 = 7;
    DAT_20001411 = 0;
    DAT_20001420 = 0;
    _DAT_20001414 = 0x32;
    DAT_20001418 = 100;
    DAT_20001422 = 0;
    FUN_08010ff8((undefined4 *)0x2000141c);
    break;
  case 5:
    _DAT_200013d4 = FUN_080116fc((uint)DAT_2000032a,0xff0000);
    _DAT_200013d8 = FUN_080116fc((uint)DAT_2000032a,0xff7f00);
    _DAT_200013dc = FUN_080116fc((uint)DAT_2000032a,0xffff00);
    _DAT_200013e0 = FUN_080116fc((uint)DAT_2000032a,0xff00);
    _DAT_200013e4 = FUN_080116fc((uint)DAT_2000032a,0xffff);
    _DAT_200013e8 = FUN_080116fc((uint)DAT_2000032a,0xff);
    _DAT_200013ec = FUN_080116fc((uint)DAT_2000032a,0xff00ff);
    DAT_20001410 = 7;
    DAT_20001411 = 0;
    DAT_20001420 = 0;
    _DAT_20001414 = 0x19;
    DAT_20001418 = 100;
    DAT_20001422 = 0;
    FUN_08010ff8((undefined4 *)0x2000141c);
    break;
  case 6:
    _DAT_200013d4 = FUN_080116fc((uint)DAT_2000032a,0xff0000);
    _DAT_200013d8 = FUN_080116fc((uint)DAT_2000032a,0xff00);
    _DAT_200013dc = FUN_080116fc((uint)DAT_2000032a,0xff);
    DAT_20001410 = 3;
    DAT_20001411 = 0;
    DAT_20001420 = 0;
    _DAT_20001414 = 0x19;
    DAT_20001418 = 100;
    DAT_20001422 = 0;
    FUN_08010ff8((undefined4 *)0x2000141c);
    break;
  case 7:
    _DAT_200013d4 = FUN_080116fc((uint)DAT_2000032a,0xffff00);
    _DAT_200013d8 = FUN_080116fc((uint)DAT_2000032a,0xffff);
    _DAT_200013dc = FUN_080116fc((uint)DAT_2000032a,0xff00ff);
    DAT_20001410 = 3;
    DAT_20001411 = 0;
    DAT_20001420 = 0;
    _DAT_20001414 = 0x19;
    DAT_20001418 = 100;
    DAT_20001422 = 0;
    FUN_08010ff8((undefined4 *)0x2000141c);
    break;
  case 8:
    _DAT_200013d4 = FUN_080116fc((uint)DAT_2000032a,0xff0000);
    _DAT_200013d8 = 0;
    _DAT_200013dc = FUN_080116fc((uint)DAT_2000032a,0xff7f00);
    _DAT_200013e0 = 0;
    _DAT_200013e4 = FUN_080116fc((uint)DAT_2000032a,0xffff00);
    _DAT_200013e8 = 0;
    _DAT_200013ec = FUN_080116fc((uint)DAT_2000032a,0xff00);
    _DAT_200013f0 = 0;
    _DAT_200013f4 = FUN_080116fc((uint)DAT_2000032a,0xffff);
    _DAT_200013f8 = 0;
    _DAT_200013fc = FUN_080116fc((uint)DAT_2000032a,0xff);
    _DAT_20001400 = 0;
    _DAT_20001404 = FUN_080116fc((uint)DAT_2000032a,0xff00ff);
    _DAT_20001408 = 0;
    DAT_20001410 = 0xe;
    DAT_20001411 = 0;
    DAT_20001420 = 0;
    _DAT_20001414 = 0x32;
    DAT_20001418 = 100;
    DAT_20001422 = 0;
    FUN_08010ff8((undefined4 *)0x2000141c);
    break;
  case 9:
    _DAT_200013d4 = FUN_080116fc((uint)DAT_2000032a,0xff0000);
    _DAT_200013d8 = 0;
    _DAT_200013dc = FUN_080116fc((uint)DAT_2000032a,0xff00);
    _DAT_200013e0 = 0;
    _DAT_200013e4 = FUN_080116fc((uint)DAT_2000032a,0xff);
    _DAT_200013e8 = 0;
    DAT_20001410 = 6;
    DAT_20001411 = 0;
    DAT_20001420 = 0;
    _DAT_20001414 = 0x32;
    DAT_20001418 = 100;
    DAT_20001422 = 0;
    FUN_08010ff8((undefined4 *)0x2000141c);
    break;
  case 10:
    _DAT_200013d4 = FUN_080116fc((uint)DAT_2000032a,0xffff00);
    _DAT_200013d8 = 0;
    _DAT_200013dc = FUN_080116fc((uint)DAT_2000032a,0xffff);
    _DAT_200013e0 = 0;
    _DAT_200013e4 = FUN_080116fc((uint)DAT_2000032a,0xff00ff);
    _DAT_200013e8 = 0;
    DAT_20001410 = 6;
    DAT_20001411 = 0;
    DAT_20001420 = 0;
    _DAT_20001414 = 0x32;
    DAT_20001418 = 100;
    DAT_20001422 = 0;
    FUN_08010ff8((undefined4 *)0x2000141c);
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08012bbe   (0x08012BBE, 101 Bytes)
 * Body: 0x08012BBE-0x08012C23
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08012bbe(void)

{
  FUN_080117bc(0,0,0);
  _DAT_40010c28 = 0x2000;
  FUN_08012836((uint)DAT_20000320);
  FUN_080125fc((uint)DAT_20000320);
  FUN_08012432((uint)DAT_20000320);
  FUN_08011bd6((uint)DAT_20000320);
  FUN_080118f2((uint)DAT_20000320);
  FUN_080118c8((uint)DAT_20000320);
  FUN_080117bc((uint)DAT_20000321,(uint)DAT_20000322,(uint)DAT_20000323);
  FUN_08011030();
  FUN_08010ffe();
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08012c24   (0x08012C24, 1 Bytes)
 * Body: 0x08012C24-0x08012C25
 * --------------------------------------------------------------------- */
void FUN_08012c24(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08012c26   (0x08012C26, 35 Bytes)
 * Body: 0x08012C26-0x08012C49
 * --------------------------------------------------------------------- */
void FUN_08012c26(void)

{
  byte bVar1;
  
  for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
    FUN_08012c24();
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08012c52   (0x08012C52, 173 Bytes)
 * Body: 0x08012C52-0x08012CFF
 * --------------------------------------------------------------------- */
void FUN_08012c52(void)

{
  byte bVar1;
  
  for (bVar1 = 0; bVar1 < 3; bVar1 = bVar1 + 1) {
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08012d00   (0x08012D00, 453 Bytes)
 * Body: 0x08012D00-0x08012EC5
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08012d00(void)

{
  byte bVar1;
  
  for (bVar1 = 0; bVar1 < 0x18; bVar1 = bVar1 + 1) {
    _DAT_40010c28 = 0x8000;
    _DAT_40010c18 = 0x8000;
  }
  FUN_08012c52();
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08012ec6   (0x08012EC6, 452 Bytes, 2 Teile)
 * Body: 0x08012EC6-0x08012FB7, 0x08012FCE-0x080130A1
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08012ec6(void)

{
  byte bVar1;
  
  for (bVar1 = 0; bVar1 < 0x18; bVar1 = bVar1 + 1) {
    _DAT_40010c28 = 0x4000;
    _DAT_40010c18 = 0x4000;
  }
  FUN_08012c52();
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08012fb6   (0x08012FB6, 212 Bytes, 2 Teile)
 * Body: 0x08012FB6-0x08012FB7, 0x08012FCE-0x080130A1
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08012fb6(void)

{
  uint unaff_r4;
  uint unaff_r8;
  
  while (unaff_r4 = unaff_r4 + 1 & 0xff, unaff_r4 < 0x18) {
    if ((0x800000 >> unaff_r4 & unaff_r8) == 0) {
      _DAT_40010c18 = 0x4000;
      _DAT_40010c28 = 0x4000;
    }
    else {
      _DAT_40010c18 = 0x4000;
      _DAT_40010c28 = 0x4000;
    }
  }
  FUN_08012c52();
  return;
}


/* ---------------------------------------------------------------------
 * FUN_080130a2   (0x080130A2, 453 Bytes)
 * Body: 0x080130A2-0x08013267
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_080130a2(void)

{
  byte bVar1;
  
  for (bVar1 = 0; bVar1 < 0x18; bVar1 = bVar1 + 1) {
    _DAT_40010c28 = 0x2000;
    _DAT_40010c18 = 0x2000;
  }
  FUN_08012c52();
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08013268   (0x08013268, 5 Bytes)
 * Body: 0x08013268-0x0801326D
 * --------------------------------------------------------------------- */
void FUN_08013268(undefined4 *param_1)

{
  *param_1 = 1;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801326e   (0x0801326E, 25 Bytes)
 * Body: 0x0801326E-0x08013287
 * --------------------------------------------------------------------- */
undefined4 FUN_0801326e(uint *param_1,uint param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((*param_1 != 0) && (*param_1 = *param_1 + 1, param_2 < *param_1)) {
    uVar1 = 1;
    *param_1 = param_2;
  }
  return uVar1;
}


/* ---------------------------------------------------------------------
 * FUN_08013288   (0x08013288, 151 Bytes)
 * Body: 0x08013288-0x0801331F
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08013288(void)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = FUN_0801326e((uint *)0x2000164c,_DAT_20001644);
  if ((iVar2 == 1) && (FUN_08013268((undefined4 *)0x2000164c), DAT_20001641 < 3)) {
    DAT_20001641 = DAT_20001641 + 1;
    FUN_080116f4(_DAT_20001604);
    FUN_080116ec(_DAT_20001604);
    FUN_080116e6((char)_DAT_20001604);
    for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
      FUN_080130a2();
    }
    for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
      FUN_08012ec6();
    }
    for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
      FUN_08012d00();
    }
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08013320   (0x08013320, 151 Bytes)
 * Body: 0x08013320-0x080133B7
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08013320(void)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = FUN_0801326e((uint *)0x200015fc,_DAT_200015f4);
  if ((iVar2 == 1) && (FUN_08013268((undefined4 *)0x200015fc), DAT_200015f1 < 3)) {
    DAT_200015f1 = DAT_200015f1 + 1;
    FUN_080116f4(_DAT_200015b4);
    FUN_080116ec(_DAT_200015b4);
    FUN_080116e6((char)_DAT_200015b4);
    for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
      FUN_080130a2();
    }
    for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
      FUN_08012ec6();
    }
    for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
      FUN_08012d00();
    }
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_080133c4   (0x080133C4, 304 Bytes, 2 Teile)
 * Body: 0x080133C4-0x080134E1, 0x080134E8-0x080134FB
 * --------------------------------------------------------------------- */
void FUN_080133c4(void)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  undefined4 auStack_30 [7];
  
  FUN_0801d2ec(auStack_30,(undefined4 *)&DAT_0801d9d0,0x1c);
  if (DAT_20000067 == '\x01') {
    if (DAT_200004e4 != '\x01') {
      DAT_200004e4 = '\x01';
      bVar1 = FUN_080116e6(0);
      uVar2 = FUN_080116ec(0xff0000);
      uVar3 = FUN_080116f4(0xff0000);
      FUN_080117bc(uVar3,uVar2,(uint)bVar1);
    }
  }
  else if (DAT_20000067 == '\x02') {
    if (DAT_200004e4 != '\x02') {
      DAT_200004e4 = '\x02';
      bVar1 = FUN_080116e6(0);
      uVar2 = FUN_080116ec(0xffff00);
      uVar3 = FUN_080116f4(0xffff00);
      FUN_080117bc(uVar3,uVar2,(uint)bVar1);
    }
  }
  else if (DAT_20000067 == '\x03') {
    if (DAT_200004e4 != '\x03') {
      DAT_200004e4 = '\x03';
      bVar1 = FUN_080116e6(0xff);
      uVar2 = FUN_080116ec(0xff);
      uVar3 = FUN_080116f4(0xff);
      FUN_080117bc(uVar3,uVar2,(uint)bVar1);
    }
  }
  else if (DAT_20000067 == '\x04') {
    if (DAT_200004e4 != '\x04') {
      DAT_200004e4 = '\x04';
      bVar1 = FUN_080116e6(0);
      uVar2 = FUN_080116ec(0xff00);
      uVar3 = FUN_080116f4(0xff00);
      FUN_080117bc(uVar3,uVar2,(uint)bVar1);
    }
  }
  else if (DAT_200004e4 != '\0') {
    DAT_200004e4 = '\0';
    FUN_080117bc(0,0,0);
  }
  switch(DAT_200004e4) {
  case '\0':
  case '\x01':
  case '\x02':
  case '\x03':
  case '\x04':
    FUN_08013320();
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_080134fc   (0x080134FC, 83 Bytes)
 * Body: 0x080134FC-0x0801354F
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_080134fc(undefined1 param_1,undefined1 param_2,undefined1 param_3)

{
  *(undefined1 *)((_DAT_20000448 % 0xe) * 3 + 0x20001794) = param_1;
  *(undefined1 *)((_DAT_20000448 % 0xe) * 3 + 0x20001795) = param_2;
  *(undefined1 *)((_DAT_20000448 % 0xe) * 3 + 0x20001796) = param_3;
  _DAT_20000448 = _DAT_20000448 + 1;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08013550   (0x08013550, 933 Bytes, 5 Teile)
 * Body: 0x08013550-0x08013585, 0x0801358E-0x08013653, 0x08013656-0x0801367F, 0x08013688-0x080137C7, 0x080137FC-0x0801393F
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08013550(void)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = FUN_0801326e((uint *)0x2000173c,_DAT_20001734);
  if (iVar2 == 1) {
    FUN_08013268((undefined4 *)0x2000173c);
    if (DAT_20001740 == '\0') {
      switch(DAT_2000049b) {
      case 0:
        DAT_20000498 = DAT_20001708;
        DAT_20000499 = 0;
        DAT_2000049a = 0;
        DAT_2000049b = 1;
        break;
      case 1:
        DAT_20000499 = DAT_20000499 + 1;
        if (_DAT_20001708 - 1U < (uint)DAT_20000499) {
          DAT_20000499 = DAT_20001708;
          DAT_2000049b = 2;
        }
        break;
      case 2:
        DAT_20000498 = DAT_20000498 - 1;
        if (DAT_20000498 == 0) {
          DAT_20000498 = 0;
          DAT_2000049b = 3;
        }
        break;
      case 3:
        DAT_2000049a = DAT_2000049a + 1;
        if (_DAT_20001708 - 1U < (uint)DAT_2000049a) {
          DAT_2000049a = DAT_20001708;
          DAT_2000049b = 4;
        }
        break;
      case 4:
        DAT_20000499 = DAT_20000499 - 1;
        if (DAT_20000499 == 0) {
          DAT_20000499 = 0;
          DAT_2000049b = 5;
        }
        break;
      case 5:
        DAT_20000498 = DAT_20000498 + 1;
        if (_DAT_20001708 - 1U < (uint)DAT_20000498) {
          DAT_20000498 = DAT_20001708;
          DAT_2000049b = 6;
        }
        break;
      case 6:
        DAT_2000049a = DAT_2000049a - 1;
        if (DAT_2000049a == 0) {
          DAT_2000049a = 0;
          DAT_2000049b = 1;
        }
      }
    }
    else {
      switch(DAT_2000049b) {
      case 0:
        DAT_20000498 = 0;
        DAT_20000499 = 0;
        DAT_2000049a = DAT_20001708;
        DAT_2000049b = 1;
        break;
      case 1:
        DAT_20000499 = DAT_20000499 + 1;
        if (_DAT_20001708 - 1U < (uint)DAT_20000499) {
          DAT_20000499 = DAT_20001708;
          DAT_2000049b = 2;
        }
        break;
      case 2:
        DAT_2000049a = DAT_2000049a - 1;
        if (DAT_2000049a == 0) {
          DAT_2000049a = 0;
          DAT_2000049b = 3;
        }
        break;
      case 3:
        DAT_20000498 = DAT_20000498 + 1;
        if (_DAT_20001708 - 1U < (uint)DAT_20000498) {
          DAT_20000498 = DAT_20001708;
          DAT_2000049b = 4;
        }
        break;
      case 4:
        DAT_20000499 = DAT_20000499 - 1;
        if (DAT_20000499 == 0) {
          DAT_20000499 = 0;
          DAT_2000049b = 5;
        }
        break;
      case 5:
        DAT_2000049a = DAT_2000049a + 1;
        if (_DAT_20001708 - 1U < (uint)DAT_2000049a) {
          DAT_2000049a = DAT_20001708;
          DAT_2000049b = 6;
        }
        break;
      case 6:
        DAT_20000498 = DAT_20000498 - 1;
        if (DAT_20000498 == 0) {
          DAT_20000498 = 0;
          DAT_2000049b = 1;
        }
      }
    }
    FUN_080134fc(DAT_20000498,DAT_20000499,DAT_2000049a);
    DAT_2000049c = '\x01';
    DAT_2000049d = 0;
  }
  if (DAT_2000049c != '\0') {
    if (DAT_2000049d == 0) {
      for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
        FUN_080130a2();
      }
    }
    else if (DAT_2000049d == 1) {
      for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
        FUN_08012ec6();
      }
    }
    else if (DAT_2000049d == 2) {
      for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
        FUN_08012d00();
      }
    }
    DAT_2000049d = DAT_2000049d + 1;
    if (2 < DAT_2000049d) {
      DAT_2000049d = 0;
      DAT_2000049c = '\0';
    }
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_080137c6   (0x080137C6, 87 Bytes, 3 Teile)
 * Body: 0x080137C6-0x080137C7, 0x080137FE-0x08013837, 0x08013922-0x0801393F
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_080137c6(void)

{
  byte unaff_r4;
  
  do {
    FUN_080130a2();
    unaff_r4 = unaff_r4 + 1;
  } while (unaff_r4 < 0xe);
  DAT_2000049d = DAT_2000049d + 1;
  if (2 < DAT_2000049d) {
    DAT_2000049d = 0;
    DAT_2000049c = 0;
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08013940   (0x08013940, 935 Bytes, 3 Teile)
 * Body: 0x08013940-0x0801396F, 0x08013976-0x08013BFB, 0x08013C2C-0x08013D1F
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08013940(void)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar2 = FUN_0801326e((uint *)0x2000178c,_DAT_20001784);
  if (iVar2 == 1) {
    FUN_08013268((undefined4 *)0x2000178c);
    switch(DAT_20001781) {
    case 0:
      uVar4 = FUN_080116fc((int)(uint)DAT_20001788 >> 1,_DAT_20001744);
      uVar3 = FUN_080116f4(uVar4);
      DAT_200004c4 = (undefined1)uVar3;
      uVar3 = FUN_080116ec(uVar4);
      DAT_200004c5 = (undefined1)uVar3;
      DAT_200004c6 = FUN_080116e6((char)uVar4);
      uVar4 = FUN_080116f4(0);
      DAT_200004c7 = (undefined1)uVar4;
      uVar4 = FUN_080116ec(0);
      DAT_200004c8 = (undefined1)uVar4;
      DAT_200004c9 = FUN_080116e6(0);
      DAT_20001781 = DAT_20001781 + 1;
      _DAT_20000448 = 0;
      DAT_200004ca = 0;
      break;
    case 1:
      for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
        FUN_080134fc(DAT_200004c7,DAT_200004c8,DAT_200004c9);
      }
      _DAT_20000448 = 0;
      *(undefined1 *)((uint)DAT_200004ca * 3 + 0x20001794) = DAT_200004c4;
      *(undefined1 *)((uint)DAT_200004ca * 3 + 0x20001795) = DAT_200004c5;
      *(undefined1 *)((uint)DAT_200004ca * 3 + 0x20001796) = DAT_200004c6;
      *(undefined1 *)((0xd - (uint)DAT_200004ca) * 3 + 0x20001794) = DAT_200004c4;
      *(undefined1 *)((0xd - (uint)DAT_200004ca) * 3 + 0x20001795) = DAT_200004c5;
      *(undefined1 *)((0xd - (uint)DAT_200004ca) * 3 + 0x20001796) = DAT_200004c6;
      DAT_200004ca = DAT_200004ca + 1;
      if (0xd < DAT_200004ca) {
        DAT_200004ca = 0;
        DAT_20001781 = DAT_20001781 + 1;
      }
      break;
    case 2:
      for (uVar4 = 0; uVar4 < 0xe; uVar4 = uVar4 + 1 & 0xff) {
        if ((DAT_200004ca < uVar4) && (uVar4 < 0xd - DAT_200004ca)) {
          *(undefined1 *)(uVar4 * 3 + 0x20001794) = DAT_200004c7;
          *(undefined1 *)(uVar4 * 3 + 0x20001795) = DAT_200004c8;
          *(undefined1 *)(uVar4 * 3 + 0x20001796) = DAT_200004c9;
        }
        else {
          *(undefined1 *)(uVar4 * 3 + 0x20001794) = DAT_200004c4;
          *(undefined1 *)(uVar4 * 3 + 0x20001795) = DAT_200004c5;
          *(undefined1 *)(uVar4 * 3 + 0x20001796) = DAT_200004c6;
        }
      }
      DAT_200004ca = DAT_200004ca + 1;
      if (7 < DAT_200004ca) {
        DAT_200004ca = 0;
        uVar4 = FUN_080116f4(_DAT_20001744);
        DAT_200004c4 = (undefined1)uVar4;
        uVar4 = FUN_080116ec(_DAT_20001744);
        DAT_200004c5 = (undefined1)uVar4;
        DAT_200004c6 = FUN_080116e6((char)_DAT_20001744);
        uVar4 = FUN_080116fc((int)(uint)DAT_20001788 >> 1,_DAT_20001744);
        uVar3 = FUN_080116f4(uVar4);
        DAT_200004c7 = (undefined1)uVar3;
        uVar3 = FUN_080116ec(uVar4);
        DAT_200004c8 = (undefined1)uVar3;
        DAT_200004c9 = FUN_080116e6((char)uVar4);
        DAT_20001781 = DAT_20001781 + 1;
      }
      break;
    case 3:
      for (uVar4 = 0; uVar4 < 0xe; uVar4 = uVar4 + 1 & 0xff) {
        if ((uVar4 < 7 - DAT_200004ca) || (DAT_200004ca + 7 < uVar4)) {
          *(undefined1 *)(uVar4 * 3 + 0x20001794) = DAT_200004c7;
          *(undefined1 *)(uVar4 * 3 + 0x20001795) = DAT_200004c8;
          *(undefined1 *)(uVar4 * 3 + 0x20001796) = DAT_200004c9;
        }
        else {
          *(undefined1 *)(uVar4 * 3 + 0x20001794) = DAT_200004c4;
          *(undefined1 *)(uVar4 * 3 + 0x20001795) = DAT_200004c5;
          *(undefined1 *)(uVar4 * 3 + 0x20001796) = DAT_200004c6;
        }
      }
      DAT_200004ca = DAT_200004ca + 1;
      if (7 < DAT_200004ca) {
        DAT_200004ca = 0;
        DAT_20001781 = DAT_20001781 + 1;
      }
      break;
    case 4:
    }
    DAT_200004cb = '\x01';
    DAT_200004cc = 0;
  }
  if ((DAT_200004cb != '\0') && (DAT_20001781 < 4)) {
    if (DAT_200004cc == 0) {
      for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
        FUN_080130a2();
      }
    }
    else if (DAT_200004cc == 1) {
      for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
        FUN_08012ec6();
      }
    }
    else if (DAT_200004cc == 2) {
      for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
        FUN_08012d00();
      }
    }
    DAT_200004cc = DAT_200004cc + 1;
    if (2 < DAT_200004cc) {
      DAT_200004cc = 0;
      DAT_200004cb = '\0';
    }
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08013d20   (0x08013D20, 621 Bytes)
 * Body: 0x08013D20-0x08013F8D
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08013d20(void)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = FUN_0801326e((uint *)0x200014bc,_DAT_200014b4);
  if (iVar2 == 1) {
    FUN_08013268((undefined4 *)0x200014bc);
    if (DAT_200014c1 == '\0') {
      DAT_200014c1 = '\x01';
      uVar3 = FUN_080116f4(*(uint *)(&DAT_20001474 +
                                    ((uint)DAT_200014b1 -
                                    (uint)DAT_200014b0 * ((uint)DAT_200014b1 / (uint)DAT_200014b0))
                                    * 4));
      DAT_20000490 = (byte)uVar3;
      uVar3 = FUN_080116ec(*(uint *)(&DAT_20001474 +
                                    ((uint)DAT_200014b1 -
                                    (uint)DAT_200014b0 * ((uint)DAT_200014b1 / (uint)DAT_200014b0))
                                    * 4));
      DAT_20000491 = (byte)uVar3;
      DAT_20000492 = FUN_080116e6((char)*(undefined4 *)
                                         (&DAT_20001474 +
                                         ((uint)DAT_200014b1 -
                                         (uint)DAT_200014b0 *
                                         ((uint)DAT_200014b1 / (uint)DAT_200014b0)) * 4));
      DAT_200014b1 = DAT_200014b1 + 1;
      DAT_20000493 = 0;
      DAT_20000494 = 0;
      DAT_20000495 = 0;
    }
    DAT_20000496 = '\x01';
    if (2 < DAT_20000497) {
      DAT_20000497 = 0;
    }
    if (DAT_200014c1 == '\x01') {
      DAT_20000493 = DAT_20000493 + 2;
      if (DAT_20000490 <= DAT_20000493) {
        DAT_20000493 = DAT_20000490;
      }
      DAT_20000494 = DAT_20000494 + 2;
      if (DAT_20000491 <= DAT_20000494) {
        DAT_20000494 = DAT_20000491;
      }
      DAT_20000495 = DAT_20000495 + 2;
      if (DAT_20000492 <= DAT_20000495) {
        DAT_20000495 = DAT_20000492;
      }
      if (((DAT_20000493 == DAT_20000490) && (DAT_20000495 == DAT_20000492)) &&
         (DAT_20000494 == DAT_20000491)) {
        DAT_200014c1 = '\x02';
      }
    }
    else if (DAT_200014c1 == '\x02') {
      if (DAT_20000493 < 2) {
        DAT_20000493 = 0;
      }
      else {
        DAT_20000493 = DAT_20000493 - 2;
      }
      if (DAT_20000494 < 2) {
        DAT_20000494 = 0;
      }
      else {
        DAT_20000494 = DAT_20000494 - 2;
      }
      if (DAT_20000495 < 2) {
        DAT_20000495 = 0;
      }
      else {
        DAT_20000495 = DAT_20000495 - 2;
      }
      if (((DAT_20000493 == 0) && (DAT_20000495 == 0)) && (DAT_20000494 == 0)) {
        DAT_200014c1 = '\0';
      }
    }
  }
  if (DAT_20000496 == '\x01') {
    if (DAT_20000497 == 0) {
      for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
        FUN_080130a2();
      }
      DAT_20000497 = 1;
    }
    else if (DAT_20000497 == 1) {
      for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
        FUN_08012ec6();
      }
      DAT_20000497 = 2;
    }
    else if (DAT_20000497 == 2) {
      for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
        FUN_08012d00();
      }
      DAT_20000497 = 3;
      DAT_20000496 = '\0';
    }
    else {
      DAT_20000497 = 3;
      DAT_20000496 = '\0';
    }
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08013f8e   (0x08013F8E, 466 Bytes, 2 Teile)
 * Body: 0x08013F8E-0x08014027, 0x08014078-0x080141B1
 * --------------------------------------------------------------------- */
void FUN_08013f8e(void)

{
  byte bVar1;
  uint uVar2;
  
  if (DAT_2000032d != DAT_20000467) {
    DAT_20000467 = DAT_2000032d;
    uVar2 = FUN_080116f4(*(uint *)(&DAT_20001424 +
                                  ((uint)DAT_20001461 -
                                  (uint)DAT_20001460 * ((uint)DAT_20001461 / (uint)DAT_20001460)) *
                                  4));
    DAT_20000462 = (undefined1)uVar2;
    uVar2 = FUN_080116ec(*(uint *)(&DAT_20001424 +
                                  ((uint)DAT_20001461 -
                                  (uint)DAT_20001460 * ((uint)DAT_20001461 / (uint)DAT_20001460)) *
                                  4));
    DAT_20000463 = (undefined1)uVar2;
    DAT_20000464 = FUN_080116e6((char)*(undefined4 *)
                                       (&DAT_20001424 +
                                       ((uint)DAT_20001461 -
                                       (uint)DAT_20001460 *
                                       ((uint)DAT_20001461 / (uint)DAT_20001460)) * 4));
    DAT_20001461 = DAT_20001461 + 1;
    DAT_20000465 = '\x01';
    DAT_20000466 = 0;
  }
  if (DAT_20000465 != '\0') {
    if (DAT_20001472 == '\0') {
      if (DAT_20000466 == 0) {
        for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
          FUN_080130a2();
        }
      }
      else if (DAT_20000466 == 1) {
        for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
          FUN_08012d00();
        }
      }
      else if (DAT_20000466 == 2) {
        for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
          FUN_08012ec6();
        }
      }
      DAT_20000466 = DAT_20000466 + 1;
      if (2 < DAT_20000466) {
        DAT_20000466 = 0;
        DAT_20000465 = '\0';
      }
    }
    else if (DAT_20001472 == '\x01') {
      for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
        FUN_080130a2();
      }
      DAT_20000466 = 0;
      DAT_20000465 = '\0';
    }
    else if (DAT_20001472 == '\x02') {
      for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
        FUN_08012d00();
      }
      DAT_20000466 = 0;
      DAT_20000465 = '\0';
    }
    else if (DAT_20001472 == '\x03') {
      for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
        FUN_08012ec6();
      }
      DAT_20000466 = 0;
      DAT_20000465 = '\0';
    }
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_080141b2   (0x080141B2, 958 Bytes, 2 Teile)
 * Body: 0x080141B2-0x0801445F, 0x08014498-0x080145A9
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_080141b2(void)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_0801326e((uint *)0x2000169c,_DAT_20001694);
  if (iVar1 == 1) {
    FUN_08013268((undefined4 *)0x2000169c);
    if (DAT_200016a1 == '\0') {
      uVar2 = FUN_080116f4(*(uint *)(&DAT_20001654 +
                                    ((uint)DAT_20001691 -
                                    (uint)DAT_20001690 * ((uint)DAT_20001691 / (uint)DAT_20001690))
                                    * 4));
      DAT_200004a3 = (undefined1)uVar2;
      uVar2 = FUN_080116ec(*(uint *)(&DAT_20001654 +
                                    ((uint)DAT_20001691 -
                                    (uint)DAT_20001690 * ((uint)DAT_20001691 / (uint)DAT_20001690))
                                    * 4));
      DAT_200004a4 = (undefined1)uVar2;
      DAT_200004a5 = FUN_080116e6((char)*(undefined4 *)
                                         (&DAT_20001654 +
                                         ((uint)DAT_20001691 -
                                         (uint)DAT_20001690 *
                                         ((uint)DAT_20001691 / (uint)DAT_20001690)) * 4));
      uVar2 = FUN_080116f4(_DAT_2000168c);
      DAT_200004a6 = (undefined1)uVar2;
      uVar2 = FUN_080116ec(_DAT_2000168c);
      DAT_200004a7 = (undefined1)uVar2;
      DAT_200004a8 = FUN_080116e6((char)_DAT_2000168c);
      DAT_20001691 = DAT_20001691 + 1;
      DAT_200016a1 = '\x01';
    }
    if (DAT_200016a2 == '\0') {
      for (uVar2 = 0; uVar2 < 0xe; uVar2 = uVar2 + 1 & 0xff) {
        if (DAT_200016a0 == '\x01') {
          if (uVar2 < 0xe - DAT_200004a9) {
            FUN_08012d00();
          }
          else {
            FUN_08012d00();
          }
        }
        else if (uVar2 < DAT_200004a9) {
          FUN_08012d00();
        }
        else {
          FUN_08012d00();
        }
      }
      for (uVar2 = 0; uVar2 < 0xe; uVar2 = uVar2 + 1 & 0xff) {
        if (DAT_200016a0 == '\x01') {
          if (uVar2 < 0xe - DAT_200004a9) {
            FUN_080130a2();
          }
          else {
            FUN_080130a2();
          }
        }
        else if (uVar2 < DAT_200004a9) {
          FUN_080130a2();
        }
        else {
          FUN_080130a2();
        }
      }
      for (uVar2 = 0; uVar2 < 0xe; uVar2 = uVar2 + 1 & 0xff) {
        if (DAT_200016a0 == '\x01') {
          if (uVar2 < 0xe - DAT_200004a9) {
            FUN_08012ec6();
          }
          else {
            FUN_08012ec6();
          }
        }
        else if (uVar2 < DAT_200004a9) {
          FUN_08012ec6();
        }
        else {
          FUN_08012ec6();
        }
      }
    }
    else if (DAT_200016a2 == '\x01') {
      for (uVar2 = 0; uVar2 < 0xe; uVar2 = uVar2 + 1 & 0xff) {
        if (DAT_200016a0 == '\x01') {
          if (uVar2 < 0xe - DAT_200004a9) {
            FUN_080130a2();
          }
          else {
            FUN_080130a2();
          }
        }
        else if (uVar2 < DAT_200004a9) {
          FUN_080130a2();
        }
        else {
          FUN_080130a2();
        }
      }
    }
    else if (DAT_200016a2 == '\x02') {
      for (uVar2 = 0; uVar2 < 0xe; uVar2 = uVar2 + 1 & 0xff) {
        if (DAT_200016a0 == '\x01') {
          if (uVar2 < 0xe - DAT_200004a9) {
            FUN_08012d00();
          }
          else {
            FUN_08012d00();
          }
        }
        else if (uVar2 < DAT_200004a9) {
          FUN_08012d00();
        }
        else {
          FUN_08012d00();
        }
      }
    }
    else if (DAT_200016a2 == '\x03') {
      for (uVar2 = 0; uVar2 < 0xe; uVar2 = uVar2 + 1 & 0xff) {
        if (DAT_200016a0 == '\x01') {
          if (uVar2 < 0xe - DAT_200004a9) {
            FUN_08012ec6();
          }
          else {
            FUN_08012ec6();
          }
        }
        else if (uVar2 < DAT_200004a9) {
          FUN_08012ec6();
        }
        else {
          FUN_08012ec6();
        }
      }
    }
    if ((DAT_200016a1 == '\x01') && (DAT_200004a9 = DAT_200004a9 + 1, 0xe < DAT_200004a9)) {
      DAT_200004a9 = 0;
      DAT_200004aa = 0;
      DAT_200016a1 = '\0';
    }
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_080145aa   (0x080145AA, 457 Bytes)
 * Body: 0x080145AA-0x08014773
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_080145aa(void)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = FUN_0801326e((uint *)0x2000141c,_DAT_20001414);
  if (iVar2 == 1) {
    FUN_08013268((undefined4 *)0x2000141c);
    uVar3 = FUN_080116f4(*(uint *)(&DAT_200013d4 +
                                  ((uint)DAT_20001411 -
                                  (uint)DAT_20001410 * ((uint)DAT_20001411 / (uint)DAT_20001410)) *
                                  4));
    DAT_2000045d = (undefined1)uVar3;
    uVar3 = FUN_080116ec(*(uint *)(&DAT_200013d4 +
                                  ((uint)DAT_20001411 -
                                  (uint)DAT_20001410 * ((uint)DAT_20001411 / (uint)DAT_20001410)) *
                                  4));
    DAT_2000045e = (undefined1)uVar3;
    DAT_2000045f = FUN_080116e6((char)*(undefined4 *)
                                       (&DAT_200013d4 +
                                       ((uint)DAT_20001411 -
                                       (uint)DAT_20001410 *
                                       ((uint)DAT_20001411 / (uint)DAT_20001410)) * 4));
    DAT_20001411 = DAT_20001411 + 1;
    DAT_20000460 = '\x01';
    DAT_20000461 = 0;
  }
  if (DAT_20000460 != '\0') {
    if (DAT_20001422 == '\0') {
      if (DAT_20000461 == 0) {
        for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
          FUN_080130a2();
        }
      }
      else if (DAT_20000461 == 1) {
        for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
          FUN_08012d00();
        }
      }
      else if (DAT_20000461 == 2) {
        for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
          FUN_08012ec6();
        }
      }
      DAT_20000461 = DAT_20000461 + 1;
      if (2 < DAT_20000461) {
        DAT_20000461 = 0;
        DAT_20000460 = '\0';
      }
    }
    else if (DAT_20001422 == '\x01') {
      for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
        FUN_080130a2();
      }
      DAT_20000461 = 0;
      DAT_20000460 = '\0';
    }
    else if (DAT_20001422 == '\x02') {
      for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
        FUN_08012d00();
      }
      DAT_20000461 = 0;
      DAT_20000460 = '\0';
    }
    else if (DAT_20001422 == '\x03') {
      for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
        FUN_08012ec6();
      }
      DAT_20000461 = 0;
      DAT_20000460 = '\0';
    }
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08014774   (0x08014774, 564 Bytes, 2 Teile)
 * Body: 0x08014774-0x08014887, 0x080148D8-0x080149F9
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08014774(void)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_0801326e((uint *)0x2000155c,_DAT_20001554);
  if (iVar1 == 1) {
    FUN_08013268((undefined4 *)0x2000155c);
    if (DAT_20001561 == '\0') {
      uVar2 = FUN_080116f4(*(uint *)(&DAT_20001514 +
                                    ((uint)DAT_20001551 -
                                    (uint)DAT_20001550 * ((uint)DAT_20001551 / (uint)DAT_20001550))
                                    * 4));
      DAT_2000049e = (undefined1)uVar2;
      uVar2 = FUN_080116ec(*(uint *)(&DAT_20001514 +
                                    ((uint)DAT_20001551 -
                                    (uint)DAT_20001550 * ((uint)DAT_20001551 / (uint)DAT_20001550))
                                    * 4));
      DAT_2000049f = (undefined1)uVar2;
      DAT_200004a0 = FUN_080116e6((char)*(undefined4 *)
                                         (&DAT_20001514 +
                                         ((uint)DAT_20001551 -
                                         (uint)DAT_20001550 *
                                         ((uint)DAT_20001551 / (uint)DAT_20001550)) * 4));
      DAT_20001551 = DAT_20001551 + 1;
      DAT_20001561 = '\x01';
    }
    for (uVar2 = 0; uVar2 < 0xe; uVar2 = uVar2 + 1 & 0xff) {
      if (DAT_20001560 == '\x01') {
        if (uVar2 < 0xe - DAT_200004a1) {
          FUN_080130a2();
        }
        else {
          FUN_080130a2();
        }
      }
      else if (DAT_200004a1 < uVar2) {
        FUN_080130a2();
      }
      else {
        FUN_080130a2();
      }
    }
    for (uVar2 = 0; uVar2 < 0xe; uVar2 = uVar2 + 1 & 0xff) {
      if (DAT_20001560 == '\x01') {
        if (uVar2 < 0xe - DAT_200004a1) {
          FUN_08012d00();
        }
        else {
          FUN_08012d00();
        }
      }
      else if (DAT_200004a1 < uVar2) {
        FUN_08012d00();
      }
      else {
        FUN_08012d00();
      }
    }
    for (uVar2 = 0; uVar2 < 0xe; uVar2 = uVar2 + 1 & 0xff) {
      if (DAT_20001560 == '\x01') {
        if (uVar2 < 0xe - DAT_200004a1) {
          FUN_08012ec6();
        }
        else {
          FUN_08012ec6();
        }
      }
      else if (DAT_200004a1 < uVar2) {
        FUN_08012ec6();
      }
      else {
        FUN_08012ec6();
      }
    }
    if (DAT_20001561 == '\x01') {
      DAT_200004a1 = DAT_200004a1 + 1;
      if (0xe < DAT_200004a1) {
        DAT_200004a1 = 0xe;
        DAT_200004a2 = 0;
        DAT_20001561 = '\x02';
      }
    }
    else if ((DAT_20001561 == '\x02') && (DAT_200004a2 = DAT_200004a2 + 1, 0x28 < DAT_200004a2)) {
      DAT_200004a1 = 0;
      DAT_200004a2 = 0;
      DAT_20001561 = '\0';
    }
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_080149fa   (0x080149FA, 471 Bytes)
 * Body: 0x080149FA-0x08014BD1
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_080149fa(void)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_0801326e((uint *)0x200015ac,_DAT_200015a4);
  if (iVar1 == 1) {
    FUN_08013268((undefined4 *)0x200015ac);
    if (DAT_200015b0 == '\x01') {
      DAT_200015a1 = DAT_200015a1 + 1;
    }
    else {
      DAT_200015a1 = DAT_200015a1 - 1;
    }
    for (uVar2 = 0; uVar2 < 0xe; uVar2 = uVar2 + 1 & 0xff) {
      FUN_080116f4(*(uint *)(&DAT_20001564 +
                            ((DAT_200015a1 + uVar2) -
                            (uint)DAT_200015a0 * ((DAT_200015a1 + uVar2) / (uint)DAT_200015a0)) * 4)
                  );
      FUN_080116ec(*(uint *)(&DAT_20001564 +
                            ((DAT_200015a1 + uVar2) -
                            (uint)DAT_200015a0 * ((DAT_200015a1 + uVar2) / (uint)DAT_200015a0)) * 4)
                  );
      FUN_080116e6((char)*(undefined4 *)
                          (&DAT_20001564 +
                          ((DAT_200015a1 + uVar2) -
                          (uint)DAT_200015a0 * ((DAT_200015a1 + uVar2) / (uint)DAT_200015a0)) * 4));
      FUN_08012d00();
    }
    for (uVar2 = 0; uVar2 < 0xe; uVar2 = uVar2 + 1 & 0xff) {
      FUN_080116f4(*(uint *)(&DAT_20001564 +
                            ((DAT_200015a1 + uVar2) -
                            (uint)DAT_200015a0 * ((DAT_200015a1 + uVar2) / (uint)DAT_200015a0)) * 4)
                  );
      FUN_080116ec(*(uint *)(&DAT_20001564 +
                            ((DAT_200015a1 + uVar2) -
                            (uint)DAT_200015a0 * ((DAT_200015a1 + uVar2) / (uint)DAT_200015a0)) * 4)
                  );
      FUN_080116e6((char)*(undefined4 *)
                          (&DAT_20001564 +
                          ((DAT_200015a1 + uVar2) -
                          (uint)DAT_200015a0 * ((DAT_200015a1 + uVar2) / (uint)DAT_200015a0)) * 4));
      FUN_08012ec6();
    }
    for (uVar2 = 0; uVar2 < 0xe; uVar2 = uVar2 + 1 & 0xff) {
      FUN_080116f4(*(uint *)(&DAT_20001564 +
                            ((DAT_200015a1 + uVar2) -
                            (uint)DAT_200015a0 * ((DAT_200015a1 + uVar2) / (uint)DAT_200015a0)) * 4)
                  );
      FUN_080116ec(*(uint *)(&DAT_20001564 +
                            ((DAT_200015a1 + uVar2) -
                            (uint)DAT_200015a0 * ((DAT_200015a1 + uVar2) / (uint)DAT_200015a0)) * 4)
                  );
      FUN_080116e6((char)*(undefined4 *)
                          (&DAT_20001564 +
                          ((DAT_200015a1 + uVar2) -
                          (uint)DAT_200015a0 * ((DAT_200015a1 + uVar2) / (uint)DAT_200015a0)) * 4));
      FUN_080130a2();
    }
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08014bd2   (0x08014BD2, 404 Bytes, 2 Teile)
 * Body: 0x08014BD2-0x08014CD1, 0x08014CF4-0x08014D89
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08014bd2(void)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = 0;
  iVar2 = FUN_0801326e((uint *)0x2000150c,_DAT_20001504);
  if (iVar2 == 1) {
    FUN_08013268((undefined4 *)0x2000150c);
    FUN_080116f4(*(uint *)(&DAT_200014c4 +
                          ((uint)DAT_20001501 -
                          (uint)DAT_20001500 * ((uint)DAT_20001501 / (uint)DAT_20001500)) * 4));
    FUN_080116ec(*(uint *)(&DAT_200014c4 +
                          ((uint)DAT_20001501 -
                          (uint)DAT_20001500 * ((uint)DAT_20001501 / (uint)DAT_20001500)) * 4));
    FUN_080116e6((char)*(undefined4 *)
                        (&DAT_200014c4 +
                        ((uint)DAT_20001501 -
                        (uint)DAT_20001500 * ((uint)DAT_20001501 / (uint)DAT_20001500)) * 4));
    DAT_20001501 = DAT_20001501 + 1;
    if ((uint)DAT_20001501 == ((int)(uint)DAT_20001501 >> 1) * 2) {
      for (; bVar1 < 7; bVar1 = bVar1 + 1) {
        FUN_080130a2();
        FUN_080130a2();
      }
    }
    else {
      for (bVar1 = 0; bVar1 < 7; bVar1 = bVar1 + 1) {
        FUN_080130a2();
        FUN_080130a2();
      }
    }
    if ((uint)DAT_20001501 == ((int)(uint)DAT_20001501 >> 1) * 2) {
      for (bVar1 = 0; bVar1 < 7; bVar1 = bVar1 + 1) {
        FUN_08012d00();
        FUN_08012d00();
      }
    }
    else {
      for (bVar1 = 0; bVar1 < 7; bVar1 = bVar1 + 1) {
        FUN_08012d00();
        FUN_08012d00();
      }
    }
    if ((uint)DAT_20001501 == ((int)(uint)DAT_20001501 >> 1) * 2) {
      for (bVar1 = 0; bVar1 < 7; bVar1 = bVar1 + 1) {
        FUN_08012ec6();
        FUN_08012ec6();
      }
    }
    else {
      for (bVar1 = 0; bVar1 < 7; bVar1 = bVar1 + 1) {
        FUN_08012ec6();
        FUN_08012ec6();
      }
    }
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08014d8a   (0x08014D8A, 687 Bytes)
 * Body: 0x08014D8A-0x08015039
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08014d8a(void)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_0801326e((uint *)0x200016ec,_DAT_200016e4);
  if (iVar1 == 1) {
    FUN_08013268((undefined4 *)0x200016ec);
    if (DAT_200016f1 == '\0') {
      if (DAT_20000364 < 0x14) {
        uVar2 = FUN_080116f4(0xff0000);
        DAT_200004ab = (undefined1)uVar2;
        uVar2 = FUN_080116ec(0xff0000);
        DAT_200004ac = (undefined1)uVar2;
        DAT_200004ad = FUN_080116e6(0);
        _DAT_200013d4 = 0xff0000;
        _DAT_200013d8 = 0;
      }
      else if (DAT_20000364 < 0x32) {
        uVar2 = FUN_080116f4(0xffff00);
        DAT_200004ab = (undefined1)uVar2;
        uVar2 = FUN_080116ec(0xffff00);
        DAT_200004ac = (undefined1)uVar2;
        DAT_200004ad = FUN_080116e6(0);
        _DAT_200013d4 = 0xffff00;
        _DAT_200013d8 = 0;
      }
      else if (DAT_20000364 < 100) {
        uVar2 = FUN_080116f4(0x99ff);
        DAT_200004ab = (undefined1)uVar2;
        uVar2 = FUN_080116ec(0x99ff);
        DAT_200004ac = (undefined1)uVar2;
        DAT_200004ad = FUN_080116e6(0xff);
        _DAT_200013d4 = 0xf5424;
        _DAT_200013d8 = 0;
      }
      else {
        uVar2 = FUN_080116f4(0x99ff);
        DAT_200004ab = (undefined1)uVar2;
        uVar2 = FUN_080116ec(0x99ff);
        DAT_200004ac = (undefined1)uVar2;
        DAT_200004ad = FUN_080116e6(0xff);
        _DAT_200013d4 = 0x99ff;
        _DAT_200013d8 = 0x99ff;
      }
      uVar2 = FUN_080116f4(_DAT_200016dc);
      DAT_200004ae = (undefined1)uVar2;
      uVar2 = FUN_080116ec(_DAT_200016dc);
      DAT_200004af = (undefined1)uVar2;
      DAT_200004b0 = FUN_080116e6((char)_DAT_200016dc);
      DAT_200016e1 = DAT_200016e1 + '\x01';
      DAT_200016f1 = '\x01';
    }
    DAT_200004b6 = '\x01';
    DAT_200004b7 = '\0';
    _DAT_200004b4 = _DAT_200004b4 + 1;
    if (5 < _DAT_200004b4) {
      _DAT_200004b4 = 0;
      DAT_200004b3 = DAT_200004b3 + 1;
      if (100 < DAT_200004b3) {
        DAT_200004b3 = 100;
      }
    }
    if (DAT_20000364 < 100) {
      DAT_200004b2 = (byte)((int)(uint)DAT_20000364 >> 3);
    }
    else {
      DAT_200004b2 = 0xe;
    }
    if (0xe < DAT_200004b2) {
      DAT_200004b2 = 0xe;
    }
    if ((DAT_200016f1 == '\x01') &&
       (DAT_200004b1 = DAT_200004b1 + 1, 0xe - DAT_200004b2 < (uint)DAT_200004b1)) {
      DAT_200004b1 = 0;
      DAT_200016f1 = '\0';
    }
  }
  if (DAT_200004b6 == '\x01') {
    if (DAT_200004b7 == '\0') {
      for (uVar2 = 0; uVar2 < 0xe; uVar2 = uVar2 + 1 & 0xff) {
        if (DAT_200004b2 < uVar2) {
          if (uVar2 < 0xe - DAT_200004b1) {
            FUN_080130a2();
          }
          else {
            FUN_080130a2();
          }
        }
        else {
          FUN_080130a2();
        }
      }
      DAT_200004b7 = DAT_200004b7 + '\x01';
    }
    else if (DAT_200004b7 == '\x01') {
      for (uVar2 = 0; uVar2 < 0xe; uVar2 = uVar2 + 1 & 0xff) {
        if (DAT_200004b2 < uVar2) {
          if (uVar2 < 0xe - DAT_200004b1) {
            FUN_08012ec6();
          }
          else {
            FUN_08012ec6();
          }
        }
        else {
          FUN_08012ec6();
        }
      }
      DAT_200004b7 = '\0';
      DAT_200004b6 = '\0';
    }
    else {
      DAT_200004b7 = '\0';
      DAT_200004b6 = '\0';
    }
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801503a   (0x0801503A, 691 Bytes, 3 Teile)
 * Body: 0x0801503A-0x0801512B, 0x08015188-0x0801530B, 0x08015316-0x08015355
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0801503a(void)

{
  undefined4 auStack_24 [7];
  
  FUN_0801d2ec(auStack_24,(undefined4 *)&DAT_0801d998,0x1c);
  if (_DAT_200002e2 < 0x23) {
    if (DAT_2000044c != '\x04') {
      DAT_2000044c = '\x04';
      FUN_080117bc(0,0,0);
      _DAT_200013d4 = FUN_080116fc((uint)DAT_2000032a,0xff0000);
      _DAT_200013d8 = 0;
      DAT_20001410 = 2;
      DAT_20001411 = 0;
      DAT_20001420 = 0;
      _DAT_20001414 = 0xf;
      DAT_20001418 = 100;
      DAT_20001422 = 0;
      FUN_08010ff8((undefined4 *)0x2000141c);
    }
  }
  else if ((_DAT_200002e2 < 0x23) || (0x2b < _DAT_200002e2)) {
    if ((_DAT_200002e2 < 0x2c) || (0x84 < _DAT_200002e2)) {
      if ((_DAT_200002e2 < 0x85) || (0xd48 < _DAT_200002e2)) {
        if (DAT_20000390 == '\x01') {
          if (DAT_2000044c != '\t') {
            DAT_2000044c = '\t';
            FUN_080117bc(0,0,0);
            _DAT_200013d4 = 0xf5424;
            _DAT_200013d8 = 0;
            DAT_20001410 = 2;
            DAT_20001411 = 0;
            DAT_20001420 = 0;
            _DAT_20001414 = 0x12;
            DAT_20001418 = 100;
            DAT_20001422 = 2;
            FUN_08010ff8((undefined4 *)0x2000141c);
            _DAT_200016a4 = 0xf5424;
            _DAT_200016dc = 0;
            DAT_200016e0 = 1;
            DAT_200016e1 = 0;
            DAT_200016f1 = 0;
            DAT_200016f0 = 0;
            _DAT_200016e4 = 8;
            DAT_200016e8 = 100;
            DAT_200016f2 = 2;
            FUN_08010ff8((undefined4 *)0x200016ec);
          }
        }
        else if (DAT_2000044c != '\0') {
          DAT_2000044c = '\0';
          FUN_080117bc(0,0,0);
          FUN_080125fc(0xb);
        }
      }
      else if (DAT_2000044c != '\x01') {
        DAT_2000044c = '\x01';
        FUN_080117bc(0,0,0);
        FUN_08011826(6,0,0);
      }
    }
    else if (DAT_2000044c != '\x02') {
      DAT_2000044c = '\x02';
      FUN_080117bc(0,0,0);
      FUN_08011826(3,0,0);
    }
  }
  else if (DAT_2000044c != '\x03') {
    DAT_2000044c = '\x03';
    FUN_080117bc(0,0,0);
    _DAT_200013d4 = FUN_080116fc((uint)DAT_2000032a,0xff0000);
    _DAT_200013d8 = 0;
    _DAT_200013dc = FUN_080116fc((uint)DAT_2000032a,0xff7f00);
    _DAT_200013e0 = 0;
    _DAT_200013e4 = FUN_080116fc((uint)DAT_2000032a,0xffff00);
    _DAT_200013e8 = 0;
    _DAT_200013ec = FUN_080116fc((uint)DAT_2000032a,0xff00);
    _DAT_200013f0 = 0;
    _DAT_200013f4 = FUN_080116fc((uint)DAT_2000032a,0xffff);
    _DAT_200013f8 = 0;
    _DAT_200013fc = FUN_080116fc((uint)DAT_2000032a,0xff);
    _DAT_20001400 = 0;
    _DAT_20001404 = FUN_080116fc((uint)DAT_2000032a,0xff00ff);
    _DAT_20001408 = 0;
    DAT_20001410 = 0xe;
    DAT_20001411 = 0;
    DAT_20001420 = 0;
    _DAT_20001414 = 0x19;
    DAT_20001418 = 100;
    DAT_20001422 = 0;
    FUN_08010ff8((undefined4 *)0x2000141c);
  }
  FUN_08013320();
  _DAT_200004d2 = _DAT_200004d2 + 1;
  switch(DAT_2000044c) {
  case '\0':
    FUN_08013d20();
    break;
  case '\x01':
    FUN_08013550();
    break;
  case '\x02':
    FUN_08013550();
    break;
  case '\x03':
    FUN_080145aa();
    break;
  case '\x04':
    FUN_080145aa();
    break;
  case '\t':
    if ((uint)_DAT_200004d2 == ((int)(uint)_DAT_200004d2 >> 1) * 2) {
      FUN_080145aa();
    }
    else {
      FUN_08014d8a();
    }
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08015356   (0x08015356, 298 Bytes, 2 Teile)
 * Body: 0x08015356-0x08015363, 0x08015394-0x080154B1
 * --------------------------------------------------------------------- */
void FUN_08015356(void)

{
  switch(DAT_20000320) {
  case 1:
    FUN_0801503a();
    break;
  case 2:
    FUN_08013550();
    break;
  case 3:
    FUN_08013550();
    break;
  case 4:
    FUN_080145aa();
    break;
  case 5:
    FUN_080145aa();
    break;
  case 6:
    FUN_080145aa();
    break;
  case 7:
    FUN_080145aa();
    break;
  case 8:
    FUN_080145aa();
    break;
  case 9:
    FUN_080145aa();
    break;
  case 10:
    FUN_080145aa();
    break;
  case 0xb:
    FUN_08013d20();
    break;
  case 0xc:
    FUN_08013d20();
    break;
  case 0xd:
    FUN_08013d20();
    break;
  case 0xe:
    FUN_08013d20();
    break;
  case 0xf:
    FUN_08013d20();
    break;
  case 0x10:
    FUN_08013d20();
    break;
  case 0x11:
    FUN_08014bd2();
    break;
  case 0x12:
    FUN_08014bd2();
    break;
  case 0x13:
    FUN_08014bd2();
    break;
  case 0x14:
    FUN_08014bd2();
    break;
  case 0x15:
    FUN_08014bd2();
    break;
  case 0x16:
    FUN_08014bd2();
    break;
  case 0x17:
    FUN_08014bd2();
    break;
  case 0x18:
    FUN_08014774();
    break;
  case 0x19:
    FUN_08014774();
    break;
  case 0x1a:
    FUN_08014774();
    break;
  case 0x1b:
    FUN_08014774();
    break;
  case 0x1c:
    FUN_08014774();
    break;
  case 0x1d:
    FUN_08014774();
    break;
  case 0x1e:
    FUN_080149fa();
    break;
  case 0x1f:
    FUN_080149fa();
    break;
  case 0x20:
    FUN_080149fa();
    break;
  case 0x21:
    FUN_080149fa();
    break;
  case 0x22:
    FUN_080149fa();
    break;
  case 0x23:
    FUN_080149fa();
    break;
  case 0x24:
    FUN_08014774();
    break;
  case 0x25:
    FUN_08014774();
    break;
  case 0x26:
    FUN_08014774();
    break;
  case 0x27:
    FUN_08014774();
    break;
  case 0x28:
    FUN_08014774();
    break;
  case 0x29:
    FUN_08014774();
    break;
  case 0x2a:
    FUN_08014774();
    break;
  case 0x2b:
    FUN_08014774();
    break;
  case 0x2c:
    FUN_08014774();
    break;
  case 0x2d:
    FUN_08014774();
    break;
  case 0x2e:
    FUN_08014774();
    break;
  case 0x2f:
    FUN_08014774();
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_080154b2   (0x080154B2, 1895 Bytes, 5 Teile)
 * Body: 0x080154B2-0x0801558B, 0x080155D4-0x080159DF, 0x08015A14-0x08015AA5, 0x08015AA8-0x08015BB1, 0x08015BC0-0x08015CA9
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_080154b2(void)

{
  undefined4 *puVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  undefined4 auStack_30 [7];
  
  FUN_0801d2ec(auStack_30,(undefined4 *)&DAT_0801d9b4,0x1c);
  if (_DAT_200004da == 0) {
    if (((_DAT_20000034 < 0x1f5) || (_DAT_20000036 < 0x1f5)) && (DAT_20000391 != '\x03')) {
      if ((_DAT_20000036 < 0x1f5) || ((DAT_200002db & 4) != 4)) {
        if (_DAT_20000036 < 0x1f5) {
          if ((_DAT_20000034 < 0x1f5) || ((DAT_200002db & 4) != 4)) {
            if (_DAT_20000034 < 0x1f5) {
              if ((DAT_200002db & 4) == 4) {
                if (DAT_200004dc != '\x05') {
                  DAT_200004dc = '\x05';
                  _DAT_200013d4 = 0xff0000;
                  _DAT_200013d8 = 0;
                  DAT_20001410 = 2;
                  DAT_20001411 = 0;
                  DAT_20001420 = 0;
                  _DAT_20001414 = 0xf;
                  DAT_20001418 = 100;
                  DAT_20001422 = 2;
                  FUN_08010ff8((undefined4 *)0x2000141c);
                  bVar2 = FUN_080116e6(0);
                  uVar3 = FUN_080116ec(0xff0000);
                  uVar4 = FUN_080116f4(0xff0000);
                  FUN_080117bc(uVar4,uVar3,(uint)bVar2);
                }
              }
              else if (((DAT_2000029f == '\0') && ((DAT_200002db & 0x8b) == 0)) &&
                      ((DAT_200002e6 & 0x8b) == 0)) {
                if (_DAT_200002e2 < 0x23) {
                  if (DAT_200004dc != '\x04') {
                    DAT_200004dc = '\x04';
                    _DAT_200013d4 = 0xff0000;
                    _DAT_200013d8 = 0;
                    DAT_20001410 = 2;
                    DAT_20001411 = 0;
                    DAT_20001420 = 0;
                    _DAT_20001414 = 0xf;
                    DAT_20001418 = 100;
                    DAT_20001422 = 0;
                    FUN_08010ff8((undefined4 *)0x2000141c);
                  }
                }
                else if ((_DAT_200002e2 < 0x23) || (0x2b < _DAT_200002e2)) {
                  if ((_DAT_200002e2 < 0x2c) || (0x84 < _DAT_200002e2)) {
                    if ((_DAT_200002e2 < 0x85) || (0xd48 < _DAT_200002e2)) {
                      if (DAT_20000390 == '\x01') {
                        if (DAT_200004dc != '\t') {
                          DAT_200004dc = '\t';
                          FUN_080117bc(0,0,0);
                          _DAT_200013d4 = 0xf5424;
                          _DAT_200013d8 = 0;
                          DAT_20001410 = 2;
                          DAT_20001411 = 0;
                          DAT_20001420 = 0;
                          _DAT_20001414 = 0x12;
                          DAT_20001418 = 100;
                          DAT_20001422 = 2;
                          FUN_08010ff8((undefined4 *)0x2000141c);
                          puVar1 = FUN_08015e2a;
                          *FUN_08015e2a = 0xf5424;
                          puVar1[0xe] = 0;
                          *(undefined1 *)(puVar1 + 0xf) = 1;
                          *(undefined1 *)((int)puVar1 + 0x3d) = 0;
                          *(undefined1 *)((int)puVar1 + 0x4d) = 0;
                          *(undefined1 *)(puVar1 + 0x13) = 0;
                          puVar1[0x10] = 8;
                          *(undefined1 *)(puVar1 + 0x11) = 100;
                          *(undefined1 *)((int)puVar1 + 0x4e) = 2;
                          FUN_08010ff8(puVar1 + 0x12);
                        }
                      }
                      else if (DAT_200004dc != '\0') {
                        DAT_200004dc = '\0';
                        FUN_080125fc(0xb);
                      }
                    }
                    else if (DAT_200004dc != '\x01') {
                      DAT_200004dc = '\x01';
                      FUN_08011826(6,0,0);
                    }
                  }
                  else if (DAT_200004dc != '\x02') {
                    DAT_200004dc = '\x02';
                    FUN_08011826(3,0,0);
                  }
                }
                else if (DAT_200004dc != '\x03') {
                  DAT_200004dc = '\x03';
                  _DAT_200013d4 = FUN_080116fc((uint)DAT_2000032a,0xff0000);
                  _DAT_200013d8 = 0;
                  _DAT_200013dc = FUN_080116fc((uint)DAT_2000032a,0xff7f00);
                  _DAT_200013e0 = 0;
                  _DAT_200013e4 = FUN_080116fc((uint)DAT_2000032a,0xffff00);
                  _DAT_200013e8 = 0;
                  _DAT_200013ec = FUN_080116fc((uint)DAT_2000032a,0xff00);
                  _DAT_200013f0 = 0;
                  _DAT_200013f4 = FUN_080116fc((uint)DAT_2000032a,0xffff);
                  _DAT_200013f8 = 0;
                  _DAT_200013fc = FUN_080116fc((uint)DAT_2000032a,0xff);
                  _DAT_20001400 = 0;
                  _DAT_20001404 = FUN_080116fc((uint)DAT_2000032a,0xff00ff);
                  _DAT_20001408 = 0;
                  DAT_20001410 = 0xe;
                  DAT_20001411 = 0;
                  DAT_20001420 = 0;
                  _DAT_20001414 = 0x19;
                  DAT_20001418 = 100;
                  DAT_20001422 = 0;
                  FUN_08010ff8((undefined4 *)0x2000141c);
                }
              }
              else if (DAT_200004dc != '\n') {
                DAT_200004dc = '\n';
                FUN_080117bc(0,0,0);
                _DAT_20001474 = 0xff0000;
                DAT_200014b0 = 1;
                DAT_200014b1 = 0;
                DAT_200014c1 = 0;
                DAT_200014c0 = 0;
                _DAT_200014b4 = 1;
                DAT_200014b8 = 100;
                DAT_200014c2 = 0;
                FUN_08010ff8((undefined4 *)0x200014bc);
              }
            }
            else if (DAT_200004dc != '\x06') {
              DAT_200004dc = '\x06';
              FUN_080117bc(0,0,0);
              _DAT_20001654 = FUN_080116fc((uint)DAT_2000032a,0xff7f00);
              _DAT_2000168c = 0;
              DAT_20001690 = 1;
              DAT_20001691 = 0;
              DAT_200016a1 = 0;
              DAT_200016a0 = 1;
              _DAT_20001694 = 6;
              DAT_20001698 = 100;
              DAT_200016a2 = 2;
              FUN_08010ff8((undefined4 *)0x2000169c);
              _DAT_20001424 = FUN_080116fc((uint)DAT_2000032a,0xff7f00);
              _DAT_20001428 = 0;
              DAT_20001460 = 2;
              DAT_20001461 = 0;
              DAT_20001470 = 0;
              _DAT_20001464 = 0xd;
              DAT_20001468 = 100;
              DAT_20001472 = 3;
              FUN_08010ff8((undefined4 *)0x2000146c);
            }
          }
          else if (DAT_200004dc != '\f') {
            DAT_200004dc = '\f';
            FUN_080117bc(0,0,0);
            _DAT_20001654 = FUN_080116fc((uint)DAT_2000032a,0xff0000);
            _DAT_2000168c = 0;
            DAT_20001690 = 1;
            DAT_20001691 = 0;
            DAT_200016a1 = 0;
            DAT_200016a0 = 1;
            _DAT_20001694 = 6;
            DAT_20001698 = 100;
            DAT_200016a2 = 2;
            FUN_08010ff8((undefined4 *)0x2000169c);
            _DAT_20001424 = FUN_080116fc((uint)DAT_2000032a,0xff0000);
            _DAT_20001428 = 0;
            DAT_20001460 = 2;
            DAT_20001461 = 0;
            DAT_20001470 = 0;
            _DAT_20001464 = 0xd;
            DAT_20001468 = 100;
            DAT_20001472 = 3;
            FUN_08010ff8((undefined4 *)0x2000146c);
          }
        }
        else if (DAT_200004dc != '\a') {
          DAT_200004dc = '\a';
          FUN_080117bc(0,0,0);
          _DAT_20001654 = FUN_080116fc((uint)DAT_2000032a,0xff7f00);
          _DAT_2000168c = 0;
          DAT_20001690 = 1;
          DAT_20001691 = 0;
          DAT_200016a1 = 0;
          DAT_200016a0 = 0;
          _DAT_20001694 = 6;
          DAT_20001698 = 100;
          DAT_200016a2 = 2;
          FUN_08010ff8((undefined4 *)0x2000169c);
          _DAT_20001424 = FUN_080116fc((uint)DAT_2000032a,0xff7f00);
          _DAT_20001428 = 0;
          DAT_20001460 = 2;
          DAT_20001461 = 0;
          DAT_20001470 = 0;
          _DAT_20001464 = 0xd;
          DAT_20001468 = 100;
          DAT_20001472 = 1;
          FUN_08010ff8((undefined4 *)0x2000146c);
        }
      }
      else if (DAT_200004dc != '\v') {
        DAT_200004dc = '\v';
        FUN_080117bc(0,0,0);
        _DAT_20001654 = FUN_080116fc((uint)DAT_2000032a,0xff0000);
        _DAT_2000168c = 0;
        DAT_20001690 = 1;
        DAT_20001691 = 0;
        DAT_200016a1 = 0;
        DAT_200016a0 = 0;
        _DAT_20001694 = 6;
        DAT_20001698 = 100;
        DAT_200016a2 = 2;
        FUN_08010ff8((undefined4 *)0x2000169c);
        _DAT_20001424 = FUN_080116fc((uint)DAT_2000032a,0xff0000);
        _DAT_20001428 = 0;
        DAT_20001460 = 2;
        DAT_20001461 = 0;
        DAT_20001470 = 0;
        _DAT_20001464 = 0xd;
        DAT_20001468 = 100;
        DAT_20001472 = 1;
        FUN_08010ff8((undefined4 *)0x2000146c);
      }
    }
    else if (DAT_200004dc != '\b') {
      DAT_200004dc = '\b';
      FUN_080117bc(0,0,0);
      _DAT_20001424 = FUN_080116fc((uint)DAT_2000032a,0xff7f00);
      _DAT_20001428 = 0;
      DAT_20001460 = 2;
      DAT_20001461 = 0;
      DAT_20001470 = 0;
      _DAT_20001464 = 0x19;
      DAT_20001468 = 100;
      DAT_20001472 = 0;
      FUN_08010ff8((undefined4 *)0x2000146c);
    }
  }
  else {
    if (DAT_200004dc != '\r') {
      DAT_200004dc = '\r';
      FUN_080117bc(0,0,0);
      _DAT_20001744 = 0x99ff;
      DAT_20001780 = 1;
      DAT_20001781 = 0;
      DAT_20001790 = 0;
      _DAT_20001784 = 4;
      DAT_20001788 = 100;
      DAT_20001792 = 0;
      FUN_08010ff8((undefined4 *)0x2000178c);
    }
    _DAT_200004da = _DAT_200004da + 1;
    if (0xf9 < _DAT_200004da) {
      _DAT_200004da = 0;
    }
  }
  *FUN_08015e2a = *FUN_08015e2a + 1;
  switch(DAT_200004dc) {
  case '\0':
  case '\x01':
  case '\x02':
  case '\x03':
  case '\x04':
  case '\t':
    if (DAT_200004dd != '\0') {
      DAT_200004dd = '\0';
      FUN_080117bc((uint)DAT_20000321,(uint)DAT_20000322,(uint)DAT_20000323);
    }
    if (DAT_2000031f == '\0') {
      FUN_08013320();
    }
    else {
      FUN_08015356();
    }
    break;
  case '\x05':
    DAT_200004dd = '\x01';
    DAT_2000044c = 0xff;
    FUN_08013320();
    FUN_080145aa();
    break;
  case '\x06':
  case '\f':
    DAT_200004dd = '\x01';
    DAT_2000044c = 0xff;
    FUN_08013320();
    if ((uint)_DAT_200004d8 == ((int)(uint)_DAT_200004d8 >> 1) * 2) {
      FUN_08013f8e();
    }
    else {
      FUN_080141b2();
    }
    break;
  case '\a':
  case '\v':
    DAT_200004dd = '\x01';
    DAT_2000044c = 0xff;
    FUN_08013320();
    if ((uint)_DAT_200004d8 == ((int)(uint)_DAT_200004d8 >> 1) * 2) {
      FUN_08013f8e();
    }
    else {
      FUN_080141b2();
    }
    break;
  case '\b':
    DAT_200004dd = '\x01';
    DAT_2000044c = 0xff;
    FUN_08013320();
    FUN_08013f8e();
    break;
  case '\n':
    DAT_200004dd = '\x01';
    DAT_2000044c = 0xff;
    FUN_08013d20();
    break;
  case '\r':
    DAT_200004dd = '\x01';
    DAT_2000044c = 0xff;
    FUN_08013940();
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08015caa   (0x08015CAA, 99 Bytes)
 * Body: 0x08015CAA-0x08015D0D
 * --------------------------------------------------------------------- */
void FUN_08015caa(void)

{
  disableIRQinterrupts();
  if ((DAT_20000391 == '\x01') || (DAT_20000391 == '\x03')) {
    if ((DAT_2000031f == '\0') || (DAT_2000031f == '\x01')) {
      FUN_080154b2();
    }
    else if (DAT_2000031f == '\x02') {
      FUN_08013550();
    }
    else if (DAT_2000031f == '\n') {
      FUN_08013288();
    }
    else {
      DAT_2000031f = '\0';
    }
  }
  else if ((DAT_20000391 == '\x02') || (DAT_20000391 == '\x04')) {
    FUN_080133c4();
  }
  else {
    FUN_08013288();
  }
  enableIRQinterrupts();
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08015d0e   (0x08015D0E, 167 Bytes)
 * Body: 0x08015D0E-0x08015DB5
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08015d0e(void)

{
  byte bVar1;
  uint auStack_34 [7];
  
  bVar1 = 0;
  FUN_0801d2ec(auStack_34,(undefined4 *)0x801d944,0x1c);
  _DAT_2000044e = _DAT_2000044e + 1;
  _DAT_20000450 = _DAT_20000450 + 1;
  if (0x32 < _DAT_2000044e) {
    _DAT_2000044e = 0;
    for (; bVar1 < 0xe; bVar1 = bVar1 + 1) {
      FUN_080116e6((char)auStack_34[(_DAT_20000450 + 4) % 7]);
      FUN_080116ec(auStack_34[(_DAT_20000450 + 4) % 7]);
      FUN_080116f4(auStack_34[(_DAT_20000450 + 4) % 7]);
      FUN_08012c24();
    }
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08015db6   (0x08015DB6, 89 Bytes)
 * Body: 0x08015DB6-0x08015E0F
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08015db6(void)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  undefined4 auStack_30 [7];
  
  FUN_0801d2ec(auStack_30,(undefined4 *)&DAT_0801d960,0x1c);
  if ((_DAT_20000034 < 0x1f5) || (_DAT_20000036 < 0x1f5)) {
    if (_DAT_20000036 < 0x1f5) {
      if (_DAT_20000034 < 0x1f5) {
        if ((DAT_200002db & 0x40) == 0x40) {
          if (DAT_20000456 != '\x06') {
            DAT_20000456 = '\x06';
            FUN_080117bc(0,0,0);
            _DAT_200013d4 = FUN_080116fc((uint)DAT_2000032a,0xff0000);
            _DAT_200013d8 = 0;
            DAT_20001410 = 2;
            DAT_20001411 = 0;
            DAT_20001420 = 0;
            _DAT_20001414 = 0x14;
            DAT_20001418 = 100;
            DAT_20001422 = 2;
            FUN_08010ff8((undefined4 *)0x2000141c);
            bVar1 = FUN_080116e6(0);
            uVar2 = FUN_080116ec(0xff0000);
            uVar3 = FUN_080116f4(0xff0000);
            FUN_080117bc(uVar3,uVar2,(uint)bVar1);
          }
        }
        else if (_DAT_200002e2 < 0x23) {
          if (DAT_20000456 != '\x04') {
            DAT_20000456 = '\x04';
            FUN_080117bc(0,0,0);
            _DAT_200013d4 = FUN_080116fc((uint)DAT_2000032a,0xff0000);
            _DAT_200013d8 = 0;
            DAT_20001410 = 2;
            DAT_20001411 = 0;
            DAT_20001420 = 0;
            _DAT_20001414 = 0xf;
            DAT_20001418 = 100;
            FUN_08010ff8((undefined4 *)0x2000141c);
          }
        }
        else if ((_DAT_200002e2 < 0x23) || (0x2b < _DAT_200002e2)) {
          if ((_DAT_200002e2 < 0x2c) || (0x84 < _DAT_200002e2)) {
            if ((_DAT_200002e2 < 0x85) || (0xd48 < _DAT_200002e2)) {
              if (DAT_20000456 != '\0') {
                DAT_20000456 = '\0';
                FUN_080117bc(0,0,0);
                FUN_080125fc(0xb);
              }
            }
            else if (DAT_20000456 != '\x01') {
              DAT_20000456 = '\x01';
              FUN_080117bc(0,0,0);
              _DAT_20001654 = FUN_080116fc((uint)DAT_2000032a,0xff0000);
              _DAT_20001658 = FUN_080116fc((uint)DAT_2000032a,0xff7f00);
              _DAT_2000165c = FUN_080116fc((uint)DAT_2000032a,0xffff00);
              _DAT_20001660 = FUN_080116fc((uint)DAT_2000032a,0xff00);
              _DAT_20001664 = FUN_080116fc((uint)DAT_2000032a,0xffff);
              _DAT_20001668 = FUN_080116fc((uint)DAT_2000032a,0xff);
              _DAT_2000166c = FUN_080116fc((uint)DAT_2000032a,0xff00ff);
              _DAT_2000168c = FUN_080116fc((uint)DAT_2000032a,0xffffff);
              DAT_20001690 = 7;
              DAT_20001691 = 0;
              DAT_200016a1 = 0;
              DAT_200016a0 = 0;
              _DAT_20001694 = 5;
              DAT_20001698 = 100;
              DAT_200016a2 = 0;
              FUN_08010ff8((undefined4 *)0x2000169c);
            }
          }
          else if (DAT_20000456 != '\x02') {
            DAT_20000456 = '\x02';
            FUN_080117bc(0,0,0);
            _DAT_20001654 = FUN_080116fc((uint)DAT_2000032a,0xff0000);
            _DAT_20001658 = FUN_080116fc((uint)DAT_2000032a,0xff7f00);
            _DAT_2000165c = FUN_080116fc((uint)DAT_2000032a,0xffff00);
            _DAT_20001660 = FUN_080116fc((uint)DAT_2000032a,0xff00);
            _DAT_20001664 = FUN_080116fc((uint)DAT_2000032a,0xffff);
            _DAT_20001668 = FUN_080116fc((uint)DAT_2000032a,0xff);
            _DAT_2000166c = FUN_080116fc((uint)DAT_2000032a,0xff00ff);
            _DAT_2000168c = FUN_080116fc((uint)DAT_2000032a,0xffffff);
            DAT_20001690 = 7;
            DAT_20001691 = 0;
            DAT_200016a1 = 0;
            DAT_200016a0 = 0;
            _DAT_20001694 = 2;
            DAT_20001698 = 100;
            DAT_200016a2 = 0;
            FUN_08010ff8((undefined4 *)0x2000169c);
          }
        }
        else if (DAT_20000456 != '\x03') {
          DAT_20000456 = '\x03';
          FUN_080117bc(0,0,0);
          _DAT_200013d4 = FUN_080116fc((uint)DAT_2000032a,0xff0000);
          _DAT_200013d8 = 0;
          _DAT_200013dc = FUN_080116fc((uint)DAT_2000032a,0xff7f00);
          _DAT_200013e0 = 0;
          _DAT_200013e4 = FUN_080116fc((uint)DAT_2000032a,0xffff00);
          _DAT_200013e8 = 0;
          _DAT_200013ec = FUN_080116fc((uint)DAT_2000032a,0xff00);
          _DAT_200013f0 = 0;
          _DAT_200013f4 = FUN_080116fc((uint)DAT_2000032a,0xffff);
          _DAT_200013f8 = 0;
          _DAT_200013fc = FUN_080116fc((uint)DAT_2000032a,0xff);
          _DAT_20001400 = 0;
          _DAT_20001404 = FUN_080116fc((uint)DAT_2000032a,0xff00ff);
          _DAT_20001408 = 0;
          DAT_20001410 = 0xe;
          DAT_20001411 = 0;
          DAT_20001420 = 0;
          _DAT_20001414 = 0x14;
          DAT_20001418 = 100;
          FUN_08010ff8((undefined4 *)0x2000141c);
        }
      }
      else if (DAT_20000456 != '\x06') {
        DAT_20000456 = '\x06';
        FUN_080117bc(0,0,0);
        _DAT_20001654 = FUN_080116fc((uint)DAT_2000032a,0xffff00);
        DAT_20001690 = 1;
        DAT_20001691 = 0;
        DAT_200016a1 = 0;
        DAT_200016a0 = 1;
        _DAT_20001694 = 3;
        DAT_20001698 = 100;
        DAT_200016a2 = 2;
        FUN_08010ff8((undefined4 *)0x2000169c);
        _DAT_200013d4 = FUN_080116fc((uint)DAT_2000032a,0xffff00);
        _DAT_200013d8 = 0;
        DAT_20001410 = 2;
        DAT_20001411 = 0;
        DAT_20001420 = 0;
        _DAT_20001414 = 0xf;
        DAT_20001418 = 100;
        DAT_20001422 = 3;
        FUN_08010ff8((undefined4 *)0x2000141c);
      }
    }
    else if (DAT_20000456 != '\a') {
      DAT_20000456 = '\a';
      FUN_080117bc(0,0,0);
      _DAT_20001654 = FUN_080116fc((uint)DAT_2000032a,0xffff00);
      DAT_20001690 = 1;
      DAT_20001691 = 0;
      DAT_200016a1 = 0;
      DAT_200016a0 = 0;
      _DAT_20001694 = 3;
      DAT_20001698 = 100;
      DAT_200016a2 = 2;
      FUN_08010ff8((undefined4 *)0x2000169c);
      _DAT_200013d4 = FUN_080116fc((uint)DAT_2000032a,0xffff00);
      _DAT_200013d8 = 0;
      DAT_20001410 = 2;
      DAT_20001411 = 0;
      DAT_20001420 = 0;
      _DAT_20001414 = 0xf;
      DAT_20001418 = 100;
      DAT_20001422 = 1;
      FUN_08010ff8((undefined4 *)0x2000141c);
    }
  }
  else if (DAT_20000456 != '\b') {
    DAT_20000456 = '\b';
    FUN_080117bc(0,0,0);
    _DAT_200013d4 = FUN_080116fc((uint)DAT_2000032a,0xffff00);
    _DAT_200013d8 = 0;
    DAT_20001410 = 2;
    DAT_20001411 = 0;
    DAT_20001420 = 0;
    _DAT_20001414 = 0xf;
    DAT_20001418 = 100;
    DAT_20001422 = 0;
    FUN_08010ff8((undefined4 *)0x2000141c);
  }
  FUN_08013320();
  switch(DAT_20000456) {
  case '\0':
    FUN_08013d20();
    break;
  case '\x01':
    FUN_080141b2();
    break;
  case '\x02':
    FUN_080141b2();
    break;
  case '\x03':
    FUN_080145aa();
    break;
  case '\x04':
    FUN_080145aa();
    break;
  case '\x05':
    FUN_080145aa();
    FUN_08013320();
    break;
  case '\x06':
    FUN_080141b2();
    FUN_080145aa();
    break;
  case '\a':
    FUN_080141b2();
    FUN_080145aa();
    break;
  case '\b':
    FUN_080145aa();
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08015e2a   (0x08015E2A, 252 Bytes, 4 Teile)
 * Body: 0x08015E2A-0x08015E89, 0x08015EDA-0x08015F21, 0x0801635C-0x0801636B, 0x08016376-0x080163BD
 * --------------------------------------------------------------------- */
/* WARNING: Removing unreachable block (ram,0x08015e52) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08015e2a(void)

{
  int unaff_r4;
  
  FUN_08010ff8((undefined4 *)((unaff_r4 >> 0x1a) * 0x4000000 + 0x48));
  _DAT_200013d4 = FUN_080116fc((uint)DAT_2000032a,0xffff00);
  _DAT_200013d8 = 0;
  DAT_20001410 = 2;
  DAT_20001411 = 0;
  DAT_20001420 = 0;
  _DAT_20001414 = 0xf;
  DAT_20001418 = 100;
  DAT_20001422 = 1;
  FUN_08010ff8((undefined4 *)0x2000141c);
  FUN_08013320();
  switch(DAT_20000456) {
  case 0:
    FUN_08013d20();
    break;
  case 1:
    FUN_080141b2();
    break;
  case 2:
    FUN_080141b2();
    break;
  case 3:
    FUN_080145aa();
    break;
  case 4:
    FUN_080145aa();
    break;
  case 5:
    FUN_080145aa();
    FUN_08013320();
    break;
  case 6:
    FUN_080141b2();
    FUN_080145aa();
    break;
  case 7:
    FUN_080141b2();
    FUN_080145aa();
    break;
  case 8:
    FUN_080145aa();
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08015e68   (0x08015E68, 31 Bytes)
 * Body: 0x08015E68-0x08015E87
 * --------------------------------------------------------------------- */
void FUN_08015e68(undefined1 param_1,int param_2)

{
  *(undefined1 *)(param_2 + 0x3d) = param_1;
  *(undefined1 *)(param_2 + 0x4c) = param_1;
  *(undefined4 *)(param_2 + 0x40) = 0xf;
  *(undefined1 *)(param_2 + 0x44) = 100;
  *(undefined1 *)(param_2 + 0x4e) = 0;
  FUN_08010ff8((undefined4 *)(param_2 + 0x48));
  FUN_08013320();
  switch(DAT_20000456) {
  case 0:
    FUN_08013d20();
    break;
  case 1:
    FUN_080141b2();
    break;
  case 2:
    FUN_080141b2();
    break;
  case 3:
    FUN_080145aa();
    break;
  case 4:
    FUN_080145aa();
    break;
  case 5:
    FUN_080145aa();
    FUN_08013320();
    break;
  case 6:
    FUN_080141b2();
    FUN_080145aa();
    break;
  case 7:
    FUN_080141b2();
    FUN_080145aa();
    break;
  case 8:
    FUN_080145aa();
  }
  return;
}


/* ---------------------------------------------------------------------
 * thunk_FUN_0801635c   (0x08015E88, 1 Bytes)
 * Body: 0x08015E88-0x08015E89
 * --------------------------------------------------------------------- */
void thunk_FUN_0801635c(void)

{
  FUN_08013320();
  switch(DAT_20000456) {
  case 0:
    FUN_08013d20();
    break;
  case 1:
    FUN_080141b2();
    break;
  case 2:
    FUN_080141b2();
    break;
  case 3:
    FUN_080145aa();
    break;
  case 4:
    FUN_080145aa();
    break;
  case 5:
    FUN_080145aa();
    FUN_08013320();
    break;
  case 6:
    FUN_080141b2();
    FUN_080145aa();
    break;
  case 7:
    FUN_080141b2();
    FUN_080145aa();
    break;
  case 8:
    FUN_080145aa();
  }
  return;
}



/* =====================================================================
 *  SEKTION: 0x08016000 - EEPROM/Settings, Init-Sequenz, Tasks
 * ===================================================================== */

/* ---------------------------------------------------------------------
 * FUN_0801635c   (0x0801635C, 86 Bytes, 2 Teile)
 * Body: 0x0801635C-0x0801636B, 0x08016376-0x080163BD
 * --------------------------------------------------------------------- */
void FUN_0801635c(void)

{
  FUN_08013320();
  switch(DAT_20000456) {
  case 0:
    FUN_08013d20();
    break;
  case 1:
    FUN_080141b2();
    break;
  case 2:
    FUN_080141b2();
    break;
  case 3:
    FUN_080145aa();
    break;
  case 4:
    FUN_080145aa();
    break;
  case 5:
    FUN_080145aa();
    FUN_08013320();
    break;
  case 6:
    FUN_080141b2();
    FUN_080145aa();
    break;
  case 7:
    FUN_080141b2();
    FUN_080145aa();
    break;
  case 8:
    FUN_080145aa();
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_080163be   (0x080163BE, 171 Bytes)
 * Body: 0x080163BE-0x08016469
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_080163be(void)

{
  undefined4 auStack_24 [7];
  
  FUN_0801d2ec(auStack_24,(undefined4 *)&DAT_0801d97c,0x1c);
  if (DAT_2000045c == '\0') {
    DAT_2000045c = '\x01';
    FUN_080117bc(0,0,0);
    _DAT_20001654 = FUN_080116fc((uint)DAT_2000032a,0xffff00);
    DAT_20001690 = 1;
    DAT_20001691 = 0;
    DAT_200016a1 = 0;
    DAT_200016a0 = 0;
    _DAT_20001694 = 3;
    DAT_20001698 = 100;
    DAT_200016a2 = 2;
    FUN_08010ff8((undefined4 *)0x2000169c);
    _DAT_200013d4 = FUN_080116fc((uint)DAT_2000032a,0xffff00);
    _DAT_200013d8 = 0;
    DAT_20001410 = 2;
    DAT_20001411 = 0;
    DAT_20001420 = 0;
    _DAT_20001414 = 0xf;
    DAT_20001418 = 100;
    DAT_20001422 = 1;
    FUN_08010ff8((undefined4 *)0x2000141c);
  }
  FUN_08013320();
  FUN_080145aa();
  FUN_080141b2();
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801646a   (0x0801646A, 493 Bytes)
 * Body: 0x0801646A-0x08016657
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0801646a(void)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  local_14 = 0;
  local_18 = 0;
  local_1c = 0;
  iVar2 = FUN_0801326e((uint *)0x200014bc,_DAT_200014b4);
  if (iVar2 == 1) {
    FUN_08013268((undefined4 *)0x200014bc);
    if (DAT_200014c1 == 0) {
      DAT_200014c1 = 1;
      uVar3 = FUN_080116f4(*(uint *)(&DAT_20001474 +
                                    ((uint)DAT_200014b1 -
                                    (uint)DAT_200014b0 * ((uint)DAT_200014b1 / (uint)DAT_200014b0))
                                    * 4));
      DAT_20000468 = (byte)uVar3;
      uVar3 = FUN_080116ec(*(uint *)(&DAT_20001474 +
                                    ((uint)DAT_200014b1 -
                                    (uint)DAT_200014b0 * ((uint)DAT_200014b1 / (uint)DAT_200014b0))
                                    * 4));
      DAT_20000469 = (byte)uVar3;
      DAT_2000046a = FUN_080116e6((char)*(undefined4 *)
                                         (&DAT_20001474 +
                                         ((uint)DAT_200014b1 -
                                         (uint)DAT_200014b0 *
                                         ((uint)DAT_200014b1 / (uint)DAT_200014b0)) * 4));
      DAT_200014b1 = DAT_200014b1 + 1;
      FUN_08011378((uint)DAT_20000468,(uint)DAT_20000469,(uint)DAT_2000046a,
                   (ulonglong *)&DAT_20000470,(undefined8 *)&DAT_20000478,
                   (undefined8 *)&DAT_20000480);
      _DAT_20000488 = 0;
    }
    FUN_080111b4((uint)_DAT_20000478,(uint)((ulonglong)_DAT_20000478 >> 0x20),(uint)_DAT_20000488,
                 (uint)(_DAT_20000488 >> 0x20),(undefined1 *)&local_14,(undefined1 *)&local_18,
                 (undefined1 *)&local_1c);
    for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
      FUN_080130a2();
    }
    for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
      FUN_08012ec6();
    }
    for (bVar1 = 0; bVar1 < 0xe; bVar1 = bVar1 + 1) {
      FUN_08012d00();
    }
    uVar5 = DAT_200014c1 != 0;
    uVar4 = DAT_200014c1 == 1;
    uVar3 = (uint)(_DAT_20000488 >> 0x20);
    if ((bool)uVar4) {
      _DAT_20000488 = FUN_0801d342((uint)_DAT_20000488,uVar3,0xeb851eb8,0x3f9eb851);
      FUN_0801d6d0((int)_DAT_20000488,(int)(_DAT_20000488 >> 0x20));
      if (!(bool)uVar5 || (bool)uVar4) {
        _DAT_20000488 = _DAT_20000480;
        DAT_200014c1 = 2;
      }
    }
    else {
      uVar5 = 1 < DAT_200014c1;
      uVar4 = DAT_200014c1 == 2;
      if ((bool)uVar4) {
        _DAT_20000488 = FUN_0801d484((uint)_DAT_20000488,uVar3,0xeb851eb8,0x3f9eb851);
        FUN_0801d6a0((int)_DAT_20000488,(int)(_DAT_20000488 >> 0x20));
        if (!(bool)uVar5 || (bool)uVar4) {
          _DAT_20000488 = 0;
          DAT_200014c1 = 0;
        }
      }
    }
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08016658   (0x08016658, 654 Bytes, 2 Teile)
 * Body: 0x08016658-0x080166A7, 0x08016704-0x08016943
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08016658(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = 0xe;
  iVar1 = FUN_0801326e((uint *)0x200016ec,_DAT_200016e4);
  if (iVar1 == 1) {
    FUN_08013268((undefined4 *)0x200016ec);
    if (DAT_200016f1 == '\0') {
      if (DAT_200004bf < 0x14) {
        uVar3 = FUN_080116f4(0xff0000);
        DAT_200004b8 = (undefined1)uVar3;
        uVar3 = FUN_080116ec(0xff0000);
        DAT_200004b9 = (undefined1)uVar3;
        DAT_200004ba = FUN_080116e6(0);
        _DAT_200013d4 = 0xff0000;
        _DAT_200013d8 = 0;
      }
      else if (DAT_200004bf < 0x32) {
        uVar3 = FUN_080116f4(0xffff00);
        DAT_200004b8 = (undefined1)uVar3;
        uVar3 = FUN_080116ec(0xffff00);
        DAT_200004b9 = (undefined1)uVar3;
        DAT_200004ba = FUN_080116e6(0);
        _DAT_200013d4 = 0xffff00;
        _DAT_200013d8 = 0;
      }
      else if (DAT_200004bf < 100) {
        uVar3 = FUN_080116f4(0x99ff);
        DAT_200004b8 = (undefined1)uVar3;
        uVar3 = FUN_080116ec(0x99ff);
        DAT_200004b9 = (undefined1)uVar3;
        DAT_200004ba = FUN_080116e6(0xff);
        _DAT_200013d4 = 0xf5424;
        _DAT_200013d8 = 0;
      }
      else {
        uVar3 = FUN_080116f4(0x99ff);
        DAT_200004b8 = (undefined1)uVar3;
        uVar3 = FUN_080116ec(0x99ff);
        DAT_200004b9 = (undefined1)uVar3;
        DAT_200004ba = FUN_080116e6(0xff);
        _DAT_200013d4 = 0x99ff;
        _DAT_200013d8 = 0x99ff;
      }
      uVar3 = FUN_080116f4(_DAT_200016dc);
      DAT_200004bb = (undefined1)uVar3;
      uVar3 = FUN_080116ec(_DAT_200016dc);
      DAT_200004bc = (undefined1)uVar3;
      DAT_200004bd = FUN_080116e6((char)_DAT_200016dc);
      DAT_200016e1 = DAT_200016e1 + '\x01';
      DAT_200016f1 = '\x01';
    }
    _DAT_200004c0 = _DAT_200004c0 + 1;
    if (5 < _DAT_200004c0) {
      _DAT_200004c0 = 0;
      DAT_200004bf = DAT_200004bf + 1;
      if (100 < DAT_200004bf) {
        DAT_200004bf = 100;
      }
    }
    if (DAT_200004bf < 100) {
      uVar3 = (int)(uint)DAT_200004bf >> 3;
    }
    else {
      uVar3 = 0xe;
    }
    if (0xe < uVar3) {
      uVar3 = 0xe;
    }
    DAT_200004c2 = '\x01';
    DAT_200004c3 = 0;
    if ((DAT_200016f1 == '\x01') &&
       (DAT_200004be = DAT_200004be + 1, 0xe - uVar3 < (uint)DAT_200004be)) {
      DAT_200004be = 0;
      DAT_200016f1 = '\0';
    }
  }
  if (DAT_200004c2 != '\0') {
    if (DAT_200004c3 == 0) {
      for (uVar2 = 0; uVar2 < 0xe; uVar2 = uVar2 + 1 & 0xff) {
        if (uVar3 < uVar2) {
          if (uVar2 < 0xe - DAT_200004be) {
            FUN_080130a2();
          }
          else {
            FUN_080130a2();
          }
        }
        else {
          FUN_080130a2();
        }
      }
    }
    else if (DAT_200004c3 == 1) {
      for (uVar2 = 0; uVar2 < 0xe; uVar2 = uVar2 + 1 & 0xff) {
        if (uVar3 < uVar2) {
          if (uVar2 < 0xe - DAT_200004be) {
            FUN_08012ec6();
          }
          else {
            FUN_08012ec6();
          }
        }
        else {
          FUN_08012ec6();
        }
      }
    }
    DAT_200004c3 = DAT_200004c3 + 1;
    if (1 < DAT_200004c3) {
      DAT_200004c3 = 0;
      DAT_200004c2 = '\0';
    }
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08016944   (0x08016944, 159 Bytes)
 * Body: 0x08016944-0x080169E3
 * --------------------------------------------------------------------- */
void FUN_08016944(uint param_1,uint param_2,uint param_3,uint param_4,undefined1 *param_5,
                 undefined1 *param_6,undefined1 *param_7)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined8 local_50;
  undefined8 local_48;
  ulonglong local_40 [4];
  
  local_40[0] = 0;
  local_48 = 0;
  local_50 = 0;
  FUN_08011378(param_2,param_3,param_4,local_40,&local_48,&local_50);
  uVar2 = FUN_0801d652(param_1);
  uVar2 = FUN_0801d490((uint)uVar2,(uint)(uVar2 >> 0x20),(uint)local_50,
                       (uint)((ulonglong)local_50 >> 0x20));
  uVar2 = FUN_0801d574((uint)uVar2,(uint)(uVar2 >> 0x20),0,0x40590000);
  lVar1 = (uVar2 & 0xffffffff00000000) + (uVar2 & 0xffffffff);
  FUN_080111b4((uint)local_48,(uint)((ulonglong)local_48 >> 0x20),(uint)lVar1,
               (uint)((ulonglong)lVar1 >> 0x20),param_5,param_6,param_7);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08016a30   (0x08016A30, 17 Bytes)
 * Body: 0x08016A30-0x08016A41
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08016a30(void)

{
  _DAT_2000183c = 0;
  _DAT_2000183a = 0;
  _DAT_2000183e = 0;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08016a42   (0x08016A42, 39 Bytes)
 * Body: 0x08016A42-0x08016A69
 * --------------------------------------------------------------------- */
void FUN_08016a42(void)

{
  uint uVar1;
  
  FUN_08016a30();
  DAT_200017c0 = 0;
  DAT_20001844 = 0;
  for (uVar1 = 0; uVar1 < 0x78; uVar1 = uVar1 + 1 & 0xffff) {
    *(undefined1 *)(uVar1 + 0x200017c1) = 0;
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08016a6a   (0x08016A6A, 273 Bytes)
 * Body: 0x08016A6A-0x08016B7B
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08016a6a(int param_1,byte *param_2)

{
  uint uVar1;
  
  if (param_1 == 0x711) {
    if (*param_2 == 2) {
      DAT_20001844 = param_2[1];
    }
    if ((*param_2 == 3) && (param_2[1] == 0)) {
      DAT_200017c0 = '\0';
      FUN_08016a30();
    }
    else if ((*param_2 == 3) && (param_2[1] == 1)) {
      DAT_200017c0 = '\x04';
      FUN_08016a30();
    }
    else if (*param_2 == 4) {
      if (CONCAT11(param_2[2],param_2[3]) < 0x79) {
        _DAT_2000183a = (ushort)param_2[1];
        DAT_200017c0 = '\x01';
        _DAT_2000183e = 0;
        _DAT_2000183c = CONCAT11(param_2[2],param_2[3]);
      }
    }
    else if (((*param_2 & 0xf0) == 0x10) && (DAT_200017c0 == '\x01')) {
      if ((*param_2 & 0xf) == _DAT_2000183e) {
        for (uVar1 = 0; (uVar1 < 7 && ((uint)_DAT_2000183e * 7 + uVar1 < (uint)_DAT_2000183c));
            uVar1 = uVar1 + 1 & 0xff) {
          *(byte *)((uint)_DAT_2000183e * 7 + uVar1 + 0x200017c1) = param_2[uVar1 + 1];
        }
        _DAT_2000183e = _DAT_2000183e + 1;
        if (_DAT_2000183a <= _DAT_2000183e) {
          DAT_200017c0 = '\x02';
          _DAT_2000183e = 0;
        }
      }
      else {
        DAT_200017c0 = '\0';
      }
    }
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08016b7c   (0x08016B7C, 33 Bytes)
 * Body: 0x08016B7C-0x08016B9D
 * --------------------------------------------------------------------- */
bool FUN_08016b7c(int param_1)

{
  return (*(byte *)(param_1 + 0x141) + 1) % 0x14 == (uint)*(byte *)(param_1 + 0x140);
}


/* ---------------------------------------------------------------------
 * FUN_08016b9e   (0x08016B9E, 119 Bytes)
 * Body: 0x08016B9E-0x08016C15
 * --------------------------------------------------------------------- */
undefined4 FUN_08016b9e(int param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 local_8;
  undefined4 uStack_4;
  
  local_8 = param_3;
  uStack_4 = param_4;
  bVar1 = FUN_08016b7c(param_1);
  if (bVar1) {
    uVar3 = 2;
  }
  else if ((byte)local_8 < 9) {
    *(byte *)(param_1 + (uint)*(byte *)(param_1 + 0x141) * 0x10 + 4) = (byte)local_8;
    *(undefined4 *)(param_1 + (uint)*(byte *)(param_1 + 0x141) * 0x10) = param_2;
    for (uVar2 = 0; uVar2 < (local_8 & 0xff); uVar2 = uVar2 + 1 & 0xffff) {
      *(undefined1 *)(param_1 + (uint)*(byte *)(param_1 + 0x141) * 0x10 + 5 + uVar2) =
           *(undefined1 *)((int)&local_8 + uVar2 + 1);
    }
    uVar2 = *(byte *)(param_1 + 0x141) + 1;
    *(char *)(param_1 + 0x141) = (char)uVar2 + (char)(uVar2 / 0x14) * -0x14;
    uVar3 = 0;
  }
  else {
    uVar3 = 2;
  }
  return uVar3;
}


/* ---------------------------------------------------------------------
 * FUN_08016c16   (0x08016C16, 284 Bytes, 2 Teile)
 * Body: 0x08016C16-0x08016D2B, 0x08016D2E-0x08016D35
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08016c16(int param_1,uint param_2)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 local_24;
  uint3 local_20;
  undefined1 local_1d;
  undefined1 local_1c;
  undefined3 uStack_1b;
  
  uVar3 = 0;
  if ((DAT_20001844 != '\0') && (param_2 < 0x78)) {
    _DAT_200018c0 = (ushort)param_2;
    if ((param_2 & 0xffff) == ((param_2 & 0xffff) / 7) * 7) {
      _DAT_200018be = _DAT_200018c0 / 7;
    }
    else {
      _DAT_200018be = _DAT_200018c0 / 7 + 1;
    }
    local_24 = CONCAT13((char)(param_2 >> 8),CONCAT12(DAT_200018be,0x400));
    local_20 = (uint3)(_DAT_200018c0 & 0xff);
    _local_20 = CONCAT13(0xaa,local_20);
    _local_1c = CONCAT31(uStack_1b,0x55);
    local_24 = CONCAT31(local_24._1_3_,8);
    FUN_08016b9e(0x200018c4,0x712,local_24,_local_20);
    for (uVar1 = 0; uVar1 < _DAT_200018be; uVar1 = uVar1 + 1) {
      for (uVar2 = 0; uVar2 < 7; uVar2 = uVar2 + 1 & 0xffff) {
        if (uVar3 < _DAT_200018c0) {
          *(undefined1 *)((int)&local_24 + uVar2 + 2) = *(undefined1 *)(param_1 + uVar3);
        }
        else {
          *(undefined1 *)((int)&local_24 + uVar2 + 2) = 0;
        }
        uVar3 = uVar3 + 1 & 0xffff;
      }
      local_24 = CONCAT31(CONCAT21(local_24._2_2_,(char)uVar1 + '\x10'),8);
      FUN_08016b9e(0x200018c4,0x712,local_24,_local_20);
    }
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08016d36   (0x08016D36, 84 Bytes, 2 Teile)
 * Body: 0x08016D36-0x08016D4B, 0x08016D52-0x08016D91
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_08016d36(int param_1,ushort *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar1 = 0;
  uVar2 = 0;
  switch(DAT_200017c0) {
  case 0:
    uVar1 = 0;
    break;
  case 1:
    uVar1 = 1;
    break;
  case 2:
    uVar1 = 2;
    *param_2 = _DAT_2000183c;
    for (uVar2 = 0; uVar2 < _DAT_2000183c; uVar2 = uVar2 + 1 & 0xffff) {
      *(undefined1 *)(param_1 + uVar2) = *(undefined1 *)(uVar2 + 0x200017c1);
    }
    DAT_200017c0 = 3;
    break;
  case 3:
    uVar1 = 1;
    break;
  case 4:
    uVar1 = 1;
  }
  return CONCAT44(uVar2,uVar1);
}


/* ---------------------------------------------------------------------
 * FUN_08016d92   (0x08016D92, 21 Bytes)
 * Body: 0x08016D92-0x08016DA7
 * --------------------------------------------------------------------- */
bool FUN_08016d92(int param_1)

{
  return *(char *)(param_1 + 0x140) == *(char *)(param_1 + 0x141);
}


/* ---------------------------------------------------------------------
 * FUN_08016da8   (0x08016DA8, 57 Bytes)
 * Body: 0x08016DA8-0x08016DE1
 * --------------------------------------------------------------------- */
bool FUN_08016da8(int param_1,undefined4 *param_2)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  
  bVar1 = FUN_08016d92(param_1);
  if (!bVar1) {
    puVar5 = (undefined4 *)(param_1 + (uint)*(byte *)(param_1 + 0x140) * 0x10);
    uVar3 = puVar5[1];
    uVar4 = puVar5[2];
    uVar6 = puVar5[3];
    *param_2 = *puVar5;
    param_2[1] = uVar3;
    param_2[2] = uVar4;
    param_2[3] = uVar6;
    uVar2 = *(byte *)(param_1 + 0x140) + 1;
    *(char *)(param_1 + 0x140) = (char)uVar2 + (char)(uVar2 / 0x14) * -0x14;
  }
  return bVar1;
}


/* ---------------------------------------------------------------------
 * FUN_08016de2   (0x08016DE2, 78 Bytes, 2 Teile)
 * Body: 0x08016DE2-0x08016E11, 0x08016E1C-0x08016E3B
 * --------------------------------------------------------------------- */
undefined4 FUN_08016de2(int param_1,ushort *param_2,int *param_3,undefined4 param_4)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  int local_30;
  undefined4 local_2c;
  int *piStack_28;
  undefined4 uStack_24;
  
  uVar3 = 0;
  uVar2 = 0;
  local_30 = param_1;
  local_2c = param_2;
  piStack_28 = param_3;
  uStack_24 = param_4;
  bVar1 = FUN_08016da8(0x200018c4,&local_30);
  if (!bVar1) {
    *param_2 = (ushort)(byte)local_2c;
    *param_3 = local_30;
    for (; uVar2 < ((uint)local_2c & 0xff); uVar2 = uVar2 + 1 & 0xff) {
      *(undefined1 *)(param_1 + uVar2) = *(undefined1 *)((int)&local_2c + uVar2 + 1);
    }
    uVar3 = 2;
  }
  return uVar3;
}


/* ---------------------------------------------------------------------
 * FUN_08016e3c   (0x08016E3C, 5 Bytes)
 * Body: 0x08016E3C-0x08016E41
 * --------------------------------------------------------------------- */
undefined1 FUN_08016e3c(void)

{
  return DAT_200017c0;
}


/* ---------------------------------------------------------------------
 * FUN_08016e88   (0x08016E88, 21 Bytes)
 * Body: 0x08016E88-0x08016E9D
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08016e88(void)

{
  disableIRQinterrupts();
  _DAT_e000ed0c = (_DAT_e000ed0c & 0x700 | 0x5fa0000) + 1;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08016e9e   (0x08016E9E, 25 Bytes)
 * Body: 0x08016E9E-0x08016EB7
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_08016e9e(void)

{
  bool bVar1;
  
  FUN_08019c44((int)_DAT_200004ec,1);
  bVar1 = FUN_08019bfe(_DAT_200004ec,-0x5a5a5a5b);
  return bVar1;
}


/* ---------------------------------------------------------------------
 * FUN_08016eb8   (0x08016EB8, 7 Bytes)
 * Body: 0x08016EB8-0x08016EBF
 * --------------------------------------------------------------------- */
bool FUN_08016eb8(void)

{
  bool bVar1;
  
  bVar1 = FUN_08016e9e();
  return bVar1;
}


/* ---------------------------------------------------------------------
 * FUN_08016ec0   (0x08016EC0, 15 Bytes)
 * Sonderpfad: Display-0x8B-Sequenz (Zweck nicht abschliessend geklaert)
 * Body: 0x08016EC0-0x08016ECF
 * --------------------------------------------------------------------- */
void FUN_08016ec0(void)

{
  FUN_0801965c();
  FUN_08016eb8();
  FUN_08016e88();
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08016f74   (0x08016F74, 3 Bytes)
 * Body: 0x08016F74-0x08016F77
 * --------------------------------------------------------------------- */
void FUN_08016f74(uint param_1,uint param_2,undefined1 *param_3)

{
  *(uint *)(param_1 + 0x40) = param_1;
  FUN_0800b990((undefined1 *)0x20001ab8,param_3,param_2);
  FUN_08018ffe(param_1 & 0xffff,(byte *)0x20001ab8,param_2);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08016f78   (0x08016F78, 29 Bytes)
 * Body: 0x08016F78-0x08016F95
 * --------------------------------------------------------------------- */
void FUN_08016f78(ushort param_1,uint param_2,undefined1 *param_3)

{
  FUN_0800b990((undefined1 *)0x20001ab8,param_3,param_2);
  FUN_08018ffe((uint)param_1,(byte *)0x20001ab8,param_2);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08016f96   (0x08016F96, 45 Bytes)
 * Body: 0x08016F96-0x08016FC3
 * --------------------------------------------------------------------- */
void FUN_08016f96(undefined4 param_1,int param_2)

{
  uint uVar1;
  
  for (uVar1 = 0; (int)uVar1 < param_2; uVar1 = uVar1 + 1 & 0xffff) {
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08016fc4   (0x08016FC4, 162 Bytes, 2 Teile)
 * EEPROM-Save (Blockindex in r0): Pruefsumme + I2C-Write
 * Body: 0x08016FC4-0x08016FCF, 0x08016FD6-0x0801706D
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08016fc4(undefined4 param_1)

{
  switch(param_1) {
  case 0:
    _DAT_20001a56 = FUN_08016f96(&DAT_20001a08,0x4e);
    FUN_08016f78(0,0x50,&DAT_20001a08);
    break;
  case 1:
    _DAT_20001a8c = FUN_08016f96(&DAT_20001a58,0x34);
    FUN_08016f78(0x50,0x38,&DAT_20001a58);
    break;
  case 2:
    _DAT_20001a9a = FUN_08016f96(&DAT_20001a90,10);
    FUN_08016f78(0x88,0xc,&DAT_20001a90);
    break;
  case 3:
    _DAT_20001aa6 = FUN_08016f96(&DAT_20001a9c,10);
    FUN_08016f78(0x94,0xc,&DAT_20001a9c);
    break;
  case 4:
    _DAT_20001ab6 = FUN_08016f96(&DAT_20001aa8,0xe);
    FUN_08016f78(0xa0,0x10,&DAT_20001aa8);
    break;
  case 5:
    _DAT_200004f6 = FUN_08016f96(&DAT_200004f2,4);
    FUN_08016f78(0xb0,6,&DAT_200004f2);
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801706e   (0x0801706E, 21 Bytes)
 * Body: 0x0801706E-0x08017083
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0801706e(void)

{
  DAT_200004f2 = 0;
  DAT_200004f3 = 0;
  _DAT_200004f4 = 0xff;
  FUN_08016fc4(5);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08017084   (0x08017084, 29 Bytes)
 * EEPROM-Read: liest N Bytes ab Blockadresse
 * Body: 0x08017084-0x080170A1
 * --------------------------------------------------------------------- */
void FUN_08017084(ushort param_1,uint param_2,undefined1 *param_3)

{
  FUN_08018fd4((uint)param_1,(undefined1 *)0x20001ab8,param_2);
  FUN_0800b990(param_3,(undefined1 *)0x20001ab8,param_2);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_080170a2   (0x080170A2, 63 Bytes)
 * Body: 0x080170A2-0x080170E1
 * --------------------------------------------------------------------- */
void FUN_080170a2(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  undefined4 uStack_10;
  uint local_c;
  
  uStack_10 = param_3;
  local_c = param_4;
  FUN_08017084(0xb0,6,(undefined1 *)&uStack_10);
  uVar1 = FUN_08016f96(&uStack_10,4);
  if ((local_c & 0xffff) == uVar1) {
    FUN_0800b990(&DAT_200004f2,(undefined1 *)&uStack_10,6);
  }
  else {
    FUN_0801706e();
  }
  DAT_20000399 = DAT_200004f2;
  DAT_2000039a = DAT_200004f2;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_080170e2   (0x080170E2, 43 Bytes)
 * Body: 0x080170E2-0x0801710D
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_080170e2(void)

{
  DAT_20001aa8 = 1;
  DAT_20001aa9 = 1;
  DAT_20001aaa = 0;
  DAT_20001aab = 0;
  DAT_20001aac = 0;
  _DAT_20001aae = 0;
  DAT_20001ab0 = 0x32;
  DAT_20001ab1 = 1;
  DAT_20001ab2 = 0;
  _DAT_20001ab4 = 0xff;
  FUN_08016fc4(4);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801710e   (0x0801710E, 119 Bytes)
 * Body: 0x0801710E-0x08017185
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_0801710e(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  uint uStack_c;
  
  uStack_18 = param_1;
  uStack_14 = param_2;
  uStack_10 = param_3;
  uStack_c = param_4;
  FUN_08017084(0xa0,0x10,(undefined1 *)&uStack_18);
  uVar1 = FUN_08016f96(&uStack_18,0xe);
  if (uStack_c >> 0x10 == uVar1) {
    FUN_0800b990(&DAT_20001aa8,(undefined1 *)&uStack_18,0x10);
  }
  else {
    FUN_080170e2();
  }
  DAT_2000031f = DAT_20001aa8;
  DAT_20000320 = DAT_20001aa9;
  DAT_20000321 = DAT_20001aaa;
  DAT_20000322 = DAT_20001aab;
  DAT_20000323 = DAT_20001aac;
  _DAT_20000328 = _DAT_20001aae;
  DAT_2000032a = DAT_20001ab0;
  DAT_2000032b = DAT_20001ab1;
  DAT_2000032c = DAT_20001ab2;
  return CONCAT44(uStack_14,uStack_18);
}


/* ---------------------------------------------------------------------
 * FUN_08017186   (0x08017186, 21 Bytes)
 * Body: 0x08017186-0x0801719B
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08017186(void)

{
  _DAT_20001a9c = 0;
  _DAT_20001aa0 = 0;
  _DAT_20001aa4 = 0xff;
  FUN_08016fc4(3);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801719c   (0x0801719C, 77 Bytes)
 * Body: 0x0801719C-0x080171E9
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0801719c(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  undefined4 uStack_18;
  undefined4 uStack_14;
  uint uStack_10;
  
  uStack_18 = param_2;
  uStack_14 = param_3;
  uStack_10 = param_4;
  FUN_08017084(0x94,0xc,(undefined1 *)&uStack_18);
  uVar1 = FUN_08016f96(&uStack_18,10);
  if (uStack_10 >> 0x10 == uVar1) {
    FUN_0800b990(&DAT_20001a9c,(undefined1 *)&uStack_18,0xc);
  }
  else {
    FUN_08017186();
  }
  if (_DAT_20001aa0 < _DAT_20001a94) {
    _DAT_20000300 = _DAT_20001a90;
  }
  else {
    _DAT_20000300 = _DAT_20001a9c;
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_080171ea   (0x080171EA, 21 Bytes)
 * Body: 0x080171EA-0x080171FF
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_080171ea(void)

{
  _DAT_20001a90 = 0;
  _DAT_20001a94 = 0;
  _DAT_20001a98 = 0xff;
  FUN_08016fc4(2);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08017200   (0x08017200, 47 Bytes)
 * Body: 0x08017200-0x0801722F
 * --------------------------------------------------------------------- */
void FUN_08017200(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  undefined4 uStack_18;
  undefined4 uStack_14;
  uint uStack_10;
  
  uStack_18 = param_2;
  uStack_14 = param_3;
  uStack_10 = param_4;
  FUN_08017084(0x88,0xc,(undefined1 *)&uStack_18);
  uVar1 = FUN_08016f96(&uStack_18,10);
  if (uStack_10 >> 0x10 == uVar1) {
    FUN_0800b990(&DAT_20001a90,(undefined1 *)&uStack_18,0xc);
  }
  else {
    FUN_080171ea();
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08017230   (0x08017230, 89 Bytes)
 * Werks-Writer Block 1: schreibt Fabriktabelle + save(1)
 * Body: 0x08017230-0x08017289
 * --------------------------------------------------------------------- */
void FUN_08017230(void)

{
  DAT_20001a58 = 0x90;
  DAT_20001a59 = 0x90;
  DAT_20001a5a = 0x1e;
  DAT_20001a5b = 0x6e;
  DAT_20001a5c = 0x78;
  DAT_20001a5d = 100;
  DAT_20001a5e = 0x30;
  DAT_20001a5f = 0x3c;
  DAT_20001a60 = 0;
  DAT_20001a85 = 0;
  DAT_20001a86 = 0;
  FUN_0800b990(&DAT_20001a61,&DAT_0801da49,0x24);
  FUN_08016fc4(1);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801728a   (0x0801728A, 300 Bytes, 2 Teile)
 * Settings-Loader: liest Block 1 (0x50), XOR ueber 0x34, bei Mismatch Werks-Writer; spiegelt nach RAM
 * Body: 0x0801728A-0x0801737F, 0x08017414-0x0801744B
 * --------------------------------------------------------------------- */
void FUN_0801728a(void)

{
  uint uVar1;
  undefined1 auStack_44 [52];
  ushort local_10;
  
  FUN_08017084(0x50,0x38,auStack_44);
  uVar1 = FUN_08016f96(auStack_44,0x34);
  if (local_10 == uVar1) {
    FUN_0800b990(&DAT_20001a58,auStack_44,0x38);
  }
  else {
    FUN_08017230();
  }
  DAT_200002d9 = DAT_20001a58;
  DAT_200002a2 = DAT_20001a59;
  DAT_200002a3 = DAT_20001a58;
  DAT_200002a4 = DAT_20001a5a;
  DAT_200002a5 = DAT_20001a5b;
  DAT_200002a6 = DAT_20001a5c;
  DAT_200002b9 = DAT_20001a5d;
  DAT_200002c6 = DAT_20001a5e;
  DAT_200002c7 = DAT_20001a5f;
  DAT_200002da = DAT_20001a60 & 0xfe;
  DAT_200002a1 = DAT_20001a61;
  DAT_2000030d = DAT_20001a85;
  DAT_20000312 = DAT_20001a86;
  if (1 < DAT_20001a86) {
    DAT_20000312 = 0;
  }
  for (uVar1 = 0; uVar1 < 6; uVar1 = uVar1 + 1 & 0xff) {
    (&DAT_200002a7)[uVar1] = (&DAT_20001a63)[uVar1 * 6];
    (&DAT_200002ad)[uVar1] = (&DAT_20001a64)[uVar1 * 6];
    (&DAT_200002b3)[uVar1] = (&DAT_20001a62)[uVar1 * 6];
    (&DAT_200002ba)[uVar1] = (&DAT_20001a65)[uVar1 * 6];
    (&DAT_200002c0)[uVar1] = (&DAT_20001a66)[uVar1 * 6];
  }
  DAT_20000308 = (DAT_200002da & 2) != 0;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801744c   (0x0801744C, 823 Bytes)
 * Block-0-Defaults: 'VCU'-Magie, Version 3.4.13, 'AWPE-VCU-220212', Frame-Nr., save(0)
 * Body: 0x0801744C-0x08017783
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0801744c(void)

{
  uint uVar1;
  
  DAT_20001a08 = 0x56;
  DAT_20001a09 = 0x43;
  DAT_20001a0a = 0x55;
  DAT_20001a0b = 0;
  DAT_20001a0c = 0x53;
  DAT_20001a0d = 5;
  DAT_20001a0e = 0;
  DAT_20001a0f = 0;
  DAT_20001a10 = 0x56;
  DAT_20001a11 = 0x43;
  DAT_20001a12 = 0x55;
  DAT_20001a13 = 1;
  DAT_20001a14 = 1;
  DAT_20001a15 = 3;
  DAT_20001a16 = 4;
  DAT_20001a17 = 0xd;
  _DAT_20001a18 = 0x17;
  DAT_20001a1a = 0x30;
  DAT_20001a1b = 0x30;
  DAT_20001a1c = 0x30;
  DAT_20001a1d = 0x30;
  DAT_20001a1e = 0x30;
  DAT_20001a1f = 0x30;
  DAT_20001a20 = 0x30;
  DAT_20001a21 = 0x30;
  DAT_20001a22 = 0x30;
  DAT_20001a23 = 0x30;
  DAT_20001a24 = 0x30;
  DAT_20001a25 = 0x30;
  DAT_20001a26 = 0x30;
  DAT_20001a27 = 0x30;
  DAT_20001a28 = 0x30;
  DAT_20001a29 = 0x30;
  DAT_20001a2a = 0x30;
  DAT_20001a2b = 0x30;
  DAT_20001a2c = 0x30;
  DAT_20001a2d = 0x30;
  DAT_20001a2e = 0x30;
  DAT_20001a2f = 0x30;
  DAT_20001a30 = 0x30;
  DAT_20001a31 = 0x30;
  DAT_20001a32 = 0x30;
  DAT_20001a33 = 0x30;
  DAT_20001a34 = 0x30;
  DAT_20001a35 = 0x30;
  DAT_20001a36 = 0x30;
  DAT_20001a37 = 0x14;
  DAT_20001a38 = 0x16;
  DAT_20001a39 = 0xc;
  DAT_20001a3a = 1;
  DAT_20001a3b = 0;
  DAT_20001a3c = 0x41;
  DAT_20001a3d = 0x57;
  DAT_20001a3e = 0x50;
  DAT_20001a3f = 0x45;
  DAT_20001a40 = 0x2d;
  DAT_20001a41 = 0x56;
  DAT_20001a42 = 0x43;
  DAT_20001a43 = 0x55;
  DAT_20001a44 = 0x2d;
  DAT_20001a45 = 0x32;
  DAT_20001a46 = 0x32;
  DAT_20001a47 = 0x30;
  DAT_20001a48 = 0x32;
  DAT_20001a49 = 0x31;
  DAT_20001a4a = 0x32;
  DAT_20001a4b = 0;
  DAT_20001a4c = 0;
  DAT_20001a4d = 0;
  DAT_20001a4e = 0;
  DAT_20001a4f = 0x30;
  DAT_20001a50 = 0x31;
  DAT_20001a51 = 0x44;
  DAT_20001a52 = 0x42;
  DAT_20001a53 = 0x39;
  DAT_20001a54 = 0x39;
  FUN_08016fc4(0);
  for (uVar1 = 0; uVar1 < 5; uVar1 = uVar1 + 1) {
    *(undefined1 *)(uVar1 + 0x20000014) = (&DAT_20001a08)[uVar1];
  }
  DAT_20000019 = DAT_20001a0d;
  DAT_2000001a = DAT_20001a0e;
  DAT_2000001b = DAT_20001a0f;
  for (uVar1 = 0; uVar1 < 5; uVar1 = uVar1 + 1) {
    *(undefined1 *)(uVar1 + 0x2000000c) = (&DAT_20001a10)[uVar1];
  }
  DAT_20000011 = DAT_20001a15;
  DAT_20000012 = DAT_20001a16;
  DAT_20000013 = DAT_20001a17;
  for (uVar1 = 0; uVar1 < 5; uVar1 = uVar1 + 1) {
    (&DAT_2000002c)[uVar1] = (&DAT_20001a37)[uVar1];
  }
  for (uVar1 = 0; uVar1 < 0x13; uVar1 = uVar1 + 1) {
    (&DAT_20000742)[uVar1] = (&DAT_20001a3c)[uVar1];
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08017784   (0x08017784, 406 Bytes, 2 Teile)
 * Body: 0x08017784-0x0801780F, 0x08017868-0x08017973
 * --------------------------------------------------------------------- */
void FUN_08017784(void)

{
  uint uVar1;
  undefined1 auStack_5c [8];
  char local_54;
  char local_53;
  char local_52;
  char local_51;
  char local_50;
  char local_4f;
  char local_4e;
  char local_4d;
  ushort local_e;
  
  FUN_08017084(0,0x50,auStack_5c);
  uVar1 = FUN_08016f96(auStack_5c,0x4e);
  if (local_e == uVar1) {
    if (((((local_54 == 'V') && (local_53 == 'C')) && (local_52 == 'U')) &&
        ((local_51 == '\x01' && (local_50 == '\x01')))) &&
       ((local_4f == '\x03' && ((local_4e == '\x04' && (local_4d == '\r')))))) {
      FUN_0800b990(&DAT_20001a08,auStack_5c,0x50);
    }
    else {
      FUN_0800b990(&DAT_20001a08,auStack_5c,0x50);
      DAT_20001a10 = 0x56;
      DAT_20001a11 = 0x43;
      DAT_20001a12 = 0x55;
      DAT_20001a13 = 1;
      DAT_20001a14 = 1;
      DAT_20001a15 = 3;
      DAT_20001a16 = 4;
      DAT_20001a17 = 0xd;
      DAT_20001a08 = 0x56;
      DAT_20001a09 = 0x43;
      DAT_20001a0a = 0x55;
      DAT_20001a0b = 0;
      DAT_20001a0c = 0x53;
      DAT_20001a0d = 5;
      DAT_20001a0e = 0;
      DAT_20001a0f = 0;
      FUN_08016fc4(0);
    }
  }
  else {
    FUN_0801744c();
  }
  for (uVar1 = 0; uVar1 < 5; uVar1 = uVar1 + 1) {
    *(undefined1 *)(uVar1 + 0x20000014) = (&DAT_20001a08)[uVar1];
  }
  DAT_20000019 = DAT_20001a0d;
  DAT_2000001a = DAT_20001a0e;
  DAT_2000001b = DAT_20001a0f;
  for (uVar1 = 0; uVar1 < 5; uVar1 = uVar1 + 1) {
    *(undefined1 *)(uVar1 + 0x2000000c) = (&DAT_20001a10)[uVar1];
  }
  DAT_20000011 = DAT_20001a15;
  DAT_20000012 = DAT_20001a16;
  DAT_20000013 = DAT_20001a17;
  for (uVar1 = 0; uVar1 < 5; uVar1 = uVar1 + 1) {
    (&DAT_2000002c)[uVar1] = (&DAT_20001a37)[uVar1];
  }
  for (uVar1 = 0; uVar1 < 0x13; uVar1 = uVar1 + 1) {
    (&DAT_20000742)[uVar1] = (&DAT_20001a3c)[uVar1];
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08017974   (0x08017974, 31 Bytes)
 * Body: 0x08017974-0x08017993
 * --------------------------------------------------------------------- */
void FUN_08017974(void)

{
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  uint extraout_r3;
  uint extraout_r3_00;
  uint extraout_r3_01;
  uint extraout_r3_02;
  undefined8 uVar1;
  
  FUN_0801883a();
  FUN_08017784();
  uVar1 = FUN_0801728a();
  uVar1 = FUN_08017200((int)uVar1,(int)((ulonglong)uVar1 >> 0x20),extraout_r2,extraout_r3);
  uVar1 = FUN_0801719c((int)uVar1,(int)((ulonglong)uVar1 >> 0x20),extraout_r2_00,extraout_r3_00);
  uVar1 = FUN_0801710e((int)uVar1,(int)((ulonglong)uVar1 >> 0x20),extraout_r2_01,extraout_r3_01);
  FUN_080170a2((int)uVar1,(int)((ulonglong)uVar1 >> 0x20),extraout_r2_02,extraout_r3_02);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08017994   (0x08017994, 15 Bytes)
 * Body: 0x08017994-0x080179A3
 * --------------------------------------------------------------------- */
void FUN_08017994(undefined1 *param_1)

{
  FUN_0800b990(param_1,&DAT_20001a08,0x50);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_080179a4   (0x080179A4, 117 Bytes)
 * Body: 0x080179A4-0x08017A19
 * --------------------------------------------------------------------- */
void FUN_080179a4(undefined1 *param_1,byte *param_2,uint param_3)

{
  *param_2 = DAT_200004f8;
  if (param_3 * (DAT_200004f8 + 1) < 0x51) {
    if (param_3 * (DAT_200004f8 + 1) == 0x50) {
      DAT_200004f8 = '\0';
    }
    else {
      FUN_0800b990(param_1,&DAT_20001a08 + DAT_200004f8 * param_3,param_3);
      DAT_200004f8 = DAT_200004f8 + 1;
    }
  }
  else {
    FUN_0800b990(param_1,&DAT_20001a08 + DAT_200004f8 * param_3,
                 param_3 * (DAT_200004f8 + 1) - 0x50 & 0xffff);
    DAT_200004f8 = '\0';
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08017a1a   (0x08017A1A, 21 Bytes)
 * Body: 0x08017A1A-0x08017A2F
 * --------------------------------------------------------------------- */
void FUN_08017a1a(undefined1 *param_1)

{
  FUN_0800b990(&DAT_20001a08,param_1,0x50);
  FUN_08016fc4(0);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08017a30   (0x08017A30, 15 Bytes)
 * Settings-Nutzung (Block-1-Schatten)
 * Body: 0x08017A30-0x08017A3F
 * --------------------------------------------------------------------- */
void FUN_08017a30(undefined1 *param_1)

{
  FUN_0800b990(param_1,&DAT_20001a58,0x38);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08017a40   (0x08017A40, 113 Bytes)
 * Body: 0x08017A40-0x08017AB1
 * --------------------------------------------------------------------- */
void FUN_08017a40(undefined1 *param_1,byte *param_2,uint param_3)

{
  *param_2 = DAT_200004f9;
  if (param_3 * (DAT_200004f9 + 1) < 0x39) {
    if (param_3 * (DAT_200004f9 + 1) == 0x38) {
      DAT_200004f9 = '\0';
    }
    else {
      FUN_0800b990(param_1,&DAT_20001a58 + DAT_200004f9 * param_3,param_3);
      DAT_200004f9 = DAT_200004f9 + 1;
    }
  }
  else {
    FUN_0800b990(param_1,&DAT_20001a58 + DAT_200004f9 * param_3,
                 param_3 * (DAT_200004f9 + 1) - 0x38 & 0xffff);
    DAT_200004f9 = '\0';
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08017ab2   (0x08017AB2, 21 Bytes)
 * Body: 0x08017AB2-0x08017AC7
 * --------------------------------------------------------------------- */
void FUN_08017ab2(undefined1 *param_1)

{
  FUN_0800b990(&DAT_20001a58,param_1,0x38);
  FUN_08016fc4(1);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08017ac8   (0x08017AC8, 15 Bytes)
 * Body: 0x08017AC8-0x08017AD7
 * --------------------------------------------------------------------- */
void FUN_08017ac8(undefined1 *param_1)

{
  FUN_0800b990(param_1,&DAT_20001a90,0xc);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08017ad8   (0x08017AD8, 113 Bytes)
 * Body: 0x08017AD8-0x08017B49
 * --------------------------------------------------------------------- */
void FUN_08017ad8(undefined1 *param_1,byte *param_2,uint param_3)

{
  *param_2 = DAT_200004fa;
  if (param_3 * (DAT_200004fa + 1) < 0xd) {
    if (param_3 * (DAT_200004fa + 1) == 0xc) {
      DAT_200004fa = '\0';
    }
    else {
      FUN_0800b990(param_1,&DAT_20001a90 + DAT_200004fa * param_3,param_3);
      DAT_200004fa = DAT_200004fa + 1;
    }
  }
  else {
    FUN_0800b990(param_1,&DAT_20001a90 + DAT_200004fa * param_3,
                 param_3 * (DAT_200004fa + 1) - 0xc & 0xffff);
    DAT_200004fa = '\0';
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08017b4a   (0x08017B4A, 21 Bytes)
 * Body: 0x08017B4A-0x08017B5F
 * --------------------------------------------------------------------- */
void FUN_08017b4a(undefined1 *param_1)

{
  FUN_0800b990(&DAT_20001a58,param_1,0xc);
  FUN_08016fc4(2);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08017b60   (0x08017B60, 15 Bytes)
 * Body: 0x08017B60-0x08017B6F
 * --------------------------------------------------------------------- */
void FUN_08017b60(undefined1 *param_1)

{
  FUN_0800b990(param_1,&DAT_20001a9c,0xc);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08017b70   (0x08017B70, 15 Bytes)
 * Body: 0x08017B70-0x08017B7F
 * --------------------------------------------------------------------- */
void FUN_08017b70(undefined1 *param_1)

{
  FUN_0800b990(param_1,&DAT_20001aa8,0x10);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08017b80   (0x08017B80, 113 Bytes)
 * Body: 0x08017B80-0x08017BF1
 * --------------------------------------------------------------------- */
void FUN_08017b80(undefined1 *param_1,byte *param_2,uint param_3)

{
  *param_2 = DAT_200004fb;
  if (param_3 * (DAT_200004fb + 1) < 0xd) {
    if (param_3 * (DAT_200004fb + 1) == 0xc) {
      DAT_200004fb = '\0';
    }
    else {
      FUN_0800b990(param_1,&DAT_20001a90 + DAT_200004fb * param_3,param_3);
      DAT_200004fb = DAT_200004fb + 1;
    }
  }
  else {
    FUN_0800b990(param_1,&DAT_20001a90 + DAT_200004fb * param_3,
                 param_3 * (DAT_200004fb + 1) - 0xc & 0xffff);
    DAT_200004fb = '\0';
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08017bf2   (0x08017BF2, 21 Bytes)
 * Body: 0x08017BF2-0x08017C07
 * --------------------------------------------------------------------- */
void FUN_08017bf2(undefined1 *param_1)

{
  FUN_0800b990(&DAT_20001a58,param_1,0xc);
  FUN_08016fc4(3);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08017c08   (0x08017C08, 128 Bytes, 2 Teile)
 * Body: 0x08017C08-0x08017C5F, 0x08017CB4-0x08017CDD
 * --------------------------------------------------------------------- */
void FUN_08017c08(void)

{
  uint uVar1;
  
  for (uVar1 = 0; uVar1 < 5; uVar1 = uVar1 + 1) {
    (&DAT_20001a08)[uVar1] = *(undefined1 *)(uVar1 + 0x20000014);
  }
  DAT_20001a0d = DAT_20000019;
  DAT_20001a0e = DAT_2000001a;
  DAT_20001a0f = DAT_2000001b;
  for (uVar1 = 0; uVar1 < 5; uVar1 = uVar1 + 1) {
    (&DAT_20001a10)[uVar1] = *(undefined1 *)(uVar1 + 0x2000000c);
  }
  DAT_20001a15 = DAT_20000011;
  DAT_20001a16 = DAT_20000012;
  DAT_20001a17 = DAT_20000013;
  for (uVar1 = 0; uVar1 < 5; uVar1 = uVar1 + 1) {
    (&DAT_20001a37)[uVar1] = (&DAT_2000002c)[uVar1];
  }
  for (uVar1 = 0; uVar1 < 0x13; uVar1 = uVar1 + 1) {
    (&DAT_20001a3c)[uVar1] = (&DAT_20000742)[uVar1];
  }
  FUN_08016fc4(0);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08017cde   (0x08017CDE, 195 Bytes)
 * Settings-Nutzung (Block-1-Schatten)
 * Body: 0x08017CDE-0x08017DA1
 * --------------------------------------------------------------------- */
void FUN_08017cde(void)

{
  uint uVar1;
  
  DAT_20001a58 = DAT_200002a3;
  DAT_20001a59 = DAT_200002a2;
  DAT_20001a5a = DAT_200002a4;
  DAT_20001a5b = DAT_200002a5;
  DAT_20001a5c = DAT_200002a6;
  DAT_20001a5d = DAT_200002b9;
  DAT_20001a5e = DAT_200002c6;
  DAT_20001a5f = DAT_200002c7;
  DAT_20001a60 = DAT_200002da;
  DAT_20001a85 = DAT_2000030d;
  DAT_20001a86 = DAT_20000312;
  for (uVar1 = 0; uVar1 < 6; uVar1 = uVar1 + 1 & 0xff) {
    (&DAT_20001a61)[uVar1 * 6] = (char)uVar1;
    (&DAT_20001a62)[uVar1 * 6] = (&DAT_200002b3)[uVar1];
    (&DAT_20001a64)[uVar1 * 6] = (&DAT_200002ad)[uVar1];
    (&DAT_20001a63)[uVar1 * 6] = (&DAT_200002a7)[uVar1];
    (&DAT_20001a66)[uVar1 * 6] = (&DAT_200002c0)[uVar1];
    (&DAT_20001a65)[uVar1 * 6] = (&DAT_200002ba)[uVar1];
  }
  FUN_08016fc4(1);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08017da2   (0x08017DA2, 17 Bytes)
 * Body: 0x08017DA2-0x08017DB3
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08017da2(void)

{
  _DAT_20001a90 = _DAT_20000300;
  FUN_08016fc4(2);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08017db4   (0x08017DB4, 17 Bytes)
 * Body: 0x08017DB4-0x08017DC5
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08017db4(void)

{
  _DAT_20001a9c = _DAT_20000300;
  FUN_08016fc4(3);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08017dc6   (0x08017DC6, 65 Bytes)
 * Body: 0x08017DC6-0x08017E07
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08017dc6(void)

{
  DAT_20001aa8 = DAT_2000031f;
  DAT_20001aa9 = DAT_20000320;
  DAT_20001aaa = DAT_20000321;
  DAT_20001aab = DAT_20000322;
  DAT_20001aac = DAT_20000323;
  _DAT_20001aae = _DAT_20000328;
  DAT_20001ab0 = DAT_2000032a;
  DAT_20001ab1 = DAT_2000032b;
  DAT_20001ab2 = DAT_2000032c;
  FUN_08016fc4(4);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08017e08   (0x08017E08, 17 Bytes)
 * Body: 0x08017E08-0x08017E19
 * --------------------------------------------------------------------- */
void FUN_08017e08(void)

{
  DAT_200004f2 = DAT_20000399;
  FUN_08016fc4(5);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08017e1a   (0x08017E1A, 17 Bytes)
 * Sonderpfad: Display-0x8C-Sequenz (Zweck nicht abschliessend geklaert)
 * Body: 0x08017E1A-0x08017E2B
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08017e1a(void)

{
  FUN_080171ea();
  FUN_08017186();
  _DAT_20000300 = 0;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08017e2c   (0x08017E2C, 882 Bytes, 2 Teile)
 * 5000ms-Task: Settings-/Persistenz-Nachlauf
 * Body: 0x08017E2C-0x080180AD, 0x08018144-0x08018235
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08017e2c(void)

{
  bool bVar1;
  
  if (_DAT_200004fc < _DAT_20000300) {
    if (10 < _DAT_20000300 - _DAT_200004fc) {
      _DAT_200004fc = _DAT_20000300;
      if (_DAT_20001aa0 < _DAT_20001a94) {
        _DAT_20001aa0 = _DAT_20001a94 + 2;
        FUN_08017db4();
      }
      else {
        _DAT_20001a94 = _DAT_20001aa0 + 2;
        FUN_08017da2();
      }
    }
  }
  else if (_DAT_200004fc == 0) {
    _DAT_200004fc = _DAT_20000300;
  }
  if (0x81 < DAT_200002a6) {
    DAT_200002a6 = 0x82;
  }
  if (DAT_200002a6 < 0x51) {
    DAT_200002a6 = 0x50;
  }
  if (5 < DAT_200004fe) {
    bVar1 = (DAT_20001a58 & 0xee) == (DAT_200002a3 & 0xee);
    do {
      if (!bVar1) goto LAB_080181a0;
      bVar1 = (DAT_20001a59 & 0xee) == (DAT_200002a2 & 0xee);
    } while (((((((!bVar1) || (bVar1 = DAT_20001a5a == DAT_200002a4, !bVar1)) ||
                (bVar1 = DAT_20001a5b == DAT_200002a5, !bVar1)) ||
               ((bVar1 = DAT_20001a5c == DAT_200002a6, !bVar1 ||
                (bVar1 = DAT_20001a5d == DAT_200002b9, !bVar1)))) ||
              (bVar1 = DAT_20001a5e == DAT_200002c6, !bVar1)) ||
             (((bVar1 = DAT_20001a5f == DAT_200002c7, !bVar1 ||
               (bVar1 = (DAT_20001a60 & 0xfe) == (DAT_200002da & 0xfe), !bVar1)) ||
              ((bVar1 = DAT_20001a85 == DAT_2000030d, !bVar1 ||
               (((bVar1 = DAT_20001a86 == DAT_20000312, !bVar1 ||
                 (bVar1 = DAT_20001a61 == '\0', !bVar1)) ||
                (bVar1 = DAT_20001a62 == DAT_200002b3, !bVar1)))))))) ||
            (((bVar1 = DAT_20001a64 == DAT_200002ad, !bVar1 ||
              (bVar1 = DAT_20001a63 == DAT_200002a7, !bVar1)) ||
             ((bVar1 = DAT_20001a66 == DAT_200002c0, !bVar1 ||
              (((bVar1 = DAT_20001a65 == DAT_200002ba, !bVar1 ||
                (bVar1 = DAT_20001a67 == '\x01', !bVar1)) ||
               (bVar1 = DAT_20001a68 == DAT_200002b4, !bVar1))))))));
    if (((((((DAT_20001a6a != DAT_200002ae) || (DAT_20001a69 != DAT_200002a8)) ||
           (DAT_20001a6c != DAT_200002c1)) ||
          ((DAT_20001a6b != DAT_200002bb || (DAT_20001a6d != '\x02')))) ||
         (((DAT_20001a6e != DAT_200002b5 ||
           ((DAT_20001a70 != DAT_200002af || (DAT_20001a6f != DAT_200002a9)))) ||
          (DAT_20001a72 != DAT_200002c2)))) ||
        ((((DAT_20001a71 != DAT_200002bc || (DAT_20001a73 != '\x03')) ||
          (DAT_20001a74 != DAT_200002b6)) ||
         ((DAT_20001a76 != DAT_200002b0 || (DAT_20001a75 != DAT_200002aa)))))) ||
       ((((((DAT_20001a78 != DAT_200002c3 ||
            ((DAT_20001a77 != DAT_200002bd || (DAT_20001a79 != '\x04')))) ||
           (DAT_20001a7a != DAT_200002b7)) ||
          ((((DAT_20001a7c != DAT_200002b1 || (DAT_20001a7b != DAT_200002ab)) ||
            (DAT_20001a7e != DAT_200002c4)) ||
           ((DAT_20001a7d != DAT_200002be || (DAT_20001a7f != '\x05')))))) ||
         ((DAT_20001a80 != DAT_200002b8 ||
          ((DAT_20001a82 != DAT_200002b2 || (DAT_20001a81 != DAT_200002ac)))))) ||
        ((DAT_20001a84 != DAT_200002c5 || (DAT_20001a83 != DAT_200002bf)))))) {
LAB_080181a0:
      FUN_08017cde();
    }
    if ((((DAT_20001aa8 != DAT_2000031f) || (DAT_20001aa9 != DAT_20000320)) ||
        (DAT_20001aaa != DAT_20000321)) ||
       ((((DAT_20001aab != DAT_20000322 || (DAT_20001aac != DAT_20000323)) ||
         ((_DAT_20001aae != _DAT_20000328 ||
          ((DAT_20001ab0 != DAT_2000032a || (DAT_20001ab1 != DAT_2000032b)))))) ||
        (DAT_20001ab2 != DAT_2000032c)))) {
      FUN_08017dc6();
    }
    if (DAT_200004f2 != DAT_20000399) {
      FUN_08017e08();
    }
    DAT_200004fe = 0;
  }
  DAT_200004fe = DAT_200004fe + 1;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08018236   (0x08018236, 55 Bytes)
 * Verarbeitung der 3-stufigen Display-0x8A-Datenfolge
 * Body: 0x08018236-0x0801826D
 * --------------------------------------------------------------------- */
void FUN_08018236(int param_1)

{
  uint uVar1;
  
  for (uVar1 = 0; uVar1 < 0x13; uVar1 = uVar1 + 1 & 0xff) {
    (&DAT_20000742)[uVar1] = *(undefined1 *)(param_1 + uVar1);
  }
  FUN_08017c08();
  FUN_0800bb42(&DAT_20000742,0x13,0);
  FUN_0800b9ec(100);
  FUN_0800bb42(&DAT_20000742,0x13,1);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801826e   (0x0801826E, 417 Bytes)
 * Body: 0x0801826E-0x0801840F
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0801826e(void)

{
  int iVar1;
  char cVar2;
  char cVar3;
  
  cVar2 = '\0';
  cVar3 = '\0';
  iVar1 = 0;
  if ((DAT_200004ff != 0) && (DAT_200004ff = DAT_200004ff + 1, 5 < DAT_200004ff)) {
    DAT_200004ff = 0;
    if ((_DAT_2000003e < 0x12d) || (699 < _DAT_2000003e)) {
      if ((_DAT_2000003e < 0x321) || (0x4af < _DAT_2000003e)) {
        if ((_DAT_2000003e < 0x515) || (0x6a3 < _DAT_2000003e)) {
          if ((_DAT_2000003e < 0x709) || (0x897 < _DAT_2000003e)) {
            if ((_DAT_2000003e < 0x8fd) || (0xa8b < _DAT_2000003e)) {
              if ((_DAT_2000003e < 0xaf1) || (0xc7f < _DAT_2000003e)) {
                iVar1 = 1;
              }
              else {
                cVar2 = '\x06';
              }
            }
            else {
              cVar2 = '\x05';
            }
          }
          else {
            cVar2 = '\x04';
          }
        }
        else {
          cVar2 = '\x03';
        }
      }
      else {
        cVar2 = '\x02';
      }
    }
    else {
      cVar2 = '\x01';
    }
    if (_DAT_20000040 < 200) {
      cVar3 = '\0';
    }
    else if ((_DAT_20000040 < 0x12d) || (699 < _DAT_20000040)) {
      if ((_DAT_20000040 < 0x321) || (0x4af < _DAT_20000040)) {
        if ((_DAT_20000040 < 0x515) || (0x6a3 < _DAT_20000040)) {
          if ((_DAT_20000040 < 0x709) || (0x897 < _DAT_20000040)) {
            if ((_DAT_20000040 < 0x8fd) || (0xa8b < _DAT_20000040)) {
              if ((_DAT_20000040 < 0xaf1) || (0xc7f < _DAT_20000040)) {
                iVar1 = iVar1 + 1;
              }
              else {
                cVar3 = '\x06';
              }
            }
            else {
              cVar3 = '\x05';
            }
          }
          else {
            cVar3 = '\x04';
          }
        }
        else {
          cVar3 = '\x03';
        }
      }
      else {
        cVar3 = '\x02';
      }
    }
    else {
      cVar3 = '\x01';
    }
    if ((iVar1 == 0) && ((DAT_20000019 != cVar2 || (DAT_2000001a != cVar3)))) {
      DAT_20001a0f = 0;
      DAT_20000019 = cVar2;
      DAT_2000001a = cVar3;
      DAT_20001a0d = cVar2;
      DAT_20001a0e = cVar3;
      FUN_08016fc4(0);
    }
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08018478   (0x08018478, 23 Bytes)
 * Body: 0x08018478-0x0801848F
 * --------------------------------------------------------------------- */
void FUN_08018478(void)

{
  DAT_20001ea4 = 0;
  DAT_20001ea1 = 0;
  DAT_20001ea0 = 0;
  DAT_20001ea5 = 0;
  DAT_20001ea3 = 0;
  DAT_20001ea6 = 0;
  DAT_20001ea7 = 0;
  DAT_20001ea8 = 0;
  DAT_20001ea9 = 0;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08018490   (0x08018490, 1 Bytes)
 * Body: 0x08018490-0x08018491
 * --------------------------------------------------------------------- */
void FUN_08018490(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08018492   (0x08018492, 155 Bytes)
 * Body: 0x08018492-0x0801852D
 * --------------------------------------------------------------------- */
void FUN_08018492(void)

{
  if (DAT_20001ea0 == '\0') {
    FUN_080079ae(0x40010c00,4);
  }
  else {
    if (DAT_20001ea1 == '\0') {
      DAT_20001ea3 = DAT_20001ea7;
      DAT_20001ea1 = '\x01';
    }
    if (DAT_20001ea6 == '\0') {
      FUN_080079a6(0x40010c00,4);
      DAT_20001ea4 = DAT_20001ea4 + 1;
      if (DAT_20001ea8 <= DAT_20001ea4) {
        DAT_20001ea4 = 0;
        DAT_20001ea6 = '\x01';
      }
    }
    else if (DAT_20001ea6 == '\x01') {
      FUN_080079ae(0x40010c00,4);
      DAT_20001ea5 = DAT_20001ea5 + 1;
      if (DAT_20001ea9 <= DAT_20001ea5) {
        DAT_20001ea5 = 0;
        DAT_20001ea6 = '\0';
        DAT_20001ea3 = DAT_20001ea3 + -1;
      }
    }
    if (DAT_20001ea3 == '\0') {
      DAT_20001ea0 = '\0';
      DAT_20001ea1 = '\0';
      DAT_20001ea2 = 0;
    }
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801852e   (0x0801852E, 37 Bytes)
 * Body: 0x0801852E-0x08018553
 * --------------------------------------------------------------------- */
void FUN_0801852e(undefined1 param_1,undefined1 param_2,undefined1 param_3,char param_4)

{
  if (DAT_20001ea2 == '\0') {
    DAT_20001ea2 = '\x01';
    DAT_20001ea0 = param_4;
    DAT_20001ea7 = param_1;
    DAT_20001ea8 = param_2;
    DAT_20001ea9 = param_3;
  }
  if (DAT_20001ea0 == '\0') {
    DAT_20001ea2 = '\0';
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08018554   (0x08018554, 197 Bytes)
 * Body: 0x08018554-0x08018619
 * --------------------------------------------------------------------- */
void FUN_08018554(void)

{
  if ((DAT_20000066 == '\x01') && ((DAT_20000391 == '\x02' || (DAT_20000391 == '\x04')))) {
    FUN_0801852e(5,10,5,'\x01');
    DAT_20000066 = -1;
  }
  else if ((DAT_20000066 == '\x02') && ((DAT_20000391 == '\x02' || (DAT_20000391 == '\x04')))) {
    FUN_0801852e(2,2,2,'\x01');
    DAT_20000066 = -1;
  }
  else if ((DAT_20000066 == '\x03') && ((DAT_20000391 == '\x02' || (DAT_20000391 == '\x04')))) {
    FUN_0801852e(1,5,2,'\x01');
    DAT_20000066 = -1;
  }
  else if ((DAT_20000066 == '\x04') && ((DAT_20000391 == '\x02' || (DAT_20000391 == '\x04')))) {
    FUN_0801852e(3,2,2,'\x01');
    DAT_20000066 = -1;
  }
  else if (DAT_20000066 == '\0') {
    FUN_0801852e(1,1,1,'\0');
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801861a   (0x0801861A, 15 Bytes)
 * Body: 0x0801861A-0x08018629
 * --------------------------------------------------------------------- */
void FUN_0801861a(void)

{
  FUN_08018554();
  FUN_08018492();
  FUN_08018490();
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801863c   (0x0801863C, 7 Bytes)
 * Body: 0x0801863C-0x08018643
 * --------------------------------------------------------------------- */
void FUN_0801863c(void)

{
  DAT_20000500 = 0;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08018644   (0x08018644, 39 Bytes)
 * Body: 0x08018644-0x0801866B
 * --------------------------------------------------------------------- */
void FUN_08018644(void)

{
  if (((DAT_20000500 == '\x01') || (DAT_20000500 == '\x02')) || (DAT_20000500 == '\x04')) {
    DAT_2000031c = 0;
  }
  DAT_20000391 = DAT_20000500;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801866c   (0x0801866C, 126 Bytes, 2 Teile)
 * Body: 0x0801866C-0x08018677, 0x0801867E-0x080186F1
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0801866c(void)

{
  switch(DAT_20000500) {
  case 0:
    _DAT_20000502 = _DAT_20000502 + 1;
    if (DAT_2000030e == '\0') {
      DAT_20000500 = 1;
    }
    if (0x32 < _DAT_20000502) {
      _DAT_20000502 = 0;
      DAT_20000500 = 4;
    }
    break;
  case 1:
    break;
  case 2:
    if (DAT_2000030e == '\0') {
      DAT_20000500 = 1;
    }
    break;
  case 3:
    DAT_20000500 = 1;
    break;
  case 4:
    _DAT_20000502 = _DAT_20000502 + 1;
    if (300 < _DAT_20000502) {
      _DAT_20000502 = 0;
      DAT_20000500 = 1;
    }
    if (DAT_2000030e == '\0') {
      DAT_20000500 = 1;
    }
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_080186f2   (0x080186F2, 1 Bytes)
 * Body: 0x080186F2-0x080186F3
 * --------------------------------------------------------------------- */
void FUN_080186f2(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_080186f4   (0x080186F4, 15 Bytes)
 * Body: 0x080186F4-0x08018703
 * --------------------------------------------------------------------- */
void FUN_080186f4(void)

{
  FUN_080186f2();
  FUN_0801866c();
  FUN_08018644();
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08018718   (0x08018718, 47 Bytes)
 * Init-Phase 1: Zeitbasis, CAN-Init, UART-Init (USART1/2/3), IRQ enable
 * Body: 0x08018718-0x08018747
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08018718(void)

{
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined8 uVar1;
  
  FUN_0801938e();
  FUN_0801914a();
  uVar1 = FUN_08019bd8();
  FUN_080194ec((int)uVar1,(int)((ulonglong)uVar1 >> 0x20),extraout_r2,extraout_r3);
  uVar1 = FUN_08019690();
  FUN_0801ba92((int)uVar1,(int)((ulonglong)uVar1 >> 0x20),extraout_r2_00,extraout_r3_00);
  FUN_080198ec(0x40013800);
  FUN_080198ec(_FUN_08018820);
  FUN_080198ec(iRam08018824);
  enableIRQinterrupts();
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08018748   (0x08018748, 1 Bytes)
 * Init-Phase: Sonderfall
 * Body: 0x08018748-0x08018749
 * --------------------------------------------------------------------- */
void FUN_08018748(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801874a   (0x0801874A, 1 Bytes)
 * Init-Phase: Sonderfall
 * Body: 0x0801874A-0x0801874B
 * --------------------------------------------------------------------- */
void FUN_0801874a(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801874c   (0x0801874C, 31 Bytes)
 * Init-Phase 2/3: Nachlauf (Sensor/EEPROM/Bereitschaft)
 * Body: 0x0801874C-0x0801876B
 * --------------------------------------------------------------------- */
void FUN_0801874c(void)

{
  FUN_0800ba20();
  FUN_0800eda0();
  FUN_08017974();
  FUN_08012bbe();
  FUN_0801cc50();
  FUN_0801863c();
  FUN_08018478();
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801876c   (0x0801876C, 11 Bytes)
 * Task 10ms: Tick-Zaehler 0x20000530++
 * Body: 0x0801876C-0x08018777
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0801876c(void)

{
  _DAT_20000530 = _DAT_20000530 + 1;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08018778   (0x08018778, 1 Bytes)
 * Task 20ms: (leer)
 * Body: 0x08018778-0x08018779
 * --------------------------------------------------------------------- */
void FUN_08018778(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801877a   (0x0801877A, 1 Bytes)
 * Task 50ms: Perioden-Slot
 * Body: 0x0801877A-0x0801877B
 * --------------------------------------------------------------------- */
void FUN_0801877a(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801877c   (0x0801877C, 23 Bytes)
 * Task 100ms: Kernkette (RX/State/Builder)
 * Body: 0x0801877C-0x08018793
 * --------------------------------------------------------------------- */
void FUN_0801877c(void)

{
  FUN_0801959c();
  FUN_080186f4();
  FUN_080195dc();
  FUN_0800fe26();
  FUN_08015caa();
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08018794   (0x08018794, 1 Bytes)
 * Task 200ms: Perioden-Slot
 * Body: 0x08018794-0x08018795
 * --------------------------------------------------------------------- */
void FUN_08018794(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08018796   (0x08018796, 23 Bytes)
 * Task 500ms: Perioden-Slot
 * Body: 0x08018796-0x080187AD
 * --------------------------------------------------------------------- */
void FUN_08018796(void)

{
  FUN_0801979e();
  FUN_0801826e();
  FUN_0801861a();
  FUN_0801d298();
  FUN_08010b40();
  return;
}


/* ---------------------------------------------------------------------
 * FUN_080187ae   (0x080187AE, 15 Bytes)
 * Task 1000ms: Perioden-Slot
 * Body: 0x080187AE-0x080187BD
 * --------------------------------------------------------------------- */
void FUN_080187ae(void)

{
  FUN_0800de4a();
  FUN_08010e02();
  FUN_0801b8c4();
  return;
}


/* ---------------------------------------------------------------------
 * FUN_080187be   (0x080187BE, 21 Bytes)
 * Task 2000ms: Perioden-Slot
 * Body: 0x080187BE-0x080187D3
 * --------------------------------------------------------------------- */
void FUN_080187be(void)

{
  FUN_0800dd38();
  FUN_080194f4();
  DAT_20000396 = DAT_20000396 + '\x01';
  return;
}


/* ---------------------------------------------------------------------
 * FUN_080187d4   (0x080187D4, 7 Bytes)
 * Task 5000ms: FUN_08017E2C (Settings-Nachlauf)
 * Body: 0x080187D4-0x080187DB
 * --------------------------------------------------------------------- */
void FUN_080187d4(void)

{
  FUN_08017e2c();
  return;
}


/* ---------------------------------------------------------------------
 * FUN_080187dc   (0x080187DC, 19 Bytes)
 * Body: 0x080187DC-0x080187EF
 * --------------------------------------------------------------------- */
void FUN_080187dc(void)

{
  undefined8 uVar1;
  
  FUN_0801bd64();
  uVar1 = FUN_0801bd96();
  FUN_0801c5e4((int)uVar1,(int)((ulonglong)uVar1 >> 0x20));
  FUN_08010e8c();
  return;
}


/* ---------------------------------------------------------------------
 * FUN_080187f0   (0x080187F0, 41 Bytes)
 * Body: 0x080187F0-0x08018819
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_080187f0(void)

{
  if (((_DAT_20000392 < 0x14) && (_DAT_20000394 < 0x32)) || (4 < DAT_20000396)) {
    DAT_20000396 = 0;
    FUN_08019e30();
    FUN_08019ca0();
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08018820   (0x08018820, 25 Bytes)
 * Body: 0x08018820-0x08018839
 * --------------------------------------------------------------------- */
undefined4 FUN_08018820(void)

{
  return 0;
}


/* ---------------------------------------------------------------------
 * FUN_0801883a   (0x0801883A, 127 Bytes)
 * Body: 0x0801883A-0x080188B9
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0801883a(void)

{
  uint local_24;
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  undefined2 local_1a;
  undefined2 local_18;
  ushort local_14;
  undefined1 local_11;
  undefined1 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  FUN_0800795a(&local_14);
  FUN_08007f40(0x200000,1);
  FUN_0800af1c(_FUN_08018c3c);
  FUN_080081e4(8,1);
  FUN_080081e4(8,1);
  local_14 = 0xc0;
  local_11 = 0;
  local_c = 0x12;
  local_8 = 1;
  local_10 = 1;
  FUN_08007776(puRam08018c40,&local_14);
  FUN_0800af1c(_FUN_08018c3c);
  local_20 = 0;
  local_1e = 0xbfff;
  local_1c = 0xff;
  local_1a = 0x400;
  local_18 = 0x4000;
  local_24 = 400000;
  FUN_0800af4e((ushort *)0x40005400,&local_24);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_080188ba   (0x080188BA, 339 Bytes)
 * Body: 0x080188BA-0x08018A0D
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_080188ba(byte *param_1,undefined4 param_2,uint param_3)

{
  short sVar1;
  bool bVar2;
  
  _DAT_2000050a = 3000;
  do {
    bVar2 = FUN_0800b298(0x40005400,0x20000);
    if (!bVar2) break;
    sVar1 = _DAT_2000050a + -1;
    bVar2 = _DAT_2000050a != 0;
    _DAT_2000050a = sVar1;
  } while (bVar2);
  FUN_0800b092((ushort *)0x40005400,1);
  _DAT_2000050a = 3000;
  do {
    bVar2 = FUN_0800b254(0x40005400,0x30001);
    if (bVar2) break;
    sVar1 = _DAT_2000050a + -1;
    bVar2 = _DAT_2000050a != 0;
    _DAT_2000050a = sVar1;
  } while (bVar2);
  FUN_0800b13e(0x40005400,0xa0,0);
  _DAT_2000050a = 3000;
  do {
    bVar2 = FUN_0800b254(0x40005400,0x70082);
    if (bVar2) break;
    sVar1 = _DAT_2000050a + -1;
    bVar2 = _DAT_2000050a != 0;
    _DAT_2000050a = sVar1;
  } while (bVar2);
  FUN_0800b132(0x40005400,(short)((uint)param_2 >> 8));
  _DAT_2000050a = 3000;
  do {
    bVar2 = FUN_0800b254(0x40005400,0x70084);
    if (bVar2) break;
    sVar1 = _DAT_2000050a + -1;
    bVar2 = _DAT_2000050a != 0;
    _DAT_2000050a = sVar1;
  } while (bVar2);
  FUN_0800b132(0x40005400,(ushort)param_2 & 0xff);
  _DAT_2000050a = 3000;
  do {
    bVar2 = FUN_0800b254(0x40005400,0x70084);
    if (bVar2) break;
    sVar1 = _DAT_2000050a + -1;
    bVar2 = _DAT_2000050a != 0;
    _DAT_2000050a = sVar1;
  } while (bVar2);
  do {
    bVar2 = param_3 == 0;
    param_3 = param_3 - 1 & 0xffff;
    if (bVar2) {
      FUN_0800b0aa((ushort *)0x40005400,1);
      return;
    }
    FUN_0800b132(0x40005400,(ushort)*param_1);
    param_1 = param_1 + 1;
    _DAT_2000050a = 3000;
    do {
      bVar2 = FUN_0800b254(0x40005400,0x70084);
      if (bVar2) break;
      sVar1 = _DAT_2000050a + -1;
      bVar2 = _DAT_2000050a != 0;
      _DAT_2000050a = sVar1;
    } while (bVar2);
  } while( true );
}


/* ---------------------------------------------------------------------
 * FUN_08018a0e   (0x08018A0E, 445 Bytes)
 * Body: 0x08018A0E-0x08018BCB
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_08018a0e(undefined4 param_1)

{
  short sVar1;
  bool bVar2;
  undefined1 uVar3;
  
  _DAT_2000050a = 3000;
  do {
    bVar2 = FUN_0800b298(0x40005400,0x20000);
    if (!bVar2) break;
    sVar1 = _DAT_2000050a + -1;
    bVar2 = _DAT_2000050a != 0;
    _DAT_2000050a = sVar1;
  } while (bVar2);
  FUN_0800b092((ushort *)0x40005400,1);
  _DAT_2000050a = 3000;
  do {
    bVar2 = FUN_0800b254(0x40005400,0x30001);
    if (bVar2) break;
    sVar1 = _DAT_2000050a + -1;
    bVar2 = _DAT_2000050a != 0;
    _DAT_2000050a = sVar1;
  } while (bVar2);
  FUN_0800b13e(0x40005400,0xa0,0);
  _DAT_2000050a = 3000;
  do {
    bVar2 = FUN_0800b254(0x40005400,0x70082);
    if (bVar2) break;
    sVar1 = _DAT_2000050a + -1;
    bVar2 = _DAT_2000050a != 0;
    _DAT_2000050a = sVar1;
  } while (bVar2);
  FUN_0800b04a((ushort *)0x40005400,1);
  FUN_0800b132(0x40005400,(short)((uint)param_1 >> 8));
  _DAT_2000050a = 3000;
  do {
    bVar2 = FUN_0800b254(0x40005400,0x70084);
    if (bVar2) break;
    sVar1 = _DAT_2000050a + -1;
    bVar2 = _DAT_2000050a != 0;
    _DAT_2000050a = sVar1;
  } while (bVar2);
  FUN_0800b132(0x40005400,(ushort)param_1 & 0xff);
  _DAT_2000050a = 3000;
  do {
    bVar2 = FUN_0800b254(0x40005400,0x70084);
    if (bVar2) break;
    sVar1 = _DAT_2000050a + -1;
    bVar2 = _DAT_2000050a != 0;
    _DAT_2000050a = sVar1;
  } while (bVar2);
  FUN_0800b092((ushort *)0x40005400,1);
  _DAT_2000050a = 3000;
  do {
    bVar2 = FUN_0800b254(0x40005400,0x30001);
    if (bVar2) break;
    sVar1 = _DAT_2000050a + -1;
    bVar2 = _DAT_2000050a != 0;
    _DAT_2000050a = sVar1;
  } while (bVar2);
  FUN_0800b13e(0x40005400,0xa0,1);
  _DAT_2000050a = 3000;
  do {
    bVar2 = FUN_0800b298(0x40005400,0x10000002);
    if (bVar2) break;
    sVar1 = _DAT_2000050a + -1;
    bVar2 = _DAT_2000050a != 0;
    _DAT_2000050a = sVar1;
  } while (bVar2);
  FUN_0800b0c2((ushort *)0x40005400,0);
  _DAT_2000050a = 3000;
  do {
    bVar2 = FUN_0800b298(0x40005400,0x10000040);
    if (bVar2) break;
    sVar1 = _DAT_2000050a + -1;
    bVar2 = _DAT_2000050a != 0;
    _DAT_2000050a = sVar1;
  } while (bVar2);
  uVar3 = FUN_0800b136(0x40005400);
  FUN_0800b0aa((ushort *)0x40005400,1);
  return uVar3;
}


/* ---------------------------------------------------------------------
 * FUN_08018bcc   (0x08018BCC, 109 Bytes)
 * Body: 0x08018BCC-0x08018C39
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08018bcc(void)

{
  short sVar1;
  undefined1 uVar2;
  uint uVar3;
  bool bVar4;
  
  uVar3 = FUN_0800b27e(0x40005400);
  if (uVar3 == 0x70080) {
    if (DAT_2000050c != '\x01') {
      return;
    }
    FUN_0800b092((ushort *)0x40005400,1);
    return;
  }
  if ((int)uVar3 < 0x70081) {
    if (uVar3 == 0x30001) {
      if (DAT_20000508 == '\0') {
        DAT_2000052c = 2;
      }
      if (DAT_2000050c == '\x01') {
        if (DAT_20000509 == '\0') {
          FUN_0800b13e(0x40005400,(ushort)DAT_2000050e,0);
          return;
        }
        FUN_0800b13e(0x40005400,(ushort)DAT_2000050e,1);
        DAT_20000509 = 0;
        return;
      }
      FUN_0800b13e(0x40005400,(ushort)DAT_2000050e,0);
      return;
    }
    if (uVar3 == 0x30002) {
      return;
    }
    bVar4 = uVar3 == 0x30040;
  }
  else {
    if (uVar3 == 0x70082) {
      if (DAT_20000508 != '\0') {
        DAT_20000508 = 0;
        FUN_0800b120(0x40005400,0x700,0);
        FUN_0800b0aa((ushort *)0x40005400,1);
        DAT_2000052c = 0;
        return;
      }
      FUN_0800b132(0x40005400,(ushort)DAT_20000510);
      DAT_20000509 = 1;
      return;
    }
    bVar4 = false;
    if (uVar3 == 0x70084) {
      if (DAT_2000050c != '\0') {
        return;
      }
      if (_DAT_20000528 != 0) {
        uVar3 = (uint)_DAT_20000526;
        _DAT_20000526 = _DAT_20000526 + 1;
        FUN_0800b132(0x40005400,(ushort)*(byte *)(uVar3 + 0x2000051e));
        _DAT_20000528 = _DAT_20000528 + -1;
        return;
      }
      FUN_0800b0aa((ushort *)0x40005400,1);
      _DAT_2000050a = 3000;
      do {
        bVar4 = FUN_0800b298(0x40005400,0x20000);
        if (!bVar4) break;
        sVar1 = _DAT_2000050a + -1;
        bVar4 = _DAT_2000050a != 0;
        _DAT_2000050a = sVar1;
      } while (bVar4);
      DAT_20000508 = 1;
      FUN_0800b092((ushort *)0x40005400,1);
      return;
    }
  }
  if (bVar4) {
    uVar2 = FUN_0800b136(_FUN_0801906c);
    *(undefined1 *)*piRam08019070 = uVar2;
    *piRam08019070 = *piRam08019070 + 1;
    _DAT_2000052a = _DAT_2000052a + -1;
    if (_DAT_2000052a == 1) {
      FUN_0800b0c2((ushort *)0x40005400,0);
      FUN_0800b0aa((ushort *)0x40005400,1);
    }
    if (_DAT_2000052a == 0) {
      FUN_0800b120(0x40005400,0x700,0);
      DAT_2000052c = 0;
    }
  }
                    /* WARNING: Read-only address (ram,0x08018c3c) is written */
                    /* WARNING: Read-only address (ram,0x0801906c) is written */
                    /* WARNING: Read-only address (ram,0x08019070) is written */
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08018c3c   (0x08018C3C, 64 Bytes, 2 Teile)
 * Body: 0x08018C3C-0x08018C79, 0x08018D8E-0x08018D91
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08018c3c(int param_1)

{
  *(char *)(param_1 * 2) = (char)param_1;
  FUN_0800b13e(_FUN_0801906c,(ushort)DAT_2000050e,0);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08018d92   (0x08018D92, 107 Bytes)
 * Body: 0x08018D92-0x08018DFD
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08018d92(void)

{
  bool bVar1;
  
  bVar1 = FUN_0800b298(0x40005400,0x10000400);
  if (bVar1) {
    if (DAT_20000508 == '\0') {
      if ((_DAT_40005418 & 1) != 0) {
        FUN_0800b0aa((ushort *)0x40005400,1);
        DAT_2000052c = 3;
      }
    }
    else {
      FUN_0800b092((ushort *)0x40005400,1);
    }
    FUN_0800b2d2(0x40005400,0x400);
  }
  bVar1 = FUN_0800b298(0x40005400,0x10000100);
  if (bVar1) {
    if ((_DAT_40005418 & 1) != 0) {
      FUN_0800b0aa((ushort *)0x40005400,1);
      DAT_2000052c = 3;
    }
    FUN_0800b2d2(0x40005400,0x100);
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08018dfe   (0x08018DFE, 159 Bytes)
 * Body: 0x08018DFE-0x08018E9D
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08018dfe(void)

{
  bool bVar1;
  short sVar2;
  
  sVar2 = -1;
  bVar1 = FUN_0800b48e(0x200000,(uint *)0x40020000);
  if (bVar1) {
    if ((_DAT_40005418 & 1) != 0) {
      FUN_0800b062(0x40005400,0);
      FUN_0800b458((uint *)0x4002006c,0);
      do {
        bVar1 = FUN_0800b298(0x40005400,0x10000004);
        if (bVar1) break;
        sVar2 = sVar2 + -1;
      } while (sVar2 != 0);
      FUN_0800b0aa((ushort *)0x40005400,1);
      do {
        bVar1 = FUN_0800b298(0x40005400,0x20000);
        if (!bVar1) break;
        sVar2 = sVar2 + -1;
      } while (sVar2 != 0);
      DAT_2000052c = 2;
    }
    FUN_0800b4a6(0x200000,0x40020000);
  }
  bVar1 = FUN_0800b48e(0x100000,(uint *)0x40020000);
  if (bVar1) {
    FUN_0800b4a6(0x100000,0x40020000);
  }
  bVar1 = FUN_0800b48e(0x400000,(uint *)0x40020000);
  if (bVar1) {
    FUN_0800b4a6(0x400000,0x40020000);
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08018e9e   (0x08018E9E, 91 Bytes)
 * Body: 0x08018E9E-0x08018EF9
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08018e9e(void)

{
  bool bVar1;
  
  bVar1 = FUN_0800b48e(0x2000000,(uint *)0x40020000);
  if (bVar1) {
    if ((_DAT_40005418 & 1) != 0) {
      FUN_0800b062(0x40005400,0);
      FUN_0800b0aa((ushort *)0x40005400,1);
      DAT_2000052c = 0;
    }
    FUN_0800b4a6(0x2000000,0x40020000);
  }
  bVar1 = FUN_0800b48e(0x1000000,(uint *)0x40020000);
  if (bVar1) {
    FUN_0800b4a6(0x1000000,0x40020000);
  }
  bVar1 = FUN_0800b48e(0x4000000,(uint *)0x40020000);
  if (bVar1) {
    FUN_0800b4a6(0x4000000,0x40020000);
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08018efa   (0x08018EFA, 217 Bytes)
 * Body: 0x08018EFA-0x08018FD3
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08018efa(void)

{
  short sVar1;
  bool bVar2;
  int local_10;
  
  local_10 = 0;
  _DAT_2000050a = 3000;
  do {
    bVar2 = FUN_0800b298(0x40005400,0x20000);
    if (!bVar2) break;
    sVar1 = _DAT_2000050a + -1;
    bVar2 = _DAT_2000050a != 0;
    _DAT_2000050a = sVar1;
  } while (bVar2);
  do {
    FUN_0800b092((ushort *)0x40005400,1);
    _DAT_2000050a = 3000;
    do {
      bVar2 = FUN_0800b254(0x40005400,0x30001);
      if (bVar2) break;
      sVar1 = _DAT_2000050a + -1;
      bVar2 = _DAT_2000050a != 0;
      _DAT_2000050a = sVar1;
    } while (bVar2);
    FUN_0800b13e(0x40005400,0xa0,0);
    _DAT_2000050a = 3000;
    do {
      sVar1 = _DAT_2000050a + -1;
      if (_DAT_2000050a == 0) break;
      _DAT_2000050a = sVar1;
    } while ((_DAT_40005414 & 0x402) == 0);
    if ((_DAT_40005414 & 2) != 0) {
      _DAT_2000050a = sVar1;
      FUN_0800b0aa((ushort *)0x40005400,1);
      return;
    }
    _DAT_2000050a = sVar1;
    FUN_0800b2d2(0x40005400,0x400);
    bVar2 = local_10 == 0x96;
    local_10 = local_10 + 1;
    if (bVar2) {
      return;
    }
  } while( true );
}


/* ---------------------------------------------------------------------
 * FUN_08018fd4   (0x08018FD4, 41 Bytes)
 * Body: 0x08018FD4-0x08018FFD
 * --------------------------------------------------------------------- */
undefined4 FUN_08018fd4(uint param_1,undefined1 *param_2,uint param_3)

{
  undefined1 uVar1;
  
  for (; param_3 != 0; param_3 = param_3 - 1 & 0xffff) {
    uVar1 = FUN_08018a0e(param_1);
    *param_2 = uVar1;
    param_2 = param_2 + 1;
    param_1 = param_1 + 1 & 0xffff;
  }
  FUN_08019166(5);
  return 0;
}


/* ---------------------------------------------------------------------
 * FUN_08018ffe   (0x08018FFE, 105 Bytes)
 * UART-Writer Hilfsfunktion
 * Body: 0x08018FFE-0x08019067
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_08018ffe(int param_1,byte *param_2,uint param_3)

{
  uint uVar1;
  ushort uVar2;
  undefined4 uVar3;
  uint uVar4;
  
  if ((int)(param_1 + param_3) < 0x1001) {
    _DAT_20001eb2 = (ushort)param_1;
    _DAT_20001eb4 = param_2;
    do {
      uVar1 = (((int)(uint)_DAT_20001eb2 >> 5) + 1) * 0x20;
      uVar4 = param_3 - ((uVar1 & 0xffff) - (uint)_DAT_20001eb2);
      uVar2 = (ushort)uVar1;
      if ((int)uVar4 < 1) {
        _DAT_20001ebc = (ushort)param_3;
        FUN_080188ba(_DAT_20001eb4,(uint)_DAT_20001eb2,param_3 & 0xffff);
        param_3 = 0;
      }
      else {
        _DAT_20001ebc = uVar2 - _DAT_20001eb2;
        FUN_080188ba(_DAT_20001eb4,(uint)_DAT_20001eb2,(uint)_DAT_20001ebc);
        param_3 = uVar4 & 0xffff;
        _DAT_20001eb4 = _DAT_20001eb4 + _DAT_20001ebc;
      }
      _DAT_20001eb2 = uVar2;
      FUN_08019166(5);
    } while (param_3 != 0);
    uVar3 = 0;
  }
  else {
    uVar3 = 2;
  }
  return uVar3;
}



/* =====================================================================
 *  SEKTION: 0x08019000 - UART-I/O, Zeitbasis, CAN, Keep-Alive
 * ===================================================================== */

/* ---------------------------------------------------------------------
 * FUN_0801906c   (0x0801906C, 109 Bytes)
 * Body: 0x0801906C-0x080190D9
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0801906c(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint unaff_r5;
  uint uVar3;
  
  *(char *)(param_1 * 2) = (char)param_1;
  uVar2 = unaff_r5 - 2;
  _DAT_20001eb4 = (byte *)0x0;
  while( true ) {
    _DAT_20001eb2 = (ushort)unaff_r5;
    FUN_08019166(5);
    if ((int)uVar2 < 1) break;
    uVar1 = (((int)(uint)_DAT_20001eb2 >> 5) + 1) * 0x20;
    unaff_r5 = uVar1 & 0xffff;
    uVar3 = uVar2 - (unaff_r5 - _DAT_20001eb2);
    if ((int)uVar3 < 1) {
      _DAT_20001ebc = (ushort)uVar2;
      FUN_080188ba(_DAT_20001eb4,(uint)_DAT_20001eb2,uVar2 & 0xffff);
      uVar2 = 0;
    }
    else {
      _DAT_20001ebc = (short)uVar1 - _DAT_20001eb2;
      FUN_080188ba(_DAT_20001eb4,(uint)_DAT_20001eb2,(uint)_DAT_20001ebc);
      uVar2 = uVar3 & 0xffff;
      _DAT_20001eb4 = _DAT_20001eb4 + _DAT_20001ebc;
    }
  }
  return 0;
}


/* ---------------------------------------------------------------------
 * FUN_080190e0   (0x080190E0, 105 Bytes)
 * TIM2-Init (Zeitbasis; Init-Werte 0x1517/0xFFFF)
 * Body: 0x080190E0-0x08019149
 * --------------------------------------------------------------------- */
void FUN_080190e0(void)

{
  byte local_1c [4];
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  undefined2 local_12;
  undefined1 local_10;
  
  local_14 = 0xffff;
  local_18 = 0x1517;
  local_12 = 0;
  local_16 = 0;
  local_10 = 0;
  FUN_0800878c((uint *)0x40000000,&local_18);
  FUN_080090a0(0x40000000,0x1517,1);
  FUN_08008f88(0x40000000,1,1);
  FUN_08008f54((uint *)0x40000000,1);
  local_1c[0] = 0x1c;
  local_1c[1] = 0;
  local_1c[2] = 1;
  local_1c[3] = 1;
  FUN_08007462(local_1c);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801914a   (0x0801914A, 7 Bytes)
 * Zeitbasis-Init Wrapper
 * Body: 0x0801914A-0x08019151
 * --------------------------------------------------------------------- */
void FUN_0801914a(void)

{
  FUN_080190e0();
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08019152   (0x08019152, 19 Bytes)
 * Zeit lesen (ms-Ticks)
 * Body: 0x08019152-0x08019165
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 FUN_08019152(void)

{
  _DAT_20000534 = FUN_0800958a(0x40000000);
  return _DAT_20000534;
}


/* ---------------------------------------------------------------------
 * FUN_08019166   (0x08019166, 87 Bytes)
 * Body: 0x08019166-0x080191BD
 * --------------------------------------------------------------------- */
void FUN_08019166(int param_1)

{
  ushort uVar1;
  uint uVar3;
  uint uVar2;
  
  uVar3 = param_1 * 10 & 0xffff;
  uVar1 = FUN_08019152();
  uVar2 = (uint)uVar1;
  if ((int)(0xffff - uVar3) < (int)uVar2) {
    do {
      uVar1 = FUN_08019152();
    } while (uVar2 < uVar1);
    do {
      uVar1 = FUN_08019152();
    } while ((int)(uint)uVar1 < (int)(param_1 * 10 - (0xffff - uVar3)));
  }
  else {
    do {
      uVar1 = FUN_08019152();
    } while ((int)(uVar1 - uVar2) < param_1 * 10);
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_080191c4   (0x080191C4, 421 Bytes)
 * Body: 0x080191C4-0x08019369
 * --------------------------------------------------------------------- */
undefined8 FUN_080191c4(uint param_1,int param_2)

{
  bool bVar1;
  uint unaff_r6;
  uint unaff_r7;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_2c;
  
  local_2c = 0;
  local_34 = 0;
  if ((((param_2 == 0) || (param_2 == 1)) || (param_2 == 2)) || (param_2 == 3)) {
    FUN_08007c68(1);
    bVar1 = FUN_08007c8a();
    if (!bVar1) {
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    local_38 = 1;
    if ((param_2 == 1) || (param_2 == 3)) {
      unaff_r7 = 1;
      unaff_r6 = 8000000;
      if (param_2 == 3) {
        local_2c = 2;
        unaff_r6 = 4000000;
      }
    }
    else if ((param_2 == 0) || (param_2 == 2)) {
      unaff_r7 = 0;
      unaff_r6 = 16000000;
      if (param_2 == 2) {
        local_2c = 2;
        unaff_r6 = 8000000;
      }
    }
  }
  else {
    local_38 = param_1;
    if (((param_2 == 4) || (param_2 == 5)) || ((param_2 == 6 || (param_2 == 7)))) {
      FUN_08007bb4(0x10000);
      bVar1 = FUN_08007c30();
      if (!bVar1) {
        do {
                    /* WARNING: Do nothing block with infinite loop */
        } while( true );
      }
      if ((param_2 == 5) || (param_2 == 7)) {
        unaff_r7 = 0x30000;
        unaff_r6 = 4000000;
        if (param_2 == 7) {
          local_2c = 2;
          unaff_r6 = 2000000;
        }
      }
      else if ((param_2 == 4) || (param_2 == 6)) {
        unaff_r7 = 0x10000;
        unaff_r6 = 8000000;
        if (param_2 == 6) {
          local_2c = 2;
          unaff_r6 = 4000000;
        }
      }
    }
  }
  if (param_1 < 0x337f981) {
    if (param_1 < 0x19bfcc1) {
      uVar3 = 0;
      iVar4 = 0;
    }
    else {
      uVar3 = 0x400;
      iVar4 = 0;
    }
  }
  else {
    uVar3 = 0x500;
    iVar4 = 0x400;
  }
  if (((param_1 == unaff_r6 * (param_1 / unaff_r6)) && (1 < param_1 / unaff_r6)) &&
     (param_1 / unaff_r6 < 0x21)) {
    uVar2 = param_1 / unaff_r6;
    if (uVar2 < 0x11) {
      uVar2 = (uVar2 - 2) * 0x40000;
    }
    else {
      uVar2 = (uVar2 - 0x11) * 0x40000 | 0x8000000;
    }
    bVar1 = FUN_08007bf8(99);
    if (!bVar1) {
      FUN_08007cdc(4,0x60);
      do {
        bVar1 = FUN_08007d14();
      } while (!bVar1);
      local_34 = 1;
    }
    FUN_08007da4(0);
    FUN_08009640(param_1 / 32000000);
    FUN_08007dc0(0);
    FUN_08007de4(iVar4);
    FUN_08007dd2(uVar3);
    FUN_08007d9e(0);
    FUN_08007d66(unaff_r7,uVar2,local_2c);
    FUN_08007d9e(1);
    do {
      bVar1 = FUN_08007bf8(0x39);
    } while (!bVar1);
    FUN_08007da4(3);
    do {
      uVar3 = FUN_08007db6();
    } while (uVar3 != 0xc);
    if (local_34 == 1) {
      FUN_08007cdc(0,0x60);
    }
    return CONCAT44(local_34,local_38);
  }
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


/* ---------------------------------------------------------------------
 * FUN_0801936a   (0x0801936A, 35 Bytes)
 * Body: 0x0801936A-0x0801938D
 * --------------------------------------------------------------------- */
void FUN_0801936a(void)

{
  FUN_080191c4(108000000,5);
  FUN_08007dd2(0x500);
  FUN_08007f40(1,1);
  FUN_080081e4(0xc,1);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801938e   (0x0801938E, 7 Bytes)
 * Body: 0x0801938E-0x08019395
 * --------------------------------------------------------------------- */
void FUN_0801938e(void)

{
  FUN_0801936a();
  return;
}


/* ---------------------------------------------------------------------
 * FUN_080193bc   (0x080193BC, 15 Bytes)
 * Body: 0x080193BC-0x080193CB
 * --------------------------------------------------------------------- */
void FUN_080193bc(int param_1,undefined4 param_2)

{
  FUN_080079a6(param_1,param_2);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_080193cc   (0x080193CC, 15 Bytes)
 * Body: 0x080193CC-0x080193DB
 * --------------------------------------------------------------------- */
void FUN_080193cc(int param_1,undefined4 param_2)

{
  FUN_080079ae(param_1,param_2);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_080193dc   (0x080193DC, 23 Bytes)
 * Body: 0x080193DC-0x080193F3
 * --------------------------------------------------------------------- */
bool FUN_080193dc(int param_1,uint param_2)

{
  bool bVar1;
  
  bVar1 = FUN_0800798c(param_1,param_2);
  return bVar1;
}


/* ---------------------------------------------------------------------
 * FUN_080193f4   (0x080193F4, 23 Bytes)
 * Body: 0x080193F4-0x0801940B
 * --------------------------------------------------------------------- */
bool FUN_080193f4(int param_1,uint param_2)

{
  bool bVar1;
  
  bVar1 = FUN_08007972(param_1,param_2);
  return bVar1;
}


/* ---------------------------------------------------------------------
 * FUN_0801940c   (0x0801940C, 29 Bytes)
 * Body: 0x0801940C-0x08019429
 * --------------------------------------------------------------------- */
undefined8 FUN_0801940c(uint *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  ushort local_20;
  undefined1 local_1e;
  undefined1 uStack_1d;
  undefined4 uStack_1c;
  undefined4 local_18;
  undefined4 uStack_14;
  
  uStack_1d = (undefined1)((uint)param_1 >> 0x18);
  local_20 = (ushort)param_2;
  local_1e = 1;
  uStack_1c = param_2;
  local_18 = param_3;
  uStack_14 = param_4;
  FUN_08007776(param_1,&local_20);
  return CONCAT44(uStack_1c,CONCAT13(uStack_1d,CONCAT12(local_1e,local_20)));
}


/* ---------------------------------------------------------------------
 * FUN_0801942a   (0x0801942A, 13 Bytes)
 * Body: 0x0801942A-0x08019437
 * --------------------------------------------------------------------- */
void FUN_0801942a(void)

{
  FUN_080079ae(0x40010800,0x8000);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08019438   (0x08019438, 13 Bytes)
 * Body: 0x08019438-0x08019445
 * --------------------------------------------------------------------- */
void FUN_08019438(void)

{
  FUN_080079ae(0x40011000,0x4000);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08019446   (0x08019446, 11 Bytes)
 * Body: 0x08019446-0x08019451
 * --------------------------------------------------------------------- */
void FUN_08019446(void)

{
  FUN_080079a6(0x40010c00,0x20);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08019452   (0x08019452, 153 Bytes)
 * Body: 0x08019452-0x080194EB
 * --------------------------------------------------------------------- */
undefined8 FUN_08019452(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  ushort local_18;
  undefined1 local_16;
  undefined1 uStack_15;
  undefined4 uStack_14;
  undefined4 local_10;
  undefined4 uStack_c;
  
  local_18 = (ushort)param_1;
  local_16 = (undefined1)((uint)param_1 >> 0x10);
  uStack_15 = (undefined1)((uint)param_1 >> 0x18);
  uStack_14 = param_2;
  local_10 = param_3;
  uStack_c = param_4;
  FUN_080081e4(0x1c,1);
  FUN_0800795a(&local_18);
  local_18 = 0x8000;
  local_10 = 1;
  local_16 = 1;
  FUN_08007776((uint *)0x40010800,&local_18);
  local_18 = 0x100;
  local_10 = 0;
  local_16 = 1;
  FUN_08007776((uint *)0x40010800,&local_18);
  local_18 = 0xf03c;
  local_10 = 1;
  local_16 = 1;
  FUN_08007776((uint *)0x40010c00,&local_18);
  local_18 = 0x6000;
  local_10 = 1;
  local_16 = 1;
  FUN_08007776((uint *)0x40011000,&local_18);
  local_18 = 0x8000;
  local_10 = 0;
  local_16 = 1;
  FUN_08007776((uint *)0x40011000,&local_18);
  FUN_08019446();
  FUN_08019438();
  FUN_0801942a();
  return CONCAT44(uStack_14,CONCAT13(uStack_15,CONCAT12(local_16,local_18)));
}


/* ---------------------------------------------------------------------
 * FUN_080194ec   (0x080194EC, 7 Bytes)
 * Body: 0x080194EC-0x080194F3
 * --------------------------------------------------------------------- */
undefined8 FUN_080194ec(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined8 uVar1;
  
  uVar1 = FUN_08019452(param_1,param_2,param_3,param_4);
  return uVar1;
}


/* ---------------------------------------------------------------------
 * FUN_080194f4   (0x080194F4, 31 Bytes)
 * Body: 0x080194F4-0x08019513
 * --------------------------------------------------------------------- */
void FUN_080194f4(void)

{
  bool bVar1;
  
  bVar1 = FUN_0800798c(0x40011000,0x2000);
  FUN_080079b2(0x40011000,0x2000,(uint)!bVar1);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08019568   (0x08019568, 11 Bytes)
 * Body: 0x08019568-0x08019573
 * --------------------------------------------------------------------- */
void FUN_08019568(void)

{
  FUN_080079ae(0x40010c00,8);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08019574   (0x08019574, 11 Bytes)
 * Body: 0x08019574-0x0801957F
 * --------------------------------------------------------------------- */
void FUN_08019574(void)

{
  FUN_080079ae(0x40010c00,0x20);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08019580   (0x08019580, 27 Bytes)
 * Body: 0x08019580-0x0801959B
 * --------------------------------------------------------------------- */
void FUN_08019580(void)

{
  bool bVar1;
  
  bVar1 = FUN_0800798c(0x40010c00,0x20);
  FUN_080079b2(0x40010c00,0x20,(uint)!bVar1);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801959c   (0x0801959C, 31 Bytes)
 * Body: 0x0801959C-0x080195BB
 * --------------------------------------------------------------------- */
void FUN_0801959c(void)

{
  DAT_2000004c = FUN_080193f4(0x40010800,0x100);
  DAT_20000397 = FUN_080193f4(0x40011000,0x8000);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_080195be   (0x080195BE, 29 Bytes)
 * Body: 0x080195BE-0x080195DB
 * --------------------------------------------------------------------- */
void FUN_080195be(int param_1,int param_2,undefined4 param_3)

{
  if (param_1 == 0) {
    FUN_080193cc(param_2,param_3);
  }
  else {
    FUN_080193bc(param_2,param_3);
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_080195dc   (0x080195DC, 127 Bytes)
 * Body: 0x080195DC-0x0801965B
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_080195dc(void)

{
  FUN_080195be((uint)(DAT_20000050 != '\0'),0x40010c00,0x10);
  FUN_080195be((uint)(DAT_20000052 != '\0'),0x40010c00,0x1000);
  if ((DAT_20000391 == '\x01') || (DAT_20000391 == '\x03')) {
    FUN_080195be(0,0x40010c00,8);
    _DAT_20000538 = _DAT_20000538 + 1;
    if (0x19 < _DAT_20000538) {
      _DAT_20000538 = 0;
      FUN_08019580();
      DAT_2000032d = DAT_2000032d == '\0';
    }
  }
  else {
    FUN_08019568();
    FUN_08019574();
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801965c   (0x0801965C, 1 Bytes)
 * Body: 0x0801965C-0x0801965D
 * --------------------------------------------------------------------- */
void FUN_0801965c(void)

{
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08019690   (0x08019690, 149 Bytes)
 * Body: 0x08019690-0x08019725
 * --------------------------------------------------------------------- */
void FUN_08019690(void)

{
  bool bVar1;
  byte local_24 [4];
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 local_18;
  ushort local_14 [4];
  undefined4 local_c;
  
  FUN_080081ca(0x1000,1);
  FUN_0800a552(0,7);
  FUN_08007e4a(0x20000,0x7000);
  FUN_0800795a(local_14);
  local_14[0] = 0x83;
  local_c = 3;
  FUN_08007776((uint *)0x40010800,local_14);
  local_14[0] = 3;
  local_c = 3;
  FUN_08007776((uint *)0x40010c00,local_14);
  local_24[0] = 0;
  local_24[1] = 0;
  local_20 = 0xe0000;
  local_1c = 0;
  local_18 = 1;
  FUN_0800a068(0x40020800,local_24);
  FUN_0800a0ba(0x40020800,1);
  do {
    bVar1 = FUN_0800a51a(0x40020800,0x20);
  } while (!bVar1);
  FUN_0800a0fe(0x40020800);
  do {
    bVar1 = FUN_0800a10c(0x40020800);
  } while (bVar1);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08019726   (0x08019726, 41 Bytes)
 * Body: 0x08019726-0x0801974F
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08019726(void)

{
  _DAT_2000053c = (((uint)_DAT_20000038 * 0x409) / 0x21 + _DAT_2000053c * 2) / 3;
  _DAT_20000044 = _DAT_2000053c;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08019750   (0x08019750, 77 Bytes)
 * Body: 0x08019750-0x0801979D
 * --------------------------------------------------------------------- */
uint FUN_08019750(int param_1)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 0xfffffff;
  FUN_0800a17e(0x40020800,param_1,1,5);
  FUN_0800a126(0x40020800,1);
  do {
    bVar1 = FUN_0800a454((uint *)0x40020800,2);
    if (bVar1) break;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  FUN_0800a466((uint *)0x40020800,2);
  FUN_0800a466((uint *)0x40020800,0x10);
  uVar2 = FUN_0800a25a(0x40020800);
  return uVar2;
}


/* ---------------------------------------------------------------------
 * FUN_0801979e   (0x0801979E, 279 Bytes)
 * Body: 0x0801979E-0x080198B5
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0801979e(void)

{
  uint uVar1;
  
  uVar1 = FUN_08019750(8);
  _DAT_20000032 = (undefined2)((((int)(uVar1 * 0xce4) / 0xfff) * 0x409) / 1000);
  uVar1 = FUN_08019750(9);
  _DAT_20000034 = (undefined2)((((int)(uVar1 * 0xce4) / 0xfff) * 0x409) / 1000);
  uVar1 = FUN_08019750(10);
  _DAT_20000036 = (undefined2)((((int)(uVar1 * 0xce4) / 0xfff) * 0x409) / 1000);
  uVar1 = FUN_08019750(1);
  _DAT_2000003e = (undefined2)((((int)(uVar1 * 0xce4) / 0xfff) * 0x409) / 1000);
  uVar1 = FUN_08019750(2);
  _DAT_20000040 = (undefined2)((((int)(uVar1 * 0xce4) / 0xfff) * 0x409) / 1000);
  uVar1 = FUN_08019750(5);
  _DAT_20000038 = (undefined2)((int)(uVar1 * 0xce4) / 0xfff);
  uVar1 = FUN_08019750(7);
  _DAT_2000003c = (undefined2)((int)(uVar1 * 0xce4) / 0xfff);
  uVar1 = FUN_08019750(6);
  _DAT_2000003a = (undefined2)((int)(uVar1 * 0xce4) / 0xfff);
  FUN_08019726();
  return;
}


/* ---------------------------------------------------------------------
 * FUN_080198ec   (0x080198EC, 513 Bytes)
 * UART-Init: USART1 115200 (DMA5), USART2 9600, USART3 9600 (DMA7) + GPIO
 * Body: 0x080198EC-0x08019AED
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_080198ec(int param_1)

{
  ushort uVar1;
  short sVar3;
  byte local_2c [4];
  ushort local_28 [2];
  undefined1 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  undefined2 local_14;
  undefined2 local_12;
  undefined2 local_10;
  undefined2 local_e;
  undefined2 local_c;
  ushort uVar2;
  
  sVar3 = (short)((uint)param_1 >> 0x10);
  uVar1 = sVar3 >> 4;
  uVar2 = sVar3 >> 3;
  if (param_1 == 0x40013800) {
    FUN_080081e4(0x4000,1);
    local_28[0] = 0x200;
    local_20 = 2;
    local_1c = 4;
    FUN_08007776((uint *)0x40010800,local_28);
    local_24 = 1;
    local_1c = 4;
    local_28[0] = uVar1;
    FUN_08007776((uint *)0x40010800,local_28);
    local_20 = 0;
    local_1c = 4;
    local_28[0] = uVar2;
    FUN_08007776((uint *)0x40010800,local_28);
    local_28[0] = 0x1000;
    local_20 = 2;
    local_1c = 4;
    FUN_08007776((uint *)0x40010800,local_28);
    local_2c[0] = 0x25;
    local_2c[1] = 0;
    local_2c[2] = 0;
    local_2c[3] = 1;
    FUN_08007462(local_2c);
    FUN_0800842e(&local_18);
    local_18 = 0x1c200;
    local_14 = 0;
    local_12 = 0;
    local_10 = 0;
    local_c = 0x300;
    local_e = 0xc;
    FUN_08008386(0x40013800,&local_18);
    FUN_0800848c(0x40013800,0x525,1);
    FUN_08008474(0x40013800,1);
  }
  if (param_1 == _FUN_08019bc0) {
    FUN_08007f40(0x20000,1);
    local_28[0] = 4;
    local_20 = 2;
    local_1c = 4;
    FUN_08007776((uint *)0x40010800,local_28);
    local_28[0] = 8;
    local_24 = 1;
    local_1c = 4;
    FUN_08007776((uint *)0x40010800,local_28);
    local_2c[0] = 0x26;
    local_2c[1] = 3;
    local_2c[2] = 3;
    local_2c[3] = 1;
    FUN_08007462(local_2c);
    FUN_0800842e(&local_18);
    local_18 = 0x2580;
    local_14 = 0;
    local_12 = 0;
    local_10 = 0;
    local_c = 0;
    local_e = 0xc;
    FUN_08008386(param_1,&local_18);
    FUN_0800848c(param_1,0x525,1);
    FUN_08008474(param_1,1);
  }
  if (param_1 == iRam08019bc4) {
    FUN_08007f40(0x40000,1);
    local_20 = 2;
    local_1c = 0;
    local_28[0] = uVar1;
    FUN_08007776((uint *)0x40010c00,local_28);
    local_24 = 1;
    local_1c = 5;
    local_28[0] = uVar2;
    FUN_08007776((uint *)0x40010c00,local_28);
    local_2c[0] = 0x27;
    local_2c[1] = 4;
    local_2c[2] = 4;
    local_2c[3] = 1;
    FUN_08007462(local_2c);
    FUN_0800842e(&local_18);
    local_18 = 0x2580;
    local_14 = 0;
    local_12 = 0;
    local_10 = 0;
    local_c = 0;
    local_e = 0xc;
    FUN_08008386(param_1,&local_18);
    FUN_0800848c(param_1,0x525,1);
    FUN_08008474(param_1,1);
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08019aee   (0x08019AEE, 43 Bytes)
 * Body: 0x08019AEE-0x08019B19
 * --------------------------------------------------------------------- */
void FUN_08019aee(ushort *param_1,int param_2)

{
  bool bVar1;
  short sVar2;
  
  sVar2 = 0xfff;
  FUN_0800854e((int)param_1,param_2);
  do {
    bVar1 = FUN_080085fc(param_1,0x80);
    if (bVar1) {
      return;
    }
    sVar2 = sVar2 + -1;
  } while (sVar2 != 0);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08019b1a   (0x08019B1A, 31 Bytes)
 * UART-Write generisch (USART-Basis als Parameter)
 * Body: 0x08019B1A-0x08019B39
 * --------------------------------------------------------------------- */
void FUN_08019b1a(ushort *param_1,byte *param_2,uint param_3)

{
  bool bVar1;
  
  while (bVar1 = param_3 != 0, param_3 = param_3 - 1 & 0xffff, bVar1) {
    FUN_08019aee(param_1,(uint)*param_2);
    param_2 = param_2 + 1;
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08019b3a   (0x08019B3A, 17 Bytes)
 * USART1-Sender (BLE)
 * Body: 0x08019B3A-0x08019B4B
 * --------------------------------------------------------------------- */
void FUN_08019b3a(byte *param_1,uint param_2)

{
  FUN_08019b1a((ushort *)0x40013800,param_1,param_2);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08019b4c   (0x08019B4C, 17 Bytes)
 * USART2-Sender (ESC)
 * Body: 0x08019B4C-0x08019B5D
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08019b4c(byte *param_1,uint param_2)

{
  FUN_08019b1a(_FUN_08019bc0,param_1,param_2);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08019b5e   (0x08019B5E, 17 Bytes)
 * USART3-Sender (Display)
 * Body: 0x08019B5E-0x08019B6F
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08019b5e(byte *param_1,uint param_2)

{
  FUN_08019b1a(FUN_08019bc0,param_1,param_2);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08019b82   (0x08019B82, 51 Bytes)
 * Keep-Alive: 10-Byte-Zaehlerframe an ESC + Display
 * Body: 0x08019B82-0x08019BB5
 * --------------------------------------------------------------------- */
void FUN_08019b82(void)

{
  uint uVar1;
  byte local_d0 [200];
  
  FUN_0801d31e(local_d0,200);
  for (uVar1 = 0; uVar1 < 10; uVar1 = uVar1 + 1 & 0xffff) {
    local_d0[uVar1] = (byte)uVar1;
  }
  FUN_08019b4c(local_d0,10);
  FUN_08019b5e(local_d0,10);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08019bc0   (0x08019BC0, 23 Bytes)
 * Body: 0x08019BC0-0x08019BD7
 * --------------------------------------------------------------------- */
undefined8 FUN_08019bc0(void)

{
  undefined1 *puVar1;
  int iVar2;
  bool bVar3;
  undefined8 uVar4;
  
  iVar2 = 0;
  uVar4 = FUN_080096f8();
  puVar1 = (undefined1 *)((ulonglong)uVar4 >> 0x20);
  if ((int)uVar4 == 1) {
    do {
      bVar3 = iVar2 != 0;
      iVar2 = iVar2 + -1;
    } while (bVar3);
  }
  if (iVar2 != 0) {
    puVar1 = &DAT_20000546;
    DAT_20000546 = 1;
  }
  return CONCAT44(puVar1,(uint)(iVar2 != 0));
}


/* ---------------------------------------------------------------------
 * FUN_08019bd8   (0x08019BD8, 37 Bytes)
 * Body: 0x08019BD8-0x08019BFD
 * --------------------------------------------------------------------- */
undefined8 FUN_08019bd8(void)

{
  undefined1 *puVar1;
  int iVar2;
  bool bVar3;
  undefined8 uVar4;
  
  iVar2 = 0;
  uVar4 = FUN_080096f8();
  puVar1 = (undefined1 *)((ulonglong)uVar4 >> 0x20);
  if ((int)uVar4 == 1) {
    do {
      bVar3 = iVar2 != 0;
      iVar2 = iVar2 + -1;
    } while (bVar3);
  }
  if (iVar2 != 0) {
    puVar1 = &DAT_20000546;
    DAT_20000546 = 1;
  }
  return CONCAT44(puVar1,(uint)(iVar2 != 0));
}


/* ---------------------------------------------------------------------
 * FUN_08019bfe   (0x08019BFE, 69 Bytes)
 * Body: 0x08019BFE-0x08019C43
 * --------------------------------------------------------------------- */
bool FUN_08019bfe(int *param_1,int param_2)

{
  FUN_08009740();
  FUN_080097cc(0x34);
  FUN_08009ada(param_1,param_2);
  FUN_080097cc(0x20);
  FUN_0800974c();
  return *param_1 == param_2;
}


/* ---------------------------------------------------------------------
 * FUN_08019c44   (0x08019C44, 87 Bytes)
 * Body: 0x08019C44-0x08019C9B
 * --------------------------------------------------------------------- */
undefined4 FUN_08019c44(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar2 = 0;
  uVar3 = 0;
  FUN_08009740();
  FUN_080097cc(0x34);
  do {
    if (param_2 <= uVar2) {
code_r0x08019c8c:
      FUN_080097cc(0x20);
      FUN_0800974c();
      return uVar3;
    }
    if ((param_1 + uVar2 * 0x400 & 0x7ff) == 0) {
      iVar1 = FUN_080097d8(param_1 + uVar2 * 0x400);
      if (iVar1 != 6) {
        uVar3 = 0;
        goto code_r0x08019c8c;
      }
      uVar3 = 1;
    }
    uVar2 = uVar2 + 1 & 0xff;
  } while( true );
}


/* ---------------------------------------------------------------------
 * FUN_08019ca0   (0x08019CA0, 399 Bytes)
 * Body: 0x08019CA0-0x08019E2F
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08019ca0(void)

{
  int iVar1;
  undefined4 in_r3;
  undefined4 extraout_r3;
  uint uVar2;
  
  uVar2 = 0;
  do {
    if (0xb < uVar2) {
code_r0x08019d0c:
      if (DAT_20000558 == '\0') {
        iVar1 = FUN_08016de2(0x20000548,(ushort *)&DAT_20000550,(int *)&DAT_20000554,in_r3);
        if (iVar1 == 2) {
          DAT_20000558 = '\x01';
          iVar1 = FUN_0801bb30(_DAT_20000554,0,0x20000548,(uint)DAT_20000550);
          if (iVar1 == 0) {
            DAT_20000558 = '\0';
          }
        }
        else {
          DAT_20000558 = '\0';
        }
      }
      else {
        iVar1 = FUN_0801bb30(_DAT_20000554,0,0x20000548,(uint)DAT_20000550);
        if (iVar1 == 0) {
          DAT_20000558 = '\0';
        }
      }
      if (DAT_2000008b == '\x02') {
        iVar1 = FUN_0801bb30(_DAT_2000055c,0,0x20000560,8);
        if (iVar1 == 0) {
          DAT_2000008b = '\0';
        }
        DAT_20000559 = DAT_20000559 + 1;
        if (2 < DAT_20000559) {
          DAT_2000008b = '\0';
          DAT_20000559 = 0;
        }
      }
      else if (DAT_2000008c == '\x02') {
        iVar1 = FUN_0801bb30(_DAT_2000056c,1,0x20000570,8);
        if (iVar1 == 0) {
          DAT_2000008c = '\0';
        }
        DAT_20000568 = DAT_20000568 + 1;
        if (2 < DAT_20000568) {
          DAT_2000008c = '\0';
          DAT_20000568 = 0;
        }
      }
      if (DAT_2000009e != '\0') {
        if (DAT_20000578 == '\0') {
          DAT_20000578 = '\x01';
          DAT_20000581 = (undefined1)((ushort)_DAT_2000009c >> 8);
          DAT_20000582 = DAT_2000009c;
          iVar1 = FUN_0801bb30(_DAT_2000057c,0,0x20000580,8);
          if (iVar1 == 0) {
            DAT_20000578 = '\0';
            DAT_2000009e = '\0';
          }
        }
        else {
          iVar1 = FUN_0801bb30(_DAT_2000057c,0,0x20000580,8);
          if (iVar1 == 0) {
            DAT_20000578 = '\0';
            DAT_2000009e = '\0';
          }
        }
      }
      return;
    }
    if (((*(char *)(uVar2 * 0x1c + 0x200024ae) == '\x01') &&
        (*(byte *)(uVar2 * 0x1c + 0x200024ac) < 9)) &&
       (iVar1 = FUN_0801bb30(*(undefined4 *)(uVar2 * 0x1c + 0x200024a0),
                             (uint)*(byte *)(uVar2 * 0x1c + 0x200024a4),
                             *(int *)(uVar2 * 0x1c + 0x200024a8),
                             (uint)*(byte *)(uVar2 * 0x1c + 0x200024ac)), in_r3 = extraout_r3,
       iVar1 == 0)) {
      *(undefined1 *)(uVar2 * 0x1c + 0x200024ae) = 0;
      goto code_r0x08019d0c;
    }
    uVar2 = uVar2 + 1 & 0xff;
  } while( true );
}


/* ---------------------------------------------------------------------
 * FUN_08019e30   (0x08019E30, 225 Bytes)
 * Body: 0x08019E30-0x08019F11
 * --------------------------------------------------------------------- */
void FUN_08019e30(void)

{
  short sVar1;
  uint uVar2;
  
  sVar1 = FUN_08019152();
  for (uVar2 = 0; uVar2 < 0xc; uVar2 = uVar2 + 1 & 0xff) {
    if ((((*(char *)(uVar2 * 0x1c + 0x200024ad) == '\x01') &&
         (*(char *)(uVar2 * 0x1c + 0x200024af) == '\x01')) &&
        (*(char *)(uVar2 * 0x1c + 0x200024ae) == '\0')) &&
       (*(ushort *)(uVar2 * 0x1c + 0x200024b0) <
        (ushort)(sVar1 - *(short *)(uVar2 * 0x1c + 0x200024b2)))) {
      if (*(int *)(uVar2 * 0x1c + 0x200024b4) != 0) {
        (**(code **)(uVar2 * 0x1c + 0x200024b4))();
      }
      *(undefined1 *)(uVar2 * 0x1c + 0x200024ae) = 1;
      *(short *)(uVar2 * 0x1c + 0x200024b2) = sVar1;
    }
  }
  for (uVar2 = 0; uVar2 < 0x16; uVar2 = uVar2 + 1 & 0xff) {
    if (((*(char *)(uVar2 * 0x20 + 0x200021ed) == '\x01') &&
        (*(char *)(uVar2 * 0x20 + 0x200021ef) == '\x01')) &&
       (((uint)(*(int *)(uVar2 * 0x20 + 0x200021f0) << 2) <
         (uint)(ushort)(sVar1 - *(short *)(uVar2 * 0x20 + 0x200021f4)) &&
        (*(int *)(uVar2 * 0x20 + 0x200021fc) != 0)))) {
      (**(code **)(uVar2 * 0x20 + 0x200021fc))();
    }
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08019f60   (0x08019F60, 143 Bytes)
 * Body: 0x08019F60-0x08019FEF
 * --------------------------------------------------------------------- */
void FUN_08019f60(int param_1,undefined4 param_2,undefined1 param_3,undefined1 param_4,int param_5,
                 undefined4 param_6,undefined1 param_7,undefined4 param_8,undefined4 param_9)

{
  undefined2 uVar1;
  
  if (param_1 < 0x16) {
    *(undefined4 *)(param_1 * 0x20 + 0x200021e0) = param_2;
    *(undefined1 *)(param_1 * 0x20 + 0x200021ec) = param_4;
    *(undefined1 *)(param_1 * 0x20 + 0x200021e4) = param_3;
    *(int *)(param_1 * 0x20 + 0x200021f0) = param_5 * 10;
    *(undefined4 *)(param_1 * 0x20 + 0x200021e8) = param_6;
    *(undefined1 *)(param_1 * 0x20 + 0x200021ed) = (&DAT_200025f0)[param_1];
    *(undefined1 *)(param_1 * 0x20 + 0x200021ee) = 0;
    *(undefined1 *)(param_1 * 0x20 + 0x200021ef) = param_7;
    uVar1 = FUN_08019152();
    *(undefined2 *)(param_1 * 0x20 + 0x200021f4) = uVar1;
    *(undefined4 *)(param_1 * 0x20 + 0x200021f8) = param_8;
    *(undefined4 *)(param_1 * 0x20 + 0x200021fc) = param_9;
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_08019ff0   (0x08019FF0, 181 Bytes)
 * Body: 0x08019FF0-0x0801A0A5
 * --------------------------------------------------------------------- */
void FUN_08019ff0(int param_1,undefined4 param_2,undefined1 param_3,undefined1 param_4,short param_5
                 ,undefined4 param_6,undefined1 param_7,undefined4 param_8,undefined4 param_9)

{
  undefined2 uVar1;
  
  if (param_1 < 0xc) {
    *(undefined4 *)(param_1 * 0x1c + 0x200024a0) = param_2;
    *(undefined1 *)(param_1 * 0x1c + 0x200024a4) = param_3;
    *(undefined1 *)(param_1 * 0x1c + 0x200024ac) = param_4;
    *(short *)(param_1 * 0x1c + 0x200024b0) = param_5 * 10;
    *(undefined4 *)(param_1 * 0x1c + 0x200024a8) = param_6;
    *(undefined1 *)(param_1 * 0x1c + 0x200024ad) = (&DAT_20002606)[param_1];
    *(undefined1 *)(param_1 * 0x1c + 0x200024ae) = 0;
    *(undefined1 *)(param_1 * 0x1c + 0x200024af) = param_7;
    uVar1 = FUN_08019152();
    *(undefined2 *)(param_1 * 0x1c + 0x200024b2) = uVar1;
    *(undefined4 *)(param_1 * 0x1c + 0x200024b4) = param_8;
    *(undefined4 *)(param_1 * 0x1c + 0x200024b8) = param_9;
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801a1a8   (0x0801A1A8, 113 Bytes)
 * Body: 0x0801A1A8-0x0801A219
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0801a1a8(void)

{
  byte bVar1;
  ushort uVar2;
  
  if (DAT_2000036d < 0x29) {
    bVar1 = 0;
  }
  else {
    bVar1 = DAT_2000036d - 0x28;
  }
  uVar2 = CONCAT11(DAT_2000035e,DAT_2000035f);
  FUN_0800b97a((undefined1 *)0x200005b8,0,8);
  FUN_0800b912(0,8,(uint)bVar1,0x200005b8);
  FUN_0800b912(8,8,(uint)DAT_20000364,0x200005b8);
  FUN_0800b912(0x18,0x10,(uint)uVar2,0x200005b8);
  FUN_0800b912(0x28,0x10,(uint)_DAT_200002f0,0x200005b8);
  FUN_0800b912(0x30,8,(uint)DAT_200002f2,0x200005b8);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801a21a   (0x0801A21A, 95 Bytes)
 * Body: 0x0801A21A-0x0801A279
 * --------------------------------------------------------------------- */
void FUN_0801a21a(void)

{
  uint uVar1;
  
  if (DAT_20000309 == '\0') {
    uVar1 = (uint)DAT_200002a1;
  }
  else {
    uVar1 = 0;
  }
  FUN_0800b97a((undefined1 *)0x200005b0,0,8);
  FUN_0800b912(0,8,uVar1,0x200005b0);
  FUN_0800b912(8,8,(uint)DAT_200002a2,0x200005b0);
  FUN_0800b912(0x10,8,(uint)DAT_20000306,0x200005b0);
  FUN_0800b912(0x18,8,(uint)DAT_200002a5,0x200005b0);
  FUN_0800b912(0x20,8,(uint)DAT_200002c7,0x200005b0);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801a27a   (0x0801A27A, 97 Bytes)
 * Body: 0x0801A27A-0x0801A2DB
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0801a27a(void)

{
  FUN_0800b97a((undefined1 *)0x200005a8,0,8);
  FUN_0800b912(0,8,(uint)DAT_200002e6,0x200005a8);
  FUN_0800b912(8,8,(uint)DAT_200002e7,0x200005a8);
  FUN_0800b912(0x18,0x10,(uint)_DAT_200002e8,0x200005a8);
  FUN_0800b912(0x20,8,(uint)DAT_200002ea,0x200005a8);
  FUN_0800b912(0x30,0x10,(uint)_DAT_200002ec,0x200005a8);
  FUN_0800b912(0x38,8,(uint)DAT_200002ee,0x200005a8);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801a2dc   (0x0801A2DC, 109 Bytes)
 * Body: 0x0801A2DC-0x0801A349
 * --------------------------------------------------------------------- */
void FUN_0801a2dc(void)

{
  uint uVar1;
  
  if (DAT_20000309 == '\0') {
    uVar1 = (uint)DAT_200002a1;
  }
  else {
    uVar1 = 0;
  }
  FUN_0800b97a((undefined1 *)0x200005a0,0,8);
  FUN_0800b912(0,8,uVar1,0x200005a0);
  FUN_0800b912(8,8,(uint)DAT_200002a3,0x200005a0);
  FUN_0800b912(0x10,8,(uint)DAT_20000306,0x200005a0);
  FUN_0800b912(0x18,8,(uint)DAT_200002a5,0x200005a0);
  FUN_0800b912(0x20,8,(uint)DAT_200002c7,0x200005a0);
  FUN_0800b912(0x28,8,(uint)DAT_20000399,0x200005a0);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801a34a   (0x0801A34A, 202 Bytes, 2 Teile)
 * Body: 0x0801A34A-0x0801A365, 0x0801A404-0x0801A4B3
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0801a34a(void)

{
  uint uVar1;
  
  if ((DAT_200002a3 & 0x80) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 8;
  }
  if (_DAT_20000034 < 0x1f5) {
    uVar1 = DAT_200002dc & 0xd7 | uVar1;
  }
  else {
    uVar1 = DAT_200002dc & 0xf7 | uVar1 | 0x20;
  }
  if (_DAT_20000036 < 0x1f5) {
    uVar1 = uVar1 & 0xbf;
  }
  else {
    uVar1 = uVar1 | 0x40;
  }
  if (_DAT_20000032 < 0x1f5) {
    uVar1 = uVar1 & 0xef;
  }
  else {
    uVar1 = uVar1 | 0x10;
  }
  if (DAT_2000030d == '\0') {
    uVar1 = uVar1 & 0xfd;
  }
  else {
    uVar1 = uVar1 | 2;
  }
  FUN_0800b97a((undefined1 *)0x20000598,0,8);
  FUN_0800b912(0,8,(uint)DAT_200002db,0x20000598);
  FUN_0800b912(8,8,uVar1,0x20000598);
  FUN_0800b912(0x18,0x10,(uint)_DAT_200002de,0x20000598);
  FUN_0800b912(0x20,8,(uint)DAT_200002e0,0x20000598);
  FUN_0800b912(0x30,0x10,(uint)_DAT_200002e2,0x20000598);
  FUN_0800b912(0x38,8,(uint)DAT_200002e4,0x20000598);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801a4b4   (0x0801A4B4, 63 Bytes)
 * Body: 0x0801A4B4-0x0801A4F3
 * --------------------------------------------------------------------- */
void FUN_0801a4b4(void)

{
  FUN_0800b97a(&DAT_20000590,0,8);
  DAT_20000590 = DAT_20000010;
  DAT_20000591 = DAT_20000011;
  DAT_20000592 = DAT_20000012;
  DAT_20000593 = DAT_20000013;
  DAT_20000594 = DAT_2000000f;
  DAT_20000595 = DAT_20000019;
  DAT_20000596 = DAT_2000001a;
  DAT_20000597 = DAT_2000001b;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801a4f4   (0x0801A4F4, 167 Bytes)
 * Body: 0x0801A4F4-0x0801A59B
 * --------------------------------------------------------------------- */
void FUN_0801a4f4(void)

{
  uint uVar1;
  
  FUN_0800b97a(&DAT_20000588,0,8);
  if (DAT_20000698 == '\b') {
    DAT_20000588 = DAT_20000698;
    for (uVar1 = 0; uVar1 < 7; uVar1 = uVar1 + 1 & 0xff) {
      *(undefined1 *)(uVar1 + 0x20000589) = (&DAT_20000742)[uVar1];
    }
    DAT_20000698 = DAT_20000698 + '\x01';
  }
  else if (DAT_20000698 == '\t') {
    DAT_20000588 = DAT_20000698;
    for (uVar1 = 0; uVar1 < 7; uVar1 = uVar1 + 1 & 0xff) {
      *(undefined1 *)(uVar1 + 0x20000589) = (&DAT_20000749)[uVar1];
    }
    DAT_20000698 = DAT_20000698 + '\x01';
  }
  else if (DAT_20000698 == '\n') {
    DAT_20000588 = DAT_20000698;
    for (uVar1 = 0; uVar1 < 5; uVar1 = uVar1 + 1 & 0xff) {
      *(undefined1 *)(uVar1 + 0x20000589) = (&DAT_20000750)[uVar1];
    }
    DAT_20000698 = '\b';
  }
  else {
    DAT_20000698 = '\b';
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801a644   (0x0801A644, 91 Bytes)
 * Body: 0x0801A644-0x0801A69F
 * --------------------------------------------------------------------- */
void FUN_0801a644(void)

{
  if ((DAT_2000067e == 'Z') && (DAT_2000067f == -0x5b)) {
    if (DAT_20000678 == '\0') {
      if (((DAT_2000067b == -1) && (DAT_2000067c == -1)) && (DAT_2000067d == -1)) {
        FUN_0801744c();
      }
    }
    else if (DAT_20000678 == '\x01') {
      FUN_08017230();
    }
    else if (DAT_20000678 == '\x02') {
      FUN_080171ea();
    }
    else if (DAT_20000678 == '\x03') {
      FUN_08017186();
    }
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801a6a0   (0x0801A6A0, 39 Bytes)
 * Body: 0x0801A6A0-0x0801A6C7
 * --------------------------------------------------------------------- */
void FUN_0801a6a0(void)

{
  if ((((DAT_20000680 == -0x56) && (DAT_20000682 == -0x56)) && (DAT_20000684 == -0x56)) &&
     (DAT_20000686 == -0x56)) {
    FUN_08016ec0();
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801a6c8   (0x0801A6C8, 222 Bytes, 2 Teile)
 * Body: 0x0801A6C8-0x0801A6ED, 0x0801A6FA-0x0801A7B3
 * --------------------------------------------------------------------- */
void FUN_0801a6c8(void)

{
  byte bVar1;
  
  for (bVar1 = 0; bVar1 < 7; bVar1 = bVar1 + 1) {
  }
  switch(DAT_20000670) {
  case 1:
    break;
  case 2:
    break;
  case 3:
    break;
  case 4:
    break;
  case 5:
    break;
  case 6:
    break;
  case 7:
    break;
  case 8:
    DAT_20000755 = DAT_20000671;
    DAT_20000756 = DAT_20000672;
    DAT_20000757 = DAT_20000673;
    DAT_20000758 = DAT_20000674;
    DAT_20000759 = DAT_20000675;
    DAT_2000075a = DAT_20000676;
    DAT_2000075b = DAT_20000677;
    DAT_200000a3 = '\x01';
    break;
  case 9:
    if (DAT_200000a3 == '\x01') {
      DAT_2000075c = DAT_20000671;
      DAT_2000075d = DAT_20000672;
      DAT_2000075e = DAT_20000673;
      DAT_2000075f = DAT_20000674;
      DAT_20000760 = DAT_20000675;
      DAT_20000761 = DAT_20000676;
      DAT_20000762 = DAT_20000677;
      DAT_200000a3 = '\x02';
    }
    break;
  case 10:
    if (DAT_200000a3 == '\x02') {
      DAT_20000763 = DAT_20000671;
      DAT_20000764 = DAT_20000672;
      DAT_20000765 = DAT_20000673;
      DAT_20000766 = DAT_20000674;
      DAT_20000767 = DAT_20000675;
      DAT_200000a3 = '\0';
      FUN_08018236(0x20000755);
    }
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801a7b4   (0x0801A7B4, 228 Bytes, 2 Teile)
 * Body: 0x0801A7B4-0x0801A803, 0x0801A8A0-0x0801A935
 * --------------------------------------------------------------------- */
void FUN_0801a7b4(void)

{
  uint uVar1;
  
  uVar1 = FUN_0800b8ae(4,4,0x20000668);
  DAT_20000069 = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(0xc,4,0x20000668);
  DAT_2000006a = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(0,4,0x20000668);
  DAT_2000006b = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(8,4,0x20000668);
  DAT_2000006c = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(0x14,4,0x20000668);
  DAT_2000006d = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(0x18,4,0x20000668);
  DAT_2000006e = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(0x1c,4,0x20000668);
  DAT_2000006f = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(0x10,4,0x20000668);
  DAT_20000070 = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(0x24,4,0x20000668);
  DAT_20000071 = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(0x20,4,0x20000668);
  DAT_20000072 = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(0x2c,4,0x20000668);
  DAT_20000073 = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(0x28,4,0x20000668);
  DAT_20000074 = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(0x34,4,0x20000668);
  DAT_20000075 = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(0x30,4,0x20000668);
  DAT_20000076 = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(0x3c,4,0x20000668);
  DAT_20000077 = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(0x38,4,0x20000668);
  DAT_20000078 = (char)uVar1;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801a936   (0x0801A936, 121 Bytes)
 * Body: 0x0801A936-0x0801A9AF
 * --------------------------------------------------------------------- */
void FUN_0801a936(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = FUN_0800b8ae(0,8,0x20000660);
  uVar2 = FUN_0800b8ae(8,8,0x20000660);
  FUN_0800b8ae(0x10,8,0x20000660);
  FUN_0800b8ae(0x18,8,0x20000660);
  uVar3 = FUN_0800b8ae(0x38,0x20,0x20000660);
  DAT_2000036b = (char)uVar1;
  DAT_2000036c = (char)uVar2;
  DAT_20000377 = (char)(uVar3 >> 0x18);
  DAT_20000378 = (char)(uVar3 >> 0x10);
  DAT_20000379 = (char)(uVar3 >> 8);
  DAT_2000037a = (char)uVar3;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801aa58   (0x0801AA58, 115 Bytes)
 * Body: 0x0801AA58-0x0801AACB
 * --------------------------------------------------------------------- */
void FUN_0801aa58(void)

{
  uint uVar1;
  
  uVar1 = FUN_0800b8ae(0,8,0x20000650);
  DAT_20000020 = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(8,8,0x20000650);
  DAT_20000021 = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(0x10,8,0x20000650);
  DAT_20000022 = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(0x18,8,0x20000650);
  DAT_20000023 = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(0x20,8,0x20000650);
  DAT_20000028 = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(0x28,8,0x20000650);
  DAT_20000029 = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(0x30,8,0x20000650);
  DAT_2000002a = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(0x38,8,0x20000650);
  DAT_2000002b = (char)uVar1;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801aacc   (0x0801AACC, 165 Bytes)
 * Body: 0x0801AACC-0x0801AB71
 * --------------------------------------------------------------------- */
void FUN_0801aacc(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar1 = FUN_0800b8ae(0,4,0x20000648);
  uVar2 = FUN_0800b8ae(4,4,0x20000648);
  uVar3 = FUN_0800b8ae(0x10,0xd,0x20000648);
  uVar4 = FUN_0800b8ae(0x20,0xd,0x20000648);
  uVar5 = FUN_0800b8ae(0x30,8,0x20000648);
  FUN_0800b8ae(0x38,8,0x20000648);
  FUN_0800b8ae(8,1,0x20000648);
  DAT_20000372 = (char)uVar1 + '\x01';
  DAT_20000373 = (char)uVar2 + '\x01';
  DAT_20000369 = (char)((uVar3 & 0xffff) / 10);
  DAT_2000036a = (char)((uVar4 & 0xffff) / 10);
  if ((uVar5 & 0xff) == 3) {
    DAT_2000038f = 1;
  }
  else if ((uVar5 & 0xff) == 2) {
    DAT_2000038f = 2;
  }
  else {
    DAT_2000038f = 0;
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801ab72   (0x0801AB72, 91 Bytes)
 * Body: 0x0801AB72-0x0801ABCD
 * --------------------------------------------------------------------- */
void FUN_0801ab72(void)

{
  uint uVar1;
  
  FUN_0800b8ae(0,4,0x20000640);
  uVar1 = FUN_0800b8ae(4,4,0x20000640);
  DAT_2000036f = (undefined1)uVar1;
  FUN_0800b8ae(8,4,0x20000640);
  FUN_0800b8ae(0xc,4,0x20000640);
  FUN_0800b8ae(0x10,8,0x20000640);
  FUN_0800b8ae(0x18,8,0x20000640);
  FUN_0800b8ae(0x28,0xd,0x20000640);
  FUN_0800b8ae(0x38,0xd,0x20000640);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801abce   (0x0801ABCE, 81 Bytes)
 * Body: 0x0801ABCE-0x0801AC1F
 * --------------------------------------------------------------------- */
void FUN_0801abce(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = FUN_0800b8ae(0,8,0x20000638);
  FUN_0800b8ae(8,8,0x20000638);
  uVar2 = FUN_0800b8ae(0x18,8,0x20000638);
  uVar3 = FUN_0800b8ae(0x28,0x10,0x20000638);
  DAT_20000364 = (char)uVar1;
  DAT_20000365 = (char)uVar2;
  uVar1 = (uVar3 & 0xffff) / 10;
  DAT_20000375 = (char)(uVar1 >> 8);
  DAT_20000376 = (char)uVar1;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801ac20   (0x0801AC20, 115 Bytes)
 * Body: 0x0801AC20-0x0801AC93
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0801ac20(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = FUN_0800b8ae(8,0x10,0x20000630);
  uVar2 = FUN_0800b8ae(0x18,0x10,0x20000630);
  uVar3 = FUN_0800b8ae(0x28,0x10,0x20000630);
  _DAT_2000039c = (undefined2)uVar3;
  uVar3 = FUN_0800b8ae(0x30,8,0x20000630);
  uVar1 = (uVar1 & 0xffff) / 10 - 100 & 0xffff;
  DAT_2000035e = (char)(uVar1 >> 8);
  DAT_2000035f = (char)uVar1;
  uVar1 = (uVar2 & 0xffff) / 10 - 100 & 0xffff;
  DAT_20000360 = (char)(uVar1 >> 8);
  DAT_20000361 = (char)uVar1;
  DAT_20000362 = (char)((ushort)_DAT_2000039c >> 8);
  DAT_20000363 = DAT_2000039c;
  DAT_2000037b = (char)uVar3;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801ad64   (0x0801AD64, 151 Bytes)
 * Body: 0x0801AD64-0x0801ADFB
 * --------------------------------------------------------------------- */
void FUN_0801ad64(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = FUN_0800b8ae(7,1,0x20000628);
  DAT_20000081 = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(0x17,1,0x20000628);
  DAT_20000082 = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(0x27,1,0x20000628);
  DAT_20000083 = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(0x37,1,0x20000628);
  DAT_20000084 = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(8,0xd,0x20000628);
  uVar2 = FUN_0800b8ae(0x18,0xd,0x20000628);
  uVar3 = FUN_0800b8ae(0x28,0xd,0x20000628);
  uVar4 = FUN_0800b8ae(0x38,0xd,0x20000628);
  DAT_2000034e = (char)((uVar1 & 0xffff) >> 8);
  DAT_2000034f = (char)(uVar1 & 0xffff);
  DAT_20000350 = (char)((uVar2 & 0xffff) >> 8);
  DAT_20000351 = (char)(uVar2 & 0xffff);
  DAT_20000352 = (char)((uVar3 & 0xffff) >> 8);
  DAT_20000353 = (char)(uVar3 & 0xffff);
  DAT_20000354 = (char)((uVar4 & 0xffff) >> 8);
  DAT_20000355 = (char)(uVar4 & 0xffff);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801adfc   (0x0801ADFC, 151 Bytes)
 * Body: 0x0801ADFC-0x0801AE93
 * --------------------------------------------------------------------- */
void FUN_0801adfc(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = FUN_0800b8ae(7,1,0x20000620);
  DAT_2000007d = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(0x17,1,0x20000620);
  DAT_2000007e = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(0x27,1,0x20000620);
  DAT_2000007f = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(0x37,1,0x20000620);
  DAT_20000080 = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(8,0xd,0x20000620);
  uVar2 = FUN_0800b8ae(0x18,0xd,0x20000620);
  uVar3 = FUN_0800b8ae(0x28,0xd,0x20000620);
  uVar4 = FUN_0800b8ae(0x38,0xd,0x20000620);
  DAT_20000346 = (char)((uVar1 & 0xffff) >> 8);
  DAT_20000347 = (char)(uVar1 & 0xffff);
  DAT_20000348 = (char)((uVar2 & 0xffff) >> 8);
  DAT_20000349 = (char)(uVar2 & 0xffff);
  DAT_2000034a = (char)((uVar3 & 0xffff) >> 8);
  DAT_2000034b = (char)(uVar3 & 0xffff);
  DAT_2000034c = (char)((uVar4 & 0xffff) >> 8);
  DAT_2000034d = (char)(uVar4 & 0xffff);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801ae94   (0x0801AE94, 151 Bytes)
 * Body: 0x0801AE94-0x0801AF2B
 * --------------------------------------------------------------------- */
void FUN_0801ae94(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = FUN_0800b8ae(7,1,0x20000618);
  DAT_20000079 = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(0x17,1,0x20000618);
  DAT_2000007a = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(0x27,1,0x20000618);
  DAT_2000007b = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(0x37,1,0x20000618);
  DAT_2000007c = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(8,0xd,0x20000618);
  uVar2 = FUN_0800b8ae(0x18,0xd,0x20000618);
  uVar3 = FUN_0800b8ae(0x28,0xd,0x20000618);
  uVar4 = FUN_0800b8ae(0x38,0xd,0x20000618);
  DAT_2000033e = (char)((uVar1 & 0xffff) >> 8);
  DAT_2000033f = (char)(uVar1 & 0xffff);
  DAT_20000340 = (char)((uVar2 & 0xffff) >> 8);
  DAT_20000341 = (char)(uVar2 & 0xffff);
  DAT_20000342 = (char)((uVar3 & 0xffff) >> 8);
  DAT_20000343 = (char)(uVar3 & 0xffff);
  DAT_20000344 = (char)((uVar4 & 0xffff) >> 8);
  DAT_20000345 = (char)(uVar4 & 0xffff);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801af2c   (0x0801AF2C, 151 Bytes)
 * Body: 0x0801AF2C-0x0801AFC3
 * --------------------------------------------------------------------- */
void FUN_0801af2c(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = FUN_0800b8ae(7,1,0x20000610);
  DAT_20000075 = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(0x17,1,0x20000610);
  DAT_20000076 = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(0x27,1,0x20000610);
  DAT_20000077 = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(0x37,1,0x20000610);
  DAT_20000078 = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(8,0xd,0x20000610);
  uVar2 = FUN_0800b8ae(0x18,0xd,0x20000610);
  uVar3 = FUN_0800b8ae(0x28,0xd,0x20000610);
  uVar4 = FUN_0800b8ae(0x38,0xd,0x20000610);
  DAT_20000336 = (char)((uVar1 & 0xffff) >> 8);
  DAT_20000337 = (char)(uVar1 & 0xffff);
  DAT_20000338 = (char)((uVar2 & 0xffff) >> 8);
  DAT_20000339 = (char)(uVar2 & 0xffff);
  DAT_2000033a = (char)((uVar3 & 0xffff) >> 8);
  DAT_2000033b = (char)(uVar3 & 0xffff);
  DAT_2000033c = (char)((uVar4 & 0xffff) >> 8);
  DAT_2000033d = (char)(uVar4 & 0xffff);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801afc4   (0x0801AFC4, 151 Bytes)
 * Body: 0x0801AFC4-0x0801B05B
 * --------------------------------------------------------------------- */
void FUN_0801afc4(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = FUN_0800b8ae(7,1,0x20000608);
  DAT_20000071 = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(0x17,1,0x20000608);
  DAT_20000072 = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(0x27,1,0x20000608);
  DAT_20000073 = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(0x37,1,0x20000608);
  DAT_20000074 = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(8,0xd,0x20000608);
  uVar2 = FUN_0800b8ae(0x18,0xd,0x20000608);
  uVar3 = FUN_0800b8ae(0x28,0xd,0x20000608);
  uVar4 = FUN_0800b8ae(0x38,0xd,0x20000608);
  DAT_2000032e = (char)((uVar1 & 0xffff) >> 8);
  DAT_2000032f = (char)(uVar1 & 0xffff);
  DAT_20000330 = (char)((uVar2 & 0xffff) >> 8);
  DAT_20000331 = (char)(uVar2 & 0xffff);
  DAT_20000332 = (char)((uVar3 & 0xffff) >> 8);
  DAT_20000333 = (char)(uVar3 & 0xffff);
  DAT_20000334 = (char)((uVar4 & 0xffff) >> 8);
  DAT_20000335 = (char)(uVar4 & 0xffff);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801b05c   (0x0801B05C, 85 Bytes)
 * Body: 0x0801B05C-0x0801B0B1
 * --------------------------------------------------------------------- */
void FUN_0801b05c(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = FUN_0800b8ae(8,0xd,0x20000600);
  uVar2 = FUN_0800b8ae(0x18,0xd,0x20000600);
  uVar3 = FUN_0800b8ae(0x28,0xd,0x20000600);
  FUN_0800b8ae(0x38,0xd,0x20000600);
  DAT_20000366 = (char)((uVar1 & 0xffff) / 10);
  DAT_20000367 = (char)((uVar2 & 0xffff) / 10);
  DAT_20000368 = (char)((uVar3 & 0xff) / 10);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801b0b2   (0x0801B0B2, 75 Bytes)
 * Body: 0x0801B0B2-0x0801B0FD
 * --------------------------------------------------------------------- */
void FUN_0801b0b2(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = FUN_0800b8ae(8,0xd,0x200005f8);
  uVar2 = FUN_0800b8ae(0x18,0xd,0x200005f8);
  FUN_0800b8ae(0x24,4,0x200005f8);
  FUN_0800b8ae(0x20,4,0x200005f8);
  DAT_2000036d = (char)((uVar1 & 0xffff) / 10);
  DAT_2000036e = (char)((uVar2 & 0xffff) / 10);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801b0fe   (0x0801B0FE, 75 Bytes)
 * Body: 0x0801B0FE-0x0801B149
 * --------------------------------------------------------------------- */
void FUN_0801b0fe(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = FUN_0800b8ae(8,0xd,0x200005f0);
  uVar2 = FUN_0800b8ae(0x18,0xd,0x200005f0);
  FUN_0800b8ae(0x24,4,0x200005f0);
  FUN_0800b8ae(0x20,4,0x200005f0);
  DAT_2000037c = (char)((uVar1 & 0xffff) >> 8);
  DAT_2000037d = (char)(uVar1 & 0xffff);
  DAT_2000037e = (char)((uVar2 & 0xffff) >> 8);
  DAT_2000037f = (char)(uVar2 & 0xffff);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801b280   (0x0801B280, 197 Bytes)
 * Body: 0x0801B280-0x0801B345
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0801b280(void)

{
  uint uVar1;
  
  uVar1 = FUN_0800b8ae(0,4,0x200005e8);
  DAT_20000385 = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(8,4,0x200005e8);
  DAT_20000387 = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(0x10,4,0x200005e8);
  DAT_20000388 = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(0x14,4,0x200005e8);
  DAT_20000389 = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(0x18,4,0x200005e8);
  DAT_20000383 = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(0x1c,4,0x200005e8);
  DAT_20000382 = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(0x20,4,0x200005e8);
  DAT_20000381 = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(0x24,4,0x200005e8);
  DAT_20000380 = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(0x28,4,0x200005e8);
  DAT_2000038b = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(0x2c,4,0x200005e8);
  DAT_2000038a = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(0x30,4,0x200005e8);
  DAT_2000038e = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(0x34,4,0x200005e8);
  DAT_2000038d = (undefined1)uVar1;
  uVar1 = FUN_0800b8ae(0x38,4,0x200005e8);
  DAT_2000038c = (char)uVar1;
  _DAT_2000005c = 10;
  DAT_20000064 = 1;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801b346   (0x0801B346, 1238 Bytes, 2 Teile)
 * Body: 0x0801B346-0x0801B67B, 0x0801B720-0x0801B8C1
 * --------------------------------------------------------------------- */
void FUN_0801b346(void)

{
  DAT_200025f0 = 1;
  DAT_200025f1 = 1;
  DAT_200025f2 = 1;
  DAT_200025f3 = 1;
  DAT_200025f4 = 1;
  DAT_200025f5 = 1;
  DAT_200025f6 = 1;
  DAT_200025f7 = 1;
  DAT_200025f8 = 1;
  DAT_200025f9 = 1;
  DAT_200025fa = 1;
  DAT_200025fb = 1;
  DAT_200025fc = 1;
  DAT_200025fd = 1;
  DAT_200025fe = 1;
  DAT_200025ff = 1;
  DAT_20002600 = 1;
  DAT_20002601 = 1;
  DAT_20002603 = 1;
  DAT_20002604 = 1;
  DAT_20002605 = 1;
  FUN_08019f60(0,0x300,0,8,100,0x200005e8,0,0x801b281,0);
  FUN_08019f60(1,800,0,8,100,0x200005f0,0,0x801b0ff,0);
  FUN_08019f60(2,0x321,0,8,100,0x200005f8,0,0x801b0b3,0);
  FUN_08019f60(3,0x310,0,8,100,0x20000600,0,0x801b05d,0);
  FUN_08019f60(4,0x308,0,8,100,0x20000608,0,0x801afc5,0);
  FUN_08019f60(5,0x309,0,8,100,0x20000610,0,0x801af2d,0);
  FUN_08019f60(6,0x30a,0,8,100,0x20000618,0,0x801ae95,0);
  FUN_08019f60(7,0x30b,0,8,100,0x20000620,0,0x801adfd,0);
  FUN_08019f60(8,0x30c,0,8,100,0x20000628,0,0x801ad65,0);
  FUN_08019f60(9,0x328,0,8,100,0x20000630,0,0x801ac21,0);
  FUN_08019f60(10,0x329,0,8,100,0x20000638,0,0x801abcf,0);
  FUN_08019f60(0xb,0x32a,0,8,100,0x20000640,0,0x801ab73,0);
  FUN_08019f60(0xc,0x32b,0,8,100,0x20000648,0,0x801aacd,0);
  FUN_08019f60(0xd,0x34f,0,8,100,0x20000650,0,0x801aa59,0);
  FUN_08019f60(0xe,0x34e,0,8,100,&DAT_20000658,0,&LAB_0801a9b0_1,0);
  FUN_08019f60(0xf,0x350,0,8,100,0x20000660,0,0x801a937,0);
  FUN_08019f60(0x10,0x351,0,8,100,0x20000668,0,0x801a7b5,0);
  FUN_08019f60(0x11,0x540,0,8,100,&DAT_20000670,0,0x801a6c9,0);
  FUN_08019f60(0x13,0x710,0,8,100,&DAT_20000680,0,0x801a6a1,0);
  FUN_08019f60(0x12,0x502,0,8,100,&DAT_20000678,0,0x801a645,0);
  FUN_08019f60(0x14,0x6e0,0,8,100,&DAT_20000688,0,&LAB_0801a5ec_1,0);
  FUN_08019f60(0x15,0x680,0,8,100,&DAT_20000690,0,&LAB_0801a59c_1,0);
  DAT_20002606 = 1;
  DAT_20002607 = 1;
  DAT_20002608 = 1;
  DAT_20002609 = 1;
  DAT_2000260a = 1;
  DAT_2000260b = 1;
  DAT_2000260c = 1;
  DAT_2000260d = 1;
  DAT_2000260e = 1;
  DAT_2000260f = 1;
  DAT_20002610 = 1;
  DAT_20002611 = 1;
  FUN_08019ff0(0,0x3ee,0,8,0xfa,&DAT_20000588,1,0x801a4f5,0);
  FUN_08019ff0(1,0x3ef,0,8,1000,&DAT_20000590,1,0x801a4b5,0);
  FUN_08019ff0(2,0x380,0,8,100,0x20000598,1,0x801a34b,0);
  FUN_08019ff0(3,0x381,0,8,200,0x200005a0,1,0x801a2dd,0);
  FUN_08019ff0(4,900,0,8,100,0x200005a8,1,0x801a27b,0);
  FUN_08019ff0(5,0x385,0,8,200,0x200005b0,1,0x801a21b,0);
  FUN_08019ff0(6,0x390,0,8,200,0x200005b8,1,0x801a1a9,0);
  FUN_08019ff0(7,0x388,0,8,200,0x200005c0,1,&LAB_0801a17e_1,0);
  FUN_08019ff0(8,0x389,0,8,200,0x200005c8,1,&LAB_0801a154_1,0);
  FUN_08019ff0(9,0x4ed,0,8,1000,&DAT_200005d0,1,&LAB_0801a114_1,0);
  FUN_08019ff0(10,0x4ee,0,8,1000,&DAT_200005d8,1,&LAB_0801a0d4_1,0);
  FUN_08019ff0(0xb,0x4ff,0,8,1000,&DAT_200005e0,1,&LAB_0801a0a6_1,0);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801b8c4   (0x0801B8C4, 67 Bytes)
 * Body: 0x0801B8C4-0x0801B907
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0801b8c4(void)

{
  if (((DAT_2000008b == '\x01') && (_DAT_200002fc < 4)) && (DAT_2000004c != '\0')) {
    _DAT_2000069c = _DAT_2000069c + 1;
    if (0x32 < _DAT_2000069c) {
      DAT_2000008b = '\x02';
      DAT_2000008c = 2;
    }
  }
  else {
    DAT_2000008b = '\0';
    DAT_2000008c = 0;
    _DAT_2000069c = 0;
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801b97c   (0x0801B97C, 39 Bytes)
 * Body: 0x0801B97C-0x0801B9A3
 * --------------------------------------------------------------------- */
void FUN_0801b97c(void)

{
  byte local_8 [4];
  
  FUN_08007458(0x600);
  local_8[0] = 0x36;
  local_8[1] = 0;
  local_8[2] = 0;
  local_8[3] = 1;
  FUN_08007462(local_8);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801b9a4   (0x0801B9A4, 63 Bytes)
 * Body: 0x0801B9A4-0x0801B9E3
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_0801b9a4(void)

{
  undefined4 in_r3;
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  undefined2 local_12;
  undefined4 local_10;
  undefined2 local_c;
  undefined2 uStack_a;
  
  local_18 = 0;
  local_16 = 0;
  local_14 = 0;
  local_12 = 0;
  local_10 = 0;
  _local_c = CONCAT22((short)((uint)in_r3 >> 0x10),0x101);
  FUN_0800a6a8(&local_18);
  FUN_0800ac86(_FUN_0801bdc4,2,1);
  return CONCAT26(local_12,CONCAT24(local_14,CONCAT22(local_16,local_18)));
}


/* ---------------------------------------------------------------------
 * FUN_0801b9e4   (0x0801B9E4, 105 Bytes)
 * Body: 0x0801B9E4-0x0801BA4D
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0801b9e4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_10 = param_2;
  local_c = param_3;
  local_8 = param_4;
  FUN_08007f40(0x2000000,1);
  FUN_0800a57c();
  FUN_0800a7aa((undefined2 *)&local_10);
  local_8 = 0x1000000;
  local_c = 0x30c;
  local_10 = 6;
  FUN_0800a594(_FUN_0801bdc4,(ushort *)&local_10);
  FUN_0801b9a4();
  FUN_0801b97c();
  FUN_0800ac86((int)_FUN_0801bdc4,2,1);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801ba4e   (0x0801BA4E, 67 Bytes)
 * CAN-Init: Filterbaenke (32-Bit-Maskenmodus)
 * Body: 0x0801BA4E-0x0801BA91
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_0801ba4e(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_14 = param_2;
  local_10 = param_3;
  local_c = param_4;
  local_18 = param_1;
  FUN_0800795a((undefined2 *)&local_18);
  FUN_080081e4(9,1);
  local_18._0_2_ = 0x100;
  local_10 = 0;
  local_14 = CONCAT31(local_14._1_3_,1);
  local_c = 5;
  FUN_08007776(FUN_0801bdc4,(ushort *)&local_18);
  local_18._0_2_ = 0x200;
  local_10 = 2;
  FUN_08007776(FUN_0801bdc4,(ushort *)&local_18);
  return CONCAT44(local_14,CONCAT22(local_18._2_2_,(ushort)local_18));
}


/* ---------------------------------------------------------------------
 * FUN_0801ba92   (0x0801BA92, 35 Bytes)
 * CAN-Init Wrapper
 * Body: 0x0801BA92-0x0801BAB5
 * --------------------------------------------------------------------- */
void FUN_0801ba92(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 extraout_r2;
  undefined4 extraout_r3;
  undefined8 uVar1;
  
  FUN_0801ba4e(param_1,param_2,param_3,param_4);
  uVar1 = FUN_0801b346();
  FUN_0801b9e4((int)uVar1,(int)((ulonglong)uVar1 >> 0x20),extraout_r2,extraout_r3);
  DAT_20000064 = 1;
  DAT_20000066 = 0;
  DAT_20000067 = 0;
  DAT_20000068 = 0;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801bab6   (0x0801BAB6, 105 Bytes)
 * Body: 0x0801BAB6-0x0801BB1F
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0801bab6(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_10 = param_2;
  local_c = param_3;
  local_8 = param_4;
  FUN_08007f40(0x2000000,1);
  FUN_0800a57c();
  FUN_0800a7aa((undefined2 *)&local_10);
  local_8 = 0x1000000;
  local_c = 0x30c;
  local_10 = 0x10006;
  FUN_0800a594(_FUN_0801bdc4,(ushort *)&local_10);
  FUN_0801b9a4();
  FUN_0801b97c();
  FUN_0800ac86((int)_FUN_0801bdc4,2,1);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801bb20   (0x0801BB20, 15 Bytes)
 * Body: 0x0801BB20-0x0801BB2F
 * --------------------------------------------------------------------- */
void FUN_0801bb20(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 extraout_r2;
  undefined4 extraout_r3;
  undefined8 uVar1;
  
  FUN_0801ba4e(param_1,param_2,param_3,param_4);
  uVar1 = FUN_0801b346();
  FUN_0801bab6((int)uVar1,(int)((ulonglong)uVar1 >> 0x20),extraout_r2,extraout_r3);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801bb30   (0x0801BB30, 329 Bytes)
 * Body: 0x0801BB30-0x0801BC79
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0801bb30(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  char cVar1;
  short sVar2;
  int iVar3;
  int extraout_r1;
  int extraout_r2;
  int iVar4;
  undefined4 extraout_r3;
  undefined4 uVar5;
  uint uVar6;
  undefined4 local_38;
  undefined4 local_34;
  undefined1 local_30;
  undefined1 local_2f;
  undefined1 local_2e;
  undefined1 local_2d [9];
  
  iVar3 = param_2;
  iVar4 = param_3;
  uVar5 = param_4;
  if (0x13 < _DAT_20000392) {
    FUN_0801b9e4((uint)_DAT_20000392,param_2,param_3,param_4);
    FUN_0800ab40(0x40006400,0);
    FUN_0800ab40(0x40006400,1);
    FUN_0800aa06(0x40006400,0);
    FUN_0800aa06(0x40006400,1);
    FUN_0800aa06(0x40006400,2);
    FUN_0800ad10(0x40006400,0x30f00070);
    iVar3 = extraout_r1;
    iVar4 = extraout_r2;
    uVar5 = extraout_r3;
  }
  if (0x31 < _DAT_20000394) {
    FUN_0801b9e4((uint)_DAT_20000394,iVar3,iVar4,uVar5);
    FUN_0800ab40(0x40006400,0);
    FUN_0800ab40(0x40006400,1);
    FUN_0800aa06(0x40006400,0);
    FUN_0800aa06(0x40006400,1);
    FUN_0800aa06(0x40006400,2);
    FUN_0800ad10(0x40006400,0x30f00070);
  }
  if (param_2 == 1) {
    local_30 = 4;
    local_34 = param_1;
  }
  else {
    local_30 = 0;
    local_38 = param_1;
  }
  local_2e = (undefined1)param_4;
  local_2f = 0;
  for (uVar6 = 0; uVar6 < 8; uVar6 = uVar6 + 1 & 0xff) {
    local_2d[uVar6] = *(undefined1 *)(param_3 + uVar6);
  }
  iVar3 = FUN_0800a856(0x40006400,(ushort *)&local_38);
  sVar2 = 0xfff;
  while( true ) {
    cVar1 = FUN_0800a97c(0x40006400,iVar3);
    if (cVar1 == '\x01') {
      _DAT_20000392 = 0;
      _DAT_20000394 = 0;
      return 0;
    }
    if (cVar1 == '\0') break;
    sVar2 = sVar2 + -1;
    if (sVar2 == 0) {
      _DAT_20000394 = _DAT_20000394 + 1;
      if (299 < _DAT_20000394) {
        _DAT_20000394 = 300;
      }
      return 0;
    }
  }
  if ((ushort)(_DAT_20000392 + 1) < 300) {
    _DAT_20000392 = _DAT_20000392 + 1;
    return 0;
  }
  _DAT_20000392 = 300;
  return 0;
}


/* ---------------------------------------------------------------------
 * FUN_0801bc7a   (0x0801BC7A, 215 Bytes)
 * Body: 0x0801BC7A-0x0801BD51
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0801bc7a(void)

{
  undefined2 uVar1;
  uint uVar2;
  int iVar3;
  
  FUN_08016a6a(_DAT_20002614,&DAT_2000261f);
  uVar2 = 0;
  while( true ) {
    if (0x15 < uVar2) {
      return;
    }
    iVar3 = _DAT_20002618;
    if (DAT_2000261c == '\0') {
      iVar3 = _DAT_20002614;
    }
    if (*(int *)(uVar2 * 0x20 + 0x200021e0) == iVar3) break;
    uVar2 = uVar2 + 1;
  }
  *(undefined1 *)(uVar2 * 0x20 + 0x200021ec) = DAT_2000261e;
  **(undefined1 **)(uVar2 * 0x20 + 0x200021e8) = DAT_2000261f;
  *(undefined1 *)(*(int *)(uVar2 * 0x20 + 0x200021e8) + 1) = DAT_20002620;
  *(undefined1 *)(*(int *)(uVar2 * 0x20 + 0x200021e8) + 2) = DAT_20002621;
  *(undefined1 *)(*(int *)(uVar2 * 0x20 + 0x200021e8) + 3) = DAT_20002622;
  *(undefined1 *)(*(int *)(uVar2 * 0x20 + 0x200021e8) + 4) = DAT_20002623;
  *(undefined1 *)(*(int *)(uVar2 * 0x20 + 0x200021e8) + 5) = DAT_20002624;
  *(undefined1 *)(*(int *)(uVar2 * 0x20 + 0x200021e8) + 6) = DAT_20002625;
  *(undefined1 *)(*(int *)(uVar2 * 0x20 + 0x200021e8) + 7) = DAT_20002626;
  uVar1 = FUN_08019152();
  *(undefined2 *)(uVar2 * 0x20 + 0x200021f4) = uVar1;
  if (*(int *)(uVar2 * 0x20 + 0x200021f8) == 0) {
    return;
  }
  (**(code **)(uVar2 * 0x20 + 0x200021f8))();
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801bd52   (0x0801BD52, 17 Bytes)
 * Body: 0x0801BD52-0x0801BD63
 * --------------------------------------------------------------------- */
void FUN_0801bd52(void)

{
  FUN_0800aa36(0x40006400,0,(uint *)&DAT_20002614);
  FUN_0801bc7a();
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801bd64   (0x0801BD64, 33 Bytes)
 * Body: 0x0801BD64-0x0801BD85
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0801bd64(void)

{
  disableIRQinterrupts();
  if (_DAT_2000005c == 0) {
    _DAT_2000005c = 0;
    DAT_20000064 = 0;
  }
  else {
    _DAT_2000005c = _DAT_2000005c + -1;
  }
  enableIRQinterrupts();
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801bd86   (0x0801BD86, 7 Bytes)
 * Body: 0x0801BD86-0x0801BD8D
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0801bd86(void)

{
  _DAT_20000060 = 1;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801bd8e   (0x0801BD8E, 7 Bytes)
 * Body: 0x0801BD8E-0x0801BD95
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0801bd8e(void)

{
  _DAT_20000060 = 0;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801bd96   (0x0801BD96, 43 Bytes)
 * Body: 0x0801BD96-0x0801BDC1
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0801bd96(void)

{
  if (((_DAT_20000060 != 0) || (DAT_20000065 != '\0')) &&
     (_DAT_20000060 = _DAT_20000060 + 1, 0x3c < _DAT_20000060)) {
    FUN_0801bd8e();
    DAT_20000065 = '\0';
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801bdc4   (0x0801BDC4, 205 Bytes)
 * CAN-Filterkonfiguration (Beispielmasken 0x04030201/0x08070605, ID 0x12345678)
 * Body: 0x0801BDC4-0x0801BE91
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0801bdc4(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  char cVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 local_40;
  undefined4 uStack_3c;
  ushort local_38 [4];
  undefined1 local_30;
  undefined1 local_2f;
  undefined1 local_2e;
  undefined1 local_2d [13];
  undefined4 local_20;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  undefined1 local_19 [9];
  int iStack_10;
  int iStack_c;
  undefined4 uStack_8;
  
  *(int *)(param_1 + 0x40) = param_1;
  uStack_8 = 0x14;
  iStack_c = param_4 << 2;
  iStack_10 = param_4 << 1;
  sVar2 = -1;
  local_40 = 0x4030201;
  uStack_3c = 0x8070605;
  local_48 = 0x5060708;
  uStack_44 = 0x1020304;
  local_38[0] = 0x400;
  local_38[1] = 0;
  local_30 = 0;
  local_2f = 0;
  local_2e = 8;
  for (uVar4 = 0; uVar4 < 8; uVar4 = uVar4 + 1 & 0xff) {
    local_2d[uVar4] = *(undefined1 *)((int)&local_40 + uVar4);
  }
  local_20 = 0x12345678;
  local_1c = 4;
  local_1b = 0;
  local_1a = 8;
  for (uVar4 = 0; uVar4 < 8; uVar4 = uVar4 + 1 & 0xff) {
    local_19[uVar4] = *(undefined1 *)((int)&local_48 + uVar4);
  }
  iVar3 = FUN_0800a856(_FUN_0801c1f8,local_38);
  for (; (cVar1 = FUN_0800a97c(_FUN_0801c1f8,iVar3), cVar1 != '\x01' && (sVar2 != 0));
      sVar2 = sVar2 + -1) {
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801bdfc   (0x0801BDFC, 149 Bytes)
 * Body: 0x0801BDFC-0x0801BE91
 * --------------------------------------------------------------------- */
void FUN_0801bdfc(void)

{
  char cVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 local_40;
  undefined4 uStack_3c;
  ushort local_38 [4];
  undefined1 local_30;
  undefined1 local_2f;
  undefined1 local_2e;
  undefined1 local_2d [13];
  undefined4 local_20;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  undefined1 local_19 [9];
  
  sVar2 = -1;
  local_40 = 0x4030201;
  uStack_3c = 0x8070605;
  local_48 = 0x5060708;
  uStack_44 = 0x1020304;
  local_38[0] = 0x400;
  local_38[1] = 0;
  local_30 = 0;
  local_2f = 0;
  local_2e = 8;
  for (uVar4 = 0; uVar4 < 8; uVar4 = uVar4 + 1 & 0xff) {
    local_2d[uVar4] = *(undefined1 *)((int)&local_40 + uVar4);
  }
  local_20 = 0x12345678;
  local_1c = 4;
  local_1b = 0;
  local_1a = 8;
  for (uVar4 = 0; uVar4 < 8; uVar4 = uVar4 + 1 & 0xff) {
    local_19[uVar4] = *(undefined1 *)((int)&local_48 + uVar4);
  }
  iVar3 = FUN_0800a856(0x40006400,local_38);
  for (; (cVar1 = FUN_0800a97c(0x40006400,iVar3), cVar1 != '\x01' && (sVar2 != 0));
      sVar2 = sVar2 + -1) {
  }
  return;
}



/* =====================================================================
 *  SEKTION: 0x0801BE00 - Mainloop-Scheduler & Anwendungslogik
 * ===================================================================== */

/* ---------------------------------------------------------------------
 * FUN_0801be92   (0x0801BE92, 429 Bytes)
 * Body: 0x0801BE92-0x0801C03F
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0801be92(undefined4 param_1,int param_2)

{
  uint uVar1;
  
  if (DAT_200002c7 == '0') {
    DAT_2000037b = 0xd;
  }
  else if (DAT_200002c7 == '4') {
    DAT_2000037b = 0xe;
  }
  else if (DAT_200002c7 == '<') {
    DAT_2000037b = 0x10;
  }
  else if (DAT_200002c7 == 'H') {
    DAT_2000037b = 0x14;
  }
  else {
    DAT_2000037b = 0x14;
  }
  uVar1 = (param_2 * 100 + 600U) / (uint)DAT_2000037b & 0xffff;
  if (uVar1 < 0x1195) {
    if (uVar1 < 0x1069) {
      _DAT_20000048 = _DAT_20000044 + 600;
    }
    else {
      _DAT_20000048 = (short)(ushort)DAT_2000037b * 0x1068;
    }
  }
  else {
    _DAT_20000048 = _DAT_20000044 + 400;
  }
  uVar1 = _DAT_20000048 / 100;
  DAT_2000035e = (undefined1)(uVar1 >> 8);
  DAT_2000035f = (char)uVar1;
  DAT_20000360 = DAT_2000035e;
  DAT_20000361 = (char)uVar1;
  uVar1 = (uVar1 * 100) / (uint)DAT_2000037b & 0xffff;
  DAT_2000037c = (undefined1)(uVar1 >> 8);
  DAT_2000037d = (undefined1)uVar1;
  DAT_2000037e = DAT_2000037c;
  DAT_2000037f = DAT_2000037d;
  DAT_2000032e = DAT_2000037c;
  DAT_2000032f = DAT_2000037d;
  DAT_20000330 = DAT_2000037c;
  DAT_20000331 = DAT_2000037d;
  DAT_20000332 = DAT_2000037c;
  DAT_20000333 = DAT_2000037d;
  DAT_20000334 = DAT_2000037c;
  DAT_20000335 = DAT_2000037d;
  DAT_20000336 = DAT_2000037c;
  DAT_20000337 = DAT_2000037d;
  DAT_20000338 = DAT_2000037c;
  DAT_20000339 = DAT_2000037d;
  DAT_2000033a = DAT_2000037c;
  DAT_2000033b = DAT_2000037d;
  DAT_2000033c = DAT_2000037c;
  DAT_2000033d = DAT_2000037d;
  DAT_2000033e = DAT_2000037c;
  DAT_2000033f = DAT_2000037d;
  DAT_20000340 = DAT_2000037c;
  DAT_20000341 = DAT_2000037d;
  DAT_20000342 = DAT_2000037c;
  DAT_20000343 = DAT_2000037d;
  DAT_20000344 = DAT_2000037c;
  DAT_20000345 = DAT_2000037d;
  DAT_20000346 = DAT_2000037c;
  DAT_20000347 = DAT_2000037d;
  DAT_20000348 = DAT_2000037c;
  DAT_20000349 = DAT_2000037d;
  DAT_2000034a = DAT_2000037c;
  DAT_2000034b = DAT_2000037d;
  DAT_2000034c = DAT_2000037c;
  DAT_2000034d = DAT_2000037d;
  DAT_2000034e = DAT_2000037c;
  DAT_2000034f = DAT_2000037d;
  DAT_20000350 = DAT_2000037c;
  DAT_20000351 = DAT_2000037d;
  DAT_20000352 = DAT_2000037c;
  DAT_20000353 = DAT_2000037d;
  DAT_20000354 = DAT_2000037c;
  DAT_20000355 = DAT_2000037d;
  FUN_0801c1f8 = &DAT_200002c7;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801c040   (0x0801C040, 219 Bytes)
 * Body: 0x0801C040-0x0801C11B
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0801c040(void)

{
  if (DAT_20000311 == '\0') {
    _DAT_200006a4 = 0;
    if (DAT_200002e4 < 0x65) {
      if (DAT_200002e4 < 0x3d) {
        DAT_200006a0 = (byte)(((uint)DAT_200002e4 << 1) / 3);
      }
      else {
        DAT_200006a0 = (char)((int)(uint)DAT_200002e4 >> 1) + 10;
      }
    }
    else {
      DAT_200006a0 = 0x3d;
    }
  }
  else {
    _DAT_200006a4 = _DAT_200006a4 + 1;
    if ((300 < _DAT_200006a4) && (_DAT_200006a4 = 0, DAT_200006a0 != 0x19)) {
      if (DAT_200006a0 < 0x1a) {
        DAT_200006a0 = DAT_200006a0 + 1;
      }
      else {
        DAT_200006a0 = DAT_200006a0 - 1;
      }
    }
  }
  DAT_2000036d = DAT_200006a0 + 0x29;
  DAT_2000036e = DAT_200006a0 + 0x28;
  DAT_20000366 = DAT_2000036e;
  DAT_20000367 = DAT_2000036d;
  DAT_20000368 = (char)(((uint)DAT_2000036d + (uint)DAT_2000036e) * 0x800000 >> 0x18);
  DAT_20000369 = DAT_200006a0 + 0x2e;
  DAT_2000036a = DAT_200006a0 + 0x2f;
  DAT_2000036b = 0x42;
  DAT_2000036c = 0x42;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801c11c   (0x0801C11C, 69 Bytes)
 * Body: 0x0801C11C-0x0801C161
 * --------------------------------------------------------------------- */
void FUN_0801c11c(void)

{
  DAT_20000362 = 0x27;
  DAT_20000363 = 0x10;
  DAT_20000365 = 100;
  DAT_20000375 = 0;
  DAT_20000376 = 0x19;
  DAT_20000377 = 0;
  DAT_20000378 = 0;
  DAT_20000379 = 0;
  DAT_2000037a = 0xff;
  DAT_20000372 = 2;
  DAT_20000373 = 2;
  DAT_2000038f = 0;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801c162   (0x0801C162, 85 Bytes)
 * Body: 0x0801C162-0x0801C1B7
 * --------------------------------------------------------------------- */
uint FUN_0801c162(int param_1,int param_2,ushort *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = param_2 - 1U & 0xffff;
  if ((int)(uint)param_3[param_2 + -1] < param_1) {
    uVar1 = param_2 - 1U & 0xffff;
  }
  else {
    uVar2 = 0;
    if (param_1 < (int)(uint)*param_3) {
      uVar1 = 0;
    }
    else {
      while (uVar3 = uVar2, uVar3 + 1 < uVar1) {
        uVar2 = (uVar1 + uVar3 & 0x1ff) >> 1;
        if (param_1 < (int)(uint)param_3[uVar2]) {
          uVar1 = uVar2;
          uVar2 = uVar3;
        }
      }
    }
  }
  return uVar1;
}


/* ---------------------------------------------------------------------
 * FUN_0801c1b8   (0x0801C1B8, 43 Bytes)
 * Body: 0x0801C1B8-0x0801C1E3
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0801c1b8(void)

{
  byte bVar1;
  short sVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  
  iVar6 = 0;
  uVar4 = 0xff;
  if (_DAT_20000048 < 0x7531) {
    _DAT_200006ac = 0;
  }
  else {
    _DAT_200006ac = _DAT_200006ac + 1;
  }
  if ((DAT_200006a8 == '\0') && (5 < _DAT_200006ac)) {
    DAT_200006a8 = '\x01';
    for (uVar5 = 0; uVar5 < 10; uVar5 = uVar5 + 1 & 0xff) {
      *(short *)(uVar5 * 2 + 0x2000263c) = (short)(_DAT_20000048 / 100);
      DAT_200006a9 = (byte)(DAT_200006a9 + 1) % 10;
    }
    uVar5 = FUN_0801c162(_DAT_20000048 / DAT_2000037b & 0xffff,0x65,(ushort *)&DAT_0801dc78);
    DAT_20000364 = (byte)uVar5;
    _DAT_200006bc = (ushort)DAT_20000364;
  }
  else if (DAT_200006a8 == '\x01') {
    uVar5 = (uint)DAT_200006a9;
    DAT_200006a9 = DAT_200006a9 + 1;
    *(short *)(uVar5 * 2 + 0x2000263c) = (short)(_DAT_20000048 / 100);
    DAT_200006a9 = DAT_200006a9 % 10;
    uVar7 = 0;
    uVar8 = 1000;
    for (uVar5 = 0; uVar5 < 10; uVar5 = uVar5 + 1 & 0xff) {
      if (uVar7 < *(ushort *)(uVar5 * 2 + 0x2000263c)) {
        uVar7 = (uint)*(ushort *)(uVar5 * 2 + 0x2000263c);
      }
      if (*(ushort *)(uVar5 * 2 + 0x2000263c) < uVar8) {
        uVar8 = (uint)*(ushort *)(uVar5 * 2 + 0x2000263c);
      }
      iVar6 = iVar6 + (uint)*(ushort *)(uVar5 * 2 + 0x2000263c);
    }
    if ((int)(uVar7 - uVar8) < 0x33) {
      _DAT_200006aa = _DAT_200006aa + 1;
      if (5 < _DAT_200006aa) {
        _DAT_200006aa = 0;
        uVar4 = FUN_0801c162((uint)(ushort)(((ulonglong)(uint)(iVar6 * 100) / 10) /
                                           (ulonglong)DAT_2000037b),0x65,(ushort *)&DAT_0801dc78);
      }
    }
    else {
      _DAT_200006aa = 0;
    }
  }
  else {
    DAT_20000364 = 0;
  }
  bVar1 = (byte)uVar4;
  sVar2 = (short)uVar4;
  if (DAT_200006ae == '\0') {
    _DAT_200006b4 = _DAT_200006b4 + 1;
    if (18000 < _DAT_200006b4) {
      _DAT_200006b0 = 0;
      _DAT_200006b4 = 0;
      _DAT_200006b8 = 0;
      DAT_200006ae = '\x01';
    }
    if (_DAT_20000318 < 0xb) {
      _DAT_200006b0 = 0;
    }
    else {
      _DAT_200006b0 = _DAT_200006b0 + 1;
      if (300 < _DAT_200006b0) {
        _DAT_200006b0 = 0;
        _DAT_200006b4 = 0;
        _DAT_200006b8 = 0;
        DAT_200006ae = '\x01';
      }
    }
    if (_DAT_20000318 < 0x65) {
      _DAT_200006b8 = 0;
    }
    else {
      _DAT_200006b8 = _DAT_200006b8 + 1;
      if (0x32 < _DAT_200006b8) {
        _DAT_200006b0 = 0;
        _DAT_200006b4 = 0;
        _DAT_200006b8 = 0;
        DAT_200006ae = '\x01';
      }
    }
    if ((DAT_200006a8 != '\0') && (uVar4 != 0xff)) {
      if ((int)(uint)_DAT_200006bc < (int)uVar4) {
        uVar3 = sVar2 - _DAT_200006bc;
      }
      else {
        uVar3 = _DAT_200006bc - sVar2;
      }
      if (5 < uVar3) {
        _DAT_200006bc = (ushort)bVar1;
        DAT_20000364 = bVar1;
      }
    }
  }
  else {
    if (_DAT_20000318 < 10) {
      _DAT_200006b0 = _DAT_200006b0 + 1;
      if (0x708 < _DAT_200006b0) {
        _DAT_200006b0 = 0;
        _DAT_200006b4 = 0;
        _DAT_200006b8 = 0;
        DAT_200006ae = '\0';
      }
    }
    else {
      _DAT_200006b0 = 0;
    }
    if (uVar4 != 0xff) {
      if ((int)(uint)_DAT_200006bc < (int)uVar4) {
        uVar3 = sVar2 - _DAT_200006bc;
      }
      else {
        uVar3 = _DAT_200006bc - sVar2;
      }
      if ((int)uVar4 < 0x1f) {
        _DAT_200006bc = (ushort)bVar1;
        DAT_20000364 = bVar1;
      }
      else if (uVar3 < 4) {
        if (uVar3 != 0) {
          if ((int)(uint)_DAT_200006bc < (int)uVar4) {
            DAT_20000364 = DAT_20000364 + 1;
          }
          else {
            DAT_20000364 = DAT_20000364 - 1;
          }
          _DAT_200006bc = (ushort)DAT_20000364;
        }
      }
      else {
        _DAT_200006bc = (ushort)bVar1;
        DAT_20000364 = bVar1;
      }
    }
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801c1f8   (0x0801C1F8, 1003 Bytes)
 * Messwert-Filter (10-Sample-Ring, Ausreisserpruefung, Kennlinie @0x0801DC78)
 * Body: 0x0801C1F8-0x0801C5E3
 * --------------------------------------------------------------------- */
/* WARNING: Removing unreachable block (ram,0x0801c348) */
/* WARNING: Removing unreachable block (ram,0x0801c382) */
/* WARNING: Removing unreachable block (ram,0x0801c352) */
/* WARNING: Removing unreachable block (ram,0x0801c386) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0801c1f8(int param_1)

{
  byte bVar1;
  short sVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  
  *(int *)(param_1 + 0x40) = param_1;
  iVar6 = 0;
  uVar5 = 0;
  _DAT_200006ac = 0;
  if (DAT_200006a8 == '\x01') {
    uVar4 = (uint)DAT_200006a9;
    DAT_200006a9 = DAT_200006a9 + 1;
    *(short *)(uVar4 * 2 + 0x2000263c) = (short)(_DAT_20000048 / 100);
    DAT_200006a9 = DAT_200006a9 % 10;
    uVar7 = 0;
    uVar8 = 1000;
    for (uVar4 = 0; uVar4 < 10; uVar4 = uVar4 + 1 & 0xff) {
      if (uVar7 < *(ushort *)(uVar4 * 2 + 0x2000263c)) {
        uVar7 = (uint)*(ushort *)(uVar4 * 2 + 0x2000263c);
      }
      if (*(ushort *)(uVar4 * 2 + 0x2000263c) < uVar8) {
        uVar8 = (uint)*(ushort *)(uVar4 * 2 + 0x2000263c);
      }
      iVar6 = iVar6 + (uint)*(ushort *)(uVar4 * 2 + 0x2000263c);
    }
    if ((int)(uVar7 - uVar8) < 0x33) {
      _DAT_200006aa = _DAT_200006aa + 1;
      if (5 < _DAT_200006aa) {
        _DAT_200006aa = 0;
        uVar5 = FUN_0801c162((uint)(ushort)(((ulonglong)(uint)(iVar6 * 100) / 10) /
                                           (ulonglong)DAT_2000037b),0x65,(ushort *)&DAT_0801dc78);
      }
    }
    else {
      _DAT_200006aa = 0;
    }
  }
  else {
    DAT_20000364 = 0;
  }
  bVar1 = (byte)uVar5;
  sVar2 = (short)uVar5;
  if (DAT_200006ae == '\0') {
    _DAT_200006b4 = _DAT_200006b4 + 1;
    if (18000 < _DAT_200006b4) {
      _DAT_200006b0 = 0;
      _DAT_200006b4 = 0;
      _DAT_200006b8 = 0;
      DAT_200006ae = '\x01';
    }
    if (_DAT_20000318 < 0xb) {
      _DAT_200006b0 = 0;
    }
    else {
      _DAT_200006b0 = _DAT_200006b0 + 1;
      if (300 < _DAT_200006b0) {
        _DAT_200006b0 = 0;
        _DAT_200006b4 = 0;
        _DAT_200006b8 = 0;
        DAT_200006ae = '\x01';
      }
    }
    if (_DAT_20000318 < 0x65) {
      _DAT_200006b8 = 0;
    }
    else {
      _DAT_200006b8 = _DAT_200006b8 + 1;
      if (0x32 < _DAT_200006b8) {
        _DAT_200006b0 = 0;
        _DAT_200006b4 = 0;
        _DAT_200006b8 = 0;
        DAT_200006ae = '\x01';
      }
    }
    if ((DAT_200006a8 != '\0') && (uVar5 != 0xff)) {
      if ((int)(uint)_DAT_200006bc < (int)uVar5) {
        uVar3 = sVar2 - _DAT_200006bc;
      }
      else {
        uVar3 = _DAT_200006bc - sVar2;
      }
      if (5 < uVar3) {
        _DAT_200006bc = (ushort)bVar1;
        DAT_20000364 = bVar1;
      }
    }
  }
  else {
    if (_DAT_20000318 < 10) {
      _DAT_200006b0 = _DAT_200006b0 + 1;
      if (0x708 < _DAT_200006b0) {
        _DAT_200006b0 = 0;
        _DAT_200006b4 = 0;
        _DAT_200006b8 = 0;
        DAT_200006ae = '\0';
      }
    }
    else {
      _DAT_200006b0 = 0;
    }
    if (uVar5 != 0xff) {
      if ((int)(uint)_DAT_200006bc < (int)uVar5) {
        uVar3 = sVar2 - _DAT_200006bc;
      }
      else {
        uVar3 = _DAT_200006bc - sVar2;
      }
      if ((int)uVar5 < 0x1f) {
        _DAT_200006bc = (ushort)bVar1;
        DAT_20000364 = bVar1;
      }
      else if (uVar3 < 4) {
        if (uVar3 != 0) {
          if ((int)(uint)_DAT_200006bc < (int)uVar5) {
            DAT_20000364 = DAT_20000364 + 1;
          }
          else {
            DAT_20000364 = DAT_20000364 - 1;
          }
          _DAT_200006bc = (ushort)DAT_20000364;
        }
      }
      else {
        _DAT_200006bc = (ushort)bVar1;
        DAT_20000364 = bVar1;
      }
    }
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801c5e4   (0x0801C5E4, 25 Bytes)
 * Body: 0x0801C5E4-0x0801C5FD
 * --------------------------------------------------------------------- */
void FUN_0801c5e4(undefined4 param_1,int param_2)

{
  if (DAT_20000064 == '\0') {
    FUN_0801be92(0,param_2);
    FUN_0801c040();
    FUN_0801c1b8();
    FUN_0801c11c();
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801c640   (0x0801C640, 5 Bytes)
 * Init-Phasensteuerung (1/3/5)
 * Body: 0x0801C640-0x0801C645
 * --------------------------------------------------------------------- */
void FUN_0801c640(undefined1 param_1)

{
  DAT_200006fd = param_1;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801c700   (0x0801C700, 1170 Bytes, 2 Teile)
 * MAINLOOP: kooperativer Timer-Scheduler (Tasks 10..5000ms)
 * Body: 0x0801C700-0x0801CA1D, 0x0801CAA4-0x0801CC19
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0801c700(void)

{
  ushort uVar1;
  short sVar2;
  uint uVar3;
  
  DAT_200006f4 = '\x01';
  DAT_200006d4 = '\0';
  DAT_200006d5 = '\0';
  DAT_200006d6 = '\0';
  DAT_200006d7 = '\0';
  DAT_200006d8 = '\0';
  DAT_200006d9 = '\0';
  DAT_200006da = '\0';
  DAT_200006db = '\0';
  DAT_200006dc = '\0';
  DAT_200006dd = '\0';
  do {
    while (DAT_200006f4 != '\0') {
      DAT_200006f4 = '\0';
      if (DAT_200006fd == '\0') {
        FUN_08018718();
        FUN_0801874c();
        FUN_0801c640(1);
      }
      if (DAT_200006fd == '\x02') {
        FUN_08018748();
        FUN_0801874c();
        FUN_0801c640(3);
      }
      if (DAT_200006fd == '\x04') {
        FUN_0801874a();
        FUN_0801c640(5);
        _DAT_200006f8 = 0;
      }
      _DAT_200006c0 = FUN_08019152();
      _DAT_200006c2 = FUN_08019152();
      _DAT_200006c4 = FUN_08019152();
      _DAT_200006c6 = FUN_08019152();
      _DAT_200006c8 = FUN_08019152();
      _DAT_200006ca = FUN_08019152();
      _DAT_200006cc = FUN_08019152();
      _DAT_200006ce = FUN_08019152();
      _DAT_200006d0 = FUN_08019152();
      _DAT_200006d2 = FUN_08019152();
    }
    if (DAT_200006d4 == '\0') {
      uVar1 = FUN_08019152();
      uVar3 = (uint)uVar1;
      if (uVar3 < _DAT_200006c0) {
        uVar3 = (0xffff - (uint)_DAT_200006c0) + uVar3;
      }
      else {
        uVar3 = uVar3 - _DAT_200006c0 & 0xffff;
      }
      if (9 < uVar3) {
        DAT_200006d4 = '\x01';
        _DAT_200006c0 = uVar1;
      }
    }
    if (DAT_200006d4 == '\x01') {
      DAT_200006d4 = '\0';
      sVar2 = FUN_08019152();
      FUN_0801876c();
      _DAT_200006de = FUN_08019152();
      _DAT_200006de = _DAT_200006de - sVar2;
    }
    if (DAT_200006d5 == '\0') {
      uVar1 = FUN_08019152();
      uVar3 = (uint)uVar1;
      if (uVar3 < _DAT_200006c2) {
        uVar3 = (0xffff - (uint)_DAT_200006c2) + uVar3;
      }
      else {
        uVar3 = uVar3 - _DAT_200006c2 & 0xffff;
      }
      if (0x13 < uVar3) {
        DAT_200006d5 = '\x01';
        _DAT_200006c2 = uVar1;
      }
    }
    if (DAT_200006d5 == '\x01') {
      DAT_200006d5 = '\0';
      sVar2 = FUN_08019152();
      FUN_08018778();
      _DAT_200006e0 = FUN_08019152();
      _DAT_200006e0 = _DAT_200006e0 - sVar2;
    }
    if (DAT_200006d6 == '\0') {
      uVar1 = FUN_08019152();
      uVar3 = (uint)uVar1;
      if (uVar3 < _DAT_200006c4) {
        uVar3 = (0xffff - (uint)_DAT_200006c4) + uVar3;
      }
      else {
        uVar3 = uVar3 - _DAT_200006c4 & 0xffff;
      }
      if (0x31 < uVar3) {
        DAT_200006d6 = '\x01';
        _DAT_200006c4 = uVar1;
      }
    }
    if (DAT_200006d6 == '\x01') {
      DAT_200006d6 = '\0';
      sVar2 = FUN_08019152();
      FUN_0801877a();
      _DAT_200006e2 = FUN_08019152();
      _DAT_200006e2 = _DAT_200006e2 - sVar2;
    }
    if (DAT_200006d7 == '\0') {
      uVar1 = FUN_08019152();
      uVar3 = (uint)uVar1;
      if (uVar3 < _DAT_200006c6) {
        uVar3 = (0xffff - (uint)_DAT_200006c6) + uVar3;
      }
      else {
        uVar3 = uVar3 - _DAT_200006c6 & 0xffff;
      }
      if (99 < uVar3) {
        DAT_200006d7 = '\x01';
        _DAT_200006c6 = uVar1;
      }
    }
    if (DAT_200006d7 == '\x01') {
      DAT_200006d7 = '\0';
      sVar2 = FUN_08019152();
      FUN_0801877c();
      _DAT_200006e4 = FUN_08019152();
      _DAT_200006e4 = _DAT_200006e4 - sVar2;
    }
    if (DAT_200006d8 == '\0') {
      uVar1 = FUN_08019152();
      uVar3 = (uint)uVar1;
      if (uVar3 < _DAT_200006c8) {
        uVar3 = (0xffff - (uint)_DAT_200006c8) + uVar3;
      }
      else {
        uVar3 = uVar3 - _DAT_200006c8 & 0xffff;
      }
      if (199 < uVar3) {
        DAT_200006d8 = '\x01';
        _DAT_200006c8 = uVar1;
      }
    }
    if (DAT_200006d8 == '\x01') {
      DAT_200006d8 = '\0';
      sVar2 = FUN_08019152();
      FUN_08018794();
      _DAT_200006e6 = FUN_08019152();
      _DAT_200006e6 = _DAT_200006e6 - sVar2;
    }
    if (DAT_200006d9 == '\0') {
      uVar1 = FUN_08019152();
      uVar3 = (uint)uVar1;
      if (uVar3 < _DAT_200006ca) {
        uVar3 = (0xffff - (uint)_DAT_200006ca) + uVar3;
      }
      else {
        uVar3 = uVar3 - _DAT_200006ca & 0xffff;
      }
      if (499 < uVar3) {
        DAT_200006d9 = '\x01';
        _DAT_200006ca = uVar1;
      }
    }
    if (DAT_200006d9 == '\x01') {
      DAT_200006d9 = '\0';
      sVar2 = FUN_08019152();
      FUN_08018796();
      _DAT_200006e8 = FUN_08019152();
      _DAT_200006e8 = _DAT_200006e8 - sVar2;
    }
    if (DAT_200006da == '\0') {
      uVar1 = FUN_08019152();
      uVar3 = (uint)uVar1;
      if (uVar3 < _DAT_200006cc) {
        uVar3 = (0xffff - (uint)_DAT_200006cc) + uVar3;
      }
      else {
        uVar3 = uVar3 - _DAT_200006cc & 0xffff;
      }
      if (999 < uVar3) {
        DAT_200006da = '\x01';
        _DAT_200006cc = uVar1;
      }
    }
    if (DAT_200006da == '\x01') {
      DAT_200006da = '\0';
      sVar2 = FUN_08019152();
      FUN_080187ae();
      _DAT_200006ea = FUN_08019152();
      _DAT_200006ea = _DAT_200006ea - sVar2;
    }
    if (DAT_200006db == '\0') {
      uVar1 = FUN_08019152();
      uVar3 = (uint)uVar1;
      if (uVar3 < _DAT_200006ce) {
        uVar3 = (0xffff - (uint)_DAT_200006ce) + uVar3;
      }
      else {
        uVar3 = uVar3 - _DAT_200006ce & 0xffff;
      }
      if (1999 < uVar3) {
        DAT_200006db = '\x01';
        _DAT_200006ce = uVar1;
      }
    }
    if (DAT_200006db == '\x01') {
      DAT_200006db = '\0';
      sVar2 = FUN_08019152();
      FUN_080187be();
      _DAT_200006ec = FUN_08019152();
      _DAT_200006ec = _DAT_200006ec - sVar2;
    }
    if (DAT_200006dc == '\0') {
      uVar1 = FUN_08019152();
      uVar3 = (uint)uVar1;
      if (uVar3 < _DAT_200006d0) {
        uVar3 = (0xffff - (uint)_DAT_200006d0) + uVar3;
      }
      else {
        uVar3 = uVar3 - _DAT_200006d0 & 0xffff;
      }
      if (4999 < uVar3) {
        DAT_200006dc = '\x01';
        _DAT_200006d0 = uVar1;
      }
    }
    if (DAT_200006dc == '\x01') {
      DAT_200006dc = '\0';
      sVar2 = FUN_08019152();
      FUN_080187d4();
      _DAT_200006ee = FUN_08019152();
      _DAT_200006ee = _DAT_200006ee - sVar2;
    }
    if (DAT_200006dd == '\0') {
      uVar1 = FUN_08019152();
      uVar3 = (uint)uVar1;
      if (uVar3 < _DAT_200006d2) {
        uVar3 = (0xffff - (uint)_DAT_200006d2) + uVar3;
      }
      else {
        uVar3 = uVar3 - _DAT_200006d2 & 0xffff;
      }
      if (9999 < uVar3) {
        DAT_200006dd = '\x01';
        _DAT_200006d2 = uVar1;
      }
    }
    if (DAT_200006dd == '\x01') {
      DAT_200006dd = '\0';
      sVar2 = FUN_08019152();
      FUN_080187dc();
      _DAT_200006f0 = FUN_08019152();
      _DAT_200006f0 = _DAT_200006f0 - sVar2;
    }
    sVar2 = FUN_08019152();
    FUN_080187f0();
    _DAT_200006f2 = FUN_08019152();
    _DAT_200006f2 = _DAT_200006f2 - sVar2;
  } while( true );
}


/* ---------------------------------------------------------------------
 * FUN_0801cc50   (0x0801CC50, 75 Bytes)
 * Body: 0x0801CC50-0x0801CC9B
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0801cc50(void)

{
  _DAT_20002650 = 0;
  _DAT_20002654 = 0;
  _DAT_20002658 = 0;
  _DAT_2000265c = 0;
  _DAT_20002660 = 0;
  _DAT_20002664 = 0x42700000;
  _DAT_20002668 = 0x40000000;
  _DAT_2000266c = 0x42c80000;
  DAT_20002670 = 0;
  DAT_20002671 = 0;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801cc9c   (0x0801CC9C, 113 Bytes)
 * Body: 0x0801CC9C-0x0801CD0D
 * --------------------------------------------------------------------- */
void FUN_0801cc9c(void)

{
  if (DAT_20002671 == '\x03') {
    DAT_20000313 = 2;
    DAT_200002c9 = DAT_2000267e;
    DAT_200002ca = DAT_2000267f;
    DAT_200002c8 = DAT_20002680;
  }
  else if (DAT_20002671 == '\x02') {
    DAT_20000313 = 3;
  }
  else if (DAT_20002671 == '\0') {
    DAT_20000313 = 0;
  }
  else {
    DAT_20000313 = 1;
  }
  if ((DAT_20002681 == '\0') || (DAT_20002671 != '\x03')) {
    DAT_2000031b = 0;
  }
  else {
    DAT_2000031b = 1;
  }
  DAT_2000031a = DAT_20002671;
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801cd0e   (0x0801CD0E, 367 Bytes)
 * Body: 0x0801CD0E-0x0801CE7D
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0801cd0e(void)

{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  uint in_fpscr;
  uint uVar4;
  float fVar5;
  float fVar6;
  
  if ((DAT_200002a1 < 2) || (4 < DAT_200002a1)) {
    uVar3 = 0;
    DAT_20002680 = 0;
  }
  else {
    uVar3 = (uint)DAT_200002b9;
    DAT_20002680 = (&DAT_200002ac)[DAT_200002a1] & 0xf;
  }
  fVar5 = (float)VectorUnsignedToFloat(uVar3,(byte)(in_fpscr >> 0x16) & 3);
  fVar5 = fVar5 + _DAT_20002654 * 0.016666668;
  uVar4 = in_fpscr & 0xfffffff;
  uVar1 = uVar4 | (uint)(fVar5 < 100.0) << 0x1f | (uint)(fVar5 == 100.0) << 0x1e;
  bVar2 = (byte)(uVar1 >> 0x18);
  if ((bool)(bVar2 >> 6 & 1) || (bool)(bVar2 >> 7) != NAN(fVar5)) {
    if (fVar5 < 2.0) {
      fVar5 = 2.0;
    }
  }
  else {
    fVar5 = 100.0;
    uVar4 = uVar1;
  }
  DAT_2000267e = (0.0 < fVar5) * (char)(int)fVar5;
  fVar5 = (float)VectorUnsignedToFloat(uVar3,(byte)(uVar4 >> 0x16) & 3);
  fVar5 = fVar5 - _DAT_20002654 * 0.016666668;
  uVar4 = uVar4 & 0xfffffff;
  uVar1 = uVar4 | (uint)(fVar5 < 100.0) << 0x1f | (uint)(fVar5 == 100.0) << 0x1e;
  bVar2 = (byte)(uVar1 >> 0x18);
  if ((bool)(bVar2 >> 6 & 1) || (bool)(bVar2 >> 7) != NAN(fVar5)) {
    if (fVar5 < 2.0) {
      fVar5 = 2.0;
    }
  }
  else {
    fVar5 = 100.0;
    uVar4 = uVar1;
  }
  DAT_2000267f = (0.0 < fVar5) * (char)(int)fVar5;
  if (DAT_20002681 == '\0') {
    fVar6 = (float)VectorUnsignedToFloat(uVar3,(byte)(uVar4 >> 0x16) & 3);
    uVar4 = uVar4 & 0xfffffff;
    if (fVar5 < fVar6) {
      DAT_20002681 = '\x01';
    }
  }
  if (DAT_20002681 != '\0') {
    DAT_20002680 = 1;
    fVar6 = (float)VectorUnsignedToFloat(uVar3,(byte)(uVar4 >> 0x16) & 3);
    if (fVar5 == fVar6) {
      _DAT_2000070a = _DAT_2000070a + 1;
      if (200 < _DAT_2000070a) {
        _DAT_2000070a = 0;
        DAT_20002681 = '\0';
      }
    }
    else {
      _DAT_2000070a = 0;
    }
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801ce7e   (0x0801CE7E, 251 Bytes)
 * Body: 0x0801CE7E-0x0801CF79
 * --------------------------------------------------------------------- */
float FUN_0801ce7e(float param_1,float *param_2)

{
  param_2[2] = *param_2 - param_1;
  if ((-10.0 < param_2[2]) && (param_2[2] < 10.0)) {
    param_2[2] = 0.0;
    param_2[4] = 0.0;
    param_2[3] = 0.0;
  }
  if ((-50.0 < param_2[2]) && (param_2[2] < 50.0)) {
    param_2[4] = param_2[2] / 2.0 + param_2[4];
    if (param_2[4] <= 520.0) {
      if (param_2[4] < -520.0) {
        param_2[4] = -520.0;
      }
    }
    else {
      param_2[4] = 520.0;
    }
  }
  param_2[1] = param_2[5] * param_2[2] + param_2[6] * param_2[4] +
               param_2[7] * (param_2[2] - param_2[3]);
  param_2[3] = param_2[2];
  return param_2[1];
}


/* ---------------------------------------------------------------------
 * FUN_0801cf7a   (0x0801CF7A, 514 Bytes, 2 Teile)
 * Body: 0x0801CF7A-0x0801D035, 0x0801D0A0-0x0801D1E7
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0801cf7a(void)

{
  if (DAT_20002671 == '\0') {
    if (((DAT_20002670 != '\0') && (1 < DAT_200002a1)) && (DAT_200002a1 < 5)) {
      if ((DAT_20002685 == '\0') || (DAT_20002686 == '\0')) {
        DAT_20002671 = '\x01';
        DAT_20002689 = 0;
        DAT_20002688 = 1;
        _DAT_200006fe = 0;
        _DAT_20000700 = 0;
        _DAT_20000704 = 0;
      }
      else {
        DAT_20002671 = '\x03';
        DAT_20002689 = 1;
        DAT_20002688 = 1;
        _DAT_200006fe = 0;
        _DAT_20000700 = 0;
        _DAT_20000704 = 0;
      }
    }
  }
  else if (DAT_20002671 == '\x01') {
    if (((ushort)((ushort)DAT_20002684 * 8) < _DAT_2000267c) && (_DAT_20002672 < 0x96)) {
      _DAT_200006fe = _DAT_200006fe + 1;
      _DAT_20000704 = _DAT_20000704 + 1;
      if (50000 < _DAT_200006fe) {
        _DAT_200006fe = 50000;
      }
      _DAT_20000700 = 0;
      _DAT_20000702 = 0;
    }
    else if ((_DAT_2000267c < 10) && (0x3c < _DAT_200006fe)) {
      _DAT_20000700 = _DAT_20000700 + 1;
      _DAT_20000702 = 0;
      _DAT_20000704 = 0;
    }
    else if (((_DAT_2000267c < 10) && (_DAT_200006fe < 0x3d)) || (200 < _DAT_20002672)) {
      _DAT_200006fe = 0;
    }
    else {
      _DAT_20000702 = _DAT_20000702 + 1;
      if (100 < _DAT_20000702) {
        _DAT_20000702 = 0;
        _DAT_200006fe = 0;
        _DAT_20000700 = 0;
        _DAT_20000704 = 0;
      }
    }
    if ((0x3c < _DAT_200006fe) && (2 < _DAT_20000700)) {
      _DAT_200006fe = 0;
      _DAT_20000700 = 0;
      DAT_20002671 = '\x02';
      DAT_20002689 = 1;
      DAT_20002688 = 1;
      _DAT_20000706 = 0;
    }
  }
  else if (DAT_20002671 == '\x02') {
    if (DAT_20002687 != '\0') {
      DAT_20002671 = '\x03';
    }
    _DAT_20000706 = _DAT_20000706 + 1;
    if (50000 < _DAT_20000706) {
      _DAT_20000706 = 0;
      DAT_20002671 = '\0';
      DAT_20002689 = 0;
      DAT_20002688 = 1;
    }
  }
  else if (DAT_20002671 == '\x03') {
    FUN_0801ce7e(_DAT_20002678,(float *)&DAT_20002650);
    FUN_0801cd0e();
  }
  else {
    DAT_20002671 = '\0';
  }
  if (((DAT_20002670 == '\0') || (DAT_200002a1 < 2)) || (4 < DAT_200002a1)) {
    DAT_20002671 = '\0';
  }
  else if ((DAT_20002685 == '\0') || (DAT_20002686 == '\0')) {
    if ((_DAT_20002672 < 100) && (_DAT_2000267c < 0x32)) {
      _DAT_20000708 = _DAT_20000708 + 1;
      if (199 < _DAT_20000708) {
        _DAT_20000708 = 0;
        DAT_20002671 = '\0';
      }
    }
    else {
      _DAT_20000708 = 0;
    }
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801d1e8   (0x0801D1E8, 175 Bytes)
 * Body: 0x0801D1E8-0x0801D297
 * --------------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0801d1e8(void)

{
  uint in_fpscr;
  
  DAT_20002670 = DAT_20000312;
  _DAT_20002674 = _DAT_20000316;
  _DAT_20002672 = _DAT_20000318;
  if (DAT_20000312 == '\0') {
    _DAT_20002678 = 0.0;
  }
  else {
    _DAT_20002678 =
         (float)VectorSignedToFloat((uint)_DAT_20000318 - (uint)_DAT_20000316,
                                    (byte)(in_fpscr >> 0x16) & 3);
    _DAT_20002678 = _DAT_20002678 / 10.0;
  }
  DAT_20002685 = (DAT_200002a3 & 0x80) == 0x80;
  DAT_20002686 = (DAT_200002a2 & 0x80) == 0x80;
  DAT_20002687 = (DAT_200002e7 & 8) == 8;
  _DAT_2000267c = _DAT_200002de;
  DAT_20002684 = (&DAT_200002ba)[DAT_200002a1];
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801d298   (0x0801D298, 15 Bytes)
 * Body: 0x0801D298-0x0801D2A7
 * --------------------------------------------------------------------- */
void FUN_0801d298(void)

{
  FUN_0801d1e8();
  FUN_0801cf7a();
  FUN_0801cc9c();
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801d2ec   (0x0801D2EC, 35 Bytes)
 * Body: 0x0801D2EC-0x0801D30F
 * --------------------------------------------------------------------- */
void FUN_0801d2ec(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  undefined4 uVar1;
  bool bVar2;
  
  if ((((uint)param_1 | (uint)param_2) & 3) == 0) {
    for (; 3 < param_3; param_3 = param_3 - 4) {
      uVar1 = *param_2;
      param_2 = param_2 + 1;
      *param_1 = uVar1;
      param_1 = param_1 + 1;
    }
  }
  while (bVar2 = param_3 != 0, param_3 = param_3 - 1, bVar2) {
    *(undefined1 *)param_1 = *(undefined1 *)param_2;
    param_1 = (undefined4 *)((int)param_1 + 1);
    param_2 = (undefined4 *)((int)param_2 + 1);
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801d310   (0x0801D310, 13 Bytes)
 * Body: 0x0801D310-0x0801D31D
 * --------------------------------------------------------------------- */
void FUN_0801d310(undefined1 *param_1,int param_2,undefined1 param_3)

{
  bool bVar1;
  
  while (bVar1 = param_2 != 0, param_2 = param_2 + -1, bVar1) {
    *param_1 = param_3;
    param_1 = param_1 + 1;
  }
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801d31e   (0x0801D31E, 3 Bytes)
 * Body: 0x0801D31E-0x0801D321
 * --------------------------------------------------------------------- */
void FUN_0801d31e(undefined1 *param_1,int param_2)

{
  FUN_0801d310(param_1,param_2,0);
  return;
}


/* ---------------------------------------------------------------------
 * FUN_0801d322   (0x0801D322, 17 Bytes)
 * Body: 0x0801D322-0x0801D333
 * --------------------------------------------------------------------- */
undefined1 * FUN_0801d322(undefined1 *param_1,undefined1 param_2,int param_3)

{
  FUN_0801d310(param_1,param_3,param_2);
  return param_1;
}


/* ---------------------------------------------------------------------
 * FUN_0801d334   (0x0801D334, 13 Bytes)
 * Body: 0x0801D334-0x0801D341
 * --------------------------------------------------------------------- */
int FUN_0801d334(char *param_1)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  
  pcVar3 = param_1;
  do {
    pcVar2 = pcVar3 + 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar2;
  } while (cVar1 != '\0');
  return (int)pcVar2 - (int)(param_1 + 1);
}


/* ---------------------------------------------------------------------
 * FUN_0801d342   (0x0801D342, 321 Bytes)
 * Body: 0x0801D342-0x0801D483
 * --------------------------------------------------------------------- */
ulonglong FUN_0801d342(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  ulonglong uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  bool bVar12;
  ulonglong uVar13;
  longlong lVar14;
  
  iVar3 = (int)(param_2 ^ param_4) >> 0x1f;
  uVar4 = -iVar3;
  uVar8 = param_3;
  uVar11 = param_4;
  if ((param_2 & 0x7fffffff) <= (param_4 & 0x7fffffff) &&
      (uint)(param_3 <= param_1) <= (param_2 & 0x7fffffff) - (param_4 & 0x7fffffff)) {
    uVar8 = param_1;
    uVar11 = param_2;
    param_2 = param_4;
    param_1 = param_3;
  }
  if ((uVar11 & 0x7fffffff) != 0 || uVar8 != 0) {
    uVar10 = param_2 >> 0x14;
    uVar5 = uVar10 & 0x7ff;
    uVar6 = uVar5 - ((uVar11 & 0x7fffffff) >> 0x14);
    if ((int)uVar6 < 0x40) {
      uVar11 = uVar11 & 0xfffff | 0x100000;
      if (uVar4 != 0) {
        bVar12 = uVar8 != 0;
        uVar8 = -uVar8;
        uVar11 = -(uint)bVar12 - uVar11;
      }
      uVar13 = FUN_0801d700(uVar8,uVar11,0x40 - uVar6);
      uVar9 = (uint)(uVar13 >> 0x20);
      uVar7 = (uint)uVar13;
      lVar14 = FUN_0801d73e(uVar8,uVar11,uVar6);
      uVar1 = lVar14 + CONCAT44(param_2,param_1);
      uVar8 = (uint)uVar1;
      uVar11 = (uint)(uVar1 >> 0x20);
      if ((param_2 ^ uVar11) >> 0x14 != 0) {
        if (uVar4 == 0) {
          uVar13 = CONCAT44(uVar9 >> 1 | uVar8 * -0x80000000,
                            (uint)((uVar13 & 0x100000000) != 0) << 0x1f | uVar7 >> 1);
          uVar11 = uVar11 + uVar10 * -0x100000 + 0x100000;
          uVar1 = CONCAT44((uVar11 >> 1) + uVar10 * 0x100000,
                           (uint)((uVar11 & 1) != 0) << 0x1f | uVar8 >> 1);
        }
        else {
          if ((int)uVar6 < 2) {
            uVar13 = FUN_0801d780(uVar8,uVar11 + uVar10 * -0x100000 + 0x100000,uVar7,uVar9,0,
                                  (uVar10 & 0x800) << 0x14,uVar5);
            return uVar13;
          }
          uVar1 = CONCAT44(uVar10 * -0x100000 + uVar11 * 2 + (uint)CARRY4(uVar8,uVar8),
                           uVar8 * 2 | uVar9 >> 0x1f);
          uVar13 = CONCAT44(uVar9 * 2 + (uint)CARRY4(uVar7,uVar7),uVar7 * 2);
        }
      }
    }
    else {
      uVar13 = CONCAT44(-(uint)(1 < (uint)(iVar3 * -2)),iVar3 * 2 + 1);
      uVar1 = CONCAT44(param_2 - (param_1 < uVar4),param_1 + iVar3);
    }
    if ((longlong)uVar13 < 0) {
      uVar2 = uVar1 + 1;
      uVar1 = uVar1 + 1;
      if ((uVar13 & 0x7fffffff) == 0 &&
          (int)(uVar13 >> 0x20) * 2 + (uint)CARRY4((uint)uVar13,(uint)uVar13) == 0) {
        uVar1 = uVar2 & 0xfffffffffffffffe;
      }
    }
    return uVar1;
  }
  return CONCAT44(param_2,param_1);
}


/* ---------------------------------------------------------------------
 * FUN_0801d484   (0x0801D484, 5 Bytes)
 * Body: 0x0801D484-0x0801D489
 * --------------------------------------------------------------------- */
ulonglong FUN_0801d484(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  
  uVar1 = FUN_0801d342(param_1,param_2,param_3,param_4 ^ 0x80000000);
  return uVar1;
}


/* ---------------------------------------------------------------------
 * FUN_0801d48a   (0x0801D48A, 5 Bytes)
 * Body: 0x0801D48A-0x0801D48F
 * --------------------------------------------------------------------- */
ulonglong FUN_0801d48a(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  
  uVar1 = FUN_0801d342(param_1,param_2 ^ 0x80000000,param_3,param_4);
  return uVar1;
}


/* ---------------------------------------------------------------------
 * FUN_0801d490   (0x0801D490, 227 Bytes)
 * Body: 0x0801D490-0x0801D573
 * --------------------------------------------------------------------- */
ulonglong FUN_0801d490(uint param_1,uint param_2,uint param_3,uint param_4)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  ulonglong uVar9;
  
  if ((param_1 == 0 && (param_2 & 0x7fffffff) == 0) || (param_3 == 0 && (param_4 & 0x7fffffff) == 0)
     ) {
    uVar9 = 0;
  }
  else {
    uVar6 = (uint)((ulonglong)param_1 * (ulonglong)param_3);
    uVar2 = param_2 & 0xfffff | 0x100000;
    uVar3 = param_4 & 0xfffff | 0x100000;
    uVar4 = param_1 >> 10 | param_2 << 0x16;
    uVar8 = param_3 >> 10 | param_4 << 0x16;
    lVar1 = (ulonglong)uVar4 * (ulonglong)uVar8;
    uVar7 = (uint)lVar1;
    iVar5 = uVar4 * (uVar3 >> 10) + (uVar2 >> 10) * uVar8 + (int)((ulonglong)lVar1 >> 0x20);
    uVar8 = ((param_1 * uVar3 +
             uVar2 * param_3 + (int)((ulonglong)param_1 * (ulonglong)param_3 >> 0x20)) -
            (iVar5 * 0x100000 | uVar7 >> 0xc)) - (uint)(uVar6 < uVar7 * 0x100000);
    uVar4 = param_1 >> 0x1a | uVar2 << 6;
    uVar2 = param_3 >> 0x1a | uVar3 << 6;
    uVar3 = uVar6 + uVar7 * -0x100000 >> 0x14 | uVar8 * 0x1000;
    lVar1 = (ulonglong)uVar4 * (ulonglong)uVar2 +
            (ulonglong)((iVar5 - uVar4 * uVar2) + (uVar8 >> 0x14) + (uint)CARRY4(uVar3,uVar7));
    uVar9 = FUN_0801d780((uint)lVar1,(int)((ulonglong)lVar1 >> 0x20),uVar6 * 0x1000,uVar3 + uVar7,0,
                         (param_2 ^ param_4) & 0x80000000,
                         ((param_4 & 0x7fffffff) >> 0x14) + ((param_2 & 0x7fffffff) >> 0x14) +
                         -0x3ff);
  }
  return uVar9;
}


/* ---------------------------------------------------------------------
 * FUN_0801d574   (0x0801D574, 250 Bytes, 2 Teile)
 * Body: 0x0801D574-0x0801D651, 0x0801D762-0x0801D77F
 * --------------------------------------------------------------------- */
undefined8 FUN_0801d574(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  bool bVar10;
  
  if ((param_1 != 0 || (param_2 & 0x7fffffff) != 0) && (param_3 != 0 || (param_4 & 0x7fffffff) != 0)
     ) {
    uVar5 = param_4 & 0xfffff | 0x100000;
    uVar4 = param_2 & 0xfffff | 0x100000;
    iVar7 = ((param_2 & 0x7fffffff) >> 0x14) - ((param_4 & 0x7fffffff) >> 0x14);
    iVar8 = iVar7 + 0x3fd;
    if (uVar5 < uVar4 || uVar4 - uVar5 < (uint)(param_3 <= param_1)) {
      iVar8 = iVar7 + 0x3fe;
    }
    else {
      bVar10 = CARRY4(param_1,param_1);
      param_1 = param_1 * 2;
      uVar4 = uVar4 * 2 + (uint)bVar10;
    }
    if (-1 < iVar8) {
      uVar3 = 0x100000;
      uVar6 = 0;
      uVar9 = 0;
      for (uVar2 = 0; uVar2 != 0 || uVar3 != 0; uVar2 = (uint)(uVar1 != 0) << 0x1f | uVar2 >> 1) {
        if (uVar5 < uVar4 || uVar4 - uVar5 < (uint)(param_3 <= param_1)) {
          bVar10 = param_1 < param_3;
          param_1 = param_1 - param_3;
          uVar4 = (uVar4 - uVar5) - (uint)bVar10;
          uVar6 = uVar6 | uVar2;
          uVar9 = uVar9 | uVar3;
        }
        uVar1 = uVar3 & 1;
        uVar3 = uVar3 >> 1;
        bVar10 = CARRY4(param_1,param_1);
        param_1 = param_1 * 2;
        uVar4 = uVar4 * 2 + (uint)bVar10;
      }
      if (param_1 != 0 || uVar4 != 0) {
        if (param_1 == param_3 && uVar4 == uVar5) {
          param_1 = 0;
          uVar4 = 0x80000000;
        }
        else if (uVar5 < uVar4 || uVar4 - uVar5 < (uint)(param_3 <= param_1)) {
          param_1 = 0xfffffffe;
          uVar4 = 0xffffffff;
        }
        else {
          param_1 = 1;
          uVar4 = 0;
        }
      }
      iVar7 = uVar9 + iVar8 * 0x100000 + ((param_2 ^ param_4) & 0x80000000);
      if ((int)uVar4 < 0) {
        bVar10 = 0xfffffffe < uVar6;
        uVar6 = uVar6 + 1;
        iVar7 = iVar7 + (uint)bVar10;
        if ((param_1 & 0x7fffffff) == 0 && uVar4 * 2 + (uint)CARRY4(param_1,param_1) == 0) {
          uVar6 = uVar6 & 0xfffffffe;
        }
      }
      return CONCAT44(iVar7,uVar6);
    }
  }
  return 0;
}


/* ---------------------------------------------------------------------
 * FUN_0801d652   (0x0801D652, 25 Bytes)
 * Body: 0x0801D652-0x0801D66B
 * --------------------------------------------------------------------- */
ulonglong FUN_0801d652(uint param_1)

{
  ulonglong uVar1;
  
  uVar1 = FUN_0801d780(param_1,0,0,0,0,0,0x433);
  return uVar1;
}


/* ---------------------------------------------------------------------
 * FUN_0801d66c   (0x0801D66C, 49 Bytes)
 * Body: 0x0801D66C-0x0801D69D
 * --------------------------------------------------------------------- */
ulonglong FUN_0801d66c(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  
  uVar2 = (param_2 & 0x7fffffff) >> 0x14;
  uVar1 = param_2 & 0xfffff | 0x100000;
  if (uVar2 < 0x3ff) {
    return (ulonglong)uVar1 << 0x20;
  }
  if (uVar2 < 0x434) {
    uVar3 = FUN_0801d71e(param_1,uVar1,-(uVar2 - 0x433));
    return uVar3;
  }
  return CONCAT44(param_2,param_1 << (uVar2 - 0x433 & 0xff)) & 0xfffffffffffff | 0x10000000000000;
}


/* ---------------------------------------------------------------------
 * FUN_0801d6a0   (0x0801D6A0, 47 Bytes)
 * Body: 0x0801D6A0-0x0801D6CF
 * --------------------------------------------------------------------- */
int FUN_0801d6a0(int param_1,int param_2)

{
  if (-1 < param_2) {
    param_1 = -param_1;
  }
  return param_1;
}


/* ---------------------------------------------------------------------
 * FUN_0801d6d0   (0x0801D6D0, 47 Bytes)
 * Body: 0x0801D6D0-0x0801D6FF
 * --------------------------------------------------------------------- */
int FUN_0801d6d0(int param_1,int param_2)

{
  if (-1 < param_2) {
    param_1 = -param_1;
  }
  return param_1;
}


/* ---------------------------------------------------------------------
 * FUN_0801d700   (0x0801D700, 29 Bytes)
 * Body: 0x0801D700-0x0801D71D
 * --------------------------------------------------------------------- */
longlong FUN_0801d700(uint param_1,int param_2,uint param_3)

{
  if (0x1f < (int)param_3) {
    return (ulonglong)(param_1 << (param_3 - 0x20 & 0xff)) << 0x20;
  }
  return CONCAT44(param_2 << (param_3 & 0xff) | param_1 >> (0x20 - param_3 & 0xff),
                  param_1 << (param_3 & 0xff));
}


/* ---------------------------------------------------------------------
 * FUN_0801d71e   (0x0801D71E, 31 Bytes)
 * Body: 0x0801D71E-0x0801D73D
 * --------------------------------------------------------------------- */
ulonglong FUN_0801d71e(uint param_1,uint param_2,uint param_3)

{
  if (0x1f < (int)param_3) {
    return (ulonglong)(param_2 >> (param_3 - 0x20 & 0xff));
  }
  return CONCAT44(param_2 >> (param_3 & 0xff),
                  param_1 >> (param_3 & 0xff) | param_2 << (0x20 - param_3 & 0xff));
}


/* ---------------------------------------------------------------------
 * FUN_0801d73e   (0x0801D73E, 35 Bytes)
 * Body: 0x0801D73E-0x0801D761
 * --------------------------------------------------------------------- */
undefined8 FUN_0801d73e(uint param_1,uint param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  
  if ((int)param_3 < 0x20) {
    iVar2 = (int)param_2 >> (param_3 & 0xff);
    uVar1 = param_1 >> (param_3 & 0xff) | param_2 << (0x20 - param_3 & 0xff);
  }
  else {
    uVar1 = (int)param_2 >> (param_3 - 0x20 & 0xff);
    iVar2 = (int)(param_2 | uVar1) >> 0x1f;
  }
  return CONCAT44(iVar2,uVar1);
}


/* ---------------------------------------------------------------------
 * FUN_0801d780   (0x0801D780, 155 Bytes)
 * Body: 0x0801D780-0x0801D81B
 * --------------------------------------------------------------------- */
ulonglong FUN_0801d780(uint param_1,int param_2,uint param_3,uint param_4,uint param_5,int param_6,
                      int param_7)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  longlong lVar7;
  
  if (param_2 == 0) {
    uVar2 = LZCOUNT(param_1) + 0x20;
  }
  else {
    uVar2 = LZCOUNT(param_2);
  }
  uVar5 = FUN_0801d700(param_1,param_2,uVar2);
  uVar3 = (uint)(uVar5 >> 0x20);
  if (((uint)uVar5 != 0 || param_3 != 0) || (uVar3 != 0 || param_4 != 0)) {
    if (param_3 != 0 || param_4 != 0) {
      uVar6 = FUN_0801d71e(param_3,param_4,0x40 - uVar2);
      lVar7 = FUN_0801d700(param_3,param_4,uVar2);
      uVar5 = CONCAT44(uVar3 | (uint)(uVar6 >> 0x20),(uint)uVar5 | (uint)uVar6 | (uint)(lVar7 != 0))
      ;
    }
    uVar3 = (uint)(uVar5 >> 0xb);
    iVar1 = (param_7 - uVar2) + 10;
    if (-1 < iVar1) {
      uVar2 = uVar3 + param_5;
      iVar1 = iVar1 * 0x100000 + (int)((uVar5 >> 0xb) >> 0x20) + param_6 +
              (uint)CARRY4(uVar3,param_5);
      if ((int)uVar5 * 0x200000 < 0) {
        bVar4 = 0xfffffffe < uVar2;
        uVar2 = uVar2 + 1;
        iVar1 = iVar1 + (uint)bVar4;
        if ((uVar5 & 0x3ff) == 0) {
          uVar2 = uVar2 & 0xfffffffe;
        }
      }
      return CONCAT44(iVar1,uVar2);
    }
    uVar5 = 0;
  }
  return uVar5;
}


/* ---------------------------------------------------------------------
 * FUN_0801d81c   (0x0801D81C, 170 Bytes, 2 Teile)
 * Body: 0x0801D81C-0x0801D83F, 0x0801D8C4-0x0801D94B
 * --------------------------------------------------------------------- */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x0801d83e) */
/* WARNING: Removing unreachable block (ram,0x0801d844) */
/* WARNING: Removing unreachable block (ram,0x0801d84e) */
/* WARNING: Removing unreachable block (ram,0x0801d852) */
/* WARNING: Removing unreachable block (ram,0x0801d856) */
/* WARNING: Removing unreachable block (ram,0x0801d864) */
/* WARNING: Removing unreachable block (ram,0x0801d85c) */
/* WARNING: Removing unreachable block (ram,0x0801d868) */
/* WARNING: Removing unreachable block (ram,0x0801d878) */
/* WARNING: Removing unreachable block (ram,0x0801d88a) */
/* WARNING: Removing unreachable block (ram,0x0801d882) */
/* WARNING: Removing unreachable block (ram,0x0801d86c) */
/* WARNING: Removing unreachable block (ram,0x0801d86e) */
/* WARNING: Removing unreachable block (ram,0x0801d872) */
/* WARNING: Removing unreachable block (ram,0x0801d88e) */
/* WARNING: Removing unreachable block (ram,0x0801d892) */

undefined4 FUN_0801d81c(void)

{
  int iVar1;
  uint uVar2;
  int extraout_r2;
  undefined4 *puVar3;
  char cVar4;
  bool bVar5;
  char cVar6;
  
  puVar3 = &DAT_0801dd44;
  while( true ) {
    cVar6 = SBORROW4((int)puVar3,0x801dd64);
    cVar4 = (int)(puVar3 + -0x2007759) < 0;
    bVar5 = puVar3 == (undefined4 *)&DAT_0801dd64;
    if (&UNK_0801dd63 < puVar3) break;
    (*(code *)puVar3[3])(*puVar3,puVar3[1],puVar3[2]);
    puVar3 = puVar3 + 4;
  }
  uVar2 = thunk_FUN_0800b882();
  if (bVar5 || cVar4 != cVar6) {
    *(short *)(puVar3 + 0xd) = (short)uVar2;
    iVar1 = -((uVar2 >> 0x15) - extraout_r2);
    *(short *)(iVar1 + 0x24) = (short)iVar1;
    uVar2 = 0x20;
  }
  *(undefined2 *)(uVar2 + 0x34) = 0;
  iVar1 = -((uVar2 & 0x1ff) * 4 - uVar2);
  *(short *)(iVar1 + 0x24) = (short)iVar1;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* ---------------------------------------------------------------------
 * FUN_0801d840   (0x0801D840, 85 Bytes)
 * Body: 0x0801D840-0x0801D895
 * --------------------------------------------------------------------- */
undefined4 FUN_0801d840(byte *param_1,byte *param_2,int param_3)

{
  byte *pbVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  uint uVar6;
  
  pbVar5 = param_2 + param_3;
  do {
    uVar6 = (uint)*param_1;
    uVar4 = uVar6 & 7;
    pbVar1 = param_1 + 1;
    if ((*param_1 & 7) == 0) {
      pbVar1 = param_1 + 2;
      uVar4 = (uint)param_1[1];
    }
    uVar2 = (int)uVar6 >> 4;
    if (uVar2 == 0) {
      uVar2 = (uint)*pbVar1;
      pbVar1 = pbVar1 + 1;
    }
    while (uVar4 = uVar4 - 1, uVar4 != 0) {
      *param_2 = *pbVar1;
      pbVar1 = pbVar1 + 1;
      param_2 = param_2 + 1;
    }
    if ((int)(uVar6 << 0x1c) < 0) {
      param_1 = pbVar1 + 1;
      iVar3 = uVar2 + 2;
      pbVar1 = param_2 + -(uint)*pbVar1;
      while (iVar3 = iVar3 + -1, -1 < iVar3) {
        *param_2 = *pbVar1;
        param_2 = param_2 + 1;
        pbVar1 = pbVar1 + 1;
      }
    }
    else {
      while (uVar2 = uVar2 - 1, param_1 = pbVar1, -1 < (int)uVar2) {
        *param_2 = 0;
        param_2 = param_2 + 1;
      }
    }
  } while (param_2 < pbVar5);
  return 0;
}



/* =====================================================================
 *  SEKTION: 0x0801F000 - Stub-Sektion (nur Analyse-Artifact, keine echte Firmware)
 * ===================================================================== */

/* ---------------------------------------------------------------------
 * entry   (0x0801F000, 2153 Bytes)
 * Body: 0x0801F000-0x0801F869
 * --------------------------------------------------------------------- */
void entry(void)

{
  bool bVar1;
  byte bVar2;
  undefined1 uVar3;
  ushort uVar4;
  uint uVar5;
  byte *pbVar6;
  undefined2 *puVar7;
  int iVar8;
  undefined4 uVar9;
  uint *puVar10;
  undefined4 *puVar11;
  ushort *puVar12;
  undefined1 *puVar13;
  char *pcVar14;
  float *pfVar15;
  undefined1 extraout_r1;
  undefined1 extraout_r1_00;
  undefined1 extraout_r1_01;
  undefined1 extraout_r1_02;
  undefined1 extraout_r1_03;
  ushort extraout_r1_04;
  ushort extraout_r1_05;
  ushort extraout_r1_06;
  uint extraout_r1_07;
  undefined4 extraout_r1_08;
  uint extraout_r1_09;
  uint extraout_r1_10;
  uint extraout_r1_11;
  int extraout_r1_12;
  uint extraout_r1_13;
  uint extraout_r1_14;
  undefined4 extraout_r1_15;
  int extraout_r1_16;
  int extraout_r1_17;
  uint extraout_r1_18;
  uint extraout_r1_19;
  uint extraout_r1_20;
  uint extraout_r1_21;
  int extraout_r1_22;
  int extraout_r1_23;
  uint extraout_r1_24;
  uint extraout_r1_25;
  uint extraout_r1_26;
  uint extraout_r1_27;
  uint extraout_r1_28;
  int extraout_r1_29;
  uint extraout_r1_30;
  int extraout_r1_31;
  int extraout_r1_32;
  int extraout_r1_33;
  undefined4 extraout_r1_34;
  undefined4 extraout_r1_35;
  uint extraout_r1_36;
  undefined4 *extraout_r1_37;
  undefined4 *extraout_r1_38;
  int extraout_r1_39;
  undefined4 *extraout_r1_40;
  undefined4 *extraout_r1_41;
  undefined4 *extraout_r1_42;
  undefined4 extraout_r1_43;
  undefined4 *extraout_r1_44;
  short *extraout_r1_45;
  undefined1 *extraout_r1_46;
  uint extraout_r1_47;
  uint extraout_r1_48;
  undefined4 extraout_r1_49;
  uint extraout_r1_50;
  undefined4 *extraout_r1_51;
  ushort *extraout_r1_52;
  uint extraout_r1_53;
  uint extraout_r1_54;
  byte *extraout_r1_55;
  uint extraout_r1_56;
  undefined4 extraout_r1_57;
  uint extraout_r1_58;
  uint extraout_r1_59;
  int extraout_r1_60;
  int extraout_r1_61;
  byte *extraout_r1_62;
  undefined1 extraout_r2;
  undefined1 extraout_r2_00;
  undefined1 extraout_r2_01;
  undefined1 extraout_r2_02;
  undefined1 extraout_r2_03;
  undefined1 extraout_r2_04;
  short extraout_r2_05;
  ushort extraout_r2_06;
  short extraout_r2_07;
  ushort extraout_r2_08;
  ushort extraout_r2_09;
  ushort extraout_r2_10;
  ushort extraout_r2_11;
  undefined2 extraout_r2_12;
  int extraout_r2_13;
  int extraout_r2_14;
  uint extraout_r2_15;
  int extraout_r2_16;
  undefined4 extraout_r2_17;
  int extraout_r2_18;
  uint extraout_r2_19;
  uint extraout_r2_20;
  int extraout_r2_21;
  int extraout_r2_22;
  uint *extraout_r2_23;
  int extraout_r2_24;
  int extraout_r2_25;
  int extraout_r2_26;
  int extraout_r2_27;
  uint extraout_r2_28;
  int extraout_r2_29;
  uint extraout_r2_30;
  uint extraout_r2_31;
  uint extraout_r2_32;
  uint extraout_r2_33;
  int extraout_r2_34;
  undefined4 extraout_r2_35;
  undefined4 extraout_r2_36;
  undefined4 extraout_r2_37;
  undefined4 extraout_r2_38;
  undefined4 extraout_r2_39;
  undefined4 extraout_r2_40;
  undefined4 extraout_r2_41;
  undefined4 extraout_r2_42;
  undefined4 extraout_r2_43;
  undefined4 extraout_r2_44;
  undefined4 extraout_r2_45;
  undefined4 extraout_r2_46;
  uint extraout_r2_47;
  int extraout_r2_48;
  undefined1 *extraout_r2_49;
  uint extraout_r2_50;
  uint extraout_r2_51;
  uint extraout_r2_52;
  int *extraout_r2_53;
  undefined4 extraout_r2_54;
  undefined1 *extraout_r2_55;
  undefined1 *extraout_r2_56;
  undefined4 extraout_r2_57;
  undefined4 extraout_r2_58;
  undefined4 extraout_r2_59;
  undefined4 extraout_r2_60;
  uint extraout_r2_61;
  uint extraout_r2_62;
  uint extraout_r2_63;
  uint extraout_r2_64;
  undefined4 extraout_r2_65;
  undefined4 extraout_r2_66;
  undefined4 extraout_r2_67;
  undefined4 extraout_r2_68;
  uint extraout_r2_69;
  undefined4 extraout_r2_70;
  undefined4 extraout_r2_71;
  undefined4 extraout_r2_72;
  undefined4 extraout_r2_73;
  int extraout_r2_74;
  undefined4 extraout_r2_75;
  ushort *extraout_r2_76;
  uint extraout_r2_77;
  int extraout_r2_78;
  uint extraout_r2_79;
  uint extraout_r2_80;
  uint extraout_r2_81;
  uint extraout_r2_82;
  uint extraout_r2_83;
  uint extraout_r2_84;
  uint extraout_r2_85;
  uint extraout_r2_86;
  uint extraout_r2_87;
  int extraout_r2_88;
  char extraout_r3;
  undefined1 extraout_r3_00;
  undefined1 extraout_r3_01;
  short extraout_r3_02;
  short extraout_r3_03;
  short extraout_r3_04;
  short extraout_r3_05;
  short extraout_r3_06;
  short extraout_r3_07;
  short extraout_r3_08;
  short extraout_r3_09;
  uint extraout_r3_10;
  uint extraout_r3_11;
  uint extraout_r3_12;
  uint extraout_r3_13;
  int extraout_r3_14;
  int extraout_r3_15;
  undefined4 extraout_r3_16;
  undefined4 extraout_r3_17;
  undefined4 extraout_r3_18;
  uint extraout_r3_19;
  undefined4 extraout_r3_20;
  undefined4 extraout_r3_21;
  undefined4 extraout_r3_22;
  undefined4 extraout_r3_23;
  undefined4 extraout_r3_24;
  undefined4 extraout_r3_25;
  undefined4 extraout_r3_26;
  undefined4 extraout_r3_27;
  ulonglong *extraout_r3_28;
  undefined4 extraout_r3_29;
  undefined4 extraout_r3_30;
  uint extraout_r3_31;
  uint extraout_r3_32;
  uint extraout_r3_33;
  uint extraout_r3_34;
  undefined4 extraout_r3_35;
  undefined4 extraout_r3_36;
  undefined4 extraout_r3_37;
  undefined4 extraout_r3_38;
  undefined4 extraout_r3_39;
  undefined4 extraout_r3_40;
  undefined4 extraout_r3_41;
  undefined4 extraout_r3_42;
  int extraout_r3_43;
  uint extraout_r3_44;
  uint extraout_r3_45;
  uint extraout_r3_46;
  uint extraout_r3_47;
  uint extraout_r3_48;
  uint extraout_r3_49;
  float extraout_s0;
  uint extraout_s2;
  uint extraout_s2_00;
  uint extraout_s3;
  uint extraout_s3_00;
  uint extraout_s4;
  uint extraout_s4_00;
  uint extraout_s5;
  uint extraout_s5_00;
  undefined8 uVar16;
  longlong lVar17;
  ulonglong uVar18;
  undefined6 uVar19;
  short sStack00000000;
  undefined8 *in_stack_00000004;
  undefined1 uStack00000008;
  undefined4 in_stack_0000000c;
  undefined4 in_stack_00000010;
  
  thunk_FUN_0800b882();
  FUN_08007160();
  FUN_08007176();
  FUN_0800717a();
  FUN_08007184();
  FUN_08007286();
  FUN_08007324();
  uVar5 = FUN_08007420();
  pbVar6 = (byte *)FUN_08007458(uVar5);
  FUN_08007462(pbVar6);
  uVar16 = FUN_08007730();
  puVar7 = (undefined2 *)FUN_08007776((uint *)uVar16,(ushort *)((ulonglong)uVar16 >> 0x20));
  uVar16 = FUN_0800795a(puVar7);
  bVar1 = FUN_08007972((int)uVar16,(uint)((ulonglong)uVar16 >> 0x20));
  bVar1 = FUN_0800798c((uint)bVar1,extraout_r1_07);
  uVar16 = FUN_080079a6((uint)bVar1,extraout_r1_08);
  uVar16 = FUN_080079ae((int)uVar16,(int)((ulonglong)uVar16 >> 0x20));
  uVar16 = FUN_080079b2((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),extraout_r2_13);
  uVar16 = FUN_080079d2((int)uVar16,(uint)((ulonglong)uVar16 >> 0x20),extraout_r2_14);
  uVar16 = FUN_08007a4a((int)uVar16,(uint)((ulonglong)uVar16 >> 0x20));
  iVar8 = FUN_08007aa4((int)uVar16,(uint)((ulonglong)uVar16 >> 0x20));
  uVar5 = FUN_08007bb4(iVar8);
  FUN_08007bf8(uVar5);
  bVar1 = FUN_08007c30();
  FUN_08007c68((uint)bVar1);
  bVar1 = FUN_08007c8a();
  FUN_08007cdc((uint)bVar1,extraout_r1_09);
  bVar1 = FUN_08007d14();
  uVar9 = FUN_08007d66((uint)bVar1,extraout_r1_10,extraout_r2_15);
  uVar5 = FUN_08007d9e(uVar9);
  FUN_08007da4(uVar5);
  uVar5 = FUN_08007db6();
  uVar5 = FUN_08007dc0(uVar5);
  iVar8 = FUN_08007dd2(uVar5);
  uVar16 = FUN_08007de4(iVar8);
  uVar16 = FUN_08007e4a((uint)uVar16,(uint)((ulonglong)uVar16 >> 0x20));
  uVar5 = FUN_08007e62((uint)uVar16,(int)((ulonglong)uVar16 >> 0x20));
  uVar16 = FUN_08007e80(uVar5);
  uVar16 = FUN_08007ec8((uint)uVar16,(int)((ulonglong)uVar16 >> 0x20));
  FUN_08007f40((uint)uVar16,(int)((ulonglong)uVar16 >> 0x20));
  uVar5 = FUN_08007f58();
  iVar8 = FUN_08007f78(uVar5);
  puVar10 = (uint *)FUN_08008006(iVar8);
  uVar16 = FUN_0800809c(puVar10);
  uVar16 = FUN_080081ca((uint)uVar16,(int)((ulonglong)uVar16 >> 0x20));
  uVar16 = FUN_080081e4((uint)uVar16,(int)((ulonglong)uVar16 >> 0x20));
  uVar16 = FUN_08008218((uint)uVar16,(int)((ulonglong)uVar16 >> 0x20));
  uVar16 = FUN_08008232((uint)uVar16,(int)((ulonglong)uVar16 >> 0x20));
  puVar11 = (undefined4 *)FUN_08008386((int)uVar16,(int *)((ulonglong)uVar16 >> 0x20));
  uVar16 = FUN_0800842e(puVar11);
  uVar16 = FUN_08008446((int)uVar16,(ushort *)((ulonglong)uVar16 >> 0x20));
  uVar16 = FUN_08008474((int)uVar16,(int)((ulonglong)uVar16 >> 0x20));
  uVar16 = FUN_0800848c((int)uVar16,(uint)((ulonglong)uVar16 >> 0x20),extraout_r2_16);
  iVar8 = FUN_0800854e((int)uVar16,(int)((ulonglong)uVar16 >> 0x20));
  uVar4 = FUN_08008556(iVar8);
  bVar1 = FUN_080085fc((ushort *)(uint)uVar4,extraout_r1_04);
  puVar12 = (ushort *)FUN_08008628((ushort *)(uint)bVar1,extraout_r1_11);
  FUN_0800867c(puVar12,extraout_r1_12);
  uVar16 = FUN_080086a0();
  uVar16 = FUN_0800878c((uint *)uVar16,(undefined2 *)((ulonglong)uVar16 >> 0x20));
  uVar16 = FUN_080088b4((int)uVar16,(ushort *)((ulonglong)uVar16 >> 0x20));
  uVar16 = FUN_08008ab0((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),extraout_r2_17,extraout_r3_10);
  uVar19 = FUN_08008aee((int)uVar16,(short *)((ulonglong)uVar16 >> 0x20));
  uVar16 = FUN_08008b4e((int)uVar19,(short)((uint6)uVar19 >> 0x20));
  uVar19 = FUN_08008b68((int)uVar16,(uint)((ulonglong)uVar16 >> 0x20),extraout_r2_05,extraout_r3_02)
  ;
  uVar16 = FUN_08008be2((int)uVar19,(ushort)((uint6)uVar19 >> 0x20));
  uVar19 = FUN_08008bf4((int)uVar16,(uint)((ulonglong)uVar16 >> 0x20),extraout_r2_06,extraout_r3_03)
  ;
  uVar16 = FUN_08008c66((int)uVar19,(short)((uint6)uVar19 >> 0x20));
  uVar19 = FUN_08008c80((int)uVar16,(uint)((ulonglong)uVar16 >> 0x20),extraout_r2_07,extraout_r3_04)
  ;
  uVar16 = FUN_08008cfa((int)uVar19,(ushort)((uint6)uVar19 >> 0x20));
  uVar16 = FUN_08008d0c((int)uVar16,(uint)((ulonglong)uVar16 >> 0x20),extraout_r2_08,extraout_r3_05)
  ;
  uVar16 = FUN_08008d7a((int)uVar16,(short *)((ulonglong)uVar16 >> 0x20));
  uVar16 = FUN_08008e92((uint *)uVar16,(ushort *)((ulonglong)uVar16 >> 0x20));
  uVar19 = FUN_08008f54((uint *)uVar16,(int)((ulonglong)uVar16 >> 0x20));
  uVar19 = FUN_08008f88((int)uVar19,(ushort)((uint6)uVar19 >> 0x20),extraout_r2_18);
  uVar19 = FUN_08008fc6((int)uVar19,(ushort)((uint6)uVar19 >> 0x20));
  uVar16 = FUN_08008fd8((int)uVar19,(ushort)((uint6)uVar19 >> 0x20));
  uVar19 = FUN_08008ff0((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),extraout_r2_19,extraout_r3_06);
  uVar19 = FUN_0800902e((int)uVar19,(ushort)((uint6)uVar19 >> 0x20),extraout_r2_09,extraout_r3_07);
  uVar19 = FUN_0800904a((int)uVar19,(ushort)((uint6)uVar19 >> 0x20),extraout_r2_10,extraout_r3_08);
  uVar19 = FUN_08009080((int)uVar19,(ushort)((uint6)uVar19 >> 0x20),extraout_r2_11,extraout_r3_09);
  uVar19 = FUN_080090a0((int)uVar19,(short)((uint6)uVar19 >> 0x20),extraout_r2_12);
  iVar8 = FUN_080090b6((int)uVar19,(ushort)((uint6)uVar19 >> 0x20),extraout_r2_20,extraout_r3_11);
  uVar4 = FUN_0800958a(iVar8);
  iVar8 = FUN_080095fe((uint)uVar4,extraout_r1_13);
  FUN_08009620(iVar8,extraout_r1_14);
  uVar5 = FUN_08009628();
  FUN_08009640(uVar5);
  FUN_080096f8();
  FUN_08009740();
  FUN_0800974c();
  FUN_0800975a();
  uVar5 = FUN_080097a6();
  uVar9 = FUN_080097cc(uVar5);
  FUN_080097d8(uVar9);
  FUN_08009826();
  FUN_08009884();
  uVar16 = FUN_08009a40();
  puVar11 = (undefined4 *)FUN_08009ada((undefined4 *)uVar16,(int)((ulonglong)uVar16 >> 0x20));
  FUN_08009b30(puVar11,extraout_r1_15);
  FUN_08009e68();
  uVar16 = FUN_0800a03c();
  uVar16 = FUN_0800a068((int)uVar16,(byte *)((ulonglong)uVar16 >> 0x20));
  iVar8 = FUN_0800a0ba((int)uVar16,(int)((ulonglong)uVar16 >> 0x20));
  iVar8 = FUN_0800a0fe(iVar8);
  bVar1 = FUN_0800a10c(iVar8);
  uVar16 = FUN_0800a126((uint)bVar1,extraout_r1_16);
  uVar16 = FUN_0800a150((int)uVar16,(int)((ulonglong)uVar16 >> 0x20));
  iVar8 = FUN_0800a17e((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),extraout_r2_21,extraout_r3_12);
  uVar5 = FUN_0800a25a(iVar8);
  uVar16 = FUN_0800a2de(uVar5,extraout_r1_17,extraout_r2_22,extraout_r3_13);
  uVar16 = FUN_0800a370((int)uVar16,(int)((ulonglong)uVar16 >> 0x20));
  bVar1 = FUN_0800a450((uint *)uVar16,(uint)((ulonglong)uVar16 >> 0x20));
  bVar1 = FUN_0800a454((uint *)(uint)bVar1,extraout_r1_18);
  uVar16 = FUN_0800a466((uint *)(uint)bVar1,extraout_r1_19);
  iVar8 = FUN_0800a46e((uint *)uVar16,(uint)((ulonglong)uVar16 >> 0x20));
  bVar1 = FUN_0800a51a(iVar8,extraout_r1_20);
  uVar16 = FUN_0800a534((uint)bVar1,extraout_r1_21);
  FUN_0800a552((int)uVar16,(uint)((ulonglong)uVar16 >> 0x20));
  uVar16 = FUN_0800a57c();
  puVar7 = (undefined2 *)FUN_0800a594((uint *)uVar16,(ushort *)((ulonglong)uVar16 >> 0x20));
  puVar7 = (undefined2 *)FUN_0800a6a8(puVar7);
  uVar16 = FUN_0800a7aa(puVar7);
  uVar16 = FUN_0800a856((int)uVar16,(ushort *)((ulonglong)uVar16 >> 0x20));
  bVar2 = FUN_0800a97c((int)uVar16,(int)((ulonglong)uVar16 >> 0x20));
  uVar16 = FUN_0800aa06((uint)bVar2,extraout_r1_22);
  uVar16 = FUN_0800aa36((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),extraout_r2_23);
  uVar16 = FUN_0800ab40((int)uVar16,(int)((ulonglong)uVar16 >> 0x20));
  puVar10 = (uint *)FUN_0800ab5a((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),extraout_r2_24);
  iVar8 = FUN_0800ab74(puVar10,extraout_r1_23);
  uVar16 = FUN_0800ac86(iVar8,extraout_r1_24,extraout_r2_25);
  iVar8 = FUN_0800ac98((int)uVar16,(uint)((ulonglong)uVar16 >> 0x20));
  uVar16 = FUN_0800ad10(iVar8,extraout_r1_25);
  bVar1 = FUN_0800ad44((uint)uVar16,(uint)((ulonglong)uVar16 >> 0x20));
  bVar1 = FUN_0800ad56((uint)bVar1,extraout_r1_26);
  uVar16 = FUN_0800af1c((uint)bVar1);
  uVar16 = FUN_0800af4e((ushort *)uVar16,(uint *)((ulonglong)uVar16 >> 0x20));
  uVar16 = FUN_0800b04a((ushort *)uVar16,(int)((ulonglong)uVar16 >> 0x20));
  uVar16 = FUN_0800b062((int)uVar16,(int)((ulonglong)uVar16 >> 0x20));
  uVar16 = FUN_0800b092((ushort *)uVar16,(int)((ulonglong)uVar16 >> 0x20));
  uVar16 = FUN_0800b0aa((ushort *)uVar16,(int)((ulonglong)uVar16 >> 0x20));
  uVar19 = FUN_0800b0c2((ushort *)uVar16,(int)((ulonglong)uVar16 >> 0x20));
  uVar19 = FUN_0800b120((int)uVar19,(ushort)((uint6)uVar19 >> 0x20),extraout_r2_26);
  iVar8 = FUN_0800b132((int)uVar19,(short)((uint6)uVar19 >> 0x20));
  bVar2 = FUN_0800b136(iVar8);
  uVar16 = FUN_0800b13e((uint)bVar2,extraout_r1_05,extraout_r2_27);
  uVar4 = FUN_0800b150((int)uVar16,(int)((ulonglong)uVar16 >> 0x20));
  bVar1 = FUN_0800b254((uint)uVar4,extraout_r1_27);
  uVar5 = FUN_0800b27e((uint)bVar1);
  bVar1 = FUN_0800b298(uVar5,extraout_r1_28);
  uVar16 = FUN_0800b2d2((uint)bVar1,extraout_r1_06);
  iVar8 = FUN_0800b2de((int)uVar16,(uint)((ulonglong)uVar16 >> 0x20));
  lVar17 = FUN_0800b300(iVar8);
  uVar16 = FUN_0800b458((uint *)lVar17,(int)((ulonglong)lVar17 >> 0x20));
  bVar1 = FUN_0800b48e((uint)uVar16,(uint *)((ulonglong)uVar16 >> 0x20));
  uVar16 = FUN_0800b4a6((uint)bVar1,extraout_r1_29);
  FUN_0800b4aa((uint)uVar16,(uint *)((ulonglong)uVar16 >> 0x20));
  FUN_0800b4d8();
  thunk_FUN_0800b4dc();
  FUN_0800b4dc();
  thunk_FUN_0800b4e0();
  FUN_0800b4e0();
  thunk_FUN_0800b4e4();
  FUN_0800b4e4();
  thunk_FUN_0800b4e8();
  FUN_0800b4e8();
  FUN_0800b4ea();
  FUN_0800b4ec();
  FUN_0800b4ee();
  FUN_0800b4f0();
  FUN_0800b4fe();
  FUN_0800b5ca();
  FUN_0800b6cc();
  thunk_FUN_0800b882();
  uVar16 = FUN_0800b882();
  uVar16 = FUN_0800b884((byte *)uVar16,(int)((ulonglong)uVar16 >> 0x20),extraout_r2_28,
                        extraout_r3_14);
  uVar5 = FUN_0800b8ae((uint)uVar16,(uint)((ulonglong)uVar16 >> 0x20),extraout_r2_29);
  puVar13 = (undefined1 *)FUN_0800b912(uVar5,extraout_r1_30,extraout_r2_30,extraout_r3_15);
  uVar16 = FUN_0800b97a(puVar13,extraout_r1,extraout_r2_31);
  uVar16 = FUN_0800b990((undefined1 *)uVar16,(undefined1 *)((ulonglong)uVar16 >> 0x20),
                        extraout_r2_32);
  iVar8 = FUN_0800b9ac((char *)uVar16,(char *)((ulonglong)uVar16 >> 0x20),extraout_r2_33);
  uVar5 = FUN_0800b9d4(iVar8,extraout_r1_31);
  uVar16 = FUN_0800b9ec(uVar5);
  FUN_0800ba04((int)uVar16,(int)((ulonglong)uVar16 >> 0x20));
  FUN_0800ba20();
  pcVar14 = (char *)FUN_0800ba8c();
  pcVar14 = (char *)FUN_0800bad2(pcVar14);
  FUN_0800bb42(pcVar14,extraout_r1_32,extraout_r2_34);
  FUN_0800bb9c();
  FUN_0800bcd6();
  uVar16 = FUN_0800bcfa();
  iVar8 = FUN_0800bd54((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),extraout_r2_35,extraout_r3_16);
  FUN_0800bda6(iVar8,extraout_r1_33);
  FUN_0800bde0();
  FUN_0800bf18();
  FUN_0800bf68();
  FUN_0800bfb8();
  FUN_0800c010();
  FUN_0800c060();
  FUN_0800c0ae();
  FUN_0800c0f2();
  FUN_0800c142();
  FUN_0800c192();
  FUN_0800c1d6();
  FUN_0800c226();
  FUN_0800c276();
  uVar16 = FUN_0800c3d6();
  uVar5 = FUN_0800c424((uint)uVar16,(uint)((ulonglong)uVar16 >> 0x20));
  FUN_0800c42c(uVar5);
  FUN_0800c4d8();
  FUN_0800c4f4();
  FUN_0800c5b8();
  uVar16 = FUN_0800c608();
  uVar16 = FUN_0800d1ec((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),extraout_r2_36,extraout_r3_17);
  uVar16 = FUN_0800d26c((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),extraout_r2_37,extraout_r3_18);
  uVar16 = FUN_0800d2dc((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),extraout_r2_38,extraout_r3_19);
  uVar9 = FUN_0800d532((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),extraout_r2_39,extraout_r3_20);
  FUN_0800d5ca(uVar9,extraout_r1_34,extraout_r2_40,extraout_r3_21);
  uVar16 = FUN_0800d724();
  FUN_0800d892((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),extraout_r2_41,extraout_r3_22);
  uVar16 = FUN_0800d8ae();
  FUN_0800d8da((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),extraout_r2_42,extraout_r3_23);
  uVar16 = FUN_0800d8f6();
  FUN_0800d91e((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),extraout_r2_43,extraout_r3_24);
  uVar4 = FUN_0800d93a();
  uVar9 = FUN_0800d96c((uint)uVar4,extraout_r1_35,extraout_r2_44,extraout_r3_25);
  puVar13 = (undefined1 *)FUN_0800d988(uVar9,extraout_r1_36);
  FUN_0800d9ce(puVar13);
  uVar16 = FUN_0800da4e();
  iVar8 = FUN_0800dbc8((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),extraout_r2_45,extraout_r3_26,
                       _sStack00000000);
  bVar1 = FUN_0800dc5c(iVar8);
  FUN_0800dc72((uint)bVar1,extraout_r1_37);
  FUN_0800dcb2();
  uVar16 = FUN_0800dd38();
  puVar13 = (undefined1 *)
            FUN_0800dd7c((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),extraout_r2_46,extraout_r3_27)
  ;
  FUN_0800ddca(puVar13);
  iVar8 = FUN_0800de4a();
  bVar1 = FUN_0800de88(iVar8);
  FUN_0800deaa((uint)bVar1,extraout_r1_38);
  FUN_0800deea();
  FUN_0800e3a6();
  FUN_0800e5ae();
  FUN_0800eb50();
  FUN_0800eb6c();
  FUN_0800eda0();
  FUN_0800ee76();
  FUN_0800ef96();
  FUN_0800f4fa();
  uVar16 = FUN_0800f720();
  bVar2 = FUN_0800f9ac((int)uVar16,(int)((ulonglong)uVar16 >> 0x20));
  bVar1 = FUN_0800f9c6((uint)bVar2,extraout_r1_39,extraout_r2_47);
  bVar1 = FUN_0800f9e8((uint)bVar1);
  bVar1 = FUN_0800f9fe((uint)bVar1,extraout_r1_40);
  bVar1 = FUN_0800fa3e((uint)bVar1);
  FUN_0800fa54((uint)bVar1,extraout_r1_41);
  FUN_0800fa94();
  FUN_0800fe26();
  FUN_0800fe3a();
  FUN_0800fe96();
  FUN_080100aa();
  FUN_08010238();
  func_0x080103aa();
  FUN_080103ac();
  FUN_080105a8();
  FUN_08010648();
  FUN_080107da();
  FUN_08010b0a();
  uVar16 = FUN_08010b40();
  iVar8 = FUN_08010b92((int)uVar16,(int)((ulonglong)uVar16 >> 0x20));
  bVar1 = FUN_08010bee(iVar8);
  iVar8 = FUN_08010c10((uint)bVar1,extraout_r1_42);
  bVar1 = FUN_08010c50(iVar8);
  uVar9 = FUN_08010c72((uint)bVar1,extraout_r1_43);
  uVar9 = FUN_08010c76(uVar9,extraout_r1_44);
  FUN_08010cb4(uVar9,extraout_r1_45);
  FUN_08010e02();
  puVar11 = (undefined4 *)FUN_08010e8c();
  FUN_08010ff8(puVar11);
  FUN_08010ffe();
  uVar16 = FUN_08011030();
  FUN_08011038((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),extraout_r2_48);
  puVar13 = (undefined1 *)FUN_08011044(extraout_s2,extraout_s3,extraout_s4,extraout_s5);
  uVar16 = FUN_080111b4(extraout_s2_00,extraout_s3_00,extraout_s4_00,extraout_s5_00,puVar13,
                        extraout_r1_46,extraout_r2_49);
  uVar3 = FUN_08011378((uint)uVar16,(uint)((ulonglong)uVar16 >> 0x20),extraout_r2_50,extraout_r3_28,
                       _sStack00000000,in_stack_00000004);
  bVar2 = FUN_080116e6(uVar3);
  uVar5 = FUN_080116ec((uint)bVar2);
  uVar5 = FUN_080116f4(uVar5);
  iVar8 = FUN_080116fc(uVar5,extraout_r1_47);
  uVar9 = FUN_080117bc(iVar8,extraout_r1_48,extraout_r2_51);
  iVar8 = FUN_08011826(uVar9,extraout_r1_00,extraout_r2);
  uVar9 = FUN_080118c8(iVar8);
  uVar9 = FUN_080118f2(uVar9);
  uVar9 = FUN_08011bd6(uVar9);
  uVar9 = FUN_08012432(uVar9);
  uVar9 = FUN_080125fc(uVar9);
  FUN_08012836(uVar9);
  FUN_08012bbe();
  FUN_08012c24();
  FUN_08012c52();
  FUN_08012d00();
  FUN_08012ec6();
  puVar11 = (undefined4 *)FUN_080130a2();
  uVar16 = FUN_08013268(puVar11);
  FUN_0801326e((uint *)uVar16,(uint)((ulonglong)uVar16 >> 0x20));
  FUN_08013288();
  FUN_08013320();
  uVar3 = FUN_080133c4();
  FUN_080134fc(uVar3,extraout_r1_01,extraout_r2_00);
  FUN_08013550();
  FUN_08013940();
  FUN_08013d20();
  FUN_08013f8e();
  FUN_080141b2();
  FUN_080145aa();
  FUN_08014774();
  FUN_080149fa();
  FUN_08014bd2();
  FUN_08014d8a();
  FUN_0801503a();
  FUN_08015356();
  FUN_080154b2();
  FUN_08015caa();
  FUN_08015d0e();
  FUN_08015db6();
  FUN_08015e2a();
  FUN_080163be();
  FUN_0801646a();
  FUN_08016658();
  FUN_08016a30();
  uVar16 = FUN_08016a42();
  iVar8 = FUN_08016a6a((int)uVar16,(byte *)((ulonglong)uVar16 >> 0x20));
  bVar1 = FUN_08016b7c(iVar8);
  iVar8 = FUN_08016b9e((uint)bVar1,extraout_r1_49,extraout_r2_52,extraout_r3_29);
  uVar16 = FUN_08016c16(iVar8,extraout_r1_50);
  uVar16 = FUN_08016d36((int)uVar16,(ushort *)((ulonglong)uVar16 >> 0x20));
  bVar1 = FUN_08016d92((int)uVar16);
  bVar1 = FUN_08016da8((uint)bVar1,extraout_r1_51);
  FUN_08016de2((uint)bVar1,extraout_r1_52,extraout_r2_53,extraout_r3_30);
  FUN_08016e3c();
  FUN_08016e88();
  FUN_08016e9e();
  FUN_08016eb8();
  uVar16 = FUN_08016ec0();
  uVar4 = FUN_08016f74((uint)uVar16,(int)((ulonglong)uVar16 >> 0x20),extraout_r2_54);
  uVar16 = FUN_08016f78(uVar4,extraout_r1_53,extraout_r2_55);
  uVar9 = FUN_08016f96((int)uVar16,(int)((ulonglong)uVar16 >> 0x20));
  FUN_08016fc4(uVar9);
  uVar4 = FUN_0801706e();
  uVar16 = FUN_08017084(uVar4,extraout_r1_54,extraout_r2_56);
  FUN_080170a2((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),extraout_r2_57,extraout_r3_31);
  uVar16 = FUN_080170e2();
  FUN_0801710e((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),extraout_r2_58,extraout_r3_32);
  uVar16 = FUN_08017186();
  FUN_0801719c((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),extraout_r2_59,extraout_r3_33);
  uVar16 = FUN_080171ea();
  FUN_08017200((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),extraout_r2_60,extraout_r3_34);
  FUN_08017230();
  FUN_0801728a();
  FUN_0801744c();
  FUN_08017784();
  puVar13 = (undefined1 *)FUN_08017974();
  puVar13 = (undefined1 *)FUN_08017994(puVar13);
  puVar13 = (undefined1 *)FUN_08017a1a(puVar13);
  uVar16 = FUN_08017a30(puVar13);
  puVar13 = (undefined1 *)
            FUN_08017a40((undefined1 *)uVar16,(byte *)((ulonglong)uVar16 >> 0x20),extraout_r2_61);
  puVar13 = (undefined1 *)FUN_08017ab2(puVar13);
  puVar13 = (undefined1 *)FUN_08017ac8(puVar13);
  puVar13 = (undefined1 *)FUN_08017b4a(puVar13);
  puVar13 = (undefined1 *)FUN_08017b60(puVar13);
  FUN_08017bf2(puVar13);
  FUN_08017c08();
  FUN_08017cde();
  FUN_08017da2();
  FUN_08017db4();
  FUN_08017dc6();
  FUN_08017e08();
  FUN_08017e1a();
  iVar8 = FUN_08017e2c();
  FUN_08018236(iVar8);
  FUN_0801826e();
  FUN_08018478();
  FUN_08018490();
  uVar3 = FUN_08018492();
  FUN_0801852e(uVar3,extraout_r1_02,extraout_r2_01,extraout_r3);
  FUN_08018554();
  FUN_0801861a();
  FUN_0801863c();
  FUN_08018644();
  FUN_0801866c();
  FUN_080186f2();
  FUN_080186f4();
  FUN_08018718();
  FUN_08018748();
  FUN_0801874a();
  FUN_0801874c();
  FUN_0801876c();
  FUN_08018778();
  FUN_0801877a();
  FUN_0801877c();
  FUN_08018794();
  FUN_08018796();
  FUN_080187ae();
  FUN_080187be();
  FUN_080187d4();
  FUN_080187dc();
  FUN_080187f0();
  FUN_08018820();
  uVar16 = FUN_0801883a();
  uVar9 = FUN_080188ba((byte *)uVar16,(int)((ulonglong)uVar16 >> 0x20),extraout_r2_62);
  FUN_08018a0e(uVar9);
  iVar8 = FUN_08018bcc();
  FUN_08018c3c(iVar8);
  FUN_08018d92();
  uVar16 = FUN_08018dfe();
  iVar8 = FUN_08018fd4((uint)uVar16,(undefined1 *)((ulonglong)uVar16 >> 0x20),extraout_r2_63);
  iVar8 = FUN_08018ffe(iVar8,extraout_r1_55,extraout_r2_64);
  FUN_0801906c(iVar8);
  FUN_080190e0();
  FUN_0801914a();
  uVar4 = FUN_08019152();
  uVar16 = FUN_08019166((uint)uVar4);
  FUN_080191c4((uint)uVar16,(int)((ulonglong)uVar16 >> 0x20));
  FUN_0801936a();
  uVar16 = FUN_0801938e();
  uVar16 = FUN_080193bc((int)uVar16,(int)((ulonglong)uVar16 >> 0x20));
  uVar16 = FUN_080193cc((int)uVar16,(int)((ulonglong)uVar16 >> 0x20));
  bVar1 = FUN_080193dc((int)uVar16,(uint)((ulonglong)uVar16 >> 0x20));
  bVar1 = FUN_080193f4((uint)bVar1,extraout_r1_56);
  FUN_0801940c((uint *)(uint)bVar1,extraout_r1_57,extraout_r2_65,extraout_r3_35);
  FUN_0801942a();
  FUN_08019438();
  uVar16 = FUN_08019446();
  uVar16 = FUN_08019452((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),extraout_r2_66,extraout_r3_36);
  FUN_080194ec((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),extraout_r2_67,extraout_r3_37);
  FUN_080194f4();
  FUN_08019568();
  FUN_08019574();
  FUN_08019580();
  uVar16 = FUN_0801959c();
  FUN_080195be((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),extraout_r2_68);
  FUN_080195dc();
  FUN_0801965c();
  FUN_08019690();
  iVar8 = FUN_08019726();
  FUN_08019750(iVar8);
  iVar8 = FUN_0801979e();
  uVar16 = FUN_080198ec(iVar8);
  uVar16 = FUN_08019aee((ushort *)uVar16,(int)((ulonglong)uVar16 >> 0x20));
  uVar16 = FUN_08019b1a((ushort *)uVar16,(byte *)((ulonglong)uVar16 >> 0x20),extraout_r2_69);
  uVar16 = FUN_08019b3a((byte *)uVar16,(uint)((ulonglong)uVar16 >> 0x20));
  uVar16 = FUN_08019b4c((byte *)uVar16,(uint)((ulonglong)uVar16 >> 0x20));
  FUN_08019b5e((byte *)uVar16,(uint)((ulonglong)uVar16 >> 0x20));
  FUN_08019b82();
  FUN_08019bc0();
  uVar16 = FUN_08019bd8();
  bVar1 = FUN_08019bfe((int *)uVar16,(int)((ulonglong)uVar16 >> 0x20));
  FUN_08019c44((uint)bVar1,extraout_r1_58);
  FUN_08019ca0();
  uVar16 = FUN_08019e30();
  uVar16 = FUN_08019f60((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),extraout_r2_02,extraout_r3_00,
                        (int)_sStack00000000,in_stack_00000004,uStack00000008,in_stack_0000000c,
                        in_stack_00000010);
  FUN_08019ff0((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),extraout_r2_03,extraout_r3_01,
               sStack00000000,in_stack_00000004,uStack00000008,in_stack_0000000c,in_stack_00000010);
  FUN_0801a1a8();
  FUN_0801a21a();
  FUN_0801a27a();
  FUN_0801a2dc();
  FUN_0801a34a();
  FUN_0801a644();
  FUN_0801a6a0();
  FUN_0801a6c8();
  FUN_0801a7b4();
  FUN_0801a936();
  FUN_0801aa58();
  FUN_0801aacc();
  FUN_0801ab72();
  FUN_0801abce();
  FUN_0801ac20();
  FUN_0801ad64();
  FUN_0801adfc();
  FUN_0801ae94();
  FUN_0801af2c();
  FUN_0801afc4();
  FUN_0801b05c();
  FUN_0801b0b2();
  FUN_0801b0fe();
  FUN_0801b280();
  FUN_0801b346();
  FUN_0801b8c4();
  FUN_0801b97c();
  uVar16 = FUN_0801b9a4();
  uVar16 = FUN_0801b9e4((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),extraout_r2_70,extraout_r3_38);
  uVar16 = FUN_0801ba4e((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),extraout_r2_71,extraout_r3_39);
  uVar16 = FUN_0801ba92((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),extraout_r2_72,extraout_r3_40);
  uVar16 = FUN_0801bab6((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),extraout_r2_73,extraout_r3_41);
  FUN_0801bb30((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),extraout_r2_74,extraout_r3_42);
  FUN_0801bc7a();
  FUN_0801bd52();
  FUN_0801bd64();
  FUN_0801bd86();
  FUN_0801bd8e();
  uVar16 = FUN_0801bd96();
  uVar16 = FUN_0801bdc4((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),extraout_r2_75,extraout_r3_43);
  FUN_0801be92((int)uVar16,(int)((ulonglong)uVar16 >> 0x20));
  FUN_0801c040();
  uVar16 = FUN_0801c11c();
  FUN_0801c162((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),extraout_r2_76);
  iVar8 = FUN_0801c1b8();
  uVar16 = FUN_0801c1f8(iVar8);
  uVar3 = FUN_0801c5e4((int)uVar16,(int)((ulonglong)uVar16 >> 0x20));
  FUN_0801c640(uVar3);
  FUN_0801c700();
  FUN_0801cc50();
  FUN_0801cc9c();
  pfVar15 = (float *)FUN_0801cd0e();
  FUN_0801ce7e(extraout_s0,pfVar15);
  FUN_0801cf7a();
  FUN_0801d1e8();
  uVar16 = FUN_0801d298();
  uVar16 = FUN_0801d2ec((undefined4 *)uVar16,(undefined4 *)((ulonglong)uVar16 >> 0x20),
                        extraout_r2_77);
  uVar16 = FUN_0801d310((undefined1 *)uVar16,(int)((ulonglong)uVar16 >> 0x20),extraout_r2_04);
  puVar13 = (undefined1 *)FUN_0801d31e((undefined1 *)uVar16,(int)((ulonglong)uVar16 >> 0x20));
  pcVar14 = FUN_0801d322(puVar13,extraout_r1_03,extraout_r2_78);
  uVar5 = FUN_0801d334(pcVar14);
  uVar18 = FUN_0801d342(uVar5,extraout_r1_59,extraout_r2_79,extraout_r3_44);
  uVar18 = FUN_0801d484((uint)uVar18,(uint)(uVar18 >> 0x20),extraout_r2_80,extraout_r3_45);
  uVar18 = FUN_0801d48a((uint)uVar18,(uint)(uVar18 >> 0x20),extraout_r2_81,extraout_r3_46);
  uVar18 = FUN_0801d490((uint)uVar18,(uint)(uVar18 >> 0x20),extraout_r2_82,extraout_r3_47);
  uVar16 = FUN_0801d574((uint)uVar18,(uint)(uVar18 >> 0x20),extraout_r2_83,extraout_r3_48);
  uVar18 = FUN_0801d652((uint)uVar16);
  uVar18 = FUN_0801d66c((uint)uVar18,(uint)(uVar18 >> 0x20));
  iVar8 = FUN_0801d6a0((int)uVar18,(int)(uVar18 >> 0x20));
  uVar5 = FUN_0801d6d0(iVar8,extraout_r1_60);
  lVar17 = FUN_0801d700(uVar5,extraout_r1_61,extraout_r2_84);
  uVar18 = FUN_0801d71e((uint)lVar17,(uint)((ulonglong)lVar17 >> 0x20),extraout_r2_85);
  uVar16 = FUN_0801d73e((uint)uVar18,(uint)(uVar18 >> 0x20),extraout_r2_86);
  FUN_0801d780((uint)uVar16,(int)((ulonglong)uVar16 >> 0x20),extraout_r2_87,extraout_r3_49,
               (uint)_sStack00000000,(int)in_stack_00000004,_uStack00000008);
  pbVar6 = (byte *)FUN_0801d81c();
  FUN_0801d840(pbVar6,extraout_r1_62,extraout_r2_88);
  entry();
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



/* =====================================================================
 *  DATENANHANG  -  alle Bytes ausserhalb der Funktionen
 *  (Vektortabelle, Tabellen, Konfigurationsblock, Strings, Restregionen)
 * ===================================================================== */

/* 1) Vektortabelle @0x08007000 (64 Eintraege) */
const uint32_t vector_table[64] = {
   0x20003B90,  /* [ 0] SP */
   0x08007161,  /* [ 1] Reset */
   0x0800B4D9,  /* [ 2] NMI */
   0x0800B4DB,  /* [ 3] HardFault */
   0x0800B4DF,  /* [ 4] MemManage */
   0x0800B4E3,  /* [ 5] BusFault */
   0x0800B4E7,  /* [ 6] UsageFault */
   0x00000000,  /* [ 7] rsv */
   0x00000000,  /* [ 8] rsv */
   0x00000000,  /* [ 9] rsv */
   0x00000000,  /* [10] SVC */
   0x0800B4EB,  /* [11] DebugMon */
   0x0800B4ED,  /* [12] rsv */
   0x00000000,  /* [13] PendSV */
   0x08007177,  /* [14] SysTick */
   0x0800B4EF,  /* [15] IRQ-1 */
   0x0800717B,  /* [16] IRQ0 */
   0x0800717B,  /* [17] IRQ1 */
   0x0800717B,  /* [18] IRQ2 */
   0x0800717B,  /* [19] IRQ3 */
   0x0800717B,  /* [20] IRQ4 */
   0x0800717B,  /* [21] IRQ5 */
   0x0800717B,  /* [22] IRQ6 */
   0x0800717B,  /* [23] IRQ7 */
   0x0800717B,  /* [24] IRQ8 */
   0x0800717B,  /* [25] IRQ9 */
   0x0800717B,  /* [26] IRQ10 */
   0x0800717B,  /* [27] IRQ11 */
   0x0800717B,  /* [28] IRQ12 */
   0x0800717B,  /* [29] IRQ13 */
   0x0800717B,  /* [30] IRQ14 */
   0x0800717B,  /* [31] IRQ15 */
   0x0800717B,  /* [32] IRQ16 */
   0x0800717B,  /* [33] IRQ17 */
   0x0800717B,  /* [34] IRQ18 */
   0x0800717B,  /* [35] IRQ19 */
   0x0800717B,  /* [36] IRQ20 */
   0x0800717B,  /* [37] IRQ21 */
   0x0800717B,  /* [38] IRQ22 */
   0x0800717B,  /* [39] IRQ23 */
   0x0800717B,  /* [40] IRQ24 */
   0x0800717B,  /* [41] IRQ25 */
   0x0800717B,  /* [42] IRQ26 */
   0x0800717B,  /* [43] IRQ27 */
   0x0800B4F1,  /* [44] IRQ28 */
   0x0800717B,  /* [45] IRQ29 */
   0x0800717B,  /* [46] IRQ30 */
   0x0800717B,  /* [47] IRQ31 */
   0x0800717B,  /* [48] IRQ32 */
   0x0800717B,  /* [49] IRQ33 */
   0x0800717B,  /* [50] IRQ34 */
   0x0800717B,  /* [51] IRQ35 */
   0x0800717B,  /* [52] IRQ36 */
   0x0800B4FF,  /* [53] IRQ37 */
   0x0800B5CB,  /* [54] IRQ38 */
   0x0800B6CD,  /* [55] IRQ39 */
   0x0800717B,  /* [56] IRQ40 */
   0x0800717B,  /* [57] IRQ41 */
   0x0800717B,  /* [58] IRQ42 */
   0x0800717B,  /* [59] IRQ43 */
   0x0800717B,  /* [60] IRQ44 */
   0x0800717B,  /* [61] IRQ45 */
   0x0800717B,  /* [62] IRQ46 */
   0x0800717B,  /* [63] IRQ47 */
};

/* 2) Fabriktabelle Block1-Settings @0x0801DA40 (9 Bytes + 36B Gangtabelle @0x0801DA49) */
 * Layout: [0..2] Flags(0x90,0x90,0x1E=Polpaare30), [3] Wheel 0x6E=11.0", [4] Temp 0x78=120C,
 * 0801DA40  90 90 1E 6E 78 64 30 3C 00 00 00 00 00 00 00 01  ...nxd0<........
 * 0801DA50  14 11 11 0F 0F 02 28 22 22 14 14 03 3C 33 33 19  ......(""...<33.
 * 0801DA60  19 04 50 44 44 1E 1E 05 64 55 55 37 37 01 01 00  ..PDD...dUU77...
 *          [5] Power 0x64=100%, [6] Spannungscode 0x30=48, [7] Pack 0x3C=60V, [8] 0x00;
 *          ab +9: 6x6B Gangtabelle: [idx, Limit(20*idx), EABS|RearStart, FrontStart, RearI, FrontI]

/* 3) Block-0-Werksdefaults @0x0801D9E8 (Version 3.4.13, Identitaet, Frame-Nr., Batch) */
 * 'VCU'+01 01 HW1.1 + 03 04 0D (Version), 'VCU'+53 05..., 29x'0', Identity-Block 14 16 0C 01,
 * 0801D9E8  FF 00 FF 00 56 43 55 01 01 03 04 0D 56 43 55 00  ....VCU.....VCU.
 * 0801D9F8  53 05 00 00 17 00 10 00 30 30 30 30 30 30 30 30  S.......00000000
 * 0801DA08  30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30  0000000000000000
 * 0801DA18  30 30 30 30 30 30 14 16 0C 01 00 41 57 50 45 2D  000000.....AWPE-
 * 0801DA28  56 43 55 2D 32 32 30 32 31 32 00 00 00 00 30 31  VCU-220212....01
 * 0801DA38  44 42 39 39 00 00 00 00 90 90 1E 6E 78 64 30 3C  DB99.......nxd0<
 *  'AWPE-VCU-220212' (Identitaet/Frame-Nr.), '01DB99' (Batch)

/* 4) Parametertabellen @0x0801D8B0..0x0801D9E7 (Frequenzen/Teiler/Bitfelder/Farbmuster) */
 * u.a. 100000/200000/400000/800000/1000000/2000000/4000000 (0x186A0..0x3D0900)
 * 0801D8B0  FB D1 70 47 00 00 00 00 00 00 00 00 01 02 03 04  ..pG............
 * 0801D8C0  06 07 08 09 00 00 00 00 01 02 03 04 A0 86 01 00  ................
 * 0801D8D0  40 0D 03 00 80 1A 06 00 00 35 0C 00 40 42 0F 00  @........5..@B..
 * 0801D8E0  80 84 1E 00 00 09 3D 00 00 00 00 00 01 02 03 04  ......=.........
 * 0801D8F0  01 02 03 04 06 07 08 09 01 02 04 06 08 0A 0C 10  ................
 * 0801D900  20 20 20 20 20 20 20 20 01 00 02 00 04 00 06 00          ........
 * 0801D910  08 00 0A 00 0C 00 10 00 20 00 40 00 80 00 00 01  ........ .@.....
 * 0801D920  00 01 00 01 00 01 00 01 A0 86 01 00 40 0D 03 00  ............@...
 * 0801D930  80 1A 06 00 00 35 0C 00 40 42 0F 00 80 84 1E 00  .....5..@B......
 * Muster 00/FF/7F (Farb-/Bitmuster-Tabelle)
 * 0801D940  00 09 3D 00 00 00 FF 00 00 7F FF 00 00 FF FF 00  ..=.............
 * 0801D950  00 FF 00 00 FF FF 00 00 FF 00 00 00 FF 00 FF 00  ................
 * 0801D960  00 00 FF 00 00 7F FF 00 00 FF FF 00 00 FF 00 00  ................
 * 0801D970  FF FF 00 00 FF 00 00 00 FF 00 FF 00 00 00 FF 00  ................
 * 0801D980  00 7F FF 00 00 FF FF 00 00 FF 00 00 FF FF 00 00  ................
 * 0801D990  FF 00 00 00 FF 00 FF 00 00 00 FF 00 00 7F FF 00  ................
 * 0801D9A0  00 FF FF 00 00 FF 00 00 FF FF 00 00 FF 00 00 00  ................
 * 0801D9B0  FF 00 FF 00 00 00 FF 00 00 7F FF 00 00 FF FF 00  ................
 * 0801D9C0  00 FF 00 00 FF FF 00 00 FF 00 00 00 FF 00 FF 00  ................
 * 0801D9D0  00 00 FF 00 00 7F FF 00 00 FF FF 00 00 FF 00 00  ................
 * 0801D9E0  FF FF 00 00 FF 00 00 00 FF 00 FF 00 56 43 55 01  ............VCU.

/* 5) 16-Bit-Kennlinientabelle @0x0801DC78 (Cap 0x65, Interpolation in Messwertpfad) */
 * Werte 0x0BB8..0x1036 (3000..4150), unlineare Steigung
 * 0801DC78  B8 0B CC 0B E0 0B F4 0B 08 0C 1C 0C 26 0C 30 0C  ............&.0.
 * 0801DC88  3A 0C 44 0C 4E 0C 58 0C 62 0C 6C 0C 76 0C 80 0C  :.D.N.X.b.l.v...
 * 0801DC98  8A 0C 94 0C 9E 0C A8 0C B2 0C C2 0C D2 0C E2 0C  ................
 * 0801DCA8  F2 0C 02 0D 10 0D 1E 0D 2C 0D 3A 0D 48 0D 54 0D  ........,.:.H.T.
 * 0801DCB8  5F 0D 6B 0D 76 0D 82 0D 8D 0D 97 0D A2 0D AC 0D  _.k.v...........
 * 0801DCC8  B7 0D C3 0D CF 0D DA 0D E6 0D F2 0D FD 0D 08 0E  ................
 * 0801DCD8  12 0E 1D 0E 28 0E 32 0E 3B 0E 45 0E 4E 0E 58 0E  ....(.2.;.E.N.X.
 * 0801DCE8  62 0E 6B 0E 75 0E 7E 0E 88 0E 90 0E 98 0E A0 0E  b.k.u.~.........
 * 0801DCF8  A8 0E B0 0E BA 0E C4 0E CE 0E D8 0E E2 0E EC 0E  ................
 * 0801DD08  F5 0E FF 0E 08 0F 12 0F 1F 0F 2C 0F 3A 0F 47 0F  ..........,.:.G.
 * 0801DD18  54 0F 5E 0F 69 0F 73 0F 7E 0F 88 0F 94 0F 9F 0F  T.^.i.s.~.......
 * 0801DD28  AB 0F B6 0F C2 0F CD 0F D9 0F E4 0F F0 0F FB 0F  ................
 * 0801DD38  07 10 13 10 1F 10 2A 10 36 10 00 00 64 DD 01 08  ......*.6...d...

/* 6) Deskriptor-/Zeigerblock @0x0801DD44 (Flash-Service-Deskriptor) */
 * Zeiger 0x0801DD64/0x0801D840/0x0801DDBC, 0x20000000, 0x70C, ...
 * 0801DD44  64 DD 01 08 00 00 00 20 0C 07 00 00 40 D8 01 08  d...... ....@...
 * 0801DD54  BC DD 01 08 0C 07 00 20 84 34 00 00 A6 D8 01 08  ....... .4......
 * 0801DD64  11 04 FF F3 6F 06 01 FF 01 FF 01 CD 28 0D 41 57  ....o.......(.AW
 * 0801DD74  56 43 55 42 31 32 33 34 38 30 01 02 1F 31 02 4D  VCUB123480...1.M
 * 0801DD84  01 02 65 FF 02 27 0E 7A 01 90 39 08 14 F8 01 08  ..e..'.z..9.....
 * 0801DD94  1A F0 04 E9 25 91 03 30 B8 0B 03 1E 50 C3 23 20  ....%..0....P.# 
 * 0801DDA4  06 52 02 43 5A A5 C5 80 01 2C 16 6B 21 05 81 49  .R.CZ....,.k!..I
 * 0801DDB4  20 01 FF 01 15 02 6B 19                           .....k.

/* 7) Strings (Auswahl; vollstaendig in AWIVCU_APP_R3_4_13.strings.txt) */
/*   0x0801DA23: AWPE-VCU-220212 (Werks-/Fallback-Identitaet, 55 42/55 43) */
/*   0x0801DA36: 01DB99 (Serie/Batchcode) */
/*   0x0801DD72: AWVCUB123480 (Board-ID) */
/*   0x0800BE58: AT+FC=1 (BLE-Flow-Control an) */
/*   0x0800BE6C: AT+LENAME=1234567890123456789 (FIN-Name setzen) */
/*   0x0800ED8C: AT+FC? / AT+FC=0 (Abfrage/aus) */

/* 8) Restregionen ohne Funktion (Graeben der Analyse) */
 *     Klassifikation: Padding = nur 00/FF; Pointer = Zeigertabelle; Rest = Codefragment/Daten.
 *
 * --- 0x080070DB-0x08007150 (117B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 080070DB  08 CD B6 00 08 7B 71 00 08 7B 71 00 08 7B 71 00  .....{q..{q..{q.
 * 080070EB  08 7B 71 00 08 7B 71 00 08 7B 71 00 08 7B 71 00  .{q..{q..{q..{q.
 * 080070FB  08 7B 71 00 08 7B 71 00 08 7B 71 00 08 7B 71 00  .{q..{q..{q..{q.
 * 0800710B  08 7B 71 00 08 7B 71 00 08 7B 71 00 08 21 B8 00  .{q..{q..{q..!..
 * 0800711B  08 7B 71 00 08 7B 71 00 08 7B 71 00 08 7B 71 00  .{q..{q..{q..{q.
 * 0800712B  08 7B 71 00 08 7B 71 00 08 7B 71 00 08 7B 71 00  .{q..{q..{q..{q.
 * 0800713B  08 7B 71 00 08 7B 71 00 08 7B 71 00 08 DF F8 10  .{q..{q..{q.....
 * 0800714B  D0 16 F0 66 FB 00 48 00 47 7D B8 00 08 AF F3 00  ...f..H.G}......
 * --- 0x08007153-0x08007160 (13B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 08007153  47 7D B8 00 08 AF F3 00 80 90 3B 00 20 06 48 80  G}........;. .H.
 * --- 0x08007167-0x08007176 (15B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 08007167  47 FE E7 FE E7 FE E7 FE E7 FE E7 FE E7 FE E7 FE  G...............
 * --- 0x0800717B-0x08007184 (9B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0800717B  E7 87 72 00 08 49 71 00 08 30 B5 00 20 00 21 00  ..r..Iq..0.. .!.
 * --- 0x0800740F-0x08007420 (17B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0800740F  BD 00 10 02 40 00 09 3D 00 00 00 00 20 00 70 00  ....@..=.... .p.
 * 0800741F  40 00 20 02 40 FF FF C0 F7 00 00 28 08 88 ED 00  @. .@......(....
 * --- 0x08007423-0x08007458 (53B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 08007423  40 FF FF C0 F7 00 00 28 08 88 ED 00 E0 00 C0 FF  @......(........
 * 08007433  F8 FF FF F6 FE FF FF 00 07 00 80 BF 04 00 70 00  ..............p.
 * 08007443  08 CC D8 01 08 00 24 F4 00 00 12 7A 00 00 00 3C  ......$....z...<
 * 08007453  08 B4 D8 01 08 67 49 01 43 67 4A 11 60 70 47 70  .....gI.CgJ.`pGp
 * --- 0x080074C5-0x0800767C (439B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 080074C5  BD 50 4A 0A 40 02 43 4B 4B 1B 1F 1A 60 70 47 39  .PJ.@.CKK...`pG9
 * 080074D5  B1 49 4A 12 1D 12 68 02 43 47 4B 1B 1D 1A 60 06  .IJ...h.CGK...`.
 * 080074E5  E0 45 4A 12 1D 12 68 82 43 43 4B 1B 1D 1A 60 70  .EJ...h.CCK...`p
 * 080074F5  47 04 28 08 D1 4F F0 E0 21 09 69 41 F0 04 01 4F  G.(..O..!.iA...O
 * 08007505  F0 E0 22 11 61 07 E0 4F F0 E0 21 09 69 21 F0 04  ..".a..O..!.i!..
 * 08007515  01 4F F0 E0 22 11 61 70 47 00 BF 00 BF 00 BF BF  .O..".apG.......
 * 08007525  F3 4F 8F 00 BF 00 BF 00 BF 00 BF 00 BF 00 BF BF  .O..............
 * 08007535  F3 6F 8F 00 BF 00 BF 00 BF 40 F0 01 01 2E 4A 88  .o.......@....J.
 *   ... (Rest ausgelassen; Gesamt 439 Bytes)
 * --- 0x08007761-0x08007776 (21B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 08007761  E7 10 B5 01 21 08 46 00 F0 56 FD 00 21 01 20 00  ....!.F..V..!. .
 * 08007771  F0 52 FD 10 BD F0 B5 03 46 00 25 00 20 00 24 00  .R......F.%. .$.
 * --- 0x08007983-0x0800798C (9B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 08007983  47 01 46 08 69 80 B2 70 47 02 46 00 20 53 69 0B  G.F.i..pG.F. Si.
 * --- 0x0800799D-0x080079A6 (9B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0800799D  47 01 46 48 69 80 B2 70 47 81 61 70 47 81 61 70  G.FHi..pG.apG.ap
 * --- 0x080079BB-0x080079D2 (23B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 080079BB  47 41 61 70 47 4F F4 80 32 0A 43 C2 61 C1 61 C2  GAapGO..2.C.a.a.
 * 080079CB  61 C2 69 C2 69 70 47 F0 B5 03 46 15 46 00 22 00  a.i.ipG...F.F.".
 * --- 0x08007A15-0x08007A30 (27B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 08007A15  E0 00 00 00 08 01 40 00 0C 01 40 00 10 01 40 00  ......@...@...@.
 * 08007A25  14 01 40 04 00 01 40 00 04 01 40 01 F0 07 02 20  ..@...@...@.... 
 * --- 0x08007ADD-0x08007BB4 (215B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 08007ADD  BD 0A 46 00 21 20 4B 1B 1F 19 68 01 23 83 40 99  ..F.! K...h.#.@.
 * 08007AED  43 02 FA 00 F3 19 43 1B 4B 1B 1F 19 60 70 47 02  C.....C.K...`pG.
 * 08007AFD  46 00 20 09 2A 11 D1 17 4B 1B 1F 18 68 20 F4 00  F. .*...K...h ..
 * 08007B0D  70 11 29 02 D1 40 F4 00 70 03 E0 20 F0 F0 00 40  p.)..@..p.. ...@
 * 08007B1D  EA 01 10 10 4B 1B 1F 18 60 11 E0 08 2A 0F D1 0D  ....K...`...*...
 * 08007B2D  4B 1B 1F 18 68 20 F4 80 70 10 29 02 D1 40 F4 80  K...h ..p.)..@..
 * 08007B3D  70 02 E0 20 F0 0F 00 08 43 07 4B 1B 1F 18 60 70  p.. ....C.K...`p
 * 08007B4D  47 00 00 00 08 01 40 00 0C 01 40 00 10 01 40 00  G.....@...@...@.
 * 08007B5D  14 01 40 00 00 20 42 04 00 01 40 00 20 F9 49 49  ..@.. B...@. .II
 * 08007B6D  6A 41 F0 04 01 F7 4A 51 62 11 46 49 68 F6 4A 11  jA....JQb.FIh.J.
 * 08007B7D  40 F4 4A 51 60 11 46 08 68 F4 49 08 40 11 46 08  @.JQ`.F.h.I.@.F.
 * 08007B8D  60 20 F4 80 20 08 60 49 68 F1 4A 11 40 ED 4A 51  ` .. .`Ih.J.@.JQ
 * 08007B9D  60 4F F4 60 51 D1 62 11 63 00 21 51 63 11 64 4F  `O.`Q.b.c.!Qc.dO
 * 08007BAD  F4 1F 01 91 60 70 47 01 46 00 20 E5 4A 10 68 20  ....`pG.F. .J.h 
 * --- 0x08007CC1-0x08007CDC (27B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 08007CC1  BD 01 46 00 20 A2 4A 10 68 20 F0 7C 00 40 EA 81  ..F. .J.h .|.@..
 * 08007CD1  00 10 60 70 47 A2 49 08 60 70 47 10 B5 02 46 00  ..`pG.I.`pG...F.
 * --- 0x08007D4B-0x08007D66 (27B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 08007D4B  BD 01 46 00 20 7F 4A 50 6A 20 F4 FF 00 40 EA C1  ..F. .JPj ...@..
 * 08007D5B  30 50 62 70 47 80 49 08 60 70 47 30 B5 0B 46 14  0PbpG.I.`pG0..F.
 * --- 0x08007DF7-0x08007E4A (83B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 08007DF7  47 31 B1 55 4A 92 68 42 EA 00 22 53 4B 9A 60 05  G1.UJ.hB.."SK.`.
 * 08007E07  E0 51 4A 92 68 22 EA 00 22 4F 4B 9A 60 70 47 52  .QJ.h".."OK.`pGR
 * 08007E17  49 D8 31 08 60 41 08 50 4A C2 F8 DC 10 70 47 01  I.1.`A.PJ....pG.
 * 08007E27  46 00 20 49 4A D0 6A 20 F0 00 50 08 43 D0 62 70  F. IJ.j ..P.C.bp
 * 08007E37  47 01 46 00 20 44 4A D0 6A 20 F0 F8 50 08 43 D0  G.F. DJ.j ..P.C.
 * 08007E47  62 70 47 02 46 00 20 40 4B D8 6A 20 F4 00 30 20  bpG.F. @K.j ..0 
 * --- 0x08007E91-0x08007EC8 (55B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 08007E91  47 02 46 00 20 2E 4B 18 6B 20 F4 00 30 20 F4 78  G.F. .K.k ..0 .x
 * 08007EA1  40 10 43 08 43 18 63 70 47 30 B1 28 49 09 6B 41  @.C.C.cpG0.(I.kA
 * 08007EB1  F4 80 21 26 4A 11 63 05 E0 25 49 09 6B 21 F4 80  ..!&J.c..%I.k!..
 * 08007EC1  21 23 4A 11 63 70 47 10 B5 02 46 00 20 20 4B 18  !#J.cpG...F.  K.
 * --- 0x08007EF5-0x08007F40 (75B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 08007EF5  BD 01 46 00 20 15 4A 10 6B 20 F4 80 70 08 43 10  ..F. .J.k ..p.C.
 * 08007F05  63 70 47 29 B1 11 4A 52 6B 02 43 0F 4B 5A 63 04  cpG)..JRk.C.KZc.
 * 08007F15  E0 0E 4A 52 6B 82 43 0C 4B 5A 63 70 47 31 B1 0A  ..JRk.C.KZcpG1..
 * 08007F25  4A 52 6B 42 EA 00 12 08 4B 5A 63 05 E0 07 4A 52  JRkB....KZc...JR
 * 08007F35  6B 22 EA 00 12 05 4B 5A 63 70 47 A1 B1 03 4A D2  k"....KZcpG...J.
 * --- 0x08007F4D-0x08007F58 (11B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 08007F4D  E0 00 00 00 10 02 40 00 C0 FF F8 FE FF F6 FE FF  ......@.........
 * --- 0x08007F58-0x08007F6C (20B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 08007F58  FE FF F6 FE FF FF 00 F7 00 00 42 42 88 04 42 42  ..........BB..BB
 * 08007F68  FF FF C0 F7 D8 4A D2 69 82 43 D7 4B DA 61 70 47  .....J.i.C.K.apG
 * --- 0x08007F9F-0x08008006 (103B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 08007F9F  BD CB 48 40 6B 00 F0 07 00 70 47 01 46 00 20 C8  ..H@k....pG.F. .
 * 08007FAF  4A 50 6B 20 F0 18 00 08 43 50 63 70 47 C4 48 40  JPk ....CPcpG.H@
 * 08007FBF  6B 00 F0 18 00 70 47 29 B1 C1 4A 52 6C 02 43 C0  k....pG)..JRl.C.
 * 08007FCF  4B 5A 64 04 E0 BE 4A 52 6C 82 43 BD 4B 5A 64 70  KZd...JRl.C.KZdp
 * 08007FDF  47 29 B1 BB 4A 52 6C 02 43 B9 4B 5A 64 04 E0 B8  G)..JRl.C.KZd...
 * 08007FEF  4A 52 6C 82 43 B6 4B 5A 64 70 47 B5 49 49 6C 01  JRl.C.KZdpG.IIl.
 * 08007FFF  43 B3 4A 51 64 70 47 10 B5 04 46 01 21 08 07 FF  C.JQdpG...F.!...
 * --- 0x08008055-0x0800809C (71B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 08008055  BD A0 49 08 60 70 47 01 46 00 20 9B 4A 10 6A 20  ..I.`pG.F. .J.j 
 * 08008065  F4 40 70 08 43 10 62 70 47 98 48 00 6A 00 F4 40  .@p.C.bpG.H.j..@
 * 08008075  70 70 47 97 49 44 39 08 60 70 47 01 46 00 20 92  ppG.ID9.`pG.F. .
 * 08008085  4A 10 6A 20 F0 20 00 08 43 10 62 70 47 8F 48 00  J.j . ..C.bpG.H.
 * 08008095  6A 00 F0 20 00 70 47 F0 B5 00 21 00 BF 00 23 00  j.. .pG...!...#.
 * --- 0x080081FD-0x08008218 (27B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 080081FD  47 29 B1 33 4A 92 6A 02 43 32 4B 9A 62 04 E0 30  G).3J.j.C2K.b..0
 * 0800820D  4A 92 6A 82 43 2F 4B 9A 62 70 47 29 B1 2D 4A D2  J.j.C/K.bpG).-J.
 * --- 0x0800824B-0x08008386 (315B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0800824B  47 22 49 40 39 08 60 70 47 29 49 C8 64 70 47 1F  G"I@9.`pG)I.dpG.
 * 0800825B  49 74 39 08 60 70 47 00 20 1A 49 09 6A 01 F0 10  It9.`pG. .I.j...
 * 0800826B  01 09 B1 01 20 00 E0 00 20 70 47 01 46 00 20 15  .... ... pG.F. .
 * 0800827B  4A 50 68 20 F0 70 40 08 43 50 60 70 47 01 46 00  JPh .p@.CP`pG.F.
 * 0800828B  20 10 4A 50 68 20 F0 E0 60 40 EA 01 60 50 60 70   .JPh ..`@..`P`p
 * 0800829B  47 00 20 0C 49 48 6A 40 F0 80 70 48 62 20 F0 80  G. .IHj@..pHb ..
 * 080082AB  70 48 62 70 47 01 46 00 20 06 4A 92 68 0A 40 0A  pHbpG.F. .J.h.@.
 * 080082BB  B1 01 20 00 E0 00 20 70 47 02 49 89 68 01 43 01  .. ... pG.I.h.C.
 * 080082CB  4A 91 60 70 47 00 10 02 40 00 70 00 40 80 04 42  J.`pG...@.p.@..B
 * 080082DB  42 00 00 3C 08 00 12 7A 00 00 24 F4 00 00 09 3D  B..<...z..$....=
 * 080082EB  00 28 D9 01 08 E8 D8 01 08 F8 D8 01 08 08 D9 01  .(..............
 * 080082FB  08 00 00 42 42 10 B5 04 46 E5 48 84 42 09 D1 01  ...BB...F.H.B...
 * 0800830B  21 88 03 FF F7 83 FF 00 21 4F F4 80 40 FF F7 7E  !.......!O..@..~
 * 0800831B  FF 32 E0 E0 48 84 42 09 D1 01 21 48 04 FF F7 83  .2..H.B...!H....
 * 0800832B  FF 00 21 4F F4 00 30 FF F7 7E FF 25 E0 DA 48 84  ..!O..0..~.%..H.
 * 0800833B  42 09 D1 01 21 88 04 FF F7 76 FF 00 21 4F F4 80  B...!....v..!O..
 * 0800834B  20 FF F7 71 FF 18 E0 D5 48 84 42 09 D1 01 21 48   ..q....H.B...!H
 * 0800835B  04 FF F7 5C FF 00 21 4F F4 00 30 FF F7 57 FF 0B  ...\..!O..0..W..
 * 0800836B  E0 CF 48 84 42 08 D1 01 21 88 04 FF F7 4F FF 00  ..H.B...!....O..
 * 0800837B  21 4F F4 80 20 FF F7 4A FF 10 BD 2D E9 F0 47 86  !O.. ..J...-..G.
 * --- 0x08008467-0x08008474 (13B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 08008467  BD 00 21 01 80 41 80 81 80 C1 80 70 47 21 B1 82  ..!..A.....pG!..
 * --- 0x080084D5-0x0800854E (121B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 080084D5  BD 1A B1 83 8A 0B 43 83 82 02 E0 83 8A 8B 43 83  ......C.......C.
 * 080084E5  82 70 47 02 8A 4F F6 F0 73 1A 40 02 82 02 8A 0A  .pG..O..s.@.....
 * 080084F5  43 02 82 70 47 82 89 4F F2 FF 73 1A 40 82 81 82  C..pG..O..s.@...
 * 08008505  89 0A 43 82 81 70 47 21 B1 82 89 42 F0 02 02 82  ..C..pG!...B....
 * 08008515  81 04 E0 82 89 4F F6 FD 73 1A 40 82 81 70 47 02  .....O..s.@..pG.
 * 08008525  8A 4F F6 DF 73 1A 40 02 82 02 8A 0A 43 02 82 70  .O..s.@.....C..p
 * 08008535  47 21 B1 02 8A 42 F4 80 42 02 82 04 E0 02 8A 4B  G!...B..B......K
 * 08008545  F6 FF 73 1A 40 02 82 70 47 C1 F3 08 02 82 80 70  ..s.@..pG......p
 * --- 0x0800855F-0x080085FC (157B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0800855F  47 81 89 41 F0 01 01 81 81 70 47 02 8B D2 B2 02  G..A.....pG.....
 * 0800856F  83 02 8B 42 EA 01 22 02 83 70 47 02 8B 02 F4 7F  ...B.."..pG.....
 * 0800857F  42 02 83 02 8B 0A 43 02 83 70 47 21 B1 82 8A 42  B.....C..pG!...B
 * 0800858F  F0 20 02 82 82 04 E0 82 8A 4F F6 DF 73 1A 40 82  . .......O..s.@.
 * 0800859F  82 70 47 21 B1 82 8A 42 F0 10 02 82 82 04 E0 82  .pG!...B........
 * 080085AF  8A 4F F6 EF 73 1A 40 82 82 70 47 21 B1 82 8A 42  .O..s.@..pG!...B
 * 080085BF  F0 08 02 82 82 04 E0 82 8A 4F F6 F7 73 1A 40 82  .........O..s.@.
 * 080085CF  82 70 47 82 8A 4F F6 FB 73 1A 40 82 82 82 8A 0A  .pG..O..s.@.....
 * 080085DF  43 82 82 70 47 21 B1 82 8A 42 F0 02 02 82 82 04  C..pG!...B......
 * 080085EF  E0 82 8A 4F F6 FD 73 1A 40 82 82 70 47 02 46 00  ...O..s.@..pG.F.
 * --- 0x08008615-0x08008628 (19B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 08008615  47 01 F4 00 72 B2 F5 00 7F 00 D1 00 BF CA 43 02  G...r.........C.
 * 08008625  80 70 47 70 B5 02 46 00 24 00 23 00 25 00 20 40  .pGp..F.$.#.%. @
 * --- 0x08008EE3-0x08008F54 (113B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 08008EE3  BD 4F F6 FF 71 81 80 00 21 01 80 C1 80 41 80 01  .O..q...!....A..
 * 08008EF3  72 41 72 81 72 C1 72 01 73 41 73 81 73 70 47 00  rAr.r.r.sAs.spG.
 * 08008F03  21 01 80 41 80 81 80 C1 80 01 81 41 81 81 81 C1  !..A.......A....
 * 08008F13  81 70 47 00 00 00 2C 01 40 00 34 01 40 00 04 00  .pG...,.@.4.@...
 * 08008F23  40 00 08 00 40 00 0C 00 40 00 3C 00 40 00 21 01  @...@...@.<.@.!.
 * 08008F33  80 41 80 01 21 81 80 00 21 C1 80 01 81 70 47 00  .A..!...!....pG.
 * 08008F43  21 01 80 41 80 81 80 C1 80 01 81 41 81 81 81 70  !..A.......A...p
 * 08008F53  47 21 B1 02 68 42 F0 01 02 02 60 03 E0 02 68 22  G!..hB....`...h"
 * --- 0x08008F69-0x08008F88 (31B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 08008F69  47 31 B1 B0 F8 44 20 42 F4 00 42 A0 F8 44 20 05  G1...D B..B..D .
 * 08008F79  E0 B0 F8 44 20 C2 F3 0E 02 A0 F8 44 20 70 47 1A  ...D ......D pG.
 * --- 0x08008F99-0x08008FC6 (45B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 08008F99  47 81 82 70 47 41 EA 02 03 A0 F8 48 30 70 47 1A  G..pGA.....H0pG.
 * 08008FA9  B1 83 89 0B 43 83 81 02 E0 83 89 8B 43 83 81 70  ....C.......C..p
 * 08008FB9  47 01 89 4F F6 F8 72 11 40 01 81 70 47 0A 46 00  G..O..r.@..pG.F.
 * --- 0x080090F5-0x08009234 (319B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 080090F5  BD 0A 46 00 21 01 8B 4F F6 8F 73 19 40 11 43 01  ..F.!..O..s.@.C.
 * 08009105  83 70 47 0A 46 00 21 01 8B 48 F6 FF 73 19 40 4F  .pG.F.!..H..s.@O
 * 08009115  F6 FF 73 03 EA 02 23 19 43 01 83 70 47 0A 46 00  ..s...#.C..pG.F.
 * 08009125  21 81 8B 4F F6 8F 73 19 40 11 43 81 83 70 47 0A  !..O..s.@.C..pG.
 * 08009135  46 00 21 81 8B 48 F6 FF 73 19 40 4F F6 FF 73 03  F.!..H..s.@O..s.
 * 08009145  EA 02 23 19 43 81 83 70 47 0A 46 00 21 B0 F8 54  ..#.C..pG.F.!..T
 * 08009155  10 4F F6 8F 73 19 40 11 43 A0 F8 54 10 70 47 0A  .O..s.@.C..T.pG.
 * 08009165  46 00 21 B0 F8 54 10 48 F6 FF 73 19 40 4F F6 FF  F.!..T.H..s.@O..
 * 08009175  73 03 EA 02 23 19 43 A0 F8 54 10 70 47 21 B1 02  s...#.C..T.pG!..
 * 08009185  68 42 F0 80 02 02 60 03 E0 02 68 22 F0 80 02 02  hB....`...h"....
 * 08009195  60 70 47 21 B1 42 68 42 F0 04 02 42 60 03 E0 42  `pG!.BhB...B`..B
 * 080091A5  68 22 F0 04 02 42 60 70 47 21 B1 42 68 42 F0 08  h"...B`pG!.BhB..
 * 080091B5  02 42 60 03 E0 42 68 22 F0 08 02 42 60 70 47 21  .B`..Bh"...B`pG!
 * 080091C5  B1 42 68 42 F0 01 02 42 60 03 E0 42 68 22 F0 01  .BhB...B`..Bh"..
 * 080091D5  02 42 60 70 47 0A 46 00 21 01 8B 4F F6 F7 73 19  .B`pG.F.!..O..s.
 * 080091E5  40 11 43 01 83 70 47 0A 46 00 21 01 8B 4F F2 FF  @.C..pG.F.!..O..
 * 080091F5  73 19 40 4F F6 FF 73 03 EA 02 23 19 43 01 83 70  s.@O..s...#.C..p
 * 08009205  47 0A 46 00 21 81 8B 4F F6 F7 73 19 40 11 43 81  G.F.!..O..s.@.C.
 * 08009215  83 70 47 0A 46 00 21 81 8B 4F F2 FF 73 19 40 4F  .pG.F.!..O..s.@O
 * 08009225  F6 FF 73 03 EA 02 23 19 43 81 83 70 47 0A 46 00  ..s...#.C..pG.F.
 * --- 0x08009247-0x080093A8 (353B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 08009247  47 0A 46 00 21 B0 F8 54 10 4F F2 FF 73 19 40 4F  G.F.!..T.O..s.@O
 * 08009257  F6 FF 73 03 EA 02 23 19 43 A0 F8 54 10 70 47 0A  ..s...#.C..T.pG.
 * 08009267  46 00 21 01 8B 4F F6 FB 73 19 40 11 43 01 83 70  F.!..O..s.@.C..p
 * 08009277  47 0A 46 00 21 01 8B 4F F6 FF 33 19 40 4F F6 FF  G.F.!..O..3.@O..
 * 08009287  73 03 EA 02 23 19 43 01 83 70 47 0A 46 00 21 81  s...#.C..pG.F.!.
 * 08009297  8B 4F F6 FB 73 19 40 11 43 81 83 70 47 0A 46 00  .O..s.@.C..pG.F.
 * 080092A7  21 81 8B 4F F6 FF 33 19 40 4F F6 FF 73 03 EA 02  !..O..3.@O..s...
 * 080092B7  23 19 43 81 83 70 47 0A 46 00 21 B0 F8 54 10 4F  #.C..pG.F.!..T.O
 * 080092C7  F6 FB 73 19 40 11 43 A0 F8 54 10 70 47 0A 46 00  ..s.@.C..T.pG.F.
 * 080092D7  21 B0 F8 54 10 4F F6 FF 33 19 40 4F F6 FF 73 03  !..T.O..3.@O..s.
 * 080092E7  EA 02 23 19 43 A0 F8 54 10 70 47 0A 46 00 21 01  ..#.C..T.pG.F.!.
 * 080092F7  8B 4F F6 7F 73 19 40 11 43 01 83 70 47 0A 46 00  .O..s.@.C..pG.F.
 * 08009307  21 01 8B C1 F3 0E 01 4F F6 FF 73 03 EA 02 23 19  !......O..s...#.
 * 08009317  43 01 83 70 47 0A 46 00 21 81 8B 4F F6 7F 73 19  C..pG.F.!..O..s.
 * 08009327  40 11 43 81 83 70 47 0A 46 00 21 81 8B C1 F3 0E  @.C..pG.F.!.....
 * 08009337  01 4F F6 FF 73 03 EA 02 23 19 43 81 83 70 47 0A  .O..s...#.C..pG.
 * 08009347  46 00 21 B0 F8 54 10 4F F6 7F 73 19 40 11 43 A0  F.!..T.O..s.@.C.
 * 08009357  F8 54 10 70 47 0A 46 00 21 B0 F8 54 10 C1 F3 0E  .T.pG.F.!..T....
 * 08009367  01 4F F6 FF 73 03 EA 02 23 19 43 A0 F8 54 10 70  .O..s...#.C..T.p
 * 08009377  47 0A 46 00 21 01 6A 21 F0 02 01 11 43 01 62 70  G.F.!.j!....C.bp
 * 08009387  47 0A 46 00 21 01 6A 21 F0 08 01 11 43 01 62 70  G.F.!.j!....C.bp
 * 08009397  47 0A 46 00 21 01 6A 21 F0 20 01 41 EA 02 11 01  G.F.!.j!. .A....
 * 080093A7  62 70 47 0A 46 00 21 01 6A 21 F0 80 01 41 EA 02  bpG.F.!.j!...A..
 * --- 0x080093A9-0x0800958A (481B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 080093A9  47 0A 46 00 21 01 6A 21 F0 80 01 41 EA 02 11 01  G.F.!.j!...A....
 * 080093B9  62 70 47 0A 46 00 21 01 6A 21 F4 00 71 41 EA 02  bpG.F.!.j!..qA..
 * 080093C9  21 01 62 70 47 0A 46 00 21 01 6A 21 F4 00 61 41  !.bpG.F.!.j!..aA
 * 080093D9  EA 02 21 01 62 70 47 0A 46 00 21 01 6A 21 F4 00  ..!.bpG.F.!.j!..
 * 080093E9  51 41 EA 02 31 01 62 70 47 0A 46 00 21 01 6A 21  QA..1.bpG.F.!.j!
 * 080093F9  F4 00 31 41 EA 02 41 01 62 70 47 0A 46 00 21 01  ..1A..A.bpG.F.!.
 * 08009409  6A 21 F4 00 11 41 EA 02 51 01 62 70 47 30 B5 00  j!...A..Q.bpG0..
 * 08009419  23 01 24 8C 40 A3 B2 04 6A 9C 43 04 62 04 6A 02  #.$.@...j.C.b.j.
 *   ... (Rest ausgelassen; Gesamt 481 Bytes)
 * --- 0x0800958F-0x080095A4 (21B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0800958F  47 01 46 08 8D 70 47 01 46 88 8D 70 47 02 46 00  G.F..pG.F..pG.F.
 * 0800959F  20 21 4B 9A 42 02 D0 21 4B 9A 42 06 D1 13 6A 0B   !K.B..!K.B...j.
 * --- 0x080095E5-0x080095FE (25B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 080095E5  47 02 46 00 20 13 69 0B 40 0B B1 01 20 00 E0 00  G.F. .i.@... ...
 * 080095F5  20 70 47 CA 43 02 61 70 47 30 B5 02 46 00 20 00   pG.C.apG0..F. .
 * --- 0x08009651-0x080096F8 (167B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 08009651  47 FB 49 09 68 21 F0 10 01 F9 4A 11 60 11 46 09  G.I.h!....J.`.F.
 * 08009661  68 01 43 11 60 70 47 F5 48 00 68 40 F0 40 00 F3  h.C.`pG.H.h@.@..
 * 08009671  49 08 60 70 47 F2 49 09 68 21 F0 80 01 F0 4A 11  I.`pG.I.h!....J.
 * 08009681  60 11 46 09 68 01 43 11 60 70 47 EC 49 09 68 21  `.F.h.C.`pG.I.h!
 * 08009691  F4 00 71 EA 4A 11 60 11 46 09 68 01 43 11 60 70  ..q.J.`.F.h.C.`p
 * 080096A1  47 00 20 E6 49 09 68 01 F4 80 71 09 B1 01 20 00  G. .I.h...q... .
 * 080096B1  E0 00 20 70 47 E2 49 09 68 21 F4 00 61 E0 4A 11  .. pG.I.h!..a.J.
 * 080096C1  60 11 46 09 68 01 43 11 60 70 47 00 20 DC 49 09  `.F.h.C.`pG. .I.
 * 080096D1  68 01 F4 80 61 09 B1 01 20 00 E0 00 20 70 47 D7  h...a... ... pG.
 * 080096E1  49 09 69 43 F6 FF 62 11 40 D5 4A 11 61 11 46 09  I.iC..b.@.J.a.F.
 * 080096F1  69 01 43 11 61 70 47 08 B5 00 21 00 22 00 92 00  i.C.apG...!."...
 * --- 0x08009CFF-0x08009E68 (361B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 08009CFF  E7 30 B5 06 24 58 48 C0 69 00 F0 1C 00 85 03 FF  .0..$XH.i.......
 * 08009D0F  F7 AF FD 08 B9 45 F0 A5 05 FF F7 B4 FD 10 B1 08  .....E..........
 * 08009D1F  24 20 46 30 BD 7C 20 FF F7 51 FD 4F F4 30 20 FF  $ F0.| ..Q.O.0 .
 * 08009D2F  F7 3A FD 04 46 06 2C 4D D1 4C 48 4B 49 88 60 4C  .:..F.,M.LHKI.`L
 * 08009D3F  48 88 60 08 46 00 69 40 F0 20 00 08 61 08 46 00  H.`.F.i@. ..a.F.
 * 08009D4F  69 40 F0 40 00 08 61 4F F4 30 20 FF F7 24 FD 04  i@.@..aO.0 ..$..
 * 08009D5F  46 06 2C 2E D1 7C 20 FF F7 31 FD 3F 48 00 69 43  F.,..| ..1.?H.iC
 * 08009D6F  F6 DF 71 08 40 3C 49 08 61 08 46 00 69 40 F0 10  ..q.@<I.a.F.i@..
 * 08009D7F  00 08 61 38 48 08 38 05 60 4F F4 30 20 FF F7 0B  ..a8H.8.`O.0 ...
 * 08009D8F  FD 04 46 06 2C 0B D1 7C 20 FF F7 18 FD 35 48 31  ..F.,..| ....5H1
 * 08009D9F  49 08 31 08 60 4F F4 30 20 FF F7 FD FC 04 46 0A  I.1.`O.0 .....F.
 * 08009DAF  2C 10 D0 2D 48 00 69 43 F6 EF 71 08 40 2A 49 08  ,..-H.iC..q.@*I.
 * 08009DBF  61 08 E0 0A 2C 06 D0 28 48 00 69 43 F6 DF 71 08  a...,..(H.iC..q.
 * 08009DCF  40 25 49 08 61 20 46 A4 E7 2D E9 F0 43 05 46 0E  @%I.a F..-..C.F.
 * 08009DDF  46 17 46 98 46 DF F8 90 90 06 24 FF F7 4B FD 18  F.F.F.....$..K..
 * 08009DEF  B1 08 24 20 46 BD E8 F0 83 FF F7 3A FD 18 B1 DF  ..$ F......:....
 * 08009DFF  F8 78 90 A9 F1 A5 09 19 48 17 49 88 60 18 48 88  .x......H.I.`.H.
 * 08009E0F  60 7C 20 FF F7 DB FC 4F F4 30 20 FF F7 C4 FC 04  `| ....O.0 .....
 * 08009E1F  46 06 2C 4F D1 10 48 00 69 40 F0 20 00 0E 49 08  F.,O..H.i@. ..I.
 * 08009E2F  61 08 46 00 69 40 F0 40 00 08 61 4F F4 30 20 FF  a.F.i@.@..aO.0 .
 * 08009E3F  F7 B2 FC 04 46 06 2C 34 D1 7C 20 FF F7 BF FC 06  ....F.,4.| .....
 * 08009E4F  48 00 69 43 F6 DF 71 08 40 03 49 08 61 08 46 00  H.iC..q.@.I.a.F.
 * 08009E5F  69 0C E0 00 00 08 F8 FF 1F 00 20 02 40 23 01 67  i......... .@#.g
 * --- 0x08009E75-0x0800A03C (455B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 08009E75  33 FF FF A5 00 F0 FF 40 F0 10 00 08 61 45 EA 06  3......@....aE..
 * 08009E85  00 38 43 40 EA 08 00 49 EA 00 40 69 49 08 60 4F  .8C@...I..@iI.`O
 * 08009E95  F4 00 50 FF F7 85 FC 04 46 0A 2C 10 D0 66 48 00  ..P.....F.,..fH.
 * 08009EA5  69 43 F6 EF 71 08 40 63 49 08 61 08 E0 0A 2C 06  iC..q.@cI.a...,.
 * 08009EB5  D0 61 48 00 69 43 F6 DF 71 08 40 5E 49 08 61 20  .aH.iC..q.@^I.a 
 * 08009EC5  46 95 E7 2D E9 F0 47 05 46 0E 46 17 46 98 46 DF  F..-..G.F.F.F.F.
 * 08009ED5  F8 68 91 6F F4 7F 0A 06 24 FF F7 D1 FC 18 B1 08  .h.o....$.......
 * 08009EE5  24 20 46 BD E8 F0 87 FF F7 C0 FC 18 B1 DF F8 4C  $ F............L
 *   ... (Rest ausgelassen; Gesamt 455 Bytes)
 * --- 0x0800A041-0x0800A068 (39B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0800A041  00 FF FF 23 01 67 45 AB 89 EF CD 10 B5 04 46 FB  ...#.gE.......F.
 * 0800A051  48 84 42 07 D1 01 21 80 14 FE F7 D0 F8 00 21 A0  H.B...!.......!.
 * 0800A061  14 FE F7 CC F8 10 BD 30 B5 02 46 00 20 00 23 50  .......0..F. .#P
 * --- 0x0800A0A9-0x0800A0BA (17B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0800A0A9  BD 00 21 01 70 41 70 41 60 81 60 01 21 01 73 70  ..!.pApA`.`.!.sp
 * 0800A0B9  47 21 B1 82 68 42 F0 01 02 82 60 03 E0 82 68 22  G!..hB....`...h"
 * --- 0x0800A0CF-0x0800A0FE (47B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0800A0CF  47 21 B1 82 68 42 F4 80 72 82 60 03 E0 82 68 22  G!..hB..r.`...h"
 * 0800A0DF  F4 80 72 82 60 70 47 10 B5 00 23 CB B2 1A B1 44  ..r.`pG...#....D
 * 0800A0EF  68 1C 43 44 60 02 E0 44 68 9C 43 44 60 10 BD 41  h.CD`..Dh.CD`..A
 * --- 0x0800A13B-0x0800A150 (21B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0800A13B  47 01 46 00 20 8A 68 02 F4 80 02 0A B1 01 20 00  G.F. .h....... .
 * 0800A14B  E0 00 20 70 47 10 B5 0A 46 00 21 00 23 41 68 21  .. pG...F.!.#Ah!
 * --- 0x0800A167-0x0800A17E (23B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0800A167  BD 21 B1 42 68 42 F4 00 62 42 60 03 E0 42 68 22  .!.BhB..bB`..Bh"
 * 0800A177  F4 00 62 42 60 70 47 F0 B5 04 46 15 46 00 20 00  ..bB`pG...F.F. .
 * --- 0x0800A243-0x0800A25A (23B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0800A243  BD 21 B1 82 68 42 F4 80 12 82 60 03 E0 82 68 22  .!..hB....`...h"
 * 0800A253  F4 80 12 82 60 70 47 01 46 C8 6C 80 B2 70 47 21  ....`pG.F.l..pG!
 * --- 0x0800A261-0x0800A2DE (125B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0800A261  47 21 B1 42 68 42 F4 80 62 42 60 03 E0 42 68 22  G!.BhB..bB`..Bh"
 * 0800A271  F4 80 62 42 60 70 47 21 B1 42 68 42 F4 80 52 42  ..bB`pG!.BhB..RB
 * 0800A281  60 03 E0 42 68 22 F4 80 52 42 60 70 47 0A 46 00  `..Bh"..RB`pG.F.
 * 0800A291  21 81 68 21 F4 E0 41 11 43 81 60 70 47 21 B1 82  !.h!..A.C.`pG!..
 * 0800A2A1  68 42 F4 00 42 82 60 03 E0 82 68 22 F4 00 42 82  hB..B.`...h"..B.
 * 0800A2B1  60 70 47 21 B1 82 68 42 F4 02 12 82 60 03 E0 82  `pG!..hB....`...
 * 0800A2C1  68 22 F4 02 12 82 60 70 47 01 46 00 20 8A 68 02  h"....`pG.F. .h.
 * 0800A2D1  F4 00 12 0A B1 01 20 00 E0 00 20 70 47 F0 B5 04  ...... ... pG...
 * --- 0x0800A3B7-0x0800A450 (153B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0800A3B7  BD 0A 46 00 21 41 68 23 4B 19 40 11 43 41 60 70  ..F.!Ah#K.@.CA`p
 * 0800A3C7  47 41 62 82 62 70 47 0A 46 00 21 41 68 21 F0 1F  GAb.bpG.F.!Ah!..
 * 0800A3D7  01 11 43 41 60 70 47 B0 B1 17 49 08 31 09 68 41  ..CA`pG...I.1.hA
 * 0800A3E7  F4 00 01 15 4A 08 32 11 60 00 BF 17 49 09 68 41  ....J.2.`...I.hA
 * 0800A3F7  F4 00 51 15 4A 11 60 00 BF 00 BF 11 46 09 68 41  ..Q.J.`.....F.hA
 * 0800A407  F4 80 11 11 60 16 E0 0C 49 08 31 09 68 21 F4 00  ....`...I.1.h!..
 * 0800A417  01 09 4A 08 32 11 60 00 BF 0B 49 09 68 21 F4 00  ..J.2.`...I.h!..
 * 0800A427  51 09 4A 11 60 00 BF 00 BF 11 46 09 68 21 F4 80  Q.J.`.....F.h!..
 * 0800A437  11 11 60 00 BF 70 47 00 00 00 08 02 40 FF FE F0  ..`..pG.....@...
 * 0800A447  FF FD F7 F1 FF FF FD 3F FF 24 18 00 40 02 46 00  .......?.$..@.F.
 * --- 0x0800A491-0x0800A51A (137B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0800A491  BD 00 22 0A 12 7F 23 93 43 03 60 70 47 02 46 00  .."...#.C.`pG.F.
 * 0800A4A1  20 CB 79 23 B1 D3 6D 43 F0 08 03 D3 65 03 E0 D3   .y#..mC....e...
 * 0800A4B1  6D 23 F0 08 03 D3 65 90 6D 0B 78 13 B1 40 F4 80  m#....e.m.x..@..
 * 0800A4C1  60 01 E0 20 F4 80 60 4B 78 13 B1 40 F4 00 70 01  `.. ..`Kx..@..p.
 * 0800A4D1  E0 20 F4 00 70 8B 78 13 B1 40 F4 80 70 01 E0 20  . ..p.x..@..p.. 
 * 0800A4E1  F4 80 70 0B 79 13 B1 40 F0 08 00 01 E0 20 F0 08  ..p.y..@..... ..
 * 0800A4F1  00 4B 79 13 B1 40 F0 04 00 01 E0 20 F0 04 00 20  .Ky..@..... ... 
 * 0800A501  F0 03 00 8B 79 18 43 20 F0 10 00 CB 78 01 2B 01  ....y.C ....x.+.
 * 0800A511  D1 40 F0 10 00 90 65 70 47 02 46 00 20 93 6D 0B  .@....epG.F. .m.
 * --- 0x0800A52B-0x0800A534 (9B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0800A52B  47 0A 46 00 21 81 6D 12 B1 41 F0 80 01 01 E0 21  G.F.!.m..A.....!
 * --- 0x0800A541-0x0800A552 (17B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0800A541  47 0A 46 00 21 81 6D 21 F0 03 01 11 43 81 65 70  G.F.!.m!....C.ep
 * 0800A551  47 70 B5 05 46 0C 46 45 B9 00 21 4F F4 80 70 FD  Gp..F.FE..!O..p.
 * --- 0x0800A7C9-0x0800A856 (141B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0800A7C9  47 21 B1 02 68 42 F4 80 32 02 60 03 E0 02 68 22  G!..hB..2.`...h"
 * 0800A7D9  F4 80 32 02 60 70 47 E1 B1 02 68 42 F0 80 02 02  ..2.`pG...hB....
 * 0800A7E9  60 4F F4 C2 72 12 58 42 F4 80 73 4F F4 C2 72 13  `O..r.XB..sO..r.
 * 0800A7F9  50 4F F4 CA 72 12 58 42 F4 80 73 4F F4 CA 72 13  PO..r.XB..sO..r.
 * 0800A809  50 4F F4 D2 72 12 58 42 F4 80 73 4F F4 D2 72 13  PO..r.XB..sO..r.
 * 0800A819  50 1B E0 02 68 22 F0 80 02 02 60 4F F4 C2 72 12  P...h"....`O..r.
 * 0800A829  58 22 F4 80 73 4F F4 C2 72 13 50 4F F4 CA 72 12  X"..sO..r.PO..r.
 * 0800A839  58 22 F4 80 73 4F F4 CA 72 13 50 4F F4 D2 72 12  X"..sO..r.PO..r.
 * 0800A849  58 22 F4 80 73 4F F4 D2 72 13 50 70 47 10 B5 02  X"..sO..r.PpG...
 * --- 0x0800AAAF-0x0800AAC8 (25B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0800AAAF  E0 00 66 00 40 03 00 00 04 00 03 00 08 00 00 03  ..f.@...........
 * 0800AABF  10 00 01 00 08 00 01 FF F7 D3 72 00 F5 D8 73 03  ..........r...s.
 * --- 0x0800AC15-0x0800AC86 (113B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0800AC15  BD 01 46 00 20 0A 68 22 F0 01 02 42 F0 02 02 0A  ..F. .h"...B....
 * 0800AC25  60 4A 68 02 F0 03 02 02 2A 00 D1 01 20 70 47 01  `Jh.....*... pG.
 * 0800AC35  46 4F F6 FF 72 00 20 0B 68 23 F0 02 03 0B 60 00  FO..r. .h#....`.
 * 0800AC45  E0 52 1E 4B 68 03 F0 02 03 02 2B 01 D1 00 2A F7  .R.Kh.....+...*.
 * 0800AC55  D1 4B 68 03 F0 02 03 02 2B 00 D0 01 20 70 47 01  .Kh.....+... pG.
 * 0800AC65  46 00 20 8A 69 02 F0 70 00 70 47 01 46 00 20 8A  F. .i..p.pG.F. .
 * 0800AC75  69 10 0E 70 47 01 46 00 20 8A 69 C2 F3 07 40 70  i..pG.F. .i...@p
 * 0800AC85  47 1A B1 43 69 0B 43 43 61 02 E0 43 69 8B 43 43  G..Ci.CCa..Ci.CC
 * --- 0x0800AE71-0x0800AF1C (171B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0800AE71  BD B1 F5 00 7F 3A D0 0F DC 20 29 28 D0 06 DC 01  .....:... )(....
 * 0800AE81  29 1C D0 04 29 1D D0 08 29 40 D1 1D E0 40 29 21  )...)...)@...@)!
 * 0800AE91  D0 B1 F5 80 7F 3A D1 26 E0 B1 F5 00 4F 31 D0 06  .....:.&....O1..
 * 0800AEA1  DC B1 F5 80 6F 25 D0 B1 F5 00 6F 2F D1 24 E0 B1  ....o%....o/.$..
 * 0800AEB1  F5 80 3F 12 D0 B1 F5 00 3F 28 D1 11 E0 16 4A 82  ..?.....?(....J.
 * 0800AEC1  60 25 E0 08 22 C2 60 22 E0 10 22 C2 60 1F E0 08  `%..".`"..".`...
 * 0800AED1  22 02 61 1C E0 10 22 02 61 19 E0 08 22 42 60 16  ".a...".a..."B`.
 * 0800AEE1  E0 10 22 42 60 13 E0 04 22 42 60 10 E0 04 22 42  .."B`..."B`..."B
 * 0800AEF1  60 0D E0 04 22 42 60 0A E0 00 22 82 61 04 22 42  `..."B`...".a."B
 * 0800AF01  60 05 E0 00 22 82 61 04 22 42 60 00 E0 00 BF 00  `...".a."B`.....
 * 0800AF11  BF 70 47 70 00 F0 30 01 01 01 00 10 B5 04 46 F7  .pGp..0.......F.
 * --- 0x0800B02B-0x0800B04A (31B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0800B02B  83 41 F2 88 31 01 60 00 21 81 80 4B F6 FF 71 C1  .A..1.`.!..K..q.
 * 0800B03B  80 00 21 01 81 41 81 4F F4 80 41 81 81 70 47 21  ..!..A.O..A..pG!
 * --- 0x0800B079-0x0800B092 (25B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0800B079  47 21 B1 82 88 42 F4 80 52 82 80 04 E0 82 88 4E  G!...B..R......N
 * 0800B089  F6 FF 73 1A 40 82 80 70 47 21 B1 02 88 42 F4 80  ..s.@..pG!...B..
 * --- 0x0800B0D9-0x0800B120 (71B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0800B0D9  47 0A 46 00 21 81 89 4F F6 01 73 19 40 02 F0 FE  G.F.!..O..s.@...
 * 0800B0E9  03 19 43 81 81 70 47 21 B1 82 89 42 F0 01 02 82  ..C..pG!...B....
 * 0800B0F9  81 04 E0 82 89 4F F6 FE 73 1A 40 82 81 70 47 21  .....O..s.@..pG!
 * 0800B109  B1 02 88 42 F0 40 02 02 80 04 E0 02 88 4F F6 BF  ...B.@.......O..
 * 0800B119  73 1A 40 02 80 70 47 1A B1 83 88 0B 43 83 80 02  s.@..pG.....C...
 * --- 0x0800B165-0x0800B180 (27B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0800B165  BD 21 B1 02 88 42 F4 00 42 02 80 03 E0 02 88 C2  .!...B..B.......
 * 0800B175  F3 0E 02 02 80 70 47 B1 F5 00 6F 04 D1 02 88 42  .....pG...o....B
 * --- 0x0800B197-0x0800B254 (189B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0800B197  47 B1 F5 00 5F 04 D1 02 88 42 F4 00 52 02 80 04  G..._....B..R...
 * 0800B1A7  E0 02 88 4D F6 FF 73 1A 40 02 80 70 47 21 B1 02  ...M..s.@..pG!..
 * 0800B1B7  88 42 F4 80 52 02 80 04 E0 02 88 4E F6 FF 73 1A  .B..R......N..s.
 * 0800B1C7  40 02 80 70 47 B1 F5 00 6F 04 D1 02 88 42 F4 00  @..pG...o....B..
 * 0800B1D7  62 02 80 04 E0 02 88 4F F2 FF 73 1A 40 02 80 70  b......O..s.@..p
 * 0800B1E7  47 21 B1 02 88 42 F0 20 02 02 80 04 E0 02 88 4F  G!...B. .......O
 * 0800B1F7  F6 DF 73 1A 40 02 80 70 47 01 46 08 8B 00 12 70  ..s.@..pG.F....p
 * 0800B207  47 21 B1 02 88 42 F0 10 02 02 80 04 E0 02 88 4F  G!...B.........O
 * 0800B217  F6 EF 73 1A 40 02 80 70 47 21 B9 02 88 42 F0 80  ..s.@..pG!...B..
 * 0800B227  02 02 80 04 E0 02 88 4F F6 7F 73 1A 40 02 80 70  .......O..s.@..p
 * 0800B237  47 B1 F5 80 4F 05 D0 82 8B 4B F6 FF 73 1A 40 82  G...O....K..s.@.
 * 0800B247  83 03 E0 82 8B 42 F4 80 42 82 83 70 47 70 B5 02  .....B..B..pGp..
 * --- 0x0800B313-0x0800B458 (325B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0800B313  BD 00 22 21 F0 7F 42 D3 43 83 82 70 47 01 68 4F  .."!..B.C..pG.hO
 * 0800B323  F6 FE 72 11 40 01 60 00 21 01 60 41 60 81 60 C1  ..r.@.`.!.`A`.`.
 * 0800B333  60 67 49 88 42 08 D1 66 49 08 39 49 68 41 F0 0F  `gI.B..fI.9IhA..
 * 0800B343  01 63 4A 08 3A 51 60 59 E0 61 49 14 31 88 42 08  .cJ.:Q`Y.aI.1.B.
 * 0800B353  D1 5F 49 08 39 49 68 41 F0 F0 01 5D 4A 08 3A 51  ._I.9IhA...]J.:Q
 * 0800B363  60 4C E0 5B 49 28 31 88 42 08 D1 59 49 08 39 49  `L.[I(1.B..YI.9I
 * 0800B373  68 41 F4 70 61 56 4A 08 3A 51 60 3F E0 54 49 3C  hA.paVJ.:Q`?.TI<
 * 0800B383  31 88 42 08 D1 52 49 08 39 49 68 41 F4 70 41 50  1.B..RI.9IhA.pAP
 * 0800B393  4A 08 3A 51 60 32 E0 4E 49 50 31 88 42 08 D1 4C  J.:Q`2.NIP1.B..L
 * 0800B3A3  49 08 39 49 68 41 F4 70 21 49 4A 08 3A 51 60 25  I.9IhA.p!IJ.:Q`%
 * 0800B3B3  E0 47 49 64 31 88 42 08 D1 45 49 08 39 49 68 41  .GId1.B..EI.9IhA
 * 0800B3C3  F4 70 01 43 4A 08 3A 51 60 18 E0 41 49 78 31 88  .p.CJ.:Q`..AIx1.
 * 0800B3D3  42 08 D1 3F 49 08 39 49 68 41 F0 70 61 3C 4A 08  B..?I.9IhA.pa<J.
 * 0800B3E3  3A 51 60 0B E0 3A 49 8C 31 88 42 07 D1 38 49 08  :Q`..:I.1.B..8I.
 * 0800B3F3  39 49 68 41 F0 70 41 36 4A 08 3A 51 60 70 47 10  9IhA.pA6J.:Q`pG.
 * 0800B403  B5 00 22 02 68 47 F6 F0 73 9A 43 0C 6A 8B 68 23  ..".hG..s.C.j.h#
 * 0800B413  43 0C 69 23 43 4C 69 23 43 8C 69 23 43 CC 69 23  C.i#CLi#C.i#C.i#
 * 0800B423  43 4C 6A 23 43 8C 6A 23 43 1A 43 02 60 CB 68 43  CLj#C.j#C.C.`.hC
 * 0800B433  60 0B 68 83 60 4B 68 C3 60 10 BD 00 21 01 60 41  `.h.`Kh.`...!.`A
 * 0800B443  60 81 60 C1 60 01 61 41 61 81 61 C1 61 01 62 41  `.`.`.aAa.a.a.bA
 * 0800B453  62 81 62 70 47 21 B1 02 68 42 F0 01 02 02 60 04  b.bpG!..hB....`.
 * --- 0x0800B46F-0x0800B48E (31B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0800B46F  47 1A B1 03 68 0B 43 03 60 02 E0 03 68 8B 43 03  G...h.C.`...h.C.
 * 0800B47F  60 70 47 41 60 70 47 01 46 48 68 80 B2 70 47 10  `pGA`pG.FHh..pG.
 * --- 0x0800B4C1-0x0800B4D8 (23B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0800B4C1  BD 48 60 70 47 10 B5 0B B1 10 61 01 E0 00 24 14  .H`pG.....a...$.
 * 0800B4D1  61 10 BD 08 00 02 40 70 47 00 BF FE E7 00 BF FE  a.....@pG.......
 * --- 0x0800B81F-0x0800B87C (93B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0800B81F  BD 10 B5 10 F0 96 FA 10 BD 00 38 01 40 40 05 00  ..........8.@@..
 * 0800B82F  20 88 1F 00 20 04 00 00 20 0C 07 00 20 05 00 00   ... ... ... ...
 * 0800B83F  20 8E 07 00 20 00 44 00 40 42 05 00 20 50 20 00   ... .D.@B.. P .
 * 0800B84F  20 06 00 00 20 20 07 00 20 07 00 00 20 2C 0E 00   ...  .. ... ,..
 * 0800B85F  20 00 48 00 40 44 05 00 20 18 21 00 20 08 00 00   .H.@D.. .!. ...
 * 0800B86F  20 2E 07 00 20 09 00 00 20 01 0F 00 20 01 E0 10   ... ... ... ...
 * --- 0x0800BE0B-0x0800BEC2 (183B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0800BE0B  E0 D4 02 00 20 D8 02 00 20 A1 02 00 20 D9 02 00  .... ... ... ...
 * 0800BE1B  20 A4 02 00 20 A5 02 00 20 A6 02 00 20 B9 02 00   ... ... ... ...
 * 0800BE2B  20 C6 02 00 20 C7 02 00 20 AD 02 00 20 A7 02 00   ... ... ... ...
 * 0800BE3B  20 B3 02 00 20 C0 02 00 20 BA 02 00 20 0C 03 00   ... ... ... ...
 * 0800BE4B  20 A4 03 00 20 51 00 00 20 52 00 00 20 41 54 2B   ... Q.. R.. AT+
 * 0800BE5B  46 43 3D 31 0D 0A 00 00 00 04 04 00 20 CD 03 00  FC=1........ ...
 * 0800BE6B  20 41 54 2B 4C 45 4E 41 4D 45 3D 31 32 33 34 35   AT+LENAME=12345
 * 0800BE7B  36 37 38 39 30 31 32 33 34 35 36 37 38 39 0D 0A  67890123456789..
 * 0800BE8B  00 4F 00 00 20 EE 03 00 20 4C 00 00 20 50 00 00  .O.. ... L.. P..
 * 0800BE9B  20 F8 03 00 20 F0 03 00 20 F4 03 00 20 EA 0C 00   ... ... ... ...
 * 0800BEAB  20 42 07 00 20 4D 00 00 20 F9 03 00 20 ED 03 00   B.. M.. ... ...
 * 0800BEBB  20 A1 03 00 20 A0 03 00 20 BD 08 00 20 AC 0D 00   ... ... ... ...
 * --- 0x0800C283-0x0800C294 (17B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0800C283  F0 08 10 34 3C 44 4C 54 5C 64 6C 75 7D 85 8D 95  ...4<DLT\dlu}...
 * 0800C293  9D FF F7 C7 FF 13 48 00 78 40 1C 12 49 08 70 96  ......H.x@..I.p.
 * --- 0x0800C2B3-0x0800C2EC (57B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0800C2B3  E0 B0 0D 00 20 7B 0D 00 20 6B 0D 00 20 0B 0D 00  .... {.. k.. ...
 * 0800C2C3  20 A1 02 00 20 0B 0E 00 20 FB 0D 00 20 9B 0D 00   ... ... ... ...
 * 0800C2D3  20 EA 0D 00 20 D9 0D 00 20 8A 0D 00 20 C8 0D 00   ... ... ... ...
 * 0800C2E3  20 B8 0D 00 20 FC 03 00 20 FF F7 64 FE FE 48 00   ... ... ..d..H.
 * --- 0x0800C6E9-0x0800C764 (123B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0800C6E9  E0 00 00 FC 03 00 20 C7 03 00 20 A8 03 00 20 74  ...... ... ... t
 * 0800C6F9  19 CF 00 30 05 00 20 0C 03 00 20 A5 03 00 20 A6  ...0.. ... ... .
 * 0800C709  03 00 20 CD 03 00 20 A4 03 00 20 7B 07 00 20 8A  .. ... ... {.. .
 * 0800C719  0D 00 20 42 07 00 20 9B 0D 00 20 11 00 00 20 AC  .. B.. ... ... .
 * 0800C729  0D 00 20 12 00 00 20 13 00 00 20 0C 00 00 20 19  .. ... ... ... .
 * 0800C739  00 00 20 1A 00 00 20 1B 00 00 20 14 00 00 20 2C  .. ... ... ... ,
 * 0800C749  00 00 20 2E 03 00 20 B8 0D 00 20 2F 03 00 20 30  .. ... ... /.. 0
 * 0800C759  03 00 20 31 03 00 20 32 03 00 20 8C F8 04 70 FE  .. 1.. 2.. ...p.
 * --- 0x0800CB61-0x0800CD1C (443B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0800CB61  E0 00 00 33 03 00 20 34 03 00 20 35 03 00 20 36  ...3.. 4.. 5.. 6
 * 0800CB71  03 00 20 37 03 00 20 38 03 00 20 39 03 00 20 3A  .. 7.. 8.. 9.. :
 * 0800CB81  03 00 20 3B 03 00 20 3C 03 00 20 3D 03 00 20 5E  .. ;.. <.. =.. ^
 * 0800CB91  03 00 20 C8 0D 00 20 5F 03 00 20 60 03 00 20 61  .. ... _.. `.. a
 * 0800CBA1  03 00 20 62 03 00 20 63 03 00 20 64 03 00 20 65  .. b.. c.. d.. e
 * 0800CBB1  03 00 20 66 03 00 20 67 03 00 20 69 03 00 20 6A  .. f.. g.. i.. j
 * 0800CBC1  03 00 20 6B 03 00 20 6C 03 00 20 6D 03 00 20 6E  .. k.. l.. m.. n
 * 0800CBD1  03 00 20 6F 03 00 20 D9 0D 00 20 70 03 00 20 71  .. o.. ... p.. q
 *   ... (Rest ausgelassen; Gesamt 443 Bytes)
 * --- 0x0800D141-0x0800D1EC (171B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0800D141  81 00 00 A3 02 00 20 0B 0D 00 20 A1 02 00 20 A4  ...... ... ... .
 * 0800D151  02 00 20 A5 02 00 20 A6 02 00 20 AD 02 00 20 A7  .. ... ... ... .
 * 0800D161  02 00 20 B3 02 00 20 B9 02 00 20 BA 02 00 20 C0  .. ... ... ... .
 * 0800D171  02 00 20 C6 02 00 20 C7 02 00 20 07 03 00 20 DB  .. ... ... ... .
 * 0800D181  02 00 20 6B 0D 00 20 DC 02 00 20 EC 03 00 20 34  .. k.. ... ... 4
 * 0800D191  00 00 20 36 00 00 20 32 00 00 20 CD 02 00 20 DE  .. 6.. 2.. ... .
 * 0800D1A1  02 00 20 E0 02 00 20 E2 02 00 20 E4 02 00 20 E6  .. ... ... ... .
 * 0800D1B1  02 00 20 E7 02 00 20 E8 02 00 20 EA 02 00 20 EC  .. ... ... ... .
 * 0800D1C1  02 00 20 EE 02 00 20 F4 02 00 20 F8 02 00 20 7B  .. ... ... ... {
 * 0800D1D1  0D 00 20 FE 02 00 20 00 03 00 20 04 03 00 20 CE  .. ... ... ... .
 * 0800D1E1  02 00 20 CF 02 00 20 D0 02 00 20 0F B4 38 B5 00  .. ... ... ..8..
 * --- 0x0800D613-0x0800D6B4 (161B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0800D613  E0 CE 02 00 20 CF 02 00 20 D0 02 00 20 51 00 00  .... ... ... Q..
 * 0800D623  20 EA 0C 00 20 09 03 00 20 D4 02 00 20 D8 02 00   ... ... ... ...
 * 0800D633  20 A1 02 00 20 D9 02 00 20 0A 03 00 20 A2 02 00   ... ... ... ...
 * 0800D643  20 A3 02 00 20 8A 0C 00 20 A4 02 00 20 A5 02 00   ... ... ... ...
 * 0800D653  20 A6 02 00 20 A7 02 00 20 B3 02 00 20 B9 02 00   ... ... ... ...
 * 0800D663  20 BA 02 00 20 C6 02 00 20 C7 02 00 20 DA 02 00   ... ... ... ...
 * 0800D673  20 AD 02 00 20 C0 02 00 20 08 03 00 20 12 03 00   ... ... ... ...
 * 0800D683  20 80 0C 00 20 B6 00 00 20 CE 00 00 20 E6 00 00   ... ... ... ...
 * 0800D693  20 FE 00 00 20 4E 02 00 20 66 02 00 20 7E 02 00   ... N.. f.. ~..
 * 0800D6A3  20 96 02 00 20 70 0C 00 20 2E 01 00 20 46 01 00   ... p.. ... F..
 * 0800D6B3  20 F8 49 08 80 F8 48 C0 88 4F F6 FF 71 88 42 03   .I...H..O..q.B.
 * --- 0x0800DA79-0x0800DA84 (11B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0800DA79  F0 9F 53 5A 61 6B 9F 9F 9F 72 00 12 28 7B D0 18  ..SZak...r..({..
 * --- 0x0800DA97-0x0800DB20 (137B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0800DA97  E0 16 01 00 20 70 0C 00 20 8E 01 00 20 A6 01 00  .... p.. ... ...
 * 0800DAA7  20 76 01 00 20 00 02 00 20 D0 01 00 20 B1 03 00   v.. ... ... ...
 * 0800DAB7  20 2C 03 00 20 1F 03 00 20 2B 03 00 20 21 03 00   ,.. ... +.. !..
 * 0800DAC7  20 24 03 00 20 22 03 00 20 25 03 00 20 23 03 00   $.. ".. %.. #..
 * 0800DAD7  20 26 03 00 20 2A 03 00 20 20 03 00 20 28 03 00   &.. *..  .. (..
 * 0800DAE7  20 B0 03 00 20 61 0C 00 20 9C 00 00 20 9E 00 00   ... a.. ... ...
 * 0800DAF7  20 55 0C 00 20 7C 03 00 20 7D 03 00 20 FC 02 00   U.. |.. }.. ...
 * 0800DB07  20 8B 00 00 20 A8 03 00 20 A4 03 00 20 A2 03 00   ... ... ... ...
 * 0800DB17  20 A3 03 00 20 4D 0A 00 20 05 98 00 90 01 A8 0F   ... M.. .......
 * --- 0x0800DFC3-0x0800E074 (177B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0800DFC3  E0 A3 03 00 20 A2 03 00 20 4D 0A 00 20 8E 07 00  .... ... M.. ...
 * 0800DFD3  20 E8 03 00 20 D4 02 00 20 D8 02 00 20 A0 03 00   ... ... ... ...
 * 0800DFE3  20 A1 03 00 20 BD 08 00 20 DD 0B 00 20 8A 0D 00   ... ... ... ...
 * 0800DFF3  20 2E 03 00 20 B8 0D 00 20 2F 03 00 20 30 03 00   ... ... /.. 0..
 * 0800E003  20 31 03 00 20 32 03 00 20 33 03 00 20 34 03 00   1.. 2.. 3.. 4..
 * 0800E013  20 35 03 00 20 36 03 00 20 37 03 00 20 38 03 00   5.. 6.. 7.. 8..
 * 0800E023  20 39 03 00 20 3A 03 00 20 3B 03 00 20 3C 03 00   9.. :.. ;.. <..
 * 0800E033  20 3D 03 00 20 5E 03 00 20 C8 0D 00 20 5F 03 00   =.. ^.. ... _..
 * 0800E043  20 60 03 00 20 61 03 00 20 62 03 00 20 63 03 00   `.. a.. b.. c..
 * 0800E053  20 64 03 00 20 65 03 00 20 66 03 00 20 67 03 00   d.. e.. f.. g..
 * 0800E063  20 68 03 00 20 69 03 00 20 6A 03 00 20 6B 03 00   h.. i.. j.. k..
 * 0800E073  20 63 73 FE 4B 1C 78 FE 4B 9C 73 FE 4B 1B 78 FC   cs.K.x.K.s.K.x.
 * --- 0x0800E46F-0x0800E5AE (319B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0800E46F  E0 6C 03 00 20 C8 0D 00 20 6D 03 00 20 6E 03 00  .l.. ... m.. n..
 * 0800E47F  20 6F 03 00 20 D9 0D 00 20 70 03 00 20 71 03 00   o.. ... p.. q..
 * 0800E48F  20 72 03 00 20 73 03 00 20 74 03 00 20 75 03 00   r.. s.. t.. u..
 * 0800E49F  20 76 03 00 20 7B 03 00 20 7C 03 00 20 7D 03 00   v.. {.. |.. }..
 * 0800E4AF  20 7E 03 00 20 80 03 00 20 9F 02 00 20 EA 0D 00   ~.. ... ... ...
 * 0800E4BF  20 81 03 00 20 82 03 00 20 83 03 00 20 84 03 00   ... ... ... ...
 * 0800E4CF  20 85 03 00 20 86 03 00 20 87 03 00 20 88 03 00   ... ... ... ...
 * 0800E4DF  20 89 03 00 20 8A 03 00 20 8B 03 00 20 8C 03 00   ... ... ... ...
 * 0800E4EF  20 8D 03 00 20 8E 03 00 20 90 03 00 20 3E 03 00   ... ... ... >..
 * 0800E4FF  20 FB 0D 00 20 3F 03 00 20 40 03 00 20 41 03 00   ... ?.. @.. A..
 * 0800E50F  20 42 03 00 20 43 03 00 20 44 03 00 20 45 03 00   B.. C.. D.. E..
 * 0800E51F  20 46 03 00 20 47 03 00 20 48 03 00 20 49 03 00   F.. G.. H.. I..
 * 0800E52F  20 4A 03 00 20 4B 03 00 20 4C 03 00 20 4D 03 00   J.. K.. L.. M..
 * 0800E53F  20 4E 03 00 20 0B 0E 00 20 4F 03 00 20 50 03 00   N.. ... O.. P..
 * 0800E54F  20 51 03 00 20 52 03 00 20 53 03 00 20 54 03 00   Q.. R.. S.. T..
 * 0800E55F  20 55 03 00 20 56 03 00 20 57 03 00 20 58 03 00   U.. V.. W.. X..
 * 0800E56F  20 59 03 00 20 5A 03 00 20 5B 03 00 20 5C 03 00   Y.. Z.. [.. \..
 * 0800E57F  20 5D 03 00 20 8E 01 00 20 1C 0E 00 20 2E 01 00   ].. ... ... ...
 * 0800E58F  20 A6 01 00 20 46 01 00 20 76 01 00 20 16 01 00   ... F.. v.. ...
 * 0800E59F  20 D0 01 00 20 00 02 00 20 E6 00 00 20 BF 03 00   ... ... ... ...
 * --- 0x0800E9FF-0x0800EA34 (53B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0800E9FF  BD B8 0D 00 20 EA 03 00 20 FB 0D 00 20 0B 0E 00  .... ... ... ...
 * 0800EA0F  20 1C 48 0F 00 C8 0D 00 20 D9 0D 00 20 7B 03 00   .H..... ... {..
 * 0800EA1F  20 EA 0D 00 20 0B 0D 00 20 A1 02 00 20 06 03 00   ... ... ... ...
 * 0800EA2F  20 6B 0D 00 20 10 B5 BE 48 00 78 10 B1 01 28 0E   k.. ...H.x...(.
 * --- 0x0800EB1B-0x0800EB50 (53B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0800EB1B  BD 10 B5 86 B0 00 24 55 20 8D F8 04 00 61 20 8D  ......$U ....a .
 * 0800EB2B  F8 05 00 10 22 82 49 0D F1 06 00 FC F7 2B FF 10  ....".I......+..
 * 0800EB3B  24 06 E0 FF 22 0D F1 06 00 61 1C 42 54 60 1C C4  $..."....a.BT`..
 * 0800EB4B  B2 10 2C F6 D3 13 21 01 A8 FD F7 27 F9 8D F8 17  ..,...!....'....
 * --- 0x0800EBBB-0x0800EDA0 (485B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0800EBBB  BD 70 47 70 47 70 47 70 47 5F 48 C0 78 FF 28 03  .pGpGpGpG_H.x.(.
 * 0800EBCB  D0 5D 48 C0 78 5D 49 08 70 5B 48 00 79 FF 28 03  .]H.x]I.p[H.y.(.
 * 0800EBDB  D0 59 48 00 79 5A 49 08 70 70 47 FF 28 1F D0 00  .YH.yZI.ppG.(...
 * 0800EBEB  F0 01 01 58 4A 11 70 00 F0 02 01 57 4A 11 70 00  ...XJ.p....WJ.p.
 * 0800EBFB  F0 04 01 56 4A 11 70 00 F0 08 01 55 4A 11 70 00  ...VJ.p....UJ.p.
 * 0800EC0B  F0 10 01 54 4A 11 70 00 F0 20 01 53 4A 11 70 00  ...TJ.p.. .SJ.p.
 * 0800EC1B  F0 40 01 52 4A 11 70 00 F0 80 01 51 4A 11 70 70  .@.RJ.p....QJ.pp
 * 0800EC2B  47 10 B5 45 48 40 79 FF 28 07 D0 43 48 80 79 FF  G..EH@y.(..CH.y.
 *   ... (Rest ausgelassen; Gesamt 485 Bytes)
 * --- 0x0800F1A3-0x0800F2C0 (285B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0800F1A3  E0 30 10 00 20 C4 11 00 20 58 13 00 20 7F 13 00  .0.. ... X.. ...
 * 0800F1B3  20 92 13 00 20 A6 13 00 20 A0 02 00 20 A1 02 00   ... ... ... ...
 * 0800F1C3  20 A2 02 00 20 A3 02 00 20 A4 02 00 20 A5 02 00   ... ... ... ...
 * 0800F1D3  20 A6 02 00 20 B9 02 00 20 C6 02 00 20 C7 02 00   ... ... ... ...
 * 0800F1E3  20 AD 02 00 20 A7 02 00 20 B3 02 00 20 C0 02 00   ... ... ... ...
 * 0800F1F3  20 BA 02 00 20 0B 03 00 20 0E 03 00 20 0F 03 00   ... ... ... ...
 * 0800F203  20 10 03 00 20 11 03 00 20 E4 02 00 20 E2 02 00   ... ... ... ...
 * 0800F213  20 CD 02 00 20 14 03 00 20 CE 02 00 20 CF 02 00   ... ... ... ...
 * 0800F223  20 D0 02 00 20 98 03 00 20 0A 04 00 20 B3 13 00   ... ... ... ...
 * 0800F233  20 68 07 00 20 A4 00 00 20 77 03 00 20 78 03 00   h.. ... w.. x..
 * 0800F243  20 79 03 00 20 7A 03 00 20 76 03 00 20 75 03 00   y.. z.. v.. u..
 * 0800F253  20 F0 02 00 20 1A 04 00 20 04 03 00 20 1C 04 00   ... ... ... ...
 * 0800F263  20 63 03 00 20 62 03 00 20 90 03 00 20 E0 93 04   c.. b.. ... ...
 * 0800F273  00 9F 02 00 20 6D 03 00 20 F2 02 00 20 86 03 00  .... m.. ... ...
 * 0800F283  20 84 03 00 20 87 03 00 20 85 03 00 20 80 03 00   ... ... ... ...
 * 0800F293  20 82 03 00 20 8D 03 00 20 8E 03 00 20 89 03 00   ... ... ... ...
 * 0800F2A3  20 88 03 00 20 64 00 00 20 FC 02 00 20 EC 02 00   ... d.. ... ...
 * 0800F2B3  20 16 03 00 20 18 03 00 20 F8 02 00 20 04 DD FD   ... ... ... ...
 * --- 0x0800F5F3-0x0800F5FE (11B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0800F5F3  F0 05 06 14 D0 E9 FA 60 F9 60 F8 B6 E1 3D 48 00  .......`.`...=H.
 * --- 0x0800F6B7-0x0800F720 (105B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0800F6B7  E0 FC 02 00 20 F8 02 00 20 FA 02 00 20 E8 02 00  .... ... ... ...
 * 0800F6C7  20 DE 02 00 20 12 04 00 20 18 04 00 20 C0 13 00   ... ... ... ...
 * 0800F6D7  20 F4 02 00 20 F6 02 00 20 10 03 00 20 A2 02 00   ... ... ... ...
 * 0800F6E7  20 11 03 00 20 A3 02 00 20 9A 03 00 20 99 03 00   ... ... ... ...
 * 0800F6F7  20 09 03 00 20 08 03 00 20 90 03 00 20 12 03 00   ... ... ... ...
 * 0800F707  20 4C 00 00 20 1B 03 00 20 06 03 00 20 DA 02 00   L.. ... ... ...
 * 0800F717  20 07 03 00 20 0E 03 00 20 0F 03 00 20 14 03 00   ... ... ... ...
 * --- 0x0800FB79-0x0800FBF0 (119B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0800FB79  E0 00 00 0D 03 00 20 7F 13 00 20 DA 02 00 20 09  ...... ... ... .
 * 0800FB89  03 00 20 08 03 00 20 A3 02 00 20 A2 02 00 20 A4  .. ... ... ... .
 * 0800FB99  02 00 20 A5 02 00 20 A6 02 00 20 A7 02 00 20 AD  .. ... ... ... .
 * 0800FBA9  02 00 20 B3 02 00 20 B9 02 00 20 BA 02 00 20 C0  .. ... ... ... .
 * 0800FBB9  02 00 20 C6 02 00 20 C7 02 00 20 12 03 00 20 1E  .. ... ... ... .
 * 0800FBC9  03 00 20 14 03 00 20 CD 02 00 20 08 04 00 20 2C  .. ... ... ... ,
 * 0800FBD9  0E 00 20 A6 13 00 20 11 03 00 20 0E 04 00 20 10  .. ... ... ... .
 * 0800FBE9  03 00 20 10 04 00 20 41 F2 88 30 FE 49 08 80 40  .. ... A..0.I..@
 * --- 0x0800FFEF-0x0801007C (141B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0800FFEF  E0 10 04 00 20 0E 04 00 20 11 03 00 20 10 03 00  .... ... ... ...
 * 0800FFFF  20 01 0F 00 20 0E 03 00 20 0C 04 00 20 7F 13 00   ... ... ... ...
 * 0801000F  20 B3 13 00 20 0A 04 00 20 C4 11 00 20 30 10 00   ... ... ... 0..
 * 0801001F  20 09 03 00 20 A1 02 00 20 AD 02 00 20 B3 02 00   ... ... ... ...
 * 0801002F  20 C0 02 00 20 6D 03 00 20 0A 03 00 20 A2 02 00   ... m.. ... ...
 * 0801003F  20 B9 02 00 20 13 03 00 20 CA 02 00 20 C8 02 00   ... ... ... ...
 * 0801004F  20 0D 03 00 20 90 03 00 20 9A 03 00 20 CD 02 00   ... ... ... ...
 * 0801005F  20 14 03 00 20 92 13 00 20 A4 02 00 20 A5 02 00   ... ... ... ...
 * 0801006F  20 A6 02 00 20 C6 02 00 20 C7 02 00 20 C6 73 13   ... ... ... .s.
 * --- 0x08010463-0x080104E0 (125B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 08010463  E0 92 13 00 20 FA 10 00 20 09 03 00 20 A1 02 00  .... ... ... ...
 * 08010473  20 AD 02 00 20 B3 02 00 20 C0 02 00 20 6D 03 00   ... ... ... m..
 * 08010483  20 0A 03 00 20 A2 02 00 20 B9 02 00 20 13 03 00   ... ... ... ...
 * 08010493  20 CA 02 00 20 C8 02 00 20 0D 03 00 20 90 03 00   ... ... ... ...
 * 080104A3  20 9A 03 00 20 CD 02 00 20 14 03 00 20 A4 02 00   ... ... ... ...
 * 080104B3  20 A5 02 00 20 A6 02 00 20 C6 02 00 20 C7 02 00   ... ... ... ...
 * 080104C3  20 CE 02 00 20 CF 02 00 20 D0 02 00 20 A7 02 00   ... ... ... ...
 * 080104D3  20 BA 02 00 20 A3 02 00 20 E7 02 00 20 04 F0 DF   ... ... ... ...
 * --- 0x080108BD-0x08010990 (211B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 080108BD  E0 67 E0 90 03 00 20 9A 03 00 20 CD 02 00 20 14  .g.... ... ... .
 * 080108CD  03 00 20 92 13 00 20 A4 02 00 20 A5 02 00 20 A6  .. ... ... ... .
 * 080108DD  02 00 20 C6 02 00 20 C7 02 00 20 CE 02 00 20 CF  .. ... ... ... .
 * 080108ED  02 00 20 D0 02 00 20 FA 10 00 20 23 04 00 20 98  .. ... ... #.. .
 * 080108FD  03 00 20 24 04 00 20 F4 02 00 20 F8 02 00 20 09  .. $.. ... ... .
 * 0801090D  03 00 20 A1 02 00 20 E7 02 00 20 EF 02 00 20 58  .. ... ... ... X
 * 0801091D  13 00 20 E6 02 00 20 E8 02 00 20 EA 02 00 20 EC  .. ... ... ... .
 * 0801092D  02 00 20 EE 02 00 20 A2 02 00 20 6D 03 00 20 64  .. ... ... m.. d
 * 0801093D  03 00 20 5E 03 00 20 5F 03 00 20 F0 02 00 20 F2  .. ^.. _.. ... .
 * 0801094D  02 00 20 FE 02 00 20 00 03 00 20 06 03 00 20 AD  .. ... ... ... .
 * 0801095D  02 00 20 B3 02 00 20 B9 02 00 20 C0 02 00 20 8E  .. ... ... ... .
 * 0801096D  12 00 20 DC 02 00 20 A3 02 00 20 E5 02 00 20 DB  .. ... ... ... .
 * 0801097D  02 00 20 2D 03 00 20 21 04 00 20 34 00 00 20 36  .. -.. !.. 4.. 6
 * 0801098D  00 00 20 F9 48 00 79 00 F0 BF 00 F7 49 08 71 F7  .. .H.y.....I.q.
 * --- 0x08010D75-0x08010DF8 (131B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 08010D75  E0 00 00 58 13 00 20 32 00 00 20 0D 03 00 20 DE  ...X.. 2.. ... .
 * 08010D85  02 00 20 E0 02 00 20 E2 02 00 20 E4 02 00 20 6D  .. ... ... ... m
 * 08010D95  03 00 20 64 03 00 20 5E 03 00 20 5F 03 00 20 F0  .. d.. ^.. _.. .
 * 08010DA5  02 00 20 F2 02 00 20 FE 02 00 20 00 03 00 20 06  .. ... ... ... .
 * 08010DB5  03 00 20 A5 02 00 20 C7 02 00 20 A4 02 00 20 A6  .. ... ... ... .
 * 08010DC5  02 00 20 A7 02 00 20 B3 02 00 20 B9 02 00 20 BA  .. ... ... ... .
 * 08010DD5  02 00 20 8E 12 00 20 22 04 00 20 0B 04 00 20 44  .. ... ".. ... D
 * 08010DE5  05 00 20 18 21 00 20 30 10 00 20 42 05 00 20 50  .. .!. 0.. B.. P
 * 08010DF5  20 00 20 00 21 6E 4A 82 F8 C9 10 70 47 6D 48 00   . .!nJ....pGmH.
 * --- 0x08010FB1-0x08010FF8 (71B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 08010FB1  47 00 00 C4 11 00 20 FC 02 00 20 28 04 00 20 FE  G..... ... (.. .
 * 08010FC1  02 00 20 00 03 00 20 8F 03 00 20 9C 03 00 20 44  .. ... ... ... D
 * 08010FD1  04 00 20 38 04 00 20 E2 02 00 20 DB 02 00 20 40  .. 8.. ... ... @
 * 08010FE1  04 00 20 3C 04 00 20 30 04 00 20 90 03 00 20 34  .. <.. 0.. ... 4
 * 08010FF1  04 00 20 2C 04 00 20 01 21 01 60 70 47 10 B5 04  .. ,.. .!.`pG...
 * --- 0x080113F3-0x08011444 (81B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 080113F3  E0 04 16 00 20 4C 04 00 20 00 00 00 00 00 00 00  .... L.. .......
 * 08011403  00 00 00 00 00 00 00 F0 3F 00 00 00 00 00 00 18  ........?.......
 * 08011413  40 00 00 00 00 00 00 00 40 00 00 00 00 00 00 08  @.......@.......
 * 08011423  40 55 55 55 55 55 55 E5 3F 00 00 00 00 00 00 E0  @UUUUUU.?.......
 * 08011433  3F 55 55 55 55 55 55 D5 3F 00 00 00 00 00 E0 6F  ?UUUUUU.?......o
 * 08011443  40 B0 EE 4A 0A F0 EE 6A 0A B0 EE 40 EA F0 EE 60  @..J...j...@...`
 * --- 0x08011B53-0x08011B74 (33B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 08011B53  E0 00 00 00 00 00 D0 74 40 B4 15 00 20 2A 03 00  .......t@... *..
 * 08011B63  20 F4 16 00 20 00 7F FF 00 00 FF FF 00 64 15 00   ... ........d..
 * 08011B73  20 F7 49 F8 48 00 78 FF F7 BF FD F7 49 88 60 4F   .I.H.x.....I.`O
 * --- 0x08011BE5-0x08011C16 (49B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 08011BE5  F0 18 00 64 00 B1 00 DF 00 0E 01 3C 01 63 00 63  ...d.......<.c.c
 * 08011BF5  00 63 00 63 00 63 00 63 00 6B 01 C1 01 0E 02 3C  .c.c.c.c.k.....<
 * 08011C05  02 6B 02 99 02 C8 02 14 03 61 03 8F 03 C7 03 F5  .k.......a......
 * 08011C15  03 4F F4 7F 01 CF 48 00 78 FF F7 6D FD CF 49 08  .O....H.x..m..I.
 * --- 0x08011F53-0x08011F68 (21B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 08011F53  E2 00 FF FF 00 2A 03 00 20 64 15 00 20 14 15 00  .....*.. d.. ...
 * 08011F63  20 00 7F FF 00 4F F4 7F 01 FD 48 00 78 FF F7 C4   ....O....H.x...
 * --- 0x08012361-0x08012374 (19B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 08012361  E0 00 00 2A 03 00 20 14 15 00 20 00 7F FF 00 00  ...*.. ... .....
 * 08012371  FF FF 00 FD 49 FE 48 00 78 FF F7 BF F9 FD 49 08  ....I.H.x.....I.
 * --- 0x08012441-0x0801244A (9B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 08012441  F0 04 23 42 60 7E 9D BC 00 4F F4 7F 01 C8 48 00  ..#B`~...O....H.
 * --- 0x0801276B-0x08012780 (21B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0801276B  E0 00 FF FF 00 2A 03 00 20 14 15 00 20 C4 14 00  .....*.. ... ...
 * 0801277B  20 74 14 00 20 06 20 08 64 64 20 81 F8 44 00 00   t.. . .dd ..D..
 * --- 0x08012843-0x0801284C (9B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 08012843  F0 04 4E 98 C4 F3 F1 F0 00 4F F4 7F 01 D1 48 00  ..N......O....H.
 * --- 0x08012B95-0x08012BAC (23B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 08012B95  E0 00 00 2A 03 00 20 74 14 00 20 00 FF FF 00 D4  ...*.. t.. .....
 * 08012BA5  13 00 20 00 7F FF 00 81 F8 4E 00 01 F1 48 00 FE  .. ......N...H..
 * --- 0x08012C49-0x08012C52 (9B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 08012C49  BD 10 B5 FF F7 EB FF 10 BD 00 20 51 E0 00 BF 00  .......... Q....
 * --- 0x08012FB7-0x08012FCE (23B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 08012FB7  E0 28 0C 01 40 20 03 00 20 23 03 00 20 22 03 00  .(..@ .. #.. "..
 * 08012FC7  20 21 03 00 20 FF E7 4F F4 80 40 F9 49 08 60 00   !.. ..O..@.I.`.
 * --- 0x080133B7-0x080133C4 (13B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 080133B7  81 18 0C 01 40 04 16 00 20 B4 15 00 20 F0 B5 87  ....@... ... ...
 * --- 0x08013585-0x0801358E (9B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 08013585  F0 04 11 24 32 45 53 68 00 94 48 00 7D 95 49 08  ...$2ESh..H.}.I.
 * --- 0x0801367F-0x08013688 (9B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0801367F  F0 04 11 24 32 45 53 66 00 00 20 57 49 08 70 57  ...$2ESf.. WI.pW
 * --- 0x080137C7-0x080137FC (53B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 080137C7  E0 D0 D9 01 08 67 00 00 20 E4 04 00 20 00 FF FF  .....g.. ... ...
 * 080137D7  00 48 04 00 20 94 17 00 20 F4 16 00 20 9B 04 00  .H.. ... ... ...
 * 080137E7  20 98 04 00 20 99 04 00 20 9A 04 00 20 9C 04 00   ... ... ... ...
 * 080137F7  20 9D 04 00 20 1C E0 00 EB 40 00 FE 49 08 44 47   ... ....@..I.DG
 * --- 0x08013BFB-0x08013C2C (49B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 08013BFB  E0 94 17 00 20 48 04 00 20 9D 04 00 20 9C 04 00  .... H.. ... ...
 * 08013C0B  20 44 17 00 20 C4 04 00 20 C5 04 00 20 C6 04 00   D.. ... ... ...
 * 08013C1B  20 C7 04 00 20 C8 04 00 20 C9 04 00 20 CA 04 00   ... ... ... ...
 * 08013C2B  20 FE 49 08 70 08 46 00 78 07 28 08 D9 00 20 08   .I.p.F.x.(... .
 * --- 0x08014027-0x08014078 (81B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 08014027  E0 CA 04 00 20 44 17 00 20 CB 04 00 20 CC 04 00  .... D.. ... ...
 * 08014037  20 94 17 00 20 74 14 00 20 90 04 00 20 91 04 00   ... t.. ... ...
 * 08014047  20 92 04 00 20 93 04 00 20 94 04 00 20 95 04 00   ... ... ... ...
 * 08014057  20 96 04 00 20 97 04 00 20 2D 03 00 20 67 04 00   ... ... -.. g..
 * 08014067  20 24 14 00 20 62 04 00 20 63 04 00 20 64 04 00   $.. b.. c.. d..
 * 08014077  20 40 1C F9 49 81 F8 3D 00 01 20 F8 49 08 70 00   @..I..=.. .I.p.
 * --- 0x0801445F-0x08014498 (57B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0801445F  E0 24 14 00 20 65 04 00 20 66 04 00 20 64 04 00  .$.. e.. f.. d..
 * 0801446F  20 63 04 00 20 62 04 00 20 54 16 00 20 A3 04 00   c.. b.. T.. ...
 * 0801447F  20 A4 04 00 20 A5 04 00 20 A6 04 00 20 A7 04 00   ... ... ... ...
 * 0801448F  20 A8 04 00 20 A9 04 00 20 00 24 33 E0 FA 48 90   ... ... .$3..H.
 * --- 0x08014887-0x080148D8 (81B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 08014887  E0 54 16 00 20 A9 04 00 20 A8 04 00 20 A7 04 00  .T.. ... ... ...
 * 08014897  20 A6 04 00 20 A5 04 00 20 A4 04 00 20 A3 04 00   ... ... ... ...
 * 080148A7  20 AA 04 00 20 D4 13 00 20 5D 04 00 20 5E 04 00   ... ... ].. ^..
 * 080148B7  20 5F 04 00 20 60 04 00 20 61 04 00 20 14 15 00   _.. `.. a.. ...
 * 080148C7  20 9E 04 00 20 9F 04 00 20 A0 04 00 20 A1 04 00   ... ... ... ...
 * 080148D7  20 FE 48 90 F8 4C 00 01 28 14 D1 FD 48 00 78 C0   .H..L..(...H.x.
 * --- 0x08014CD1-0x08014CF4 (35B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 08014CD1  E0 00 00 14 15 00 20 A1 04 00 20 A0 04 00 20 9F  ...... ... ... .
 * 08014CE1  04 00 20 9E 04 00 20 A2 04 00 20 64 15 00 20 C4  .. ... ... d.. .
 * 08014CF1  14 00 20 2A 46 39 46 30 46 FE F7 01 F8 00 22 11  .. *F9F0F.....".
 * --- 0x0801512B-0x08015188 (93B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0801512B  E0 C4 14 00 20 A4 16 00 20 64 03 00 20 AB 04 00  .... ... d.. ...
 * 0801513B  20 AC 04 00 20 AD 04 00 20 D4 13 00 20 00 FF FF   ... ... ... ...
 * 0801514B  00 24 54 0F 00 AE 04 00 20 AF 04 00 20 B0 04 00  .$T..... ... ...
 * 0801515B  20 B6 04 00 20 B7 04 00 20 B4 04 00 20 B3 04 00   ... ... ... ...
 * 0801516B  20 B2 04 00 20 B1 04 00 20 98 D9 01 08 E2 02 00   ... ... .......
 * 0801517B  20 4C 04 00 20 2A 03 00 20 00 7F FF 00 2A E0 08   L.. *.. ....*..
 * --- 0x0801530B-0x08015316 (11B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0801530B  F0 05 08 0B 0E 11 22 22 22 22 14 FE F7 03 FD 19  ......""""......
 * --- 0x08015363-0x08015394 (49B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 08015363  F0 A5 18 1B 1E 21 24 27 2A 2D 30 33 36 39 3C 3F  .....!$'*-0369<?
 * 08015373  42 45 48 4B 4E 51 54 57 5A 5D 60 63 66 69 6C 6F  BEHKNQTWZ]`cfilo
 * 08015383  72 75 78 7B 7E 81 84 87 8A 8D 90 93 96 99 9C 9F  rux{~...........
 * 08015393  A2 FF F7 51 FE 89 E0 FE F7 D9 F8 86 E0 FE F7 D6  ...Q............
 * --- 0x0801558B-0x080155D4 (73B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0801558B  E0 2A 03 00 20 D4 13 00 20 E2 02 00 20 4C 04 00  .*.. ... ... L..
 * 0801559B  20 90 03 00 20 24 54 0F 00 A4 16 00 20 D2 04 00   ... $T..... ...
 * 080155AB  20 20 03 00 20 B4 D9 01 08 DA 04 00 20 DC 04 00    .. ....... ...
 * 080155BB  20 44 17 00 20 34 00 00 20 36 00 00 20 91 03 00   D.. 4.. 6.. ...
 * 080155CB  20 00 7F FF 00 24 14 00 20 00 20 81 F8 4E 00 01   ....$.. . ..N..
 * --- 0x080159DF-0x08015A14 (53B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 080159DF  E0 36 00 00 20 DB 02 00 20 DC 04 00 20 2A 03 00  .6.. ... ... *..
 * 080159EF  20 54 16 00 20 24 14 00 20 00 7F FF 00 34 00 00   T.. $.. ....4..
 * 080159FF  20 D4 13 00 20 9F 02 00 20 E6 02 00 20 74 14 00   ... ... ... t..
 * 08015A0F  20 E2 02 00 20 FE 49 88 60 00 20 C8 60 FD 49 FE   ... .I.`. .`.I.
 * --- 0x08015BB1-0x08015BC0 (15B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 08015BB1  F0 07 08 09 0A 0B 23 2E 45 5C 0C 67 46 2F 70 00  ......#.E\.gF/p.
 * --- 0x08015E0F-0x08015E2A (27B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 08015E0F  E0 D4 13 00 20 00 FF FF 00 2A 03 00 20 E2 02 00  .... ....*.. ...
 * 08015E1F  20 DC 04 00 20 90 03 00 20 24 54 0F 00 A4 16 00   ... ... $T.....
 * --- 0x08015E89-0x08015EDA (81B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 08015E89  E2 FE 48 00 88 B0 F5 FA 7F 46 DD FC 48 00 78 07  ..H......F..H.x.
 * 08015E99  28 F5 D0 07 20 FA 49 08 70 00 22 11 46 10 46 FB  (... .I.p.".F.F.
 * 08015EA9  F7 88 FC F7 49 F8 48 00 78 FB F7 23 FC F7 49 08  ....I.H.x..#..I.
 * 08015EB9  60 01 20 81 F8 3C 00 00 20 81 F8 3D 00 81 F8 4D  `. ..<.. ..=...M
 * 08015EC9  00 81 F8 4C 00 03 20 08 64 64 20 81 F8 44 00 02  ...L.. .dd ..D..
 * 08015ED9  20 81 F8 4E 00 01 F1 48 00 FB F7 89 F8 E9 49 E9   ..N...H......I.
 * --- 0x08015F21-0x0801635C (1083B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 08015F21  E2 DE 48 00 88 B0 F5 FA 7F 47 DD D6 48 00 78 06  ..H......G..H.x.
 * 08015F31  28 A9 D0 06 20 D4 49 08 70 00 22 11 46 10 46 FB  (... .I.p.".F.F.
 * 08015F41  F7 3C FC D1 49 D2 48 00 78 FB F7 D7 FB D1 49 08  .<..I.H.x.....I.
 * 08015F51  60 01 20 81 F8 3C 00 00 20 81 F8 3D 00 81 F8 4D  `. ..<.. ..=...M
 * 08015F61  00 01 20 81 F8 4C 00 03 20 08 64 64 20 81 F8 44  .. ..L.. .dd ..D
 * 08015F71  00 02 20 81 F8 4E 00 01 F1 48 00 FB F7 3C F8 C2  .. ..N...H...<..
 * 08015F81  49 C3 48 00 78 FB F7 B9 FB C3 49 08 60 00 20 48  I.H.x.....I.`. H
 * 08015F91  60 02 20 81 F8 3C 00 00 20 81 F8 3D 00 81 F8 4C  `. ..<.. ..=...L
 *   ... (Rest ausgelassen; Gesamt 1083 Bytes)
 * --- 0x0801636B-0x08016376 (11B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0801636B  F0 05 08 0B 0E 11 14 19 1E 23 00 FD F7 D3 FC 1D  .........#......
 * --- 0x080166A7-0x08016704 (93B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 080166A7  E0 54 16 00 20 00 FF FF 00 2A 03 00 20 56 04 00  .T.. ....*.. V..
 * 080166B7  20 7C D9 01 08 5C 04 00 20 D4 13 00 20 74 14 00   |...\.. ... t..
 * 080166C7  20 68 04 00 20 69 04 00 20 6A 04 00 20 80 04 00   h.. i.. j.. ...
 * 080166D7  20 78 04 00 20 70 04 00 20 00 00 00 00 00 00 00   x.. p.. .......
 * 080166E7  00 88 04 00 20 B8 1E 85 EB 51 B8 9E 3F A4 16 00  .... ....Q..?...
 * 080166F7  20 BF 04 00 20 B8 04 00 20 B9 04 00 20 FA F7 EF   ... ... ... ...
 * --- 0x080169E3-0x08016A30 (77B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 080169E3  87 00 21 01 60 70 47 00 00 BA 04 00 20 D4 13 00  ..!.`pG..... ...
 * 080169F3  20 BF 04 00 20 00 FF FF 00 B8 04 00 20 B9 04 00   ... ....... ...
 * 08016A03  20 24 54 0F 00 A4 16 00 20 BB 04 00 20 BC 04 00   $T..... ... ...
 * 08016A13  20 BD 04 00 20 C0 04 00 20 C2 04 00 20 C3 04 00   ... ... ... ...
 * 08016A23  20 BE 04 00 20 00 00 00 00 00 00 59 40 00 20 F8   ... ......Y@. .
 * --- 0x08016E11-0x08016E1C (11B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 08016E11  E0 00 00 C0 17 00 20 C4 18 00 20 0D F1 05 00 00  ...... ... .....
 * --- 0x08016E41-0x08016E88 (71B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 08016E41  47 01 20 0F 49 C1 F8 80 00 70 47 00 20 0D 49 C1  G. .I....pG. .I.
 * 08016E51  F8 80 00 70 47 00 B5 0A 48 D0 F8 80 00 80 B1 08  ...pG...H.......
 * 08016E61  48 D0 F8 80 00 40 1C 06 49 C1 F8 80 00 08 46 D0  H....@..I.....F.
 * 08016E71  F8 80 00 3C 28 04 D9 FF F7 E8 FF 00 20 01 49 08  ...<(....... .I.
 * 08016E81  70 00 BD C0 17 00 20 72 B6 32 48 00 68 00 F4 E0  p..... r.2H.h...
 * --- 0x08016ECF-0x08016F74 (165B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 08016ECF  BD 70 47 10 B5 02 F0 C2 FB FF F7 FA FF 01 21 20  .pG...........! 
 * 08016EDF  48 02 F0 B0 FE 1F 49 1E 48 02 F0 89 FE FF F7 CC  H.....I.H.......
 * 08016EEF  FF 10 BD 10 B5 1C 48 44 68 A0 47 10 BD 1B 48 00  ......HDh.G...H.
 * 08016EFF  78 70 47 1A 49 08 70 70 47 10 B5 18 48 00 78 30  xpG.I.ppG...H.x0
 * 08016F0F  B1 00 20 16 49 08 70 02 F0 A1 FB FF F7 D1 FF 10  .. .I.p.........
 * 08016F1F  BD 13 48 00 68 00 68 70 47 10 B5 01 21 0B 48 00  ..H.h.hpG...!.H.
 * 08016F2F  68 02 F0 88 FE 10 BD 10 B5 0E 48 F3 F7 1F FB 72  h.........H....r
 * 08016F3F  B6 4F F0 00 60 44 68 01 46 08 68 80 F3 08 88 00  .O..`Dh.F.h.....
 * 08016F4F  BF A0 47 10 BD 0C ED 00 E0 00 00 FA 05 EC 04 00  ..G.............
 * 08016F5F  20 00 F0 07 08 4C 6C 51 03 00 80 00 08 F0 04 00   ....LlQ........
 * 08016F6F  20 E8 04 00 20 00 64 00 40 70 B5 04 46 0D 46 16   ... .d.@p..F.F.
 * --- 0x0801737F-0x08017414 (149B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0801737F  E0 B8 1A 00 20 78 DA 01 08 08 1A 00 20 58 1A 00  .... x...... X..
 * 0801738F  20 90 1A 00 20 9C 1A 00 20 A8 1A 00 20 F2 04 00   ... ... ... ...
 * 0801739F  20 99 03 00 20 9A 03 00 20 1F 03 00 20 20 03 00   ... ... ...  ..
 * 080173AF  20 21 03 00 20 22 03 00 20 23 03 00 20 28 03 00   !.. ".. #.. (..
 * 080173BF  20 2A 03 00 20 2B 03 00 20 2C 03 00 20 00 03 00   *.. +.. ,.. ...
 * 080173CF  20 40 DA 01 08 D9 02 00 20 A2 02 00 20 A3 02 00   @...... ... ...
 * 080173DF  20 A4 02 00 20 A5 02 00 20 A6 02 00 20 B9 02 00   ... ... ... ...
 * 080173EF  20 C6 02 00 20 C7 02 00 20 DA 02 00 20 A1 02 00   ... ... ... ...
 * 080173FF  20 0D 03 00 20 12 03 00 20 A7 02 00 20 AD 02 00   ... ... ... ...
 * 0801740F  20 B3 02 00 20 FE 49 08 55 04 EB 44 01 FD 48 00   ... .I.U..D..H.
 * --- 0x0801780F-0x08017868 (89B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0801780F  E0 BA 02 00 20 61 1A 00 20 C0 02 00 20 DA 02 00  .... a.. ... ...
 * 0801781F  20 08 03 00 20 F4 D9 01 08 08 1A 00 20 EC D9 01   ... ....... ...
 * 0801782F  08 00 DA 01 08 1E DA 01 08 23 DA 01 08 36 DA 01  .........#...6..
 * 0801783F  08 14 00 00 20 19 00 00 20 1A 00 00 20 1B 00 00  .... ... ... ...
 * 0801784F  20 0C 00 00 20 11 00 00 20 12 00 00 20 13 00 00   ... ... ... ...
 * 0801785F  20 2C 00 00 20 42 07 00 20 FD 48 F4 F7 91 F8 FD   ,.. B.. .H.....
 * --- 0x08017C5F-0x08017CB4 (85B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 08017C5F  E0 08 1A 00 20 EC D9 01 08 F4 D9 01 08 14 00 00  .... ...........
 * 08017C6F  20 19 00 00 20 1A 00 00 20 1B 00 00 20 0C 00 00   ... ... ... ...
 * 08017C7F  20 11 00 00 20 12 00 00 20 13 00 00 20 2C 00 00   ... ... ... ,..
 * 08017C8F  20 42 07 00 20 F8 04 00 20 58 1A 00 20 F9 04 00   B.. ... X.. ...
 * 08017C9F  20 90 1A 00 20 FA 04 00 20 9C 1A 00 20 A8 1A 00   ... ... ... ...
 * 08017CAF  20 FB 04 00 20 FE 48 01 5D FE 48 01 55 64 1C 05   ... .H.].H.Ud..
 * --- 0x080180AD-0x08018144 (151B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 080180AD  E0 00 00 2C 00 00 20 37 1A 00 20 42 07 00 20 A3  ...,.. 7.. B.. .
 * 080180BD  02 00 20 58 1A 00 20 A2 02 00 20 A4 02 00 20 A5  .. X.. ... ... .
 * 080180CD  02 00 20 A6 02 00 20 B9 02 00 20 C6 02 00 20 C7  .. ... ... ... .
 * 080180DD  02 00 20 DA 02 00 20 0D 03 00 20 12 03 00 20 B3  .. ... ... ... .
 * 080180ED  02 00 20 AD 02 00 20 A7 02 00 20 C0 02 00 20 BA  .. ... ... ... .
 * 080180FD  02 00 20 00 03 00 20 90 1A 00 20 9C 1A 00 20 1F  .. ... ... ... .
 * 0801810D  03 00 20 A8 1A 00 20 20 03 00 20 21 03 00 20 22  .. ...  .. !.. "
 * 0801811D  03 00 20 23 03 00 20 28 03 00 20 2A 03 00 20 2B  .. #.. (.. *.. +
 * 0801812D  03 00 20 2C 03 00 20 99 03 00 20 F2 04 00 20 FC  .. ,.. ... ... .
 * 0801813D  04 00 20 FE 04 00 20 90 F8 25 00 B1 49 09 79 88  .. ... ..%..I.y.
 * --- 0x0801840F-0x08018478 (105B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0801840F  BD BA 02 00 20 58 1A 00 20 B3 02 00 20 AD 02 00  .... X.. ... ...
 * 0801841F  20 A7 02 00 20 C0 02 00 20 A8 1A 00 20 1F 03 00   ... ... ... ...
 * 0801842F  20 20 03 00 20 21 03 00 20 22 03 00 20 23 03 00    .. !.. ".. #..
 * 0801843F  20 28 03 00 20 2A 03 00 20 2B 03 00 20 2C 03 00   (.. *.. +.. ,..
 * 0801844F  20 F2 04 00 20 99 03 00 20 FE 04 00 20 42 07 00   ... ... ... B..
 * 0801845F  20 FF 04 00 20 3E 00 00 20 40 00 00 20 19 00 00   ... >.. @.. ...
 * 0801846F  20 1A 00 00 20 08 1A 00 20 00 20 6C 49 08 71 48   ... ... . lI.qH
 * --- 0x08018629-0x0801863C (19B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 08018629  BD 00 00 A0 1E 00 20 00 0C 01 40 66 00 00 20 91  ...... ...@f.. .
 * 08018639  03 00 20 00 20 31 49 08 70 70 47 2F 48 00 78 01  .. . 1I.ppG/H.x.
 * --- 0x08018703-0x08018718 (21B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 08018703  BD 00 05 00 20 1C 03 00 20 91 03 00 20 02 05 00  .... ... ... ...
 * 08018713  20 0E 03 00 20 10 B5 00 F0 38 FE 00 F0 14 FD 01   ... ....8......
 * --- 0x08018C79-0x08018D8E (277B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 08018C79  E0 88 E0 FB 48 F2 F7 5A FA FB 49 09 68 08 70 F9  ....H..Z..I.h.p.
 * 08018C89  48 00 68 40 1C F8 49 08 60 F8 48 00 88 40 1E F6  H.h@..I.`.H..@..
 * 08018C99  49 08 80 08 46 00 88 01 28 07 D1 00 21 F1 48 F2  I...F...(...!.H.
 * 08018CA9  F7 0B FA 01 21 EF 48 F2 F7 FB F9 EF 48 00 88 40  ....!.H.....H..@
 * 08018CB9  B9 00 22 4F F4 E0 61 EA 48 F2 F7 2D FA 00 20 EB  .."O..a.H..-.. .
 * 08018CC9  49 08 70 5F E0 1D E0 FF E7 EA 48 00 78 80 B1 00  I.p_......H.x...
 * 08018CD9  20 E8 49 08 70 00 22 4F F4 E0 61 E1 48 F2 F7 1B   .I.p."O..a.H...
 * 08018CE9  FA 01 21 DF 48 F2 F7 DC F9 00 20 E0 49 08 70 49  ..!.H..... .I.pI
 * 08018CF9  E0 E1 48 01 78 DB 48 F2 F7 17 FA 01 20 DF 49 08  ..H.x.H..... .I.
 * 08018D09  70 40 E0 DE 48 00 78 01 28 03 D1 01 21 D5 48 F2  p@..H.x.(...!.H.
 * 08018D19  F7 BB F9 37 E0 DA 48 00 78 10 BB D9 48 00 88 00  ...7..H.x...H...
 * 08018D29  BB 01 21 CF 48 F2 F7 BC F9 40 F6 B8 30 D6 49 08  ..!.H....@..0.I.
 * 08018D39  80 07 E0 D4 48 01 88 00 88 40 1E D2 4A 10 80 01  ....H....@..J...
 * 08018D49  B9 06 E0 4F F4 00 31 C6 48 F2 F7 A1 FA 00 28 F0  ...O..1.H.....(.
 * 08018D59  D1 00 BF 01 20 C7 49 08 70 01 21 C1 48 F2 F7 94  .... .I.p.!.H...
 * 08018D69  F9 0F E0 C9 48 02 88 00 88 40 1C C7 4B 18 80 C7  ....H....@..K...
 * 08018D79  48 81 5C BB 48 F2 F7 D8 F9 C2 48 00 88 40 1E C0  H.\.H.....H..@..
 * 08018D89  49 08 80 00 BF 00 BF 10 BD 10 B5 C1 49 B5 48 F2  I...........I.H.
 * --- 0x08019395-0x080193BC (39B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 08019395  BD 10 B5 EE F7 E6 FB 10 BD 00 00 00 12 7A 00 00  .............z..
 * 080193A5  24 F4 00 00 09 3D 00 00 48 E8 01 80 F9 37 03 C0  $....=..H....7..
 * 080193B5  FC 9B 01 00 F3 6F 06 70 B5 04 46 0D 46 29 46 20  .....o.p..F.F)F 
 * --- 0x08019513-0x08019568 (85B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 08019513  BD 70 47 10 B5 4F F4 80 51 53 48 EE F7 42 FA 10  .pG..O..QSH..B..
 * 08019523  BD 10 B5 4F F4 80 51 50 48 EE F7 3F FA 10 BD 10  ...O..QPH..?....
 * 08019533  B5 10 21 4D 48 EE F7 35 FA 10 BD 10 B5 10 21 4A  ..!MH..5......!J
 * 08019543  48 EE F7 33 FA 10 BD 10 B5 01 20 48 49 08 70 C1  H..3...... HI.p.
 * 08019553  03 43 48 EE F7 26 FA 10 BD 10 B5 08 21 42 48 EE  .CH..&......!BH.
 * 08019563  F7 20 FA 10 BD 10 B5 08 21 3F 48 EE F7 1E FA 10  . ......!?H.....
 * --- 0x0801965D-0x08019690 (51B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0801965D  47 70 47 70 47 00 00 00 08 01 40 00 10 01 40 00  GpGpG.....@...@.
 * 0801966D  0C 01 40 1C 03 00 20 4C 00 00 20 97 03 00 20 50  ..@... L.. ... P
 * 0801967D  00 00 20 52 00 00 20 91 03 00 20 38 05 00 20 2D  .. R.. ... 8.. -
 * 0801968D  03 00 20 00 B5 89 B0 01 21 08 03 EE F7 97 FD 07  .. .....!.......
 * --- 0x080198B5-0x080198EC (55B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 080198B5  BD 00 00 00 08 01 40 00 0C 01 40 00 08 02 40 38  ......@...@...@8
 * 080198C5  00 00 20 3C 05 00 20 44 00 00 20 32 00 00 20 34  .. <.. D.. 2.. 4
 * 080198D5  00 00 20 36 00 00 20 3E 00 00 20 40 00 00 20 3C  .. 6.. >.. @.. <
 * 080198E5  00 00 20 3A 00 00 20 10 B5 8A B0 04 46 B1 48 84  .. :.. .....F.H.
 * --- 0x08019B6F-0x08019B82 (19B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 08019B6F  BD 16 48 00 88 70 47 16 48 00 88 70 47 15 48 00  ..H..pG.H..pG.H.
 * 08019B7F  88 70 47 10 B5 B2 B0 C8 21 68 46 03 F0 C8 FB 00  .pG.....!hF.....
 * --- 0x08019BB5-0x08019BC0 (11B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 08019BB5  BD 00 00 00 38 01 40 00 08 01 40 00 44 00 40 00  ....8.@...@.D.@.
 * --- 0x08019F11-0x08019F60 (79B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 08019F11  BD 00 00 A0 24 00 20 58 05 00 20 54 05 00 20 50  ....$. X.. T.. P
 * 08019F21  05 00 20 48 05 00 20 8B 00 00 20 60 05 00 20 5C  .. H.. ... `.. \
 * 08019F31  05 00 20 59 05 00 20 8C 00 00 20 70 05 00 20 6C  .. Y.. ... p.. l
 * 08019F41  05 00 20 68 05 00 20 9E 00 00 20 78 05 00 20 9C  .. h.. ... x.. .
 * 08019F51  00 00 20 80 05 00 20 7C 05 00 20 E0 21 00 20 2D  .. ... |.. .!. -
 * --- 0x0801A0A5-0x0801A1A8 (259B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0801A0A5  E7 10 B5 08 22 00 21 B2 48 F1 F7 64 FC B2 48 00  ....".!.H..d..H.
 * 0801A0B5  7C B0 49 08 70 B0 48 40 7C 48 70 AE 48 80 7C 88  |.I.p.H@|Hp.H.|.
 * 0801A0C5  70 00 20 C8 70 08 71 48 71 88 71 C8 71 10 BD 10  p. .p.qHq.q.q...
 * 0801A0D5  B5 08 22 00 21 A9 48 F1 F7 4D FC A6 48 00 7A A6  ..".!.H..M..H.z.
 * 0801A0E5  49 08 70 A4 48 40 7A 48 70 A3 48 80 7A 88 70 A1  I.p.H@zHp.H.z.p.
 * 0801A0F5  48 C0 7A C8 70 A0 48 00 7B 08 71 9E 48 40 7B 48  H.z.p.H.{.q.H@{H
 * 0801A105  71 9D 48 80 7B 88 71 9B 48 C0 7B C8 71 10 BD 10  q.H.{.q.H.{.q...
 * 0801A115  B5 08 22 00 21 9A 48 F1 F7 2D FC 96 48 00 78 97  ..".!.H..-..H.x.
 * 0801A125  49 08 70 94 48 40 78 48 70 93 48 80 78 88 70 91  I.p.H@xHp.H.x.p.
 * 0801A135  48 C0 78 C8 70 90 48 00 79 08 71 8E 48 40 79 48  H.x.p.H.y.q.H@yH
 * 0801A145  71 8D 48 80 79 88 71 8B 48 C0 79 C8 71 10 BD 10  q.H.y.q.H.y.q...
 * 0801A155  B5 08 22 00 21 8B 48 F1 F7 0D FC 89 4B 8A 48 02  ..".!.H.....K.H.
 * 0801A165  88 10 21 08 20 F1 F7 D2 FB 86 4B 87 48 18 21 02  ..!. .....K.H.!.
 * 0801A175  68 20 20 F1 F7 CB FB 10 BD 10 B5 08 22 00 21 83  h  .........".!.
 * 0801A185  48 F1 F7 F8 FB 82 4B 82 48 02 88 10 21 08 20 F1  H.....K.H...!. .
 * 0801A195  F7 BD FB 7E 4B 80 48 02 88 10 21 18 20 F1 F7 B6  ...~K.H...!. ...
 * 0801A1A5  FB 10 BD 70 B5 7D 48 00 78 28 28 03 DD 7B 48 00  ...p.}H.x((..{H.
 * --- 0x0801A365-0x0801A404 (159B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0801A365  E0 00 00 E0 21 00 20 F0 25 00 20 A0 24 00 20 06  ....!. .%. .$. .
 * 0801A375  26 00 20 E0 05 00 20 42 07 00 20 D8 05 00 20 D0  &. ... B.. ... .
 * 0801A385  05 00 20 C8 05 00 20 FE 02 00 20 00 03 00 20 C0  .. ... ... ... .
 * 0801A395  05 00 20 F4 02 00 20 F8 02 00 20 6D 03 00 20 5F  .. ... ... m.. _
 * 0801A3A5  03 00 20 5E 03 00 20 B8 05 00 20 64 03 00 20 F0  .. ^.. ... d.. .
 * 0801A3B5  02 00 20 F2 02 00 20 09 03 00 20 A1 02 00 20 B0  .. ... ... ... .
 * 0801A3C5  05 00 20 A2 02 00 20 06 03 00 20 A5 02 00 20 C7  .. ... ... ... .
 * 0801A3D5  02 00 20 A8 05 00 20 E6 02 00 20 E7 02 00 20 E8  .. ... ... ... .
 * 0801A3E5  02 00 20 EA 02 00 20 EC 02 00 20 EE 02 00 20 A0  .. ... ... ... .
 * 0801A3F5  05 00 20 A3 02 00 20 99 03 00 20 DC 02 00 20 00  .. ... ... ... .
 * --- 0x0801A59B-0x0801A644 (169B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0801A59B  BD 00 21 00 20 00 BF 05 E0 AC 4A 12 5C 0A 44 D1  ..!. .....J.\.D.
 * 0801A5AB  B2 42 1C D0 B2 07 28 F7 DB A8 4A 12 78 A8 4B 1A  .B....(...J.x.K.
 * 0801A5BB  70 A6 4A 52 78 A7 4B 1A 70 A4 4A 92 78 A6 4B 1A  p.JRx.K.p.J.x.K.
 * 0801A5CB  70 1A 46 12 78 AA 2A 03 D1 00 22 A4 4B 1A 70 06  p.F.x.*...".K.p.
 * 0801A5DB  E0 A1 4A 12 78 55 2A 02 D1 01 22 A0 4B 1A 70 70  ..J.xU*...".K.pp
 * 0801A5EB  47 70 B5 00 25 00 24 00 BF 05 E0 9D 48 00 5D 28  Gp..%.$.....H.](
 * 0801A5FB  44 C5 B2 60 1C C4 B2 07 2C F7 DB 99 48 C0 79 A8  D..`....,...H.y.
 * 0801A60B  42 19 D1 97 48 00 78 81 28 08 D1 95 48 40 78 01  B...H.x.(...H@x.
 * 0801A61B  28 04 D1 94 49 08 70 01 F0 B0 FB 0C E0 90 48 00  (...I.p.......H.
 * 0801A62B  78 81 28 08 D1 8E 48 40 78 FE 28 04 D1 00 20 8D  x.(...H@x.(... .
 * 0801A63B  49 08 70 01 F0 A6 FB 70 BD 10 B5 8B 48 80 79 5A  I.p....p....H.yZ
 * --- 0x0801A6ED-0x0801A6FA (13B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0801A6ED  F0 61 06 07 08 09 0A 0B 0C 0D 27 45 00 59 E0 58  .a........'E.Y.X
 * --- 0x0801A803-0x0801A8A0 (157B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0801A803  E0 34 00 00 20 36 00 00 20 32 00 00 20 0D 03 00  .4.. 6.. 2.. ...
 * 0801A813  20 98 05 00 20 DB 02 00 20 DE 02 00 20 E0 02 00   ... ... ... ...
 * 0801A823  20 E2 02 00 20 E4 02 00 20 90 05 00 20 0C 00 00   ... ... ... ...
 * 0801A833  20 11 00 00 20 12 00 00 20 13 00 00 20 19 00 00   ... ... ... ...
 * 0801A843  20 1A 00 00 20 1B 00 00 20 88 05 00 20 98 06 00   ... ... ... ...
 * 0801A853  20 42 07 00 20 90 06 00 20 66 00 00 20 67 00 00   B.. ... f.. g..
 * 0801A863  20 68 00 00 20 99 03 00 20 88 06 00 20 65 00 00   h.. ... ... e..
 * 0801A873  20 78 06 00 20 80 06 00 20 70 06 00 20 55 07 00   x.. ... p.. U..
 * 0801A883  20 A3 00 00 20 68 06 00 20 69 00 00 20 6A 00 00   ... h.. i.. j..
 * 0801A893  20 6B 00 00 20 6C 00 00 20 6D 00 00 20 F1 F7 05   k.. l.. m.. ...
 * --- 0x0801A9AF-0x0801AA58 (169B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0801A9AF  87 CD 48 00 78 0B 28 4D D2 DF E8 00 F0 4C 06 07  ..H.x.(M.....L..
 * 0801A9BF  08 09 0A 0B 0C 0D 24 3B 00 44 E0 43 E0 42 E0 41  ......$;.D.C.B.A
 * 0801A9CF  E0 40 E0 3F E0 3E E0 C4 48 40 78 C4 49 08 70 C2  .@.?.>..H@x.I.p.
 * 0801A9DF  48 80 78 48 70 C0 48 C0 78 88 70 BF 48 00 79 C8  H.xHp.H.x.p.H.y.
 * 0801A9EF  70 BD 48 40 79 08 71 BC 48 80 79 48 71 BA 48 C0  p.H@y.q.H.yHq.H.
 * 0801A9FF  79 88 71 27 E0 B8 48 40 78 B8 49 C8 71 B6 48 80  y.q'..H@x.I.q.H.
 * 0801AA0F  78 08 72 B5 48 C0 78 48 72 B3 48 00 79 88 72 B2  x.r.H.xHr.H.y.r.
 * 0801AA1F  48 40 79 C8 72 B0 48 80 79 08 73 AF 48 C0 79 48  H@y.r.H.y.s.H.yH
 * 0801AA2F  73 10 E0 AD 48 40 78 AD 49 88 73 AB 48 80 78 C8  s...H@x.I.s.H.x.
 * 0801AA3F  73 A9 48 C0 78 08 74 A8 48 00 79 48 74 A6 48 40  s.H.x.t.H.yHt.H@
 * 0801AA4F  79 88 74 00 BF 00 BF 70 47 10 B5 A5 4A 08 21 00  y.t....pG...J.!.
 * --- 0x0801AC93-0x0801AD64 (209B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0801AC93  BD 6E 00 00 20 68 06 00 20 6F 00 00 20 70 00 00  .n.. h.. o.. p..
 * 0801ACA3  20 71 00 00 20 72 00 00 20 73 00 00 20 74 00 00   q.. r.. s.. t..
 * 0801ACB3  20 75 00 00 20 76 00 00 20 77 00 00 20 78 00 00   u.. v.. w.. x..
 * 0801ACC3  20 60 06 00 20 75 03 00 20 76 03 00 20 6B 03 00   `.. u.. v.. k..
 * 0801ACD3  20 6C 03 00 20 77 03 00 20 78 03 00 20 79 03 00   l.. w.. x.. y..
 * 0801ACE3  20 7A 03 00 20 58 06 00 20 7B 07 00 20 50 06 00   z.. X.. {.. P..
 * 0801ACF3  20 1C 00 00 20 21 00 00 20 22 00 00 20 23 00 00   ... !.. ".. #..
 * 0801AD03  20 24 00 00 20 29 00 00 20 2A 00 00 20 2B 00 00   $.. ).. *.. +..
 * 0801AD13  20 48 06 00 20 72 03 00 20 73 03 00 20 69 03 00   H.. r.. s.. i..
 * 0801AD23  20 6A 03 00 20 8F 03 00 20 40 06 00 20 6F 03 00   j.. ... @.. o..
 * 0801AD33  20 38 06 00 20 64 03 00 20 65 03 00 20 30 06 00   8.. d.. e.. 0..
 * 0801AD43  20 9C 03 00 20 5E 03 00 20 5F 03 00 20 60 03 00   ... ^.. _.. `..
 * 0801AD53  20 61 03 00 20 62 03 00 20 63 03 00 20 7B 03 00   a.. b.. c.. {..
 * 0801AD63  20 2D E9 F0 41 F8 4A 01 21 07 20 F0 F7 9E FD F7   -..A.J.!. .....
 * --- 0x0801B149-0x0801B280 (311B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0801B149  81 00 00 28 06 00 20 81 00 00 20 82 00 00 20 83  ...(.. ... ... .
 * 0801B159  00 00 20 84 00 00 20 4E 03 00 20 4F 03 00 20 50  .. ... N.. O.. P
 * 0801B169  03 00 20 51 03 00 20 52 03 00 20 53 03 00 20 54  .. Q.. R.. S.. T
 * 0801B179  03 00 20 55 03 00 20 20 06 00 20 7D 00 00 20 7E  .. U..  .. }.. ~
 * 0801B189  00 00 20 7F 00 00 20 80 00 00 20 46 03 00 20 47  .. ... ... F.. G
 * 0801B199  03 00 20 48 03 00 20 49 03 00 20 4A 03 00 20 4B  .. H.. I.. J.. K
 * 0801B1A9  03 00 20 4C 03 00 20 4D 03 00 20 18 06 00 20 79  .. L.. M.. ... y
 * 0801B1B9  00 00 20 7A 00 00 20 7B 00 00 20 7C 00 00 20 3E  .. z.. {.. |.. >
 * 0801B1C9  03 00 20 3F 03 00 20 40 03 00 20 41 03 00 20 42  .. ?.. @.. A.. B
 * 0801B1D9  03 00 20 43 03 00 20 44 03 00 20 45 03 00 20 10  .. C.. D.. E.. .
 * 0801B1E9  06 00 20 75 00 00 20 76 00 00 20 77 00 00 20 78  .. u.. v.. w.. x
 * 0801B1F9  00 00 20 36 03 00 20 37 03 00 20 38 03 00 20 39  .. 6.. 7.. 8.. 9
 * 0801B209  03 00 20 3A 03 00 20 3B 03 00 20 3C 03 00 20 3D  .. :.. ;.. <.. =
 * 0801B219  03 00 20 08 06 00 20 71 00 00 20 72 00 00 20 73  .. ... q.. r.. s
 * 0801B229  00 00 20 74 00 00 20 2E 03 00 20 2F 03 00 20 30  .. t.. ... /.. 0
 * 0801B239  03 00 20 31 03 00 20 32 03 00 20 33 03 00 20 34  .. 1.. 2.. 3.. 4
 * 0801B249  03 00 20 35 03 00 20 00 06 00 20 66 03 00 20 67  .. 5.. ... f.. g
 * 0801B259  03 00 20 68 03 00 20 F8 05 00 20 6D 03 00 20 6E  .. h.. ... m.. n
 * 0801B269  03 00 20 F0 05 00 20 7C 03 00 20 7D 03 00 20 7E  .. ... |.. }.. ~
 * 0801B279  03 00 20 7F 03 00 20 10 B5 FE 4A 04 21 00 20 F0  .. ... ...J.!. .
 * --- 0x0801B67B-0x0801B720 (165B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0801B67B  E0 E8 05 00 20 85 03 00 20 87 03 00 20 88 03 00  .... ... ... ...
 * 0801B68B  20 89 03 00 20 83 03 00 20 82 03 00 20 81 03 00   ... ... ... ...
 * 0801B69B  20 80 03 00 20 8B 03 00 20 8A 03 00 20 8E 03 00   ... ... ... ...
 * 0801B6AB  20 8D 03 00 20 8C 03 00 20 5C 00 00 20 64 00 00   ... ... \.. d..
 * 0801B6BB  20 F0 25 00 20 F0 05 00 20 F8 05 00 20 00 06 00   .%. ... ... ...
 * 0801B6CB  20 08 06 00 20 10 06 00 20 18 06 00 20 20 06 00   ... ... ...  ..
 * 0801B6DB  20 28 06 00 20 30 06 00 20 38 06 00 20 40 06 00   (.. 0.. 8.. @..
 * 0801B6EB  20 48 06 00 20 50 06 00 20 58 06 00 20 60 06 00   H.. P.. X.. `..
 * 0801B6FB  20 68 06 00 20 70 06 00 20 80 06 00 20 78 06 00   h.. p.. ... x..
 * 0801B70B  20 ED A5 01 08 88 06 00 20 9D A5 01 08 90 06 00   ....... .......
 * 0801B71B  20 06 26 00 20 00 20 79 49 01 22 79 4B CD E9 01   .&. . yI."yK...
 * --- 0x0801B907-0x0801B97C (117B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0801B907  47 F5 A4 01 08 88 05 00 20 B5 A4 01 08 90 05 00  G....... .......
 * 0801B917  20 4B A3 01 08 98 05 00 20 DD A2 01 08 A0 05 00   K...... .......
 * 0801B927  20 7B A2 01 08 A8 05 00 20 1B A2 01 08 B0 05 00   {...... .......
 * 0801B937  20 A9 A1 01 08 B8 05 00 20 7F A1 01 08 C0 05 00   ....... .......
 * 0801B947  20 55 A1 01 08 C8 05 00 20 15 A1 01 08 D0 05 00   U...... .......
 * 0801B957  20 D5 A0 01 08 D8 05 00 20 A7 A0 01 08 E0 05 00   ....... .......
 * 0801B967  20 8B 00 00 20 FC 02 00 20 4C 00 00 20 9C 06 00   ... ... L.. ...
 * 0801B977  20 8C 00 00 20 08 B5 4F F4 C0 60 EB F7 69 FD 36   ... ..O..`..i.6
 * --- 0x0801C1E3-0x0801C1F8 (21B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0801C1E3  E0 01 02 03 04 05 06 07 08 08 07 06 05 04 03 02  ................
 * 0801C1F3  01 78 56 34 12 00 64 00 40 C7 02 00 20 7B 03 00  .xV4..d.@... {..
 * --- 0x0801C5FD-0x0801C640 (67B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0801C5FD  BD 00 00 AC 06 00 20 A8 06 00 20 48 00 00 20 3C  ...... ... H.. <
 * 0801C60D  26 00 20 A9 06 00 20 7B 03 00 20 78 DC 01 08 64  &. ... {.. x...d
 * 0801C61D  03 00 20 BC 06 00 20 AA 06 00 20 AE 06 00 20 18  .. ... ... ... .
 * 0801C62D  03 00 20 B0 06 00 20 B4 06 00 20 B8 06 00 20 64  .. ... ... ... d
 * 0801C63D  00 00 20 F7 49 08 70 70 47 F6 48 00 78 70 47 F4  .. .I.ppG.H.xpG.
 * --- 0x0801C645-0x0801C700 (187B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0801C645  47 F6 48 00 78 70 47 F4 48 00 78 03 28 10 D0 F3  G.H.xpG.H.x.(...
 * 0801C655  48 00 78 02 28 0C D1 01 20 F2 49 08 70 02 20 EE  H.x.(... .I.p. .
 * 0801C665  49 08 70 F0 48 00 78 01 28 02 D1 00 20 EE 49 08  I.p.H.x.(... .I.
 * 0801C675  70 70 47 E9 48 00 78 01 28 08 D0 E8 48 00 78 01  ppG.H.x.(...H.x.
 * 0801C685  28 04 D1 E7 49 08 70 00 20 E4 49 08 70 70 47 E2  (...I.p. .I.ppG.
 * 0801C695  48 00 78 05 28 0C D0 E1 48 00 78 04 28 08 D1 E2  H.x.(...H.x.(...
 * 0801C6A5  48 00 78 28 B9 01 20 DE 49 08 70 04 20 DB 49 08  H.x(.. .I.p. .I.
 * 0801C6B5  70 70 47 D9 48 00 78 05 28 1E D1 DC 48 00 68 40  ppG.H.x.(...H.h@
 * 0801C6C5  1C DB 49 08 60 08 46 00 68 32 28 15 D9 01 20 D4  ..I.`.F.h2(... .
 * 0801C6D5  49 08 70 00 20 D1 49 08 70 D5 49 08 60 D5 48 00  I.p. .I.p.I.`.H.
 * 0801C6E5  78 40 1C D3 49 08 70 08 46 00 78 02 28 04 DD 00  x@..I.p.F.x.(...
 * 0801C6F5  20 08 70 01 20 CD 49 08 70 70 47 01 20 C9 49 08   .p. .I.ppG. .I.
 * --- 0x0801CA1D-0x0801CAA4 (135B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0801CA1D  E0 00 00 FD 06 00 20 91 03 00 20 F4 06 00 20 59  ...... ... ... Y
 * 0801CA2D  00 00 20 5A 00 00 20 F8 06 00 20 FC 06 00 20 D4  .. Z.. ... ... .
 * 0801CA3D  06 00 20 D5 06 00 20 D6 06 00 20 D7 06 00 20 D8  .. ... ... ... .
 * 0801CA4D  06 00 20 D9 06 00 20 DA 06 00 20 DB 06 00 20 DC  .. ... ... ... .
 * 0801CA5D  06 00 20 DD 06 00 20 C0 06 00 20 C2 06 00 20 C4  .. ... ... ... .
 * 0801CA6D  06 00 20 C6 06 00 20 C8 06 00 20 CA 06 00 20 CC  .. ... ... ... .
 * 0801CA7D  06 00 20 CE 06 00 20 D0 06 00 20 D2 06 00 20 DE  .. ... ... ... .
 * 0801CA8D  06 00 20 E0 06 00 20 E2 06 00 20 E4 06 00 20 E6  .. ... ... ... .
 * 0801CA9D  06 00 20 E8 06 00 20 5D 48 00 88 4F F6 FF 71 08  .. ... ]H..O..q.
 * --- 0x0801CC19-0x0801CC50 (55B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0801CC19  E5 00 00 CC 06 00 20 DA 06 00 20 EA 06 00 20 DB  ...... ... ... .
 * 0801CC29  06 00 20 CE 06 00 20 EC 06 00 20 DC 06 00 20 D0  .. ... ... ... .
 * 0801CC39  06 00 20 EE 06 00 20 DD 06 00 20 D2 06 00 20 F0  .. ... ... ... .
 * 0801CC49  06 00 20 F2 06 00 20 9F ED F9 0A F9 48 80 ED 00  .. ... .....H...
 * --- 0x0801D035-0x0801D0A0 (107B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0801D035  E0 00 00 00 00 00 00 50 26 00 20 00 00 70 42 00  .......P&. ..pB.
 * 0801D045  00 C8 42 70 26 00 20 13 03 00 20 C9 02 00 20 CA  ..Bp&. ... ... .
 * 0801D055  02 00 20 C8 02 00 20 1B 03 00 20 1A 03 00 20 A1  .. ... ... ... .
 * 0801D065  02 00 20 BA 02 00 20 C0 02 00 20 B9 02 00 20 AD  .. ... ... ... .
 * 0801D075  02 00 20 89 88 88 3C 0A 07 00 20 00 00 48 C2 00  .. ...<... ..H..
 * 0801D085  00 48 42 00 00 02 44 00 00 02 C4 FE 06 00 20 00  .HB...D....... .
 * 0801D095  07 00 20 04 07 00 20 02 07 00 20 81 48 80 89 0A  .. ... ... .H...
 * --- 0x0801D2A7-0x0801D2EC (69B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0801D2A7  BD 70 26 00 20 FE 06 00 20 00 07 00 20 02 07 00  .p&. ... ... ...
 * 0801D2B7  20 04 07 00 20 06 07 00 20 50 26 00 20 A1 02 00   ... ... P&. ...
 * 0801D2C7  20 08 07 00 20 12 03 00 20 16 03 00 20 18 03 00   ... ... ... ...
 * 0801D2D7  20 A3 02 00 20 A2 02 00 20 E7 02 00 20 DE 02 00   ... ... ... ...
 * 0801D2E7  20 BA 02 00 20 40 EA 01 03 9B 07 03 D0 09 E0 08   ... @..........
 * --- 0x0801D895-0x0801D8C4 (47B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0801D895  BD 02 E0 08 C8 12 1F 08 C1 00 2A FA D1 70 47 70  ..........*..pGp
 * 0801D8A5  47 00 20 01 E0 01 C1 12 1F 00 2A FB D1 70 47 00  G. .......*..pG.
 * 0801D8B5  00 00 00 00 00 00 00 01 02 03 04 06 07 08 09 00  ................
 * --- 0x0801D94B-0x0801DDBC (1137B)  Codefragment/Daten (nicht als Funktion erfasst) ---
 * 0801D94B  00 00 FF FF 00 00 FF 00 00 FF FF 00 00 FF 00 00  ................
 * 0801D95B  00 FF 00 FF 00 00 00 FF 00 00 7F FF 00 00 FF FF  ................
 * 0801D96B  00 00 FF 00 00 FF FF 00 00 FF 00 00 00 FF 00 FF  ................
 * 0801D97B  00 00 00 FF 00 00 7F FF 00 00 FF FF 00 00 FF 00  ................
 * 0801D98B  00 FF FF 00 00 FF 00 00 00 FF 00 FF 00 00 00 FF  ................
 * 0801D99B  00 00 7F FF 00 00 FF FF 00 00 FF 00 00 FF FF 00  ................
 * 0801D9AB  00 FF 00 00 00 FF 00 FF 00 00 00 FF 00 00 7F FF  ................
 * 0801D9BB  00 00 FF FF 00 00 FF 00 00 FF FF 00 00 FF 00 00  ................
 *   ... (Rest ausgelassen; Gesamt 1137 Bytes)

/* ============================== ENDE ================================= */