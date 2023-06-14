/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:06:00 by edelage           #+#    #+#             */
/*   Updated: 2023/06/13 13:06:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm():
	Form("Default", 145, 137) {
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
	Form(target, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other):
	Form(other) {
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other) {
	if (this == &other)
		return (*this);
	this->setIsSigned(other.getIsSigned());
	return (*this);
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	if (!this->getIsSigned())
		throw FormNotSigned();
	else if (this->getGradeToExecute() < executor.getGrade())
		throw GradeTooLowException();

	std::ofstream outfile(this->getName() + "_shruberry");
	if (outfile.fail())
	{
		std::cerr << "Cannot open file " << this->getName() << "_shruberry" << std::endl;
		return ;
	}
	outfile << "               ,@@@@@@@,\n"
			   "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
			   "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
			   "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
			   "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
			   "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
			   "   `&%\\ ` /%&'    |.|        \\ '|8'\n"
			   "       |o|        | |         | |\n"
			   "       |.|        | |         | |\n"
			   "    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_\n";
	outfile.close();
}
