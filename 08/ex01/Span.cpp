/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 08:48:00 by edelage           #+#    #+#             */
/*   Updated: 2023/06/17 08:48:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "Span.hpp"
#include <algorithm>

Span::Span() {
	this->_span = std::vector<int>();
	this->_size = 0;
}

Span::Span(unsigned int size) {
	this->_span = std::vector<int>();
	this->_size = size;
}

Span::Span(Span const &other) {
	*this = other;
}

Span::~Span() {}

Span &Span::operator=(Span const &other) {
	if (this == &other)
		return (*this);
	this->_span = other._span;
	this->_size = other._size;
	return (*this);
}

unsigned int Span::getSize() {
	return (this->_size);
}

unsigned int Span::getNbElem() {
	return (this->_span.size());
}

void Span::addNumber(int number) {
	if (this->_size > this->_span.size())
		this->_span.push_back(number);
	else
		throw std::runtime_error("Too many numbers in span");
}

void Span::displaySpan() {
	std::cout << "Span:" << std::endl;
	for (std::vector<int>::const_iterator it = _span.begin(); it != _span.end(); ++it) {
		std::cout << *it << std::endl;
	}
}

int Span::longestSpan() {
	if (_span.size() == 0 || _span.size() == 1)
		throw (std::exception);
	return (*std::max_element(_span.begin(), _span.end()) - *std::min_element(_span.begin(), _span.end()));
}

int Span::shortestSpan() {
	if (_span.size() == 0 || _span.size() == 1)
		throw (std::exception);

	std::vector<int> copy = _span;
	std::sort(copy.begin(), copy.end());

	std::vector<int>::const_iterator	it = copy.begin();
	int 								previousValue = *it++;
	int 								shortest = *it - previousValue;

	for (; it != copy.end(); ++it) {
		if (*it - previousValue < shortest)
			shortest = *it - previousValue;
		previousValue = *it;
	}
	return (shortest);
}

