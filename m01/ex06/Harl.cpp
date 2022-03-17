#include "Harl.hpp"

Harl::Harl( void )
{
	this->_mood[0] = &Harl::debug;
	this->_mood[1] = &Harl::info;
	this->_mood[2] = &Harl::warning;
	this->_mood[3] = &Harl::error;
	this->_levels[0] = "DEBUG";
	this->_levels[1] = "INFO";
	this->_levels[2] = "WARNING";
	this->_levels[3] = "ERROR";

	std::cout	<< "Harl constructor called."
				<< std::endl;
	return;
}

Harl::~Harl( void )
{
	std::cout	<< "Harl dectructor called."
				<< std::endl;
	return;
}

std::string toUppercase ( std::string str )
{
	size_t	i = 0;

	while (str[i])
	{
		if (std::islower(str[i]))
			str[i] = std::toupper(str[i]);
		i++;
	}
	return str;
}

void Harl::complain( std::string level )
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_levels[i] == toUppercase(level))
		{
			(this->*_mood[i])();
			return ;
		}
	}
}

void Harl::explain( std::string level )
{
	short		print = 0;

	for (int i = 0; i < 4; i++)
	{
		if (print || this->_levels[i] == toUppercase(level))
		{
			std::cout << "[" << this->_levels[i] << "]" << std::endl;
			(this->*_mood[i])();
			std::cout << std::endl;
			print = 1;
		}
	}
	if (!print)
		std::cout << COLOUR_INFO
				<< "[ Probably complaining about insignificant problems ]"
				<< COLOUR_FIN << std::endl;
}

void Harl::debug( void )
{
	std::cout	<< COLOUR_DEBUG
				<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

void Harl::info( void )
{
	std::cout	<< COLOUR_INFO
				<< "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

void Harl::warning( void )
{
	std::cout	<< COLOUR_WARNING
				<< "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
				<< COLOUR_FIN
				<< std::endl;
	return;
}

void Harl::error( void )
{
	std::cout	<< COLOUR_ERROR
				<< "This is unacceptable! I want to speak to the manager now."
				<< COLOUR_FIN
				<< std::endl;
	return;
}
