CC = avr-gcc
OBJCOPY = avr-objcopy
MCU = atmega328p
F_CPU = 8000000UL
CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -Wall -Wextra
LDFLAGS = -mmcu=$(MCU)

SRC_DIR = src
BUILD_DIR = build

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

ELF = $(BUILD_DIR)/program.elf
HEX = $(BUILD_DIR)/program.hex

all: $(HEX)

# $(HEX) is the final program we upload to the controller
# and $(ELF) would be the linked binary
$(HEX): $(ELF)
	@mkdir -p $(BUILD_DIR)
	$(OBJCOPY) -O ihex -R .eeprom $< $@

# $@ is the name of the target (bin/program.elf)
# $^ is the name of all pre-requisites (all the object files in this case)
# links all compiled object files to the target
$(ELF): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(LDFLAGS) -o $@ $^

# $@ is the name of the target (eg. file.o)
# $< is the first pre-requisite (eg. file.c in this case)
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(BUILD_DIR)

flash: $(HEX)
	avrdude -c stk500v1 -p $(MCU) -P /dev/ttyUSB0 -b 19200 -U flash:w:$<:i

.PHONY: all clean

