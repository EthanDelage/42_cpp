/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:34:00 by edelage           #+#    #+#             */
/*   Updated: 2023/06/12 17:34:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form(): _name("Default"), _gradeToSign(1), _gradeToExecute(1) {
	this->_isSigned = false;
}

Form::Form(std::string name, uint8_t gradeToSign, uint8_t gradeToExecute):
	_name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	this->_isSigned = false;
	if (gradeToExecute > 150 || gradeToSign > 150)
		throw GradeTooLowException();
	else if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
}

Form::Form(Form const &other): _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
	*this = other;
}

Form::~Form() {}

Form &Form::operator=(Form const &other) {
	if (this == &other)
		return (*this);
	this->_isSigned = other._isSigned;
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, Form const &F) {
	if (F.getIsSigned())
		os << F.getName() << " can be executed from grade " << F.getGradeToExecute() << " upwards";
	else
		os << F.getName() << " can be signed from grade " << F.getGradeToSign() << " upwards";
	return (os);
}

void Form::beSigned(Bureaucrat signatory) {
	if (signatory.getGrade() > this->_gradeToExecute)
		throw GradeTooLowException();
	else
		this->_isSigned = true;
}

std::string Form::getName() const {
	return (this->_name);
}

bool Form::getIsSigned() const {
	return (this->_isSigned);
}

uint8_t Form::getGradeToSign() const {
	return (this->_gradeToSign);
}

uint8_t Form::getGradeToExecute() const {
	return (this->_gradeToExecute);
}
