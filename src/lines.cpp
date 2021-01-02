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
#include <iostream>
#include "lines.hpp"
#include "opts.hpp"

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
    lines::opts::opt_t commands = prompt();
    exec_builtin_opt(commands);
  }

  return 0;
}


