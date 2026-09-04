/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 15:39:51 by antuel            #+#    #+#             */
/*   Updated: 2026/09/04 18:32:36 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int ac, char** av)
{
	if (ac != 2)
		return (std::cerr << "Error: could not open file." << std::endl, 1);

	std::ifstream file(av[1]);
	if (!file.is_open())
		return (perror("Error: could not open file"), 1);

	BitcoinExchange 	exchange;
	std::string 		line;
	
	std::getline(file, line);
	
	while(std::getline(file, line))
		exchange.processLine(line);

		
	file.close();

	return 0;
}