#ifndef EASYFIND_H
# define EASYFIND_H

# include <algorithm>
# include "Colours.hpp"

template <typename T>
typename T::const_iterator easyfind(T &arr, int n)
{
	typename T::const_iterator iter = find(arr.begin(), arr.end(), n);
	if (arr.begin() == arr.end()) {
		throw std::overflow_error("Array is empty");
	}
	else if (iter == arr.end()) {
		throw std::overflow_error("Vallue not found");
	}
	else {
		return iter;
	}
}

#endif
