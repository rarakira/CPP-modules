#include "Animal.hpp"
#include "Brain.hpp"

Brain::Brain( void )
{
	std::cout	<< COLOUR_NEW
				<< "Brain DEFAULT constructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

Brain::Brain( Brain const & src )
{
	for (size_t i = 0; i < 100; i++)
		this->setThought(i, src.getThought(i));
	std::cout	<< COLOUR_NEW
				<< "Brain COPY constructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

Brain & Brain::operator=( Brain const & rhs )
{
	// this->_type = rhs.getType();
	return *this;
}

Brain::~Brain( void )
{
	std::cout	<< COLOUR_DELETE
				<< "Brain destructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

std::string Brain::getThought( size_t n ) const
{
	return this->_ideas[n];
}

void Brain::setThought( size_t n, std::string thought )
{
	this->_ideas[n] = thought;
}
