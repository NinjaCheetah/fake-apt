TARGET = fake-apt

CC = gcc
CFLAGS = -Wall -O2

BUILD_DIR ?= ./bin
SRC_DIRS ?= ./src
INC_DIRS ?= ./include

SRCS := $(shell find $(SRC_DIRS) -name *.c)

INC_FLAGS := $(addprefix -I,$(INC_DIRS))

mac: macX86 macARM
	lipo -create bin/$(TARGET)X86 bin/$(TARGET)ARM -output bin/$(TARGET)
	rm bin/$(TARGET)X86
	rm bin/$(TARGET)ARM

macX86:
	$(MKDIR_P) bin/./src/
	$(CC) $(SRCS) $(CFLAGS) -target x86_64-apple-macos10.12 -o $(BUILD_DIR)/$(TARGET)X86 $(LDFLAGS)

macARM:
	$(MKDIR_P) bin/./src/
	$(CC) $(SRCS) $(CFLAGS) -target arm64-apple-macos11 -o $(BUILD_DIR)/$(TARGET)ARM $(LDFLAGS)

.PHONY: clean

clean:
	rm -rf bin/

MKDIR_P ?= mkdir -p