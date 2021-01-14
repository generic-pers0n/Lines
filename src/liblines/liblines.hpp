/* This file is a part of liblines
 *
 * Copyright (C) 2019-2020 Avery King <avery98@pm.me>
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
#ifndef LIBLINES_HPP
#define LIBLINES_HPP

#define LIBLINES_MAJOR_VER 3
#define LIBLINES_MINOR_VER 1
#define LIBLINES_PATCH_VER 0

/* TODO: Add a namespace to liblines (named 'liblines'). Planed for 4.0
   Yes, I know having a namespace is a good idea, and I want to add one.
   However, this will (unfortunately) have to wait until Lines v4.0 because
   this will case incompatible changes with older versions of Lines. I
   don't want that to happen because that technically means Lines 4.0 will
   arrive WAY to early. In the mean time, we must unfortunately suffer).
*/

#ifndef COMPAT_MODE

#define LIBLINES_EXTERN_APIS extern "C" {
#define END_EXTERN }

// Function prototypes

LIBLINES_EXTERN_APIS // begin external APIs
#endif

void coordinate(double xcoor1, double ycoor1, double xcoor2, double ycoor2);
void slope(double xcoor, double ycoor, double slope);
void generate_points(double slope, double y_intercept, int max_number, int starting_number);
void generate_point(double slope, double y_intercept, double number);

#ifndef COMPAT_MODE
END_EXTERN // end external APIs
#endif

#endif // end liblines.hpp
