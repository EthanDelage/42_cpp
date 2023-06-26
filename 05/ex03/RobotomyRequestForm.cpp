/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 02:26:00 by edelage           #+#    #+#             */
/*   Updated: 2023/06/14 02:26:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm():
	Form("RobotomyRequestForm", 72, 45) {
	this->_target = "Default";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target):
	Form("RobotomyRequestForm", 72, 45) {
	this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other):
	Form(other) {
	*this = other;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other) {
	if (this == &other)
		return (*this);
	this->_target = other._target;
	this->setIsSigned(other.getIsSigned());
	return (*this);
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	if (!this->getIsSigned())
		throw FormNotSigned();
	else if (this->getGradeToExecute() < executor.getGrade())
		throw GradeTooLowException();

	std::cout << "* drill noises *" << std::endl;
	if (rand() % 2)
		std::cout << this->_target << " has been robotomized" << std::endl;
	else
		std::cout << "The robotomy failed" << std::endl;
}
