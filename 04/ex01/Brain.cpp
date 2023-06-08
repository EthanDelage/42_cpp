/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 01:49:00 by edelage           #+#    #+#             */
/*   Updated: 2023/06/08 01:49:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
	std::cout << "Brain constructor called" << std::endl;
	for (int i = 0; i < NB_IDEAS; i++)
		this->_ideas[i] = std::string();
}

Brain::Brain(Brain const &other) {
	std::cout << "Brain copy constructor called" << std::endl;
	*this = other;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(Brain const &other) {
	for (int i = 0; i < NB_IDEAS; ++i)
		this->_ideas[i] = other._ideas[i];
	return (*this);
}
