/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 11:53:23 by antuel            #+#    #+#             */
/*   Updated: 2026/04/12 18:32:41 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main(void)
{
    int N = 12;
	int i;

	std::cout << "the horde of " << N << " attack! run away !!!!" << std::endl;
	Zombie *horde = zombieHorde(N, "BRAINeater");

	for (i = 0; i < N; i++)
	{
		horde[i].announce();
	}
	delete[] horde;
	std::cout << "\nthe zombies are dead ... again\n" << std::endl;
	return (0);
}