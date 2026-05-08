/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 11:53:23 by antuel            #+#    #+#             */
/*   Updated: 2026/05/08 18:21:05 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//void randomChump(std::string name);
//Zombie* newZombie(std::string name);


int main(void)
{
    std::cout << "=== STACK ZOMBIE ===" << std::endl;
	randomChump("Zaz");

    std::cout << "\n=== HEAP ZOMBIE ===" << std::endl;
	std::cout << "the immortal heap zombie come !" << std::endl;
	Zombie* heapzombie = newZombie("Highlander");
	heapzombie->announce();

	std::cout << "\n=== DELLETING HEAP ZOMBIE ===" << std::endl;
	delete heapzombie;

    std::cout << "\n=== PROGRAM END ===" << std::endl;
	return (0);
}
