TARGET_EXEC ?= fake-apt

CC = gcc
CFLAGS = -Wall -O2

BUILD_DIR ?= ./bin
SRC_DIRS ?= ./src
INC_DIRS ?= ./include

SRCS := $(shell find $(SRC_DIRS) -name *.c)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

# C source
$(BUILD_DIR)/%.c.o: %.c
	$(MKDIR_P) $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Build universal Mac executable
mac:
	$(MKDIR_P) $(BUILD_DIR)/./$(SRC_DIRS)/
	$(CC) $(SRCS) $(CFLAGS) -target x86_64-apple-macos10.12 -o $(BUILD_DIR)/$(TARGET)X86 $(LDFLAGS)
	$(MKDIR_P) $(BUILD_DIR)/./$(SRC_DIRS)/
	$(CC) $(SRCS) $(CFLAGS) -target arm64-apple-macos11 -o $(BUILD_DIR)/$(TARGET)ARM $(LDFLAGS)
	lipo -create $(BUILD_DIR)/$(TARGET)X86 $(BUILD_DIR)/$(TARGET)ARM -output $(BUILD_DIR)/$(TARGET_EXEC)
	rm $(BUILD_DIR)/$(TARGET)X86
	rm $(BUILD_DIR)/$(TARGET)ARM

.PHONY: clean

clean:
	$(RM) -r $(BUILD_DIR)

-include $(DEPS)

MKDIR_P ?= mkdir -p