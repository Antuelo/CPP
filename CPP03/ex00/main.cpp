/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 16:34:38 by antuel            #+#    #+#             */
/*   Updated: 2026/05/14 19:31:36 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap player1("Michel");
    ClapTrap player2("Jackson");
    
    player1.attack("ennemi");
    
    player2.takeDamage(3);
    
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