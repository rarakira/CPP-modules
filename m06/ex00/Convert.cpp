#include <sstream>
#include <iomanip>
#include <limits>
#include <istream>
#include "Convert.hpp"

// INT 0 -42
// FLOAT 42.21f
// DOUBLE 42.21
// ASCII
// nan | nanf
// -inff +inff | -inf +inf

Convert::Convert(): _number(0), _type(0), _str("Error"), _prec(0) {
	return;
}

Convert::Convert(std::string const & str): _number(0), _type(0), _str(str), _prec(0)  {
	// std::stringstream	ss(str);

	if (isChar(str)) {const_cast<short &>(_type) = T_CHAR; }
	else if (isSpecial(str)) {const_cast<short &>(_type) = T_SPECIAL; }
	else if (isInt(str)) {const_cast<short &>(_type) = T_INT; }
	else if (isFloat(str)) {const_cast<short &>(_type) = T_FLOAT; }
	else if (isDouble(str)) {const_cast<short &>(_type) = T_DOUBLE; }

	if (_type == T_CHAR) {
		const_cast<double &>(this->_number) = str.at(0);
	}
	if (_type  == T_INT || _type == T_FLOAT || _type == T_DOUBLE) {
		const_cast<double &>(this->_number) = std::stod(str);
		size_t pos = 0;
		if ((pos = str.find(".")) != std::string::npos) {
			this->_prec = str.length() - ++pos;
			if (_type == T_FLOAT) {
				this->_prec -= 1;
			}
		}
	}
	return;
}

Convert::Convert(Convert const & src) : _number(src.getNumber()), _type(src.getType()), _str(src.getStr()), _prec(src.getPrec()) {
	return;
}

Convert & Convert::operator=(Convert const & rhs) {
	const_cast<double &>(_number) = rhs.getNumber();
	const_cast<short &>(_type) = rhs.getType();
	return *this;
}

Convert::~Convert() {
	return;
}

const double & Convert::getNumber(void) const {
	return this->_number;
}

const short & Convert::getType(void) const {
	return this->_type;
}

const std::string & Convert::getStr(void) const {
	return this->_str;
}
const int & Convert::getPrec(void) const {
	return this->_prec;
}
	
bool Convert::isChar(std::string const & str) const {
	return (str.length() == 1 && std::isprint(str[0]));
}

bool Convert::isInt(std::string const & str) const {
	std::stringstream 	ss(str);
	int num;

	ss >> num;
	return (ss.eof() == 1 && ss.fail() == 0);
}

bool Convert::isFloat(std::string const & str) const {
	float num = std::stof(str);
	std::stringstream 	ss;
	ss << num;
	if (str.at(str.length() - 1) == 'f') {
		if (str.length() == (ss.str().length() + 1)) {
			return true;
		}
	}
	return false;
	// std::stringstream 	ss(str);
	// double 				num;
	// std::string			ch;

	// std::cout << "Start:: " << str << std::endl;
	// if (!(ss >> num)) {
	// 	std::cout << "[ Unsuccessfull ]" << std::endl;
	// }
	// ss >> ch;
	// std::cout << "CONVERTER:: " << num << " " << ch << std::endl;
	// return (ch == "f" && ss.eof() == 1 && ss.fail() == 0);
}

bool Convert::isDouble(std::string const & str) const {
	std::stringstream 	ss(str);
	double				num;

	ss >> num;
	return (ss.eof() == 1 && ss.fail() == 0);
}

bool Convert::isSpecial(std::string const & str) const {
	std::stringstream 	ss("nan nanf -inff +inff -inf +inf inff inf");
	std::string			current;

	while (ss.eof() != 1)
	{
		ss >> current;
		if (current == str) {
			return true;
		}
	}
	return (false);
}

void Convert::toChar(void) {
	std::cout << "char: ";
	if (this->_type == T_EMPTY) {
		std::cout << "Error";
	}
	else if (this->_type == T_SPECIAL) {
		std::cout << "Impossible";
	}
	else if (std::isprint(static_cast<char>(this->_number))) {
		std::cout << "\'"
		<< static_cast<char>(this->_number) << "\'";
	}
	else if (this->_str == " ") {
		std::cout << "\' \'";
	}
	else {
		std::cout << "Non displayable";
	}
	std::cout << std::endl;
}
void Convert::toInt(void) {
	std::cout << "int: ";
	if (this->_type == T_EMPTY) {
		std::cout << "Error";
	}
	else if (this->_type == T_SPECIAL) {
		std::cout << "Impossible";
	}
	else if (this->_number < static_cast<double>(INT_MIN) || this->_number > static_cast<double>(INT_MAX)) {
		std::cout << "Overflow";
	}
	else {
		std::cout << static_cast<int>(this->_number);
	}
	std::cout << std::endl;
}

void Convert::toFloat(void) {
	std::cout << "float: ";
	if (this->_type == T_EMPTY) {
		std::cout << "Error";
	}
	else if (this->_type == T_SPECIAL)
	{
		if (this->_str == "inff" || this->_str == "-inff" || this->_str == "+inff" || this->_str == "nanf") {
			std::cout << this->_str;
		}
		else {
			std::cout << this->_str << 'f';
		}
	}
	else {
		std::cout	<< std::fixed << std::setprecision(this->_prec)
					<< static_cast<float>(this->_number) << 'f';
	}
	std::cout << std::endl;
}

void Convert::toDouble(void) {
	std::cout << "double: ";
	if (this->_type == T_EMPTY) {
		std::cout << "Error";
	}
	else if (this->_type == T_SPECIAL)
	{
		if (this->_str == "inff" || this->_str == "-inff" || this->_str == "+inff" || this->_str == "nanf") {
			std::cout << this->_str.substr(0, this->_str.length() - 1);
		}
		else {
			std::cout << this->_str;
		}
	}
	else {
		std::cout	<< std::fixed << std::setprecision(this->_prec)
					<< this->_number;
	}
	std::cout << std::endl;
}
