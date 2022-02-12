TARGET = fake-apt

WINFLAGS = /c /W3 /O1 /GS- /Fo.\bin\\

WINLIBS = kernel32.lib advapi32.lib ws2_32.lib

win:
	mkdir bin
	cl $(WINFLAGS) src\main.c
	cl $(WINFLAGS) src\install.c
	cl $(WINFLAGS) src\search.c
	cl $(WINFLAGS) src\update.c
	cl $(WINFLAGS) src\upgrade.c
	cl $(WINFLAGS) src\reinstall.c
	link bin\main.obj bin\install.obj bin\search.obj bin\update.obj bin\upgrade.obj bin\reinstall.obj $(WINLIBS) /RELEASE /EMITPOGOPHASEINFO /MANIFEST:NO /DEBUG:NONE /SUBSYSTEM:CONSOLE /SAFESEH:NO /OUT:bin\$(TARGET).exe

clean:
	rm -rf bin/
