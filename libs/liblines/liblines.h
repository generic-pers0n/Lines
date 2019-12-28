/* This file is a part of liblines
 *
 * Copyright (C) 2019 Avery King <avery98@pm.me>
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
#ifndef LIBLINES_H
#define LIBLINES_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <bits/stdc++.h>
#include <lines/util.h>
using namespace Util; // liblines-util namespace "Util"

#ifdef _WIN32
  #define OS "win"
#elif __unix__ || __APPLE__
  #define OS "unix"
#endif

// Namespaces
using namespace std;

// Declarations in liblines.cpp
void coordinate(double xcoor1, double ycoor1, double xcoor2, double ycoor2);
void slope(double xcoor, double ycoor, double slope);
void generate_points(double slope, double y_intercept, int max_number, int starting_number);
void generate_point(double slope, double y_intercept, int number);
void write_generated_points_to_file(double slope, double y_intercept, int max_number, int starting_number, string file_name);

// Main screen (deprecated)
//
// The main screen is going away soon. Over time, as liblines-util
// matures, main_screen() will eventually be removed.
void main_screen(string custom_data, string prompt_type) {
  cout << "To see a list of commands, type \'help\'\n";

  // Prompt the user
  vector<string> command = prompt();
  get_option(command);
}

#endif // end liblines.h
