/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 11:37:35 by antuel            #+#    #+#             */
/*   Updated: 2026/08/05 12:02:01 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <string>
#include <limits.h>

template <typename T>
void 	print(const T& p){std::cout << p << std::endl;}

void 	increment(int& x)
{
	if (x <= INT_MAX)
		x++;
	else
		std::cout << "incrementation impossible" << std::endl;
}

void 	decrement(int& x)
{
	if (x >= INT_MIN)
		x--;
	else
		std::cout << "decrementation impossible" << std::endl;
}

void 	OneMoreZero(int& x){x = x * 10;}


void	printASCII(char& c)
{
	if (isprint(c))
	{
		std::cout << "This char: " << c << ", is ASCII number: "<< static_cast<int>(c) << std::endl;
	}
	else
		std::cout << "Error: Impossible to print this char: " << c << ", as a number"<< std::endl;
}

int main()
{
	int intArray[] = { 1, -4, 123, 560, 879895};
	std::cout << "Int Test:" << std::endl;	
	iter(intArray, 5, print);

	std::cout << "\nIncrement:\n";
	iter(intArray, 5, increment);
	iter(intArray, 5, print);

	std::cout << "\nDecrement:\n";
	iter(intArray, 5, decrement);
	iter(intArray, 5, print);

	std::cout << "\nOne More Zero\n";
	iter(intArray, 5, OneMoreZero);
	iter(intArray, 5, print);
	std::cout << std::endl;
	
	std::cout << "-------------------------------\n" << std::endl;
	
	char charArray[] = {'A', 'h', '5', '@', '+'};
	std::cout << "Char Test:\nThe list is:" << std::endl;
	iter(charArray, 5, print);
	std::cout << "\nNow printing in int if its possible: " << std::endl;
	iter(charArray, 5, printASCII);
	
	return 0;
}