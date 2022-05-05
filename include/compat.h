/*fake-apt "compatsleep.h"
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

#ifndef FAKE_APT_COMPAT_H
#define FAKE_APT_COMPAT_H

#ifdef _WIN32
    #define msleep(x) Sleep(x)
#else
    #define msleep(x) usleep(x*1000)
    #define _countof(x) (sizeof(x)/sizeof(*(x)))
#endif

#endif //FAKE_APT_COMPAT_H
