#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(const ScavTrap &copy);
		ScavTrap(std::string name);

		virtual ~ScavTrap();

		ScavTrap& operator=(const ScavTrap &other);

		void guardGate();
		void attack(const std::string &target);
};

#endif //SCAVTRAP_HPP
