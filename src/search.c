/*fake-apt "search.c"
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
#include "../include/src/search.h"
#include "../include/src/base.h"
#include "../include/compat.h"
// Use different headers for Windows
#ifdef _WIN32
    #include <Windows.h>
    #include <winsock.h>
#else
    #include <unistd.h>
#endif
// Start code
int apt_search(int argc,char *argv[]) {
    if(argc < 3) {
        printf("\e[0;91mE: \e[0mYou must give at least one search pattern\n");
        return(-1);
    }
    // Perform a fake search for the package name provided
    msleep(500);
    printf("Sorting... ");
    fflush(stdout);
    msleep(1000);
    printf("Done\n");
    printf("Full Text Search... ");
    fflush(stdout);
    msleep(1000);
    printf("Done\n");
    fflush(stdout);
    int versions[4];
    apt_create_version(versions);
    printf("\e[0;32m%s\e[0m/jammy %d:%d.%d.%d all\n\n", argv[2], versions[0], versions[1], versions[2], versions[3]);
    return(0);
}
