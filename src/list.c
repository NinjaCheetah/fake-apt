/*fake-apt "list.c"
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
#include <stdlib.h>
#include <time.h>
// Local headers
#include "../include/src/list.h"
#include "../include/cpuarch.h"
#include "../include/compat.h"
#include "../include/qrand.h"
#include "../include/version.h"
// Use different headers in Windows
#ifdef _WIN32
#include <Windows.h>
    #include <winsock.h>
#else
#include <unistd.h>
#endif
// Start code
int apt_list(int argc,char *argv[]) {
    if(argc < 3) {
        // List all installed packages, which in this case will always just be apt
        printf("Listing... ");
        fflush(stdout);
        msleep(1500);
        printf("Done\n");
        fflush(stdout);
        msleep(500);
        printf("\e[0;32mapt\e[0m/stable,now %s %s [installed]\n", APT_VERSION, CPU_ARCH);
        return(1);
    }
    // List the provided package as installed with a random version and the current CPU architecture
    printf("Listing... ");
    fflush(stdout);
    msleep(1500);
    printf("Done\n");
    fflush(stdout);
    msleep(500);
    srand(time(0));
    int verMax[4]={25,50,9,9};
    int versions[4];
    int i;
    for(i=0;i<4;i++){
        versions[i] = qrand(verMax[i]);
    }
    printf("\e[0;32m%s\e[0m/stable,now %d:%d.%d.%d %s [installed]\n", argv[2], versions[0], versions[1], versions[2], versions[3], CPU_ARCH);
    return(0);
}
