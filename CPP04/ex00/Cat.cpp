/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 16:14:57 by antuel            #+#    #+#             */
/*   Updated: 2026/05/24 20:05:48 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.hpp"

Cat::Cat() : Animal("Default-Cat")
{
	std::cout << "MIAAUUU DEFAULT constructor called" << std::endl;
}

Cat::Cat(const Cat& copy) : Animal(copy)
{
	std::cout << "MIAAAUU COPY constructor called" << std::endl;
}

Cat::Cat(std::string type) : Animal(type)
{
	std::cout << "MIIIAAUUU PARAMETER constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "MIIAAAUU Destructor called" << std::endl;
}

//----------operator

Cat& Cat::operator=(const Cat &other)
{
	if (this != &other)
		this->_type = other._type;
	return *this;
}

void Cat::makeSound()const
{
	std::cout << "Miauuuuuu !" << std::endl;
}