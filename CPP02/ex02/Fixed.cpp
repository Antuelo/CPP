/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 12:18:31 by antuel            #+#    #+#             */
/*   Updated: 2026/05/05 18:49:22 by antuel           ###   ########.fr       */
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

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	_raw_bits = num * (1 << _fractional_bits);
}

Fixed::Fixed(const float real)
{
	std::cout << "Float constructor called" << std::endl;
	_raw_bits = roundf(real * (1 << _fractional_bits));
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

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return os;
}


		// Comparison Operators

bool Fixed::operator>(const Fixed& fixed)const
{
	return (this->toFloat() > fixed.toFloat());
}

bool Fixed::operator>=(const Fixed& fixed)const
{
	return (this->toFloat() >= fixed.toFloat());
}

bool Fixed::operator<(const Fixed& fixed)const
{
	return (this->toFloat() < fixed.toFloat());
}

bool Fixed::operator<=(const Fixed& fixed)const
{
	return (this->toFloat() <= fixed.toFloat());
}

bool Fixed::operator==(const Fixed& fixed)const
{
	return (this->toFloat() == fixed.toFloat());
}

bool Fixed::operator!=(const Fixed& fixed)const
{
	return (this->toFloat() != fixed.toFloat());
}


		// Arithmetic Operators
		
float Fixed::operator+(const Fixed &oper)const
{
	return (this->toFloat() + oper.toFloat());	
}

float Fixed::operator-(const Fixed &oper)const
{
	return (this->toFloat() - oper.toFloat());	
}

float Fixed::operator/(const Fixed &oper)const
{
	return (this->toFloat() / oper.toFloat());	
}

float Fixed::operator*(const Fixed &oper)const
{
	return (this->toFloat() * oper.toFloat());	
}


		// pre-increment Operators



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

float Fixed::toFloat()const
{
	return ((float)_raw_bits / (1 << _fractional_bits));
}

int Fixed::toInt()const
{
	return (_raw_bits / (1 << _fractional_bits));
}