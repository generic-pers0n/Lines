/* Copyright (C) 2019 Avery King <avery98@pm.me>
 *
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

#ifndef LINES_H
#define LINES_H

#include <iostream>
#include <string>
#include <cstdlib>
#include "libs/liblines-util/util.h"
#include <csignal>
using namespace std;

// Signal handler
void handler(int sig_num) {
  cout << "\nSignal " << sig_num << " received. Exiting...\n";

  // Call a custom exit() function here, but it's unimplemented
  // Something like unload() would be called

  // Finally, exit
  exit(sig_num);
}

#endif // end lines.hpp

