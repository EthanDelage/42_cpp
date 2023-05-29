/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:32:00 by edelage           #+#    #+#             */
/*   Updated: 2023/05/17 20:32:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

static void	displaySearch(int totalContactAdd, Contact contactList[MAX_CONTACT]);
static void	displaySearchRow(int index, Contact contact);
static void	displaySearchCell(std::string content);
static void	displaySeparation();
static int	getIndex(int totalContactAdd);
static bool isNumber(std::string str);

PhoneBook::PhoneBook() {
	this->totalContactAdd = 0;
}

void PhoneBook::addContact() {
	Contact		newContact;
	std::string	input;

	std::cout << "Add a new contact:" << std::endl;
	std::cout << "\tEnter first name:\t";
	std::cin >> input;
	newContact.setFirstName(input);
	std::cout << "\tEnter last name:\t";
	std::cin >> input;
	newContact.setLastName(input);
	std::cout << "\tEnter nickname:\t\t";
	std::cin >> input;
	newContact.setNickName(input);
	std::cout << "\tEnter phone number:\t";
	std::cin >> input;
	newContact.setPhoneNumber(input);
	std::cout << "\tEnter darkest secret:\t";
	std::cin >> input;
	newContact.setDarkestSecret(input);
	this->contactList[this->totalContactAdd % MAX_CONTACT] = newContact;
	this->totalContactAdd++;
}

void	PhoneBook::searchContact() {
	int	index;
	displaySearch(this->totalContactAdd, this->contactList);
	if (this->totalContactAdd != 0)
	{
		index = getIndex(this->totalContactAdd);
		if (index != -1)
			this->contactList[index].toString();
	}
	else
		std::cout << "You have no contact" << std::endl;
}

static void	displaySearch(int totalContactAdd, Contact contactList[MAX_CONTACT]) {
	std::cout << std::endl;
	displaySeparation();
	if (totalContactAdd == 0)
	{
		std::cout << "|          |          |          |          |" << std::endl;
		displaySeparation();
	}
	for (int i = 0; i < MAX_CONTACT && i < totalContactAdd; i++)
		displaySearchRow(i, contactList[i]);
	std::cout << std::endl;
}

static void	displaySearchRow(int index, Contact contact)
{
	std::cout << '|' << std::setw(CELL_WIDTH) << index << '|';
	displaySearchCell(contact.getFirstName());
	std::cout << '|';
	displaySearchCell(contact.getLastName());
	std::cout << '|';
	displaySearchCell(contact.getNickName());
	std::cout << '|' << std::endl;
	displaySeparation();
}

static void	displaySearchCell(std::string content)
{
	if (content.length() <= CELL_WIDTH)
		std::cout << std::setw(CELL_WIDTH) << content;
	else
		std::cout << content.substr(0, CELL_WIDTH - 1) << '.';
}

static void	displaySeparation() {
	for (int i = 0; i < CELL_WIDTH * 4 + 5; i++)
	{
		if (i % (CELL_WIDTH + 1) == 0)
			std::cout << '-';
		else
			std::cout << '-';
	}
	std::cout << std::endl;
}

static int	getIndex(int totalContactAdd) {
	std::string input;
	int	index;

	std::cout << "Select an index for more information: ";

	std::cin >> input;
	std::stringstream(input) >> index;
	if (!isNumber(input) || index < 0
		|| (index >= totalContactAdd || index >= MAX_CONTACT))
	{
		std::cout << "Not a valid index" << std::endl;
		return (-1);
	}
	return (index);

}

static bool isNumber(std::string str) {
	const size_t	len = str.length();

	for (size_t i = 0; i < len; i++)
	{
		if (!isdigit(str[i]))
			return (false);
	}
	return (true);
}
