/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 21:00:42 by antuel            #+#    #+#             */
/*   Updated: 2026/07/02 14:34:17 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"


//Defualt parameters = name(default name), signed(false), execution grade(150), singnature grade(150)
AForm::AForm() : 
	_name("default-name"),
	_sign(false),
	_sing_grade(150),
	_exec_grade(150)
{
	std::cout << "Default consturctor called" << std::endl;
}

AForm::AForm(const AForm &copy)
: 	_name(copy._name),
	_sign(copy._sign),
	_sing_grade(copy._sing_grade),
	_exec_grade(copy._exec_grade)
{}

AForm::AForm(std::string name, int sing_grade, int exec_grade) :
	_name(name),
	_sign(false),
	_sing_grade(sing_grade),
	_exec_grade(exec_grade)
{
	std::cout << "Parameters constructor called" << std::endl;
	if (sing_grade > 150)
		throw AForm::GradeTooLowException();
	else if (sing_grade < 1)
		throw AForm::GradeTooHighException();
		
	if (exec_grade > 150)
		throw AForm::GradeTooLowException();
	else if (exec_grade < 1)
		throw AForm::GradeTooHighException();
}

AForm::~AForm()
{
	std::cout << "Default destructor called" << std::endl;
}


std::string AForm::getName() const
{
	return _name;
}

int AForm::getExecGrade() const
{
	return _exec_grade;
}

int AForm::getSignGrade() const
{
	return _sing_grade;
}

bool AForm::getSignState() const
{
	return _sign;
}

void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= this->getSignGrade())
		_sign = true;
	else
		throw AForm::GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "AForm signature grade is too High!!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "AForm signature grade is too low!!";
}

const char *AForm::NotSignedException::what() const throw()
{
	return "The Form isn't signed - execution not possible";
}


std::ostream &operator<<(std::ostream &os, const AForm &other)
{
	os << other.getName() << ", Sing grade: " << other.getSignGrade() << 
	", Exec grade: " << other.getExecGrade() << " Signed: " << other.getSignState() << std::endl;
	return os;
}

