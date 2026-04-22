/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 09:06:39 by antuel            #+#    #+#             */
/*   Updated: 2026/04/22 18:43:21 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl harl;
	
	std::cout << "Harl say: \n" << std::endl;

	harl.complain("INFO");
	std::cout << std::endl;

	harl.complain("WARNING");
	std::cout << std::endl;

	harl.complain("DEBUG");
	std::cout << std::endl;
	
	harl.complain("ERROR");
	std::cout << std::endl;

	harl.complain("other thing");
	
	return(0);
}