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
#include <cstdlib>

int	main() {
	srand(time(NULL));

	Bureaucrat	ceo("CEO", 1);
	std::cout << ceo << std::endl;
	Bureaucrat	developer("dev", 50);
	Bureaucrat	intern("intern", 150);

	ShrubberyCreationForm	test("test");
	ceo.executeForm(test);
	ceo.signForm(test);
	intern.executeForm(test);
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

}
