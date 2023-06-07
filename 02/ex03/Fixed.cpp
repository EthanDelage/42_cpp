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
#include <cmath>

Fixed::Fixed() {
	this->_fixedPointValue = 0;
}

Fixed::Fixed(const int integer) {
	this->_fixedPointValue = integer << this->_nbFractionalBits;
}

Fixed::Fixed(const float decimalNumber) {
	this->_fixedPointValue = (int) roundf(decimalNumber * (1 << this->_nbFractionalBits));
}

Fixed::Fixed(const Fixed &copy) {
	this->_fixedPointValue = copy._fixedPointValue;
}

Fixed::~Fixed() {}

Fixed	&Fixed::operator=(const Fixed &a) {
	this->_fixedPointValue = a._fixedPointValue;
	return (*this);
}

Fixed	operator+(const Fixed &a, const Fixed &b) {
	Fixed	result;

	result.setRawBits(a.getRawBits() + b.getRawBits());
	return (result);
}

Fixed	operator-(const Fixed &a, const Fixed &b) {
	Fixed	result;

	result.setRawBits(a.getRawBits() - b.getRawBits());
	return (result);
}

Fixed	operator*(const Fixed &a, const Fixed &b) {
	Fixed	result;

	result.setRawBits((a.getRawBits() * b.getRawBits())
		>> Fixed::getNbFractionalBits());
	return (result);
}

Fixed	operator/(const Fixed &a, const Fixed &b) {
	Fixed	result;

	result.setRawBits(roundf(((float) a.getRawBits() / b.getRawBits())
		* (1 << Fixed::getNbFractionalBits())));
	return (result);
}

Fixed	&Fixed::operator++()
{
	this->_fixedPointValue++;
	return (*this);
}

Fixed	&Fixed::operator--()
{
	_fixedPointValue--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	result = *this;

	++*this;
	return (result);
}

Fixed	Fixed::operator--(int)
{
	Fixed	result = *this;

	--*this;
	return (result);
}

bool			operator>(const Fixed &a, const Fixed &b) {
	return (a.getRawBits() > b.getRawBits());
}

bool			operator<(const Fixed &a, const Fixed &b) {
	return (a.getRawBits() < b.getRawBits());
}

bool			operator>=(const Fixed &a, const Fixed &b) {
	return (a.getRawBits() >= b.getRawBits());
}

bool			operator<=(const Fixed &a, const Fixed &b) {
	return (a.getRawBits() <= b.getRawBits());
}

bool			operator==(const Fixed &a, const Fixed &b) {
	return (a.getRawBits() == b.getRawBits());
}

bool			operator!=(const Fixed &a, const Fixed &b) {
	return (a.getRawBits() != b.getRawBits());
}

std::ostream	&operator<<(std::ostream &os, const Fixed &a)
{
	os << a.toFloat();
	return (os);
}

void	Fixed::setRawBits(const int raw) {
	this->_fixedPointValue = raw;
}

int	Fixed::getRawBits() const {
	return (this->_fixedPointValue);
}

int Fixed::getNbFractionalBits() {
	return (_nbFractionalBits);
}

int	Fixed::toInt() const {
	return (this->_fixedPointValue >> this->_nbFractionalBits);
}

float	Fixed::toFloat() const {
	return ((float) this->_fixedPointValue / (1 << this->_nbFractionalBits));
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b) {
	if (a > b)
		return (b);
	return (a);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b) {
	if (a > b)
		return (a);
	return (b);
}

Fixed	Fixed::min(Fixed &a, Fixed &b) {
	if (a > b)
		return (b);
	return (a);
}

Fixed	Fixed::max(Fixed &a, Fixed &b) {
	if (a > b)
		return (a);
	return (b);
}
