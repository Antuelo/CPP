/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 18:24:12 by antuel            #+#    #+#             */
/*   Updated: 2026/07/27 23:06:09 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cctype>
#include <iomanip>
#include <limits>
#include <limits.h>
#include <cerrno>
#include <cstdlib> //strtol, strtof, strtod
 
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
    if (param == "+inf" || param == "+inff" || param == "inf" || param == "inff")
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
	//std::cout << "Error type: "<< e << std::endl;
	
	//CHAR
	if (charError == 'c')
    	std::cout << "char: impossible" << std::endl;
	else if (isprint(c))
    	std::cout << "char: '" << c << "'" << std::endl;
	else
    	std::cout << "char: Non displayable" << std::endl;

	//INT
	if (e != 'i' && e != 'f' && e != 'd')
		std::cout << "int: " << i << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	
	//FLOAT
	if (e != 'f' && e != 'd')	
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	else
		std::cout << "float: impossible" << std::endl;

	//DOUBLE
	if (e != 'd')	
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
	else
		std::cout << "double: impossible" << std::endl;
}

void	convertion(std::string param, std::string type)
{
//	std::cout << type << std::endl;
	
	char 	e = '\0';//e= error \0= default
	char 	charE = '\0';

	//CHAR
	if  (type == "char")
	{
		char c = param[1];
        printConversions(c, static_cast<int>(c), static_cast<float>(c), static_cast<double>(c), e, charE);		
	}
	//INT & DOUBLE
	else if (type == "int" || type == "double")
	{
		char *end;
		errno = 0;

		float f = strtof(param.c_str(), NULL);
		if (f < INT_MIN || f > INT_MAX)
			e = 'i';
		if (errno == ERANGE || *end != '\0')
			e = 'f';		
		
		errno = 0;
		double d = strtod(param.c_str(), &end);
		
		if (errno == ERANGE || *end != '\0')
			e = 'd';
		
		if (d < std::numeric_limits<char>::min() || 
			d > std::numeric_limits<char>::max())
				charE = 'c';
		
		printConversions(static_cast<char>(d), static_cast<int>(d), f, d, e, charE);
		return ;
	}
	//FLOAT
	else if (type == "float")
	{
		char *end;
		errno = 0;
		float f = strtof(param.c_str(), &end);

		if (f < INT_MIN || f > INT_MAX)
		{
			e = 'i';
			if (errno == ERANGE && *end != '\0')
			{
					e = 'f';
			}
		}
		errno = 0;
    	double d = strtod(param.c_str(), NULL);
		if (errno == ERANGE)
			e = 'd'; 
		
		if (f < std::numeric_limits<char>::min() || 
			f > std::numeric_limits<char>::max())
				charE = 'c';

		printConversions(static_cast<char>(f), static_cast<int>(f), f, d, e, charE);
	}
}

void ScalarConverter::convert(std::string param)
{
	int 			length = param.length() - 1;
	bool			onlyNumbers = false;
	int				points = 0;
	int 			i = 0;
	
	if (param[0] == '-' || param[0] == '+')
		i++;
	

	while (i <= length)
	{
		if (isdigit(param[i]) || param[i] == '.')
			onlyNumbers = true;
		else
		{
			onlyNumbers = false;
			break;
		}
			
		if (param[i] == '.')
		{
			points++;
			if (points > 1 || (i < length && !isdigit(param[i+1]) && param[i+1] != 'f'))
			{
				onlyNumbers = false;
				break;
			}
		}
		
		i++;
		
		if (param[i] == 'f' && i == length)
		{
			onlyNumbers = true;
			break;
		}
	}
	
	if (param == "")
	{
		std::cout << "empty entry" << std::endl;
		return ;
	}
	
	else if (param.length() == 3 && param[0] == '\'' && param[2] == '\'')					//char
		return convertion(param, "char");
		
	else if (param[length] == 'f' && (points == 1 || points == 0)&& onlyNumbers == true)	//float
		return convertion(param, "float");
		
	else if (points == 1 && onlyNumbers)													//double
		return convertion(param, "double");
		
	else if (onlyNumbers && points == 0)													//int
		return convertion(param, "int");
		
	else if (param == "nan" || param == "nanf" || param == "-inf" || param == "+inf" ||
        param == "-inff" || param == "+inff" || param == "inf" || param == "inff" )
    {
        handleSpecialCases(param);
        return;
    }
	else
		std::cout 	<< "Your entry isn't literal in its most common form!\nex char: \"\'a\'\"\n"
					<< "int: 34 or \"5\" ... etc" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;	
	return *this;
}