/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 18:04:42 by antuel            #+#    #+#             */
/*   Updated: 2026/07/23 17:30:28 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout 	<< 	"A string is necessary\n" 
							<< "exemple: char: 'a', int: 42, float: 42.5f, double 42.2"
							<< std::endl;
		return 1;
	}
	
	std::string input = av[1];

	ScalarConverter::convert(input);
	std::cout << std::endl;

    return 0;
}