#include "PhoneBook.hpp"

int main( void )
{
	PhoneBook		book;
	std::string		command;

	while (1)
	{
		std::cout << "Please, enter command: ";
		std::getline(std::cin, command);
		if (command.compare("ADD") == 0)
			book.add_contact();
		else if (command.compare("SEARCH") == 0)
			book.search_contact();
		else if (command.compare("EXIT") == 0)
			break;
		else
			std::cout << "Availible commands are: ADD, SEARCH and EXIT" << std::endl;
	}
	return 0;
}
