#include "AForm.hpp"

AForm::AForm(std::string const & name, std::string const & target, int nToSign, int nToExec)
		:	_name(name), _target(target), _signed(false),
			_gradeToSign(nToSign), _gradeToExec(nToExec) {
	if (nToSign < 1 || nToExec < 1)
		throw AForm::GradeTooHighException();
	if (nToSign > 150 || nToExec > 150)
		throw AForm::GradeTooLowException();
	std::cout	<< COLOUR_NEW
				<< "AForm::" << this->_name << " constructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

AForm::AForm(AForm const & src)
		:	_name (src.getName()), _target(src.getTarget()), _signed(src.isSigned()),
			_gradeToSign(src.getGradeToSign()), _gradeToExec(src.getGradeToExec()) {
	std::cout	<< COLOUR_NEW
				<< "AForm COPY constructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

AForm & AForm::operator=(AForm const & rhs) {
	this->setName(rhs.AForm::getName());
	this->setTarget(rhs.AForm::getTarget());
	this->setSigned(rhs.AForm::isSigned());
	this->setGradeToExec(rhs.AForm::getGradeToExec());
	this->setGradeToSign(rhs.AForm::getGradeToSign());
	return *this;
}

AForm::~AForm() {
	std::cout	<< COLOUR_DELETE
				<< "AForm destructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

const std::string & AForm::getName(void) const {
	return this->_name;
}

const std::string & AForm::getTarget(void) const {
	return this->_target;
}

const int & AForm::getGradeToSign(void) const {
	return this->_gradeToSign;
}

const int & AForm::getGradeToExec(void) const {
	return this->_gradeToExec;
}

void AForm::setName(const std::string & name) {
	const_cast<std::string &>(_name) = name;
}

void AForm::setTarget(const std::string & target) {
	const_cast<std::string &>(_target) = target;
}

void AForm::setSigned(bool s) {
	this->_signed = s;
}

void AForm::setGradeToSign(int n) {
	const_cast<int &>(_gradeToSign) = n;
}

void AForm::setGradeToExec(int n) {
	const_cast<int &>(_gradeToExec) = n;
}


bool AForm::isSigned(void) const {
	return this->_signed;
}

bool AForm::beSigned(Bureaucrat const & clerk) {
	if (this->isSigned())
		std::cout	<< COLOUR_BBLUE
				<< "FORM: Bureaucrat " << clerk.getName() << " could not sign the form " << this->getName() << " because it's already signed"
				<< COLOUR_FIN
				<< std::endl;
	else if (this->_gradeToSign < clerk.getGrade())
	{
		std::cout	<< COLOUR_BBLUE
				<< "FORM: Bureaucrat " << clerk.getName() << " could not sign the Aform " << this->getName() << " because his grade is too low"
				<< COLOUR_FIN
				<< std::endl;
		throw AForm::GradeTooLowException();
	}
	else
	{
		this->_signed = true;
		std::cout	<< COLOUR_BBLUE
				<< "FORM: Bureaucrat " << clerk.getName() << " signed the form " << this->getName()
				<< COLOUR_FIN
				<< std::endl;
		return true;
	}
	return false;
}

std::ostream & operator<<(std::ostream & o, AForm const & rhs) {
	o	<< "Document name: \"" << rhs.getName()
		<< (rhs.isSigned() ? "\", is signed, " : "\", is not signed.") << std::endl
		<< "Target: \"" << rhs.getTarget() << "\"" << std::endl
		<< "Can be signed starting from " << rhs.getGradeToSign() << "th grade."  << std::endl
		<< "Can be executed starting from " << rhs.getGradeToExec() << "th grade.";
	return o;
}

const char* AForm::GradeTooHighException::what() const throw() {
	return (">> The grade is too high for the form!");
}

const char* AForm::GradeTooLowException::what() const throw() {
	return (">> The grade is too low for the form!");
}
