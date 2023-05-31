/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 23:38:00 by edelage           #+#    #+#             */
/*   Updated: 2023/05/24 23:38:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "ClapTrap.hpp"

#include <iostream>

ClapTrap::ClapTrap() {
	std::cout << "Default constructor called" << std::endl;
	this->_name = "Default";
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

ClapTrap::ClapTrap(ClapTrap const &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

ClapTrap::ClapTrap(std::string name) {
	std::cout << "Constructor called" << std::endl;
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &other) {
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	return (*this);
}

void	ClapTrap::attack(const std::string &target) {
	if (this->_energyPoints == 0)
		std::cout << "ClapTrap " << this->_name
			<< " doesn't have enough energy point" << std::endl;
	else if (this->_hitPoints == 0)
		std::cout << "ClapTrap " << this->_name << " is dead" << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target
			<< ", causing " << this->_attackDamage
			<< " points of damage!" << std::endl;
		this->_energyPoints--;
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap " << this->_name << " took "
		<< amount << " damage" << std::endl;
	if (this->_hitPoints > amount)
		this->_hitPoints = 0;
	else
		this->_hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energyPoints == 0)
		std::cout << "ClapTrap " << this->_name
			<< " doesn't have enough energy point" << std::endl;
	else if (this->_hitPoints == 0)
		std::cout << "ClapTrap " << this->_name << " is dead" << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->_name << " repaired "
			<< amount << std::endl;
		this->_hitPoints += amount;
		this->_energyPoints--;
	}
}

void ClapTrap::setAttackDamage(unsigned int amount) {
	this->_attackDamage = amount;
}

unsigned int ClapTrap::getAttackDamage() {
	return (this->_attackDamage);
}
