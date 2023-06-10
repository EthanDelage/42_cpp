/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 00:19:00 by edelage           #+#    #+#             */
/*   Updated: 2023/06/10 00:19:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "MateriaSource.hpp"

#include <iostream>

MateriaSource::MateriaSource() {
	for (int i = 0; i < NB_SLOTS; ++i) {
		this->_inventory[i] = NULL;
	}
}

MateriaSource::MateriaSource(MateriaSource const &other) {
	*this = other;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < NB_SLOTS; ++i) {
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
}

MateriaSource &MateriaSource::operator=(MateriaSource const &other) {
	for (int i = 0; i < 4; ++i) {
		this->_inventory[i] = other._inventory[i];
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria *m) {
	size_t	index;

	index = 0;
	while (index < NB_SLOTS && this->_inventory[index])
		index++;
	if (index != NB_SLOTS)
		this->_inventory[index] = m;
}

AMateria *MateriaSource::createMateria(const std::string &type) {
	for (int i = 0; i < NB_SLOTS; ++i) {
		if (this->_inventory[i] && this->_inventory[i]->getType() == type)
			return (this->_inventory[i]->clone());
	}
	std::cout << "Unknown type" << std::endl;
	return (NULL);
}
