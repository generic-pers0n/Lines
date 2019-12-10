#include <iostream>
#include <string>
#include <cstdlib>
#ifndef CMDLINE_H
#define CMDLINE_H
#endif
using namespace std;

class CmdLineError {
  void fatal_error(string err_msg, int exit_status = -1) {
    cout << "\x1B[41mThe program has encountered a fatal error. It cannot continue.\0[0m";

    if (err_msg == "") {
      exit(exit_status);
    }

    cout << "Error message: " << err_msg << endl;
    exit(exit_status);
  0}

  void warning(string err_msg) {
    cout << "\x1B[30;43mWarning - " << err_msg << "\0[0m" << endl;
  }
};

