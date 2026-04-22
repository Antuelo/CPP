/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:06:23 by anoviedo          #+#    #+#             */
/*   Updated: 2026/04/21 14:22:46 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	PhoneBook pb;
	std::string cmd;

	while (true)
	{
		std::cout << "Enter command: ";
		if (!std::getline(std::cin, cmd))
		{
			std::cout << "\nGood bye" <<std::endl;
			break ;
		}
    	if  (cmd == "ADD")
			pb.addContact();
		else if (cmd == "SEARCH")
			pb.searchContact();
		else if (cmd == "EXIT")
			break;
	}
	return(0);
}
