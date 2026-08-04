/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 18:04:51 by antuel            #+#    #+#             */
/*   Updated: 2026/08/03 16:06:26 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() 
{
	Data*				pointer = new(Data);
	long long int		number = 0;
	Data*				result;

	pointer->name = "The number ONE";
	pointer->id = 1;

	std::cout << "NUMBER is now: " << number << std::endl;
    std::cout << "\n" <<pointer->name << " is of course the number: " << pointer->id <<std::endl;

	number = Serializer::serialize(pointer);
	
	std::cout << "\nNow NUMBER is: " << number << "\nThis NUMBER became result(a Data struct)..." << std::endl;

	result = Serializer::deserialize(number);

	if (result)
	{
			std::cout << "\nLook ! is the same pointer!" << std::endl;
			std::cout << "pointer= " <<pointer << " = " << result << " =result"<<std::endl;
			std::cout << std::endl;		

		
		std::cout << "Now result is: "<< result->name << ", and his number is: "<< result->id << std::endl;
		delete result;
	}	
	
	return 0;
}

