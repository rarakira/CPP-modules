#ifndef FORM_H
# define FORM_H

# include <iostream>
# include "Bureaucrat.hpp"
# include "Colours.hpp"

class Bureaucrat;

class Form {
private:
	const std::string	_name;
	bool				_signed;
	const int			_gradeToSign;
	const int			_gradeToExec;
public:
	Form();
	Form(std::string const & name, int nToSign, int nToExec);
	Form(Form const & src);
	Form & operator=(Form const & rhs);
	~Form();

	const std::string & getName(void) const;
	const int & getGradeToSign(void) const;
	const int & getGradeToExec(void) const;
	bool isSigned(void) const;
	bool beSigned(Bureaucrat const & clerk);

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
};

std::ostream & operator<<(std::ostream & o, Form const & rhs);

#endif