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
	Form("Default", 25, 5) {
}

PresidentialPardonForm::PresidentialPardonForm(std::string target):
	Form(target, 25, 5) {

}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other):
	Form(other) {
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other) {
	if (this == &other)
		return (*this);
	this->setIsSigned(other.getIsSigned());
	return (*this);
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	if (!this->getIsSigned())
		throw FormNotSigned();
	else if (this->getGradeToExecute() < executor.getGrade())
		throw GradeTooLowException();

	std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
