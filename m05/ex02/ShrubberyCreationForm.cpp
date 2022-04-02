#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm("ShrubberyCreationForm", "void", 137, 145)
{
	std::cout	<< COLOUR_NEW
				<< "ShrubberyCreationForm DEFAULT constructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string const & target ) : AForm("ShrubberyCreationForm", target, 137, 145)
{
	std::cout	<< COLOUR_NEW
				<< "ShrubberyCreationForm constructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & src ) : AForm(src.AForm::getName(), src.AForm::getTarget(), 145, 137)
{
	std::cout	<< COLOUR_NEW
				<< "ShrubberyCreationForm COPY constructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	this->setName(rhs.AForm::getName());
	this->setTarget(rhs.AForm::getTarget());
	this->setSigned(rhs.AForm::isSigned());
	this->setGradeToExec(rhs.AForm::getGradeToExec());
	this->setGradeToSign(rhs.AForm::getGradeToSign());
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
	std::cout	<< COLOUR_DELETE
				<< "ShrubberyCreationForm destructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

bool ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!this->AForm::isSigned())
	{
		std::cout	<< COLOUR_BBLUE
				<< this->AForm::getName() << " form is fot signed!"
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
	std::cout	<< COLOUR_ORG
				<< this->AForm::getTarget() << "_target is created 🥦 🥦 🥦"
				<< COLOUR_FIN
				<< std::endl;
	return true;
}

// const char* ShrubberyCreationForm::GradeTooHighException::what() const throw()
// {
// 	return (">> The grade is too high for the ShrubberyCreationForm!");
// }

// const char* ShrubberyCreationForm::GradeTooLowException::what() const throw()
// {
// 	return (">> The grade is too low for the ShrubberyCreationForm!");
// }
