#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string 	_name;
		bool				_sign;
		const int			_sing_grade;
		const int 			_exec_grade;

	public:
		AForm();
		AForm(const AForm &copy);
		AForm(std::string name, int sing_grade, int exec_grade);

		virtual ~AForm();

		//methods
		std::string		getName() const;
		int				getSignGrade() const;
		int 			getExecGrade() const;
		bool			getSignState() const;
		void			beSigned(const Bureaucrat &b);

		class GradeTooHighException : public std::exception
		{
			public :
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		//ABSTRACT METHOD
		virtual void execute(const Bureaucrat &executor) const = 0;

		class NotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, const AForm &other);

#endif
