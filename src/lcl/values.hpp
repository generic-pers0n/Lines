#ifndef LCL_VALUES
#define LCL_VALUES

#include <string>

namespace lines {

enum class lcl_value
{
  INT,      // Integers 
  FLOAT,    // Floats (including doubles)
  BOOL,     // Booleans
  STRING,   // Strings
  UNDEFINED // Any undefined values
};

namespace lcl { 

bool is_valid_value(std::string& str);
lcl_values determine_value(std::string& str);

} // namespace lcl
} // namespace lines
#endif // end LCL_VALUES

