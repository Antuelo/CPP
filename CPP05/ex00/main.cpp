/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 11:03:08 by antuel            #+#    #+#             */
/*   Updated: 2026/06/16 23:30:56 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try 
	{
		std::cout << std::endl;
		Bureaucrat		Agent = 	Bureaucrat("Roberto", 5);
		std::cout << "the actual grade is: "<< Agent.getGrade() << std::endl;
		Agent.incrementGrade();
		std::cout << "Grade up!\nThe new grade is: " << Agent.getGrade() <<std::endl;
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

	
	
	return 0;
}