/*fake-apt "update.c"
Copyright (C) 2021 NinjaCheetah
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.*/
#include <stdio.h>
// Local headers
#include "../include/update.h"
#include "../include/compat.h"
#include "../include/cpuarch.h"
// Use different headers for Windows
#ifdef _WIN32
#include <Windows.h>
#include <winsock.h>
#else
#include <unistd.h>
#endif
// Start code
int apt_update() {
    // This will (currently at least) never report updates, so it basically just prints out some text
    msleep(1000);
    printf("Get:1 http://ports.ubuntu.com/ubuntu-ports focal InRelease\n");
    fflush(stdout);
    msleep(750);
    printf("Get:2 http://ports.ubuntu.com/ubuntu-ports focal-updates InRelease [114 kB]\n");
    fflush(stdout);
    msleep(750);
    printf("Get:3 http://ports.ubuntu.com/ubuntu-ports focal-backports InRelease [108 kB]\n");
    fflush(stdout);
    msleep(750);
    printf("Get:4 http://ports.ubuntu.com/ubuntu-ports focal-security InRelease [114 kB]\n");
    fflush(stdout);
    msleep(750);
    printf("Get:5 http://ports.ubuntu.com/ubuntu-ports focal-updates/universe %s Packages [852 kB]\n", CPU_ARCH);
    fflush(stdout);
    msleep(750);
    printf("Get:6 http://ports.ubuntu.com/ubuntu-ports focal-updates/multiverse %s Packages [8,228 B]\n", CPU_ARCH);
    fflush(stdout);
    msleep(1000);
    printf("Reading package lists... ");
    fflush(stdout);
    msleep(2000);
    printf("Done\n");
    return(0);
}