/*fake-apt "show.c"
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
// Local headers
#include "../include/src/show.h"
#include "../include/src/base.h"
#include "../include/cpuarch.h"
#include "../include/compat.h"
#include "../include/qrand.h"
#include "../include/words.h"
// Use different headers in Windows
#ifdef _WIN32
#include <Windows.h>
    #include <winsock.h>
#else
#include <unistd.h>
#endif
// Start code
int countWords(unsigned char *buffer,int size){
    // Count number of words in the file based on newlines
    int numWords=0,i;
    for(i=0;i<size;i++){
        char c=buffer[i];
        if(c=='\n'||i==size-1)numWords++;
    }
    return numWords;
}
int apt_show(int argc,char *argv[]) {
    if(argc < 3) {
        msleep(750);
        printf("\e[0;91mE: \e[0mNo packages found\n");
        return(-1);
    }
    // Provide information about the specified package
    msleep(1000);
    int i;
    int versions[4];
    apt_create_version(versions);
    int downloadSize = qrand(64);
    int installedSize = qrand(64) + downloadSize;
    printf("Package: %s\n", argv[2]);
    printf("Version: %d.%d.%d-%d\n", versions[0], versions[1], versions[2], versions[3]);
    printf("Priority: optional\n");
    printf("Section: utils\n");
    printf("Maintainer: NinjaCheetah <ninjacheetah@ncxprogramming.com>\n");
    printf("Installed-Size: %d mB\n", installedSize);
    printf("Homepage: https://github.com/NinjaCheetah/fake-apt\n");
    printf("Download-Size: %d mB\n", downloadSize);
    printf("APT-Sources: http://archive.ubuntu.com/ubuntu jammy-updates/universe %s Packages\n", CPU_ARCH);
    printf("Description: \n");
    int numWords = countWords(words_txt,words_txt_len);
    unsigned char **wordArray = malloc(numWords * sizeof(char *));
    int nextCharBeginsWord = 1;
    int nCountedWords = 0;
    for(i=0;i<words_txt_len;i++){
        if(nextCharBeginsWord == 1) wordArray[nCountedWords++] = words_txt + i;
        char c = words_txt[i];
        if(c == '\n'){
            nextCharBeginsWord=1;
            words_txt[i]='\0';
        }
        else nextCharBeginsWord=0;
    }
    for(i=0;i<64;i++){
        printf(" %s", wordArray[rand() % nCountedWords]);
    }
    printf(".\n");
    return(0);
}