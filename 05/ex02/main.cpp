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
#include <iostream>

int	main() {
	Bureaucrat	ceo("CEO", 1);
	std::cout << ceo << std::endl;
	Bureaucrat	developer("dev", 50);
	Bureaucrat	intern("intern", 150);

	ShrubberyCreationForm	test("tost");
	ceo.signForm(test);
	test.execute(ceo);
//	Form	forTheCEO("For the CEO", 1, 1);
//	std::cout << forTheCEO << std::endl;
//	Form	forTheDev("For the dev", 50, 1);
//	Form	random("Random form", 150, 100);
//
//	ceo.signForm(forTheCEO);
//	ceo.signForm(forTheCEO);
//
//	intern.signForm(forTheDev);
//
//	developer.signForm(forTheDev);
//
//	developer.signForm(random);
}
