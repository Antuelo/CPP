/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 19:11:17 by antuel            #+#    #+#             */
/*   Updated: 2026/04/21 11:26:03 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contacts.hpp"
#include <iostream>
#include <iomanip>

std::string Contact::getFirstName() const
{
    return _first_name;
}

std::string Contact::getLastName() const
{
    return _last_name;
}

std::string Contact::getNickname() const
{
    return _nickname;
}

Contact::Contact() {}
void	Contact::setContact(const std::string& first,
							const std::string& last,
							const std::string& nick,
							const std::string& phone,
							const std::string& secret)
{
	_first_name = first;
	_last_name = last;
	_nickname = nick;
	_phone_number = phone;
	_darkest_secret = secret;
}

void Contact::displayContact() const
{
	std::cout << "First name: " << _first_name << std::endl;
	std::cout << "Last name: " << _last_name << std::endl;
	std::cout << "Nickname: " << _nickname << std::endl;
	std::cout << "Phone number: " << _phone_number << std::endl;
	std::cout << "Darkest secret: " << _darkest_secret << std::endl;
}

static std::string formatField(const std::string& str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return str;
}

void Contact::displayShort() const
{
    std::cout << std::setw(10) << formatField(_first_name) << "|";
    std::cout << std::setw(10) << formatField(_last_name) << "|";
    std::cout << std::setw(10) << formatField(_nickname) << std::endl;
}
