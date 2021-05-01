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

namespace lines {
namespace opts {

class opt_t
{
  private:
    std::string m_opt_name;
    std::vector<std::string> m_args;

  public:
    // Functions
    std::string get_name() const;
    void set_name(std::string& new_name);
    std::vector<std::string> get_args() const;

    bool has_arg(std::string& arg) const;
    bool has_args() const;
    bool has_args(std::vector<std::string>& args) const;

    void set_args(std::vector<std::string>& new_args);
    void add_arg(std::string& new_arg);

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

} // namespace lines
} // namespace opts

#endif // end LINES_OPTS
