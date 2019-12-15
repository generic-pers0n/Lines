#include <iostream>
#include <string>
#include <fstream>
#include <bits/stdc++.h>
#define FAILESAFE 0 // false
using namespace std;

namespace Util {
  // Function declarations
  void failsafe(string prompt_type);

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
}

