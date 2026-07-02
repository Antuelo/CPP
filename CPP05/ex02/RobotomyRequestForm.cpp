/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 14:18:16 by antuel            #+#    #+#             */
/*   Updated: 2026/07/02 15:56:55 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm()
: 	AForm("Default - RobotomyRequestForm", 72, 45),
	_target("default - target")
{}


RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
: 	_target(copy._target),
	AForm(copy)
{}


RobotomyRequestForm::RobotomyRequestForm(std::string target)
:	AForm("RobotomyRequestForm", 72, 45),
	_target(target)
{}

RobotomyRequestForm::~RobotomyRequestForm()
{}

const char *RobotomyRequestForm::RobotomisedFail::what() const throw()
{
	return "Robotomised failed";
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (!this->getSignState())
		throw AForm::NotSignedException();
	if (executor.getGrade() > this->getExecGrade())
		throw AForm::NotSignedException();

	int random = rand() % 2;

	if (random == 0)
	{
		std::cout 	<< "dddrrrrrrrrzzzzzzzzzzzzz beeeep bep bep* drilling noises *" 
					<< this->getName()
					<< " has been robotomized successfully!"
					<< std::endl;
	}
	else
		throw RobotomisedFail::exception();
}