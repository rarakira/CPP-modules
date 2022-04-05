#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
		: AForm("ShrubberyCreationForm", "void", 137, 145) {
	std::cout	<< COLOUR_NEW
				<< "ShrubberyCreationForm DEFAULT constructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target)
		: AForm("ShrubberyCreationForm", target, 137, 145) {
	std::cout	<< COLOUR_NEW
				<< "ShrubberyCreationForm constructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src)
		: AForm(src.AForm::getName(), src.AForm::getTarget(), 137, 145) {
	std::cout	<< COLOUR_NEW
				<< "ShrubberyCreationForm COPY constructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs) {
	AForm::operator=(rhs);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout	<< COLOUR_DELETE
				<< "ShrubberyCreationForm destructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

bool ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (!this->AForm::isSigned()) {
		std::cout	<< COLOUR_BBLUE
				<< this->AForm::getName() << " form is not signed!"
				<< COLOUR_FIN
				<< std::endl;
		return false;
	}
	else if (this->AForm::getGradeToExec() < executor.getGrade()) {
		std::cout	<< COLOUR_BBLUE
					<< this->AForm::getName() << " form can not be executed by " << executor.getName()
					<< COLOUR_FIN
					<< std::endl;
		throw AForm::GradeTooLowException();
	}	
	std::string		filename(this->getTarget() + "_target");
	std::ofstream	ofs(filename);
	if (ofs.is_open())
	{
		ofs << " 🥦 🥦 🥦 🥦 🥦 🥦 🥦 🥦 🥦 ";
		ofs.close();
		std::cout	<< COLOUR_BBLUE
					<< this->AForm::getTarget() << "_target is created"
					<< COLOUR_FIN
					<< std::endl;
		return true;
	}
	std::cout	<< COLOUR_RED
				<< "Error creating "
				<< this->AForm::getTarget() << "_target file"
				<< COLOUR_FIN
				<< std::endl;
	return false;
}
