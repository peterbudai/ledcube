FIRMWARE_DIR = "firmware"
FIRMWARE_TARGET = "out/firmware.elf"

SIMULATOR_DIR = "simulator"
SIMULATOR_TARGET = "out/simulator"

build: $(FIRMWARE_DIR)/$(FIRMWARE_TARGET) $(SIMULATOR_DIR)/$(SIMULATOR_TARGET)

run: build
	$(MAKE) -C $(SIMULATOR_DIR) run

debug: build
	$(MAKE) -C $(SIMULATOR_DIR) debug

clean:
	$(MAKE) -C $(FIRMWARE_DIR) clean
	$(MAKE) -C $(SIMULATOR_DIR) clean

$(FIRMWARE_DIR)/$(FIRMWARE_TARGET):
	$(MAKE) -C $(FIRMWARE_DIR)

$(SIMULATOR_DIR)/$(SIMULATOR_TARGET):
	$(MAKE) -C $(SIMULATOR_DIR)

.PHONY: build run debug clean
