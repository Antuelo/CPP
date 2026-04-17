#ifndef HUMANB_HBB
#define HUMANB_HBB

#include "Weapon.hpp"

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
