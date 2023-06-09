/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:46:00 by edelage           #+#    #+#             */
/*   Updated: 2023/06/09 11:46:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "AMateria.hpp"

AMateria::AMateria() {
	this->_type = "AMateria";
}

AMateria::AMateria(const std::string &type) {
	this->_type = type;
}

AMateria::AMateria(AMateria const &other) {
	*this = other;
}

AMateria::~AMateria() {}

AMateria &AMateria::operator=(AMateria const &other) {
	this->_type = other._type;
	return (*this);
}

const std::string &AMateria::getType() const {
	return (this->_type);
}
