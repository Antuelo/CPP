/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 10:51:22 by antuel            #+#    #+#             */
/*   Updated: 2026/04/21 13:47:28 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>

PhoneBook::PhoneBook()
{
	index = 0;
	total_contacts = 0;
}

void PhoneBook::addContact()
{
	std::string first, last, nick, phone, secret;

	std::cout << "First name: ";
	std::getline(std::cin, first);
	if (first.empty())
	{
		std::cout << "Error: empty field\n";
		return;
	}

	std::cout << "Last name: ";
	std::getline(std::cin, last);
	if (last.empty())
	{
		std::cout << "Error: empty field\n";
		return;
	}

	std::cout << "Nickname: ";
	std::getline(std::cin, nick);
	if (nick.empty())
	{
		std::cout << "Error: empty field\n";
		return;
	}

	std::cout << "Phone number: ";
	std::getline(std::cin, phone);
	if (phone.empty())
	{
		std::cout << "Error: empty field\n";
		return;
	}

	std::cout << "Your darkest secret: ";
	std::getline(std::cin, secret);
	if (secret.empty())
	{
		std::cout << "Error: empty field\n";
		return;
	}

	contacts[index].setContact(first, last, nick, phone, secret);

	index = (index + 1) % 8;

	if (total_contacts < 8)
		total_contacts++;

	std::cout << "Contact saved\n";
}

void PhoneBook::searchContact()
{
	if (total_contacts == 0)
	{
		std::cout << "No contacts\n";
		return;
	}

	std::cout << "\n     Index|First Name| Last Name|  Nickname\n";
	int i = 0;
	while (i < total_contacts)
	{
		std::cout << std::setw(10) << i << "|";
		contacts[i].displayShort();
		i++;
	}

	std::string number_index;
	std::cout << "\n\nGet the number index (leave empty to exit): ";
	std::getline(std::cin, number_index);
	if (number_index.empty())
	{
		std::cout << std::endl;
		return;
	}
	else
	{
		if (!std::isdigit(number_index[0]) || number_index.length() != 1)
			{
				std::cout << "Error: not digit or index number" << std::endl;
				return;
			}
	}
	int conversion = std::atoi(number_index.c_str());
	if (conversion < 0 || conversion >= total_contacts)
	{
		std::cout << "Error: That index number does not exist" << std::endl;
		return;
	}
	else
	{
		std::cout << std::endl;
		contacts[conversion].displayContact();
		std::cout << std::endl;
	}
}
