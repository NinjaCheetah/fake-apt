CC = gcc
TARGET = fake-apt
CFLAGS = -Wall -O2

mac: macX86 macARM
	lipo -create bin/$(TARGET)X86 bin/$(TARGET)ARM -output bin/$(TARGET)
	rm bin/$(TARGET)X86
	rm bin/$(TARGET)ARM

macX86:
	mkdir -p bin/./src/
	$(CC) -c src/main.c $(CFLAGS) -target x86_64-apple-macos10.12 -o bin/src/main.c.o
	$(CC) -c src/install.c $(CFLAGS) -target x86_64-apple-macos10.12 -o bin/src/install.c.o
	$(CC) bin/src/main.c.o bin/src/install.c.o -target x86_64-apple-macos10.12 -o bin/$(TARGET)X86

macARM:
	mkdir -p bin/./src/
	$(CC) -c src/main.c $(CFLAGS) -target arm64-apple-macos11 -o bin/src/main.c.o
	$(CC) -c src/install.c $(CFLAGS) -target arm64-apple-macos11 -o bin/src/install.c.o
	$(CC) bin/src/main.c.o bin/src/install.c.o -target arm64-apple-macos11 -o bin/$(TARGET)ARM

clean:
	rm -rf bin/