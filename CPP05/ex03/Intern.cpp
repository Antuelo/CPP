/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 16:01:48 by antuel            #+#    #+#             */
/*   Updated: 2026/07/10 18:55:17 by antuel           ###   ########.fr       */
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