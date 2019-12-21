#include <iostream>
#include <string>
#include <fstream>
#include <bits/stdc++.h>
#define FAILSAFE false
using namespace std;

namespace Util {
  // Function declarations (internal only)
  void get_failsafe_option_single(string option);
  void get_failsafe_option(vector<string> option);

  vector<string> prompt() {
    vector<string> commands;
    string input;

    cout << ">> ";
    getline(cin, input);

    return commands;
  }

  string single_prompt() {
    string command;

    cout << ">> ";
    cin >> command;
    return command;
  }

  void failsafe(string prompt_type) {
    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
    cout << "!! Lines has entered failsafe mode      !!\n";
    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";

    cout << "A problem occured and Lines has entered failsafe\n";
    cout << "mode. Lines will have limited functionality in this\n";
    cout << "mode.\n\n";

    cout << "In this mode, normal functionality is disabled. You can\n";
    cout << "try to continue into normal mode, but after 5 tries, that\n";
    cout << "option will be disabled. For more information, please visit\n";
    cout << "the Lines wiki.\n\n";

    if (prompt_type == "single") {
      string answer = single_prompt();
      get_failsafe_option_single(answer);
    }

    else if (prompt_type == "default") {
      vector<string> answer = prompt();
      get_failsafe_option(answer);
    }
  }
}

