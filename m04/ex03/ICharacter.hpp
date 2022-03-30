#ifndef ICHARACRER_H
# define ICHARACRER_H

# include <iostream>
# include "Colours.hpp"
# include "AMateria.hpp"

# define COLOUR_BBLUE	"\033[0;38;5;80m"
# define COLOUR_YELL	"\033[0;38;5;220m"
# define COLOUR_VIOL	"\033[0;38;5;135m"
# define COLOUR_ORG		"\033[0;38;5;209m"
# define COLOUR_NEW		"\033[0;38;5;42m"
# define COLOUR_DELETE	"\033[0;38;5;203m"
# define COLOUR_FIN		"\033[0m"

class AMateria;

class ICharacter
{
	public:
		virtual ~ICharacter() {}

		virtual const std::string &getName() const = 0;
		virtual void equip(AMateria *m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter &target) = 0;
};

#endif