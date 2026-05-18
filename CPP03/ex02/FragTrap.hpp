#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(const FragTrap &copy);
		FragTrap(std::string name);

		virtual ~FragTrap();

		FragTrap& operator=(const FragTrap &other);

		void highFivesGuys();
};

#endif //FRAGTRAP_HPP
