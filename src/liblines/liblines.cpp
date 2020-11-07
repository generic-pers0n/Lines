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
  cout << "The equation of this graph is y=";

  // Slope formatting
  //
  // Here, the slope can either be positive or negative. We
  // don't need to be worrying about adding the proper sign
  // in front of itv
  if (slope == 1) { // If the slope is 1
    cout << "x";
  } else { // If the slope is positive or negative
    cout << slope << "x";
  }

  // Y-intercept formatting
  //
  // Unlike with the slope, we do need to add the proper sign
  // in front of the y-intercept if it's positive. Else, then
  // we can just leave it.
  if (y_intercept > 0) { // If the y-intercept is positive
    cout << "+" << y_intercept << endl;
  } else { // If the y-intercept is negative
    cout << y_intercept << endl;
  }

  // Print the slope and y-intercept of the graph
  cout << "The slope of this graph is " << slope << endl;
  cout << "The y-intercept of this graph is (0, " << y_intercept << ")" << "\n\n";
}

// Find an equation using a slope and a coordinate point
void slope(double xcoor, double ycoor, double slope) {
  // Throw an exception if the slope is 0
  if (slope == 0) {
    throw "This graph does not grow!";
  }

  // Find the y-intercept
  double y_intercept = ycoor - slope * xcoor;


  cout << "The equation of this graph is y=";

  // Slope formatting
  //
  // Here, the slope can either be positive or negative. We
  // don't need to be worrying about adding the proper sign
  // in front of itv
  if (slope == 1) { // If the slope is 1
    cout << "x";
  } else { // If the slope is positive or negative
    cout << slope << "x";
  }

  // Y-intercept formatting
  //
  // Unlike with the slope, we do need to add the proper sign
  // in front of the y-intercept if it's positive. Else, then
  // we can just leave it.
  if (y_intercept > 0) { // If the y-intercept is positive
    cout << "+" << y_intercept << endl;
  } else { // If the y-intercept is negative
    cout << y_intercept << endl;
  }

  // Print the slope and y-intercept of the graph
  cout << "The slope of this graph is " << slope << endl;
  cout << "The y-intercept of this graph is (0, " << y_intercept << ")" << "\n\n";
}

// Generate multiple coordinate points 
void generate_points(double slope, double y_intercept, int max_number, int starting_number) {
  int i = starting_number;

  while (true) {
    double result = slope*i + y_intercept;
    // Display the final result
    cout << "(" << i << ", " << result << ")\n";

    i++;
    if (i == max_number + 1) {
      break;
    }

    // (5, 20)
    // y=2x+10      Equation
    // y=2(5)+10    Multiply x (i) by the slope
    // y=10+10      Add the product of slope * x with the y-intercept
    //y=20          Final result
  }
}

// Generate a coordinate point
void generate_point(double slope, double y_intercept, double number) {
  double result = slope * number + y_intercept;

  // Display the final result
  cout << "(" << number << ", " << result << ")\n";
}
