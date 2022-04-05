#include <cstdlib>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
		: AForm("RobotomyRequestForm", "void", 72, 45) {
	std::cout	<< COLOUR_NEW
				<< "RobotomyRequestForm DEFAULT constructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target)
		: AForm("RobotomyRequestForm", target, 72, 45) {
	std::cout	<< COLOUR_NEW
				<< "RobotomyRequestForm constructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src)
		: AForm(src.AForm::getName(), src.AForm::getTarget(), 72, 45) {
	std::cout	<< COLOUR_NEW
				<< "RobotomyRequestForm COPY constructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs) {
	AForm::operator=(rhs);
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout	<< COLOUR_DELETE
				<< "RobotomyRequestForm destructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

bool RobotomyRequestForm::execute(Bureaucrat const & executor) const {
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
				<< "** DZZZZZZ VZZZZZZ **"
				<< std::endl;
	if (rand() % 2)
	{
		std::cout	<< "[SUCCESS] "
					<< this->AForm::getTarget()
					<< " has been robotomized successfully!"
					<< COLOUR_FIN
					<< std::endl;
		return true;
	}
	std::cout	<< "[FAILURE] Robotization of "
				<< this->AForm::getTarget()
				<< " failed."
				<< COLOUR_FIN
				<< std::endl;
	return false;
}