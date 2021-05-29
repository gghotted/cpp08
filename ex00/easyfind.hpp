#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

template<typename T>
typename T::iterator easyfind(T& iterable, int target)
{
  return std::find(iterable.begin(), iterable.end(), target);
}

#endif // EASYFIND_HPP
