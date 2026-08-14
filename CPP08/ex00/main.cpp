/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 11:01:28 by antuel            #+#    #+#             */
/*   Updated: 2026/08/07 20:42:08 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <ctime>

int main()
{
	std::vector<int> 			vec;
	std::vector<int>::iterator 	it;
	
	for (int i = 1; i <= 10; i++)
		vec.push_back(i);

	try
	{
		std::cout << "Priting list:" << std::endl;
		for (it = vec.begin(); it != vec.end(); it++)
		{
			std::cout << *it;
			if (it != vec.end() - 1)
				std::cout << " - ";
		}
		
		std::cout << "\n\nSearching number (5)... ";
		it = easyfind(vec, 5);
		std::cout << "Found! is: " << *it << "\n" <<std::endl;
		
		std::cout << "Searching number (42)...";
		it = easyfind(vec, 42);
	}
	catch (const NotFound& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}


/*

vec.size();           	¿Cuántos tengo?
vec.empty();          	¿Está vacío?
vec.clear();          	Borrar todo
vec.insert(pos, 99);  	Insertar en una posición
vec.erase(pos);       	Eliminar de una posición
vec.push_back(30)		Inserta "30" AL FINAL DEL VECTOR

*/