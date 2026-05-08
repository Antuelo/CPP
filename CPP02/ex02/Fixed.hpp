#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int 					_raw_bits;
		static  const int 		_fractional_bits = 8;

	public:
		Fixed();
		Fixed(const Fixed &copy);
		Fixed(const int num);
		Fixed(const float real);


		Fixed& 	operator=(const Fixed& other);
		bool	operator>(const Fixed& fixed)const;
		bool	operator<(const Fixed& fixed)const;
		bool	operator>=(const Fixed& fixed)const;
		bool	operator<=(const Fixed& fixed)const;
		bool	operator==(const Fixed& fixed)const;
		bool	operator!=(const Fixed& fixed)const;

		Fixed	operator+(const Fixed &oper)const;
		Fixed	operator-(const Fixed &oper)const;
		Fixed 	operator/(const Fixed &oper)const;
		Fixed 	operator*(const Fixed &oper)const;

		// pre-increment Operators
		Fixed& operator++();
		Fixed& operator--();
		// post-increment Operators
		Fixed operator++(int);
		Fixed operator--(int);

		//Overload min & max
		static const Fixed		&min(const Fixed& a, const Fixed &b);
		static const Fixed		&max(const Fixed &a, const Fixed &b);
		static Fixed			&min(Fixed &a, Fixed &b);
		static Fixed			&max(Fixed &a, Fixed &b);


		~Fixed();

		int 	getRawBits(void) const;
		void 	setRawBits(int const raw);
		float 	toFloat(void) const;
		int 	toInt( void ) const;
};


/*
Add these four public overloaded member functions to your class:

• A static member function min that takes two references to fixed-point numbers as
parameters, and returns a reference to the smallest one.

• A static member function min that takes two references to constant fixed-point
numbers as parameters, and returns a reference to the smallest one.

• A static member function max that takes two references to fixed-point numbers as
parameters, and returns a reference to the greatest one.

• A static member function max that takes two references to constant fixed-point
numbers as parameters, and returns a reference to the greatest one*/

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif
