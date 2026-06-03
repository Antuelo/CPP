/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 15:24:45 by antuel            #+#    #+#             */
/*   Updated: 2026/06/03 11:40:52 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.hpp"
#include "WrongAnimal.hpp"

/*commented because the Animal's class is abstract, so ... not possible to utilise*/
int main()
{

		//defaul
		//const Animal *bestiole = new Animal();
		//copy
		//const Animal *autrebestiole = new Animal(*bestiole);
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

//		std::cout << "An animal makes a strange sound: ";
//		bestiole->makeSound();

//		std::cout << "An other strange animal copy the strange animal: ";
//		autrebestiole->makeSound();

//		delete bestiole;
//		delete autrebestiole;
		delete gato;
		delete perro;

	return (0);
}
