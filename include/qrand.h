/*fake-apt "qrand.h"
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
#ifndef FAKE_APT_QRAND_H
#define FAKE_APT_QRAND_H

// Quick version of rand that lets you directly specify a max
#define qrand(x) rand() % x

#endif //FAKE_APT_QRAND_H