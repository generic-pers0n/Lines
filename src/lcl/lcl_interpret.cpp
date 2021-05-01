/* This file is part of Lines
 *
 * Copyright (C) 2019-2021 Avery King <avery98@pm.me>
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
/** @file lcl_interpret.cpp
 *
 * The implementation of things defined in lcl_interpret.hpp
 *
 * Note that we're keeping this file and such here for now. In Lines 4.0
 * or something, coorpt will be moved into liblines (but not any related
 * functions). As a result, various liblines functions will now use coorpt
 * as an accepted argument.
 **/
#ifndef LCL_INTR
#define LCL_INTR

#include "lcl_interpret.hpp"
#include <iostream>
#include <string>
#include <exception>

namespace lines {
namespace lcl_intr {

// Coorpt implementations
void coorpt::operator=(double num)
{
  x = y = num;
}

bool coorpt::operator==(coorpt& r_cpt)
{
  return (((*this).x == r_cpt.x) && ((*this).y == r_cpt.y));
}

// Functions

/** Takes a std::string and converts it to a fraction
 *
 * This function allows you to take a string and convert it
 * to a number. After converting the string to a number, we
 * then divide the numerator by the denominator.
 *
 * The syntax requirements for the string are very simple: a
 * '/' character is required for the fraction to be valid. If
 * this character is not found, then this function is essentially
 * std::stod(), returning the value from it. If std::stod()
 * throws, then frac() also throws (at least, if it's
 * std::logic_error that's thrown).
 *
 * @return The value of the converted fraction.
 **/
double frac(std::string& str)
{
  std::size_t separator, space;
  std::string fraction[2]; // Temporary array for our string

  while ((space = str.find(' ')) != std::string::npos)
  {
    str.erase(str.begin() + space);
  }

  separator = str.find('/');

  // Try to convert the fraction to a regular number if no separator is found
  double num;
  if (separator == std::string::npos)
  {
    try
    {
      num = std::stod(str);
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
    numerator = std::stod(fraction[0]);
    denominator = std::stod(fraction[1]);
  } catch (...)
  {
    numerator = 0;
    denominator = 1; // set to 1 to prevent any exceptions from happening
  }

  if (denominator == 0) // Division by zero attempt
  {
    throw std::logic_error("Division by zero attempt");
  }

  return numerator / denominator; // Returns a fully-converted fraction
}

/** A function that converts a string to a coordinate point (coorpt)
 *
 * Note that this function conforms to only 1 syntax rule: a comma must
 * be present. Otherwise an invalid syntax error (std::invalid_argument)
 * will be thrown. Parenthesis are optional (they don't matter, actually).
 *
 * List of possible valid coordinate point syntax:
 *   * (1, 2)
 *   * (1,2)
 *   * 1, 2
 *   * 1,2
 * List of technically valid coordinate point syntax:
 *   * (1, 2
 *   * (1,2
 *   * 1, 2)
 *   * 1,2)
 **/

coorpt mkcoorpt(std::string& str)
{
  coorpt coordinate;
  std::size_t start = str.find('(');
  std::size_t end = str.find(')');
  std::size_t comma = str.find(',');

  std::string tmp_str;

  if (start == std::string::npos)
  {
    start = 0;
  } else if (end == std::string::npos)
  {
    end = str.size();
  }

  if (comma == std::string::npos)
  {
    throw std::invalid_argument("Invalid syntax in string");
  }

  // X
  try
  {
    tmp_str = str.substr(start + 1, comma);
    coordinate.x = frac(tmp_str);
  } catch (...)
  {
    coordinate.x = 0;
  }

  // Y
  try
  {
    tmp_str = str.substr(comma + 1, end);
    coordinate.y = frac(tmp_str);
  } catch (...)
  {
    coordinate.y = 0;
  }

  return coordinate;
}

str_vec split(std::string& str, const char delim)
{
  std::string str_token;
  str_vec split_str;

  if (str.find(delim) == std::string::npos)
  {
    split_str.push_back(str);
    return split_str;
  }

  for (size_t i = 0; i < str.size() ; i++)
  {
    if (str[i] == delim)
    {
      if (str_token != "")
      {
        split_str.push_back(str_token);
      }

      str_token.clear();
    } else
    {
      str_token.push_back(str[i]);
    }
  }

  split_str.push_back(str_token);

  return split_str;
}

} // namespace lcl_intr
} // namespace lines

#endif // end frac.hpp
