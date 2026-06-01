/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 15:24:45 by antuel            #+#    #+#             */
/*   Updated: 2026/06/01 22:39:38 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.hpp"
#include "WrongAnimal.hpp"

int main()
{
	const	Animal* j = new Dog();
	const 	Animal* i = new Cat();
	
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	
	delete j;//should not create a leak
	delete i;
	
	Animal *animals[10];
	for(int i = 0; i < 10; i++)
	{
		if (i < 5)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
		delete animals[i];
	
	return 0;
}