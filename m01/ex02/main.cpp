#include <iostream>

int main( void )
{
	std::string	str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout	<< "\nADDRESSES:\nstr addr: " << &str << std::endl
				<< "strPTR addr: " << &stringPTR << std::endl
				<< "strRED addr: " << &stringREF << std::endl
				<< std::endl;
	std::cout	<< "VALUES:\nstr = " << str << std::endl
				<< "strPTR = " << *stringPTR << std::endl
				<< "strRED = " << stringREF << std::endl
				<< std::endl;
	return 0;
}
