/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 00:30:33 by antuel            #+#    #+#             */
/*   Updated: 2026/08/22 11:45:08 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	srand(time(NULL));
	
	{//VECTOR TRY
		std::cout << "TEST WITH VECTOR" << std::endl;
		Span sp = Span(5);
		
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		
		
		//printlist
		sp.print_vec();
		sp.print_sorted_vec();
		
		std::cout << "The short
est Span is: " << sp.shortestSpan() << std::endl;
		std::cout << "The longest Span is:  " << sp.longestSpan() << std::endl;

		std::cout << "\n\nNow with a vector to 10000 random numbers, between 0 and 1000000000" << std::endl;
		
		Span sp2 = Span(10000);
		for (int i = 0; i < 10000; i++)
			sp2.addNumber(rand() % 1000000000 + 1);
		
		std::cout << "The shortest Span is: " << sp2.shortestSpan() << std::endl;
		std::cout << "The longest Span is:  " << sp2.longestSpan() << std::endl;
	}

    // TEST 2: List
    std::cout << "\nTEST WITH LIST"  << std::endl;
    {
        std::list<unsigned int> lst;
        for (int i = 0; i < 10000; i++)
            lst.push_back(rand() % 1000000000 + 1);
        
        Span sp(10000);
        sp.addRange(lst.begin(), lst.end());
        
        std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest:  " << sp.longestSpan() << std::endl;
    }
    
    // TEST 3: Deque
    std::cout << "\nTEST WITH DEQUE" << std::endl;
    {
        std::deque<unsigned int> dq;
        for (int i = 0; i < 10000; i++)
            dq.push_back(rand() % 1000000000 + 1);
        
        Span sp(10000);
        sp.addRange(dq.begin(), dq.end());
        
        std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest:  " << sp.longestSpan() << std::endl;
    }
    
    // TEST 4: Array C-style 
    std::cout << "\nTEST WITH C ARRAY" << std::endl;
    {
        int arr[10000];
        for (int i = 0; i < 10000; i++)
            arr[i] = rand() % 1000000000 + 1;
        
        Span sp(10000);
        sp.addRange(arr, arr + 10000);
        
        std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest:  " << sp.longestSpan() << std::endl;
    }
	
	return 0;
}