/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 16:17:52 by antuel            #+#    #+#             */
/*   Updated: 2026/05/24 20:05:38 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.hpp"

Dog::Dog() : Animal("Default-Dog")
{
	std::cout << "BOUOOFFF Dog DEFAULT constructor called" << std::endl;
}

Dog::Dog(const Dog& copy) : Animal (copy)
{
	std::cout << "BOUOOFFF COPY constructor called" << std::endl;
}

Dog::Dog(std::string type) : Animal(type)
{
	std::cout << "BOUOOFF PARAMETER constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "BOUOOOFFF Destructor called" << std::endl;
}

//------methods and operators

Dog& Dog::operator=(const Dog &other)
{
	if (this != &other)
		_type = other._type;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Ouaf ouaf !" << std::endl;
}