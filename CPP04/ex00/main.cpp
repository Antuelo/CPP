/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 15:24:45 by antuel            #+#    #+#             */
/*   Updated: 2026/05/26 10:16:26 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.hpp"
#include "WrongAnimal.hpp"

/*int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	
	return 0;
}*/

int main()
{
	{
		//defaul
		const Animal *bestiole = new Animal();
		//copy
		const Animal *autrebestiole = new Animal(*bestiole);
		//inherits (with parameter made in the children class)
		const Animal *gato = new Cat();
		const Animal *perro = new Dog();

		std::cout << "el gato es: a " << gato->getType() << std::endl;
		std::cout << "el perro es: a " << perro->getType() << std::endl;
		//methods
		std::cout << "the cat say: ";
		gato->makeSound();
		std::cout << "The dog say: ";
		perro->makeSound();

		std::cout << "An animal makes a strange sound: ";
		bestiole->makeSound();

		std::cout << "An other strange animal copy the strange animal: ";
		autrebestiole->makeSound();
		
		delete bestiole;
		delete autrebestiole;
		delete gato;
		delete perro;
	}
	//wrong animals examples
	{
		std::cout << "\n-------------- Wrong animal time ----------------------\n" << std::endl;
		const WrongAnimal 	*strange 				= new WrongAnimal();
		const WrongAnimal	*this_is_a_wrongCat 	= new WrongCat();

		std::cout << "A strange cat say: ";
		this_is_a_wrongCat->makeSound();
		
		std::cout << "so ... a wrong animal say: ";
		strange->makeSound();

		delete strange;
		delete this_is_a_wrongCat;
	}
	return (0);
}