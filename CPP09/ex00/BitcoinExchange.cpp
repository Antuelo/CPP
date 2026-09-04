/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 15:44:27 by antuel            #+#    #+#             */
/*   Updated: 2026/09/04 18:34:56 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iomanip>


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
		std::cout << "Problem opening file in load_database" << std::endl;
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
			
			
		char		*end;				
		float price = strtof(PriceSTR.c_str(), &end);

		if (end == PriceSTR.c_str() || *end != '\0') //j'ignore si rien est converti ou il y a des caracters en plus
			continue;
		
		_data[Date] = price;					//je garde finalement dans map
	}
}

bool	BitcoinExchange::validationDate(const std::string &date) const
{
	if (date.length() != 10) //la date a seulment 10 caracteres
		return false;
	
	if (date[4] != '-' && date[7] != '-') //position obligatoire de tires
		return false;

	for(int i = 0; i < 10; i++)		// constrol de chifres
	{
		if (i == 4 || i == 7)
			continue;

		if (!std::isdigit(date[i]))
			return false;
	}

	int year = 	atoi(date.substr(0, 4).c_str());
	int month = atoi(date.substr(5, 2).c_str());
	if (month < 1 || month > 12)
		return false;
	int day = 	atoi(date.substr(8, 2).c_str());
	
	int day_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0); //ajouter leap year ... bissextile
    
	if (isLeap && month == 2)
	{
		day_month[1] = 29;
	}
	
	if (day < 1 || day > day_month[month - 1])
	{
		return false;
	}
	
	return true;	
}

bool	BitcoinExchange::Value_valid(float value) const
{
	return (value >= 0 && value <= 1000);
}


float BitcoinExchange::lookingfor_exchangerate(const std::string &date) const
{
    std::map<std::string, float>::const_iterator it = _data.lower_bound(date); //lower bound cherche le >= 
    
    if (it != _data.end() && it->first == date) //date exacte
        return it->second;
    
    if (it == _data.begin()) // il n'y a pas de date anterieure
        throw std::runtime_error("Error: no previous date");
    
    --it;
    return it->second; //date anterieure
}

void BitcoinExchange::processLine(const std::string &line) const
{
	if (line.empty() || line.find_first_not_of(" \t") == std::string::npos) //jump empty spaces
		return;

	size_t pipe = line.find(" | ");
	if (pipe == std::string::npos)
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return;
	}

	std::string date = line.substr(0, pipe);
	std::string valueStr = line.substr(pipe + 3);

	if (!validationDate(date))
	{
		std::cout << "Error: invalid date: "<< date << std::endl;
		return;	
	}
	
	char	*end;
	float	value = strtof(valueStr.c_str(), &end);
	if (*end != '\0')
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return;
	}
	
	if (!Value_valid(value))
	{
		if (value < 0)
			std::cout << "Error: not a positive number" << std::endl;
		else
			std::cout << "Error: too large number" << std::endl;
		return;
	}
	
	try
	{
		float rate = lookingfor_exchangerate(date);
		float result = value * rate;
		std::cout 	<< date << " => "<< value << " = "
					<< std::fixed << std::setprecision(2) << result << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	
}

