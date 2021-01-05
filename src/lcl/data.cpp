#include "data.hpp"
#include <iostream>
#include <string>
#include <algorithm>

// C Headers
#include <cstdlib>
#include <cstring>

// Internal functions
void __alloc(std::size_t __alloc_size = SIZE)
{
  try
  {
    __data = new char[__alloc_size];
    __dat_size = __alloc_size;
  } catch (...)
  {
    __data = nullptr;
  }

}

// Constructors
data::data()
{
  __alloc();
}

explicit data::data(std::size_t alt_size)
{
  __alloc(alt_size);
}

data::data(unsigned long long data)
{
  std::string _tmp_str = std::to_string(data);
  char* _tmp_buff = _tmp_str.data();

  if (__data == nullptr)
  {
    __alloc();
  }

  if (__data != nullptr)
  {
    std::copy(_tmp_buff, _tmp_buff+_tmp_str.size(), __data);
  }
}

// Destructors
data::~data()
{
  if (__data != nullptr)
  {
    delete[] __data;
  }
}

// Functions
template<class Type>
void add(Type elmnt)
{
  
}

template<class Type>
void add(Type* elmnt, std::size_t src_size)
{
  if (src_size > __dat_size)
  {
    __alloc(src_size + __dat_size);
  }

  if (__data != nullptr)
  {
    std::copy_n(elmnt, src_size, __data);
  }
}
