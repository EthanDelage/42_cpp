/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:41:00 by edelage           #+#    #+#             */
/*   Updated: 2023/05/23 11:41:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "Point.hpp"

Point::Point() {
	_x = Fixed();
	_y = Fixed();
}

Point::Point(const Point &copy) {
	_x = copy._x;
	_y = copy._y;
}

Point::Point(const Fixed &x, const Fixed &y) {
	_x = Fixed(x);
	_y = Fixed(y);
}

Point::~Point() {}

Point &Point::operator=(const Point &copy) {
	this->_x = copy._x;
	this->_y = copy._y;
	return (*this);
}

Point	Point::getVector(const Point start, const Point end) {
	return (Point(Fixed(end._x - start._x), Fixed(end._y - start._y)));
}

Fixed	Point::vectorProduct(const Point leftVector, const Point rightVector) {
	return (leftVector._x * rightVector._y - leftVector._y * rightVector._x);
}

bool	Point::pointInTriangle(const Point pointA, const Point pointB, const Point pointC, const Point pointP) {
	Point	sideTriangleVector;
	Point	relativeVector;
	Fixed	sign;
	Fixed	result;

	sideTriangleVector = getVector(pointA, pointB);
	relativeVector = getVector(pointA, pointP);
	sign = vectorProduct(sideTriangleVector, relativeVector);
	if (sign == 0)
		return (true);
	sideTriangleVector = getVector(pointB, pointC);
	relativeVector = getVector(pointB, pointP);
	result = vectorProduct(sideTriangleVector, relativeVector);
	if (result == 0)
		return (true);
	else if ((result < 0 && sign > 0) || (result > 0 && sign < 0))
		return (false);
	sideTriangleVector = getVector(pointC, pointA);
	relativeVector = getVector(pointC, pointP);
	result = vectorProduct(sideTriangleVector, relativeVector);
	if (result == 0)
		return (true);
	else if ((result < 0 && sign > 0) || (result > 0 && sign < 0))
		return (false);
	return (true);
}
