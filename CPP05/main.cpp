/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 11:03:08 by antuel            #+#    #+#             */
/*   Updated: 2026/06/16 11:42:00 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try 
	{
		std::cout << std::endl;
		Bureaucrat		Aggent = 	Bureaucrat("Roberto", 5);
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
		Bureaucrat 		the_default;
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