#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class AForm;

class Bureaucrat
{
	private:
		const std::string 	_name;
		int					_grade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &copy);

		~Bureaucrat();


	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};


	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	//members fonctions

		int					getGrade()const;
		std::string			getName()const;

		void				incrementGrade();
		void				decrementGrade();
		void				signForm(AForm &f);
};


std::ostream &operator<<(std::ostream &os, const Bureaucrat &other);

#endif //BUREAUCRAT_HPP
