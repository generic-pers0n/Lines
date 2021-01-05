#ifndef LCL_OBJ
#define LCL_OBJ

#include <string>
#include "values.hpp"
#include "data.hpp"

namespace lcl {
namespace obj {

enum class lcl_obj_types
{
  Obj,    // Regular object
  VarObj, // Variable object
  FnObj,  // Function object
};

class lcl_obj
{
  private:
    lcl_obj_types __obj_type;
    lcl::data __data = nullptr;

  public:
    // Constructors
    lcl_obj();                  // Nothing

    lcl_obj(const int data);          // Ints
    lcl_obj(const ldouble data);      // Floats
    lcl_boj(const bool data);         // Data
    lcl_obj(std::string const& data); // Strings

    // Destructors
    ~lcl_obj();

    // Member functions
    void store_data(int data);
    void store_data(ldouble data);
    void store_data(const bool data);
    void store_data(std::string const& data)

    /** Allocates data for the internal buffer of the object
     * 
     * alloc() prepares the object by allocating the internal
     * buffer with actual memory. Unlike store_data(), however, no actual
     * data is allocated. This is useful if you want to pre-allocate any
     * data before you want to actually store data.
     * 
     * The second definition of this function allows you to allocate
     * a set amount of elements, provided the object type is a container
     * object. If you attempt to do this on any other type, then the size
     * is ignored and a single element is allocated instead (essentially
     * behaving the same as the first definition).
     * 
     * If the internal buffer is not null (!= nullptr), then no new data is
     * allocated. 
     * 
     * @param sz The number of bytes to reallocate. Ignored if either 0 or the
     * object's type is not a container object (an "array" in other words).
     * 
     * @return This function does not return.
     * @see realloc
     * 
     **/
    void alloc();
    void alloc(size_t sz);

    /** Reallocates data in the object's internal buffer
     * 
     * This function reallocates the internal buffer to 'new_size' number of
     * bytes. If new_size is 0, then 
     * 
     **/
    void realloc(size_t new_size = 0);
};

} // namespace obj
} // namespace lcl

#endif // end LCL_OBJ
