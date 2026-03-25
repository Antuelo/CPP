#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contacts.hpp"

class PhoneBook
{
private:

    Contact contacts[8];
    int index;
    int total_contacts;

public:
	PhoneBook();
	
    void addContact();
    void searchContact();
};

#endif