/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 20:41:00 by edelage           #+#    #+#             */
/*   Updated: 2023/05/20 20:41:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "Harl.hpp"
#include <iostream>

Harl::Harl() {}

void	Harl::complain(std::string level) {
	std::string	levelId[] = {"DEBUG", "INFO", "WARNING", "ERROR", ""};
	int	i;

	i = 0;
	while (levelId[i] != "" && levelId[i] != level)
		i++;
	switch (i) {
		case 0:
			debug();
			info();
			warning();
			error();
			break;
		case 1:
			info();
			warning();
			error();
			break;
		case 2:
			warning();
			error();
			break;
		case 3:
			error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]"
					<< std::endl;
	}
}

void	Harl::debug() {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "debug message" << std::endl;
}

void	Harl::info() {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "info message" << std::endl;
}

void	Harl::warning() {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "warning message" << std::endl;
}

void	Harl::error() {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "error message" << std::endl;
}