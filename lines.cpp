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
#include "libs/liblines-util/libcalc.hpp"

// Function declarations
void OriginalLines::original_main();


int main(int argc, char *argv[]) {
  if (argv[1] == "--classic") {
    cout << "You have implied the --classic flag\n\n";
    cout << "You will have the opportunity to use an older version of Lines.However,\n";
    cout << "You will be able to go back to this version of Lines. To get back to\n";
    cout << "this screen again, use the \'classic\' command to get back to classic\n";
    cout << "mode\n\n";

    OriginalLines::original_main();
  }

  else {
    cerr << "Unknown command: " << argv[1] << endl;
    return -1;
  }

  clear();
  main_screen("", "");
}

