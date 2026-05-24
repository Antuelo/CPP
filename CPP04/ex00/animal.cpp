/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 15:57:49 by antuel            #+#    #+#             */
/*   Updated: 2026/05/24 19:48:52 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.hpp"

//default constructor: default animal
Animal::Animal() : _type("Default-animal")
{
	std::cout << "Animal DEFAULT constructor called" << std::endl;
}

//copy constructor: type = copy de animal
Animal::Animal(const Animal& copy) : _type(copy._type)
{
	std::cout << "Animal COPY constructor called" << std::endl;
}

//constructor with parameter: _type= parameter type
Animal::Animal(std::string type) : _type(type)
{
	std::cout << "Animal PARAMETER constructor called" << std::endl;
}

//default destructor
Animal::~Animal()
{
	std::cout << "Animal Destructor called" << std::endl;
}


//Methods

void Animal::makeSound() const
{
	std::cout << "Animal Sound: asdfjaoeifhé" << std::endl;
}

Animal& Animal::operator=(const Animal &other)
{
	std::cout << "Operator \\= called" << std::endl;
	if (this != &copy)
		_type = copy._type;
	return *this;
}

std::string Animal::getType()const
{
	return _type;
}

std::ostream& operator<<(std::ostream &os, const Animal &obj)
{
	os << obj.getType();
	return os;
}