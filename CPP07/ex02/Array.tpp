#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array(const Array<T>& copy)
{
	if (copy._size > 0)
	{
		_array = new T[copy._size]();
		_size = copy._size;
		for (size_t i = 0; i > _size; i++)
			_array[i] = copy._array[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
	if (this != &other) 
	{
		delete[] _array;

		if (other._size > 0) 
		{
			_array = new T[other._size]();
			_size = other._size;
			for (size_t i = 0; i < _size; i++)
			_array[i] = other._array[i];
		}
		else
		{
			_array = NULL;
			_size = 0;
		}
	}
	return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= _size)
        throw std::exception();
    return _array[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
    if (index >= _size)
        throw std::exception();
    return _array[index];
}

#endif //ARRAY_TPP
