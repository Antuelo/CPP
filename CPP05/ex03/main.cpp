/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 11:03:08 by antuel            #+#    #+#             */
/*   Updated: 2026/07/10 18:57:04 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main()
{
    try
	{
		Bureaucrat 	TheBoss("Rockefeler", 1);
		Intern		NoOneInTheWorld;

		AForm *Form1 = NoOneInTheWorld.makeForm("Shrubbery Creation", "DisneyWorld");
		std::cout << std::endl;
		AForm *Form2 = NoOneInTheWorld.makeForm("Robotomy Request", "Other place");
		std::cout << std::endl;
		AForm *Form3 = NoOneInTheWorld.makeForm("Presidential Pardon", "The God");
		std::cout << std::endl;

		AForm *Form42 = NoOneInTheWorld.makeForm("This Form not exist of course hahaha", "Why are you laughing?");

		if (Form1)
		{
			TheBoss.signForm(*Form1);
			TheBoss.executeForm(*Form1);
			delete Form1;
		}
		if (Form2)
		{
			TheBoss.signForm(*Form2);
			TheBoss.executeForm(*Form2);
			delete Form2;
		}
		if (Form3)
		{
			TheBoss.signForm(*Form3);
			TheBoss.executeForm(*Form3);
			delete Form3;
		}
		if (!Form42)
			std::cout << std::endl;
		//FORM4 IS NULL MY BROTHER isn t necessary delete him ... of course
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}