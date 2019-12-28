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
#include "lines.hpp"
#include "libs/liblines-util/util.h"
#include <getopt.h>
using namespace Util;

int main(int argc, char *argv[]) {
  // Register SIGINT (interrupt) with handler()
  signal(SIGINT, handler);

  // Copyright screen
  cout << "Lines  Copyright (C) 2019  Avery King\n";
  cout << "This program comes with ABSOLUTELY NO WARRANTY; for details type `copyright'.\n";
  cout << "This is free software, and you are welcome to redistribute it\n";
  cout << "under certain conditions; type `copyright' for details.\n\n";

  // Welcome message
  cout << "Welcome to Lines. For a list of commands, type \'help\'.\n";

  // Main prompt
  vector<string> input = prompt();
  get_option(input);
}

