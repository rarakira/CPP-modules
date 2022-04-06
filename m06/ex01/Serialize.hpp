#ifndef SERIALIZE_H
#define SERIALIZE_H

#include <iostream>
# include "Colours.hpp"

struct Data
{
	std::string		name;
	std::string		type;
	int				age;
};

uintptr_t	serialize(Data* ptr);
Data*		deserialize(uintptr_t raw);

#endif