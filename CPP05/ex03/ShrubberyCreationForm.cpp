/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 14:18:19 by antuel            #+#    #+#             */
/*   Updated: 2026/07/06 14:35:40 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
:	AForm("Default - ShrubberyCreationForm", 145, 137),
	_target("default-target")
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
: 	AForm(copy),
	_target(copy._target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: 	AForm("ShrubberyCreationForm", 145, 137),
	_target(target)
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (!this->getSignState())
		throw AForm::NotSignedException();
	if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
		
	std::ofstream file((_target + "_shrubbery").c_str());
	file << "                                                         .\n"
		"                                              .         ;  \n"
		"                 .              .              ;%     ;;   \n"
		"                   ,           ,                :;%  %;    \n"
		"                    :         ;                   :;%;'     .,   \n"
		"           ,.        %;     %;            ;        %;'    ,;   \n"
		"             ;       ;%;  %%;        ,     %;    ;%;    ,%'    \n"
		"              %;       %;%;      ,  ;       %;  ;%;   ,%;'     \n"
		"               ;%;      %;        ;%;        % ;%;  ,%;'       \n"
		"                `%;.     ;%;     %;'         `;%%;.%;'         \n"
		"                 `:;%.    ;%%. %@;        %; ;@%;%'            \n"
		"                    `:;%.  :;bd%;          %;@%;'               \n"
		"                      `@%:.  :;%.         ;@@%;'                \n"
		"                        `@%.  `;@%.      ;@@%;                  \n"
		"                          `@%%. `@%%    ;@@%;                   \n"
		"                            ;@%. :@%%  %@@%;                    \n"
		"                              %@bd%%%bd%%:;                     \n"
		"                                #@%%%%%:;;                      \n"
		"                                %@@%%%::;                       \n"
		"                                %@@@%(o);  . '                 \n"
		"                                %@@@o%;:(.,'                   \n"
		"                            `.. %@@@o%::;                      \n"
		"                               `)@@@o%::;                      \n"
		"                                %@@(o)::;                      \n"
		"                               .%@@@@%::;                      \n"
		"                               ;%@@@@%::;.                     \n"
		"                              ;%@@@@%%:;;;.                    \n"
		"                          ...;%@@@@@%%:;;;;,..                 \n";
	
	file.close();
	std::cout << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
		this->_target = other._target;

	return *this;	
}
