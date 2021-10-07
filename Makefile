CC = gcc
TARGET = fake-apt
CFLAGS = -Wall -O2

all: linux

linux:
	mkdir -p bin/
	$(CC) $(TARGET)/main.c $(CFLAGS) -o bin/$(TARGET)

# Note that the mac executables can only be compiled on mac
macX86:
	mkdir -p bin/
	$(CC) $(TARGET)/main.c $(CFLAGS) -target x86_64-apple-macos10.12 -o bin/$(TARGET)X86

macARM:
	mkdir -p bin/
	$(CC) $(TARGET)/main.c $(CFLAGS) -target arm64-apple-macos11 -o bin/$(TARGET)ARM

mac: macX86 macARM
	lipo -create bin/$(TARGET)X86 bin/$(TARGET)ARM -output bin/$(TARGET)-macOS
	rm bin/$(TARGET)X86
	rm bin/$(TARGET)ARM

clean:
	rm -rf bin/
