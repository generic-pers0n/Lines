/** @file data.hpp
 * 
 * Definition for data type 'data'
 * 
 * This data type is similar to a std::string, except 1) it is mean to be
 * simpler than std::string and 2) it is designed to hold various other
 * data types in a (C-style) string.
 * 
 **/
#ifndef LCL_DATA_TYPE
#define LCL_DATA_TYPE

#include <string>
#include "values.hpp"

namespace lcl {

constexpr std::size_t SIZE = 64; // In bytes

/** Data type for holding an object's data.
 * 
 * This data type is similar to a string as it actually reimplements a std::string. However,
 * you will find a few differences and the fact that this is oriented to containing multiple
 * types in a single string in addition to being a simple string. You can interface with
 * std::string as well, including if it was a regular string.
 * 
 * In addition to acting like a string, this data type can hold a single element
 * 
 **/
class data
{
  private:
    char* __data = nullptr;
    lcl::lcl_value __value_type;
    std::size_t __dat_size;

    /** Allocates the internal array to the default size.
     * 
     * This function is an internal function that allocates the internal array to a
     * specified size. This size, by default, is equal to SIZE which is 64 bytes.
     *
     * @param __alloc_size The size to allocate the internal array. If this is <= 1,
     * then only a single element is allocated.
     * 
     **/
    void __alloc(std::size_t __alloc_size = SIZE);

  public:
    // Constructors
    data();                              // Does nothing
    explicit data(std::size_t alt_size); // Use a different size rather than the default
    data(long long data);                // For ints
    data(unsigned long long data);       // For unsigned long long
    data(long double data);              // For floats (long doubles)
    data(char* data);                    // For C-style strings (excluding size)
    data(car* data, std::size_t size);   // For C-style strings (including size)
    data(std::string& data);             // For strings

    // Destructors
    ~data();

    // Functions
    /** Adds an element to the internal buffer
     * 
     * This function adds a single element to the internal buffer of this object.
     * There are various overloads for the various data types you can add, and these
     * include POD-types along with std::string. 
     *
     * @return Nothing is returned for these functions.
     *
     **/
    void add(llong elmnt);      // For long long
    void add(ullong elmnt);     // Unsigned version
    void add(char elmnt);       // For char
    void add(uchar elmnt);      // Unsigned version
    void add(std::string str);  // For std::string

    /** Adds elements to the internal buffer
     * 
     * These are the same as the other add functions (the ones that add a single element),
     * except that these functions can add either a POD-type array or a std::vector (of
     * whichever type).
     * 
     * These funcitons do not throw any exceptions.
     *
     * @return Nothing is returned for these functions.
     * 
     **/
    template<class Type>
    void add(Type* data, std::size_t src_size); // Adds an element (an array of sorts)

    template<class Type>
    void add(std::vector<Type> data); // 

    /** Removes an element from a specified index
     * 
     * This function removes an element from a specified index. If the index is out
     * of range, then an exception is thrown.
     * 
     * The second definition removes a range of elements. If either range is invalid,
     * then an exception is thrown. If 'begin' and 'end' are the same, then the behavior
     * is the exact same as remove with only one index. If begin > end, an exception is
     * thrown (invalid range).
     * 
     * @param in The index to remove the element from. Must be valid
     * @param begin The beginning index to where the range should start. Must be valid
     * @param end The ending index to where the range should end. If end equals 0, then
     * everything until the end of the array is removed (same as clear).
     * 
     **/
    void remove(std::size_t in = 0);
    void remove(std::size_t begin = 0, std::size_t end = 0);

    /** Returns the current size of the internal array.
     *
     * This functoin returns the size of the internal array. Note that the returned value
     * does not reflect the current number of elements. 
     *
     * This function never throws an exception
     * 
     * @return The size of the object's internal array.
     **/
    std::size_t size() const noexcept; // Returns the current size of the object
};

} // namespace lcl
#endif // end LCL_DATA_TYPE
