/*fake-apt "satisfy.c"
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
#include "../include/src/satisfy.h"
#include "../include/compat.h"
// Use different headers in Windows
#ifdef _WIN32
#include <Windows.h>
    #include <winsock.h>
#else
#include <unistd.h>
#endif
// Start code
int apt_satisfy(int argc) {
    if(argc < 3) {
        msleep(750);
        printf("\e[0;91mE: \e[0mMust specify at least one package to check builddeps for\n");
        return(-1);
    }
    // Just say that package doesn't need to be satisfied
    msleep(500);
    printf("Reading package lists... ");
    fflush(stdout);
    msleep(850);
    printf("Done\n");
    printf("Building dependency tree... ");
    fflush(stdout);
    msleep(900);
    printf("Done\n");
    printf("Reading state information... ");
    fflush(stdout);
    msleep(900);
    printf("Done\n");
    msleep(750);
    printf("0 upgraded, 0 newly installed, 0 to remove and 0 not upgraded.\n");
    return(0);
}
