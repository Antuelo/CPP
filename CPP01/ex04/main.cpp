/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 15:40:27 by antuel            #+#    #+#             */
/*   Updated: 2026/04/19 16:08:02 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int ac, char **av)
{
	if (ac != 4)
		return (std::cout << "Invalid format!\nformat need: [file] [search text] [replace text]" << std::endl, 1);

}