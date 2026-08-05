#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array
{
	private:
		T*			_array;
		size_t		_size;

	public:
		Array()						: _array(NULL), _size(0)		{}
		Array(unsigned int n)		: _array(new T[n]()), _size(n)	{}
		Array(const Array& Copy)	: _array(NULL), _size(0)		{*this = Copy;}

		~Array();

			Array& 	operator=(const Array& other)
			{
				if (this != &other)
					delete[] _array;

				if (other.size > 0)
				{
					
				}
			}

			T&		operator[](unsigned int index);
	const	T&		operator[](unsigned int index) const;

		size_t	size() const;
};


#endif //ARRAY_HPP
