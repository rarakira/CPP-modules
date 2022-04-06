#include "Base.hpp"

Base * generate(void) {
	int	i = rand() % 3;

	if (i == 0) { return (new A); }
	else if (i == 1) { return (new B); }
	else { return (new C); }
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p)) {
		std::cout << "A";
	}
	else if (dynamic_cast<B*>(p)) {
		std::cout << "B";
	}
	else {
		std::cout << "C";
	}
	std::cout << " class was created" << std::endl;
}

void identify(Base& p) {
	try {
		A &d = dynamic_cast<A &>(p);
		(void) d;
		std::cout << "A";
	}
	catch(std::bad_cast &bc) {
		
		try {
			B &d = dynamic_cast<B &>(p);
			(void) d;
			std::cout << "B";
		}
		catch(std::bad_cast &bc) {
			std::cout << "C";
		}
	}
	std::cout << " class was created" << std::endl;
}
