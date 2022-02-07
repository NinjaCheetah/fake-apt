CC = gcc
TARGET = fake-apt
WINFLAGS = /W3 /O1 /GS-
WINLIBS = kernel32.lib advapi32.lib ws2_32.lib
CFLAGS = -Wall -O2

all: linux

linux:
	mkdir -p bin/
	$(CC) src/main.c $(CFLAGS) -o bin/$(TARGET)

macX86:
	mkdir -p bin/
	$(CC) src/main.c $(CFLAGS) -target x86_64-apple-macos10.12 -o bin/$(TARGET)X86

macARM:
	mkdir -p bin/
	$(CC) src/main.c $(CFLAGS) -target arm64-apple-macos11 -o bin/$(TARGET)ARM

mac: macX86 macARM
	lipo -create bin/$(TARGET)X86 bin/$(TARGET)ARM -output bin/$(TARGET)-macOS
	rm bin/$(TARGET)X86
	rm bin/$(TARGET)ARM

clean:
	rm -rf bin/
