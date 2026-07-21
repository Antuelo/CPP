/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 16:01:48 by antuel            #+#    #+#             */
/*   Updated: 2026/07/21 14:53:42 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{}

Intern::Intern(const Intern &other)
{
	*this = other;
}

Intern::~Intern()
{}

Intern &Intern::operator=(const Intern &other)
{
	if (&other != this)
		*this = other;
	
	return *this;
}

static AForm* Shrubberycreator(const std::string& target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm* Robotomycreator(const std::string& target)
{
	return (new RobotomyRequestForm(target));
}

static AForm* Pardoncreator(const std::string& target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeForm(const std::string form_name, const std::string form_target)
{
	typedef	AForm*	(*Formcreator)(const std::string&);
	
	std::string form[] =
	{
		"Shrubbery Creation",
		"Robotomy Request",
		"Presidential Pardon"
	};

	Formcreator creator[] =
	{
		&Shrubberycreator,
		&Robotomycreator,
		&Pardoncreator
	};
	
	for (int i = 0; i < 3; i++)
	{
		if (form[i] == form_name)
		{
			std::cout << "Inter creates: " << form_name << std::endl;
			return (creator[i](form_target));
		}
	}
	
	std::cout << "Error: Inter cannot create: "<< form_name << ", because it doesn't exist" << std::endl;
	return NULL;
}

/*

lo acabo de hacer mejor

AForm	*Intern::makeForm(const std::string form_name, const std::string form_target)
{
	int 			i = 0;
	std::string 	Forms[] = {"Shrubbery Creation", "Robotomy Request", "Presidential Pardon"};

	while (i < 3 && Forms[i] != form_name)
		i++;
		
	switch (i)
	{
		case 0:
			std::cout << "Intern create form named: "<< form_name << std::endl;
			return (new ShrubberyCreationForm(form_target));

		case 1:
			std::cout << "Intern create form named: "<< form_name << std::endl;
			return (new RobotomyRequestForm(form_target));

		case 2:
			std::cout << "Intern create form named: "<< form_name << std::endl;
			return (new PresidentialPardonForm(form_target));
			
		default:
			std::cout << "The form mentioned: \" "<< form_name <<" \" does not exist" << std::endl;
			return NULL;		
	}
}
	*/