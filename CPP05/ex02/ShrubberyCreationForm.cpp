/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 14:18:19 by antuel            #+#    #+#             */
/*   Updated: 2026/07/02 13:54:49 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :
_target("default-target")
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
: _target(copy._target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: _target(target)
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	
}