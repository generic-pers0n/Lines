/* Lines Plugin Manager
 *
 * Copyright (C) 2019 Avery King <avery98@pm.me>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 **/

#ifndef LPM
#define LPM

#include <iostream>
#include <string>
#include <cstdlib>
#include <dlfcn.h>
#ifdef __unix__ // unix API
#include <unistd.h>
#elif _WIN32 // windows API
// We won't be using anything regarding the Windows API,
// but we'll #include it for when the time comes for
// adding Windows compatibility
#include <windows.h>
#endif
#include <spawn.h>
using namespace std;

<<<<<<< HEAD
#ifndef LPAPI_H
#define LPAPI_H

// Global variables
ofstream file;
char *error = dlerror();

namespace Plugin {
  void write(string data) {
    cout << "plugin: " << data;
  }

  string fwrite(string file_path, string data) {
    file.open(file_path);
    file << data;
    file.close();
    return file_path; // Return file location
  }

  // Here I got some inspiration from the C library
  // functions 'malloc()' and 'free()'.
  void *allocate(size_t size) {
    void *data = malloc(size);
=======
class PluginInfo {
  public:
    PluginInfo(string n, string v) {
      // n is name, v is version
      if (n == "") { // When no name is provided
        name = "";
      }

      if (v == "") { // When no version is provided
        version = "";
      }
    }
>>>>>>> Rewrite everything

    void setName(string new_name) {
      name = new_name;
    }

    void setVer(string new_ver) {
      version = new_ver;
    }

    string getName() {
      return name;
    }

    string getVer() {
      return version;
    }

  private:
    string name;
    string version;
};

class Plugin {
  public:
    void getPluginInfo(PluginInfo pinfo) {
      plugin_name = pinfo.getName();
      plugin_version = pinfo.getVer();
    }

  private:
    string plugin_name;
    string plugin_version;
};

#endif // end plugin.h
