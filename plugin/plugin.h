/* Lines Plugin API (LPAPI)
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

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <dlfcn.h>
#include <lines/util.h>
using namespace std;

#ifdef _WIN32
#error "The Lines Plugin Framework does not work on Windows"
#endif

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

    // Whenever this function fails (if NULL), then Lines will go into
    // a failsafe mode. First, the function will make sure Lines is not
    // in a failsafe mode. If that's true, then allocate() will not work.
    if (data == NULL) {
        cout << "Error: Failed to allocate RAM";
        Lines::failsafe("Error: Failed to deallocate RAM"); // Enter a failsafe mode
    }

    return data; // Return memory location
  }

  void *deallocate(void *ptr) {
    if (!ptr) {
        cout << "Error: Could not deallocate RAM\n";
        Lines::failsafe(); // Enter a failsafe mode
    }

    free(ptr); // Free allocated space
  }

  // Unload a plugin
  void unload(void *plugin) {
    dlclose(plugin);

    if (error != NULL) {
      cout << "Error: " << error << endl;
    }
  }
}

#endif // end lpapi.h
