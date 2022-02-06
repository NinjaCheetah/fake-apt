/*fake-apt "main.c"
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
#include <stdlib.h>
#include <time.h>
#include <string.h>
// Use different headers in Windows
#ifdef _WIN32
    #include <Windows.h>
    #include <winsock.h>
#else
    #include <unistd.h>
    #define _countOf(x) (sizeof(x)/sizeof(*(x)))
#endif
// Set architecture
#if defined __aarch64__ || defined _M_ARM64
  char g_arch[]="arm64";
#elif defined i386 || defined __i386__ || defined __i386 || defined _M_IX86
  char g_arch[]="i386";
#else
  char g_arch[]="amd64";
#endif
// Start code
void msleep(int time){
    #ifdef _WIN32
      Sleep(time);
    #else
      usleep(time*1000);
    #endif
}
int getRand(int maxNum){
    // Get the random number, seed is taken from the time
    return(rand() % maxNum);
}
int main(int argc,char *argv[]){
    // Check args, abort if too few are passed
    if(argc < 2) {
        printf("Please specify an argument!\n");
        return(0);
    }
    if(argc < 3 && (strcmp(argv[1], "install") == 0)) {
        printf("Please specify the package you want to install!\n");
        return(0);
    }
    // Get all variables and random numbers set
    // Seed rand()
    srand(time(0));
    // Number of installed directories (I'm honestly not even sure what that means)
    int installedDirectories = getRand(8000000);
    // "Coin flip" to see if we're going to get a dependency or not
    int randGetDependencies = getRand(2);
    char *deps[] = {"-runtime", "-man", "-headers", "-config", "-utils", "-dev", "-data"};
    int selectedDependency = getRand(_countOf(deps));
    // Get archive sizes, second will go unused if coin flip is false
    int archiveSize = getRand(84);
    int archiveSize2 = getRand(64);
    // Combine sizes if there's going to be a dependency, if there's not then don't
    int totalDownSize;
    if(randGetDependencies == 1) totalDownSize = archiveSize + archiveSize2;
    else totalDownSize = archiveSize;
    // Get total disk space needed
    int extractSize = getRand(64);
    int diskSpace = totalDownSize + extractSize;
    // Get download time
    int downloadRate[6]={50,100,200,250,300,500};
    int downloadTime = archiveSize * downloadRate[getRand(6)];
    int downloadTime2 = archiveSize2 * downloadRate[getRand(6)];
    // Combine them for the displayed download time
    int totalDownTime = downloadTime + downloadTime2;
    // Get all the various version numbers
    int verMax[4]={25,50,9,9};
    int versions[4];
    int versionsd[4];
    int i;
    for(i=0;i<4;i++){
      versions[i] = getRand(verMax[i]);
    }
    if(randGetDependencies){
      for(i=0;i<4;i++){
        versionsd[i] = getRand(verMax[i]);
      }
    }
    char *fakePackage = argv[2];
    // Remove newline character, if it exists
    strtok(fakePackage,"\n");
    // Now that we have the package, we can assemble the dependency using the pre-generated suffix
    char dependency[96];
    if(randGetDependencies == 1){
        strcpy(dependency,fakePackage);
        strcat(dependency,deps[selectedDependency]);
    }
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
    // List packages, no need to check if there's a dependency because you won't notice anything if there isn't
    printf("The following NEW packages will be installed:\n");
    printf("  %s  %s\n",fakePackage,dependency);
    // If there's a dependency say 2 new packages, if not say 1
    if(randGetDependencies==1)printf("0 upgraded, 2 newly installed, 0 to remove and 0 not upgraded.\n");
    else printf("0 upgraded, 1 newly installed, 0 to remove and 0 not upgraded.\n");
    msleep(750);
    // Get that nice pre-generated archive size and then output how much space it will use
    printf("Need to get %d mB of archives.\n",totalDownSize);
    msleep(250);
    printf("After this operation, %d mB of additional disk space will be used.\nGet:1 http://archive.ubuntu.com/ubuntu focal-updates/universe %s %s %s %d:%d.%d.%d [%d mB]\n",diskSpace,g_arch,fakePackage,g_arch,versions[0],versions[1],versions[2],versions[3],archiveSize);
    msleep(downloadTime);
    // If there's a dependency, download that too
    if(randGetDependencies==1){
        printf("Get:2 http://archive.ubuntu.com/ubuntu focal-updates/universe %s %s %s %d:%d.%d.%d [%d mB]\n",g_arch,fakePackage,g_arch,versionsd[0],versionsd[1],versionsd[2],versionsd[3],archiveSize2);
        msleep(downloadTime2);
    }
    printf("Fetched %d mB in %ds\n",totalDownSize,totalDownTime/1000);
    msleep(850);
    printf("Selecting previously unselected package %s.\n",fakePackage);
    msleep(850);
    printf("(Reading database ... %d files and directories currently installed.)\n",installedDirectories);
    // Use those nice version numbers
    printf("Preparing to unpack .../%s_%d:%d.%d.%d-%s.deb ...\n",fakePackage,versions[0],versions[1],versions[2],versions[3],g_arch);
    msleep(750);
    printf("Unpacking %s (%d:%d.%d.%d) ...\n",fakePackage,versions[0],versions[1],versions[2],versions[3]);
    msleep(2000);
    printf("Setting up %s (%d:%d.%d.%d) ...\n",fakePackage,versions[0],versions[1],versions[2],versions[3]);
    msleep(2000);
    if(randGetDependencies){
      // Say the same thing for the dependency
      printf("Preparing to unpack .../%s_%d:%d.%d.%d-%s.deb ...\n",dependency,versionsd[0],versionsd[1],versionsd[2],versionsd[3],g_arch);
      msleep(750);
      printf("Unpacking %s (%d:%d.%d.%d) ...\n",dependency,versionsd[0],versionsd[1],versionsd[2],versionsd[3]);
      msleep(2000);
      printf("Setting up %s (%d:%d.%d.%d) ...\n",dependency,versionsd[0],versionsd[1],versionsd[2],versionsd[3]);
      msleep(2000);
    }
    // In theory, I will update this number if I notice that man-db has had an update
    printf("Processing triggers for man-db (2.9.1-1) ...\n\n");
    msleep(2000);
    return(0);
}
