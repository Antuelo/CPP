/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 18:24:12 by antuel            #+#    #+#             */
/*   Updated: 2026/07/21 14:35:29 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	if (&copy)
		*this = copy;
}

ScalarConverter::~ScalarConverter()
{}

void ScalarConverter::convert(std::string param)
{
	int length = 0;

	length = param.length();
	
	if (param == "")
		return ;
	else if (param.length() == 3 && param[0] == '\'' && param[2] == '\'')
		return ;//es char
	else if (param[length] == 'f' && param.find('.') != std::string::npos && param[0] != '.')
		return ;//es un float
	else if (param[length] == 'f')
		return ;//es double
	else
		return ;//es int
}
