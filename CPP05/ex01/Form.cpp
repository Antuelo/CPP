/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 21:00:42 by antuel            #+#    #+#             */
/*   Updated: 2026/06/23 22:18:11 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"


//Defualt parameters = name(default name), signed(false), execution grade(150), singnature grade(150)
Form::Form() : 
	_name("default-name"),
	_sign(false),
	_exec_grade(150),
	_sing_grade(150)
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

Form::~Form()
{
	std::cout << "Default destructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Form &other)
{
	
}