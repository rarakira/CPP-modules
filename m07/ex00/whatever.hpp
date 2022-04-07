#ifndef WHATEVER_H
#define WHATEVER_H

/*
swap:	Swaps the values of two given arguments. Does not return anything.

min:	Compares the two values passed in its arguments and returns the smallest one.
		If the two of them are equal, then it returns the second one.

max:	Compares the two values passed in its arguments and returns the greatest one.
		If the two of them are equal, then it returns the second one.
*/

template<typename T>
void swap(T & lhs, T & rhs) {
	T	tmp = lhs;
	lhs = rhs;
	rhs = tmp;
}

template<typename T>
T const & min(T const & lhs, T const & rhs) {
	return (lhs < rhs ? lhs : rhs);
}

template<typename T>
T const & max(T const & lhs, T const & rhs) {
	return (lhs > rhs ? lhs : rhs);
}

#endif
