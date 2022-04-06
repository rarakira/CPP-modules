#include <iostream>
#include <iomanip>
#include "Serialize.hpp"

void print_status(std::string const msg) {
	std::cout	<< std::endl
				<< std::left << std::setw(40) << std::setfill('-')
				<< msg << std::endl;
}

int main(void) {
	Data		*cat = new Data;
	uintptr_t	raw;

	print_status("--- Create ");
	cat->name = "Sam";
	cat->type = "cat";
	cat->age = 4;

	std::cout	<< "ptr: " << cat << std::endl;
	std::cout	<< cat->name << " is a " << cat->type
				<< " he is " << cat->age << " years old." << std::endl;

	print_status("--- Serialize ");
	raw = serialize(cat);
	std::cout	<< "raw: " << raw << "["
				<< std::hex << raw << std::dec << "]" << std::endl;
	std::cout	<< reinterpret_cast<Data *>(raw)->name << " is a " << reinterpret_cast<Data *>(raw)->type
				<< " he is " << reinterpret_cast<Data *>(raw)->age << " years old." << std::endl;

	print_status("--- Deserialize ");
	Data *dog = deserialize(raw);
	std::cout	<< "ptr: " << dog << std::endl;
	std::cout	<< dog->name << " is a " << dog->type
				<< " he is " << dog->age << " years old." << std::endl;

	print_status("--- Finished ");

	delete dog;
	return 0;
}
