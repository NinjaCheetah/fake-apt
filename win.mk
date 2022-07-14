TARGET = fake-apt

WINFLAGS = /c /W3 /O1 /GS- /Fo.\bin\\

WINLIBS = kernel32.lib advapi32.lib ws2_32.lib

win:
	mkdir bin
	cl $(WINFLAGS) src\main.c
	cl $(WINFLAGS) src\base.c
	cl $(WINFLAGS) src\install.c
	cl $(WINFLAGS) src\search.c
	cl $(WINFLAGS) src\update.c
	cl $(WINFLAGS) src\upgrade.c
	cl $(WINFLAGS) src\reinstall.c
	cl $(WINFLAGS) src\remove.c
	cl $(WINFLAGS) src\list.c
	cl $(WINFLAGS) src\show.c
	cl $(WINFLAGS) src\satisfy.c
	cl $(WINFLAGS) src\editsources.c
	link bin\main.obj bin\base.obj bin\install.obj bin\search.obj bin\update.obj bin\upgrade.obj bin\reinstall.obj bin\remove.obj bin\list.obj bin\show.obj bin\satisfy.obj bin\editsources.obj $(WINLIBS) /RELEASE /EMITPOGOPHASEINFO /MANIFEST:NO /DEBUG:NONE /SUBSYSTEM:CONSOLE /SAFESEH:NO /OUT:bin\$(TARGET).exe

clean:
	rm -rf bin/
