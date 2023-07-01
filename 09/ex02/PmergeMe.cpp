/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:26:00 by edelage           #+#    #+#             */
/*   Updated: 2023/07/01 15:26:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "PmergeMe.hpp"

#include <iostream>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int argc, char **argv) {

}

PmergeMe::PmergeMe(PmergeMe const &other) {
	*this = other;
}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(PmergeMe const &other) {
	if (this == &other)
		return (*this);
	_list = other._list;
	_deque = other._deque;
	return (*this);
}

int PmergeMe::parseArgument(const char *str) {
	double	result;
	char	*rest;

	result = strtod(str, &rest);
	if (*rest != '\0')
		throw std::exception();
	else if ()
}
