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
		const Animal*		meta = new Animal();
		const Animal*		j = new Dog();
		const Animal*		i = new Cat();

		std::cout << i->getType() << ": ";
		i->makeSound();
		std::cout << j->getType() << ": ";
		j->makeSound();
		std::cout << meta->getType() << ": ";
		meta->makeSound();
		delete meta;
		delete i;
		delete j;
	}
	{
		print_status("--- TEST 2 ");
		const Animal*		animal = new Animal();
		const Animal*		cat = new Cat();
		const Cat*			catCat = new Cat();

		std::cout << animal->getType() << ": ";
		animal->makeSound();
		std::cout << cat->getType() << ": ";
		cat->makeSound();
		std::cout << catCat->getType() << ": ";
		catCat->makeSound();
		delete animal;
		delete cat;
		delete catCat;
	}
	{
		print_status("--- TEST 3 ");
		const WrongAnimal*		animal = new WrongAnimal();
		const WrongAnimal*		cat = new WrongCat();
		const WrongCat*			catCat = new WrongCat();

		std::cout << animal->getType() << ": ";
		animal->makeSound();
		std::cout << cat->getType() << ": ";
		cat->makeSound();
		std::cout << catCat->getType() << ": ";
		catCat->makeSound();
		delete animal;
		delete cat;
		delete catCat;
	}
	return 0;
}
