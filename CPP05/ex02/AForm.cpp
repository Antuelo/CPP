/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 21:00:42 by antuel            #+#    #+#             */
/*   Updated: 2026/06/30 16:53:09 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"


//Defualt parameters = name(default name), signed(false), execution grade(150), singnature grade(150)
Form::Form() : 
	_name("default-name"),
	_sign(false),
	_sing_grade(150),
	_exec_grade(150)
{
	std::cout << "Default consturctor called" << std::endl;
}

Form::Form(std::string name, int sing_grade, int exec_grade) :
	_name(name),
	_sign(false),
	_sing_grade(sing_grade),
	_exec_grade(exec_grade)
{
	std::cout << "Parameters constructor called" << std::endl;
	if (sing_grade > 150)
		throw Form::GradeTooLowException();
	else if (sing_grade < 1)
		throw Form::GradeTooHighException();
		
	if (exec_grade > 150)
		throw Form::GradeTooLowException();
	else if (exec_grade < 1)
		throw Form::GradeTooHighException();
}

std::string Form::getName() const
{
	return _name;
}

int Form::getExecGrade() const
{
	return _exec_grade;
}

int Form::getSignGrade() const
{
	return _sing_grade;
}

bool Form::getSignState() const
{
	return _sign;
}

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= this->getSignGrade())
		_sign = true;
	else
		throw Form::GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Form signature grade is too High!!";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Form signature grade is too low!!";
}

Form::~Form()
{
	std::cout << "Default destructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Form &other)
{
	os << other.getName() << ", Sing grade: " << other.getSignGrade() << 
	", Exec grade: " << other.getExecGrade() << " Signed: " << other.getSignState() << std::endl;
	return os;
}
