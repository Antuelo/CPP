/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 16:52:04 by antuel            #+#    #+#             */
/*   Updated: 2026/05/18 12:03:55 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//CONSTRUCTORS
ClapTrap::ClapTrap(std::string name) 
    : _name(name), _hit_points(10), _attack_damage(0), _energy_points(10)
{
    std::cout << "ClapTrap " << name << " constructed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
}

ClapTrap::ClapTrap() : _name("no-name"), _hit_points(10), _attack_damage(0), _energy_points(10)
{}

//DESTRUCTOR
ClapTrap::~ClapTrap()
{
	std::cout << "Destruction de ClapTrap: " << _name << std::endl;
}

//OPERATORS
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_energy_points = other._energy_points;
		this->_attack_damage = other._attack_damage;
		this->_hit_points = other._hit_points;
	}

	return *this;
}

//METHODS
int ClapTrap::get_hitpoints()const
{
	return(_hit_points);
}

int ClapTrap::get_energypoints()const
{
	return(_energy_points);
}


void ClapTrap::takeDamage(int damage)
{
	if (damage <= 0)
	{
		std::cout << "Error: The attack need be over 0 (zero)" << std::endl;
		return ;
	}
	else if (_hit_points == 0)
	{
		std::cout << "impossible take damage, hit_points is almost 0" << std::endl;
		return ;
	}

	_hit_points -= damage;

	if (_hit_points < 0)
	{
		_hit_points = 0;
		std::cout << _name << " took " << damage << " damage" <<std::endl;
		std::cout << _name << " has no more health :( hit_points: " << _hit_points << std::endl;
	}
	else
	{
		std::cout << _name << " took " << damage << " damage" <<std::endl;
		std::cout << _name <<" only has " << _hit_points << " health points" << std::endl;
	}
}

void ClapTrap::beRepaired(int mount)
{
	if (_hit_points == 0 || _energy_points == 0)
	{
		if (_hit_points == 0)
			std::cout << "Insufficient number of hit_points for BE REPAIRED" << std::endl;
		else
			std::cout << "Insufficient number of energy_points for BE REPAIRED" << std::endl;
		return ;
	}
	else if (mount <= 0)
	{
		std::cout << "Error: the repair must be greater than 0" << std::endl;
		return ;
	}
	
	_energy_points--;
	std::cout << "Adding " << mount << " health points to current " << _hit_points << std::endl;
	
	_hit_points += mount;

	std::cout << "Total health now: " << _hit_points << std::endl;
}
