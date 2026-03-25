/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 10:14:47 by antuel            #+#    #+#             */
/*   Updated: 2026/03/23 19:10:19 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>
# include <iomanip> 
/*	The '&' means the parameter is passed by reference 
	(no copy is made):						 !here
		    void setContact(const std::string& firt, ...)
*/
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