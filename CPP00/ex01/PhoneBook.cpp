/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 10:51:22 by antuel            #+#    #+#             */
/*   Updated: 2026/03/25 10:09:30 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

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
	std::cout << "     Index|First Name| Last Name|  Nickname\n";
	int i = 0;
	while (i < total_contacts)
	{
		std::cout << std::setw(10) << i << "|";
		contacts[i].displayShort();
		i++;
	}
}