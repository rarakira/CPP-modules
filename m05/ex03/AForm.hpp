#ifndef AFORM_H
# define AFORM_H

# include <iostream>
# include "Bureaucrat.hpp"
# include "Colours.hpp"

class Bureaucrat;

class AForm {
private:
	const std::string	_name;
	const std::string	_target;
	bool				_signed;
	const int			_gradeToSign;
	const int			_gradeToExec;
public:
	AForm(std::string const & name, std::string const & target, int nToSign, int nToExec);
	AForm(AForm const & src);
	virtual AForm & operator=(AForm const & rhs);
	virtual ~AForm();

	/* getters */
	const std::string & getName(void) const;
	const std::string & getTarget(void) const;
	const int & getGradeToSign(void) const;
	const int & getGradeToExec(void) const;
	bool isSigned(void) const;

	/* setters */
	void setName(const std::string & name);
	void setTarget(const std::string & target);
	void setSigned(bool s);
	void setGradeToSign(int n);
	void setGradeToExec(int n);

	bool beSigned(Bureaucrat const & clerk);
	virtual bool execute(Bureaucrat const & executor) const = 0;

	/* exceptions */
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

std::ostream & operator<<(std::ostream & o, AForm const & rhs);

#endif