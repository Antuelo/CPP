/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 18:55:55 by antuel            #+#    #+#             */
/*   Updated: 2026/04/23 10:34:21 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl 			harl;
	std::string 	level;

	if (ac == 1)
		return (0);
	else
		level = av[1];

	std::cout << std::endl;
	harl.complain(level);
	return(0);
}
