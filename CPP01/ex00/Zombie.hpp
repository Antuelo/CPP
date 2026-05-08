/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 11:53:32 by antuel            #+#    #+#             */
/*   Updated: 2026/05/08 18:21:30 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
private:
	std::string _name;
public:
	Zombie(std::string name);

	~Zombie();

	void announce() const;
};

void randomChump(std::string name);
Zombie* newZombie(std::string name);

#endif //ZOMBIE_HPP
