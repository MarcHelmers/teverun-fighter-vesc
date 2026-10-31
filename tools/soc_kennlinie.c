/* =====================================================================
 * soc_kennlinie.c - Naeherungsfunktionen der SOC-Kennlinie (R3.4.13)
 * Original: Tabelle @0x0801DC78 (101 x u16 mV, Index = SOC %) in
 *           FUN_0801C1B8 / FUN_0801C1F8 (Binärsuche FUN_0801C162).
 * Fehler gegenueber der Original-Interpolation (max/RMS in %SOC):
 *   Segmente K=5 (empfohlen): 1.10 / 0.54
 *   11 Stuetzstellen:         1.67 / 0.40
 *   Polynom Grad 8:           0.86 / 0.32
 *   Polynom Grad 12:          0.55 / 0.15
 * ===================================================================== */

#include <stdint.h>

/* Originaltabelle (mV je SOC%) */
static const uint16_t soc_mv[101] = {
    3000, 3020, 3040, 3060, 3080, 3100, 3110, 3120, 3130, 3140,
    3150, 3160, 3170, 3180, 3190, 3200, 3210, 3220, 3230, 3240,
    3250, 3266, 3282, 3298, 3314, 3330, 3344, 3358, 3372, 3386,
    3400, 3412, 3423, 3435, 3446, 3458, 3469, 3479, 3490, 3500,
    3511, 3523, 3535, 3546, 3558, 3570, 3581, 3592, 3602, 3613,
    3624, 3634, 3643, 3653, 3662, 3672, 3682, 3691, 3701, 3710,
    3720, 3728, 3736, 3744, 3752, 3760, 3770, 3780, 3790, 3800,
    3810, 3820, 3829, 3839, 3848, 3858, 3871, 3884, 3898, 3911,
    3924, 3934, 3945, 3955, 3966, 3976, 3988, 3999, 4011, 4022,
    4034, 4045, 4057, 4068, 4080, 4091, 4103, 4115, 4127, 4138,
    4150,
};

/* 1) Firmware-aequivalent: Stufenfunktion */
uint8_t soc_from_mv_fw(uint16_t mv)
{
    uint8_t lo = 0, hi = 100;
    while (lo < hi) { uint8_t mid = (uint8_t)((lo + hi + 1) >> 1);
        if (mv >= soc_mv[mid]) lo = mid; else hi = (uint8_t)(mid - 1); }
    return (mv >= soc_mv[0]) ? lo : 0;
}

/* 2) Stuecklinear ueber alle 101 Punkte (Interpolation, 1%-Raster) */
uint8_t soc_from_mv_lin(uint16_t mv)
{
    if (mv <= soc_mv[0]) return 0;
    if (mv >= soc_mv[100]) return 100;
    uint8_t i = 0;
    while (mv >= soc_mv[i + 1]) i++;
    uint32_t num = (uint32_t)(mv - soc_mv[i]) * 100u;
    uint32_t den = (uint32_t)(soc_mv[i + 1] - soc_mv[i]);
    return (uint8_t)(i + (num + den / 2) / den);
}

/* 3) Optimale 5-Segment-Naeherung (DP-optimiert) */
static const uint16_t seg_mv[]  = {3000, 3100, 3200, 3511, 3898, 4150};
static const uint8_t  seg_soc[] = {0, 5, 15, 40, 78, 100};
#define SEG_N (sizeof(seg_mv)/sizeof(seg_mv[0]))
uint8_t soc_from_mv_seg(uint16_t mv)
{
    if (mv <= seg_mv[0]) return seg_soc[0];
    if (mv >= seg_mv[SEG_N-1]) return seg_soc[SEG_N-1];
    uint8_t i = 0; while (mv >= seg_mv[i + 1]) i++;
    uint32_t d = (uint32_t)(mv - seg_mv[i]) * (seg_soc[i + 1] - seg_soc[i]);
    return (uint8_t)(seg_soc[i] + (d + (seg_mv[i+1]-seg_mv[i])/2) / (seg_mv[i+1]-seg_mv[i]));
}

/* 4) Polynomnaeherung Grad 8, t=(mv-3700)/100 */
static const double poly8[9] = {-3.804279476e-06, -1.569477797e-04, -2.050972890e-04, 9.679362513e-03, 9.821609525e-03, -2.166607489e-01, -1.966325738e-02, 1.070190172e+01, 5.832562850e+01};
uint8_t soc_from_mv_poly(double mv)
{
    double t = (mv - 3700.0) / 100.0, s = 0.0;
    for (int i = 0; i < 9; i++) s = s * t + poly8[i];
    if (s < 0.0) s = 0.0; if (s > 100.0) s = 100.0;
    return (uint8_t)(s + 0.5);
}

/* 5) Inverse: SOC -> mV */
uint16_t mv_from_soc(uint8_t soc)
{
    return soc_mv[soc > 100 ? 100 : soc];
}

/* 6) 21-Stuetzstellen-Naeherung (5%-Raster, max. Fehler 0.05 %SOC - praktisch exakt) */
static const uint16_t p21_mv[]  = {3000, 3100, 3200, 3266, 3330, 3400, 3458, 3511, 3570, 3624, 3672, 3720, 3760, 3810, 3858, 3911, 3955, 3999, 4045, 4091, 4150};
static const uint8_t  p21_soc[] = {0, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100};
#define P21_N (sizeof(p21_mv)/sizeof(p21_mv[0]))
uint8_t soc_from_mv_p21(uint16_t mv)
{
    if (mv <= p21_mv[0]) return p21_soc[0];
    if (mv >= p21_mv[P21_N-1]) return p21_soc[P21_N-1];
    uint8_t i = 0; while (mv >= p21_mv[i + 1]) i++;
    uint32_t d = (uint32_t)(mv - p21_mv[i]) * (p21_soc[i + 1] - p21_soc[i]);
    return (uint8_t)(p21_soc[i] + (d + (p21_mv[i+1]-p21_mv[i])/2) / (p21_mv[i+1]-p21_mv[i]));
}
