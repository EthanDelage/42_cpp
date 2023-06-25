/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 02:45:00 by edelage           #+#    #+#             */
/*   Updated: 2023/06/14 02:45:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm():
	Form("PresidentialPardonForm", 25, 5) {
	this->_target = "Default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target):
	Form("PresidentialPardonForm", 25, 5) {
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other):
	Form(other) {
	*this = other;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other) {
	if (this == &other)
		return (*this);
	this->_target = other._target;
	this->setIsSigned(other.getIsSigned());
	return (*this);
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	if (!this->getIsSigned())
		throw FormNotSigned();
	else if (this->getGradeToExecute() < executor.getGrade())
		throw GradeTooLowException();

	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
