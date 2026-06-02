/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 16:17:52 by antuel            #+#    #+#             */
/*   Updated: 2026/06/01 22:27:52 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "BOUOOFFF Dog DEFAULT constructor called" << std::endl;
	_dog_brain = new Brain();
}

Dog::Dog(const Dog& copy) : Animal (copy)
{
	std::cout << "BOUOOFFF COPY constructor called" << std::endl;
	_dog_brain = new Brain(*copy._dog_brain);
}

Dog::Dog(std::string type) : Animal(type)
{
	std::cout << "BOUOOFF PARAMETER constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "BOUOOOFFF Destructor called" << std::endl;
	delete _dog_brain;
}

//------methods and operators

Dog& Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		*_dog_brain = *other._dog_brain;
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Ouaf ouaf !" << std::endl;
}