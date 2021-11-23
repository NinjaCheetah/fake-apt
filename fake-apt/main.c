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
#endif
// Start code
void msleep(int time){
    #ifdef _WIN32
      Sleep(time);
    #else
      usleep(time*1000);
    #endif
}
int getRand(int *var,int maxNum){
    // Get the random number, seed is taken from the time
    *var=rand()%maxNum;
    return(0);
}
void clrScrn(){
    // Screen clear fucntion, checks OS first for compatibility:tm:
    #ifdef _WIN32
        system("cls");
    #elif unix
        system("clear");
    #elif __APPLE__
        system( "clear" );
    #endif
}
int main(void){
    // Get all variables and random numbers set
    // Set rand() seed
    srand(time(0));
    // Hostname and Username
    char usr[32];
    #ifdef _WIN32
      DWORD bufSiz = 32;
      GetUserNameA(usr,&bufSiz);
    #else
      char host[64];
      getlogin_r(usr,32);
      gethostname(host,64);
    #endif
    // Number of installed directories (I'm honestly not even sure what that means)
    int installedDirectories;
    getRand(&installedDirectories,8000000);
    // "Coin flip" to see if we're going to get a dependency or not
    int randGetDependencies;
    getRand(&randGetDependencies,2);
    //char *dependencySuffix=malloc(32);
    char dependencySuffix[32];
    char *deps[] = {"-runtime", "-man", "-headers", "-config", "-utils", "-dev", "-data"};
    if(randGetDependencies){
      int selectedDependency;
      getRand(&selectedDependency,8);
      strcpy(dependencySuffix, deps[selectedDependency - 1]);
    }
    // Get archive sizes, second will go unused if coin flip is false
    int archiveSize, archiveSize2;
    getRand(&archiveSize,84);
    getRand(&archiveSize2,64);
    // Combine sizes if there's going to be a dependency, if there's not then don't
    int totalDownSize;
    if(randGetDependencies==1)totalDownSize=archiveSize+archiveSize2;
    else totalDownSize=archiveSize;
    // Get total disk space needed
    int extractSize;
    getRand(&extractSize,64);
    int diskSpace;
    diskSpace=totalDownSize+extractSize;
    // Get download time
    int downloadTime, downloadTime2;
    int downloadRate[6]={50,100,200,250,300,500};
    downloadTime=archiveSize*downloadRate[rand()%6-1];
    downloadTime2=archiveSize2*downloadRate[rand()%6-1];
    // Combine them for the displayed download time
    int totalDownTime;
    totalDownTime=downloadTime+downloadTime2;
    // Get all the various version numbers
    int verMax[4]={25,50,9,9};
    int versions[4];
    int versionsd[4];
    int i;
    for(i=0;i<4;i++){
      getRand(&versions[i],verMax[i]);
    }
    if(randGetDependencies){
      for(i=0;i<4;i++){
        getRand(&versionsd[i],verMax[i]);
      }
    }
    // Start actually doing stuff
    clrScrn();
    #ifdef _WIN32
      // If Windows, use CMD-style prompt format
      printf("C:\\Users\\%s>sudo apt install ",usr);
      fflush(stdout);
    #elif unix
        // If unix, use debian-style prompt format
        printf("\e[1;32m%s@%s\e[0m:\e[1;34m~\e[0m$ sudo apt install ",usr,host);
        fflush(stdout);
    #elif __APPLE__
        // If macOS, use macOS-style prompt format
        int len = strlen(host);
        host[len-6] = '\0';
        printf("%s:~ %s$ sudo apt install ",host,usr);
        fflush(stdout);
    #endif
    char fakePackage[64];
    scanf("%s", fakePackage);
    // Remove newline character
    strtok(fakePackage,"\n");
    // Now that we have the package, we can assemble the dependency using the pre-generated suffix
    char dependency[96];
    if(randGetDependencies==1){
        strcpy(dependency,fakePackage);
        strcat(dependency,dependencySuffix);
    }
    // Fake password prompt
    printf("[sudo] password for %s: ",usr);
    fflush(stdout);
    // Just using a getchar() so you can enter whatever as the password and I don't have to store it
    getchar();
    getchar();
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
    printf("After this operation, %d mB of additional disk space will be used.\nGet:1 http://archive.ubuntu.com/ubuntu focal-updates/universe amd64 %s amd64 %d:%d.%d.%d [%d mB]\n",diskSpace,fakePackage,versions[0],versions[1],versions[2],versions[3],archiveSize);
    msleep(downloadTime);
    // If there's a dependency, download that too
    if(randGetDependencies==1){
        printf("Get:2 http://archive.ubuntu.com/ubuntu focal-updates/universe amd64 %s amd64 %d:%d.%d.%d [%d mB]\n",fakePackage,versionsd[0],versionsd[1],versionsd[2],versionsd[3],archiveSize2);
        msleep(downloadTime2);
    }
    printf("Fetched %d mB in %ds\n",totalDownSize,totalDownTime/1000);
    msleep(850);
    printf("Selecting previously unselected package %s.\n",fakePackage);
    msleep(850);
    printf("(Reading database ... %d files and directories currently installed.)\n",installedDirectories);
    // Use those nice version numbers
    printf("Preparing to unpack .../%s_%d:%d.%d.%d-amd64.deb ...\n",fakePackage,versions[0],versions[1],versions[2],versions[3]);
    msleep(750);
    printf("Unpacking %s (%d:%d.%d.%d) ...\n",fakePackage,versions[0],versions[1],versions[2],versions[3]);
    msleep(2000);
    printf("Setting up %s (%d:%d.%d.%d) ...\n",fakePackage,versions[0],versions[1],versions[2],versions[3]);
    msleep(2000);
    if(randGetDependencies){
      // Say the same thing for the dependency
      printf("Preparing to unpack .../%s_%d:%d.%d.%d-amd64.deb ...\n",dependency,versionsd[0],versionsd[1],versionsd[2],versionsd[3]);
      msleep(750);
      printf("Unpacking %s (%d:%d.%d.%d) ...\n",dependency,versionsd[0],versionsd[1],versionsd[2],versionsd[3]);
      msleep(2000);
      printf("Setting up %s (%d:%d.%d.%d) ...\n",dependency,versionsd[0],versionsd[1],versionsd[2],versionsd[3]);
      msleep(2000);
    }
    // In theory I will update this number if I notice that man-db has had an update
    printf("Processing triggers for man-db (2.9.1-1) ...\n\n");
    msleep(2000);
    return(0);
}
