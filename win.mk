TARGET = fake-apt

WINFLAGS = /c /W3 /O1 /GS- /Fo.\bin\\

WINLIBS = kernel32.lib advapi32.lib ws2_32.lib

SRC_DIRS ?= ./src

SRCS := $(shell find $(SRC_DIRS) -name *.c)

win:
	mkdir bin
	cl $(WINFLAGS) src\*.c
#cl $(WINFLAGS) src\install.c
#cl $(WINFLAGS) src\search.c
#cl $(WINFLAGS) src\update.c
#cl $(WINFLAGS) src\upgrade.c
	link bin\* $(WINLIBS) /RELEASE /EMITPOGOPHASEINFO /MANIFEST:NO /DEBUG:NONE /SUBSYSTEM:CONSOLE /SAFESEH:NO /OUT:bin\$(TARGET).exe
#cl $(WINFLAGS) $(SRCS) /link $(WINLIBS) /RELEASE /EMITPOGOPHASEINFO /MANIFEST:NO /DEBUG:NONE /SUBSYSTEM:CONSOLE /SAFESEH:NO /OUT:bin\$(TARGET).exe


clean:
	rm -rf bin/
