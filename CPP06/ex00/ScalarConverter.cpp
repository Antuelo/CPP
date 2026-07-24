/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 18:24:12 by antuel            #+#    #+#             */
/*   Updated: 2026/07/24 15:39:23 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cctype>
#include <algorithm>
#include <iomanip>
#include <limits>
#include <limits.h>
#include <cerrno>
#include <cstdlib>

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	*this = copy;
}

ScalarConverter::~ScalarConverter()
{}

void handleSpecialCases(const std::string& param)
{
    // Para nan y nanf
    if (param == "nan" || param == "nanf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return;
    }

    // Para -inf y -inff
    if (param == "-inf" || param == "-inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
        return;
    }

    // Para +inf y +inff
    if (param == "+inf" || param == "+inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
        return;
    }
}

void printConversions(char c, int i, float f, double d, char e, char charError)
{
	if (charError == 'c')
    	std::cout << "char: impossible" << std::endl;
	else if (isprint(c))
    	std::cout << "char: '" << c << "'" << std::endl;
	else
    	std::cout << "char: Non displayable" << std::endl;

	if (e != 'i')
		std::cout << "int: " << i << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
		
	if (e != 'f')	
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	else
		std::cout << "float: impossible" << std::endl;

	if (e != 'd')	
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
	else
		std::cout << "double: impossible" << std::endl;
}

void	convertion(std::string param, std::string type)
{
	char 	e = '\0';//e= error \0= default
	char 	charE = '\0';

	if  (type == "char")
	{
		char c = param[1];
        printConversions(c, static_cast<int>(c), static_cast<float>(c), static_cast<double>(c), e, charE);		
	}
	else if (type == "int")
	{
		char *end;
		errno = 0;
		long int i = strtol(param.c_str(), &end, 10);
		
		if (errno == ERANGE || *end != '\0' || i < INT_MIN || i > INT_MAX)
			e = 'i';//i = int
		if (i < std::numeric_limits<char>::min() || 
			i > std::numeric_limits<char>::max())
				charE = 'c';
		
		printConversions(static_cast<char>(i), static_cast<int>(i), static_cast<float>(i), static_cast<double>(i), e, charE);
	}
	else if (type == "float")
	{
		char *end;
		errno = 0;
		float f = strtof(param.c_str(), &end);
		
		if (errno == ERANGE || *end != '\0')
		{
			if (*end != 'f')
				e = 'f';
		}
		
		if (f < std::numeric_limits<char>::min() || 
			f > std::numeric_limits<char>::max())
				charE = 'c';
		
		printConversions(static_cast<char>(f), static_cast<int>(f), f, static_cast<double>(f), e, charE);
	}	
	else //double
	{
		char *end;
		errno = 0;
		double d = strtod(param.c_str(), &end);
		
		if (errno == ERANGE || *end != '\0')
			e = 'd';

		if (d < std::numeric_limits<char>::min() || 
			d > std::numeric_limits<char>::max())
				charE = 'c';
		
		printConversions(static_cast<char>(d), static_cast<int>(d), static_cast<float>(d), d, e, charE);
		return ; //float 	
	}	
}

void ScalarConverter::convert(std::string param)
{
	int 	length = param.length() - 1;
	bool	onlyNumbers = true;
	int 	i = 0;
	
	if (param[0] == '-' || param[0] == '+')
		i++;
	
	while(i < length + 1)
	{
		if (param[i] < '0' || param[i] > '9')
		{
			onlyNumbers = false;
			break;
		}
		i++;
	}
	
	
	if (param == "")
		return ;
	else if (param.length() == 3 && param[0] == '\'' && param[2] == '\'')	//char
		return convertion(param, "char");
		
	else if (param[length] == 'f' && param.find('.') != std::string::npos)	//float
		return convertion(param, "float");
		
	else if (param.find('.') != std::string::npos)							//double
		return convertion(param, "double");
		
	else if (onlyNumbers)													//int
		return convertion(param, "int");
		
	else if (param == "nan" || param == "nanf" || param == "-inf" || param == "+inf" ||
        param == "-inff" || param == "+inff")
    {
        handleSpecialCases(param);
        return;
    }
	else
		std::cout << "Your entry isn't literal in its most common form" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;	
	return *this;
}