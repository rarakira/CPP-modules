#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

static AForm	*createPresidentialPardonForm(std::string const &target);
static AForm	*createRobotomyRequestForm(std::string const &target);
static AForm	*createShrubberyCreationForm(std::string const &target);

Intern::Intern() {
	std::cout	<< COLOUR_NEW
				<< "Intern DEFAULT constructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

Intern::Intern(Intern const & src) {
	(void) src;
	std::cout	<< COLOUR_NEW
				<< "Intern COPY constructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

Intern & Intern::operator=(Intern const & rhs) {
	(void) rhs;
	return *this;
}

Intern::~Intern() {
	std::cout	<< COLOUR_DELETE
				<< "Intern destructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

AForm * Intern::makeForm(const std::string & name, const std::string & target) {
	AForm			*form = NULL;
	typedef AForm *(*_func)(std::string const &target);
	typedef struct {
		std::string name;
		_func func;
	}	FormTypes;

	FormTypes	forms[] = {
		{"presidential pardon", &createPresidentialPardonForm},
		{"robotomy request", &createRobotomyRequestForm},
		{"shrubbery creation", &createShrubberyCreationForm}
	};

	for (int i = 0; i < 3; i++) {
		if (forms[i].name == name) {
			form = forms[i].func(target);
			std::cout << COLOUR_VIOL
			<< "Intern creates " << form->getName()
			<< COLOUR_FIN
			<< std::endl;
			return form;
		}
	}
	std::cout	<< COLOUR_VIOL
				<< "Intern can`t create the form "
				<< name
				<< COLOUR_FIN
				<< std::endl;
	return form;
}

static AForm	*createPresidentialPardonForm(std::string const &target)
{
	return new PresidentialPardonForm(target);
}

static AForm	*createRobotomyRequestForm(std::string const &target)
{
	return new RobotomyRequestForm(target);
}

static AForm	*createShrubberyCreationForm(std::string const &target)
{
	return new ShrubberyCreationForm(target);
}