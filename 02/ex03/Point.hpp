/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:41:00 by edelage           #+#    #+#             */
/*   Updated: 2023/05/23 11:41:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {

public:
	Point();
	Point(const Point &copy);
	Point(const float x, const float y);
	Point(const Fixed &x, const Fixed &y);
	~Point();

	Point	&operator=(const Point &copy);

	static Point	getVector(const Point, const Point);
	static Fixed	vectorProduct(const Point leftVector, const Point rightVector);
	static bool		bsp(const Point pointA, const Point pointB, const Point pointC,
						const Point pointP);

private:
	Fixed	_x;
	Fixed	_y;

};

#endif