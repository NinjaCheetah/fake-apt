/*fake-apt "cpuarch.h"
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
#ifndef CPUARCH_DOT_H
#define CPUARCH_DOT_H

// Declare CPU architecture char
#if defined __aarch64__ || defined _M_ARM64
char g_arch[]="arm64";
#elif defined i386 || defined __i386__ || defined __i386 || defined _M_IX86
char g_arch[]="i386";
#else
char g_arch[]="amd64";
#endif

#endif // CPUARCH_DOT_H