#ifndef ICE_H
# define ICE_H

# include <iostream>

# include "Colours.hpp"
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice: public AMateria
{
	public:
		Ice();
		Ice(const Ice &src);
		virtual ~Ice();

		Ice &operator=(const Ice &newValue);
		
		virtual AMateria	*clone() const;
		virtual void		use(ICharacter &target);
};

#endif