/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 14:18:10 by antuel            #+#    #+#             */
/*   Updated: 2026/07/06 15:08:08 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
: 	AForm("default-name", 25, 5),
	_target("default-target")
{}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
: 	AForm("PresidentialPardonForm", 25, 5),
	_target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
: 	AForm(copy),
	_target(copy._target)
{}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
		this->_target = other._target;

	return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (!this->getSignState())
		throw AForm::NotSignedException();
	if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();		
	
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;	
}