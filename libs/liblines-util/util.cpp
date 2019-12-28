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
#include <lines/liblines.h>
#include <lines/util.h>

namespace Util {
  ///////////////////// Get failsafe prompt option /////////////////////
  void get_failsafe_option(vector<string> option) {
    if (option[0] == "continue") {
      cout << "Attempting to continue...\n";
    }

    else if (option[0] == "exit") {
      cout << "Exiting...";
    }

    else {
      cerr << "Unknown command\n";

      // Return to the prompt
      vector<string> input = prompt();
      get_failsafe_option(input);
    }
  }
  //////////////////////////////////////////////////////////////////////

  void get_option(vector<string> option) {
    if (option[0] == "coordinate") { // "slope" command
      double xcoor1, ycoor1, xcoor2, ycoor2;

      // Get the coordinate points from the user
      cout << "Enter coordinate point 1: ";
      cin >> xcoor1 >> ycoor1;

      cout << "Enter coordinate point 2: ";
      cin >> xcoor2 >> ycoor2;

      // Calculate the equation and so with two coordinate points
      coordinate(xcoor1, ycoor1, xcoor2, ycoor2);

      // Return to the prompt (for single prompt)
      vector<string> option = prompt();
      get_option(option);
    }

    else if (option[0] == "slope") { // "coordinate" command
      // Variables
      double xcoor, ycoor, slope_value;

      // Get the slope from the user
      cout << "Enter the slope of the graph: ";
      cin >> slope_value;

      // Get the coordinate points from the user
      cout << "Enter coordinate point x: ";
      cin >> xcoor;

      cout << "Enter coordinate point y: ";
      cin >> ycoor;

      // Calculate the equation
      slope(xcoor, ycoor, slope_value);

      // Return to the prompt
      vector<string> option = prompt();
      get_option(option);
    }

    else if (option[0] == "gencoor") { // "gencoor" command
      // Variables
      double y_intercept;
      double slope;
      int max_number;
      int starting_number;

      if (option[1] == "") { // default option
        // Get the y-intercept and slope
        cout << "What is the slope? ";
        cin >> slope;

        cout << "What is the y-intercept? ";
        cin >> y_intercept;

        cout << "What number do you want to start at? ";
        cin >> starting_number;

        // Get the amount of coordinate points the user wants
        cout << "What number should be the maximum generated (no decimals)? ";
        cin >> max_number;

        generate_points(slope, y_intercept, max_number, starting_number);

        // Return to the prompt
        vector<string> option = prompt();
        get_option(option);
      }

      else if (option[1] == "write") {
        // Get the and slope
        cout << "What is the slope and y-intercept";
        cin >> slope >> y_intercept;

        // Get the number the user wants to start at
        cout << "What number do you want to start at? ";
        cin >> starting_number;

        // Get the amount of coordinate points the user wants
        cout << "What number should be the maximum generated (no decimals)? ";
        cin >> max_number;

        cout << "The file will be named Coordinate Points.txt\n";
        cout << "It will be saved to your desktop\n\n";

        #ifdef __unix__
          write_generated_points_to_file(slope, y_intercept, max_number, starting_number, "Coordinate Points.txt");
          system("mv \"Coordinate Points.txt\" ~/Desktop");
        #elif _WIN32
          write_generated_points_to_file(slope, y_intercept, max_number, starting_number, "Coordinate Points.txt");
          system("move \"Coordinate Points.txt\" %userprofile%\\Desktop");
        #endif

        // Return to the main prompt
        vector<string> option = prompt();
        get_option(option);
      }
    }

    else if (option[0] == "about") { // "about" command
      cout << "====================================\n";
      cout << "Lines v3.0 dev\n";
      cout << "====================================\n\n";
      
      cout << "Lines, the Swiss Army knife for Linear Graphs\n";
      cout << "Partially made during a Xoads live stream\n";
      cout << "We miss you, Xoads!\n\n";

      cout << "Thanks to everyone who supported me when I showed them this\n";
      cout << "calculator.\nI would like to thank my friends, classmates, and\n";
      cout << "my parents! THANK YOU SO MUCH!!!\n\n";

      cout << "Lines  Copyright (C) 2019  Avery King\n";
      cout << "This program comes with ABSOLUTELY NO WARRANTY; for details type `copyright'.\n";
      cout << "This is free software, and you are welcome to redistribute it\n";
      cout << "under certain conditions; type `copyright' for details.\n";

      // Return to the prompt
      vector<string> option = prompt();
      get_option(option);
    }

    else if (option[0] == "copyright") { // "copyright command"
      cout << "The swiss army knife for linear graphs.\n\n";
      cout << "Copyright (C) 2019  Avery King\n";
      cout << "This program is free software: you can redistribute it and/or modify\n";
      cout << "it under the terms of the GNU General Public License as published by\n";
      cout << "the Free Software Foundation, either version 3 of the License, or\n";
      cout << "(at your option) any later version.\n\n";
      cout << "This program is distributed in the hope that it will be useful,\n";
      cout << "but WITHOUT ANY WARRANTY; without even the implied warranty of\n";
      cout << "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n";
      cout << "GNU General Public License for more details.\n\n";
      cout << "You should have received a copy of the GNU General Public License\n";
      cout << "along with this program.  If not, see <https://www.gnu.org/licenses/>.\n\n";

      // Return to the main prompt
      vector<string> option = prompt();
      get_option(option);
    }

    else if (option[0] == "exit") { // "exit" command
      // Stuff to clean up goes here.
      //
      // Mainly, there should be an unload function here. That
      // function would unload any plugins, close things, etc.
      cout << "Bye!";
      exit(0);
    }

    else if (option[0] == "") { // If nothing was entered
      vector<string> option = prompt();
      get_option(option);
    }

    else { // Unknown commands
      cout << option[0] << " is not a command" << endl;

      // Return to the prompt (for single prompt)
      vector<string> option = prompt();
      get_option(option);
    }
  }
}
