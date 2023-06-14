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

RobotomyRequestForm::RobotomyRequestForm():
	Form("Default", 72, 45) {
}

RobotomyRequestForm::RobotomyRequestForm(std::string target):
	Form(target, 72, 45) {
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other):
	Form(other) {
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other) {
	if (this == &other)
		return (*this);
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
		std::cout << this->getName() << " has been robotomized" << std::endl;
	else
		std::cout << "The robotomy failed" << std::endl;
}
