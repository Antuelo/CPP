/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 00:51:12 by antuel            #+#    #+#             */
/*   Updated: 2026/04/18 01:22:25 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>
# include "HumanA.hpp"
# include "HumanB.hpp"

class Weapon
{
	private:
		std::string	type;

	public:
		Weapon(std::string type);
		const std::string&	getType() const;
		void				setType(std::string newType);
};

#endif