/*fake-apt "main.c"
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
#include <string.h>
// Local headers
#include "../include/cpuarch.h"
#include "../include/version.h"
#include "../include/src/install.h"
#include "../include/src/reinstall.h"
#include "../include/src/search.h"
#include "../include/src/update.h"
#include "../include/src/upgrade.h"
#include "../include/src/remove.h"
#include "../include/src/list.h"
#include "../include/src/show.h"
#include "../include/src/satisfy.h"
// Use different headers in Windows
#ifdef _WIN32
    #include <Windows.h>
#endif
// Define this ahead of time so main() can be first
int apt_usage();
// Start code
int main(int argc,char *argv[]) {
    int returnCode;
    // Check args, abort if too few are passed
    if(argc < 2) {
        // Show usage
        apt_usage();
        return(0);
    }
    if(strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0) {
        // Show usage
        returnCode = apt_usage();
    }
    else if(strcmp(argv[1], "list") == 0) {
        // Run list
        returnCode = apt_list(argc, argv);
    }
    else if(strcmp(argv[1], "search") == 0) {
        // Run search
        returnCode = apt_search(argc, argv);
    }
    else if(strcmp(argv[1], "show") == 0) {
        // Run show
        returnCode = apt_show(argc, argv);
    }
    else if(strcmp(argv[1], "install") == 0) {
        // Run install
        returnCode = apt_install(argc, argv);
    }
    else if(strcmp(argv[1], "reinstall") == 0) {
        // Run reinstall
        returnCode = apt_reinstall(argc, argv);
    }
    else if(strcmp(argv[1], "remove") == 0) {
        // Run remove
        returnCode = apt_remove(argc, argv);
    }
    else if(strcmp(argv[1], "autoremove") == 0) {
        // Run autoremove
        returnCode = apt_autoremove();
    }
    else if(strcmp(argv[1], "update") == 0) {
        // Run update
        returnCode = apt_update();
    }
    else if(strcmp(argv[1], "upgrade") == 0) {
        // Run upgrade
        returnCode = apt_upgrade();
    }
    else if(strcmp(argv[1], "full-upgrade") == 0) {
        // Run full-upgrade
        returnCode = apt_fullupgrade();
    }
    else if(strcmp(argv[1], "satisfy") == 0) {
        // Run satisfy
        returnCode = apt_satisfy(argc);
    }
    else {
        // Go through all possible scenarios and print the corresponding error
        char *unknownArg = argv[1];
        if(unknownArg[0] == '-') {
            // Full argument (ex. --help)
            if(unknownArg[1] == '-') {
                printf("\e[0;91mE: \e[0mCommand line option %s is not understood in combination with the other options\n", unknownArg);
                returnCode = -1;
            }
            // Short argument (ex. -h)
            else {
                printf("\e[0;91mE: \e[0mCommand line option '%c' [from %s] is not understood in combination with the other options.\n", unknownArg[1], unknownArg);
                returnCode = -1;
            }
        }
        else {
            // Catch-all for any other argument
            printf("\e[0;91mE: \e[0mInvalid operation %s\n", unknownArg);
            returnCode = -1;
        }
    }
    return(returnCode);
}
// Print APT usage blurb
int apt_usage() {
    printf("apt %s (%s)\nUsage: apt [options] command\n\n", APT_VERSION, CPU_ARCH);
    printf("apt is a commandline package manager and provides commands for\n"
           "searching and managing as well as querying information about packages.\n"
           "It provides the same functionality as the specialized APT tools,\n"
           "like apt-get and apt-cache, but enables options more suitable for\n"
           "interactive use by default.\n\n");
    printf("Most used commands:\n"
           "  list - list packages based on package names\n"
           "  search - search in package descriptions\n"
           "  show - show package details\n"
           "  install - install packages\n"
           "  reinstall - reinstall packages\n"
           "  remove - remove packages\n"
           "  autoremove - Remove automatically all unused packages\n"
           "  update - update list of available packages\n"
           "  upgrade - upgrade the system by installing/upgrading packages\n"
           "  full-upgrade - upgrade the system by removing/installing/upgrading packages\n"
           /*"  edit-sources - edit the source information file\n"*/
           "  satisfy - satisfy dependency strings\n"
           "\n");
    printf("See apt(8) for more information about the available commands.\n"
           "Configuration options and syntax is detailed in apt.conf(5).\n"
           "Information about how to configure sources can be found in sources.list(5).\n"
           "Package and version choices can be expressed via apt_preferences(5).\n"
           "Security details are available in apt-secure(8).\n");
    printf("                                        This APT has Super Cow Powers.\n");
    return(0);
}