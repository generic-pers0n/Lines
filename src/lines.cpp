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
#include <iostream>
#include "lines.hpp"

int main() {
  // Copyright screen
  std::cout << "Lines  Copyright (C) 2019-2020  Avery King\n";
  std::cout << "This program comes with ABSOLUTELY NO WARRANTY; for details type `copyright'.\n";
  std::cout << "This is free software, and you are welcome to redistribute it\n";
  std::cout << "under certain conditions; type `copyright' for details.\n\n";

  // Welcome message and main prompt
  std::cout << "Welcome to Lines. For a list of commands, type \'help\'.\n";

  #ifdef PORT // portable macro
  std::cout << "You\'re using a portable version of Lines\n";
  #endif

  // Return to the prompt
  std::vector<string> commands = prompt();
  options(commands);

  return 0;
}


