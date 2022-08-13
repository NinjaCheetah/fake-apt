/*fake-apt "update.c"
Copyright (C) 2022 NinjaCheetah
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
#include "../include/src/update.h"
#include "../include/src/base.h"
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
    char* apt_get_url = apt_fetch_get_url();
    char* apt_get_os = apt_fetch_os();
    msleep(1000);
    printf("Get:1 %s %s InRelease\n", apt_get_url, apt_get_os);
    fflush(stdout);
    msleep(750);
    printf("Get:2 %s %s-updates InRelease [114 kB]\n", apt_get_url, apt_get_os);
    fflush(stdout);
    msleep(750);
    printf("Get:3 %s %s-backports InRelease [108 kB]\n", apt_get_url, apt_get_os);
    fflush(stdout);
    msleep(750);
    printf("Get:4 %s %s-security InRelease [114 kB]\n", apt_get_url, apt_get_os);
    fflush(stdout);
    msleep(750);
    printf("Get:5 %s %s-updates/universe %s Packages [852 kB]\n", apt_get_url, apt_get_os, CPU_ARCH);
    fflush(stdout);
    msleep(750);
    printf("Get:6 %s %s-updates/multiverse %s Packages [8,228 B]\n", apt_get_url, apt_get_os, CPU_ARCH);
    fflush(stdout);
    msleep(1000);
    printf("Reading package lists... ");
    fflush(stdout);
    msleep(2000);
    printf("Done\n");
    return(0);
}