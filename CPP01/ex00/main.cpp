/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 11:53:23 by antuel            #+#    #+#             */
/*   Updated: 2026/03/28 15:45:20 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void randomChump(std::string name);
Zombie* newZombie(std::string name);


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