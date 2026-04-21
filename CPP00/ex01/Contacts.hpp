/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 10:14:47 by antuel            #+#    #+#             */
/*   Updated: 2026/04/21 14:24:04 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>
# include <iomanip>

class Contact
{
private:

    std::string _first_name;
    std::string _last_name;
    std::string _nickname;
    std::string _phone_number;
    std::string _darkest_secret;

public:
	Contact();

    void setContact(const std::string& first,
					const std::string& last,
					const std::string& nick,
					const std::string& phone,
					const std::string& secret);

    void displayContact() const;
    void displayShort() const;

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
};

#endif
