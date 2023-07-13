/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethan <ethan@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 23:18:00 by ethan             #+#    #+#             */
/*   Updated: 2023/06/10 23:18:00 by ethan            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <cstdlib>

int	main() {
	srand(time(NULL));

	try {
		Bureaucrat	ceo("CEO", 1);
		std::cout << ceo << std::endl;
		Bureaucrat	developer("dev", 50);
		Intern		intern;

		ShrubberyCreationForm	test("test");
		ceo.executeForm(test);
		ceo.signForm(test);
		ceo.executeForm(test);

		std::cout << std::endl;

		RobotomyRequestForm	anonymous("Anonymous");
		developer.signForm(anonymous);
		developer.executeForm(anonymous);
		ceo.executeForm(anonymous);

		std::cout << std::endl;

		PresidentialPardonForm	random("Random");
		ceo.executeForm(random);
		ceo.signForm(random);
		ceo.executeForm(random);

		std::cout << std::endl;

		Form	*form;
		form = intern.makeForm("shrubbery creation", "tost");
		ceo.signForm(*form);
		ceo.executeForm(*form);
		delete form;

		std::cout << std::endl;

		form = intern.makeForm("robotomy request", "tost");
		delete form;
		form = intern.makeForm("presidential pardon", "tost");
		delete form;
	} catch (std::exception const & e) {
		std::cerr << e.what() << std::endl;
	}
}
