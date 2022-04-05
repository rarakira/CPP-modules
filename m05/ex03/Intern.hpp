#ifndef INTERN_H
# define INTERN_H

# include <iostream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include "Colours.hpp"

class AForm;

class Intern {
public:
	Intern();
	Intern(Intern const & src);
	Intern & operator=(Intern const & rhs);
	~Intern();

	AForm *makeForm(const std::string & name, const std::string & target);
};

std::ostream & operator<<(std::ostream & o, Intern const & rhs);

#endif