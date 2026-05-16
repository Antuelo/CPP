#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
	protected:
		std::string 			_name;
		int 			_hit_points;
		int 			_energy_points;
		int			_attack_damage;
		
	
	public:
		ClapTrap(std::string name);

		virtual ~ClapTrap(){std::cout << "Destruction de ClapTrap: " << _name << std::endl;};

	void 	attack(const std::string &target);
	void 	takeDamage(int amount);
	void 	beRepaired(int amount);

	int		get_hitpoints()const;
	int		get_energypoints()const;
};

#endif //CLAPTRAP_HPP
