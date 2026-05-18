/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 18:38:41 by antuel            #+#    #+#             */
/*   Updated: 2026/05/18 11:56:05 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

//CONSTRUCTOR
FragTrap::FragTrap() : ClapTrap("default constructor")
{
	_hit_points = 		100;
	_energy_points = 	100;
	_attack_damage = 	30;

	std::cout << " DEEEEEEEEEEEFFFAAAUUUUULT !!! FragTrap CONSTRUCTED" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "THEEEE COOOOPY FragTrap constructor IS CALLED :O" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hit_points = 		100;
	_energy_points = 	100;
	_attack_damage = 	30;

	std::cout << "CHAN CHAN CHAAAAAAAAAAAAAAN !!! FragTrap " << name << " CONSTRUCTED" << std::endl;
}

//DESTRUCTOR
FragTrap::~FragTrap()
{
	std::cout << " BOOOOOOOM! FragTrap DESTRUCTEEEEEEEEEEEEEDDDDD" << std::endl;
}

//OPERATOR
FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
		ClapTrap::operator=(other);
		
	return *this;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << _name << " says: High fives everyone!!" << std::endl;
}

