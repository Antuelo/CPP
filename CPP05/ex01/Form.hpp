#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string 	_name;
		bool				_sign;
		const int			_sing_grade;
		const int 			_exec_grade;

	public:
		Form();
		Form(std::string name, int sing_grade, int exec_grade);

		~Form();

		void		getName() const;
		void		getSignGrade() const;
		void 		getExecGrade() const;
		void		beSigned(const Bureaucrat &b);

		class GradeTooHighException : public std::exception
		{
			virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, const Form);

#endif
