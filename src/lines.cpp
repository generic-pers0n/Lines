/** Copyright (C) 2019-2021 Avery King <avery98@pm.me>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 **/
/** @file lines.cpp
 * 
 * The core of Lines. Although this file does not do much, this file is
 * the core of Lines as the program starts here.
 * 
 * @see lines.hpp
 * 
 **/
#include <iostream>
#include "lines.hpp"
#include "opts.hpp"

/** The main function of Lines
 * 
 * This is the main function of Lines. There is nothing to explain here as
 * this is where every program in C and C++ begins their execution. Why this
 * is even documented I don't even know.
 * 
 * @returns 0. Just 0. Unless std::exit() says otherwise.
 *
 **/
int main()
{
  std::cout << "Lines  Copyright (C) 2019-2021  Avery King\n";
  std::cout << "This program comes with ABSOLUTELY NO WARRANTY; for details type `about\'.\n";
  std::cout << "This is free software, and you are welcome to redistribute it\n";
  std::cout << "under certain conditions; type `about' for details.\n\n";
  std::cout << "Welcome to Lines. For a list of commands, type \'help\'.\n";

  // Return to the prompt
  while (true)
  {
    lines::opts::opt_t commands = lines::prompt();
    lines::exec_builtin_opt(commands);
  }

  return 0;
}


