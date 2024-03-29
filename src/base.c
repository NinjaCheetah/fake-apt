/*fake-apt "base.c"
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
#include "../include/src/base.h"
#include "../include/compat.h"
#include "../include/qrand.h"
// Use different headers in Windows
#ifdef _WIN32
#include <Windows.h>
    #include <winsock.h>
#else
#include <unistd.h>
#endif
int apt_init() {
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
    return(0);
}
int apt_create_version(int versions[]) {
    int verMax[4]={25,50,9,9};
    int i;
    for(i=0;i<4;i++) {
        versions[i] = qrand(verMax[i]);
    }
    return(0);
}
char* apt_fetch_get_url() {
#if defined(_WIN32)
    return("https://packages.microsoft.com/windows");
#elif defined(__APPLE__)
    return("https://packages.apple.com/macos");
#else
    return("http://archive.ubuntu.com/ubuntu");
#endif
}
char* apt_fetch_os() {
#if defined(_WIN32)
    return("windows-11");
#elif defined(__APPLE__)
    return("monterey");
#else
    return("jammy");
#endif
}