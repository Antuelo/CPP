/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 16:14:57 by antuel            #+#    #+#             */
/*   Updated: 2026/06/01 22:22:31 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "MIAAUUU DEFAULT constructor called" << std::endl;
	_cat_brain = new Brain();
}

Cat::Cat(const Cat& copy) : Animal(copy)
{
	std::cout << "MIAAAUU COPY constructor called" << std::endl;
	_cat_brain = new Brain(*copy._cat_brain);
}

Cat::Cat(std::string type) : Animal(type)
{
	std::cout << "MIIIAAUUU PARAMETER constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "MIIAAAUU Destructor called" << std::endl;
	delete _cat_brain;
}

//----------operator

Cat& Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		*_cat_brain = *other._cat_brain;
	}
	return *this;
}

void Cat::makeSound()const
{
	std::cout << "Miauuuuuu !" << std::endl;
}