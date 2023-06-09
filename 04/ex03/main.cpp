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
# include "Character.hpp"
# include "Ice.hpp"
# include "Cure.hpp"
#include <iostream>

int main() {
	AMateria	*elements[10];

	for (int i = 0; i < 5; ++i) {
		elements[i] = new Ice();
	}
	for (int i = 5; i < 10; ++i) {
		elements[i] = new Cure();
	}

	for (int i = 0; i < 10; ++i) {
		delete elements[i];
	}
}