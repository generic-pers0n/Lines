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
/* lines.hpp
 *
 *
 * This file contains the basic functionallity of Lines. It includes
 * the command-line functionallity, what each command does, etc.
 *
 */
#ifndef LINES_HPP
#define LINES_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <stdexcept>
#include <boost/algorithm/string.hpp>
#include "liblines/liblines.hpp"
#include "frac.hpp"

// Conditional includes
#ifdef DEBUG
#include <limits>
#endif

using namespace std;

std::vector<string> prompt() {
  std::vector<string> commands;
  std::string usr_input;

  std::cout << ">> ";
  std::getline(std::cin, usr_input);

  // Split the input and save it into 'commands'
  boost::split(commands, usr_input, boost::is_any_of(" "));
  return commands;
}

void options(std::vector<string> option) {
  if (option[0] == "coordinate") { // "coordinate" command
    double xcoor1, ycoor1, xcoor2, ycoor2; // Coordinate point variables
    std::string xcoor1_str, ycoor1_str, xcoor2_str, ycoor2_str; // Coordinate point input variables

    // Get the coordinate points from the user
    std::cout << "Enter coordinate point 1: ";
    std::cin >> xcoor1_str >> ycoor1_str;

    std::cout << "Enter coordinate point 2: ";
    std::cin >> xcoor2_str >> ycoor2_str;

    // Convert the input from a string to a fraction
    try {
      xcoor1 = frac(xcoor1_str);
      ycoor1 = frac(ycoor1_str);
      xcoor2 = frac(xcoor2_str);
      ycoor2 = frac(ycoor2_str);
    } catch (std::logic_error& err) {
      std::cout << err.what() << ", setting all values to zero!\n";
      xcoor1 = 0, ycoor1 = 0, xcoor2 = 0, ycoor2 = 0;
    }

    // Calculate the equation and so with two coordinate points
    try {
      coordinate(xcoor1, ycoor1, xcoor2, ycoor2);
    } catch (const char* err) {
      std::cout << err << endl;
      std::vector<string> commands = prompt();
      options(commands);
    }

    // Return to the prompt
    std::vector<string> commands = prompt();
    options(commands);
  }

  else if (option[0] == "slope") { // "slope" command
    // Variables
    double xcoor, ycoor, slope_value;

    // Get the slope from the user
    std::cout << "Enter the slope of the graph: ";
    std::cin >> slope_value;

    // Get the coordinate points from the user
    std::cout << "Enter the coordinate point to use: ";
    std::cin >> xcoor >> ycoor;

    try {
      // Calculate the equation
      slope(xcoor, ycoor, slope_value);
    } catch (const char* err) {
      std::cout << err << endl;
    }

    // Return to the prompt
    std::vector<string> commands = prompt();
    options(commands);
  }

  else if (option[0] == "gencoor") { // "gencoor" command
    // Variables
    double slope, y_intercept;
    int starting_number, max_number; // For ranges

    // Find the subcommands in the vector
    // Note: the 'write' subcommand has been removed, and we're still
    // keeping the 'default' subcommand until v4.0, maybe earlier
    std::vector<string>::iterator single_subcmd = std::find(option.begin(), option.end(), "single");
    std::vector<string>::iterator default_subcmd = std::find(option.begin(), option.end(), "default");

    if (single_subcmd == option.end() && default_subcmd == option.end()) { // Default action, where there's no subcommand
      // Get the y-intercept and slope
      std::cout << "What is the slope and y-intercept of your equation? ";
      std::cin >> slope >> y_intercept;

      std::cout << "Enter your desired range (no decimals): ";
      std::cin >> starting_number >> max_number;

      generate_points(slope, y_intercept, max_number, starting_number);

      // Return to the prompt
      std::vector<string> commands = prompt();
      options(commands);
    } else if (single_subcmd != option.end()) { // Found 'gencoor single'
      double number; // We're redeclaring this because we can take advantage of this type

      // Get the slope
      std::cout << "What is the slope and y-intercept? ";
      std::cin >> slope >> y_intercept;

      // Get the number the user wants to use for x
      std::cout << "What is the number that x will be? ";
      std::cin >> number;

      // Generate a certain amount of coordinate points
      generate_point(slope, y_intercept, number);

      // Return to the prompt
      std::vector<string> commands = prompt();
      options(commands);
    } else if (default_subcmd != option.end()) { // Found 'gencoor default'
      // Deprecation warning
      std::cout << "Note: this command is DEPRECATED! Use gencoor (without any subcommands) instead.\n\n";
      std::cout << "Tip of the day: in Lines v3.0, gencoor had a bug in which if you were to run it without\n";
      std::cout << "any subcommands, then Lines would crash with a segmentation fault error (on Windows you\n";
      std::cout << "wouldn\'t see anything). To circumvent this \'gencoor default\' was born, but now, obviously,\n";
      std::cout << "this has been fixed...\n";

      // Get the y-intercept and slope
      cout << "What is the slope and y-intercept? ";
      cin >> slope >> y_intercept;

      cout << "What is the range you want to use (no decimals)? ";
      cin >> starting_number >> max_number;

      generate_points(slope, y_intercept, max_number, starting_number);

      // Return to the prompt
      std::vector<string> commands = prompt();
      options(commands);
    }
  }

  else if (option[0] == "about") { // "about" command
    std::cout << "====================================\n";
    #ifdef PORT
    std::cout << "\tLines Portable v3.0\n";
    #elif defined(DEBUG)
    std::cout << "\tLines v3.0-debug\n"; // Technically v3.1-dev2-debug, but we'll leave it for now
    #else // Should no other macro be defined
    std::cout << "\tLines v3.0\n";
    #endif
    std::cout << "====================================\n";

    std::cout << "Copyright (C) 2019-2020 Avery King\n";
    std::cout << "For more information about the copyright on Lines, type \'copyright\'\n\n";

    // Debug information
    #ifdef DEBUG
    std::cout << "Build date: " << __DATE__ << " @ " __TIME__ << std::endl << std::endl;

    // Sizes
    std::cout << "Sizes of int and float types: \n\n";
    std::cout << "int: " << sizeof(int) << std::endl;
    std::cout << "long: " << sizeof(long) << std::endl;
    std::cout << "long long: " << sizeof(long long) << std::endl;
    std::cout << "double: " << sizeof(double) << std::endl;
    std::cout << "long double: " << sizeof(long double) << std::endl << std::endl;

    // Values
    std::cout << "Possible ranges for int and float types: \n\n";
    std::cout << "int: " << std::numeric_limits<int>::min() << " to " << std::numeric_limits<int>::max() << std::endl;
    std::cout << "long: " << std::numeric_limits<long>::min() << " to " << std::numeric_limits<long>::max() << std::endl;
    std::cout << "long long: " << std::numeric_limits<long>::min() << " to " << std::numeric_limits<long long>::max()<< std::endl;
    std::cout << "double: " << std::numeric_limits<double>::min() << " to " << std::numeric_limits<double>::max() << std::endl;
    std::cout << "long double: " << std::numeric_limits<long double>::min() << " to " << std::numeric_limits<long double>::max() << std::endl << std::endl;

    #endif

    std::cout << "Partially made during a Xoads live stream (Xoads is my friend). Thanks to everyone who\n";
    std::cout << "supported me when I showed them this calculator. I would like to thank my friends,\n";
    std::cout << "classmates, and my parents! THANK YOU SO MUCH!!!\n\n";

    // Return to the prompt
    std::vector<string> commands = prompt();
    options(commands);
  }

  else if (option[0] == "help") { // "help" command
    std::cout << "Available commands:\n";
    std::cout << "  * coordinate\n";
    std::cout << "  * slope\n";
    std::cout << "  * gencoor:\n";

    std::cout << "    - default\n";
    std::cout << "    - write\n";
    std::cout << "    - single\n";

    std::cout << "  * about\n";
    std::cout << "  * copyright\n";
    std::cout << "  * exit\n";

    std::cout << "For more help on these commands, and for more help on Lines,\n";
    std::cout << "please visit the Lines wiki\n";

    // Return to the prompt
    std::vector<string> commands = prompt();
    options(commands);
  }

  else if (option[0] == "copyright") { // "copyright command"
    std::cout << "The swiss army knife for linear graphs.\n\n";
    std::cout << "Copyright (C) 2019-2020  Avery King\n";
    std::cout << "This program is free software: you can redistribute it and/or modify\n";
    std::cout << "it under the terms of the GNU General Public License as published by\n";
    std::cout << "the Free Software Foundation, either version 3 of the License, or\n";
    std::cout << "(at your option) any later version.\n\n";
    std::cout << "This program is distributed in the hope that it will be useful,\n";
    std::cout << "but WITHOUT ANY WARRANTY; without even the implied warranty of\n";
    std::cout << "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n";
    std::cout << "GNU General Public License for more details.\n\n";
    std::cout << "You should have received a copy of the GNU General Public License\n";
    std::cout << "along with this program.  If not, see <https://www.gnu.org/licenses/>.\n";

    // Return to the prompt
    std::vector<string> commands = prompt();
    options(commands);
  }

  else if (option[0] == "exit") { // "exit" command
    std::cout << "Bye!\n";
    exit(0);
  }

  else if (option[0] == "") { // If nothing was entered
    // Return to the prompt
    std::vector<string> commands = prompt();
    options(commands);
  }

  else { // Unknown commands
    std::cout << "'" << option[0] << "'" << " is not a command" << endl;

    // Return to the prompt
    std::vector<string> commands = prompt();
    options(commands);
  }
}

#endif // end lines.hpp

