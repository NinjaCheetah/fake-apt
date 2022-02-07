TARGET = fake-apt
WINFLAGS = /c /W3 /O1 /GS- /F.\bin\
WINLIBS = kernel32.lib advapi32.lib ws2_32.lib

win:
	mkdir bin
	cl $(WINFLAGS) src\main.c
	cl $(WINFLAGS) src\install.c
	link bin\main.obj bin\install.obj $(WINLIBS) /RELEASE /EMITPOGOPHASEINFO /MANIFEST:NO /DEBUG:NONE /SUBSYSTEM:CONSOLE /SAFESEH:NO /OUT:bin\$(TARGET).exe

clean:
	rm -rf bin/