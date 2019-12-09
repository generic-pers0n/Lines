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
/* This is my original equation calculator. It has very basic
 * funtionallity, and the second feature is unimplemented.
 *
 * I've decided to repurpose this code to make a "classic
 * mode" for Lines. This allows you to use my original
 * equation calculator.
 *
 * I was going to test compiling libraries when I found this
 * in my Downloads folder on my tablet (that's where I
 * sometimes keep my code). I was already thinking of making
 * a classic mode for Lines, but when I saw this, I then
 * thought of using this instead of making the first version
 * of Lines from scratch.
 *
 * Originally, this calculator did not have a license. It
 * remained like that for a long time. However, as you've
 * read above, this is licensed udner the GPL, version 3 or
 * (at your choice) any later version, the same license as
 * Lines.
 *
 * What you see here is what you get. This is before my
 * initial release of Lines. However, there are a few things
 * that were neccessarly to change to make this a library.
 * My original calculator was not a library, but instead an
 * actual application.
 *
 **/

#include "libcalc.hpp"


// Global variables
int option;

void main_screen() {
  // Welcome screen
	cout << "========================================\n";
	cout << "Linear Graph Equation Calculator\n";
	cout << "========================================\n\n";

  // Options screen
  cout << "Select an option: \n\n";
  cout << "(1) Find an equation with two given points\n";
  cout << "(2) Find an equation with a given slope and a point (unimplemented)\n\n";
  cout << ">> ";
  cin >> option;
}

// NOTE: The main function has been change from 'int main' to
// 'void main'. This is because a library does not
// have a main() function. While the original application was
// not a library, this has been converted to a library.
// Nevertheless, the code you see here was the original code
// here, but this is even before the first version of Lines.
// Plus, there is a new namespace: 

namespace OriginalLines{
  void main() {

    // Display the main screen
    main_screen();

    // Do an action based on the selection
    switch (option) {
      case (1):
        double coor1x, coor1y, coor2x, coor2y;

        // Get the coordinate points from the user
        cout << "Enter coordinate point 1 (x): ";
        cin >> coor1x;

        cout << "Enter coordinate point 1 (y): ";
        cin >> coor1y;

        cout << "Enter coordinate point 2 (x): ";
        cin >> coor2x;

        cout << "Enter coordinate point 2 (y): ";
        cin >> coor2y;

        // Declare two Linear objects
        Linear linear;
        linear.coordinate(coor1x, coor1y, coor2x, coor2y);
        break;

      // NOTE: Option 2 is not yet implemented
      case (2):
        cout << "This feature is not available yet\n";
        return 0;
        break;

      case (3):
        cout << "2019 Avery King\n\n";

      default:
        cerr << "Error: you need to select an option!\n";
        main();
        break;
    }
  }
}

