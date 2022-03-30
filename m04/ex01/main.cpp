#include <iostream>
#include <iomanip>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void print_status( std::string const msg)
{
	std::cout	<< std::endl
				<< std::left << std::setw(40) << std::setfill('-')
				<< msg << std::endl;
}

int main( void )
{
	{
		print_status("--- TEST 1 ");
		const Cat*			cat1 = new Cat();

		cat1->getBrain()->setThought(0, "I love Tuna!");
		std::cout << "Cat 1 thinks: \"" << cat1->getBrain()->getThought(0) << "\"" << std::endl;
		
		const Animal*		cat2 = new Cat(*cat1);
		std::cout << "Cat 2 thinks: \"" << cat2->getBrain()->getThought(0) << "\"" << std::endl;
		cat2->getBrain()->setThought(0, "I love Shrimps!");
		std::cout << "Cat 2 thinks: \"" << cat2->getBrain()->getThought(0) << "\"" << std::endl;
		std::cout << "Cat 1 thinks: \"" << cat1->getBrain()->getThought(0) << "\"" << std::endl;

		delete cat1;
		delete cat2;
	}
	{
		print_status("--- TEST 2 ");
		size_t				n = 6;
		const Animal*		animal[n];

		for (size_t i = 0; i < n; i++)
		{
			if (i % 2)
				animal[i] = new Cat();
			else
				animal[i] = new Dog();
			std::cout << "Animal [" << i << "] CREATED : " << animal[i]->getType() << std::endl;
		}

		for (size_t i = 0; i < n; i++)
		{
			std::cout << "Animal [" << i << "] : " << animal[i]->getType() << std::endl;
			delete animal[i];
		}
	}
	return 0;
}
