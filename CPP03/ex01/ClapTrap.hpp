#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
	protected:
		std::string 			_name;
		int		 				_hit_points;
		int						_attack_damage;
		int 					_energy_points;
		
	
	public:
		ClapTrap();
		ClapTrap(const ClapTrap &other);
		ClapTrap(std::string name);

		virtual ~ClapTrap();
	
		ClapTrap& operator=(const ClapTrap &other);

	void 	attack(const std::string &target);
	void 	takeDamage(int amount);
	void 	beRepaired(int amount);

	int		get_hitpoints()const;
	int		get_energypoints()const;
};

#endif //CLAPTRAP_HPP
