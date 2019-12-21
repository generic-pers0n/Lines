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
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#ifndef LINES_API_H
#define LINES_API
using namespace std;

// Function declarations
void coordinate(double xcoor1, double ycoor1, double xcoor2, double ycoor2);
void slope(double xcoor, double ycoor, double slope);

void generate_points(double slope, double y_intercept, int max_number, int starting_number);
void generate_point(double slope, double y_intercept, int number);
void write_generated_points_to_file(double slope, double y_intercept, int max_number, int starting_number, string file_name);

namespace Lines {
  class Calc{
    void calc_coor_pts(double xcoor, double ycoor, double xcoor2, double ycoor2) {
      coordinate(xcoor, ycoor, xcoor2, ycoor2);
    }

    void calc_coor_pts_slope(double slope, double xcoor, double ycoor) {
      slope(xcoor, ycoor, slope);
    }
  };

  class GenCoorPts {
    void generate(double slope, double y_int, int max, int start) {
      generate_points(slope, y_int, max, start);
    }

    void generate_single(double slope, double y_int, int number) {
      generate_point(slope, y_int, number);
    }

    void write(double slope, double y_int, int max, int start, string file) {
      write(write_generated_points_to_file(slope, y_int, max, start, file);
    }
  };

  string getver() {
    return "v3.0";
  }
}

#endif // end lines-api.h

