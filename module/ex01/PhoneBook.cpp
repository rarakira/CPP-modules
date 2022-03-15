#include <iomanip>

#include "PhoneBook.hpp"

PhoneBook::PhoneBook( void )
{
	this->_count = 0;
	// std::cout << "PhoneBook created" << std::endl;
	return;
}

PhoneBook::~PhoneBook( void )
{
	// std::cout << "PhoneBook dectructor called" << std::endl;
	return;
}

void PhoneBook::add_contact( void )
{
	this->_book[_count % 8].set_values();
	this->_count += 1;
}

bool isNumber( std::string str)
{
	int		i = 0;

	while (str[i])
	{
		if (std::isdigit(str.at(i++)) == 0)
			return false;
	}
	return true;
}

void printColumn( const std::string value )
{
	std::string		pipe = "|";

	if (value.length() <= 10)
		std::cout << pipe << std::setw(10) << value;
	else
		std::cout <<pipe << value.substr(0,9) << ".";
}

int	PhoneBook::get_count( void )
{
	return this->_count;
}

void PhoneBook::search_contact( void )
{
	int				i = 0;
	std::string		input;
	std::string		separator = "+----------+----------+----------+----------+";
	std::string		pipe = "|";

	if (this->_count == 0)
	{
		std::cout << "The PhoneBook is empty." << std::endl;
		return ;
	}
	std::cout << separator << std::endl;
	std::cout << "| INDEX    | F.NAME   | L.NAME   | NICKNAME |" << std::endl;
	std::cout << separator << std::endl;

	while (i < this->_count && i < 8)
	{
		std::cout << std::left << pipe << std::setw(10) << (i + 1);
		printColumn(this->_book[i].get_first_name());
		printColumn(this->_book[i].get_last_name());
		printColumn(this->_book[i].get_nickname());
		std::cout << pipe << std::endl;
		i++;
	}
	std::cout << separator << std::endl;
	std::cout << "Please, enter index number: ";
	std::getline(std::cin, input);
	if (isNumber(input) == false)
	{
		std::cout	<< "The number should be from 1 to ";
		if (get_count() < 8)
			std::cout << get_count() << std::endl;
		else
			std::cout << "8" << std::endl;
	}
	else
	{
		i = std::stoi(input) - 1;
		if (i >= 0 && i < get_count() && i < 8)
		{
			std::cout << separator << std::endl;
			std::cout	<< std::left
						<< std::setw(18) << "First name:" << this->_book[i].get_first_name() << std::endl
						<< std::setw(18) << "Last name:" << this->_book[i].get_last_name() << std::endl
						<< std::setw(18) << "Nickname:" << this->_book[i].get_nickname() << std::endl
						<< std::setw(18) << "Phone Number:" << this->_book[i].get_phone_number() << std::endl
						<< std::setw(18) << "Darkest Secret:" << this->_book[i].get_darkest_secret()
						<< std::endl;
			std::cout << separator << std::endl;
		}
		else
		{
			std::cout	<< "The number should be from 1 to ";
			if (get_count() < 8)
				std::cout << get_count();
			else
				std::cout << "8";
			std::cout << std::endl;
		}
	}
}
