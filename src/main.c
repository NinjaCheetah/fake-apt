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
#include <string.h>
// Local headers
#include "../include/cpuarch.h"
#include "../include/install.h"
#include "../include/search.h"
#include "../include/update.h"
// Use different headers in Windows
#ifdef _WIN32
    #include <Windows.h>
#endif
// Start code
int main(int argc,char *argv[]) {
    int returnCode = 0;
    // Check args, abort if too few are passed
    if(argc < 2) {
        printf("apt 2.0.6 (%s)\nUsage: apt [options] command\n\n", CPU_ARCH);
        printf("apt is a commandline package manager and provides commands for\n"
               "searching and managing as well as querying information about packages.\n"
               "It provides the same functionality as the specialized APT tools,\n"
               "like apt-get and apt-cache, but enables options more suitable for\n"
               "interactive use by default.\n\n");
        printf("Most used commands:\n"
               /*"  list - list packages based on package names\n"*/
               "  search - search in package descriptions\n"
               /*"  show - show package details\n"*/
               "  install - install packages\n"
               /*"  reinstall - reinstall packages\n"*/
               /*"  remove - remove packages\n"*/
               /*"  autoremove - Remove automatically all unused packages\n"*/
               "  update - update list of available packages\n"
               /*"  upgrade - upgrade the system by installing/upgrading packages\n"*/
               /*"  full-upgrade - upgrade the system by removing/installing/upgrading packages\n"*/
               /*"  edit-sources - edit the source information file\n"*/
               /*"  satisfy - satisfy dependency strings\n"*/
               "\n");
        printf("See apt(8) for more information about the available commands.\n"
               "Configuration options and syntax is detailed in apt.conf(5).\n"
               "Information about how to configure sources can be found in sources.list(5).\n"
               "Package and version choices can be expressed via apt_preferences(5).\n"
               "Security details are available in apt-secure(8).\n");
        printf("                                        This APT has Super Cow Powers.\n");
        return(0);
    }
    if(strcmp(argv[1], "install") == 0) {
        // Run install
        returnCode = apt_install(argc, argv);
    }
    else if(strcmp(argv[1], "search") == 0) {
        // Run search
        returnCode = apt_search(argc, argv);
    }
    else if(strcmp(argv[1], "update") == 0) {
        // Run update
        returnCode = apt_update();
    }
    return(returnCode);
}
