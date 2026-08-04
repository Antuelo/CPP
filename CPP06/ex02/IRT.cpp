/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IRT.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 16:32:34 by antuel            #+#    #+#             */
/*   Updated: 2026/08/03 11:38:22 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IRT.hpp"

Base::~Base(){}

//take a base object and make a objet A, B or C
Base* generate()
{	
	int		num = std::rand() % 3 + 1;

	if (num == 1)
		return new A();
	else if (num == 2)
		return new B();
	else
		return new C();
}

//take a pointer and retourn if it's A, B or C object
void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if( dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
		//isn't A
	}
	try
	{
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
		return;
	}
	catch(const std::exception& e)
	{
		//Isn't B
	}
	std::cout << "C" << std::endl;
}