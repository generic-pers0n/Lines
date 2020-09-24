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
/************************** FRACTION FUNCTIONS **************************
 * This file contains the necessary funcitons for dealing with fractions.
 * Here, we have functions that allow us to convert a fraction to a single
 * number, to fix a fraction, and more.
*/
#ifndef FRAC_HPP
#define FRAC_HPP

#include <iostream>
#include <string>
using namespace std;

namespace lines {
namespace frac {

// Take a string and convert it to a fraction. Then, return the result after
// converting it from the string.
double frac(std::string str) {
  std::size_t separator, space;
  std::string fraction[2]; // Temporary array for our string

  while ((space = str.find(' ')) !=std::string::npos)
  {
    str.erase(str.begin() + space);
  }

  separator = str.find('/');

  // Try to convert the fraction to a regular number if no separator is found
  if (separator == std::string::npos)
  {
    double num;
    try
    {
      num = stod(str);
    } catch (...)
    {
      num = 0;
    }

    return num;
  }

  fraction[0] = str.substr(0, separator) ; // Get the numerator ([1]/2)
  fraction[1] = str.substr(separator + 1); // Get the denominator (1/[2])

  // Convert the fraction from its string counterpart to an actual number
  double numerator, denominator;
  try
  {
    numerator = stod(fraction[0]);
    denominator = stod(fraction[1]);
  } catch (...)
  {
    numerator = 0;
    denominator = 1; // set to 1 to prevent exceptions
  }

  if (denominator == 0) // Division by zero attempt
  {
    throw std::logic_error("Division by zero attempt");
  }

  return numerator / denominator; // Returns a fully-converted fraction
}

} // namespace frac
} // namespace lines

#endif // end frac.hpp
