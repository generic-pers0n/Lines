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
using namespace std;

// Find an equation using 2 coordinate points
void coordinate(double xcoor1, double ycoor1, double xcoor2, double ycoor2) {
  // Find the slope of the graph
  double delta_x = xcoor1 - xcoor2;
  double delta_y = ycoor1 - ycoor2;

  if (delta_y == 0) {
    throw "Slope equals 0!";
  } else if (delta_x == 0) {
    throw "Division by 0!";
  }

  // Slope
  double slope = delta_y / delta_x;

  // Find the y-intercept
  double y_intercept = ycoor1 - slope * xcoor1;


  // Print the equation of the graph (formatting)
  std::cout << "\nThe equation of this graph is y=";

  // Slope formatting
  if (slope == 1) { // If the slope is 1
    std::cout << "x";
  } else { // If the slope is positive or negative
    std::cout << slope << "x";
  }

  // y-intercept formatting
  // Note: we only print the y-intercept if it's not zero (0)
  if (y_intercept != 0) { // If the y-intercept is not 0
    if (y_intercept > 0) { // If the y-intercept is positive
      std::cout << "+" << y_intercept << std::endl;
    } else { // If the y-intercept is negative
      std::cout << y_intercept << std::endl;
    }
  }

  // Print the slope and y-intercept of the graph
  std::cout << "Y-intercept: (0, " << y_intercept << ")" << std::endl;
  std::cout << "Slope: " << slope << "\n\n";
}

// Find an equation using a slope and a coordinate point
void slope(double xcoor, double ycoor, double slope) {
  // Throw an exception if the slope is 0
  if (slope == 0) {
    throw "This graph does not grow!";
  }

  // Find the y-intercept
  double y_intercept = ycoor - slope * xcoor;

  std::cout << "The equation of this graph is y=";

  // Slope formatting
  if (slope == 1) { // If the slope is 1
    std::cout << "x";
  } else { // If the slope is positive or negative
    std::cout << slope << "x";
  }

  // y-intercept formatting
  // Note: we only print the y-intercept if it's not zero (0)
  if (y_intercept != 0) { // If the y-intercept is not 0
    if (y_intercept > 0) { // If the y-intercept is positive
      std::cout << "+" << y_intercept << std::endl;
    } else { // If the y-intercept is negative
      std::cout << y_intercept << std::endl;
    }
  }


  // Print the slope and y-intercept of the graph
  std::cout << "Slope: " << slope << std::endl;
  std::cout << "Y-intercept: (0, " << y_intercept << ")" << "\n\n";
}

// Generate multiple coordinate points
// Note: In Lines v4.0, this function will return an array (maybe a vector, even) of
// a custom data type that holds a coordinate point.
void generate_points(double slope, double y_intercept, int max_number, int starting_number) {
  for (int i = starting_number; i <= max_number; i++) {
    // Display the final result
    std::cout << "(" << i << ", " << slope * i + y_intercept << ")\n";

    // Example:
    // (5, 20)      Coordinate point to use
    // y=2x+10      Equation to use
    // y=2(5)+10    Multiply x (i) by the slope
    // y=10+10      Add the product of slope * x with the y-intercept
    // y=20          Final result
  }
}

// Generate a coordinate point
// I'm pretty tempted to change this in fact. Therefore, in Lines v4.0, this function
// will be inlined and will return (type: double).
void generate_point(double slope, double y_intercept, double number) {
  std::cout << "(" << number << ", " << slope * number + y_intercept << ")\n";
}

