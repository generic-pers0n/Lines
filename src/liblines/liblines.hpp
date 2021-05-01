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



#define LIBLINES_EXTERN_APIS extern "C" {
#define LIBLINES_END_EXTERN }

namespace liblines {

#define LIBLINES_MAJOR_VER 3
#define LIBLINES_MINOR_VER 1
#define LIBLINES_PATCH_VER 0

#ifndef STATIC
#define __LIBLINES_VER_CONSTS

extern "C" const int major_ver;
extern "C" const int minor_ver;
extern "C" const int patch_ver;

#endif

LIBLINES_EXTERN_APIS // begin external APIs

void coordinate(double x1, double y1, double x2, double y2);
void slope(double x, double y, double slope);
void genpoints(double slope, double y_intercept, int start, int end);

LIBLINES_END_EXTERN // end external APIs

} // namespace liblines

#endif // end liblines.hpp

