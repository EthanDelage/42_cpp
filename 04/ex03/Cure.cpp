/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:58:00 by edelage           #+#    #+#             */
/*   Updated: 2023/06/09 11:58:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "Cure.hpp"
#include "ICharacter.hpp"

#include <iostream>

Cure::Cure(): AMateria("cure") {}

Cure::Cure(Cure const &other): AMateria(other) {}

Cure::~Cure() {}

Cure &Cure::operator=(Cure const &other) {
	this->_type = other._type;
	return (*this);
}

AMateria *Cure::clone() const {
	Cure	*clone;

	clone = new Cure(*this);
	return (clone);
}

void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
