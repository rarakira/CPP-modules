#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <iostream>
# include "Colours.hpp"

class Bureaucrat {
private:
	const std::string	_name;
	int					_grade;
public:
	Bureaucrat();
	Bureaucrat(std::string const & name, int number);
	Bureaucrat(Bureaucrat const & src);
	Bureaucrat & operator=(Bureaucrat const & rhs);
	~Bureaucrat();

	const std::string & getName(void) const;
	int getGrade(void) const;
	void incrementGrade(int points);
	void decrementGrade(int points);

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

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs);

#endif