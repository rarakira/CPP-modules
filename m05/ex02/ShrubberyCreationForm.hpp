#ifndef FORM_H
# define FORM_H

# include <iostream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include "Colours.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm( void );
	ShrubberyCreationForm(  std::string const & target );
	ShrubberyCreationForm( ShrubberyCreationForm const & src );
	ShrubberyCreationForm & operator=( ShrubberyCreationForm const & rhs );
	~ShrubberyCreationForm( void );

	const std::string & getName( void ) const;
	const int & getGradeToSign( void ) const;
	const int & getGradeToExec( void ) const;
	bool isSigned( void ) const;
	bool beSigned( Bureaucrat const & clerk );
	virtual bool execute(Bureaucrat const & executor) const;
};

// std::ostream & operator<<( std::ostream & o, ShrubberyCreationForm const & rhs );

#endif