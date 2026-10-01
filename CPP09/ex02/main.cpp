/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 13:17:39 by antuel            #+#    #+#             */
/*   Updated: 2026/09/30 21:51:29 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	PmergeMe FordJohnson;
	
	if (!FordJohnson.parseInput(ac, av))
		return 1;

	FordJohnson.sort();
	FordJohnson.printResult();
		
	return 0;
}