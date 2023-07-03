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
#include <ctime>

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
	std::deque<int>	copy = _deque;

	std::cout << "Before: ";
	for (std::deque<int>::const_iterator it = _deque.begin(); it != _deque.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	std::sort(copy.begin(), copy.end());
	std::cout << "After: ";
	for (std::deque<int>::const_iterator it = copy.begin(); it != copy.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	clock_t	start = clock();
	mergeInsertSortDeque(0, _deque.size() - 1);
	clock_t	end = clock();
	double	duration = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << _deque.size()
		<< " elements with std::deque<int>: " << duration << " s" << std::endl;

	start = clock();
	mergeInsertSortList(0, _list.size());
	end = clock();
	duration = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << _deque.size()
		<< " elements with std::list<int>: " << duration << " s" << std::endl;
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
	int				nLeft = middle - left + 1;
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
}

void PmergeMe::mergeInsertSortList(int left, int right) {
	int	middle = left + (right - left) / 2;

	if (middle != left && middle != right) {
		mergeInsertSortList(left, middle);
		mergeInsertSortList(middle + 1, right);
	}
	mergeList(left, middle, right);
}

void PmergeMe::mergeList(int left, int middle, int right) {
	int				nLeft = middle - left + 1;
	int 			nRight = right - middle;

	std::list<int>				leftList(nLeft);
	std::list<int>				rightList(nRight);
	std::list<int>::iterator	leftIt = leftList.begin();
	std::list<int>::iterator	rightIt = rightList.begin();
	std::list<int>::iterator	listIt = _list.begin();

	std::advance(listIt, left - 1);
	for (int i = 0; i < nLeft; ++i) {
		*leftIt = *listIt;
		++leftIt;
		++listIt;
	}
	listIt = _list.begin();
	std::advance(listIt, middle);
	for (int i = 0; i < nRight; ++i) {
		*rightIt = *(listIt);
		++rightIt;
		++listIt;
	}

	leftIt = leftList.begin();
	rightIt = rightList.begin();
	listIt = _list.begin();
	std::advance(listIt, left - 1);
	while (leftIt != leftList.end() && rightIt != rightList.end()) {
		if (*leftIt <= *rightIt) {
			*listIt = *leftIt;
			++leftIt;
		} else {
			*listIt = *rightIt;
			++rightIt;
		}
		++listIt;
	}
	while (leftIt != leftList.end()) {
		*listIt = *leftIt;
		++leftIt;
		++listIt;
	}
	while (rightIt != rightList.end()) {
		*listIt = *rightIt;
		++rightIt;
		++listIt;
	}
}
