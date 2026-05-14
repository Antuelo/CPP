/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 16:52:04 by antuel            #+#    #+#             */
/*   Updated: 2026/05/14 18:57:58 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) 
    : _name(name), _hit_points(10), _attack_damage(0), _energy_points(10)
{
    std::cout << "ClapTrap to " << name << " constructed" << std::endl;
}

void ClapTrap::takeDamage(unsigned int damage)
{
	_hit_points -= damage;
	if (_hit_points < 0)
	{
		_hit_points = 0;
		std::cout << _name << " has no more health :( hit_points: " << _hit_points << std::endl;
	}
	else
		std::cout << _name <<" only has " << _hit_points << " health points :O" << std::endl;
}

void ClapTrap::beRepaired(unsigned int mount)
{
	if (_hit_points <= 0 || _energy_points <= 0)
	{
		std::cout << "Insufficient number of hit_points or energy_points for BE REPAIRED" << std::endl;
		return ;
	}
	else if (mount == 0)
	{
		std::cout << "Error: the repair must be greater than 0" << std::endl;
		return ;
	}
	_energy_points--;
	std::cout << "Will be repaired: " << _hit_points << " with: " << mount <<std::endl;
	_hit_points += mount;
	std::cout << "total Health now: " << _hit_points <<std::endl;
}


void ClapTrap::attack(const std::string &target)
{
	if (_hit_points <= 0 || _energy_points <= 0)
	{
		std::cout << "Insufficient number of hit_points or energy_points for ATTACK" << std::endl;
		return ;
	}
	
	std::cout << _name << " Attack with " << target << " causing " << _attack_damage << " points of damage!" << std::endl;
	_energy_points--;
	
}