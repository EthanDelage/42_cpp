/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 21:08:00 by edelage           #+#    #+#             */
/*   Updated: 2023/06/01 21:08:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "Animal.hpp"
#include <iostream>

Animal::Animal() {
	std::cout << "Animal default constructor called" << std::endl;
	this->type = "";
}

Animal::Animal(Animal const &other) {
	std::cout << "Animal copy constructor called" << std::endl;
	*this = other;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(Animal const &other) {
	this->type = other.type;
	return (*this);
}
