#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>
#include <exception>

template <typename T>
void iter(T *array, size_t lenght, void (*fonction)(T&))
{
	for (size_t i = 0; i < lenght; i++)
	{
		fonction(array[i]);
	}
}

//FONCTION CONST

template <typename T>
void iter(T *array, size_t lenght, void (*fonction)(const T&))
{
	for (size_t i = 0; i < lenght; i++)
	{
		fonction(array[i]);
	}
}



#endif //ITER_HPP
