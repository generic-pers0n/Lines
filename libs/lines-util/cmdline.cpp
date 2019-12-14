#include "cmdline.hpp"

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

