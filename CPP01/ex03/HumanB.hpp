#ifndef HUMANB_HBB
#define HUMANB_HBB

#include <string>
#include <iostream>

class Weapon;

class HumanB
{
	private:
		std::string	name;
		Weapon*		weapon;

	public:
		HumanB(std::string name);
		void		setWeapon(Weapon& weapon);
		void		attack() const;
};

#endif //HUMANB_HBB
