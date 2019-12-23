#include <lines/plugin.h>
#include <lines/util.h>

if (FAILSAFE == 1) {
  cout << "WARNING: You are in failsafe mode. Plugins don\'t work in failsafe mode.\n";
}

// Load plugin function (internal only)
//
// Plugins will not be able to load other plugins. Only Lines will
// be able to do that. This is made 'static' for the sole purposes
// of interoperability of Lines.
static void load(string plugin) {
  string plugin_path_full = "/lib64/lines-plugins/" + plugin;
  void *plugin = dlopen(plugin_path_full.c_str(), RTLD_NOW);

  if (!plugin) {
    cout << "Failed to load plugin: " << plugin << endl;
  }
}

