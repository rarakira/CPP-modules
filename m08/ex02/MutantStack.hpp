#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H

# include <iostream>
# include <stack>
# include "Colours.hpp"

template <typename T>
class MutantStack: public std::stack<T> {
public:
	MutantStack<T>() {}
	MutantStack<T>(MutantStack<T> const & src): std::stack<T>(src) {}
	MutantStack<T> & operator=(MutantStack<T> const & rhs) {
		std::stack<T>::operator=(rhs);
		return *this;
	}
	~MutantStack<T>() {}

	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin() { return std::stack<int>::c.begin(); }
	iterator end() { return std::stack<int>::c.end(); }
};

#endif
