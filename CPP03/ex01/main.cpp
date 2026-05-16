/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 16:34:38 by antuel            #+#    #+#             */
/*   Updated: 2026/05/16 14:29:40 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
    std::cout << "\n=== TEST 1: CREATION ===" << std::endl;
    ScavTrap scav("Robert");
    
    std::cout << "\n=== TEST 2: ATTACK (ScavTrap version) ===" << std::endl;
    scav.attack("target");
    
    std::cout << "\n=== TEST 3: SPECIAL ABILITY ===" << std::endl;
    scav.guardGate();
    
    std::cout << "\n=== TEST 4: TAKE DAMAGE (inherited from ClapTrap) ===" << std::endl;
    scav.takeDamage(30);
    scav.takeDamage(80);  // here I kill him
    
    std::cout << "\n=== TEST 5: BE REPAIRED (inherited from ClapTrap) ===" << std::endl;
    scav.beRepaired(20);
    
    std::cout << "\n=== TEST 6: TRY TO ACT WHEN DEAD ===" << std::endl;
    scav.attack("enemy");
    scav.guardGate();
    
    std::cout << "\n=== TEST 7: MULTIPLE ATTACKS TO DRAIN ENERGY ===" << std::endl;
    ScavTrap scav2("EnergyTest");
    for (int i = 0; i < 52; i++) {
        scav2.attack("training dummy");
		if (scav2.get_hitpoints() == 0 || scav2.get_energypoints() == 0)
		{
			std::cout << "not more energy_points" << std::endl;
			break ;
		}
    }
    
    std::cout << "\n=== TEST 8: DESTRUCTION ===" << std::endl;
    return (0);
}

/*
int main(void)
{
    ClapTrap player1("Michel");
    ClapTrap player2("Jackson");
    
    player1.attack("ennemi");
    
    player2.takeDamage(-3);
    
    player2.beRepaired(5);
    
    for (int i = 0; i < 11; i++)
	{
        player1.attack("sac d'entraînement");
		if (player1.get_energypoints() == 0)
			break;
    }
    
    player1.attack("ennemi");
    
    player2.takeDamage(100);
    player2.beRepaired(10);
    
    player2.attack("ennemi");
    
    return (0);
}
*/

/*
int main(void)
{
	ClapTrap player1("Michael Jackson");
	ClapTrap player2("ta soeur");
	
	player1.attack("singing");
	player2.takeDamage(5);
	
	player2.attack("dancing");
	player1.takeDamage(1);

	player1.attack("dancing and singing");
	player2.takeDamage(15351);
	
	player1.beRepaired(55);

	return (0);
}
*/