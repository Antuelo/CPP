#ifndef INTERN_HPP
#define INTERN_HPP

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include <exception>
# include "AForm.hpp"

class AForm;

class Intern
{
	public:
		Intern();
		Intern(const Intern &other);
		
		~Intern();
		
		Intern &operator=(const Intern &other);

		AForm	*makeForm(const std::string form_name, const std::string form_target) ;
};

#endif //INTERN_HPP
