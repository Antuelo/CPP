/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 11:01:28 by antuel            #+#    #+#             */
/*   Updated: 2026/08/15 16:22:25 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

int main()
{
	try
	{
		std::cout << "VECTOR" << std::endl;
		std::vector<int> 				vec;
		std::vector<int>::iterator		it = vec.begin();
	
		for (int i = 1; i <= 10; i++)
			vec.push_back(i);
			
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

// ------------------------------------- LA MEME CHOSE AVEC LIST -----------------
	
	try
	{
		std::cout << "\n\nNow with list:" << std::endl;
		
		std::list<int> 				vec;
		std::list<int>::iterator 	it = vec.begin();

		for(int i = 20; i <= 62; i++)
			vec.push_back(i);

		std::cout << "Priting list:" << std::endl;
		
		unsigned int count = 0;
		for(it = vec.begin(); it != vec.end(); it++)
		{
			std::cout << *it;
			if (count++ < vec.size() - 1)
				std::cout << " - ";
		}
		

		std::cout << "\n\nSearching nuber (42)";
		it = easyfind(vec, 42);
		std::cout << "Found! the number is: " << *it << "\n" << std::endl;
		
		std::cout << "Searching number (5): ";
		it = easyfind(vec, 5);
	}
	catch(const NotFound& e)
	{
		std::cerr << e.what() << '\n';
	}
	
//----------------------------------DEQUE VECTOR ---------------------
	
	try
	{
		std::cout << "\n\nDeque!" << std::endl;
		
		std::deque<int>				vec;
		std::deque<int>::iterator 	it = vec.begin();
		
		for (int i = 1; i <= 10; i++)
			vec.push_back(i);

		std::cout << "Priting list:" << std::endl;
		for(it = vec.begin(); it < vec.end(); it++)
		{
			std::cout << *it;
			if (it != vec.end() - 1)
				std::cout << " - ";
		}

		std::cout << "\n\nSearching number (4)" << std::endl;
		it = easyfind(vec, 4);
		std::cout << "Found! the number is: " << *it << std::endl;

		std::cout << "\nSearching number (323)" << std::endl;
		it = easyfind(vec, 323);
	}
	catch(const NotFound& e)
	{
		std::cerr << e.what() << '\n';
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



ASSOCIATIVE CONTAINERS:
std::map<int, std::string>  	//  Tiene pares clave-valor
std::set<int>               	//  Almacena solo claves
std::multiset<int>          	//  
std::unordered_map<int, int> 	//

// VECTOR:  acceso rápido O(1), bueno al final, malo en medio
// LIST:    inserciones rápidas O(1) en cualquier lado, acceso lento O(n)
// DEQUE:   rápido en ambos extremos, parecido a vector en medio
*/