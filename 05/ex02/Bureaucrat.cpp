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

Bureaucrat::Bureaucrat(): _name("Default") {
	this->_grade = 150;
}

Bureaucrat::Bureaucrat(std::string name, uint8_t grade): _name(name) {
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other): _name(other._name) {
	*this = other;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other) {
	if (this == &other)
		return (*this);
	this->_grade = other._grade;
	return (*this);
}

void Bureaucrat::signForm(Form &formToSign) {
	bool alreadySigned = formToSign.getIsSigned();

	try {
		formToSign.beSigned(*this);
		if (alreadySigned)
			std::cout << this->_name << " couldn't sign " << formToSign.getName()
				<< " because it has already signed" << std::endl;
		else
			std::cout << this->_name << " signed " << formToSign.getName() << std::endl;
	}
	catch (Form::GradeTooLowException &e) {
		std::cout << this->_name << " couldn't sign " << formToSign.getName()
			<< " because its grade is too low" << std::endl;
		std::cout << "grade required: " << formToSign.getGradeToSign() << std::endl;
	}
}

void Bureaucrat::executeForm(const Form &formToExecute) {
	try {
		formToExecute.execute(*this);
		std::cout << this->_name << " executed " << formToExecute.getName() << std::endl;
	}
	catch (Form::FormNotSigned &e) {
		std::cerr << this->_name << " cannot execute " << formToExecute.getName() << ": " << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e) {
		std::cerr << this->_name << " cannot execute " << formToExecute.getName() << ": " << e.what() << std::endl;
	}
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
	else
		throw GradeTooHighException();
}

void Bureaucrat::decreaseGrade() {
	if (this->_grade < 150)
		this->_grade++;
	else
		throw GradeTooLowException();
}

std::ostream	&operator<<(std::ostream &os, Bureaucrat const &B) {
	os << B.getName() << ", bureaucrat grade " << (unsigned int) B.getGrade();
	return (os);
}