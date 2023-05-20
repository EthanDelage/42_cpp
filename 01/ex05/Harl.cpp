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
	void			(Harl::*levelFunction[]) (void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; levelId[i] != ""; i++)
	{
		if (levelId[i] == level)
			(this->*levelFunction[i])();
	}
}

void	Harl::debug() {
	std::cout << "Debug" << std::endl;
}

void	Harl::info() {
	std::cout << "Info" << std::endl;
}

void	Harl::warning() {
	std::cout << "Warning" << std::endl;
}

void	Harl::error() {
	std::cout << "Error" << std::endl;
}