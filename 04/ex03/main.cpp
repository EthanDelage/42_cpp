/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:46:00 by edelage           #+#    #+#             */
/*   Updated: 2023/06/09 11:46:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "Ice.hpp"
#include <iostream>

int main() {
	AMateria	*test;

	test = new Ice();
	std::cout << test->getType() << std::endl;
	AMateria	*clone = test->clone();
	std::cout << clone->getType() << std::endl;
	delete clone;
}