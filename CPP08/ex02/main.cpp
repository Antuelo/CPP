/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 12:58:24 by antuel            #+#    #+#             */
/*   Updated: 2026/08/24 22:16:30 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	
	std::cout << "The Top to stack is: " << mstack.top() << std::endl;
	
	std::cout << "The stack size is: " << mstack.size() << std::endl;
	std::cout << "We delete one number" << std::endl;
	mstack.pop();
	
	std::cout << "Now the size is: ";
	std::cout << mstack.size() << std::endl;
	
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	++it;
	--it;

	std::cout << "\nWe print the final list with iterators: " << std::endl;
	while (it != ite)
	{
		std::cout << *it;
		if (ite - 1 != it)
			std::cout << " - ";
		++it;
	}
	std::cout << std::endl;
	
	std::stack<int> s(mstack);
	return 0;
}