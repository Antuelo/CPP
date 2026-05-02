/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 12:18:31 by antuel            #+#    #+#             */
/*   Updated: 2026/05/02 16:50:20 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//constructors

Fixed::Fixed () : _raw_bits (0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_raw_bits = copy._raw_bits;
}


//destructor

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

//operators

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_raw_bits = other._raw_bits;

	return *this;
}

//methods

int Fixed::getRawBits()const
{
	std::cout << "getRawBits member function called" << std::endl;

	return (this->_raw_bits);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;

	this->_raw_bits = raw;	
}