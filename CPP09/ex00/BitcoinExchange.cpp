/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 15:44:27 by antuel            #+#    #+#             */
/*   Updated: 2026/08/30 17:18:38 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
BitcoinExchange::BitcoinExchange()
{
	load_database();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	if (this != &copy)
		_data = copy._data;
}

BitcoinExchange::~BitcoinExchange()
{}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		_data = other._data;

	return *this;
}



void BitcoinExchange::load_database()
{
	std::ifstream file("data.csv");
	if (!file.is_open())
	{
		std::cout << "Problem opening file in load_databasse" << std::endl;
		return;
	}
	
	std::string line;
	std::getline(file, line);					//sauter la premier ligne (titre)

	while(std::getline(file,line))
	{
		size_t		commaPos = line.find(',');
		if (commaPos == std::string::npos)
			continue;							//je saute la ligne... si pas de virgule, le format est incorrect

		std::string Date = line.substr(0, commaPos);
		std::string PriceSTR = line.substr(commaPos + 1); // +1, je saute la virgule


		float price = strtof(PriceSTR.c_str(), NULL);

		_data[Date] = price;					//je garde finalement dans map
	}
}