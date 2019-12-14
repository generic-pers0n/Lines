/* Lines Plugin API (LPAPI)
 *
 * <insert copyright message here>
 *
 **/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <dlfcn.h>
#include <lines/util.h>
using namespace std;

#ifndef LPAPI_H
#define LPAPI_H

// Global variables
ofstream file;

struct LpapiData {
  string api_ver = "v3.0";
  string lines_ver = "v3.0 dev";
};

namespace Plugin {
  void write(string data) {
    cout << "plugin: " << data;
  }

  string fwrite(string file, string data) {
    file.open(file);
    file << data;
    file.close();
    return file; // Return file location
  }

  void *allocate(size_t size) {
    void *data = malloc(size);

    // Whenever this function fails (if NULL), then Lines will go into
    // a failsafe mode. First, the function will make sure Lines is not
    // in a failsafe mode. If that's true, then allocate() will not work.
    //
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

  // unimplemented
  void unload();
}

#endif // end lpapi.h
