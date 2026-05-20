/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 11:53:23 by antuel            #+#    #+#             */
/*   Updated: 2026/05/20 09:47:19 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	//N zombies
    int N = 12;

	std::cout << "the horde of " << N << " attack! run away !!!!" << std::endl;
	Zombie *horde = zombieHorde(N, "Michale Jackson");

	for (int i = 0; i < N; i++)
	{
		horde[i].announce();
	}
	delete[] horde;
	std::cout << "\nthe zombies are dead ... again\n" << std::endl;
	return (0);
}