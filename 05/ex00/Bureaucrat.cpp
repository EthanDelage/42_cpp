/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethan <ethan@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 23:22:00 by ethan             #+#    #+#             */
/*   Updated: 2023/06/10 23:22:00 by ethan            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
	this->_name = "Default";
	this->_grade = 150;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) {
	*this = other;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other) {
	this->_name = other._name;
	this->_grade = other._grade;
	return (*this);
}

std::string Bureaucrat::getName() const {
	return (this->_name);
}

uint8_t Bureaucrat::getGrade() const {
	return (this->_grade);
}

void Bureaucrat::incrementGrade() {
	if (this->_grade > 1)
		this->_grade--;
}

void Bureaucrat::decreaseGrade() {
	if (this->_grade < 150)
		this->_grade++;
}