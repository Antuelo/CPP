/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 11:26:12 by antuel            #+#    #+#             */
/*   Updated: 2026/06/12 11:45:05 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//default constructror: name(default), grade(150)
Bureaucrat::Bureaucrat() :
	_name("default"),
	_grade(150)
{
	std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) :
	_name(name),
	_grade(grade)
{
	std::cout << "Parameters constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) :
	Bureaucrat(copy)
{
	std::cout << "Copy constructor called" << std::endl;
}

~Bureaucrat::Bureaucrat()
{
	std::cout << "default destructor called" << std::endl;
}