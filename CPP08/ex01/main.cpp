/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 00:30:33 by antuel            #+#    #+#             */
/*   Updated: 2026/08/21 14:07:48 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	Span sp = Span(5);
	
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	
	//printlist
	for(std::vector<unsigned int>::iterator it = sp.begin(); it != sp.end(); it++)
	{
		std::cout << *it;
		if (it + 1 != sp.end())
			std::cout << " - ";
	}
	std::cout << "\n" <<std::endl;

	sp.print_sorted_vec();
	
	std::cout << "The shortest Span is: " << sp.shortestSpan() << std::endl;
	std::cout << "The longest Span is:  " << sp.longestSpan() << std::endl;
	return 0;
}