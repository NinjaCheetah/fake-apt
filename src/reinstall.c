/*fake-apt "reinstall.c"
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
#include <string.h>
// Local headers
#include "../include/src/reinstall.h"
#include "../include/version.h"
#include "../include/cpuarch.h"
#include "../include/compat.h"
#include "../include/qrand.h"
// Use different headers in Windows
#ifdef _WIN32
#include <Windows.h>
    #include <winsock.h>
#else
#include <unistd.h>
#endif
// Start code
int apt_reinstall(int argc, char *argv[]) {
    if(argc < 3) {
        // Run start of apt install (this is what real apt will do)
        msleep(500);
        printf("Reading package lists... ");
        fflush(stdout);
        msleep(850);
        printf("Done\n");
        printf("Building dependency tree\n");
        msleep(900);
        printf("Reading state information... ");
        fflush(stdout);
        msleep(900);
        printf("Done\n");
        msleep(750);
        printf("0 upgraded, 0 newly installed, 0 to remove and 0 not upgraded.\n");
        return(1);
    }
    // Get all variables and random numbers set
    // Seed rand()
    srand(time(0));
    // Number of installed directories (I'm honestly not even sure what that means)
    int installedDirectories = qrand(8000000);
    // Get archive sizes, second will go unused if coin flip is false
    int archiveSize = qrand(84);
    // Get download time
    int downloadRate[6]={50,100,200,250,300,500};
    int downloadTime = archiveSize * downloadRate[qrand(6)];
    // Get all the various version numbers
    int verMax[4]={25,50,9,9};
    int versions[4];
    int i;
    for(i=0;i<4;i++){
        versions[i] = qrand(verMax[i]);
    }
    char *fakePackage = argv[2];
    // Remove newline character, if it exists
    strtok(fakePackage,"\n");
    // Run the fake install
    msleep(500);
    printf("Reading package lists... ");
    fflush(stdout);
    msleep(850);
    printf("Done\n");
    printf("Building dependency tree\n");
    msleep(900);
    printf("Reading state information... ");
    fflush(stdout);
    msleep(900);
    printf("Done\n");
    // If there's a dependency say 2 new packages, if not say 1
    printf("0 upgraded, 0 newly installed, 1 reinstalled, 0 to remove and 0 not upgraded.\n");
    msleep(750);
    // Get that nice pre-generated archive size and then output how much space it will use
    printf("Need to get %d mB of archives.\n", archiveSize);
    msleep(250);
    printf("After this operation, 0 B of additional disk space will be used.\nGet:1 http://archive.ubuntu.com/ubuntu jammy-updates/universe %s %s %s %d:%d.%d.%d [%d mB]\n",CPU_ARCH,fakePackage,CPU_ARCH,versions[0],versions[1],versions[2],versions[3],archiveSize);
    msleep(downloadTime);
    printf("Fetched %d mB in %ds\n", archiveSize, downloadTime / 1000);
    msleep(850);
    printf("Selecting previously unselected package %s.\n",fakePackage);
    msleep(850);
    printf("(Reading database ... %d files and directories currently installed.)\n",installedDirectories);
    // Use those nice version numbers
    printf("Preparing to unpack .../%s_%d:%d.%d.%d-%s.deb ...\n",fakePackage,versions[0],versions[1],versions[2],versions[3],CPU_ARCH);
    msleep(750);
    printf("Unpacking %s (%d:%d.%d.%d) over (%d:%d.%d.%d) ...\n",fakePackage,versions[0],versions[1],versions[2],versions[3],versions[0],versions[1],versions[2],versions[3]);
    msleep(2000);
    printf("Setting up %s (%d:%d.%d.%d) ...\n",fakePackage,versions[0],versions[1],versions[2],versions[3]);
    msleep(2000);
    // In theory, I will update this number if I notice that man-db has had an update
    printf("Processing triggers for man-db (%s) ...\n\n", MAN_DB_VERSION);
    msleep(2000);
    return(0);
}
