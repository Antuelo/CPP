/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 16:52:06 by antuel            #+#    #+#             */
/*   Updated: 2026/08/15 18:11:28 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <vector>
#include <list>
#include <deque>

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
