#include <iostream>
#include <string>
#include <unistd.h>
#include <cstdlib>
using namespace std;

class CmdLineError {
  int exit(int status) {
    return status;
  }

  void fatal_error(string err_msg) {
    cout << "The program has encountered a fatal error. It cannot continue";

    if (err_msg == "") {
      exit(0);
    }

    cout << "Error message: " << err_msg << endl;
    exit(0);
  }
};

