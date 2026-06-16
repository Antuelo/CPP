/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 11:26:12 by antuel            #+#    #+#             */
/*   Updated: 2026/06/16 23:34:04 by antuel           ###   ########.fr       */
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
	_name(name)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade = grade;
			
	std::cout << "Parameters constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) :
	_name(copy._name),
	_grade(copy._grade)
{
	std::cout << "Copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "default destructor called" << std::endl;
}

//exceptions

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too High !!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too Low !!");
}

//getters

int Bureaucrat::getGrade()const
{
	return this->_grade;
}

std::string Bureaucrat::getName()const
{
	return this->_name;
}

void Bureaucrat::incrementGrade()
{
	if (_grade > 0)
		_grade--;
	else
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementGrade()
{
	if (_grade < 150)
		_grade++;
	else
		throw Bureaucrat::GradeTooLowException();
}