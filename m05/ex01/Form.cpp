#include "Form.hpp"

Form::Form( void ) : _name("Noname"), _signed(false), _gradeToSign(50), _gradeToExec(150)
{
	std::cout	<< COLOUR_NEW
				<< "Form DEFAULT constructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

Form::Form( std::string const & name, int nToSign, int nToExec ) : _name(name), _signed(false), _gradeToSign(nToSign), _gradeToExec(nToExec)
{
	if (nToSign < 1 || nToExec < 1)
		throw Form::GradeTooHighException();
	if (nToSign > 150 || nToExec > 150)
		throw Form::GradeTooLowException();
	std::cout	<< COLOUR_NEW
				<< "Form constructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

Form::Form( Form const & src ) : _gradeToSign(src.getGradeToSign()), _gradeToExec(src.getGradeToExec())
{
	const_cast<std::string &>(_name) = src.getName();
	this->_signed = src.isSigned();
	std::cout	<< COLOUR_NEW
				<< "Form COPY constructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

Form & Form::operator=( Form const & rhs )
{
	const_cast<std::string &>(_name) = rhs.getName();
	this->_signed = rhs.isSigned();
	const_cast<int &>(_gradeToSign) = rhs.getGradeToSign();
	const_cast<int &>(_gradeToExec) = rhs.getGradeToExec();
	return *this;
}

Form::~Form( void )
{
	std::cout	<< COLOUR_DELETE
				<< "Form destructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

const std::string & Form::getName( void ) const
{
	return this->_name;
}

const int & Form::getGradeToSign( void ) const
{
	return this->_gradeToSign;
}

const int & Form::getGradeToExec( void ) const
{
	return this->_gradeToExec;
}

bool Form::isSigned( void ) const
{
	return this->_signed;
}

bool Form::beSigned( Bureaucrat const & clerk )
{
	if (this->isSigned())
		std::cout	<< COLOUR_BBLUE
				<< "FORM: Bureaucrat " << clerk.getName() << " could not sign the form " << this->getName() << " because it's already signed"
				<< COLOUR_FIN
				<< std::endl;
	else if (this->_gradeToSign < clerk.getGrade())
	{
		std::cout	<< COLOUR_BBLUE
				<< "FORM: Bureaucrat " << clerk.getName() << " could not sign the form " << this->getName() << " because his grade is too low"
				<< COLOUR_FIN
				<< std::endl;
		throw Form::GradeTooLowException();
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

std::ostream & operator<<( std::ostream & o, Form const & rhs )
{
	o	<< "Document name: " << rhs.getName()
		<< (rhs.isSigned() ? ", is signed, " : ", is not signed, ")
		<< "can be signed starting from " << rhs.getGradeToSign() << "th grade,"
		<< "can be executed starting from " << rhs.getGradeToExec() << "th grade";
	return o;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return (">> The grade is too high for the form!");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return (">> The grade is too low for the form!");
}
