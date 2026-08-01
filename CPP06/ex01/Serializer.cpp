/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 11:22:46 by antuel            #+#    #+#             */
/*   Updated: 2026/08/01 12:21:35 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{}

Serializer::Serializer(const Serializer &copy)
{
	if (&copy)
		*this = copy;
}

Serializer::~Serializer()
{}

Serializer &Serializer::operator=(const Serializer &other)
{
	(void)other;
	return (*this);
}

uintptr_t Serializer::serialize (Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}