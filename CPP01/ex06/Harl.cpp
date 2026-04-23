/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:49:09 by antuel            #+#    #+#             */
/*   Updated: 2026/04/23 10:52:18 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"


void Harl::debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info()
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t putenough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming foryears, whereas you started working here just last month." << std::endl;
}

void Harl::error()
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

/*
void Harl::complain(std::string level)
{
	typedef void (Harl::*t_func)(void);
	std::string text [4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	t_func actions[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int i = 0;
	while (i < 4)
	{
		if (level == text[i])
			break;
		i++;
	}
	switch (i)
	{
	case 0:
		(this->*actions[0])();
		std::cout << std::endl;
		//fall through
	case 1:
		(this->*actions[1])();
		std::cout << std::endl;
		//fall through
	case 2:
		(this->*actions[2])();
		std::cout << std::endl;
		//fall through
	case 3:
	{	
		(this->*actions[3])();
		std::cout << std::endl;
		break;
	}
	default:
		std::cout << "\n[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	}
}*/

void Harl::complain(std::string level)
{
	std::string text [4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;
	while (i < 4)
	{
		if (level == text[i])
			break;
		i++;
	}
	switch (i)
	{
	case 0:
		debug();
		std::cout << std::endl;
		/* fall through */
		
	case 1:
		info();
		std::cout << std::endl;
		/* fall through */
		
	case 2:
		warning();
		std::cout << std::endl;
		/* fall through */
		
	case 3:	
		error();
		std::cout << std::endl;
		break;

	default:
		std::cout << "\n[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	}
}
