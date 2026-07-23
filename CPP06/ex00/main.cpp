/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 18:04:42 by antuel            #+#    #+#             */
/*   Updated: 2026/07/23 16:44:42 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main()
{
	/*if (ac == 1)
	{
		std::cout 	<< 	"A string is necessary\n" 
							<< "exemple: char: 'a', int: 42, float: 42.5f, double 42.2"
							<< std::endl;
		return 0;
	}*/

	ScalarConverter::convert("0");
	std::cout << std::endl;
	ScalarConverter::convert("42");
	std::cout << std::endl;
    ScalarConverter::convert("42.0f");
	std::cout << std::endl;
    ScalarConverter::convert("'a'");
	std::cout << std::endl;
    ScalarConverter::convert("nan");
	
	std::cout << std::endl;
	ScalarConverter::convert("dfasfasfd adsf 15531sda");
    return 0;

}