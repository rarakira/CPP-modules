#include "Span.hpp"

Span::Span(): _max(0) {
	std::cout	<< COLOUR_NEW
				<< "Span default constructor called"
				<< COLOUR_FIN
				<< std::endl;
}

Span::Span(unsigned int const & max): _max(max) {
	std::cout	<< COLOUR_NEW
				<< "Span constructor called"
				<< COLOUR_FIN
				<< std::endl;
}

Span::Span(Span const & src): _max(src._max) {
	this->_arr = src._arr;
	std::cout	<< COLOUR_NEW
				<< "Span copy constructor called"
				<< COLOUR_FIN
				<< std::endl;
}

Span & Span::operator=(Span const & rhs) {
	this->_max = rhs._max;
	this->_arr = rhs._arr;
	std::cout	<< COLOUR_NEW
				<< "Assignation operator called"
				<< COLOUR_FIN
				<< std::endl;
	return *this;
}

Span::~Span() {
	// this->_arr.clear();
	std::cout	<< COLOUR_DELETE
				<< "Span destructor called"
				<< COLOUR_FIN
				<< std::endl;
}

unsigned int Span::getCurrentSize(void) const {
	return this->_arr.size();
}

void Span::addNumber(int num) {
	if (this->_arr.size() == this->_max) {
		throw std::overflow_error("The span is full");
	}
	else {
		this->_arr.push_back(num);
		std::cout << "| " << num << " is added to the span" << std::endl;
	}
}

void Span::addRange(std::vector<int>::iterator a, std::vector<int>::iterator z) {
	unsigned int	num = std::distance(a, z);

	if (this->_max < num) {
		throw std::overflow_error("Not enough space to insert the range");
	}
	copy(a, z, std::back_inserter(this->_arr));
}

int	Span::shortestSpan() const
{
	std::vector<int>	tmp = this->_arr;
	int					result;

	if (this->_arr.size() < 2) {
		throw std::logic_error("The span has less than 2 elements");
	}
	sort(tmp.begin(), tmp.end());
	result = *(tmp.begin() + 1) - *tmp.begin();
	std::vector<int>::iterator	iter = tmp.begin() + 1;
	std::vector<int>::iterator	last = tmp.end() - 1;
	while (iter != last && result != 0) {
		if (*(iter + 1) - *iter < result) {
			result = *(iter + 1) - *iter;
		}
		iter++;
	}
	return result;
}

int	Span::longestSpan() const
{
	std::vector<int>::const_iterator min = std::min_element(this->_arr.begin(), this->_arr.end());
	std::vector<int>::const_iterator max = std::max_element(this->_arr.begin(), this->_arr.end());

	if (this->_arr.size() < 2) {
		throw std::logic_error("The span has less than 2 elements");
	}
	return (*max - *min);
}

std::vector<int>::iterator	Span::begin(void)
{
	return this->_arr.begin();
}

std::vector<int>::iterator	Span::end(void)
{
	return this->_arr.end();
}

std::ostream	&operator<<(std::ostream &out, Span &elem)
{
	if (elem.getCurrentSize() == 0)
		return out;
	std::vector<int>::iterator	current = elem.begin();
	std::vector<int>::iterator	fin = elem.end();

	while (current != fin) {
		out << "| " << *current << std::endl;
		current++;
	}
	return out;
}
