#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int 				_raw_bits;
		static  const int 	_fractional_bits = 8;

	public:
		Fixed();
		Fixed(const Fixed &copy);

		Fixed& operator=(const Fixed &other);
	
		~Fixed();
		
		int getRawBits(void) const;

		void setRawBits(int const raw);
};

#endif