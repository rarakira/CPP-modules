#ifndef ARRAY_H
# define ARRAY_H

# include <iostream>
# include "Colours.hpp"

template <typename T>
class Array {
private:
	unsigned int		_size;
	T *					_arr;
public:
	Array<T>();
	Array<T>(unsigned int size);
	Array<T>(Array<T> const & src);
	Array<T> & operator=(Array<T> const & rhs);
	~Array<T>();

	T & operator[](const unsigned int index) const;
	unsigned int size() const;
};

#endif
