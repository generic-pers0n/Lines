#include <iostream>
#include <string>
#include <fstream>
#include <bits/stdc++.h>
#define FAILESAFE 0 // false
using namespace std;

namespace Util {
  vector<string> prompt() {
    vector<string> commands;
    string input;

    cout << ">> ";
    getline(cin, input);

    return option;
  }

  string single_prompt() {
    string option;

    cout << ">> ";
    cin >> option;

    return option;
  }

  void failsafe() {
    #undef FAILSAFE
    #define FAILSAFE 1 // true

    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
    cout << "!! Lines has entered failsafe mode       !!\n";
    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n";

    cout << "An error occured so serious that Lines cannot function normally. There\n";
    cout << "are numerous reasons why this happens.\n\n";

    cout << "In failsafe mode, normal functionality is disabled. You only have basic\n";
    cout << "functionality. All plugins are unloaded unless there was an error doing\n";
    cout << "so. Plugin functionality is also limited.\n\n";

    cout << "For a list of commands, type \'help\'. Note that no normal command will be\n";
    cout << "available during this time.\n\n";
  }
}

