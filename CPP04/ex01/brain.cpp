/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 09:50:45 by antuel            #+#    #+#             */
/*   Updated: 2026/06/03 11:35:57 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brain.hpp"

Brain::Brain()
{
	std::cout << "Default BRAIN constructor called" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Copy Brain constructor called" << std::endl;

	*this = copy;
}


Brain::~Brain()
{
	std::cout << "Default Brain Destructor called" << std::endl;
}

Brain& Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (int i=0; i < 100; i++)
			ideas[i] = other.ideas[i];
	}
	return *this;
}
