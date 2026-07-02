/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 11:26:12 by antuel            #+#    #+#             */
/*   Updated: 2026/07/01 15:16:42 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

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
	if (_grade > 1)
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

void Bureaucrat::signForm(AForm &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << this->getName() <<" signed " << f.getName() << std::endl;
	}
	catch (const AForm::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;	
	}
	catch (const AForm::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
		
}


std::ostream &operator<<(std::ostream &os, const Bureaucrat &other)
{
	os << other.getName() << ", Bureaucrat grade: " << other.getGrade();
	return os;
}

//ex02
void Bureaucrat::executeForm(const AForm &form)
	{
		try
		{
			form.execute(*this);
			std::cout<< Bureaucrat::getName() << " exectued form: " << form.getName() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
