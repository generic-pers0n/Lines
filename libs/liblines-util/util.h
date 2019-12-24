#ifndef UTIL_H
#define UTIL_H // util.h

#include <iostream>
#include <string>
#include <fstream>
#include <bits/stdc++.h>
#include <boost/algorithm/string.hpp>
#define FAILSAFE false
using namespace std;

namespace Util {
  // Function declarations (internal only)
  void get_failsafe_option(vector<string> option);
  void get_option(vector<string> option);

  vector<string> prompt() {
    vector<string> commands;
    string input;

    cout << ">> ";
    getline(cin, input);

    // Split the input and save it into 'commands'
    boost::split(commands, input, boost::is_any_of(" "));
    return commands;
  }

  void failsafe(string error) {
    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
    cout << "!! Lines has entered failsafe mode      !!\n";
    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";

    cout << "A problem occured and Lines has entered failsafe\n";
    cout << "mode. Lines will have limited functionality when in\n";
    cout << "failsafe mode.\n\n";

    cout << "In this mode, normal functionality is disabled. You can\n";
    cout << "try to continue into normal mode, but after 5 tries, that\n";
    cout << "option will be disabled. For more information, please visit\n";
    cout << "the Lines wiki.\n\n";

    if (error != "") {
      cout << "Some error information was provided:\n";
      cout << error;
    }

    else {
      cout << "No error information was provided\n";
    }

    // Launch a prompt
    vector<string> answer = prompt();
    get_failsafe_option(answer);
  }
}

#endif // end util.h
