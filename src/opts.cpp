/** @file opts.cpp
 *
 * Contains the implementation of things defined in opts.hpp
 **/

#include "opts.hpp"
#include <iostream>
#include <algorithm>
#include <cassert>

/** \namespace lines
 *
 * A group of namespaces for the internal components of Lines. All other components
 * of Lines have their own namespace under this whole namespace. Anything that is
 * under this namespace that isn't another namespace is used for the core of Lines.
 *
 * @see lines.hpp
 * @see lines.cpp
 * 
 **/
namespace lines {

/** \namespace opts
 *
 * The namespace for the Option Handling component of Lines.
 *
 * This namespace mainly contains various things related to handling options
 * on the LCL. This does not have any other dependency on any other component
 * of Lines, as is the requirement for all components of Lines
 *
 * Note that the LCL consists of various other components and is not one
 * component of itself.
 *
 * Also note: currently, no functions for handling any actuall options in Lines.
 * are available. The main LCL options are currently hard-coded into Lines, but
 * maybe sometime into the future they will become dynamic...
 *
 * @see opts.hpp
 * @see opts.cpp
 */
namespace opts {

std::vector<alias_t> lcl_aliases; //!< A vector to store any aliases in the LCL. This vector does NOT contain any unaliased options in Lines!

////////////////////////////////////////////////////////
// opt_t member functions                             //
////////////////////////////////////////////////////////

std::string opt_t::get_name() const
{
  return m_opt_name;
}

void opt_t::set_name(std::string new_name)
{
  m_opt_name = new_name;
}

std::vector<std::string> opt_t::get_args() const
{
  return m_args;
}

bool opt_t::has_arg(std::string arg) const
{
  return (std::find(m_args.begin(), m_args.end(), arg) != m_args.end()) ? true : false;
}

bool opt_t::has_args() const
{
  return (m_args.size() != 0) ? true : false;
}

bool opt_t::has_args(std::vector<std::string> args) const
{
  auto it = m_args.begin();

  for (size_t i = 0; args[i] != *it; i++)
  {
    if (it == m_args.end())
    {
      return false;
    }
  }

  return true;
}

void opt_t::set_args(std::vector<std::string> new_args)
{
  m_args = new_args;
}

void opt_t::add_arg(std::string new_arg)
{
  m_args.push_back(new_arg);
}

void opt_t::clear()
{
  m_args.clear();
  m_opt_name.clear();
}

} // namespace opts
} // namespace lines

