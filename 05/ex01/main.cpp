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
#include "Form.hpp"
#include <iostream>

int	main() {
	try {
		Bureaucrat	ceo("CEO", 1);
		std::cout << ceo << std::endl;
		Bureaucrat	developer("dev", 50);
		Bureaucrat	intern("intern", 150);

		Form	forTheCEO("For the CEO", 1, 1);
		std::cout << forTheCEO << std::endl;
		Form	forTheDev("For the dev", 50, 1);
		Form	random("Random form", 150, 100);

		ceo.signForm(forTheCEO);
		ceo.signForm(forTheCEO);

		intern.signForm(forTheDev);

		developer.signForm(forTheDev);

		developer.signForm(random);
	} catch (std::exception const & e) {
		std::cerr << e.what() << std::endl;
	}
}
