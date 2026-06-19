/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 11:03:08 by antuel            #+#    #+#             */
/*   Updated: 2026/06/19 10:57:28 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try 
	{
		std::cout << std::endl;
		Bureaucrat		Agent = Bureaucrat("Roberto", 5);
		std::cout << Agent << std::endl;
		Agent.incrementGrade();
		std::cout << "Grade up!\nThe new grade is: " << Agent.getGrade() <<std::endl;
			Agent.incrementGrade();
		std::cout << "Grade up again!\nThe new grade is: " << Agent <<std::endl;
		Agent.decrementGrade();
		std::cout << "Grade Down!\nThe new grade is: " << Agent <<std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() <<std::endl;
	}
		
	try 
	{
		std::cout << std::endl;
		std::cout << "Trying to make a President with grade -1:" << std::endl;
		Bureaucrat		President = Bureaucrat("Anonimus", -1);
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}	
	

	try
	{
		std::cout << std::endl;
		std::cout << "Traying to make a Trash with grade 170" << std::endl;
		Bureaucrat 		Trash = 	Bureaucrat("Anithing", 170);
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}

	

	try
	{
		std::cout << std::endl;
		std::cout << "Trying to make a default user (grade 150)" << std::endl;
		Bureaucrat 		the_default;
		std::cout << "\nTrying to down default user level: " << std::endl;
		the_default.decrementGrade();
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	

	//LAST EXAMPLE
	std::cout << std::endl;
	Bureaucrat	*last_exemple = NULL;
	
	try
	{
		std::cout << "----------THE LAST EXEMPLE------------" << std::endl;
		last_exemple = new Bureaucrat("Agent", 8);
		std::cout << "We are created: " << *last_exemple << std::endl;
		std::cout << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	//NOW... MODIFICATIONS!
	if (last_exemple)
	{
	
		try
		{
			std::cout << "Decrement grade just 1 time" << std::endl;
			last_exemple->decrementGrade();
			std::cout << *last_exemple << std::endl;
			std::cout << std::endl;
		}
		catch (const Bureaucrat::GradeTooLowException &error)
		{
			std::cout << error.what() << std::endl;
		}
		catch (const Bureaucrat::GradeTooHighException &error)
		{
			std::cout << error.what() << std::endl;
		}

		try
		{
			std::cout << "Increment grade 6 times!" << std::endl;
			for(int i = 0; i < 6; i++)
			{
				last_exemple->incrementGrade();
				std::cout << *last_exemple << std::endl;
			}
			std::cout << std::endl;
		}
		catch (const Bureaucrat::GradeTooHighException &error)
		{
			std::cout << error.what() << std::endl;			
		}
	}	
		
	std::cout << "\nThe last grade: "<< *last_exemple << "\n" << std::endl;
	
	if (last_exemple)
		delete last_exemple;

	return 0;
}