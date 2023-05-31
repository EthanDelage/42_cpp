/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 00:53:00 by edelage           #+#    #+#             */
/*   Updated: 2023/05/31 00:53:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(): ClapTrap() {
	std::cout << "ScavTrap default constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string &name): ClapTrap(name) {
	std::cout << "ScavTrap constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap const &other): ClapTrap(other) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called" << std::endl;
}

void	ScavTrap::attack(const std::string &target) {
	if (this->_energyPoints == 0)
		std::cout << "ScavTrap " << this->_name
				  << " doesn't have enough energy point" << std::endl;
	else if (this->_hitPoints == 0)
		std::cout << "ScavTrap " << this->_name << " is dead" << std::endl;
	else
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target
				  << ", causing " << this->_attackDamage
				  << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->_name << " has entered in Guard Gate mode" << std::endl;
}
