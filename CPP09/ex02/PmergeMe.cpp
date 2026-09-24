/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 13:17:43 by antuel            #+#    #+#             */
/*   Updated: 2026/09/24 12:10:01 by antuel           ###   ########.fr       */
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
	
	for (int i = 1; i < ac; i++)
	{
		std::string 	str = av[i];
		if (str.empty())
		{
			std::cerr << "Error: empty argument" << std::endl;
			return false;
		}
				
		for (int j = 0; j < (int)str.length(); j++) // correction de chaque caractère
		{
			if (std::isdigit(static_cast<unsigned char>(str[j]))) //hago cast para las letras con tilde que pueden ser negativas = undefined behavior
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
	
	_original = _vector;
	return true;
}

//insertion de vectores
void PmergeMe::_insertionSortDeque(std::deque<int> &deque, int left, int right)
{
	int		key = 0;
	int		j 	= 0;
	
	for(int i = left + 1; i <= right; i++)
	{
		key = deque[i];
		j 	= i - 1;

		while (j >= left && deque[j] > key)
		{
			deque[j + 1] = deque[j];
			j--;
		}
		deque[j + 1] = key;
	}
}

void PmergeMe::_insertionSortVector(std::vector<int> &vec, int left, int right)
{
	int		key = 0;
	int 		j 	= 0;

	for (int i = left + 1; i <= right; i++)
	{
		key = vec[i];
		j 	= i - 1;

		while (j >= left && vec[j] > key)
		{
			vec[j + 1] = vec[j];
			j--;
		}
		vec[j + 1] = key;
	}
}

void	PmergeMe::_mergeSortDeque(std::deque<int> &deque, int left, int midle, int right)
{
	std::deque<int> copy_left	(deque.begin() + left, deque.begin() + midle + 1	);
	std::deque<int> copy_right	(deque.begin() + midle + 1, deque.begin() + right + 1);

	int 	 index_left = 0;
	int		 index_right = 0;
	int 	 index_container = left;

	while (index_left < (int)copy_left.size() && index_right < (int)copy_right.size())
	{
		if (copy_left[index_left] <= copy_right[index_right])
		{
			deque[index_container] = copy_left[index_left];
			index_left++;
		}
		else
		{
			deque[index_container] = copy_right[index_right];
			index_right++;
		}
		index_container++;
	}

	//copier ce qui reste
	while (index_left < (int)copy_left.size())
	{
		deque[index_container] = copy_left[index_left];
		index_left++;
		index_container++;
	}

	while(index_right < (int)copy_right.size())
	{
		deque[index_container] = copy_right[index_right];
		index_right++;
		index_container++;
	}
}


void PmergeMe::_mergeSortVector(std::vector<int> &vector, int left, int midle, int right)
{
	std::vector<int> copy_left (vector.begin() + left, vector.begin() + midle + 1);
	std::vector<int> copy_rigth(vector.begin() + midle + 1, vector.begin() + right + 1);

	int 	index_left = 0;
	int 	index_right = 0;
	int		index_container = left;

	while(index_left < (int)copy_left.size() && index_right < (int)copy_rigth.size())
	{
		if (copy_left[index_left] <= copy_rigth[index_right])
		{
			vector[index_container] = copy_left[index_left];
			index_left++;
		}
		else
		{
			vector[index_container] = copy_rigth[index_right];
			index_right++;
		}
		index_container++;
	}
	
	while (index_left < (int)copy_left.size())
	{
		vector[index_container] = copy_left[index_left];
		index_container++;
		index_left++;
	}

	while (index_right < (int)copy_rigth.size())
	{
		vector[index_container] = copy_rigth[index_right];
		index_container++;
		index_right++;
	}	
}