#include <iostream>
#include <string>
#include <unistd.h>
#include <cstdlib>
#ifndef CMDLINE_H
#define CMDLINE_H
#endif
using namespace std;

class CmdLineError {
  void fatal_error(string err_msg, int exit_status = -1) {
    cout << "The program has encountered a fatal error. It cannot continue";

    if (err_msg == "") {
      exit(exit_status);
    }

    cout << "Error message: " << err_msg << endl;
    exit(exit_status);
  }
};

