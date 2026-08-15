#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <exception>

class NotFound : public std::exception
{	
	public: virtual const char* what() const throw()
	{
		return ("Value not found in the container");
	}
};

template<typename T>
typename T::iterator easyfind(T& container, const int num)
{
	typename T::iterator it = std::find(container.begin(), container.end(), num);

	if (it != container.end())
		return it;

	throw NotFound();
}

#endif


