CC = gcc
TARGET = fake-apt
CFLAGS = -Wall -O2

all: linux

linux:
	mkdir -p bin/
	$(CC) $(TARGET)/main.c $(CFLAGS) -o bin/$(TARGET)

# Note that the mac executables can only be compiled on mac
mac:
	mkdir -p bin/
	gcc -target x86_64-apple-macos10.12 $(TARGET)/main.c $(CFLAGS) -o bin/$(TARGET)X86

macARM:
	mkdir -p bin/
	gcc -target arm64-apple-macos11 $(TARGET)/main.c $(CFLAGS) -o bin/$(TARGET)ARM

clean:
	rm -rf bin/
