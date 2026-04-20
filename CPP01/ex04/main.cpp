/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 15:40:27 by antuel            #+#    #+#             */
/*   Updated: 2026/04/20 22:39:10 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int main(int ac, char **av)
{
	if (ac != 4)
		return (std::cout << "Invalid format!\nformat need: [file] [search text] [replace text]" << std::endl, 1);

	Replace file(av[1], av[2], av[3]);
	

	if(std::string(av[1]).empty() || std::string(av[2]).empty() || std::string(av[3]).empty())
		return (std::cout << "Error: empty string" << std::endl, 1);
	
	std::string content = file.readFile();
	std::string result = file.replaceall(content);

	file.writeFile(result);

	return (0);
}