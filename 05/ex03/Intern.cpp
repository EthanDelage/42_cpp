/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:44:00 by edelage           #+#    #+#             */
/*   Updated: 2023/06/14 20:44:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(Intern const &other) {
	*this = other;
}

Intern::~Intern() {}

Intern &Intern::operator=(Intern const &other) {
	(void) other;
	return (*this);
}


Form *Intern::makeForm(std::string formName, std::string target) {
	Form		*newForm;
	std::string	formNames[] = {"robotomy request", "shrubbery creation", "presidential pardon", ""};
	Form		*forms[] = {new RobotomyRequestForm(target), new ShrubberyCreationForm(target), new PresidentialPardonForm()};

	for (int i = 0; !formNames[i].empty(); ++i) {
		if (formName == formNames[i]) {
			std::cout << "Intern create a " << formNames[i] << std::endl;
			newForm = forms[i];
		}
		else
			delete forms[i];
	}
	return (newForm);
}
