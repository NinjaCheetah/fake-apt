/*fake-apt "remove.c"
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
#include "../include/src/remove.h"
#include "../include/src/base.h"
#include "../include/version.h"
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
int apt_remove(int argc, char *argv[]) {
    if(argc < 3) {
        // Say nothing will change
        apt_init();
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
    // Get total disk space needed
    int extractSize = qrand(64);
    int diskSpace = archiveSize + extractSize;
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
    // Now that we have the package, we can assemble the dependency using the pre-generated suffix
    char dependency[96];
    // Run the fake install
    apt_init();
    // List packages, no need to check if there's a dependency because you won't notice anything if there isn't
    printf("The following packages will be REMOVED:\n");
    printf("  %s  %s\n",fakePackage,dependency);
    // If there's a dependency say 2 new packages, if not say 1
    printf("0 upgraded, 0 newly installed, 1 to remove and 0 not upgraded.\n");
    msleep(750);
    // Get that nice pre-generated archive size and then output how much space it will use
    printf("After this operation, %d mB disk space will be freed.\n", diskSpace);
    msleep(850);
    printf("Do you want to continue? [Y/n] ");
    int chkAbort = getchar();
    if(chkAbort == 78 || chkAbort == 110) {
        printf("Abort.\n");
        return(1);
    }
    printf("(Reading database ... %d files and directories currently installed.)\n", installedDirectories);
    msleep(850);
    // Use those nice version numbers
    printf("Removing %s (%d:%d.%d.%d) ...\n", fakePackage, versions[0], versions[1], versions[2], versions[3]);
    msleep(2000);
    // In theory, I will update this number if I notice that man-db has had an update
    printf("Processing triggers for man-db (%s) ...\n\n", MAN_DB_VERSION);
    msleep(2000);
    return (0);
}

int apt_autoremove() {
    // Run apt autoremove, always says no packages need to be removed
    msleep(500);
    printf("Reading package lists... ");
    fflush(stdout);
    msleep(1000);
    printf("Done\n");
    printf("Building dependency tree\n");
    fflush(stdout);
    msleep(900);
    printf("Reading state information... ");
    fflush(stdout);
    msleep(900);
    printf("Done\n");
    fflush(stdout);
    msleep(500);
    printf("0 upgraded, 0 newly installed, 0 to remove and 0 not upgraded.\n");
    return(0);
}
