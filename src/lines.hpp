/* Copyright (C) 2019-2021 Avery King <avery98@pm.me>
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
#include <vector>
#include <stdexcept>

// C headers
#include <cstdlib>

#include "liblines/liblines.hpp"
#include "lcl/lcl_interpret.hpp" // Interpreting funcitons
#include "opts.hpp"  // Option functions

// Conditional includes
#ifdef DEBUG
#include <limits>
#endif

namespace lines {

/**
 * A function that brings up the main prompt
 * 
 * This function gets a line of input and splits the input up into a string
 * (the 1st argument or the option in other words) and a vector (of std::string,
 * for any arguments).
 *
 * Note that most likely there are a few things that I do want to do to make
 * things perhaps a bit easier to comprehend (or something). However, the overall
 * behavior won't be changed and everything will still be the same.
 * 
 * @return Returns a vector (of std::string) containing the split input.
 * @see main()
 **/
opts::opt_t prompt()
{
  opts::opt_t command;
  std::string raw_input;
  std::string main_opt;
  std::size_t whitespace;

  std::cout << ">> ";
  std::getline(std::cin, raw_input);

  whitespace = raw_input.find(' ');

  if (std::cin.eof())
  {
    std::exit(EXIT_FAILURE);
  }

  if (whitespace == std::string::npos)
  {
    command.set_name(raw_input);
    return command;
  } else
  {
    main_opt = raw_input.substr(0, whitespace + 1);
    size_t _space = main_opt.find(' ');

    while (_space != std::string::npos)
    {
      main_opt.erase(_space, main_opt.find(' '));
	  _space = main_opt.find(' ');
    }

    command.set_name(main_opt);
  }

  // Erase the main option
  raw_input.erase(0, whitespace + 1);

  ////////////////////////////////////////////////////////
  // Heyo! I'm a code block                             //
  //                                                    //
  // This block down here is for finding and splitting  //
  // arguments.                                         //
  ////////////////////////////////////////////////////////
  {
    /**
     * This area here is what I want to refactor. I'm wanting to use
     * iterators instead of what we're already doing instead, or maybe
     * a hybrid (but more emphasism on iterators, if you know what I
     * mean).
     **/
    std::size_t __space = raw_input.find(' ');
    std::size_t __begin = 0; // Essentially this will stay constant
    std::string __tmp_str;

    for (std::size_t i = 0; i < raw_input.size(); i++)
    {
      __space = raw_input.find(' ');
      if (__space != std::string::npos)
      {
        __tmp_str = raw_input.substr(__begin, __space + 1);

        raw_input.erase(__begin, __space); // We eventually modify this string
      } else
      {
        __tmp_str = raw_input;
        command.add_arg(__tmp_str);
      }
    }
  }

  return command;
}

/**  The function that executes the primary options in Lines.
 *
 * Simply put, this function is essentially the LCL right here. However, this
 * only executes unaliased options in Lines. If an option is aliased, then this
 * function will not recognize it.
 *
 * @return Returns 0 if an option was valid. Otherwise, -1 is returned.
 **/
