/* Copyright (C) 2019 Avery King <avery98@pm.me>
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
/* liblines v2.0
 *
 * This file contains functions for Lines. It contains the functions to
 * calculate a graph's slope, equation, and Y-Intercept. It also
 * contains many more functions, like a coordinate point generator.
 *
 *
 * For crucial functionallity of Lines, see lines.hpp
 **/
#include "liblines.h"
#include "../liblines-util/util.h" // libs/liblines-util/util.h
using namespace std;


// Find a linear graph equation
void coordinate(double xcoor1, double ycoor1, double xcoor2, double ycoor2) {
  // Find the slope of the graph
  double delta_x = xcoor1 - xcoor2;
  double delta_y = ycoor1 - ycoor2;

  if (delta_x == 0 && delta_y == 0) {
    cerr << "\nThere is a 0 / 0 case, and Lines cannot solve this.\n";
    cerr << "This means that Lines cannot solve for the equation, y-intercept, and slope\n";
    main_screen("", "");
  }

  double slope = delta_y / delta_x;

  // If the slope is 0, then give the user an error
  if (slope == 0) {
    main_screen("This graph does not grow\nThe reason being is because the slope is 0;", "");
  }

  // Find the y-intercept
  double slope_x_xcoor1 = slope * xcoor1;

  double y_intercept = ycoor1 - slope_x_xcoor1; // y-intercept


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

  main_screen("", "");
}

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

void generate_points(double slope, double y_intercept, int max_number, int starting_number) {
  int i = starting_number;

  while (true) {
    double slope_x_number = slope * i; // I is X in this case
    double final_result = slope_x_number + y_intercept;
    // Display the final result
    cout << "(" << i << ", " << final_result << ")\n";

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

// Generate a coordinate point using a number
void generate_point(double slope, double y_intercept, int number) {
  double slope_x_number = slope * number; // The variable "number" is x in this case
  double final_result = slope_x_number + y_intercept;

  // Display the final result
  cout << "(" << number << ", " << final_result << ")\n";
}

// Write generated coordinate points to a file function
void write_generated_points_to_file(double slope, double y_intercept, int max_number, int starting_number, string file_name) {
  // Variables
  int i = starting_number;
  ofstream file; // File to save generated coordinate points in

  if (file_name == "") {
    cout << "A file name wasn't specified, so the coordinate points cannot be written to the file\n";
    main_screen("", "");
  }

  file.open(file_name);

  while (true) {
    double slope_x_number = slope * i; // I is X in this case
    double final_result = slope_x_number + y_intercept;

    // Write the coordinate points to the file
    file << "(" << i << ", " << final_result << ")\n";

    i++;
    if (i == max_number + 1) {
      break;
      file.close(); // Close the file where the answers are stored
    }

    // (5, 20)
    // y=2x+10      Equation
    // y=2(5)+10    Multiply x (i) by the slope
    // y=10+10      Add the product of slope * x with the y-intercept
    //y=20          Final result
  }
}
