/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 11:37:35 by antuel            #+#    #+#             */
/*   Updated: 2026/08/04 15:43:30 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <string>

template <typename T>
void 	print(const T& p){std::cout << p << std::endl;}

void 	increment(int& x){x++;}

void 	decrement(int& x){x--;}

void 	OneMoreZero(int& x){x = x * 10;}


void	printNumChar(char& c)
{
	if (isprint(c))
	{
		std::cout << "This char: " << c << ", is number: "<< static_cast<int>(c) << std::endl;
	}
	else
		std::cout << "Error: Impossible to print this char: " << c << ", as a number"<< std::endl;
}

int main()
{
	int intArray[] = { 1, -4, 123, 560.5, 8798765};
	std::cout << "Int Test:" << std::endl;	
	iter(intArray, 5, print);

	std::cout << "Increment: ";
	iter(intArray, 5, increment);
	iter(intArray, 5, print);

	std::cout << "Decrement: ";
	iter(intArray, 5, decrement);
	iter(intArray, 5, print);

	std::cout << "One More Zero";
	iter(intArray, 5, OneMoreZero);
	iter(intArray, 5, print);
	std::cout << std::endl;
	
	std::cout << "-------------------------------\n" << std::endl;
	
	char charArray[] = {'A', 'h', '5', '@', '£'};
	std::cout << "Char Test:\nThe list is: " << std::endl;
	iter(charArray, 5, print);
	std::cout << "Now printing in int if its possible: " << std::endl;
	iter(charArray, 5, printNumChar);
	
	return 0;
}