#!/bin/bash

#    Cross platform unix* package manager more like scripts written in bash - themispkg
#    Copyright (C) 2022  lazypwny751
#
#    This program is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.

#    You should have received a copy of the GNU General Public License
#    along with this program.  If not, see <https://www.gnu.org/licenses/>.

# "Kalp Allah'ın mülküdür, göğsünde atınca senin mi sandın."

. /usr/share/themis/init.sh || { echo -e "\033[0;31mFatal:\033[0m Could not initalizing in this time! Try '$(basename "${BASH_SOURCE[0]}" --fix)'" ; exit 1 ;}
