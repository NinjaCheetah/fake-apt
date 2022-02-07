CC = gcc
TARGET = fake-apt
CFLAGS = -Wall -O2

mac: macX86 macARM
	lipo -create bin/$(TARGET)X86 bin/$(TARGET)ARM -output bin/$(TARGET)-macOS
	rm bin/$(TARGET)X86
	rm bin/$(TARGET)ARM

macX86:
	mkdir -p bin/
	$(CC) src/main.c $(CFLAGS) -target x86_64-apple-macos10.12 -o bin/$(TARGET)X86

macARM:
	mkdir -p bin/
	$(CC) src/main.c $(CFLAGS) -target arm64-apple-macos11 -o bin/$(TARGET)ARM

clean:
	rm -rf bin/