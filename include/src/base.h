/*fake-apt "base.h"
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
#ifndef FAKE_APT_BASE_H
#define FAKE_APT_BASE_H

// Declare base fake-apt functions
int apt_init();
int apt_create_version(int versions[]);
char* apt_fetch_get_url();
char* apt_fetch_os();

#endif //FAKE_APT_BASE_H
