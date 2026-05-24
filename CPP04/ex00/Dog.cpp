/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 16:17:52 by antuel            #+#    #+#             */
/*   Updated: 2026/05/24 19:45:00 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.hpp"

Dog::Dog() : Animal("Default-Dog")
{
	std::cout << "BOUOOFFF Dog DEFAULT constructor called" << std::endl;
}

Dog::Dog(const Dog& copy) : Animal (copy._type)
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
