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
#include <lines/util.h>
using namespace std;

// Function declarations
void coordinate(double xcoor1, double ycoor1, double xcoor2, double ycoor2);
void slope(double xcoor, double ycoor, double slope);
void generate_points(double slope, double y_intercept, int max_number, int starting_number);
void generate_point(double slope, double y_intercept, int number);
void write_generated_points_to_file(double slope, double y_intercept, int max_number, int starting_number, string file_name);

void main_screen(string custom_data, string prompt_type);
void options(string option); // For use later on
void clear();
void help();
void show_copyright(bool program_start = false);
string get_platform();

// Global variables
string answer;

void options(string option) {
  // Do an action based on the option
  if (option == "1") { // Find equation using two coordinate points
    // NOTE: Option 1 is effectively the "slope" command. It does not have its own
    // funcitonality anymore. This is part of the migration process of moving any
    // command-line functionality from Lines itself to liblines-util.
    Util::get_single_option("slope");
  }

  else if (option == "2") { // Find equation and related using slope and coordinate point
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

    // Return to the main screen
    main_screen("", "");
  }

  else if (option == "3") { // Generate coordinate points
    // Variables
    double y_intercept;
    double slope;

    int max_number;
    int starting_number;

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

    // Return to the main screen
    main_screen("", "");
  }

  else if (option == "4") {
    // Variables
    double y_intercept;
    double slope;

    string custom_file_name_response;
    int max_number;
    int starting_number;

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

    string platform = get_platform();

    if (platform == "unix") {
      write_generated_points_to_file(slope, y_intercept, max_number, starting_number, "Coordinate Points.txt");
      system("mv \"Coordinate Points.txt\" ~/Desktop");
    }

    else if (platform == "win") {
      write_generated_points_to_file(slope, y_intercept, max_number, starting_number, "Coordinate Points.txt");
      system("move \"Coordinate Points.txt\" %userprofile%\\Desktop");
    }

    // Return to the main screen
    main_screen("", "");
  }

  else if (option == "5") { // Generate one coordinate point with number
    double slope;
    double y_intercept;
    double number;

    // Get the slope
    cout << "What is the slope and y-intercept? ";
    cin >> slope >> y_intercept;

    // Get the number the user wants to use for x
    cout << "What is the number that x will be? ";
    cin >> number;

    // Generate a certain amount of coordinate points
    generate_point(slope, y_intercept, number);

    // Return to the main screen
    main_screen("", "");
  }

  // "about" command
  else if (option == "about") {
    clear();
    cout << "====================================\n";
    cout << "Lines v3.0 dev\n";
    cout << "====================================\n";
    cout << "\n2019 Avery King\n";
    cout << "Partially made during a Xoads live stream\n\n";

    // About screen message
    cout << "Thanks to everyone who supported me when I showed them this \
calculator.\nI would like to thank my friends, classmates, and my parents! \
THANK YOU SO MUCH!!!\n\n\n";

    // Return to the main screen
    main_screen("", "");
  }

  else if (option == "clear") {
    clear();
    main_screen("", "");
  }

  // "help" command
  else if (option == "help") {
    // Run the help command
    help();
  }

  else if (option == "exit") { // Command 2 (exit)
    clear();
    cout << "Bye!\n";
    exit(0);
  }

  else if (option == "copyright") {
    show_copyright();
    main_screen("", "");
  }

  else {
    main_screen("Unknown command - " + option, "prompt");
  }
}

#endif // end lines.hpp

