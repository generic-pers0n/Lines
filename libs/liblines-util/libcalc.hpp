/* Copyright (C) 2019 Avery King <avery98@pm.me>
 *
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
/* libcalc v1.1
 *
 * This was an older version of what would become now liblines. It has limited
 * functionallity and was meant to be more of a general library. The original
 * libcalc did not have a license, but now, it has a license.
 *
 * This file contains functions for a basic calculator. It contains functions to
 * add, subtract, multiply, divide, round, calculate exponents, calculate the
 * sqaure root of a number, calculate the equation, the y-intercept, and the
 * slope for a graph, and the Pythagorean Theorem (no triplets).
 *
 * Limitations:
 *      - You can only input two numbers at a time for adding, subtracting,
 *        multiplying, and dividing
 *
 *
 **/
#include <iostream>
#include <cmath>
// #include <string>
// #include <cstdlib>
using namespace std;

// Add
double add(double num1, double num2) {
  double result = num1 + num2;
  return result;
}

// Subtract
double subtract(double num1, double num2) {
  double result = num1 - num2;
  return result;
}

// Multiply
double multiply(double num1, double num2) {
  double result = num1 * num2;
  return result;
}

// Divide
double divide(double num1, double num2) {
  double result = num1 / num2;
  return result;
}

// Rounding
double round_number(double number) {
  // Round the number
  double result = round(number);
  return result;
}

// Absolute value
double absolute_value(double num) {
  double number = num;

  // If the number given is positive, don't multiply
  // by -1, display the given number, and return the
  // given number
  if (number >= 0) {
    cout << number << endl;
  }

  double result = number * -1;
  return result;
}

// Square Root
double square_root(double num) {
  double number = num;

  // If the number is negative, alert the user and exit
  if (number < 0) {
    cerr << "Error: You cannot square root a negative number!";
    return 0;
  }

  // Calculate the sqaure root
  double result = sqrt(number);
  return result;
}

// Exponents
double exp(double num, double pwr) {
  double number = num;
  double power = pwr;
  double result = pow(number, power);
  return result;
}

namespace OriginalLines {
  // Find a linear graph equation
  class Linear {
    public:
      void coordinate(double pt1x, double pt1y, double pt2x, double pt2y) {
        // Coordinate point variables
        double xcoor1 = pt1x;
        double ycoor1 = pt1y;
        double xcoor2 = pt2x;
        double ycoor2 = pt2y;

        // Equation variables
        // double x;
        double y;

        // Subtract the coordinate points from each other
        //double delta_x = pt1x - pt2x;
        double delta_x = subtract(pt1x, pt2x);
        //double delta_y = pt1y - pt2y;
        double delta_y = subtract(pt1y, pt2y);
        //double slope = delta_y / delta_x; // The slope of the graph
        double slope = divide(delta_y, delta_x);

        // Find the y-intercept
        // (4, 10)
        y = ycoor1;
        //double mx = slope * xcoor1;
        double mx = multiply(slope, xcoor1);
        //double b = y - mx;
        double b = subtract(y, mx);

        cout << "\nThe equation of this graph is y=" << slope << "x" << b << endl;
        cout << "The slope of this graph is " << slope << endl;
        cout << "The y-intercept of this graph is (0, " << b << ")" << endl;
      }

      void slope(double xpt, double ypt, double slp) {
        double xcoor = xpt;
        double ycoor = ypt;
        double slope = slp;
        double y;

        // Find the y-intercept using the slope and two points
        y = ycoor;
        //double mx = slope * xcoor1; // 2(4)+b
        double mx = multiply(slope, xcoor);
        //double b = y - mx;
        double b = subtract(y, mx);

        // Display the equation, y-intercept, and slope
        cout << "\nThe equation of this graph is y=" << slope << "x" << b << endl;
        cout << "The slope of this graph is " << slope << endl;
        cout << "The y-intercept of this graph is (0, " << b << ")" << endl;
    }
  };

  // Find the hypotenuse or a missing side length using the Pythagorean Theorem
  class Pythagorean {
    public:
      double hypotenuse(double side_a, double hyp) {
       // Variables
       double a = side_a; // 10^2
       double b;
       double h = hyp; // 20^2

       // Square side A and the Hypotenuse
       double a2 = exp(side_a, 2); // 100
       double h2 = exp(h, 2); // 400

       double hyp_min_a = h2 - a2; // 300

       // Sqaure root the result after subtracting side A from the Hypotenuse
       double sqrt_hma = square_root(hyp_min_a); // 17.3
       b = sqrt_hma;

       cout << "Side B is equal to " << b;
       return b;
     }
  };

