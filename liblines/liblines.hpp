/* This file is a part of liblines
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
/* Libcalc Core (libcalc.hpp)
 *
 * Part of liblines v2.0
 *
 * This file contains the core functionallity that powers Lines. For example, it
 * contains certain commands like the "clear" command.
 *
 **/

// Includes
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#ifdef _WIN32
  #define OS "win"
#elif __unix__ || __APPLE__
  #define OS "unix"
#endif

// Namespaces
using namespace std;

// Function declarations
void options(string option);

// Get OS platform
string get_platform() {
  if (OS == "win") {
    return "win";
  }

  else if (OS == "unix") {
    return "unix";
  }

  else {
    return "other";
  }
}

// Copyright command
void show_copyright() {
  cout << "The swiss army knife for linear graphs. \
Copyright (C) 2019  Avery King\n\n \
This program is free software: you can redistribute it and/or modify\n \
it under the terms of the GNU General Public License as published by\n \
the Free Software Foundation, either version 3 of the License, or\n \
(at your option) any later version.\n\n \
This program is distributed in the hope that it will be useful,\n \
but WITHOUT ANY WARRANTY; without even the implied warranty of\n \
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n \
GNU General Public License for more details.\n \
You should have received a copy of the GNU General Public License\n \
along with this program.  If not, see <https://www.gnu.org/licenses/>.\n\n";
}

// Clear command
void clear() {
  // Clear command
  if (OS == "win") { // Clear command for Windows (cls)
    system("cls");
  } else if (OS == "unix" || OS == "macos") { // Clear (clear) command for Unix and similar
    system("clear");
  } else { // If none of the above is specified, then the default is "clear"
    system("clear");
  }
}

// Main screen
void main_screen(string custom_data, string prompt_type) {
  // Variables
  string option;

  // Parameter checks
  if (prompt_type == "prompt" && custom_data != "") {
    clear();
    // It's easier if we just detect prompt. Any other value will be ignored
    cout << custom_data << endl;
    cout << ">> ";
    getline(cin, option);
    options(option);
  }

  if (custom_data != "") {
    clear();
    cout << custom_data << "\n\n";
  }

  // Welcome screen
  cout << "====================================\n";
  cout << "Welcome to Lines\n";
  cout << "====================================\n\n";

  // Options screen
  cout << "Select an option: \n\n";

  cout << "(1) Find an equation with two given points\n";
  cout << "(2) Find an equation with a given slope and a point\n";
  cout << "(3) Generate coordinate points\n";
  cout << "(4) Generate coordinate points to a file\n";
  cout << "(5) Generate coordinate point with only one number\n\n";
  cout << "To see a list of commands, type \'help\'\n";

  cout << ">> ";
  cin >> option;
  options(option);
}

