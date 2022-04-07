#ifndef SPAN_H
# define SPAN_H

# include <iostream>
# include <vector>
# include "Colours.hpp"

class Span
{
private:
	unsigned int		_max;
	std::vector<int>	_arr;

	Span();

public:
	Span(unsigned int const & max);
	Span(Span const & src);
	Span & operator=(Span const & rhs);
	~Span();

	unsigned int getCurrentSize(void) const;
	void addNumber(int num);
	void addRange(std::vector<int>::iterator a, std::vector<int>::iterator z);
	int shortestSpan() const;
	int longestSpan() const;

	std::vector<int>::iterator	begin(void);
	std::vector<int>::iterator	end(void);
};

std::ostream	&operator<<(std::ostream &out, Span &inst);

#endif
