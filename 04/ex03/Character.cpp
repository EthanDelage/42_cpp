/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 20:35:00 by edelage           #+#    #+#             */
/*   Updated: 2023/06/09 20:35:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "Character.hpp"

Character::Character() {
	this->_name = "default";
	for (int i = 0; i < NB_SLOTS; ++i) {
		this->_inventory[i] = NULL;
	}
}

Character::Character(std::string name) {
	this->_name = name;
	for (int i = 0; i < NB_SLOTS; ++i) {
		this->_inventory[i] = NULL;
	}
}

Character::Character(Character const &other) {
	*this = other;
}

Character::~Character() {
	for (int i = 0; i < NB_SLOTS; ++i) {
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
}

Character &Character::operator=(Character const &other) {
	this->_name = other._name;
	for (int i = 0; i < NB_SLOTS; ++i) {
		this->_inventory[i] = other._inventory[i]->clone();
	}
	return (*this);
}

const std::string &Character::getName() const {
	return (this->_name);
}

void Character::equip(AMateria *m) {
	size_t	index;

	index = 0;
	while (index < NB_SLOTS && this->_inventory[index])
		index++;
	if (index != NB_SLOTS)
		this->_inventory[index] = m;
}

void Character::unequip(int index) {
	this->_inventory[index] = NULL;
}

void Character::use(int index, ICharacter &target) {
	if (this->_inventory[index])
	{
		this->_inventory[index]->use(target);
		delete this->_inventory[index];
		this->_inventory[index] = NULL;
	}
}
