#ifndef CONVERT_H
# define CONVERT_H

# include <iostream>
# include "Colours.hpp"

#define T_EMPTY		0
#define T_CHAR		1
#define T_INT		2
#define T_FLOAT		3
#define T_DOUBLE	4
#define T_SPECIAL	5

class Convert {
private:
	const double			_number;
	const short				_type;
	const std::string		_str;
	int						_prec;
public:
	Convert();
	Convert(std::string const & str);
	Convert(Convert const & src);
	Convert & operator=(Convert const & rhs);
	~Convert();

	const double & getNumber(void) const;
	const short & getType(void) const;
	const std::string & getStr(void) const;
	const int & getPrec(void) const;
	
	bool isChar(std::string const & str) const;
	bool isInt(std::string const & str) const;
	bool isFloat(std::string const & str) const;
	bool isDouble(std::string const & str) const;
	bool isSpecial(std::string const & str) const;

	void toChar(void);
	void toInt(void);
	void toFloat(void);
	void toDouble(void);
};

#endif