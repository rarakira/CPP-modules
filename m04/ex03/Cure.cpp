#ifndef CURE_H
# define CURE_H

# include <iostream>

# include "Colours.hpp"
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure: public AMateria
{
	public:
		Cure();
		Cure(const Cure &src);
		virtual ~Cure();

		Cure &operator=(const Cure &newValue);
		
		virtual AMateria	*clone() const;
		virtual void		use(ICharacter &target);
};

#endif