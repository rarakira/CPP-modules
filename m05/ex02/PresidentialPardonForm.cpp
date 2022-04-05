#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
		: AForm("PresidentialPardonForm", "void", 25, 5) {
	std::cout	<< COLOUR_NEW
				<< "PresidentialPardonForm DEFAULT constructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const & target)
		: AForm("PresidentialPardonForm", target, 25, 5) {
	std::cout	<< COLOUR_NEW
				<< "PresidentialPardonForm constructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src)
		: AForm(src.AForm::getName(), src.AForm::getTarget(), 25, 5) {
	std::cout	<< COLOUR_NEW
				<< "PresidentialPardonForm COPY constructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs) {
	AForm::operator=(rhs);
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout	<< COLOUR_DELETE
				<< "PresidentialPardonForm destructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

bool PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (!this->AForm::isSigned())
	{
		std::cout	<< COLOUR_BBLUE
				<< this->AForm::getName() << " form is not signed!"
				<< COLOUR_FIN
				<< std::endl;
		return false;
	}
	else if (this->AForm::getGradeToExec() < executor.getGrade())
	{
		std::cout	<< COLOUR_BBLUE
					<< this->AForm::getName() << " form can not be executed by " << executor.getName()
					<< COLOUR_FIN
					<< std::endl;
		throw AForm::GradeTooLowException();
	}
	std::cout	<< COLOUR_BBLUE
				<< this->AForm::getTarget() << " has been pardoned by Zaphod Beeblebrox."
				<< COLOUR_FIN
				<< std::endl;
	return true;
}
