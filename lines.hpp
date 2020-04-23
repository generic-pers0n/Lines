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
/* lines.hpp
 *
 *
 * This file contains the basic functionallity of Lines. It includes
 * the command-line functionallity, what each command does, etc.
 *
 **/
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <boost/algorithm/string.hpp>
#include "liblines/liblines.hpp"
using namespace std;

// Global variables
string answer;

vector<string> prompt() {
  vector<string> commands;
  string usr_input;

  cout << ">> ";
  getline(cin, usr_input);

  // Split the input and save it into 'commands'
  boost::split(commands, usr_input, boost::is_any_of(" "));
  return commands;
}

void options(vector<string> option) {
  if (option[0] == "coordinate") { // "coordinate" command
    double xcoor1, ycoor1, xcoor2, ycoor2;

    // Get the coordinate points from the user
    cout << "Enter coordinate point 1: ";
    cin >> xcoor1 >> ycoor1;

    cout << "Enter coordinate point 2: ";
    cin >> xcoor2 >> ycoor2;

    // Calculate the equation and so with two coordinate points
    try {
      coordinate(xcoor1, ycoor1, xcoor2, ycoor2);
    } catch (const char* err) {
      cout << err << endl;
      vector<string> commands = prompt();
      options(commands);
    }

    // Return to the prompt
    vector<string> commands = prompt();
    options(commands);
  }

  else if (option[0] == "slope") { // "slope" command
    // Variables
    double xcoor, ycoor, slope_value;

    // Get the slope from the user
    cout << "Enter the slope of the graph: ";
    cin >> slope_value;

    // Get the coordinate points from the user
    cout << "Enter the coordinate point to use: ";
    cin >> xcoor >> ycoor;

    // Calculate the equation
    slope(xcoor, ycoor, slope_value);

    // Return to the prompt
    vector<string> commands = prompt();
    options(commands);
  }

  else if (option[0] == "gencoor") { // "gencoor" command
    // Variables
    double y_intercept;
    double slope;
    int max_number;
    int starting_number;

    if (option[1] == "default") { // default option (gencoor default)
      // Get the y-intercept and slope
      cout << "What is the slope? ";
      cin >> slope;

      cout << "What is the y-intercept? ";
      cin >> y_intercept;

      cout << "What number do you want to start at? ";
      cin >> starting_number;

      // Get the amount of coordinate points the user wants
      cout << "What number should be the maximum generated (no decimals)? ";
      cin >> max_number;

      generate_points(slope, y_intercept, max_number, starting_number);

      // Return to the prompt
      vector<string> commands = prompt();
      options(commands);
    }

    else if (option[1] == "single") {
      double slope;
      double y_intercept;
      double number;

      // Get the slope
      cout << "What is the slope and y-intercept? ";
      cin >> slope >> y_intercept;

      // Get the number the user wants to use for x
      cout << "What is the number that x will be? ";
      cin >> number;

      // Generate a certain amount of coordinate points
      generate_point(slope, y_intercept, number);

      // Return to the prompt
      vector<string> commands = prompt();
      options(commands);
    }

    else if (option[1] == "write") { // NOTE: Disabled
      cout << "There are a few problems with gencoor write. Currently, it is disabled.\n";
      cout << "Hopefully one day, gencoor write can shine...\n";

      // Return to the prompt
      vector<string> commands = prompt();
      options(commands);
    }

    else {
      cout << "Unknown option: " << option[1] << endl;

      // Return to the prompt
      vector<string> commands = prompt();
      options(commands);
    }
  }

  else if (option[0] == "about") { // "about" command
    cout << "====================================\n";
    #ifdef PORT
    cout << "\tLines Portable v3.0\n";
    #else
    cout << "\tLines v3.0\n";
    #endif
    cout << "====================================\n";
    cout << "Copyright (C) 2019-2020 Avery King\n";
    cout << "For more information about the copyright on Lines, type \'copyright\'\n\n";

    cout << "Partially made during a Xoads live stream (Xoads is my friend). Thanks to everyone who\n";
    cout << "supported me when I showed them this calculator. I would like to thank my friends,\n";
    cout << "classmates, and my parents! THANK YOU SO MUCH!!!\n\n";

    // Return to the prompt
    vector<string> commands = prompt();
    options(commands);
  }

  else if (option[0] == "help") { // "help" command
    cout << "Available commands:\n";
    cout << "  * coordinate\n";
    cout << "  * slope\n";
    cout << "  * gencoor:\n";

    cout << "    - default\n";
    cout << "    - write\n";
    cout << "    - single\n";

    cout << "  * about\n";
    cout << "  * copyright\n";
    cout << "  * exit\n";

    cout << "For more help on these commands, and for more help on Lines,\n";
    cout << "please visit the Lines wiki\n";

    // Return to the prompt
    vector<string> commands = prompt();
    options(commands);
  }

  else if (option[0] == "copyright") { // "copyright command"
    cout << "The swiss army knife for linear graphs.\n\n";
    cout << "Copyright (C) 2019-2020  Avery King\n";
    cout << "This program is free software: you can redistribute it and/or modify\n";
    cout << "it under the terms of the GNU General Public License as published by\n";
    cout << "the Free Software Foundation, either version 3 of the License, or\n";
    cout << "(at your option) any later version.\n\n";
    cout << "This program is distributed in the hope that it will be useful,\n";
    cout << "but WITHOUT ANY WARRANTY; without even the implied warranty of\n";
    cout << "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n";
    cout << "GNU General Public License for more details.\n\n";
    cout << "You should have received a copy of the GNU General Public License\n";
    cout << "along with this program.  If not, see <https://www.gnu.org/licenses/>.\n";

    // Return to the prompt
    vector<string> commands = prompt();
    options(commands);
  }

  else if (option[0] == "exit") { // "exit" command
    cout << "Bye!\n";
    exit(0);
  }

  else if (option[0] == "") { // If nothing was entered
    // Return to the prompt
    vector<string> commands = prompt();
    options(commands);
  }

  else { // Unknown commands
    cout << "'" << option[0] << "'" << " is not a command" << endl;

    // Return to the prompt
    vector<string> commands = prompt();
    options(commands);
  }
}

