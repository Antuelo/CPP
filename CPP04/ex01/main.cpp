/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 15:24:45 by antuel            #+#    #+#             */
/*   Updated: 2026/06/02 15:04:06 by antuel           ###   ########.fr       */
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
	
	std::cout << std::endl;
	std::cout << "copy test time-----------------------\n" << std::endl;
	
	Dog *Perro = new Dog();
	Dog *Pitbul = new Dog(*Perro);
	
	std::cout << std::endl;
	std::cout << "DESTRUCTION .............>" << std::endl;
	std::cout << std::endl;
	
	delete Perro;
	delete Pitbul;
	
	return 0;
}