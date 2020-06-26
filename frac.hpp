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

// This function actually strips any whitespaces out from a
// proper fraction. For example, 1 / 2 would be stripped
// down to 1/2. NOTE: Unfinished
std::string fix_frac(std::string str) {
  std::size_t space = str.find(" ");
  while (space != std::string::npos) {
    str.erase(space);
  }

  return str;
}

// Take a string and convert it to a fraction. Then, return the result after
// converting it from the string.
double frac(std::string str) {
  std::size_t separator = str.find("/"); // Position of the fraction seperator
  std::string fraction[2]; // Temporary array for our string

  // If the fraction is invalid, e.g. a regular number, then we can just convert
  // the string to a number and return it. No extra work necessary.
  if (separator == std::string::npos) {
    double num = stod(str);
    return num;
  }

  // Try to ind a whitespace between the numerator, denominator and separator.
  // If one is found, erase it
  if (str.find(" ") != std::string::npos) {
    str.erase(str.begin() + (separator - 1)); // Numerator
    str.erase(str.begin() + (separator + 1)); // Denominator
  }

  fraction[0] = str.substr(0, separator) ; // Get the numerator ([1]/2)
  fraction[1] = str.substr(separator + 1); // Get the denominator (1/[2])

  // Convert the fraction from its string counterpart to an actual number
  double numerator = stod(fraction[0]), denominator = stod(fraction[1]);

  if (denominator == 0) { // Division by zero attempt
    throw std::logic_error("Division by zero attempt");
  }

  return numerator / denominator; // Returns a fully-converted fraction
}

#endif // end frac.hpp
