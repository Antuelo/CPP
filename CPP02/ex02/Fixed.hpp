#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int 				_raw_bits;
		static  const int 	_fractional_bits = 8;

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
		Fixed operator++();
		Fixed operator--();
		// post-increment Operators
		Fixed operator++(int);
		Fixed operator--(int);

		~Fixed();
		
		int 	getRawBits(void) const;
		void 	setRawBits(int const raw);
		float 	toFloat(void) const;
		int 	toInt( void ) const;
};

/*Add public member functions to your class to overload the following operators:
•The 6 comparison operators: >, <, >=, <=, ==, and !=.
•The 4 arithmetic operators: +, -, *, and /.
•The 4 increment/decrement (pre-increment and post-increment, pre-decrement and
post-decrement) operators, which will increase or decrease the fixed-point value by
the smallest representable ε, such that 1 + ε > 1.*/


std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif