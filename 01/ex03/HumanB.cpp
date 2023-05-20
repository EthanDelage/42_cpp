/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:58:00 by edelage           #+#    #+#             */
/*   Updated: 2023/05/20 14:58:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) {
	this->_name = name;
	this->_weapon = NULL;
}

void HumanB::attack() {
	if (this->_weapon == NULL)
		std::cout << this->_name << " has no gun" << std::endl;
	else
		std::cout << this->_name
				  << " attacks with their "
				  << this->_weapon->getType()
				  << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
}
