/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 16:52:06 by antuel            #+#    #+#             */
/*   Updated: 2026/08/21 18:47:10 by antuel           ###   ########.fr       */
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

void Span::addNumber(unsigned int num)
{
	if (_vec.size() < _max_size)
		_vec.push_back(num);
	else
		throw NotMoreSpace();
}


unsigned int Span::longestSpan()
{
	if (this->_vec.size() < 2)
		throw unsifficentNumbers();
		
	std::vector<unsigned int>::iterator max_it = std::max_element(_vec.begin(), _vec.end());
	std::vector<unsigned int>::iterator min_it = std::min_element(_vec.begin(), _vec.end());
	
	unsigned int max = *max_it;
	unsigned int min = *min_it;
	
	return max - min;
}

unsigned int Span::shortestSpan()
{
	if (_vec.size() < 2)
		throw unsifficentNumbers();

	//copy vec + ranger 
	std::vector<unsigned int> copy_vec = _vec;
	std::sort(copy_vec.begin(),copy_vec.end());

	//une chiffre grand pour comparer (le dernier = le plus grand de la liste)
	std::vector<unsigned int>::iterator it = copy_vec.end();
	unsigned int MIN = UINT_MAX;

	unsigned int dif = 0;
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
	std::vector<unsigned int>		copy_vec = _vec;
	
	std::cout << "The vector is: ";
	for(unsigned int i = 0; i < copy_vec.size(); i++)
	{
		std::cout << copy_vec[i];

		if (copy_vec.size() - 1 != i)
			std::cout << "-";
	}
	
	std::cout << std::endl;
}


void Span::print_sorted_vec() const
{
	std::vector<unsigned int>		copy_vec = _vec;

	std::sort(copy_vec.begin(), copy_vec.end());
	
	std::cout << "The sorted vector is: ";
	for(unsigned int i = 0; i < copy_vec.size(); i++)
	{
		std::cout << copy_vec[i];

		if (copy_vec.size() - 1 != i)
			std::cout << " - ";
	}
	
	std::cout << std::endl;
}