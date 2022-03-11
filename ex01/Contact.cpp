#include "Contact.hpp"

Contact::Contact( void )
{
	// std::cout << "Contact constructed" << std::endl;
	return;
}

Contact::~Contact( void )
{
	// std::cout << "Contact dectructor called" << std::endl;
	return;
}

void Contact::set_values( void )
{
	std::cout << "First name: ";
	std::getline(std::cin, this->_first_name);
	std::cout << "Last name: ";
	std::getline(std::cin, this->_last_name);
	std::cout << "Nickname: ";
	std::getline(std::cin, this->_nickname);
	std::cout << "Phone Number: ";
	std::getline(std::cin, this->_phone_number);
	std::cout << "Darkest Secret: ";
	std::getline(std::cin, this->_darkest_secret);
	std::cout << "Contact " << this->_nickname << " created" << std::endl;
}

std::string Contact::get_first_name( void ) const
{
	return this->_first_name;
}

std::string Contact::get_last_name( void ) const
{
	return this->_last_name;
}

std::string Contact::get_nickname( void ) const
{
	return this->_nickname;
}

std::string Contact::get_phone_number( void ) const
{
	return this->_phone_number;
}

std::string Contact::get_darkest_secret( void ) const
{
	return this->_darkest_secret;
}
