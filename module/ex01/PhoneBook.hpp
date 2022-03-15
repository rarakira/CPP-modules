#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H
# include "Contact.hpp"

class PhoneBook {
	Contact	_book[8];
	int		_count;

public:
	PhoneBook( void );
	~PhoneBook( void );

	void add_contact( void );
	void search_contact( void );
	int get_count( void );
};

#endif
