/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 21:43:00 by edelage           #+#    #+#             */
/*   Updated: 2023/06/01 21:43:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "Cat.hpp"

#include <iostream>

Cat::Cat() {
	std::cout << "Cat default constructor called" << std::endl;
	this->_type = "Cat";
	this->_Brain = new Brain();
}

Cat::Cat(Cat const &other): Animal(other) {
	std::cout << "Cat copy constructor called" << std::endl;
	*this = other;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete	this->_Brain;
}

Cat &Cat::operator=(Cat const &other) {
	this->_type = other._type;
	for (int i = 0; i < NB_IDEAS; i++)
		this->_Brain[i] = other._Brain[i];
	return (*this);
}

void Cat::makeSound() const {
	std::cout << "Meow" << std::endl;
}
