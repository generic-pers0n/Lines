# Copyright (C) 2019 Avery King <avery98@pm.me>
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with this program.  If not, see <https://www.gnu.org/licenses/>.
liblines: liblines.cpp liblines.o
	g++ -fPIC -g -c liblines.cpp -o liblines.o
	g++ -shared -fPIC -g liblines.o -o liblines.so
	rm -rf liblines.o

install: liblines.so
	install liblines.so /lib64
