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
void main_screen(string custom_data, string prompt_type);

// Platform detection
string get_platform() {
  if (OS == "win") {
    return "windows";
  }

  else if (OS == "unix") {
    return "unix";
  }

  else {
    return "unknown";
  }
}

// Copyright command
void show_copyright() {
  cout << "The swiss army knife for linear graphs.\n\n";
  cout << "Copyright (C) 2019  Avery King\n";
  cout << "This program is free software: you can redistribute it and/or modify\n";
  cout << "it under the terms of the GNU General Public License as published by\n";
  cout << "the Free Software Foundation, either version 3 of the License, or\n";
  cout << "(at your option) any later version.\n\n";
  cout << "This program is distributed in the hope that it will be useful,\n";
  cout << "but WITHOUT ANY WARRANTY; without even the implied warranty of\n";
  cout << "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n";
  cout << "GNU General Public License for more details.\n\n";
  cout << "You should have received a copy of the GNU General Public License\n";
  cout << "along with this program.  If not, see <https://www.gnu.org/licenses/>.\n\n";
}

//////////////////////// Commands ////////////////////////
void clear() { // Clear command
  // Clear command
  if (OS == "win") { // Clear command for Windows (cls)
    system("cls");
  } else if (OS == "unix" || OS == "macos") { // Clear (clear) command for Unix and similar
    system("clear");
  } else { // If none of the above is specified, then the default is "clear"
    system("clear");
  }
}

void about() { // About command
  clear();
  cout << "====================================\n";
  cout << "Lines v2.1.1\n";
  cout << "====================================\n";
  cout << "\nCopyright (C) 2019 Avery King\n";
  cout << "Partially made during a Xoads live stream\n\n";

  // About screen message
  cout << "Thanks to everyone who supported me when I showed them this\n";
  cout << "calculator.\nI would like to thank my friends, classmates, and my parents!\n";
  cout << "THANK YOU SO MUCH!!!\n\n\n";

  // Return to the main screen
  main_screen("", "");
}


void help() { // Help command
  cout << "Available commands:\n\n";
  cout << "about - Shows the About screen\n";
  cout << "help - Displays this message\n";
  cout << "copyright - Displays copyright\n";
  cout << "exit - Exits the program\n";
  cout << "clear - Clears the screen\n";
  cout << "For more help on Lines, see the Lines wiki at https://github.com/generic-pers0n/lines/wiki\n\n";

  // Return to the main screen
  main_screen("", "");
}

//////////////////////////////////////////////////////////

// Main screen
void main_screen(string custom_data, string prompt_type) {
  // Variables
  string option;

  // Parameter checks
  if (prompt_type == "prompt" && custom_data != "") {
    clear();
    // It's easier if we just detect "prompt". Any other value will be ignored
    cout << custom_data << endl;
    cout << ">> ";
    getline(cin, option);
    options(option);
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

