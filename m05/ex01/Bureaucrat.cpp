#include <sstream>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : _name("Noname"), _grade(75)
{
	std::cout	<< COLOUR_NEW
				<< "Bureaucrat DEFAULT constructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

Bureaucrat::Bureaucrat( std::string const & name, int number ) : _name(name), _grade(number)
{
	if (number < 1)
		throw Bureaucrat::GradeTooHighException();
	if (number > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout	<< COLOUR_NEW
				<< "Bureaucrat constructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

Bureaucrat::Bureaucrat( Bureaucrat const & src )
{
	const_cast<std::string &>(_name) = src.getName();
	this->_grade = src.getGrade();
	std::cout	<< COLOUR_NEW
				<< "Bureaucrat COPY constructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

Bureaucrat & Bureaucrat::operator=( Bureaucrat const & rhs )
{
	const_cast<std::string &>(_name) = rhs.getName();
	this->_grade = rhs.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat( void )
{
	std::cout	<< COLOUR_DELETE
				<< "Bureaucrat destructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

const std::string & Bureaucrat::getName( void ) const
{
	return this->_name;
}

int Bureaucrat::getGrade( void ) const
{
	return this->_grade;
}

void Bureaucrat::incrementGrade( int points )
{
	if ((this->_grade - points) < 1)
		throw Bureaucrat::GradeTooHighException();
	if ((this->_grade - points) > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade -= points;
	std::cout	<< COLOUR_VIOL
				<< "Bureaucrat " << this->_name << " got promoted to " << this->_grade << "th grade."
				<< COLOUR_FIN
				<< std::endl;
}

void Bureaucrat::decrementGrade( int points )
{
	if ((this->_grade + points) < 1)
		throw Bureaucrat::GradeTooHighException();
	if ((this->_grade + points) > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade += points;
	std::cout	<< COLOUR_YELL
				<< "Bureaucrat " << this->_name << " got downgraded to " << this->_grade << "th grade."
				<< COLOUR_FIN
				<< std::endl;
}

void Bureaucrat::signForm( Form & doc )
{
	try
	{
		if (doc.beSigned(*this))
			std::cout	<< COLOUR_ORG
					<< "Bureaucrat " << this->_name << " signed the form " << doc.getName()
					<< COLOUR_FIN
					<< std::endl;
		else
		{
			std::cout	<< COLOUR_ORG
					<< "Bureaucrat " << this->_name << " could not sign the form " << doc.getName()
					<< COLOUR_FIN
					<< std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

std::ostream & operator<<( std::ostream & o, Bureaucrat const & rhs )
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return o;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return (">> The grade is too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return (">> The grade is too low!");
}