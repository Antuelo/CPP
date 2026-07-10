#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string 	_target;
	
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		RobotomyRequestForm(std::string target);

		~RobotomyRequestForm();

		class RobotomisedFail : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		void 	execute(const Bureaucrat &executor) const;

	RobotomyRequestForm	&operator=(const RobotomyRequestForm &other);
};

#endif