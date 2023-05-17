/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:33:00 by edelage           #+#    #+#             */
/*   Updated: 2023/05/17 20:33:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "Contact.hpp"
#include <iostream>

Contact::Contact() {
	this->firstName = "";
	this->lastName = "";
	this->nickName = "";
	this->phoneNumber = "";
	this->darkestSecret = "";
}

Contact::~Contact() {return ;}

void Contact::setFirstName(std::string firstName) {
	this->firstName = firstName;
}

std::string Contact::getFirstName() {
	return (this->firstName);
}

void Contact::setLastName(std::string lastName) {
	this->lastName = lastName;
}

std::string Contact::getLastName() {
	return (this->lastName);
}

void Contact::setNickName(std::string nickName) {
	this->nickName = nickName;
}

std::string Contact::getNickName() {
	return (this->nickName);
}

void Contact::setPhoneNumber(std::string phoneNumber) {
	this->phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(std::string darkestSecret) {
	this->darkestSecret = darkestSecret;
}

void Contact::toString() {
	std::cout << this->nickName << "information:" << std::endl;
	std::cout << "\tFirst Name:\t" << this->firstName << std::endl;
	std::cout << "\tLast Name:\t" << this->lastName << std::endl;
	std::cout << "\tPhone number:\t" << this->phoneNumber << std::endl;
	std::cout << "\tDarkest secret:\t" << this->darkestSecret << std::endl;
}
