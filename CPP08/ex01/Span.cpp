/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 16:52:06 by antuel            #+#    #+#             */
/*   Updated: 2026/08/24 09:24:37 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#define DEFAULT 700

Span::Span():
	_vec(),
	_max_size(DEFAULT)
{}

Span::Span(const Span& copy)
{
	*this = copy;
}

Span::Span(unsigned int N):
	_vec(),
	_max_size(N)
{}

Span::~Span()
{}

Span &Span::operator=(const Span& copy)
{
	if (this != &copy)
	{
		this->_max_size = copy._max_size;
		this->_vec 		= copy._vec;
	}
	return *this;
}

void Span::addNumber(int num)
{
	if (_vec.size() < static_cast<std::size_t>(_max_size))
		_vec.push_back(num);
	else
		throw NotMoreSpace();
}


int Span::longestSpan()
{
	if (this->_vec.size() < 2)
		throw unsifficentNumbers();
		
	std::vector<int>::iterator max_it = std::max_element(_vec.begin(), _vec.end());
	std::vector<int>::iterator min_it = std::min_element(_vec.begin(), _vec.end());
	
	int max = *max_it;
	int min = *min_it;
	
	return max - min;
}

int Span::shortestSpan()
{
	if (_vec.size() < 2)
		throw unsifficentNumbers();

	//copy vec + ranger 
	std::vector<int> copy_vec = _vec;
	std::sort(copy_vec.begin(),copy_vec.end());

	//une chiffre grand pour comparer (le dernier = le plus grand de la liste)
	std::vector<int>::iterator it = copy_vec.end();
	int MIN = INT_MAX;

	int dif = 0;
	for(it = copy_vec.begin(); it != copy_vec.end(); it++)
	{
		if (it + 1 != copy_vec.end())
			dif = *(it + 1) - *it;
			
		if (dif < MIN)
			MIN = dif;
	}

	return MIN;
}

void Span::print_vec() const
{
	std::vector<int>		copy_vec = _vec;
	
	std::cout << "The vector is: ";
	for(std::size_t i = 0; i < copy_vec.size(); i++)
	{
		std::cout << copy_vec[i];

		if (i != copy_vec.size() - 1)
			std::cout << "-";
	}
	
	std::cout << std::endl;
}


void Span::print_sorted_vec() const
{
	std::vector<int>		copy_vec = _vec;

	std::sort(copy_vec.begin(), copy_vec.end());
	
	std::cout << "The sorted vector is: ";
	for(std::size_t i = 0; i < copy_vec.size(); i++)
	{
		std::cout << copy_vec[i];

		if (i != copy_vec.size() - 1)
			std::cout << " - ";
	}
	
	std::cout << std::endl;
}