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
#include <cstdlib>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int argc, char **argv) {
	int	value;

	for (int i = 1; i < argc; ++i) {
		value = parseArgument(argv[i]);
		_list.push_back(value);
		_deque.push_back(value);
	}
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

void PmergeMe::display() {
	for (std::deque<int>::const_iterator it = _deque.begin(); it != _deque.end(); ++it) {
		std::cout << *it << ", ";
	}
	std::cout << std::endl;
}

int PmergeMe::parseArgument(const char *str) {
	double	result;
	char	*rest;

	result = strtod(str, &rest);
	if (*rest != '\0' && std::string(str).find('.'))
		throw std::exception();
	return (static_cast<int>(result));
}

void PmergeMe::mergeInsertSortDeque(int left, int right) {
	int	middle = left + (right - left) / 2;

	if (middle != left && middle != right) {
		mergeInsertSortDeque(left, middle);
		mergeInsertSortDeque(middle + 1, right);
	}
	mergeDeque(left, middle, right);
}

void PmergeMe::mergeDeque(int left, int middle, int right) {
	int				nLeft = left - middle + 1;
	int 			nRight = right - middle;

	std::deque<int>	leftDeque(nLeft);
	std::deque<int>	rightDeque(nRight);

	for (int i = 0; i < nLeft; ++i)
		leftDeque[i] = _deque[left + i];
	for (int i = 0; i < nRight; ++i)
		rightDeque[i] = _deque[middle + 1 + i];

	int i = 0;
	int j = 0;
	int	k = left;
	while (i < nLeft && j < nRight) {
		if (leftDeque[i] <= rightDeque[j]) {
			_deque[k] = leftDeque[i];
			++i;
		} else {
			_deque[k] = rightDeque[j];
			++j;
		}
		++k;
	}
	while (i < nLeft) {
		_deque[k] = leftDeque[i];
		++i;
		++k;
	}
	while (j < nRight) {
		_deque[k] = rightDeque[j];
		++j;
		++k;
	}
	std::cout << "test" << std::endl;
}
