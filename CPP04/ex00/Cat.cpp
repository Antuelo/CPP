/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 16:14:57 by antuel            #+#    #+#             */
/*   Updated: 2026/05/24 16:22:37 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.hpp"

Cat::Cat()
{
	std::cout << "MIAAUUU DEFAULT constructor called" << std::endl;
}

Cat::Cat(const Cat& copy)
{
	std::cout << "MIAAAUU COPY constructor called" << std::endl;
}

Cat::Cat(std::string type)
{
	std::cout << "MIIIAAUUU PARAMETER constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "MIIAAAUU Destructor called" << std::endl;
}
