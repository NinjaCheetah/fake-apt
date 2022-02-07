TARGET = fake-apt
WINFLAGS = /W3 /O1 /GS-
WINLIBS = kernel32.lib advapi32.lib ws2_32.lib

win:
	mkdir bin
	cl $(WINFLAGS) src\main.c /link $(WINLIBS) /out:bin\$(TARGET).exe