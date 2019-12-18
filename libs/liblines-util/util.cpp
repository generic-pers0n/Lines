#include <boost/algorithm/string.hpp>
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

  void failsafe() {
    #undef FAILSAFE
    #define FAILSAFE true

    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
    cout << "!! Lines has entered failsafe mode       !!\n";
    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n";

    cout << "Failsafe mode is a special kind of mode that Lines enters when there\'s\'\n";
    cout << "something wrong. Many things can cause Lines to go into failsafe mode.\n\n";

    cout << "In failsafe mode, normal functionality is disabled. You only have basic\n";
    cout << "functionality. All plugins are unloaded unless there was an error doing\n";
    cout << "so. Plugin functionality is also limited.\n\n";

    cout << "For a list of commands, type \'help\'. Note that no normal command will be\n";
    cout << "available during this time.\n\n";

    single_prompt();
  }
}
