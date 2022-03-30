#ifndef Dog_H
# define CAT_H

# include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog( void );
		Dog( Dog const & src );
		Dog & operator=( Dog const & rhs );
		~Dog( void );

		virtual void makeSound( void ) const;
};

#endif