#include <iostream>
#include <iomanip>
#include "Array.hpp"

void print_status(std::string const msg) {
	std::cout	<< std::endl
				<< std::left << std::setw(40) << std::setfill('-')
				<< msg << std::endl;
}

#define MAX_VAL 750
int main(int, char**)
{
	{
		print_status("--- Subject tests ");
		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		//SCOPE
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		try
		{
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}
		delete [] mirror;//
	}
	{
		print_status("--- My tests ");
		Array<int>				nums(5);
		Array<std::string>		cities1(5);
		Array<std::string>		cities2(5);

		int						vals[] = {1, 2, 3, 4, 5};
		std::string				citiesUk[] = {"London", "Liverpool", "Manchester", "Sheffield", "Bristol"};
		std::string				citiesSpain[] = {"Madrid", "Valencia", "Cordoba", "Sevilla", "Barcelona"};

		print_status("--- Check cities1 ");
		for (unsigned int i = 0; i < cities1.size(); i++) {
			std::cout << "cities1[" << i << "] = " << cities1[i] << std::endl;
		}

		print_status("--- Set values for cities 1 and nums ");
		for (unsigned int i = 0; i < cities1.size(); i++) {
			cities1[i] = citiesUk[i];
			nums[i] = vals[i];
			std::cout << "cities1[" << i << "] = " << cities1[i] << std::endl;
		}
		print_status("--- Copy cities1 to cities2 ");
		cities2 = cities1;

		print_status("--- Update values for cities2 ");
		for (unsigned int i = 0; i < cities2.size(); i++) {
			cities2[i] = citiesSpain[i];
			std::cout << "cities1[" << i << "] = " << cities2[i] << std::endl;
		}

		print_status("--- Check cities1 ");
		for (unsigned int i = 0; i < cities1.size(); i++) {
			std::cout << "cities1[" << i << "] = " << cities1[i] << std::endl;
		}
		print_status("--- Check out of bounds ");
		try {
			std::cout << "nums size is " << nums.size() << std::endl;
			std::cout << "nums[5] is " << nums[5] << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
		try {
			std::cout << "nums[-1] is " << nums[-1] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return 0;
}
