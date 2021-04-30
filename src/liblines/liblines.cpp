/* Copyright (C) 2019-2020 Avery King <avery98@pm.me>
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
/* liblines
 *
 * This file contains the overall core functions that Lines uses. You can
 * also use this "library" in your application, provided you follow the
 * GPL v3, or any later version (liblines was originally not meant to be
 * used for other applications).
 *
 *
 * For crucial functionallity of Lines, see lines.hpp
 **/
#include "liblines.hpp"
#include <iostream>

namespace liblines {

#ifndef STATIC
#define __LIBLINES_VER_CONSTS

/** liblines version constants.
 *
 * These constants represent the current major version, minor version, and patch
 * version of liblines. These are useful if you want to check at runtime for a
 * certain version of liblines.
 *
 * Note that these variables are not present if a static version of liblines is
 * present. These variables are only useful if liblines has been compiled as a
 * dynamic library. Otherwise, you can use the LIBLINES_VER constants for
 * compile time conditions.
 *
 **/
const int major_ver = 3;
const int minor_ver = 1;
const int patch_ver = 0;
#endif

LIBLINES_EXTERN_APIS // begin public APIs

// Find an equation using 2 coordinate points
void coordinate(double x1, double y1, double x2, double y2)
{
  // Find the slope of the graph
  double delta_x = x1 - x2;
  double delta_y = y1 - y2;

  if (delta_y == 0)
  {
    throw "Slope equals 0!";
  } else if (delta_x == 0)
  {
    throw "Division by 0!";
  }

  // Slope
  double slope = delta_y / delta_x;

  // Find the y-intercept
  double y_intercept = y1 - slope * x1;


  // Print the equation of the graph (formatting)
  std::cout << "\nThe equation of this graph is y=";

  if (slope == 1) // If the slope is 1
  {
    std::cout << "x";
  } else // If the slope is positive or negative
  {
    std::cout << slope << "x";
  }

  if (y_intercept > 0) // If the y-intercept is positive
  {
    std::cout << "+" << y_intercept << std::endl;
  } else if (y_intercept < 0) // If the y-intercept is negative
  {
    std::cout << y_intercept << std::endl;
  } else
  {
    std::cout << std::endl; // No need to display the y-intercept
  }

  // Print the slope and y-intercept of the graph
  std::cout << "The slope of this graph is " << slope << std::endl;
  std::cout << "The y-intercept of this graph is (0, " << y_intercept << ")" << "\n\n";
}

/** Find an equation using a slope and a coordinate point
 *
 * Note that this function is literally coordinate() but with a few
 * changes. It's pretty much the same thing anyways...
 **/
void slope(double x, double y, double slope)
{
  // Throw an exception if the slope is 0
  if (slope == 0)
  {
    throw "This graph does not grow!";
  }

  // Find the y-intercept
  double y_intercept = y - slope * x;

  std::cout << "The equation of this graph is y=";

  if (slope == 1) // If the slope is 1
  {
    std::cout << "x";
  } else // If the slope is positive or negative
  {
    std::cout << slope << "x";
  }

  if (y_intercept > 0) // If the y-intercept is positive
  {
    std::cout << "+" << y_intercept;
  } else if (y_intercept < 0) // If the y-intercept is negative
  {
    std::cout << y_intercept;
  }

  // Print the slope and y-intercept of the graph
  std::cout << "\nThe slope of this graph is " << slope << std::endl;
  std::cout << "The y-intercept of this graph is (0, " << y_intercept << ")" << "\n\n";
}

// Generate multiple coordinate points 
void genpoints(double slope, double y_intercept, int start = 1, int end = 1)
{
  for (int i = start; i  <= end; i++)
  {
    double result = (slope * i) + y_intercept;
    std::cout << "(" << i << ", " << result << ")\n";

    // (5, 20)
    // y=2x+10      Equation
    // y=2(5)+10    Multiply x (i) by the slope
    // y=10+10      Add the product of slope * x with the y-intercept
    // y=20          Final result
  }
}

LIBLINES_END_EXTERN // end extern APIs

} // namespace liblines
