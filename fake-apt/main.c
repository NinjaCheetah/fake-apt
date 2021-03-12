#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#ifdef _WIN32
#include <winbase.h>
#endif
// Declare variables
char usr[32];
char host[64];
int installedDirectories;
int randGetDependencies = false;
bool getDependencies;
int selectedDependency;
char dependency[96];
char fakePackage[64];
int archiveSize;
int diskSpace;
int extractSize;
int downloadTime;
int archiveSize2;
int downloadTime2;
int totalDownSize;
int totalDownTime;
char dependencySuffix[32];
int v1;
int v2;
int v3;
int v4;
// Start code
int getRand(int *var,int maxNum){
    // Get the random number, seed is taken from the time
    srand(time(0));
    *var = rand() % maxNum;
}
int clrScrn() {
    // Screen clear fucntion, checks OS first for compatibility:tm:
    #ifdef _WIN32
        system("cls");
    #endif
    #ifdef unix
        system("clear");
    #endif
    #ifdef __APPLE__
        system( "clear" );
    #endif
}
int main(void){
    // Get all variables and random numbers set
    // Hostname and Username
    #ifdef _WIN32
        GetUserNameA(usr,32);
    #endif
    #ifdef unix
        getlogin_r(usr,32);
        gethostname(host,64);
    #endif
    #ifdef __APPLE__
        getlogin_r(usr,32);
        gethostname(host,64);
    #endif
    // Number of installed directories (I'm honestly not even sure what that means)
    getRand(&installedDirectories,8000000);
    // "Coin flip" to see if we're going to get a dependency or not
    getRand(&randGetDependencies,2);
    getDependencies=randGetDependencies;
    if(getDependencies==true){
        // Choose what dependency suffix to use if the coin flip was true
        getRand(&selectedDependency,8);
        switch(selectedDependency){
            case 1:
                strcpy(dependencySuffix,"-runtime");
                break;
            case 2:
                strcpy(dependencySuffix,"-man");
                break;
            case 3:
                strcpy(dependencySuffix,"-headers");
                break;
            case 4:
                strcpy(dependencySuffix,"-config");
                break;
            case 5:
                strcpy(dependencySuffix,"-utils");
                break;
            case 6:
                strcpy(dependencySuffix,"-dev");
                break;
            case 7:
                strcpy(dependencySuffix,"-data");
                break;}}
    // Get archive sizes, second will go unused if coin flip is false
    getRand(&archiveSize,96);
    getRand(&archiveSize2,84);
    // Combine sizes if there's going to be a dependency, if there's not then don't
    if(getDependencies==true)totalDownSize=archiveSize+archiveSize2;
    else totalDownSize=archiveSize;
    // Get total disk space needed
    getRand(&extractSize, 84);
    diskSpace=totalDownSize+extractSize;
    // Get download time
    getRand(&downloadTime,8);
    getRand(&downloadTime2,6);
    // Combine them for the displayed download time
    totalDownTime=downloadTime+downloadTime2;
    // Get all the various version numbers
    getRand(&v1,25);
    getRand(&v2,50);
    getRand(&v3,9);
    getRand(&v4,9);
    // Start actually doing stuff
    clrScrn();
    #ifdef _WIN32
    #endif
    #ifdef unix
        // If unix, use unix color scheme
        printf("\e[1;32m%s@%s\e[0m:\e[1;34m~\e[0m$ sudo apt install ",usr,host);
    #endif
    #ifdef __APPLE__
        int len = strlen(host);
        host[len-6] = '\0';
        printf("%s:~ %s$ sudo apt install ",host,usr);
    #endif
    scanf("%s", fakePackage);
    // Remove newline character
    strtok(fakePackage,"\n");
    // Now that we have the package, we can assemble the dependency using the pre-generated suffix
    if(getDependencies==true){
        strcpy(dependency,fakePackage);
        strcat(dependency,dependencySuffix);}
    // Fake password prompt
    printf("[sudo] password for %s: ",usr);
    // Just using a getchar() so you can enter whatever as the password and I don't have to store it
    getchar();
    getchar();
    printf("Reading package lists... ");
    fflush(stdout);
    usleep(850000);
    printf("Done\n");
    printf("Building dependency tree\n");
    usleep(900000);
    printf("Reading state information... ");
    fflush(stdout);
    usleep(900000);
    printf("Done\n");
    // List packages, no need to check if there's a dependency because you won't notice anything if there isn't
    printf("The following NEW packages will be installed:\n");
    printf("  %s  %s\n",fakePackage,dependency);
    // If there's a dependency say 2 new packages, if not say 1
    if(getDependencies==true)printf("0 upgraded, 2 newly installed, 0 to remove and 0 not upgraded.\n");
    else printf("0 upgraded, 1 newly installed, 0 to remove and 0 not upgraded.\n");
    usleep(750000);
    // Get that nice pre-generated archive size and then output how much space it will use
    printf("Need to get %d mB of archives.\n",totalDownSize);
    usleep(250000);
    printf("After this operation, %d mB of additional disk space will be used.\nGet:1 http://archive.ubuntu.com/ubuntu focal-updates/universe amd64 %s amd64 %d:%d.%d.%d [%d mB]\n",diskSpace,fakePackage,v1,v2,v3,v4,archiveSize);
    sleep(downloadTime);
    // If there's a dependency, download that too
    if(getDependencies==true){
        printf("Get:2 http://archive.ubuntu.com/ubuntu focal-updates/universe amd64 %s amd64 [%d mB]\n",fakePackage,archiveSize2);
        sleep(downloadTime2);}
    printf("Fetched %d mB in %ds\n",totalDownSize,totalDownTime);
    usleep(850000);
    printf("Selecting previously unselected package %s.\n",fakePackage);
    usleep(850000);
    printf("(Reading database ... %d files and directories currently installed.)\n",installedDirectories);
    // Use those nice version numbers
    printf("Preparing to unpack .../%s_%d:%d.%d.%d-amd64.deb ...\n",fakePackage,v1,v2,v3,v4);
    usleep(750000);
    printf("Unpacking %s (%d:%d.%d.%d) ...\n",fakePackage,v1,v2,v3,v4);
    sleep(2);
    printf("Setting up %s (%d:%d.%d.%d) ...\n",fakePackage,v1,v2,v3,v4);
    sleep(2);
    // In theory I will update this number if I notice that man-db has had an update
    printf("Processing triggers for man-db (2.9.1-1) ...\n\n");
    sleep(2);
    return(0);
}