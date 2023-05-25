/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 00:36:00 by edelage           #+#    #+#             */
/*   Updated: 2023/05/21 00:36:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
# include "Point.hpp"

int	main(void)
{
	const Point	A = Point(Fixed(2), Fixed(1));
	const Point	B = Point(Fixed(1), Fixed(2));
	const Point	C = Point(Fixed(1), Fixed(1));
	const Point	P = Point(Fixed(1.5f), Fixed(1.5f));

	if (Point::pointInTriangle(A, B, C, P))
		std::cout << "Point in triangle" << std::endl;
	else
		std::cout << "Point outside triangle" << std::endl;

	const Point	D = Point(Fixed(2), Fixed(1));
	const Point	E = Point(Fixed(1.5f), Fixed(2));
	const Point	F = Point(Fixed(4), Fixed(2.5f));
	const Point	M = Point(Fixed(1), Fixed(1));

	if (Point::pointInTriangle(A, B, C, P))
		std::cout << "Point in triangle" << std::endl;
	else
		std::cout << "Point outside triangle" << std::endl;
}
