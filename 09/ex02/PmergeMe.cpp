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
#include <algorithm>
#include <ctime>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int argc, char **argv) {
	int	value;

	for (int i = 1; i < argc; ++i) {
		value = parseArgument(argv[i]);
		_list.push_back(value);
		_vector.push_back(value);
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
	_vector = other._vector;
	return (*this);
}

void PmergeMe::display() {
	std::cout << "Before: ";
	for (std::vector<int>::const_iterator it = _vector.begin(); it != _vector.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	clock_t	start = clock();
	mergeInsertSortVector(_vector);
	clock_t	end = clock();
	std::cout << "After: ";
	for (std::vector<int>::const_iterator it = _vector.begin(); it != _vector.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	double	duration = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << _vector.size()
		<< " elements with std::vector<int>: " << duration << " s" << std::endl;

	start = clock();
	mergeInsertSortList(_list);
	end = clock();
	duration = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << _list.size()
		<< " elements with std::list<int>: " << duration << " s" << std::endl;
}

int PmergeMe::parseArgument(const char *str) {
	double	result;
	char	*rest;

	result = strtod(str, &rest);
	if (*rest != '\0' || std::string(str).find('.') != std::string::npos)
		throw std::exception();
	return (static_cast<int>(result));
}

void PmergeMe::mergeInsertSortVector(std::vector<int> & vector) {
	std::vector<int>::iterator	middle = vector.begin() + vector.size() / 2;

	if (vector.size() <= K) {
		insertSortVector(vector);
		return;
	}
	std::vector<int>	left = std::vector<int>(vector.begin(), middle);
	std::vector<int>	right = std::vector<int>(middle, vector.end());
	mergeInsertSortVector(left);
	mergeInsertSortVector(right);
	std::merge(left.begin(), left.end(),
			   right.begin(), right.end(),
			   vector.begin());
}

void PmergeMe::insertSortVector(std::vector<int> & vector) {
	size_t	tmpIndex;
	int 	value;

	for (size_t index = 1; index != vector.size(); ++index) {
		tmpIndex = index;
		value = vector[tmpIndex];
		while (tmpIndex && vector[tmpIndex - 1] > value) {
			vector[tmpIndex] = vector[tmpIndex - 1];
			--tmpIndex;
		}
		vector[tmpIndex] = value;
	}
}

void PmergeMe::mergeInsertSortList(std::list<int> & list) {
	std::list<int>::iterator	middle = list.begin();

	std::advance(middle, list.size() / 2);
	if (list.size() <= K) {
		insertSortList(list);
		return;
	}
	std::list<int>	left = std::list<int>(list.begin(), middle);
	std::list<int>	right = std::list<int>(middle, list.end());
	mergeInsertSortList(left);
	mergeInsertSortList(right);
	std::merge(left.begin(), left.end(),
			   right.begin(), right.end(),
			   list.begin());
}

void PmergeMe::insertSortList(std::list<int> & list) {
	size_t						tmpIndex;
	int 						value;
	std::list<int>::iterator	listElem;
	std::list<int>::iterator	listPreviousElem;

	for (size_t index = 1; index != list.size(); ++index) {
		tmpIndex = index;
		listElem = list.begin();
		listPreviousElem = listElem;
		--listPreviousElem;
		std::advance(listElem, tmpIndex);
		value = *listElem;
		while (tmpIndex && *listPreviousElem > value) {
			*listElem = *listPreviousElem;
			--tmpIndex;
		}
		*listElem = value;
	}
}
