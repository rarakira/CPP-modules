#include <iostream>
#include <iomanip>
#include "Base.hpp"

void print_status(std::string const msg) {
	std::cout	<< std::endl
				<< std::left << std::setw(40) << std::setfill('-')
				<< msg << std::endl;
}

int main(void) {
	{
		Base *		a = new A();
		Base *		b = new B();
		Base *		c = new C();

		print_status("--- Create ");

		identify(a);
		identify(*a);
		identify(b);
		identify(*b);
		identify(c);
		identify(*c);

		print_status("--- Destroy ");

		delete a;
		delete b;
		delete c;
	}
	{
		Base *		a[10];

		print_status("--- Check by ptr* ");

		for (size_t i = 0; i < 10; i++) {
			a[i] = generate();
			identify(a[i]);
		}
		print_status("--- Check by ref& ");
		for (size_t i = 0; i < 10; i++) {
			identify(a[i]);
		}

		print_status("--- Destroy ");

		for (size_t i = 0; i < 10; i++) {
			delete a[i];
		}
	}
	return 0;
}
