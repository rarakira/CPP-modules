#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H

# include <iostream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include "Colours.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm {
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string const & target);
	PresidentialPardonForm(PresidentialPardonForm const & src);
	PresidentialPardonForm & operator=(PresidentialPardonForm const & rhs);
	virtual ~PresidentialPardonForm();

	bool execute(Bureaucrat const & executor) const;
};

#endif