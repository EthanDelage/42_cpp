/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:57:00 by edelage           #+#    #+#             */
/*   Updated: 2023/06/09 11:57:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "Ice.hpp"
#include "ICharacter.hpp"
#include <iostream>

Ice::Ice(): AMateria("ice") {}

Ice::Ice(Ice const &other): AMateria(other) {}

Ice::~Ice() {}

Ice &Ice::operator=(Ice const &other) {
	this->_type = other._type;
	return (*this);
}

AMateria *Ice::clone() const {
	Ice	*clone;

	clone = new Ice(*this);
	return (clone);
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
