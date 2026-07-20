/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 18:24:12 by antuel            #+#    #+#             */
/*   Updated: 2026/07/19 18:28:27 by antuel           ###   ########.fr       */
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