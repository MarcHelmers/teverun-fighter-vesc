# ============================================================================
#  ivcu_fw -- Makefile (arm-none-eabi-gcc)
#  ---------------------------------------------------------------------------
#  Eigene IVCU-Firmware: ersetzt den Original-App-Bereich der Teverun-IVCU
#  (GD32F303-Klasse / STM32F1-artige Peripherie) und arbeitet direkt mit einem
#  VESC zusammen (Bridge-Protokoll 8 Byte '54 cmd p0..p4 XOR'), waehrend
#  Stock-Display (USART3) und Stock-BLE-Modul (USART1, Teverun-App) bleiben.
#
#  BAUEN:
#     make            -> build/ivcu_fw.elf + .bin + .hex + Groessenausgabe
#     make clean
#
#  FLASHEN (Beispiel, ST-Link + OpenOCD):
#     openocd -f interface/stlink.cfg -f target/stm32f1x.cfg \
#             -c "program build/ivcu_fw.hex verify reset exit"
#  (GD32F303 laeuft in der Praxis als STM32F1-Ziel; alternativ GD32-cfg.)
#
#  Flash-Strategie: Standard = VOLLERSATZ ab 0x08000000 (ld/ivcu_full.ld,
#  Bootloader entfaellt). Variante "Bootloader-Fenster" siehe ld/ivcu_app_boot.ld
#  + Abschnitt "Flash-Strategie" in README.md.
# ============================================================================

TARGET   := ivcu_fw
BUILD    := build
LDSCRIPT := ld/ivcu_full.ld

CC       := arm-none-eabi-gcc
OBJCOPY  := arm-none-eabi-objcopy
SIZE     := arm-none-eabi-size

# Cortex-M3 = 7-M-Kompatibilitaets-Subset; laeuft auf dem Cortex-M4F der IVCU.
# (Optional -mcpu=cortex-m4 ohne FPU; FPU wird von dieser Firmware nicht genutzt.)
CFLAGS   := -mcpu=cortex-m3 -mthumb -O2 -g3 \
            -Wall -Wextra -std=gnu11 \
            -ffunction-sections -fdata-sections \
            -Iinclude

LDFLAGS  := -T$(LDSCRIPT) -nostartfiles \
            -Wl,--gc-sections -Wl,-Map=$(BUILD)/$(TARGET).map

SRCS     := $(wildcard src/*.c)
OBJS     := $(patsubst src/%.c,$(BUILD)/%.o,$(SRCS))

.PHONY: all clean flash size

all: $(BUILD)/$(TARGET).elf $(BUILD)/$(TARGET).bin $(BUILD)/$(TARGET).hex size

$(BUILD)/%.o: src/%.c | $(BUILD)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD)/$(TARGET).elf: $(OBJS) $(LDSCRIPT)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $@

$(BUILD)/$(TARGET).bin: $(BUILD)/$(TARGET).elf
	$(OBJCOPY) -O binary $< $@

$(BUILD)/$(TARGET).hex: $(BUILD)/$(TARGET).elf
	$(OBJCOPY) -O ihex $< $@

size: $(BUILD)/$(TARGET).elf
	$(SIZE) $<

$(BUILD):
	mkdir -p $(BUILD)

clean:
	rm -rf $(BUILD)

# Komfort-Ziel (OpenOCD muss im PATH sein; Ziel-Config ggf. anpassen):
flash: $(BUILD)/$(TARGET).hex
	openocd -f interface/stlink.cfg -f target/stm32f1x.cfg \
	        -c "program $< verify reset exit"
