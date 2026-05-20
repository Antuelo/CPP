#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
	private:
		std::string 	_name;
		int 			_hit_points;
		int				_attack_damage;
		int 			_energy_points;


	public:
		//const
		ClapTrap();
		ClapTrap(const ClapTrap &other);
		ClapTrap(std::string name);
		//destr
		~ClapTrap();

		//oper
		ClapTrap& operator=(const ClapTrap &other);

		//method
	void 	attack(const std::string &target);
	void 	takeDamage(unsigned int amount);
	void 	beRepaired(unsigned int amount);

	int		get_hitpoints()const;
	int		get_energypoints()const;
};

#endif //CLAPTRAP_HPP
