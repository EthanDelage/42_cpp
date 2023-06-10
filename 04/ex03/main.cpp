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
# include "MateriaSource.hpp"
# include "Character.hpp"
# include "Ice.hpp"
# include "Cure.hpp"
#include <iostream>

int main() {
	IMateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("test");
	std::cout << std::endl;
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	std::cout << std::endl;

	AMateria	*elements[8];
	Character	player("test");
	Character	player1("tost");

	for (int i = 0; i < 4; ++i) {
		elements[i] = new Ice();
	}
	for (int i = 4; i < 8; ++i) {
		elements[i] = new Cure();
	}
	player.equip(elements[0]);
	player.equip(elements[1]);
	player.equip(elements[4]);
	player.equip(elements[5]);
	player1.equip(elements[2]);
	player1.equip(elements[6]);
	player1.equip(elements[3]);
	player.equip(elements[7]);
	player1.equip(elements[7]);

	std::cout << "Player 1's name: " << player1.getName() << std::endl;

	player.use(1, player1);
	player1.unequip(3);

	delete elements[7];
}