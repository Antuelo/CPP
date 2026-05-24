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

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal DEFAULT constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy)
{
	std::cout << "WrongAnimal COPY constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
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
	std::cout << "WrongAnimal Sound: asdfjaoeifhé" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &copy)
{
	if (this != &copy)
		_type = copy._type;
	return *this;
}


//----------------------------------------------WrongExemple-------------------------------->


