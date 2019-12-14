#include <lines/lpapi.h>
#include <lines/util.h>

if (FAILSAFE == 1) {
  cout << "WARNING: You are in failsafe mode. Plugin do not work in failsafe mode\n";
}

void load(string plugin) { // Load plugin
  string plugin_path_full = "/lib64/lines-plugins/" + plugin;
  void *plugin = dlopen(plugin_path_full.c_str(), RTLD_NOW);

  if (!plugin) {
    cout << "Failed to load plugin: " << plugin << endl;
  }
}

