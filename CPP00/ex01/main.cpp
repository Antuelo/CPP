#include "PhoneBook.hpp"

int main()
{
	PhoneBook pb;
	std::string cmd;

	while (true)
	{
		std::cout << "Enter command: ";
		std::getline(std::cin, cmd);

    	if  (cmd == "ADD")
			pb.addContact();
		else if (cmd == "SEARCH")
			pb.searchContact();
		else if (cmd == "EXIT")
			break;
	}
	return(0);
}