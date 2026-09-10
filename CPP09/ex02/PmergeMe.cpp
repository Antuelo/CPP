/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 13:17:43 by antuel            #+#    #+#             */
/*   Updated: 2026/09/10 15:09:19 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe &copy):
	_vector(copy._vector),
	_deque(copy._deque)
{}

PmergeMe::~PmergeMe()
{}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_vector = other._vector;
		_deque 	= other._deque;
	}

	return *this;
}

//--------------------------------------------------ça commence

bool	PmergeMe::parseInput(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Error: need at least one number" << std::endl;
		return false;
	}
	
	long 	num = 0;
	
	for (size_t i = 1; i < ac; i++)
	{
		std::string 	str = av[i];
		if (str.empty())
		{
			std::cerr << "Error: empty argument" << std::endl;
			return false;
		}
				
		for (size_t j = 0; j < str.length(); j++) // correction de chaque caractère
		{
			if (std::isdigit(str[j]))
				continue;
			std::cerr << "Error: invalid character, only numbers are accepted" << std::endl;
			return false;
		}
		
		char *end;
		num = std::strtol(str.c_str(), &end, 10);
		if (*end != '\0')
		{
			std::cerr << "Error: converion strtol" << std::endl;
			return false;
		}
		if( num > 2147483647)
		{
			std::cerr << "Error: number too long" << std::endl;
			return false;
		}

		if (num <= 0)
		{
			std::cerr << "Error: Negative or null numbers are not allowed." << std::endl;
			return false;
		}

		_vector.push_back(num);
		_deque.push_back(num);
	}
	return true;
}