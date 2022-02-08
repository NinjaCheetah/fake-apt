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
    #define CPU_ARCH "arm64"
#elif defined i386 || defined __i386__ || defined __i386 || defined _M_IX86
    #define CPU_ARCH "i386"
#elif defined __ARM_ARCH_2__ || defined __ARM_ARCH_3__ || defined __ARM_ARCH_4T__ || defined __ARM_ARCH_5__ || defined __ARM_ARCH_6__ || defined __ARM_ARCH_7__
    #define CPU_ARCH "armhf"
#elif defined __powerpc  || defined __powerpc__  || defined __powerpc64__  || defined __POWERPC__  || defined __ppc__  || defined __PPC__  || defined _ARCH_PPC
    #define CPU_ARCH "ppc"
#elif defined __PPC64__  || defined __ppc64__  || defined _ARCH_PPC64
    #define CPU_ARCH "ppc64";
#else
    #define CPU_ARCH "amd64"
#endif

#endif // CPUARCH_DOT_H