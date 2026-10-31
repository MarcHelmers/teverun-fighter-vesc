// ============================================================================
//  can_sniffer_esp32 -- passiver BMS-CAN-Mitschnitt (Listen-Only!)
//  ---------------------------------------------------------------------------
//  Zweck: CAN-IDs/Layout des Teverun-BMS-Busses klären (offener Punkt der
//  Analyse). Es wird NICHTS gesendet (TWAI_MODE_LISTEN_ONLY) - der Sniffer
//  kann den Bus nicht stoeren.
//
//  Ausgabe (115200 Bd, eine Zeile je Frame):
//     t=<ms>  id=0x123  ext=0  dlc=8  data=00 11 22 33 44 55 66 77
//
//  Danach die Logdatei mit ivcu_esc_sniffer.py?  -> NEIN: das ist der
//  UART-Sniffer fuer den ESC-Bus. Fuer CAN: IDs/Perioden manuell sichten
//  oder spaeter in ein eigenes DBC/Decoder-Tool giessen.
// ============================================================================
#include <Arduino.h>
#include "driver/twai.h"
#include "can_sniffer_config.h"

static void can_init()
{
    twai_general_config_t g = TWAI_GENERAL_CONFIG_DEFAULT(
        (gpio_num_t)PIN_CAN_TX, (gpio_num_t)PIN_CAN_RX, TWAI_MODE_LISTEN_ONLY);
    g.rx_queue_len = 64;

#if CAN_BITRATE == 250000
    twai_timing_config_t t = TWAI_TIMING_CONFIG_250KBITS();
#elif CAN_BITRATE == 1000000
    twai_timing_config_t t = TWAI_TIMING_CONFIG_1MBITS();
#elif CAN_BITRATE == 125000
    twai_timing_config_t t = TWAI_TIMING_CONFIG_125KBITS();
#else
    twai_timing_config_t t = TWAI_TIMING_CONFIG_500KBITS();
#endif

    twai_filter_config_t f = TWAI_FILTER_CONFIG_ACCEPT_ALL();

    if (twai_driver_install(&g, &t, &f) != ESP_OK) {
        Serial.println("# TWAI-Install fehlgeschlagen");
        return;
    }
    if (twai_start() != ESP_OK) {
        Serial.println("# TWAI-Start fehlgeschlagen");
        return;
    }
    Serial.printf("# BMS-CAN-Sniffer aktiv (Listen-Only), Bitrate %d\n", CAN_BITRATE);
}

void setup()
{
    Serial.begin(SNIFFER_SERIAL_BAUD);
    delay(300);
    can_init();
}

void loop()
{
    twai_message_t msg;
    if (twai_receive(&msg, pdMS_TO_TICKS(1000)) != ESP_OK) {
        return;                                  // Timeout/Fehler: weiter warten
    }
    Serial.printf("t=%lu  id=0x%03lX  ext=%u  dlc=%u  data=",
                  (unsigned long)millis(), (unsigned long)msg.identifier,
                  msg.extd ? 1u : 0u, msg.data_length_code);
    for (uint8_t i = 0; i < msg.data_length_code && i < 8; i++) {
        Serial.printf("%02X%s", msg.data[i], (i + 1 < msg.data_length_code) ? " " : "");
    }
    Serial.println();
}
