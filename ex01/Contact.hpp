#ifndef CONTACT_H
# define CONTACT_H
# include "Contact.hpp"
# include <iostream>

class Contact {
	std::string		_first_name;
	std::string		_last_name;
	std::string		_nickname;
	std::string		_phone_number;
	std::string		_darkest_secret;
public:
	Contact( void );
	~Contact( void );

	void set_values( void );
	std::string get_first_name( void ) const;
	std::string get_last_name( void ) const;
	std::string get_nickname( void ) const;
	std::string get_phone_number( void ) const;
	std::string get_darkest_secret( void ) const;
};

#endif
