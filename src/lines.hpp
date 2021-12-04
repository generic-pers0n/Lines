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
#include <stdexcept>
#include <limits>

#include "liblines/liblines.hpp"
#include "lcl/lcl_interpret.hpp" // Interpreting funcitons
#include "opts.hpp"  // Option functions

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
  lines::lcl_intr::str_vec split_input;

  std::cout << ">> ";
  std::getline(std::cin, raw_input);

  if (std::cin.eof())
  {
    std::exit(EXIT_FAILURE);
  }

  split_input = lines::lcl_intr::split(raw_input, ' ');
  command.set_name(split_input[0]);

  if (split_input.size() > 1)
  {
    for (size_t i = 1; i < split_input.size(); i++)
    {
      command.add_arg(split_input[i]);
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
  std::string coor1_str, coor2_str;
  lcl_intr::coorpt coor1, coor2;
  if (command.get_name() == "coordinate") // "coordinate" comman
  {
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
      std::cout << "Invalid coordinate points entered" << std::endl;
      return;
    }

    // Calculate the equation and so with two coordinate points
    try
    {
      liblines::coordinate(coor1.x, coor1.y, coor2.x, coor2.y);
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
    double slope_input;
    std::string coor_str, slope_str;
    lcl_intr::coorpt coor;

    // Get the slope from the user
    std::cout << "Enter the slope of the graph: ";
    std::getline(std::cin, slope_str);
 
    try
    {
      slope_input = std::stod(slope_str);
    } catch (...)
    {
      std::cout << "Could not convert input from string to number" << std::endl;
      return;
    }

    // Get the coordinate point from the user
    std::cout << "Enter the coordinate point to use: ";
    std::getline(std::cin, coor_str);

    try
    {
      coor = lcl_intr::mkcoorpt(coor_str);
    } catch (std::invalid_argument& err)
    {
      std::cout << "Invalid coordinate point entered.\n";
      return; // Just return
    }

    try
    {
      // Calculate the equation
      liblines::slope(coor.x, coor.y, slope_input);
    } catch (const char* err) {
      std::cout << err << std::endl;
    }

    return;
  }

  else if (command.get_name() == "gencoor") // "gencoor" command
  {
    // Variables
    double slope, y_intercept, start, end;
    std::string start_raw, end_raw; // For ranges

    std::cout << "What is the slope and y-intercept? ";
    std::cin >> slope >> y_intercept;

    std::cout << "Enter your desired range (no decimals): ";
    std::cin >> start_raw >> end_raw;

    try 
    {
      start = std::stod(start_raw);
      end   = std::stod(end_raw);
    } catch (std::invalid_argument& err)
    {
      std::cout << "Error: invalid number entered." << std::endl;
    } catch (std::out_of_range& err)
    {
      std::cout << "Error: number out of range." << std::endl;
      std::cout << "Minimum input supported: " << std::numeric_limits<double>::min() << std::endl;
      std::cout << "Maximum input supported: " << std::numeric_limits<double>::max() << std::endl;
      std::cout << "Note that this naturally varies across system, and Lines doesn\'t have very" << std::endl;
      std::cout << "much control over this." << std::endl;
      return;
    }

    liblines::genpoints(slope, y_intercept, start, end);

    return;
  }

  else if (command.get_name() == "about") // "about" command
  {
    std::cout << "====================================\n";
    std::cout << "\tLines v3.1\n";
    std::cout << "====================================\n";
    std::cout << "Built date: " << __DATE__ << " @ " << __TIME__ << std::endl;
    std::cout << "liblines version " << liblines::major_ver << "." << liblines::minor_ver;

    if (liblines::patch_ver != 0)
    {
      std::cout << "." << liblines::patch_ver;
    }

    std::cout << std::endl << std::endl;
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

    return;
  }

  else if (command.get_name() == "help") // "help" command
  {
    std::cout << "Available commands:\n";
    std::cout << "  * coordinate\n";
    std::cout << "  * slope\n";
    std::cout << "  * gencoor\n";
    std::cout << "  * about\n";
    std::cout << "  * exit\n";

    std::cout << "For more help on these commands, and for more help on Lines,\n";
    std::cout << "please visit the Lines wiki\n";

    return;
  }

  else if (command.get_name() == "exit") // "exit" command
  {
    std::cout << "Bye!\n";
    std::exit(0);
  }

  else if (command.get_name() == "")
  {
    return;
  }

  else // Unknown commands
  {
    std::cout << "Unknown command: \'" << command.get_name() << "\'" << std::endl;
    return;
  }
}

} // namespace lines
#endif // end LINES_HPP

