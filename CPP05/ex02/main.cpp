/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 11:03:08 by antuel            #+#    #+#             */
/*   Updated: 2026/07/19 17:38:12 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <ctime>
#include <cstdlib>

int main()
{
	srand(time(NULL)); 	// Inicializa el generador de números aleatorios con la hora actual como semil(semilla - Seed)
						//I want say in English ... Seeds the random number generator with the current time
	
	try
    {
		std::cout << "---------- first try --------" << std::endl;
        Bureaucrat b1("Pedro", 20);
        Bureaucrat b2("Zaphod", 1);
        
		std::cout << std::endl;

        ShrubberyCreationForm s("home");
        RobotomyRequestForm r("Bender");
        PresidentialPardonForm p("Arturito");
        
		std::cout << "\nSign and execute forms:\n" << std::endl;
		
        b1.signForm(s);
        b1.executeForm(s);
		b1.executeForm(s);
        b1.executeForm(s);

		b2.executeForm(s);

        
        b2.signForm(r);
        b2.executeForm(r);
        
        b2.signForm(p);
        b2.executeForm(p);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

	//-------------------------------------------------------------

	try
	{
		std::cout << "\n\n--------- second try ROBOTOMY MY REQUEST RANDOM TEST -------------" << std::endl;
		Bureaucrat robot("presi", 1);
		
		RobotomyRequestForm formul("robo-processus");
		
		robot.signForm(formul);
		std::cout << "1)" << std::endl;
		robot.executeForm(formul);
		std::cout << "2)" << std::endl;
		robot.executeForm(formul);
		std::cout << "3)" << std::endl;
		robot.executeForm(formul);
		std::cout << "4)" << std::endl;
		robot.executeForm(formul);
		std::cout << "5)" << std::endl;
		robot.executeForm(formul);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
    return 0;
}