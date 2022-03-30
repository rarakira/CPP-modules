#ifndef AMATERIASOURCE_H
# define AMATERIASOURCE_H

# include <iostream>
# include "Colours.hpp"

class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif