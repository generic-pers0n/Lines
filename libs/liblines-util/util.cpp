#include <lines/lines.h>
#include <lines/util.h>

namespace Util {
  ///////////////////// Get failsafe prompt option /////////////////////
  void failsafe_multi_options(vector<string> option);

  void failsafe_option(string option) {
  }
  //////////////////////////////////////////////////////////////////////

  void get_single_option(string option) {
    if (option == "slope") {
      double xcoor1, ycoor1, xcoor2, ycoor2;

      // Get the coordinate points from the user
      cout << "Enter coordinate point 1: ";
      cin >> xcoor1 >> ycoor1;

      cout << "Enter coordinate point 2: ";
      cin >> xcoor2 >> ycoor2;

      // Calculate the equation and so with two coordinate points
      coordinate(xcoor1, ycoor1, xcoor2, ycoor2);

      // Return to the prompt (for single prompt)
      single_prompt();
    }

    else {
      cerr << option << " is not a command.\n";
    }
  }

  void get_option(vector<string> option) {

  }
}