void exec_builtin_opt(opts::opt_t& command)
{
  if (command.get_name() == "coordinate") // "coordinate" comman
  {
    std::string coor1_str, coor2_str;
    lcl_intr::coorpt coor1, coor2;

    // Get the coordinate points from the user
    std::cout << "Enter coordinate point 1: ";
    std::getline(std::cin, coor1_str);

    std::cout << "Enter coordinate point 2: ";
    std::getline(std::cin, coor2_str);

    // Convert the input from a string to a fraction
    try
    {
      coor1 = lcl_intr::mkcoorpt(coor1_str);
      coor2 = lcl_intr::mkcoorpt(coor2_str);
    } catch (std::invalid_argument& err)
    {
      std::cout << "Invalid coordinate points entered (most likely), using default values\n";

      coor1.x = coor1.y = 1;
      coor2.x = coor2.y = 2;
    }

    // Calculate the equation and so with two coordinate points
    try
    {
      coordinate(coor1.x, coor1.y, coor2.x, coor2.y);
    } catch (const char* err) // Yes, this (and others like it) will be changed in liblines v4.0
    {
      std::cout << err << std::endl;
      return;
    }

    return;
  }

  else if (command.get_name() == "slope") // "slope" command
  {
    // Variables
    double slope_value;
    double coor[2];

    // Get the slope from the user
    std::cout << "Enter the slope of the graph: ";
    std::cin >> slope_value;

    // Get the coordinate points from the user
    std::cout << "Enter the coordinate point to use: ";
    std::cin >> coor[0] >> coor[1];

    try {
      // Calculate the equation
      slope(coor[0], coor[1], slope_value);
    } catch (const char* err) {
      std::cout << err << std::endl;
    }

    return;
  }

  else if (command.get_name() == "gencoor") // "gencoor" command
  {
    // Variables
    double slope, y_intercept, input;
    int start, end; // For ranges

    // Find the subcommands in the vector
    // Note: we're still keeping the 'default' subcommand until v4.0 or something
    // std::vector<std::string> cmd_args = command.get_args();
    // auto arg = cmd_args.begin();

    if (command.has_args() != true)
    {
      std::cout << "What is the slope and y-intercept? ";
      std::cin >> slope >> y_intercept;

      std::cout << "Enter your desired range (no decimals): ";
      std::cin >> start >> end;

      generate_points(slope, y_intercept, start, end);
      return;
    }

    /*else if (*arg == "") // Default action, where there's no subcommand
    {
      // Get the y-intercept and slope
      std::cout << "What is the slope and y-intercept of your equation? ";
      std::cin >> slope >> y_intercept;

      std::cout << "Enter your desired range (no decimals): ";
      std::cin >> start >> end;

      generate_points(slope, y_intercept, start, end);
    }*/

    else if (command.has_arg("single")) // Found 'gencoor single'
    {
      // Get the slope
      std::cout << "What is the slope and y-intercept? ";
      std::cin >> slope >> y_intercept;

      // Get the number the user wants to use for x
      std::cout << "What is the number that x will be? ";
      std::cin >> input;

      // Generate a certain amount of coordinate points
      generate_point(slope, y_intercept, input);
    }

    else if (command.has_arg("default")) // Found 'gencoor default'
    {
      // Deprecation warning
      std::cout << "Note: this argument is DEPRECATED! Use gencoor (without any subcommands) instead.\n\n";

      /* Tip of the day: in Lines v3.0, gencoor had a bug in which if you were to run it without
       * any subcommands, then Lines would crash with a segmentation fault error. To circumvent
       * this, gencoor default was born. Now, obviously, this has been fixed...
       * 
       * Yes, I know that having a 'default' option was obviously a bad way to deal with things
       * back then, but now I know better...
       */

      // Get the y-intercept and slope
      std::cout << "What is the slope and y-intercept? ";
      std::cin >> slope >> y_intercept;

      std::cout << "Enter your desired range (no decimals): ";
      std::cin >> start >> end;

      generate_points(slope, y_intercept, start, end);
    }

    else
    {
      std::cout << "Unknown argument.\n";
      std::cout << "usage: gencoor [option]\n";
      std::cout << "Whereas \'option\' (optional) can be single or default (deprecated)\n";
    }

    return;
  }

  else if (command.get_name() == "about") // "about" command
  {
    std::cout << "====================================\n";
    std::cout << "\tLines v3.1b1\n";
    std::cout << "====================================\n";
    std::cout << "Built date: " << __DATE__ << " @ " << __TIME__ << std::endl << std::endl;    

    std::cout << "Copyright (C) 2019-2021  Avery King\n\n";

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

    // Debug information
    #ifdef DEBUG

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
  }

  else if (command.get_name() == "help") // "help" command
  {
    std::cout << "Available commands:\n";
    std::cout << "  * coordinate\n";
    std::cout << "  * slope\n";
    std::cout << "  * gencoor:\n";

    std::cout << "    - default (deprecated)\n";
    std::cout << "    - write\n";
    std::cout << "    - single\n";

    std::cout << "  * about\n";
    std::cout << "  * exit\n";

    std::cout << "For more help on these commands, and for more help on Lines,\n";
    std::cout << "please visit the Lines wiki\n";

    return;
  }

  else if (command.get_name() == "exit") { // "exit" command
    std::cout << "Bye!\n";
    std::exit(0);
  }

  else if (command.get_name() == "")
  {
    return;
  }

  else { // Unknown commands
    std::cout << "Unknown command: \'" << command.get_name() << "\'" << std::endl;
    return;
  }
}

} // namespace lines
#endif // end LINES_HPP

