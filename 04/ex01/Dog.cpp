/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 21:43:00 by edelage           #+#    #+#             */
/*   Updated: 2023/06/01 21:43:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "Dog.hpp"

#include <iostream>

Dog::Dog() {
	std::cout << "Dog default constructor called" << std::endl;
	this->_type = "Dog";
	this->_Brain = new Brain();
}

Dog::Dog(Dog const &other): Animal(other) {
	std::cout << "Dog copy constructor called" << std::endl;
	*this = other;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete this->_Brain;
}

Dog &Dog::operator=(Dog const &other) {
	this->_type = other._type;
	for (int i = 0; i < NB_IDEAS; i++)
		this->_Brain[i] = other._Brain[i];
	return (*this);
}

void Dog::makeSound() const {
	std::cout << "Woof" << std::endl;
}
