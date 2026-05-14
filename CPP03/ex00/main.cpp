/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 16:34:38 by antuel            #+#    #+#             */
/*   Updated: 2026/05/14 17:02:40 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

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