#ifndef LCL_VALUES
#define LCL_VALUES

#include <string>

namespace lcl {

// Types
typedef long double ldouble;

enum class lcl_value
{
  INT,      // Integers 
  FLOAT,    // Floats (including doubles)
  BOOL,     // Booleans
  STRING,   // Strings
  UNDEFINED // Any undefined values
};

bool is_valid_value(std::string& str);
lcl_values determine_value(std::string& str);

} // namespace lcl
} // namespace lines
#endif // end LCL_VALUES

