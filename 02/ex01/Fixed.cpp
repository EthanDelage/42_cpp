/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 00:37:00 by edelage           #+#    #+#             */
/*   Updated: 2023/05/21 00:37:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->_fixedPointValue = 0;
}

Fixed::Fixed(const int integer) {
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = integer << this->_nbFractionalBits;
}

Fixed::Fixed(const float decimalNumber) {
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = (int) roundf(decimalNumber * (1 << this->_nbFractionalBits));
}

Fixed::Fixed(const Fixed &copy) {
	std::cout << "Copy constructor called" << std::endl;
	this->_fixedPointValue = copy._fixedPointValue;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &a) {
	std::cout << "Copy assignment operator called" << std::endl;
	_fixedPointValue = a._fixedPointValue;
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, const Fixed &a) {
	os << a.toFloat();
	return (os);
}

void	Fixed::setRawBits(const int raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPointValue = raw;
}

int	Fixed::getRawBits() {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPointValue);
}

int	Fixed::toInt() const {
	return (this->_fixedPointValue >> this->_nbFractionalBits);
}

float	Fixed::toFloat() const {
	return ((float) this->_fixedPointValue / (1 << this->_nbFractionalBits));
}
