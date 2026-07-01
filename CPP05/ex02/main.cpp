/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 11:03:08 by antuel            #+#    #+#             */
/*   Updated: 2026/06/30 17:34:28 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat Pedro("Pedro", 25);
		Form BossForm("Boss form", 30, 30);
		std::cout << std::endl;
		std::cout << Pedro << std::endl;
		std::cout << BossForm << std::endl;
	
		//Pedro can sing it!
		Pedro.signForm(BossForm);
		std::cout << BossForm << std::endl;
		
		//Pedro can't sign it... this is for a president
		Form PresidentForm("President Form", 1, 1);
		Pedro.signForm(PresidentForm);
		std::cout << PresidentForm << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	//now I will try create a bad form
	try
	{
		//I will try not more because it finish here
		Form BadForm("Bad Form", 180, 5);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	try
	{
		Form BadForm2("other bad form", 5, -325);
	}
	catch (const std::exception &error)
	{
		std::cout << error.what() << std::endl;
	}
	
	std::cout << std::endl;
	try
	{
		Form OneMoreBadForm("lala", -5, 10);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return 0;	
}