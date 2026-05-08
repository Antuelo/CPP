/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 12:18:31 by antuel            #+#    #+#             */
/*   Updated: 2026/05/08 13:12:09 by anoviedo         ###   ########.fr       */
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

Fixed Fixed::operator+(const Fixed &other)const
{
	Fixed result;
	result.setRawBits(this->_raw_bits + other._raw_bits);
	return (result);
}

Fixed Fixed::operator-(const Fixed &other)const
{
	Fixed result;
	result.setRawBits(this->_raw_bits - other._raw_bits);
	return (result);
}

Fixed Fixed::operator*(const Fixed &other)const
{
	return (Fixed(toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other)const
{
	if  (other.getRawBits() == 0)
		return(perror("Error: division by zero"), Fixed(0));
    return (Fixed(toFloat() / other.toFloat()));
}

		// pre-increment Operators

Fixed Fixed::operator++()
{
	++this->_raw_bits;
	return (*this);
}

Fixed Fixed::operator--()
{
	--this->_raw_bits;
	return(*this);
}

		// Overloaded post-increment Operators

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	++_raw_bits;
	return temp;
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	--_raw_bits;
	return temp;
}

		//Overload MAX & MIN

const Fixed &Fixed::min(const &Fixed &a, const &Fixed &b)
{
	if (a < b)
		return (a);
	else
		return (b);
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

float Fixed::toFloat()const
{
	return ((float)_raw_bits / (1 << _fractional_bits));
}

int Fixed::toInt()const
{
	return (_raw_bits / (1 << _fractional_bits));
}
