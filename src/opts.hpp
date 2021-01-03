/** @file opts.hpp
 *
 * Contains the definitions of all the functions in the Option Handling component
 * of Lines.
 *
 * @see opt_t
 **/
#ifndef LINES_OPTS
#define LINES_OPTS

#include <string>
#include <vector>

#ifdef DEBUG
  #define MAX_LCL_OPTS 8
#else
  #define MAX_LCL_OPTS 7
#endif

namespace lines {
namespace opts {

class opt_t
{
  private:
    std::string m_opt_name;
    std::vector<std::string> m_args;

  public:
    // Constructors
    opt_t(std::string name) : m_opt_name(name) {}
    opt_t() {}

    // Functions
    std::string get_name();
    void set_name(std::string new_name);
    std::vector<std::string> get_args();

    bool has_arg(std::string arg);
    bool has_args();
    bool has_args(std::vector<std::string> args);

    void set_args(std::vector<std::string> new_args);
    void add_arg(std::string new_arg);

    void clear(); //!< Clears everything in this option.
};

// Classes/Structures/Custom Types
struct alias_t
{
  std::string alias;    //!< Alias name
  opt_t alias_to; //!< Option name that this is aliased to

  // Constructors
  alias_t(std::string new_alias) : alias(new_alias) {}
};

// External variables
//static std::vector<opt_t> lcl_aliases;

void mkalias(std::string new_alias, std::string alias_to);

} // namespace lines
} // namespace opts

#endif // end LINES_OPTS
