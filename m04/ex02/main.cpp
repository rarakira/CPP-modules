#include <iostream>
#include <iomanip>

#include "AAnimal.hpp"
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

		std::cout << "Cat 1 says: ";
		cat1->makeSound();
		cat1->getBrain()->setThought(0, "I love Tuna!");
		std::cout << "Cat 1 thinks: \"" << cat1->getBrain()->getThought(0) << "\"" << std::endl;
		
		const AAnimal*		cat2 = new Cat(*cat1);
		std::cout << "Cat 2 says: ";
		cat2->makeSound();
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
		const AAnimal*		animal[n];
		AAnimal*				catPtr;
		
		for (size_t i = 0; i < n; i++)
		{
			if (i % 2)
				animal[i] = new Cat();
			else
				animal[i] = new Dog();
			std::cout << "Animal [" << i << "] CREATED : " << animal[i]->getType() << std::endl;
			animal[i]->makeSound();
		}
		animal[3]->getBrain()->setThought(0, "I love Tuna!");
		std::cout << "Cat [3] thinks: \"" << animal[3]->getBrain()->getThought(0) << "\"" << std::endl;
		std::cout << "Copying the [3] cat" << std::endl;
		catPtr = (Cat*)animal[3];
		catPtr->makeSound();
		catPtr->getBrain()->setThought(0, "I love Anchovies!");
		std::cout << "Copied Cat thinks: \"" << catPtr->getBrain()->getThought(0) << "\"" << std::endl;
		std::cout << "Cat [3] thinks: \"" << animal[3]->getBrain()->getThought(0) << "\"" << std::endl;
		for (size_t i = 0; i < n; i++)
		{
			std::cout << "Animal [" << i << "] : " << animal[i]->getType() << std::endl;
			delete animal[i];
		}
	}
	{
		print_status("--- TEST 3 ");
		Cat		cat1;
		cat1.getBrain()->setThought(0, "I love Anchovies!");
		Cat		cat2 = cat1;
		std::cout << "Copied Cat thinks: \"" << cat2.getBrain()->getThought(0) << "\"" << std::endl;
		cat1.getBrain()->setThought(0, "I love scratching sofa!");
		std::cout << "Copied Cat thinks: \"" << cat2.getBrain()->getThought(0) << "\"" << std::endl;
		std::cout << "First Cat thinks: \"" << cat1.getBrain()->getThought(0) << "\"" << std::endl;

	}
	return 0;
}
