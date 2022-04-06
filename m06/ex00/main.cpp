#include <iostream>
#include "Convert.hpp"

int main(int argc, char **argv) {
	if (argc == 2) {
		if (argv[1][0] == 0) {
			std::cerr << "Error: The argument should not be empty" << std::endl;
			return 1;
		}
		Convert num(argv[1]);
		num.toChar();
		num.toInt();
		num.toFloat();
		num.toDouble();
	}
	else {
		std::cerr << "Error: Converter takes 1 argument" << std::endl;
		return 1;
	}
	return 0;
}
