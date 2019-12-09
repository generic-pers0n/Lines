#include "cmd-line.hpp"

void action(int argc, string str_argv, string option_list) {
  char *argv = str_argv.c_str();
  int opt_val;

  while ((opt_val = getopt(argc, argv, option_list.c_str())) != -1) {
    switch (opt_val) {
      case 'slope':
        cout << "slope\n";
    }
  }
}

void prompt() {
  // Command values
  string option;
  string option_list = "slopeclassictest";
  cout << ">> ";

  cin >> option;

  if (option == "") {
    prompt();
  }

  option(option)
}

