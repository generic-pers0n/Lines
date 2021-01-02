/* This file is part of Lines
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
/** LCL Functions
 * 
 * This file contains the necessary funcitons for dealing with fractions,
 * coordinate points, and various other things. This also includes various
 * data types and such.
 **/
#ifndef LCL_INTR_HPP
#define LCL_INTR_HPP

#include <string>

namespace lines {
namespace lcl_intr {

// Data types
struct coorpt
{
  double x, y;

  // Constructors
  coorpt() {}
  coorpt(double num) : x(num), y(num) {}

  // Operators
  void operator=(double num);
  bool operator==(coorpt& r_cpt);
};

// Functions
double frac(std::string& str);
coorpt mkcoorpt(std::string& str);

} // namespace frac
} // namespace lines

#endif // end frac.hpp
