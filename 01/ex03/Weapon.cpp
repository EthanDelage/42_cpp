/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:58:00 by edelage           #+#    #+#             */
/*   Updated: 2023/05/20 14:58:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
	this->_type = type;
}

const std::string	&Weapon::getType() {
	const std::string	&type = this->_type;

	return (type);
}

void Weapon::setType(std::string type) {
	this->_type = type;
}
