#include "lcl_values.hpp"
#include <algorithm>
#include <stdexcept>

/** Determines if a string is a valid value
 * This function determines if a string contains a valid value.
 * Nothing special is done ere, as we just check for several
 * different values.
 * 
 * There are several possible valid values:
 * 
 *   * An int (lcl_values::INT)
 *   * A float (or double, lcl_values::FLOAT)
 *   * A boolean (lcl_values::BOOL)
 *   * A string (lcl_values::STRING)
 * 
 * All of these values are represented via the enum class
 * 'lcl_values'. In addition to the list of possible values
 * (listed above), next to the possible values are their representation
 * in the 'lcl_values' enum.
 *
 * The syntax rules that this function follows is pretty loose. All
 * whitespaces are removed from the string first before anything else
 * happens. Therefore, an expression like 't     r    u                       e'
 * will be interpreted as 'true' and thus evaluate to a valid value.
 * (But do you really want to write that? Seriously, it's really unreadable).
 *
 * @return True if the contained value is valid. False otherwise.
 **/
bool is_valid_value(std::string str)
{
  // Erase any whitespaces
  std::size_t wspace = str.find(' ');
  std::size_t previous_wspace = 0;
  while ((wspace = str.find(' ')) != std::string::npos)
  {
    str.erase(previous_wspace, wspace);
    previous_wspace = wspace;
  }

  // Is the value a boolean?
  //
  // No, 'True', 'False', or anything not 'true' or 'false (no pun intended)
  // is considered valid for booleans. This is in addition to the documentation
  // for this function provided above.
  if (str == "true" || str == "false")
  {
    return true;
  }

  // Is the value a float?
  std::size_t decimal = str.find('.');
  if (decimal != std::string:npos)
  {
    return true;
  }

  // Is the value an integer?
  bool no_except;

  int _num;
  try
  {
    _num = std::stoi(_num);
  } catch(std::invalid_argument& err)
  {
    no_except = false;
  }

  // Is the value a string?
  std::size_t dquote1 = str.find('\"'),
	      dquote2 = str.find('\"');

  if (dquote1 == std::string::npos
      || dquote2 == std::string::npos)
  {
    return false;
  } else if (dquote1 == std::string::npos
             && dquote2 == std::string::pos)
  {
    return false;
  } else
  {
    return true;
  }
}

/** Determines the value contained in a string
 * 
 * This function determines if a value contained in a string
 * is valid. This is done so by determining if this is a valid
 * value. Once that's done, the value contained in the string
 * is then determined.
 * 
 * This function only throws an exception if is_valid_value()
 * returns false. Otherwise, this function does not throw an
 * exception.
 * 
 * @return The appropriate lcl_value enum member (STRING, INT) or
 * lcl_value::UNDEFINED if unknown.
 * 
 * @see is_valid_value
 **/
lcl_values determine_value(std::string& str)
{
  if (!is_valid_value(str))
  {
    throw std::invalid_argument("Invalid syntax");
  }
}

