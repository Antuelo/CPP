/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 18:56:37 by antuel            #+#    #+#             */
/*   Updated: 2026/05/24 19:24:53 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.hpp"
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("Defaul-WrongAnimal")
{
	std::cout << "WrongAnimal DEFAULT constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy) : _type(copy._type)
{
	std::cout << "WrongAnimal COPY constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	std::cout << "WrongAnimal PARAMETER constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor called" << std::endl;
}


//Methods

void WrongAnimal::makeSound() const
{
	std::cout << "allalaallalalala :V" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
		_type = other._type;
	return *this;
}

std::string WrongAnimal::getType()const
{
	return _type;
}

//----------------------------------------------WrongExemple-------------------------------->
//DOG

WrongDog::WrongDog() : WrongAnimal("Default-WrongDog")
{
	std::cout << "BOUOOFFF WrongDog DEFAULT constructor called" << std::endl;
}

WrongDog::WrongDog(const WrongDog& copy) : WrongAnimal (copy)
{
	std::cout << "BOUOOFFF COPY constructor called" << std::endl;
}

WrongDog::WrongDog(std::string type) : WrongAnimal(type)
{
	std::cout << "BOUOOFF PARAMETER constructor called" << std::endl;
}

WrongDog::~WrongDog()
{
	std::cout << "BOUOOOFFF Destructor called" << std::endl;
}

//------methods and operators

WrongDog& WrongDog::operator=(const WrongDog &other)
{
	if (this != &other)
		_type = other._type;
	return *this;
}

void WrongDog::makeSound() const
{
	std::cout << "Ouaf ouaf !" << std::endl;
}

//--------------------------------------------Wront Example-------------------->
//WrongCat


WrongCat::WrongCat() : WrongAnimal("Default-WrongCat")
{
	std::cout << "MIAAUUU DEFAULT constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy)
{
	std::cout << "MIAAAUU COPY constructor called" << std::endl;
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type)
{
	std::cout << "MIIIAAUUU PARAMETER constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "MIIAAAUU Destructor called" << std::endl;
}

//----------operator

WrongCat& WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
		this->_type = other._type;
	return *this;
}

void WrongCat::makeSound()const
{
	std::cout << "Miauuuuuu !" << std::endl;
}

std::ostream& operator<<(std::ostream &os, WrongAnimal &obj)
{
	os << obj.getType();
	return os;
}