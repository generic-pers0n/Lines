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
    cerr << "!!  The slope will be 0, so the graph will not grow  !!";
  } else if (delta_x == 0) {
    throw "Division by 0!";
  }

  // Slope
  double slope = delta_y / delta_x;


  // Find the y-intercept
  double slope_x_xcoor1 = slope * xcoor1;

  double y_intercept = ycoor1 - slope_x_xcoor1; // y-intercept


  // Print the equation of the graph (formatting)
  if (slope == 1) { // If the slope is just 1
    if (y_intercept == 0) { // If the y-intercept is just 0 (x = 0)
      cout << "\nThe equation of this graph is y=x" << endl;
    }

    else if (y_intercept > 0) { // If the y-intercept is positive (x > 0)
      cout << "\nThe equation of this graph is y=x+" << slope << endl;
    }

    else { // If the y-intercept is negative (x < 0)
      cout << "\nThe equation of this graph is y=x" << slope << endl;
    }
  }

  else if (y_intercept == 0) {
    cout << "\nThe equation of this graph is y=" << slope << "x" << endl;
  }

  else if (y_intercept < 0) { // If the y-intercept is negative
    cout << "\nThe equation of this graph is y=" << slope << "x" << y_intercept << endl;
  }

  else { // If the y-intercept is positive
    cout << "\nThe equation of this graph is y=" << slope << "x+" << y_intercept << endl;
  }

  // Print the slope and y-intercept of the graph
  cout << "The slope of this graph is " << slope << endl;
  cout << "The y-intercept of this graph is (0, " << y_intercept << ")" << "\n\n";
}

// Find an equation using a slope and a coordinate point
void slope(double xcoor, double ycoor, double slope) {
  // If the slope is NaN (not a number), then give the user an error
  if (slope == 0) {
    cout << "This graph does not grow";
    cout << "The reason being is because the slope is 0\n\n";
    exit(0);
  }

  // Find the y-intercept
  double slope_x_xcoor = slope * xcoor;
  double y_intercept = ycoor - slope_x_xcoor; // y-intercept


  // Print the equation of the graph (formatting)
  if (slope == 1) { // If the slope is just 1
    if (y_intercept == 0) { // If the y-intercept is just 0
      cout << "\nThe equation of this graph is y=x" << endl;
    }

    else if (y_intercept > 0) { // If the y-intercept is positive
      cout << "\nThe equation of this graph is y=x+" << slope << endl;
    }

    else { // If the y-intercept is negative
      cout << "\nThe equation of this graph is y=x" << slope << endl;
    }
  }

  else if (y_intercept == 0) {
    cout << "\nThe equation of this graph is y=" << slope << "x";
  }

  else if (y_intercept < 0) { // If the y-intercept is negative
    cout << "\nThe equation of this graph is y=" << slope << "x" << y_intercept << endl;
  }

  else { // If the y-intercept is positive
    cout << "\nThe equation of this graph is y=" << slope << "x+" << y_intercept << endl;
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
void generate_point(double slope, double y_intercept, int number) {
  double result = slope*number + y_intercept;

  // Display the final result
  cout << "(" << number << ", " << result << ")\n";
}
