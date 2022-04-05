#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

# include <iostream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include "Colours.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm {
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string const & target);
	ShrubberyCreationForm(ShrubberyCreationForm const & src);
	ShrubberyCreationForm & operator=(ShrubberyCreationForm const & rhs);
	virtual ~ShrubberyCreationForm();

	virtual bool execute(Bureaucrat const & executor) const;
};

#endif