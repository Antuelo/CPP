/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 13:25:01 by antuel            #+#    #+#             */
/*   Updated: 2026/05/18 11:39:38 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

//CONSTRUCTORS
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
	std::cout << "ScavTrap " << name << " constructed" << std::endl;
}

//constr - default
ScavTrap::ScavTrap() : ClapTrap("default-ScavTrap")
{
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
    std::cout << "Default ScavTrap constructed" << std::endl;	
}

//constr - copy
ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
    std::cout << "ScavTrap copy constructor" << std::endl;
}


//DESTRUCTOR
ScavTrap::~ScavTrap()
{
    std::cout << "Destruction de ScavTrap: " << _name << std::endl;
}

//OPERATOR
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
		ClapTrap::operator=(other);	
	
	return *this;
}

//METHODS
void ScavTrap::attack(const std::string &target)
{
    if (_hit_points <= 0 || _energy_points <= 0)
    {
        if (_hit_points == 0)
            std::cout << "ScavTrap " << _name << " is dead and cannot act!" << std::endl;
        else
            std::cout << "ScavTrap " << _name << " has no energy points for ATTACK" << std::endl;
        return;
    }
    
    _energy_points--;
    std::cout << "ScavTrap " << _name << " attacks " << target 
              << ", causing " << _attack_damage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
	if (_hit_points <= 0)
		return ;

    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode!" << std::endl;
}